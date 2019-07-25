#include "../ast/node.hpp"
#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include "ir_generator.hpp"
#include "../global_configuration/global_configuration.hpp"
#include <llvm/IR/Constants.h>
#include <llvm/ADT/APInt.h>


std::shared_ptr<llvm::Value> IntergerIRGenerator::generate(Node& node)
{
    int num = node.int_num;
    auto val = std::shared_ptr<llvm::Value>(llvm::ConstantInt::get(context, llvm::APInt(global_configuration::INT_BIT,num)));
    return val;
}


std::shared_ptr<llvm::Value> FloatIRGenerator::generate(Node& node)
{
    double num = node.float_num;
    auto val = std::shared_ptr<llvm::Value>(llvm::ConstantFP::get(context, llvm::APFloat(num)));
    return val;
}

std::shared_ptr<llvm::Value> BinaryExpressionIRGenerator::generate(Node& node)
{
    auto operator_kind = node.operator_kind;
    auto left = node.left_node->generate();
    auto right = node.right_node->generate();
    std::shared_ptr<llvm::Value> value;
    if (operator_kind == "+")
    {
        value = std::shared_ptr<llvm::Value>(ir_builder.CreateFAdd(left.get(),right.get()));
        return value;

    }
    if (operator_kind == "-")
    {
        value = std::shared_ptr<llvm::Value>(ir_builder.CreateFSub(left.get(),right.get()));
        return value;
    }
    if (operator_kind == "*")
    {
        value = std::shared_ptr<llvm::Value>(ir_builder.CreateFMul(left.get(),right.get()));
        return value;
    }
    if (operator_kind == "/")
    {
        value = std::shared_ptr<llvm::Value>(ir_builder.CreateFDiv(left.get(),right.get()));
        return value;
    }
}