#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "../errors/errors.hpp"
#include "../utils/scoped_collector.hpp"

namespace ast {
class NodeBase;
class VariableNode;
class ArgumentNode;
class GenericFunctionNode;
class GenericClassNode;
class Node;
}  // namespace ast

namespace ast {

class Builder {
    private:
    int current_line_number;
    utils::ScopedCollector<std::shared_ptr<Node>> node_collector;
    utils::Scope current_scope;

    std::map<std::string, std::shared_ptr<Node>> access_namespace(
        std::vector<std::string>&&);

    public:
    Builder(int line_number = 1);

    void count_line_number();

    void into_named_scope(std::string name);

    void into_anonymous_scope();

    void break_out_of_scope();

    std::shared_ptr<Node> create_integer(int num);

    std::shared_ptr<Node> create_float(double num);

    std::shared_ptr<Node> create_minus(std::shared_ptr<Node> expr);

    std::shared_ptr<Node> create_string(std::string str);

    std::shared_ptr<Node> create_void();

    std::shared_ptr<Node> create_binary_expression(
        std::shared_ptr<Node> node, std::shared_ptr<Node> other,
        const std::string operator_type);

    std::shared_ptr<Node> create_variable_definition(
        std::string name, std::shared_ptr<Node> node);

    std::shared_ptr<Node> create_member_variable_definition(
        std::string name, std::shared_ptr<Node> node);

    std::shared_ptr<Node> create_global_variable_definition(
        std::string name, std::shared_ptr<Node>);

    std::shared_ptr<Node> create_assignment(std::shared_ptr<Node> left,
                                            std::shared_ptr<Node> right);

    std::shared_ptr<Node> create_deep_copy(std::shared_ptr<Node> pointer,
                                           std::shared_ptr<Node> object);

    std::shared_ptr<Node> create_block(
        std::vector<std::shared_ptr<Node>>&& expressions);

    std::shared_ptr<Node> create_call(
        std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>> arguments);

    std::shared_ptr<Node> create_if(std::shared_ptr<Node> cond,
                                    std::shared_ptr<Node> if_body,
                                    std::shared_ptr<Node> else_body);

    std::shared_ptr<Node> create_for(std::shared_ptr<Node>,
                                     std::shared_ptr<Node>,
                                     std::shared_ptr<Node>,
                                     std::shared_ptr<Node> body);

    std::shared_ptr<Node> create_access(std::shared_ptr<Node> left,
                                        std::string right);

    std::shared_ptr<Node> create_array(
        std::vector<std::shared_ptr<Node>> elements);

    std::shared_ptr<Node> create_array();

    std::shared_ptr<Node> create_generic_function_declaration(
        std::string name, std::vector<std::string> argument_names);

    std::shared_ptr<Node> create_generic_function_definition(
        std::string name, std::vector<std::string> arguments,
        std::shared_ptr<Node> body, std::shared_ptr<Node> return_value);

    std::shared_ptr<Node> create_generic_class_definition(
        std::string name, std::vector<std::string> arguments,
        std::vector<std::shared_ptr<Node>> members_definition,
        std::vector<std::shared_ptr<Node>> methods);

    std::shared_ptr<Node> create_generic_class_declaration(
        std::string name, std::vector<std::string> argument_names);

    bool exist(const std::string&) const;
    std::shared_ptr<Node> get_named_node(std::string name);

    void set_all_program(std::shared_ptr<Node>&& program);
};

}  // namespace ast