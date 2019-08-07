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
        std::map<std::string,std::shared_ptr<VariableNode>>
            > 
        variables;
    std::map<
        std::vector<std::string>,
        std::map<std::string,std::shared_ptr<FunctionNode>>
            > 
        unsolved_functions;
public:
    std::shared_ptr<IRGenerator> ir_generator;
    std::shared_ptr<IntergerIRGenerator> int_ir_generator;
    std::shared_ptr<FloatIRGenerator> float_ir_generator;
    std::shared_ptr<VariableIRGenerator> variable_generator;
    std::shared_ptr<BinaryExpressionIRGenerator> binary_expression_generator;
    ASTGenerator(llvm::Module &module,
    llvm::IRBuilder<> &ir_builder,
    llvm::LLVMContext &context);
    void into_namespace(std::string name);
    void break_out_of_namespace();
    std::shared_ptr<BinaryExpressionNode> attach_operator(std::shared_ptr<Node> node,std::shared_ptr<Node> other,const std::string operator_type);
    std::shared_ptr<VariableNode> add_variable(std::string name,std::shared_ptr<Node> node);
    std::shared_ptr<VariableNode> get_variable(std::string name);
    std::shared_ptr<IntergerNode> create_interger(int num);
    std::shared_ptr<FloatNode> create_float(double num);
    void book_function(std::string name,std::vector<std::string> arguments,std::vector<std::shared_ptr<Node>> body);
    std::shared_ptr<Node> call_function(std::string name,std::vector<std::shared_ptr<Node>> arguments);
    void generate();
};