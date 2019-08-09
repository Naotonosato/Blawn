#pragma once
#include <vector>
#include <string>
#include <map>
#include <memory>
#include <iostream>


class Node;
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
    std::vector<std::string> current_namespace;
    std::map<
        std::vector<std::string>,
        std::map<std::string,llvm::Value*>
            > 
        variables;
    std::map<
        std::vector<std::string>,
        std::map<std::string,std::shared_ptr<FunctionNode>>
            > 
        functions;
public:
    std::shared_ptr<IRGenerator> ir_generator;
    std::shared_ptr<IntergerIRGenerator> int_ir_generator;
    std::shared_ptr<FloatIRGenerator> float_ir_generator;
    std::shared_ptr<VariableIRGenerator> variable_generator;
    std::shared_ptr<BinaryExpressionIRGenerator> binary_expression_generator;
    std::shared_ptr<FunctionIRGenerator> function_generator;
    std::shared_ptr<CallFunctionIRGenerator> calling_generator;
    ASTGenerator(llvm::Module &module,
    llvm::IRBuilder<> &ir_builder,
    llvm::LLVMContext &context);
    void into_namespace(std::string name);
    void break_out_of_namespace();
    std::unique_ptr<BinaryExpressionNode> attach_operator(std::unique_ptr<Node> node,std::unique_ptr<Node> other,const std::string operator_type);
    std::unique_ptr<VariableNode> add_variable(std::string name,std::unique_ptr<Node> node);
    std::unique_ptr<VariableNode> get_variable(std::string name);
    void add_argument(std::string);
    std::unique_ptr<IntergerNode> create_interger(int num);
    std::unique_ptr<FloatNode> create_float(double num);
    void book_function(std::string name,std::vector<std::string> arguments,std::vector<std::unique_ptr<Node>> body,std::unique_ptr<Node> return_value);
    std::unique_ptr<Node> call_function(std::string name,std::vector<std::unique_ptr<Node>> arguments);
    void generate();
    std::string get_namespace_as_string();
};