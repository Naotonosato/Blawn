#include "../errors/errors.hpp"
#include "../ast/node.hpp"
#include <llvm/IR/Value.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/BasicBlock.h>
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
llvm::Value* IRGenerator::generate(VariableNode& node) 
{return 0;}
llvm::Value* IRGenerator::generate(BinaryExpressionNode& node) 
{return 0;}
llvm::Function* IRGenerator::generate(FunctionNode &node)
{return 0;}
llvm::Value* IRGenerator::generate(CallFunctionNode &node) 
{return 0;}

llvm::Value* IntergerIRGenerator::generate(Node& node) 
{
    return llvm::ConstantInt::get(context, llvm::APInt(global_configuration::INT_BIT,node.int_num));
}

llvm::Value* FloatIRGenerator::generate(Node& node) 
{
    return llvm::ConstantFP::get(context, llvm::APFloat(node.float_num));
}

llvm::Value* VariableIRGenerator::generate(VariableNode& node) 
{
    return node.right_value;
}

llvm::Value* BinaryExpressionIRGenerator::generate(BinaryExpressionNode& node) 
{
    auto operator_kind = node.operator_kind;
    auto left = node.left_node->generate();
    auto right = node.right_node->generate();
    if (operator_kind == "+")
    {
        return ir_builder.CreateFAdd(left,right);
    }
    if (operator_kind == "-")
    {
        return ir_builder.CreateFSub(left,right);
    }
    if (operator_kind == "*")
    {
        return ir_builder.CreateFMul(left,right);
    }
    if (operator_kind == "/")
    {
        return ir_builder.CreateFDiv(left,right);
    }
    return 0;
}

llvm::Function* FunctionIRGenerator::generate(FunctionNode& node)
{
    auto previous_block = ir_builder.GetInsertBlock();
    std::vector<llvm::Type*> types(
        node.arguments.size(),
        llvm::Type::getInt8Ty(context)
        );
    auto func_type = llvm::FunctionType::get(
        llvm::Type::getVoidTy(context),types,false
        );
    auto function = llvm::Function::Create(
        func_type,
        llvm::Function::ExternalLinkage,
        node.name,
        &module
        );
    auto block = llvm::BasicBlock::Create(context,"entry",function);
    ir_builder.SetInsertPoint(block);
    ir_builder.CreateRetVoid();
    llvm::verifyFunction(*function,&llvm::outs());
    ir_builder.SetInsertPoint(previous_block);
    return function;
} 

llvm::Value* CallFunctionIRGenerator::generate(CallFunctionNode &node)
{
    auto &for_debug = llvm::outs();
    auto callee_block = ir_builder.GetInsertBlock();
    std::vector<llvm::Type*> types;
    std::vector<llvm::Value*> argument_values;
    for (auto &arg: node.arguments)
    {
        auto v = arg->generate();
        types.push_back(v->getType());
        argument_values.push_back(v);
    }
    auto iter = node.function->signatures.find(types);
    
    if (iter != node.function->signatures.end())
    //function is already generated
    {
        std::cout << "already exist function with the signature" << std::endl;
        return 0;
    }
    node.function->register_signature(types);
    
    auto temporary_block = llvm::BasicBlock::Create(context,"temporary");
    ir_builder.SetInsertPoint(temporary_block);

    int count = 0;
    for (auto &name:node.function->arguments)
    {
        auto argument = new llvm::Argument(node.arguments[count]->generate()->getType(),name);
        node.local_variables[node.function->self_namespace][name] = argument;
        count += 1;
    }
    
    for (auto &line:node.function->body)
    {
        line->generate()->print(llvm::errs());
    }
    auto func_type = llvm::FunctionType::get(node.function->return_value->generate()->getType(),types,false);
    auto function = llvm::Function::Create(
        func_type,
        llvm::Function::ExternalLinkage,
        node.function->name,
        &module
    );
    auto block = llvm::BasicBlock::Create(context,"entry",function);
    ir_builder.SetInsertPoint(block);
    for (auto &line:node.function->body)
    {
        line->generate()->print(llvm::errs());
    }
    ir_builder.CreateRet(node.function->return_value->generate());
    ir_builder.SetInsertPoint(callee_block);
    return ir_builder.CreateCall(function,argument_values);

}