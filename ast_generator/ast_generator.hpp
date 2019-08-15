#pragma once
#include <vector>
#include <string>
#include <map>
#include <memory>
#include <iostream>

template<typename T>
class NodeCollector;
class Node;
class FunctionNode;
class IntergerIRGenerator;
class FloatIRGenerator;
namespace llvm
{
    class Module;
    template<typename T,typename Inserter>
    class IRBuilder;
    class Value;
}

 
class ASTGenerator
{
public:
    ~ASTGenerator();
private:
    llvm::Module &module;
    llvm::IRBuilder<> &ir_builder;
    llvm::LLVMContext &context;
    std::shared_ptr<NodeCollector<VariableNode>> variable_collector;
    std::shared_ptr<NodeCollector<FunctionNode>> function_collector;
    std::shared_ptr<NodeCollector<ArgumentNode>> argument_collector;
    std::map<std::string,std::shared_ptr<VariableNode>&> access_namespace(std::vector<std::string>);
public:
    std::shared_ptr<IRGenerator> ir_generator;
    std::shared_ptr<IntergerIRGenerator> int_ir_generator;
    std::shared_ptr<FloatIRGenerator> float_ir_generator;
    std::shared_ptr<VariableIRGenerator> variable_generator;
    std::shared_ptr<ArgumentIRGenerator> argument_generator;
    std::shared_ptr<AssigmentIRGenerator> assigment_generator;
    std::shared_ptr<BinaryExpressionIRGenerator> binary_expression_generator;
    std::shared_ptr<FunctionIRGenerator> function_generator;
    std::shared_ptr<CallFunctionIRGenerator> calling_generator;
    ASTGenerator(llvm::Module &module,
    llvm::IRBuilder<> &ir_builder,
    llvm::LLVMContext &context);
    void into_namespace(std::string name);
    void break_out_of_namespace();
    std::unique_ptr<BinaryExpressionNode> attach_operator(std::shared_ptr<Node> node,std::shared_ptr<Node> other,const std::string operator_type);
    std::shared_ptr<Node> assign(std::string name,std::shared_ptr<Node> node);
    std::shared_ptr<Node> get_named_value(std::string name);
    void add_argument(std::string);
    std::unique_ptr<IntergerNode> create_interger(int num);
    std::unique_ptr<FloatNode> create_float(double num);
    std::shared_ptr<FunctionNode> book_function(std::string name,std::vector<std::string> arguments,std::vector<std::shared_ptr<Node>> body,std::shared_ptr<Node> return_value);
    std::unique_ptr<Node> call_function(std::string name,std::vector<std::shared_ptr<Node>> arguments);
    void generate();
};