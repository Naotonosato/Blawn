#include "../errors/errors.hpp"
#include "../ast/node.hpp"
#include <llvm/IR/Value.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include "ir_generator.hpp"
#include "../global_configuration/global_configuration.hpp"
#include <llvm/IR/Constants.h>
#include <llvm/ADT/APInt.h>
#include <iostream>

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
    std::vector<llvm::Type*> types(
        node.arguments.size(),
        llvm::Type::getVoidTy(context)
        );
    auto func_type = llvm::FunctionType::get(
        llvm::Type::getDoubleTy(context),types,false
        );
    auto function = llvm::Function::Create(
        func_type,
        llvm::Function::ExternalLinkage,
        node.name,
        &module
        );
    auto block = llvm::BasicBlock::Create(context,"entry",function);
    ir_builder.SetInsertPoint(block);
    return function;
} 

llvm::Value* CallFunctionIRGenerator::generate(CallFunctionNode &node)
{
    auto iter = std::find(
        node.function->arguments_kind.begin(),
        node.function->arguments_kind.end(),
        node.arguments
        );
    if (iter != node.function->arguments_kind.end())//function is already generated
    {
        return 0;
    }
    else
    {

        std::vector<llvm::Type*> types;
        for (auto &arg: node.arguments)
        {
            types.push_back(arg->generate()->getType());
        }
        auto args = &node.local_variables[node.function->self_namespace];
        int count = 0;
        for (auto &name:node.function->arguments)
        {
            auto argument = std::shared_ptr<llvm::Argument>(new llvm::Argument(node.arguments[count]->generate()->getType(),name));
            (*args)[name] = argument.get();
            count += 1;
        }
        auto func_type = llvm::FunctionType::get(
            node.function->return_value->generate()->getType(),types,false
        );
        auto function = llvm::Function::Create(
            func_type,
            llvm::Function::ExternalLinkage,
            node.function->name,
            &module
        );
    }
}