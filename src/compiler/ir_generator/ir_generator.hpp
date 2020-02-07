#pragma once
#include <iostream>
#include <memory>
// forward declaration
namespace ast {
class Node;
class VariableNode;
class ArgumentNode;
class BinaryExpressionNode;
class DeepCopyNode;
class FunctionNode;
class CallFunctionNode;
}  // namespace ast

namespace llvm {
class LLVMContext;
class Value;

class Module;
template <typename T, typename Inserter>
class IRBuilder;
}  // namespace llvm
// forward declaration

void initialize();

class IRGenerator {
    public:
    llvm::LLVMContext &context;
    llvm::Module &module;
    llvm::IRBuilder<> &ir_builder;
    IRGenerator(llvm::LLVMContext &context, llvm::Module &module,
                llvm::IRBuilder<> &ir_builder);
    IRGenerator &operator=(const IRGenerator &) = default;
    virtual llvm::Value *generate(ast::Node &node);
};

class SizeofGenerator : public IRGenerator {
    public:
    SizeofGenerator(llvm::LLVMContext &context, llvm::Module &module,
                    llvm::IRBuilder<> &ir_builder)
        : IRGenerator(context, module, ir_builder) {}
    llvm::Value *generate(ast::Node &node) override;
};

class TypeIdGenerator : public IRGenerator {
    public:
    TypeIdGenerator(llvm::LLVMContext &context, llvm::Module &module,
                    llvm::IRBuilder<> &ir_builder)
        : IRGenerator(context, module, ir_builder) {}
    llvm::Value *generate(ast::Node &node) override;
};

class CastIRGenerator : public IRGenerator {
    public:
    CastIRGenerator(llvm::LLVMContext &context, llvm::Module &module,
                    llvm::IRBuilder<> &ir_builder)
        : IRGenerator(context, module, ir_builder) {}
    llvm::Value *generate(ast::Node &node) override;
};

class NullIRGenerator : public IRGenerator {
    public:
    NullIRGenerator(llvm::LLVMContext &context, llvm::Module &module,
                    llvm::IRBuilder<> &ir_builder)
        : IRGenerator(context, module, ir_builder) {}
    llvm::Value *generate(ast::Node &node) override;
};

class IntegerIRGenerator : public IRGenerator {
    public:
    IntegerIRGenerator(llvm::LLVMContext &context, llvm::Module &module,
                       llvm::IRBuilder<> &ir_builder)
        : IRGenerator(context, module, ir_builder) {}

    llvm::Value *generate(ast::Node &node) override;
};

class FloatIRGenerator : public IRGenerator {
    public:
    FloatIRGenerator(llvm::LLVMContext &context, llvm::Module &module,
                     llvm::IRBuilder<> &ir_builder)
        : IRGenerator(context, module, ir_builder) {}
    llvm::Value *generate(ast::Node &node) override;
};

class StringIRGenerator : public IRGenerator {
    public:
    StringIRGenerator(llvm::LLVMContext &context, llvm::Module &module,
                      llvm::IRBuilder<> &ir_builder)
        : IRGenerator(context, module, ir_builder) {}
    llvm::Value *generate(ast::Node &node) override;
};

class ArgumentIRGenerator : public IRGenerator {
    public:
    ArgumentIRGenerator(llvm::LLVMContext &context, llvm::Module &module,
                        llvm::IRBuilder<> &ir_builder)
        : IRGenerator(context, module, ir_builder) {}
    llvm::Value *generate(ast::Node &node) override;
};

class VariableIRGenerator : public IRGenerator {
    public:
    VariableIRGenerator(llvm::LLVMContext &context, llvm::Module &module,
                        llvm::IRBuilder<> &ir_builder)
        : IRGenerator(context, module, ir_builder) {}
    llvm::Value *generate(ast::Node &) override;
};

class AssigmentIRGenerator : public IRGenerator {
    public:
    AssigmentIRGenerator(llvm::LLVMContext &context, llvm::Module &module,
                         llvm::IRBuilder<> &ir_builder)
        : IRGenerator(context, module, ir_builder) {}
    llvm::Value *generate(ast::Node &) override;
};

class StoreIRGenerator : public IRGenerator {
    static void walk(llvm::Type *type,
                     std::vector<std::pair<llvm::Value *, llvm::Value *>> &res,
                     ast::DeepCopyNode &node, llvm::LLVMContext &context,
                     llvm::Module &module, llvm::IRBuilder<> &ir_builder,
                     StoreIRGenerator &store_generator);
    static void store(ast::DeepCopyNode &node, llvm::Value *pointer,
                      llvm::Value *object, llvm::LLVMContext &context,
                      llvm::Module &module, llvm::IRBuilder<> &ir_builder);

    public:
    StoreIRGenerator(llvm::LLVMContext &context, llvm::Module &module,
                     llvm::IRBuilder<> &ir_builder)
        : IRGenerator(context, module, ir_builder) {}
    llvm::Value *generate(ast::Node &) override;
};

