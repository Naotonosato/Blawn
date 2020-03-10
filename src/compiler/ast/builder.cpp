#include "node.hpp"
#include "../utils/scoped_collector.hpp"
#include "builder.hpp"

namespace ast {

Builder::Builder(int line_number)
    : current_line_number(line_number),
      node_collector(utils::ScopedCollector<std::shared_ptr<Node>>("[GLOBAL]")),
      current_scope(node_collector.get_scope()) {}

void Builder::into_named_scope(std::string name) {
    node_collector.into_named_scope(name);
}

void Builder::into_anonymous_scope() { node_collector.into_anonymous_scope(); }

void Builder::break_out_of_scope() { node_collector.break_out_of_namespace(); }

std::shared_ptr<Node> create_binary_expression(std::shared_ptr<Node> node,
                                               std::shared_ptr<Node> other,
                                               const std::string operator_type);

std::shared_ptr<Node> Builder::create_variable_definition(
    std::string name, std::shared_ptr<Node> right_node) {
    auto variable =
        Node::create<VariableNode>(current_line_number, name, right_node);
    node_collector.add(name, variable);
    return variable;
}

std::shared_ptr<Node> Builder::create_integer(int num) {
    return Node::create<IntegerNode>(current_line_number, num);
}

std::shared_ptr<Node> Builder::create_float(double num) {
    return Node::create<FloatNode>(current_line_number, num);
}

std::shared_ptr<Node> Builder::create_minus(std::shared_ptr<Node> expr) {
    auto zero = Node::create<IntegerNode>(current_line_number, 0);
    return create_binary_expression(zero, expr, "-");
}

std::shared_ptr<Node> Builder::create_string(std::string str) {
    return Node::create<StringNode>(current_line_number, str);
}

std::shared_ptr<Node> Builder::create_block(
    std::vector<std::shared_ptr<Node>>&& expressions) {
    return Node::create<BlockNode>(current_line_number, std::move(expressions));
}

std::shared_ptr<Node> Builder::create_array(
    std::vector<std::shared_ptr<Node>> elements) {
    return Node::create<ArrayNode>(current_line_number, std::move(elements));
}

std::shared_ptr<Node> Builder::create_array() {
    return Node::create<ArrayNode>(current_line_number);
}

std::shared_ptr<Node> Builder::create_generic_function_declaration(
    std::string name, std::vector<std::string> argument_names) {
    auto declaration = Node::create<GenericFunctionNode>(
        current_line_number, name, std::move(argument_names));
    return declaration;
}

std::shared_ptr<Node> Builder::create_generic_function_definition(
    std::string name, std::vector<std::string> arguments,
    std::shared_ptr<Node> body, std::shared_ptr<Node> return_value) {
    auto declaration =
        std::move(*node_collector.get(name))->get<GenericFunctionNode>();
    declaration.set_body(body);
    declaration.set_return_value(return_value);
    return *node_collector.get(name);
}

std::shared_ptr<Node> Builder::create_generic_class_declaration(
    std::string name, std::vector<std::string> argument_names) {
    auto declaration = Node::create<GenericClassNode>(
        current_line_number, name, std::move(argument_names));
    return declaration;
}

std::shared_ptr<Node> Builder::create_generic_class_definition(
    std::string name, std::vector<std::string> arguments,
    std::vector<std::shared_ptr<Node>> members,
    std::vector<std::shared_ptr<Node>> methods) {
    auto declaration =
        std::move(*node_collector.get(name))->get<GenericClassNode>();
    declaration.set_member_variables(std::move(members));
    declaration.set_methods(std::move(methods));
    return *node_collector.get(name);
}

bool Builder::exist(const std::string& name) const {
    return node_collector.get(name) != std::nullopt;
}

std::shared_ptr<Node> Builder::get_named_node(std::string name) {
    auto node = node_collector.get(name);
    if (node == std::nullopt) {
        return nullptr;
    }
    return *node;
}

}  // namespace ast