#pragma once
#include <iostream>
#include <memory>
//forward declaration
class Node;
class VariableNode;
class ArgumentNode;
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
    IRGenerator& operator=(const IRGenerator&) = default;
    virtual llvm::Value* generate(Node &node);
};


class IntegerIRGenerator: public IRGenerator
{
public:
    IntegerIRGenerator(
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
    llvm::Value* generate(Node &node);
};


class ArgumentIRGenerator: public IRGenerator
{
    public:
    ArgumentIRGenerator(
        llvm::LLVMContext &context,
        llvm::Module &module,
        llvm::IRBuilder<> &ir_builder
        )
    :IRGenerator(context,module,ir_builder){}
    llvm::Value* generate(Node& node);
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
    llvm::Value* generate(Node&);
};


class AssigmentIRGenerator: public IRGenerator
{
public:
    AssigmentIRGenerator(
        llvm::LLVMContext &context,
        llvm::Module &module,
        llvm::IRBuilder<> &ir_builder
        )
    :IRGenerator(context,module,ir_builder){}
    llvm::Value* generate(Node&);
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
    llvm::Value* generate(Node &node);
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
    llvm::Function* generate(Node &node);
};

class CallUnsolvedFunctionIRGenerator:public IRGenerator
{
    CallUnsolvedFunctionIRGenerator(
        llvm::LLVMContext &context,
        llvm::Module &module,
        llvm::IRBuilder<> &ir_builder
        )
    :IRGenerator(context,module,ir_builder){}
    llvm::Function* generate(Node &node) override;
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
    llvm::Value* generate(Node &node);
};


class ClassIRGenerator: public IRGenerator
{
    public:
    ClassIRGenerator(
        llvm::LLVMContext &context,
        llvm::Module &module,
        llvm::IRBuilder<> &ir_builder
        )
    :IRGenerator(context,module,ir_builder){}
    llvm::Value* generate(Node &node);
};


class CallConstructorIRGenerator:public IRGenerator
{
    public:
    CallConstructorIRGenerator(
        llvm::LLVMContext &context,
        llvm::Module &module,
        llvm::IRBuilder<> &ir_builder
        )
    :IRGenerator(context,module,ir_builder){}
    llvm::Value* generate(Node &node);
};