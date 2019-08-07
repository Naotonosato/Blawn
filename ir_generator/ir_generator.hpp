#pragma once
#include <iostream>
#include <memory>
//forward declaration
class Node;
class VariableNode;
class BinaryExpressionNode;
namespace llvm
{
    class LLVMContext;
    class Value;

    class Module;
    template<typename T,typename Inserter>
    class IRBuilder;
}
//forward declaration


class IRGenerator
{
public:
    llvm::LLVMContext &context;
    llvm::Module &module;
    llvm::IRBuilder<> &ir_builder;
    IRGenerator(
        llvm::LLVMContext &context,
        llvm::Module &module,
        llvm::IRBuilder<> &ir_builder
        )
    :context(context),module(module),ir_builder(ir_builder){}
    virtual llvm::Value* generate(Node &node) const;
    virtual llvm::Value* generate(VariableNode &node) const;
    virtual llvm::Value* generate(BinaryExpressionNode &node) const;
};


class IntergerIRGenerator: public IRGenerator
{
public:
    IntergerIRGenerator(
        llvm::LLVMContext &context,
        llvm::Module &module,
        llvm::IRBuilder<> &ir_builder
        )
    :IRGenerator(context,module,ir_builder){}

    llvm::Value* generate(Node &node) const;
};


class FloatIRGenerator: public IRGenerator
{
public:
    FloatIRGenerator(
        llvm::LLVMContext &context,
        llvm::Module &module,
        llvm::IRBuilder<> &ir_builder
        )
    :IRGenerator(context,module,ir_builder){}
    llvm::Value* generate(Node &node) const;
};


class VariableIRGenerator: public IRGenerator
{
public:
    VariableIRGenerator(
        llvm::LLVMContext &context,
        llvm::Module &module,
        llvm::IRBuilder<> &ir_builder
        )
    :IRGenerator(context,module,ir_builder){}

    llvm::Value* generate(VariableNode &node) const;
};

class BinaryExpressionIRGenerator: public IRGenerator
{
public:
    BinaryExpressionIRGenerator(
        llvm::LLVMContext &context,
        llvm::Module &module,
        llvm::IRBuilder<> &ir_builder
        )
    :IRGenerator(context,module,ir_builder){}
    llvm::Value* generate(BinaryExpressionNode &node) const;
};


