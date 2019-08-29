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

    llvm::Value* generate(Node &node) override;
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
    llvm::Value* generate(Node &node) override;
};


class StringIRGenerator:public IRGenerator
{
    public:
    StringIRGenerator(
        llvm::LLVMContext &context,
        llvm::Module &module,
        llvm::IRBuilder<> &ir_builder
        )
    :IRGenerator(context,module,ir_builder){}
    llvm::Value* generate(Node &node) override;
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
    llvm::Value* generate(Node& node) override;
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
    llvm::Value* generate(Node&) override;
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
    llvm::Value* generate(Node&) override;
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
    llvm::Value* generate(Node &node) override;
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
    llvm::Value* generate(Node &node) override;
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
    llvm::Value* generate(Node &node) override;
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
    llvm::Value* generate(Node &node) override;
};


class IfIRGenerator:public IRGenerator
{
    public:
    IfIRGenerator(
        llvm::LLVMContext &context,
        llvm::Module &module,
        llvm::IRBuilder<> &ir_builder
        )
    :IRGenerator(context,module,ir_builder){}
    llvm::Value* generate(Node &node) override;
};


class AccessIRGenerator:public IRGenerator
{
    public:
    AccessIRGenerator(
        llvm::LLVMContext &context,
        llvm::Module &module,
        llvm::IRBuilder<> &ir_builder
        )
    :IRGenerator(context,module,ir_builder){}
    llvm::Value* generate(Node &node) override;
};


class ForIRGenerator:public IRGenerator
{
    public:
    ForIRGenerator(
        llvm::LLVMContext &context,
        llvm::Module &module,
        llvm::IRBuilder<> &ir_builder
        )
    :IRGenerator(context,module,ir_builder){}
    llvm::Value* generate(Node &node) override;
};