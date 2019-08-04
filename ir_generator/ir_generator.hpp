#include <iostream>
#include <memory>
//forward declaration
class Node;
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
    std::shared_ptr<llvm::LLVMContext> context;
    std::shared_ptr<llvm::Module> module;
    std::shared_ptr<llvm::IRBuilder<>> ir_builder;
    IRGenerator(
        std::shared_ptr<llvm::LLVMContext> context,
        std::shared_ptr<llvm::Module> module,
        std::shared_ptr<llvm::IRBuilder<>> ir_builder
        )
    :context(context),module(module),ir_builder(ir_builder){}
    virtual llvm::Value* generate(Node& node)
    {std::cout << "empty\n";return 0;}
};


class IntergerIRGenerator: public IRGenerator
{
public:
    IntergerIRGenerator(
        std::shared_ptr<llvm::LLVMContext> context,
        std::shared_ptr<llvm::Module> module,
        std::shared_ptr<llvm::IRBuilder<>> ir_builder
        )
    :IRGenerator(context,module,ir_builder){}

    llvm::Value* generate(Node& node);
};


class FloatIRGenerator: public IRGenerator
{
public:
    FloatIRGenerator(
        std::shared_ptr<llvm::LLVMContext> context,
        std::shared_ptr<llvm::Module> module,
        std::shared_ptr<llvm::IRBuilder<>> ir_builder
        )
    :IRGenerator(context,module,ir_builder){}
    llvm::Value* generate(Node& node);
};


class BinaryExpressionIRGenerator: public IRGenerator
{
public:
    BinaryExpressionIRGenerator(
        std::shared_ptr<llvm::LLVMContext> context,
        std::shared_ptr<llvm::Module> module,
        std::shared_ptr<llvm::IRBuilder<>> ir_builder
        )
    :IRGenerator(context,module,ir_builder){}
    llvm::Value* generate(Node& node);
};