class BinaryExpressionIRGenerator : public IRGenerator {
    public:
    BinaryExpressionIRGenerator(llvm::LLVMContext &context,
                                llvm::Module &module,
                                llvm::IRBuilder<> &ir_builder)
        : IRGenerator(context, module, ir_builder) {}
    llvm::Value *generate(ast::Node &node) override;
};

class FunctionIRGenerator : public IRGenerator {
    public:
    FunctionIRGenerator(llvm::LLVMContext &context, llvm::Module &module,
                        llvm::IRBuilder<> &ir_builder)
        : IRGenerator(context, module, ir_builder) {}
    llvm::Function *generate(ast::Node &node) override;
};

class DeclareCIRGenerator : public IRGenerator {
    public:
    DeclareCIRGenerator(llvm::LLVMContext &context, llvm::Module &module,
                        llvm::IRBuilder<> &ir_builder)
        : IRGenerator(context, module, ir_builder) {}
    llvm::Value *generate(ast::Node &node) override;
};

class CallFunctionIRGenerator : public IRGenerator {
    public:
    CallFunctionIRGenerator(llvm::LLVMContext &context, llvm::Module &module,
                            llvm::IRBuilder<> &ir_builder)
        : IRGenerator(context, module, ir_builder) {}
    llvm::Value *generate(ast::Node &node) override;
};

class ClassIRGenerator : public IRGenerator {
    public:
    ClassIRGenerator(llvm::LLVMContext &context, llvm::Module &module,
                     llvm::IRBuilder<> &ir_builder)
        : IRGenerator(context, module, ir_builder) {}
    llvm::Value *generate(ast::Node &node) override;
};

class CallConstructorIRGenerator : public IRGenerator {
    public:
    CallConstructorIRGenerator(llvm::LLVMContext &context, llvm::Module &module,
                               llvm::IRBuilder<> &ir_builder)
        : IRGenerator(context, module, ir_builder) {}
    llvm::Value *generate(ast::Node &node) override;
};

class IfIRGenerator : public IRGenerator {
    public:
    IfIRGenerator(llvm::LLVMContext &context, llvm::Module &module,
                  llvm::IRBuilder<> &ir_builder)
        : IRGenerator(context, module, ir_builder) {}
    llvm::Value *generate(ast::Node &node) override;
};

class AccessIRGenerator : public IRGenerator {
    public:
    AccessIRGenerator(llvm::LLVMContext &context, llvm::Module &module,
                      llvm::IRBuilder<> &ir_builder)
        : IRGenerator(context, module, ir_builder) {}
    llvm::Value *generate(ast::Node &node) override;
};

class ForIRGenerator : public IRGenerator {
    public:
    ForIRGenerator(llvm::LLVMContext &context, llvm::Module &module,
                   llvm::IRBuilder<> &ir_builder)
        : IRGenerator(context, module, ir_builder) {}
    llvm::Value *generate(ast::Node &node) override;
};

class ListIRGenerator : public IRGenerator {
    public:
    ListIRGenerator(llvm::LLVMContext &context, llvm::Module &module,
                    llvm::IRBuilder<> &ir_builder)
        : IRGenerator(context, module, ir_builder) {}
    llvm::Value *generate(ast::Node &node) override;
};

class BlockEndIRGenerator : public IRGenerator {
    public:
    BlockEndIRGenerator(llvm::LLVMContext &context, llvm::Module &module,
                        llvm::IRBuilder<> &ir_builder)
        : IRGenerator(context, module, ir_builder) {}
    llvm::Value *generate(ast::Node &node) override;
};

class IRGenerators {
    public:
    IRGenerator ir_generator;
    SizeofGenerator sizeof_generator;
    TypeIdGenerator typeid_generator;
    CastIRGenerator cast_generator;
    NullIRGenerator null_generator;
    IntegerIRGenerator int_ir_generator;
    FloatIRGenerator float_ir_generator;
    StringIRGenerator string_generator;
    VariableIRGenerator variable_generator;
    ArgumentIRGenerator argument_generator;
    AssigmentIRGenerator assigment_generator;
    StoreIRGenerator store_generator;
    BinaryExpressionIRGenerator binary_expression_generator;
    FunctionIRGenerator function_generator;
    DeclareCIRGenerator declare_C_generator;
    CallFunctionIRGenerator calling_generator;
    ClassIRGenerator class_generator;
    CallConstructorIRGenerator call_constructor_generator;
    IfIRGenerator if_generator;
    ForIRGenerator for_generator;
    AccessIRGenerator access_generator;
    ListIRGenerator list_generator;
    BlockEndIRGenerator block_end_generator;
    IRGenerators(llvm::LLVMContext &, llvm::Module &, llvm::IRBuilder<> &);
    IRGenerators &get_generators();
};