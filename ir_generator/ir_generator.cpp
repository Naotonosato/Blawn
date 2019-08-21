#include "../errors/errors.hpp"
#include "../ast/node.hpp"
#include <llvm/IR/Instructions.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Instructions.h>
#include <llvm/Transforms/Utils/Cloning.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/DataLayout.h>
#include <llvm/Support/raw_ostream.h>
#include "ir_generator.hpp"
#include "../global_configuration/global_configuration.hpp"
#include <llvm/IR/Constants.h>
#include <llvm/ADT/APInt.h>
#include <llvm/ADT/APFloat.h>
#include <iostream>
#include "../utils/utils.hpp"


void initialize(llvm::LLVMContext &context,llvm::Module &module,llvm::IRBuilder<> &ir_builder)
{
    //declare malloc
    std::vector<llvm::Type*> malloc_types(1,ir_builder.getInt64Ty());
    auto malloc_declaration_type = llvm::FunctionType::get(ir_builder.getInt64Ty()->getPointerTo(),malloc_types,false);
    llvm::Function::Create(malloc_declaration_type,llvm::Function::ExternalLinkage,"malloc",&module);
    //declare free
    std::vector<llvm::Type*> free_types(1,ir_builder.getInt64Ty()->getPointerTo());
    auto free_declaration_type = llvm::FunctionType::get(ir_builder.getVoidTy(),free_types,false);
    llvm::Function::Create(free_declaration_type,llvm::Function::ExternalLinkage,"free",&module);
    //create main function
    std::vector<llvm::Type*> main_types;
    auto function_type = llvm::FunctionType::get(llvm::Type::getInt8Ty(context),main_types, false);
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

llvm::Value* IntegerIRGenerator::generate(Node& node) 
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
    
    if (!node.is_generated())
    {
        llvm::Value* right;
        if (node.generated_right_values.count(node.right_node))
        {
            right = node.generated_right_values[node.right_node];
        }
        else right = node.right_node->generate();
        //std::cout << "new variable " << node.name << std::endl;
        node.alloca_inst = ir_builder.CreateAlloca(right->getType(),0,node.name);
        ir_builder.CreateStore(right,node.alloca_inst);
        node.generated();
        return ir_builder.CreateLoad(node.alloca_inst);
    }
    else
    {
        //if (node.store_inst == nullptr)
          //  {node.store_inst = ir_builder.CreateStore(right,node.alloca_inst);}
        return ir_builder.CreateLoad(node.alloca_inst);
    }
}

llvm::Value* AssigmentIRGenerator::generate(Node& node_)
{
    auto& node = *static_cast<AssigmentNode*>(&node_);
    auto alloca = node.get_target()->alloca_inst;
    ir_builder.CreateStore(node.get_right_node()->generate(),alloca);
    return ir_builder.CreateLoad(alloca);
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
    bool both_int = (left->getType()->isIntegerTy() && right->getType()->isIntegerTy());
    
    if (operator_kind == "+")
    {
        if(both_int) return ir_builder.CreateAdd(left,right);
        else return ir_builder.CreateFAdd(left,right);
    }
    if (operator_kind == "-")
    {
        if(both_int) return ir_builder.CreateSub(left,right);
        else return ir_builder.CreateFSub(left,right);
    }
    if (operator_kind == "*")
    {
        if(both_int) return ir_builder.CreateMul(left,right);
        else return ir_builder.CreateFMul(left,right);
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
    return function;
} 

llvm::Value* CallUnsolvedFunctionIRGenerator::generate(Node& node_)
{
    auto& node = *static_cast<CallUnsolvedFunctionNode*>(&node_);
    if (node.function_collector->exist(node.name))
    {
        std::vector<llvm::Type*> types;
        std::vector<llvm::Value*> args;
        for (auto& arg:node.passed_arguments)
        {
            auto value = arg->generate();
            types.push_back(value->getType());
            args.push_back(value);
        }
        auto func_node = node.function_collector->get(node.name);
        auto func = func_node.get_function(types);
        if (func == nullptr)
        {   
            std::cout << "Error: No Function with the signature." << std::endl;
            exit(1);
        }
        else
        {
            return ir_builder.CreateCall(func,args);
            aospcm;@;@@;@;@;@@;@@@@;@;@;@;@;@;@;@;@;@;@;@;@;@;@;@;@;@;
        }
    }
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
    auto base_function_type = llvm::FunctionType::get(ir_builder.getVoidTy(),types,false);
    auto base_function = llvm::Function::Create(
        base_function_type,
        llvm::Function::ExternalLinkage,
        node.function->name,
        &module
    );
    
    auto block = llvm::BasicBlock::Create(context,"entry",base_function);
    ir_builder.SetInsertPoint(block);
    
    int count = 0;
    for (auto &tmp_func_arg:base_function->args())
    {
        std::string name = node.function->arguments_names[count];
        tmp_func_arg.setName(name);
        auto local = node.function->get_self_namespace();
        auto empty_node = node.argument_collector.get(name,local);
        empty_node->set_right_value(&tmp_func_arg);
        count += 1;
    }
    //auto destruction_block = llvm::BasicBlock::Create(context,"destruction");
    //auto merge = llvm::BasicBlock::Create(context,"merge");
    for (auto& line:node.function->body)
    {
        line->initialize();
        line->generate();
    }
    auto return_value = node.function->return_value->generate();
    /*
    for (auto &d:node.function->destructors)
    {
        std::vector<llvm::Value*> arg(1,d.second);
        ir_builder.CreateCall(d.first,arg);
    }
    */
    ir_builder.CreateRet(return_value);
    //base_function->print(llvm::outs());

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
    for (auto &tmp_arg:base_function->args())
    {
        new_arg->setName(tmp_arg.getName());
        vmap[&tmp_arg] = new_arg;
        new_arg++;
    }
    
    llvm::SmallVector<llvm::ReturnInst*,0> returns;
    llvm::CloneFunctionInto(new_function,base_function,vmap,false,returns);
    //llvm::CloneFunctionInto(new_function,vmap,true,returns);
    node.function->register_function(types,new_function);
    node.function->get_temporary_function()->replaceAllUsesWith(new_function);
    //base_function->eraseFromParent();
    //llvm::verifyFunction(*new_function,&llvm::outs());
    ir_builder.SetInsertPoint(callee_block);
    return ir_builder.CreateCall(new_function,argument_values);

}

llvm::Value* ClassIRGenerator::generate(Node& node_)
{
    auto& node = *static_cast<ClassNode*>(&node_);
    std::vector<llvm::Type*> types;
    auto type = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),types,false
        );
    auto constructor = llvm::Function::Create(
        type,
        llvm::Function::ExternalLinkage,
        node.name,
        &module
        );
    node.set_temporary_constructor(constructor);
    return constructor;
}

