#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "include/scope/scoped_collector.hpp"

namespace ast
{
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

namespace debug
{
class DebugInfo;
}

namespace ast
{
enum NodeExistsState
{
    EXISTS,
    NOT_EXISTS,
    NO_DEFINITION
};

class Builder
{
    private:
    const std::string filename;
    unsigned long current_line_number;
    unsigned long current_token_index;
    std::string current_token;
    scope::ScopedCollector<NodeExistsState> ast_container;
    scope::ScopeID& current_scope_id;
    std::unique_ptr<Node> root;

    public:
    Builder(std::string filename);

    void count_line_number();

    void count_token_index(int index);

    void set_token(std::string token);

    debug::DebugInfo create_current_debug_info();

    void into_named_scope(std::string name);

    void into_anonymous_scope();

    void break_out_of_scope();

    std::unique_ptr<Node> create_integer(int num);

    std::unique_ptr<Node> create_float(double num);

    std::unique_ptr<Node> create_minus(std::unique_ptr<Node>&& expr);

    std::unique_ptr<Node> create_string(std::string str);

    std::unique_ptr<Node> create_void();

    std::unique_ptr<Node> create_lazy();

    std::unique_ptr<Node> create_array(
        std::vector<std::unique_ptr<Node>>&& elements);

    std::unique_ptr<Node> create_array();

    std::unique_ptr<Node> create_binary_expression(
        std::unique_ptr<Node>&& node, std::unique_ptr<Node>&& other,
        const std::string& operator_type);

    std::unique_ptr<Node> create_variable_definition(
        std::string name, std::unique_ptr<Node>&& node);

    std::unique_ptr<Node> create_member_variable_definition(
        std::string name, std::unique_ptr<Node>&& node);

    std::unique_ptr<Node> create_global_variable_definition(
        std::string name, std::unique_ptr<Node>&&);

    std::unique_ptr<Node> create_argument(std::string name);

    std::unique_ptr<Node> create_assignment(std::unique_ptr<Node>&& left,
                                            std::unique_ptr<Node>&& right);

    std::unique_ptr<Node> create_deep_copy(std::unique_ptr<Node>&& pointer,
                                           std::unique_ptr<Node>&& object);

    std::unique_ptr<Node> create_block(
        std::vector<std::unique_ptr<Node>>&& expressions);

    std::unique_ptr<Node> create_call(
        std::unique_ptr<Node>&&,
        std::vector<std::unique_ptr<Node>>&& arguments);

    std::unique_ptr<Node> create_call(
        const std::string& name,
        std::vector<std::unique_ptr<Node>>&& arguments);

    std::unique_ptr<Node> create_if(std::unique_ptr<Node>&& cond,
                                    std::unique_ptr<Node>&& if_body,
                                    std::unique_ptr<Node>&& else_body);

    std::unique_ptr<Node> create_for(std::unique_ptr<Node>&& first_expression,
                                     std::unique_ptr<Node>&& condition,
                                     std::unique_ptr<Node>&& last_expression,
                                     std::unique_ptr<Node>&& body);

    std::unique_ptr<Node> create_access(std::unique_ptr<Node>&& left,
                                        std::string right);

    std::unique_ptr<Node> create_generic_function_declaration(
        std::string name, std::vector<std::unique_ptr<Node>>&& arguments);

    std::unique_ptr<Node> create_generic_function_declaration(
        std::string name, int num_arguments);

    std::unique_ptr<Node> create_generic_function_definition(
        const std::string& name, std::vector<std::unique_ptr<Node>>&& arguments,
        std::unique_ptr<Node>&& body);

    std::unique_ptr<Node> create_generic_class_definition(
        const std::string& name, std::vector<std::unique_ptr<Node>>&& arguments,
        std::vector<std::unique_ptr<Node>>&& members_definition,
        std::vector<std::unique_ptr<Node>>&& methods);

    bool exist_named_expression(std::string name);

    std::unique_ptr<Node> create_named_node(std::string name);

    void create_root(std::vector<std::unique_ptr<Node>>&& program);

    Node& build() const;
};

}  // namespace ast