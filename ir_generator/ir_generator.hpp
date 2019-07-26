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
    llvm::LLVMContext& context;
    llvm::IRBuilder<> &ir_builder;
    IRGenerator(llvm::IRBuilder<> &ir_builder, llvm::LLVMContext& context)
    :ir_builder(ir_builder),context(context){};
    virtual llvm::Value* generate(Node& node){return 0;};
};


class IntergerIRGenerator: public IRGenerator
{
public:
    IntergerIRGenerator(llvm::IRBuilder<>& ir_builder,llvm::LLVMContext& context)
    :IRGenerator(ir_builder,context){}

    llvm::Value* generate(Node& node);
};


class FloatIRGenerator: public IRGenerator
{
public:
    FloatIRGenerator(llvm::IRBuilder<>& ir_builder,llvm::LLVMContext& context)
    :IRGenerator(ir_builder,context){}
    llvm::Value* generate(Node& node);
};

class BinaryExpressionIRGenerator: public IRGenerator
{
public:
    BinaryExpressionIRGenerator(llvm::IRBuilder<>& ir_builder,llvm::LLVMContext& context)
    :IRGenerator(ir_builder,context){}
    llvm::Value* generate(BinaryExpressionNode& node);
};