llvm::Value* CallConstructorIRGenerator::generate(Node& node_)
{
    auto& node = *static_cast<CallConstructorNode*>(&node_);

    for (auto &arg: node.get_passed_arguments())
    {
        if (arg->is_argument())
        {
            if (static_cast<ArgumentNode*>(arg.get())->get_right_value() == nullptr)
            {
                std::vector<llvm::Value*> empty_arg;
                return ir_builder.CreateCall(node.get_class()->get_temporary_constructor(),empty_arg);
            }
        }
    }
    auto callee_block = ir_builder.GetInsertBlock();
    std::vector<llvm::Type*> types;
    std::vector<llvm::Value*> argument_values;
    for (auto &arg: node.get_passed_arguments())
    {
        auto v = arg->generate();
        types.push_back(v->getType());
        argument_values.push_back(v);
    }
    auto f = node.get_class()->get_constructor(types);
    if (f != nullptr)
    //constructor is already generated
    {
        return ir_builder.CreateCall(f,argument_values);
    }
    auto base_constructor_type = llvm::FunctionType::get(ir_builder.getVoidTy(),types,false);
    auto base_constructor = llvm::Function::Create(
        base_constructor_type,
        llvm::Function::ExternalLinkage,
        node.get_class()->name,
        &module
    );
    
    auto block = llvm::BasicBlock::Create(context,"entry",base_constructor);
    ir_builder.SetInsertPoint(block);
    
    int count = 0;
    for (auto &tmp_constructor_arg:base_constructor->args())
    {
        std::string name = node.get_class()->get_arguments_names()[count];
        tmp_constructor_arg.setName(name);
        auto local = node.get_class()->get_self_namespace();
        auto empty_node = node.argument_collector.get(name,local);
        empty_node->set_right_value(&tmp_constructor_arg);
        count += 1;
    }

    std::vector<llvm::Type*> fields;
    std::vector<llvm::Value*> initial_values;

    for (auto& line:node.get_class()->get_members_definition())
    {
        line->initialize();
        auto value = line->generate();
        fields.push_back(value->getType());
        initial_values.push_back(value);
    }

    auto instance_type/*class*/ = llvm::StructType::create(context,fields,node.get_class()->name);
    auto instance_alloca = utils::malloc_value(instance_type,context,module,ir_builder);
    for (unsigned int idx=0;idx<=fields.size()-1;idx++)
    {
        ir_builder.CreateStore(
            initial_values[idx],
            ir_builder.CreateStructGEP(instance_type,instance_alloca,idx)
            );
    }
    ir_builder.CreateRet(instance_alloca);

    auto new_constructor_type = llvm::FunctionType::get(
        instance_type->getPointerTo(),
        types,
        false
        );
    auto new_constructor = llvm::Function::Create(
        new_constructor_type,
        llvm::Function::ExternalLinkage,
        node.get_class()->name,
        &module
    );

    llvm::ValueToValueMapTy vmap;
    
    auto new_arg = new_constructor->arg_begin();
    for (auto &tmp_arg:base_constructor->args())
    {
        new_arg->setName(tmp_arg.getName());
        vmap[&tmp_arg] = new_arg;
        new_arg++;
    }
    
    llvm::SmallVector<llvm::ReturnInst*,0> returns;
    llvm::CloneFunctionInto(new_constructor,base_constructor,vmap,false,returns);
    node.get_class()->register_constructor(types,new_constructor);
    node.get_class()->get_temporary_constructor()->replaceAllUsesWith(new_constructor);
    llvm::verifyFunction(*new_constructor,&llvm::outs());

    std::vector<llvm::Type*> destructor_args(1,instance_type->getPointerTo());
    auto destructor = node.get_class()->get_destructor(destructor_args);
    if (destructor == nullptr)
    {
        auto destructor_type = llvm::FunctionType::get(ir_builder.getVoidTy(),destructor_args,false);
        destructor = llvm::Function::Create(
            destructor_type,
            llvm::Function::ExternalLinkage,
            "#destructor_of_" + node.get_class()->name,
            &module
            );
        auto destructor_entry = llvm::BasicBlock::Create(context,"entry",destructor);
        ir_builder.SetInsertPoint(destructor_entry);
        utils::free_value(destructor->arg_begin(),module,ir_builder);
        ir_builder.CreateRetVoid(); 
        node.get_class()->register_destructor(destructor_args,destructor);
    }
    node.set_destructor(destructor,instance_alloca);
    ir_builder.SetInsertPoint(callee_block);
    return ir_builder.CreateCall(new_constructor,argument_values);

}