#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "include/utils/scoped_collector.hpp"

namespace ast {
class NodeBase;
class IntegerNode;
class FloatNode;
class ArrayNode;
class StringNode;
class VariableNode;
class GlobalVariableNode;
class ArgumentNode;
class AssignmentNode;
class BinaryExpressionNode;
class CallFunctionNode;
class AccessElementNode;
class DeepCopyNode;
class BlockNode;
class IfNode;
class ForNode;
class GenericFunctionDeclarationNode;
class GenericFunctionNode;
class GenericClassNode;
class Node;
class RootNode;
}  // namespace ast

namespace module {
class Module;
}

namespace ast {

class Builder {
    private:
    std::shared_ptr<module::Module> module;
    int current_line_number;
    utils::Scope& current_scope;
    std::shared_ptr<RootNode> root;

    public:
    Builder(std::shared_ptr<module::Module> module, int line_number = 1);

    void count_line_number();

    const int get_current_line_number() const;

    void into_named_scope(std::string name);

    void into_anonymous_scope();

    void break_out_of_scope();

    std::shared_ptr<IntegerNode> create_integer(int num);

    std::shared_ptr<FloatNode> create_float(double num);

    std::shared_ptr<Node> create_minus(std::shared_ptr<Node> expr);

    std::shared_ptr<StringNode> create_string(std::string str);

    std::shared_ptr<Node> create_void();

    std::shared_ptr<ArrayNode> create_array(
        std::vector<std::shared_ptr<Node>> elements);

    std::shared_ptr<ArrayNode> create_array();

    std::shared_ptr<BinaryExpressionNode> create_binary_expression(
        std::shared_ptr<Node> node, std::shared_ptr<Node> other,
        const std::string& operator_type);

    std::shared_ptr<VariableNode> create_variable_definition(
        std::string name, std::shared_ptr<Node> node);

    std::shared_ptr<VariableNode> create_member_variable_definition(
        std::string name, std::shared_ptr<Node> node);

    std::shared_ptr<GlobalVariableNode> create_global_variable_definition(
        std::string name, std::shared_ptr<Node>);

    std::shared_ptr<ArgumentNode> create_argument(const std::string& name);

    std::shared_ptr<AssignmentNode> create_assignment(
        std::shared_ptr<Node> left, std::shared_ptr<Node> right);

    std::shared_ptr<AssignmentNode> create_assignment(
        std::shared_ptr<AccessElementNode> left, std::shared_ptr<Node> right);

    std::shared_ptr<DeepCopyNode> create_deep_copy(
        std::shared_ptr<Node> pointer, std::shared_ptr<Node> object);

    std::shared_ptr<BlockNode> create_block(
        std::vector<std::shared_ptr<Node>>&& expressions);

    std::shared_ptr<CallFunctionNode> create_call(
        std::string name, std::vector<std::shared_ptr<Node>> arguments);

    std::shared_ptr<CallFunctionNode> create_call(
        std::shared_ptr<AccessElementNode>,
        std::vector<std::shared_ptr<Node>> arguments);

    std::shared_ptr<IfNode> create_if(std::shared_ptr<Node> cond,
                                      std::shared_ptr<BlockNode> if_body,
                                      std::shared_ptr<BlockNode> else_body);

    std::shared_ptr<ForNode> create_for(std::shared_ptr<Node>,
                                        std::shared_ptr<Node>,
                                        std::shared_ptr<Node>,
                                        std::shared_ptr<BlockNode> body);

    std::shared_ptr<AccessElementNode> create_access(std::shared_ptr<Node> left,
                                                     std::string right);

    std::shared_ptr<GenericFunctionDeclarationNode>
    create_generic_function_declaration(
        std::string name, std::vector<std::shared_ptr<ArgumentNode>> arguments);

    std::shared_ptr<GenericFunctionDeclarationNode>
    create_generic_function_declaration(std::string name, int num_arguments);

    std::shared_ptr<GenericFunctionNode> create_generic_function_definition(
        std::string name,
        std::vector<std::shared_ptr<ast::ArgumentNode>> arguments,
        std::shared_ptr<BlockNode> body, std::shared_ptr<Node> return_value);

    std::shared_ptr<GenericClassNode> create_generic_class_definition(
        std::string name,
        std::vector<std::shared_ptr<ast::ArgumentNode>> arguments,
        std::vector<std::shared_ptr<VariableNode>> members_definition,
        std::vector<std::shared_ptr<GenericFunctionNode>> methods);

    /*std::shared_ptr<Node> create_generic_class_declaration(
        std::string name, std::vector<std::string> argument_names);
    */
    bool exist(std::string);

    std::shared_ptr<Node> get_named_node(std::string name);

    std::shared_ptr<RootNode> create_root(std::shared_ptr<BlockNode> program);

    std::shared_ptr<Node> build() const;
};

}  // namespace ast