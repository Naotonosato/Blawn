#include "../errors/errors.hpp"
#include "../ast/node.hpp"
#include <llvm/IR/Instructions.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Instructions.h>
#include <llvm/Transforms/Utils/Cloning.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/Support/raw_ostream.h>
#include "ir_generator.hpp"
#include "../global_configuration/global_configuration.hpp"
#include <llvm/IR/Constants.h>
#include <llvm/ADT/APInt.h>
#include <iostream>


void initialize(llvm::LLVMContext &context,llvm::Module &module,llvm::IRBuilder<> &ir_builder)
{
    std::vector<llvm::Type*> types;
    auto function_type = llvm::FunctionType::get(llvm::Type::getInt8Ty(context),types, false);
    auto function = llvm::Function::Create(function_type,llvm::Function::ExternalLinkage,"main",&module);
    auto block = llvm::BasicBlock::Create(context,"entry",function);
    ir_builder.SetInsertPoint(block);
}


IRGenerator::IRGenerator(
        llvm::LLVMContext &context,
        llvm::Module &module,
        llvm::IRBuilder<> &ir_builder
        ):context(context),module(module),ir_builder(ir_builder)
{
    static bool flag = true;
    if (flag)
    {
        initialize(context,module,ir_builder);
        flag = false;
    }
}
llvm::Value* IRGenerator::generate(Node& node) 
{return 0;}

llvm::Value* IntergerIRGenerator::generate(Node& node) 
{
    return llvm::ConstantInt::get(context, llvm::APInt(global_configuration::INT_BIT,node.int_num));
}

llvm::Value* FloatIRGenerator::generate(Node& node) 
{
    return llvm::ConstantFP::get(context, llvm::APFloat(node.float_num));
}

llvm::Value* VariableIRGenerator::generate(Node& node_) 
{
    auto& node = *static_cast<VariableNode*>(&node_);
    llvm::Value* right;
    if (node.generated_right_values.count(node.right_node))
    {
        right = node.generated_right_values[node.right_node];
    }
    else right = node.right_node->generate();
    
    if (!node.is_generated)
    {
        //std::cout << "new variable " << node.name << std::endl;
        node.alloca_inst = ir_builder.CreateAlloca(right->getType(),0,node.name);
        ir_builder.CreateStore(right,node.alloca_inst);
        node.is_generated = true;
        return ir_builder.CreateLoad(node.alloca_inst);
    }
    else
    {
        //if (node.store_inst == nullptr)
          //  {node.store_inst = ir_builder.CreateStore(right,node.alloca_inst);}
        if (node.load_inst == nullptr)
            {node.load_inst = ir_builder.CreateLoad(node.alloca_inst);}
        return node.load_inst;
    }
}

llvm::Value* AssigmentIRGenerator::generate(Node& node_)
{
    auto& node = *static_cast<AssigmentNode*>(&node_);
    auto alloca = node.get_target()->alloca_inst;
    return ir_builder.CreateStore(node.get_right_node()->generate(),alloca);
}

llvm::Value* ArgumentIRGenerator::generate(Node& node_)
{
    auto& node = *static_cast<ArgumentNode*>(&node_);
    return node.get_right_value();
}

llvm::Value* BinaryExpressionIRGenerator::generate(Node& node_) 
{
    auto& node = *static_cast<BinaryExpressionNode*>(&node_);
    
    auto operator_kind = node.operator_kind;
    auto left = node.left_node->generate();
    auto right = node.right_node->generate();
    if (operator_kind == "+")
    {
        return ir_builder.CreateAdd(left,right);
    }
    if (operator_kind == "-")
    {
        return ir_builder.CreateSub(left,right);
    }
    if (operator_kind == "*")
    {
        return ir_builder.CreateMul(left,right);
    }
    if (operator_kind == "/")
    {
        return ir_builder.CreateFDiv(left,right);
    }
    return 0;
}

