#include <memory>
//forward declaration
class Node;
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
    llvm::LLVMContext context;
    llvm::IRBuilder<> ir_builder;
    IRGenerator(const llvm::IRBuilder<>& ir_builder):ir_builder(ir_builder){};
    virtual std::shared_ptr<llvm::Value> generate(Node& node){};
};


class IntergerIRGenerator: public IRGenerator
{
public:
    IntergerIRGenerator(const llvm::IRBuilder<>& ir_builder): IRGenerator(ir_builder){}

    std::shared_ptr<llvm::Value> generate(Node& node);
};


class FloatIRGenerator: public IRGenerator
{
public:
    FloatIRGenerator(const llvm::IRBuilder<>& ir_builder): IRGenerator(ir_builder){}
    std::shared_ptr<llvm::Value> generate(Node& node);
};

class BinaryExpressionIRGenerator: public IRGenerator
{
public:
    BinaryExpressionIRGenerator(const llvm::IRBuilder<>& ir_builder): IRGenerator(ir_builder){}
    std::shared_ptr<llvm::Value> generate(Node& node);
};