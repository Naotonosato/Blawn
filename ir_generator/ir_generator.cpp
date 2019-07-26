#include "../ast/node.hpp"
#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include "ir_generator.hpp"
#include "../global_configuration/global_configuration.hpp"
#include <llvm/IR/Constants.h>
#include <llvm/ADT/APInt.h>


llvm::Value* IntergerIRGenerator::generate(Node& node)
{
    return llvm::ConstantInt::get(context, llvm::APInt(global_configuration::INT_BIT,node.int_num));
}


llvm::Value* FloatIRGenerator::generate(Node& node)
{
    return llvm::ConstantFP::get(context, llvm::APFloat(node.float_num));
}

llvm::Value* BinaryExpressionIRGenerator::generate(BinaryExpressionNode& node)
{
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
        return ir_builder.CreateFMul(left,right);
    }
    if (operator_kind == "/")
    {
        return ir_builder.CreateFDiv(left,right);
    }
    return 0;
}