#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "../errors/errors.hpp"

template <typename T>
class NodeCollector;
namespace ast {
class Node;
class FunctionNode;
}  // namespace ast
class IntegerIRGenerator;
class FloatIRGenerator;
namespace llvm {
class Module;
template <typename T, typename Inserter>
class IRBuilder;
class Value;
}  // namespace llvm

class ASTGenerator {
    private:
    llvm::Module &module;
    llvm::IRBuilder<> &ir_builder;
    llvm::LLVMContext &context;
    NodeCollector<ast::VariableNode> variable_collector;
    NodeCollector<ast::FunctionNode> function_collector;
    NodeCollector<ast::ArgumentNode> argument_collector;
    NodeCollector<ast::ClassNode> class_collector;
    NodeCollector<ast::ClassNode> C_type_collector;
    std::map<std::string, std::shared_ptr<ast::VariableNode> &>
        access_namespace(std::vector<std::string>);
    Scope current_scope;

    public:
    IRGenerators ir_generators;
    int line_number;
    std::shared_ptr<ast::Node> no_value_node;
    BlawnLogger logger;
    ASTGenerator(llvm::Module &module, llvm::IRBuilder<> &ir_builder,
                 llvm::LLVMContext &context, int line_number = 1);
    void into_namespace(std::string name);
    void into_namespace();
    void break_out_of_namespace();
    std::shared_ptr<ast::BinaryExpressionNode> attach_operator(
        std::shared_ptr<ast::Node> node, std::shared_ptr<ast::Node> other,
        const std::string operator_type);
    std::shared_ptr<ast::Node> create_assign(std::string name,
                                             std::shared_ptr<ast::Node> node,
                                             bool is_global);
    std::shared_ptr<ast::Node> create_assign(
        std::shared_ptr<ast::AccessNode> left,
        std::shared_ptr<ast::Node> right);
    std::shared_ptr<ast::Node> create_assign_typeid(
        std::string name, std::shared_ptr<ast::Node> type_id);
    std::shared_ptr<ast::Node> create_store(std::shared_ptr<ast::Node> pointer,
                                            std::shared_ptr<ast::Node> object);
    std::shared_ptr<ast::Node> get_typeid(std::string name);
    std::shared_ptr<ast::Node> get_named_value(std::string name);
    std::shared_ptr<ast::Node> create_C_member(std::string name);
    std::shared_ptr<ast::Node> add_global_variables(
        std::vector<std::shared_ptr<ast::Node>>);
    std::shared_ptr<ast::Node> declare_C_function(
        std::string name, std::vector<std::shared_ptr<ast::Node>> args,
        std::shared_ptr<ast::Node> return_);
    void add_argument(std::string);
    std::shared_ptr<ast::IntegerNode> create_integer(int num);
    std::shared_ptr<ast::FloatNode> create_float(double num);
    std::shared_ptr<ast::Node> create_minus(std::shared_ptr<ast::Node> expr);
    std::shared_ptr<ast::StringNode> create_string(std::string str);
    void book_function(std::string name);
    std::shared_ptr<ast::FunctionNode> add_function(
        std::string name, std::vector<std::string> arguments,
        std::vector<std::shared_ptr<ast::Node>> body,
        std::shared_ptr<ast::Node> return_value);
    std::shared_ptr<ast::Node> create_call(
        std::string name, std::vector<std::shared_ptr<ast::Node>> arguments);
    std::shared_ptr<ast::Node> create_call(
        std::shared_ptr<ast::AccessNode>,
        std::vector<std::shared_ptr<ast::Node>> arguments);
    std::shared_ptr<ast::ClassNode> create_class(
        std::string, std::vector<std::string> arguments,
        std::vector<std::shared_ptr<ast::Node>> members_definition,
        std::vector<std::shared_ptr<ast::FunctionNode>> body);
    std::shared_ptr<ast::ClassNode> create_C_type(
        std::string name,
        std::vector<std::shared_ptr<ast::Node>> members_definition);
    std::shared_ptr<ast::Node> create_if(
        std::shared_ptr<ast::Node> cond,
        std::vector<std::shared_ptr<ast::Node>> if_body,
        std::vector<std::shared_ptr<ast::Node>> else_body);
    std::shared_ptr<ast::Node> create_for(
        std::shared_ptr<ast::Node>, std::shared_ptr<ast::Node>,
        std::shared_ptr<ast::Node>,
        std::vector<std::shared_ptr<ast::Node>> body);
    std::shared_ptr<ast::AccessNode> create_access(std::string left,
                                                   std::string right);
    std::shared_ptr<ast::AccessNode> create_access(
        std::shared_ptr<ast::Node> left, std::string right);
    std::shared_ptr<ast::ArrayNode> create_list(
        std::vector<std::shared_ptr<ast::Node>> elements);
    std::shared_ptr<ast::ArrayNode> create_list();
    std::shared_ptr<ast::Node> create_block_end();
    void generate(std::vector<std::shared_ptr<ast::Node>>);
};