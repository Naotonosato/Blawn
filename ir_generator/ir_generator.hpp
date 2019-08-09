#pragma once
#include <iostream>
#include <memory>
//forward declaration
class Node;
class VariableNode;
class BinaryExpressionNode;
class FunctionNode;
class CallFunctionNode;

namespace llvm
{
    class LLVMContext;
    class Value;

    class Module;
    template<typename T,typename Inserter>
    class IRBuilder;
}
//forward declaration


void initialize();


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
        );
    virtual llvm::Value* generate(Node &node) ;
    virtual llvm::Value* generate(VariableNode &node) ;
    virtual llvm::Value* generate(BinaryExpressionNode &node) ;
    virtual llvm::Function* generate(FunctionNode &node);
    virtual llvm::Value* generate(CallFunctionNode &node);
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

    llvm::Value* generate(Node &node) ;
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
    llvm::Value* generate(Node &node) ;
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

    llvm::Value* generate(VariableNode &node) ;
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
    llvm::Value* generate(BinaryExpressionNode &node);
};


class FunctionIRGenerator: public IRGenerator
{
public:
    FunctionIRGenerator(
        llvm::LLVMContext &context,
        llvm::Module &module,
        llvm::IRBuilder<> &ir_builder
        )
    :IRGenerator(context,module,ir_builder){}
    llvm::Function* generate(FunctionNode &node);
};


class CallFunctionIRGenerator: public IRGenerator
{
public:
    CallFunctionIRGenerator(
        llvm::LLVMContext &context,
        llvm::Module &module,
        llvm::IRBuilder<> &ir_builder
        )
    :IRGenerator(context,module,ir_builder){}
    llvm::Value* generate(CallFunctionNode &node);
};