llvm::Function* FunctionIRGenerator::generate(Node& node_)
{
    auto& node = *static_cast<FunctionNode*>(&node_);
    auto previous_block = ir_builder.GetInsertBlock();
    std::vector<llvm::Type*> types;
    auto func_type = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),types,false
        );
    auto function = llvm::Function::Create(
        func_type,
        llvm::Function::ExternalLinkage,
        node.name,
        &module
        );
    node.set_temporary_function(function);
    auto block = llvm::BasicBlock::Create(context,"empty_entry",function);
    ir_builder.SetInsertPoint(block);
    ir_builder.CreateRetVoid();
    //llvm::verifyFunction(*function,&llvm::outs());
    ir_builder.SetInsertPoint(previous_block);
    return function;
} 

llvm::Value* CallFunctionIRGenerator::generate(Node &node_)
{
    auto& node = *static_cast<CallFunctionNode*>(&node_);
    for (auto &arg: node.passed_arguments)
    {
        if (arg->is_argument())
        {
            if (static_cast<ArgumentNode*>(arg.get())->get_right_value() == nullptr)
            {
                std::vector<llvm::Value*> empty_arg;
                return ir_builder.CreateCall(node.function->get_temporary_function(),empty_arg);
            }
        }
    }
    auto callee_block = ir_builder.GetInsertBlock();
    std::vector<llvm::Type*> types;
    std::vector<llvm::Value*> argument_values;
    for (auto &arg: node.passed_arguments)
    {
        auto v = arg->generate();
        types.push_back(v->getType());
        argument_values.push_back(v);
    }
    auto f = node.function->get_function(types);
    if (f != nullptr)
    //function is already generated
    {
        return ir_builder.CreateCall(f,argument_values);
    }
    auto tmp_function_type = llvm::FunctionType::get(ir_builder.getVoidTy(),types,false);
    auto tmp_function = llvm::Function::Create(
        tmp_function_type,
        llvm::Function::ExternalLinkage,
        node.function->name,
        &module
    );
    auto block = llvm::BasicBlock::Create(context,"entry",tmp_function);
    ir_builder.SetInsertPoint(block);
    //std::vector<llvm::Value*> tmp_value_as_arg;
    int count = 0;
    for (auto &tmp_func_arg:tmp_function->args())
    {
        std::string name = node.function->arguments_names[count];
        tmp_func_arg.setName(name);
        auto local = node.function->get_self_namespace();
        auto empty_node = node.argument_collector.get(name,local);
        empty_node->set_right_value(&tmp_func_arg);
        count += 1;
    }
    /*
    for (auto &l:node.function->body)
    {
        l->generate();
    }
    */
    auto& debug = llvm::outs();
    /*
    auto vnode = dynamic_cast<VariableNode*>(node.function->body[0].get());
    auto c = dynamic_cast<CallFunctionNode*>(vnode->right_node.get());
    int bug = 0;
    int* bugp = &bug;
    bugp = nullptr;
    std::cout << *bugp;
    */
    auto return_value = node.function->return_value->generate();
    //return_value->print(llvm::outs());
    ir_builder.CreateRet(return_value);
    auto new_function_type = llvm::FunctionType::get(
        return_value->getType(),
        types,
        false
        );
    auto new_function = llvm::Function::Create(
        new_function_type,
        llvm::Function::ExternalLinkage,
        node.function->name,
        &module
    );

    llvm::ValueToValueMapTy vmap;
    
    auto new_arg = new_function->arg_begin();
    for (auto &tmp_arg:tmp_function->args())
    {
        new_arg->setName(tmp_arg.getName());
        vmap[&tmp_arg] = new_arg;
        new_arg++;
    }
    
    llvm::SmallVector<llvm::ReturnInst*,0> returns;
    llvm::CloneFunctionInto(new_function,tmp_function,vmap,true,returns);
    //llvm::CloneFunctionInto(new_function,vmap,true,returns);
    node.function->register_function(types,new_function);
    node.function->get_temporary_function()->replaceAllUsesWith(new_function);
    tmp_function->eraseFromParent();
    llvm::verifyFunction(*new_function,&llvm::outs());
    ir_builder.SetInsertPoint(callee_block);
    return ir_builder.CreateCall(new_function,argument_values);

}