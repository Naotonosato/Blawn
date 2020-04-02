#include <algorithm>
#include "include/ast/node.hpp"

namespace ast {

std::shared_ptr<BlockNode> RootNode::get_child_block() const {
    return child_block;
}

const uint64_t IntegerNode::get_initial_value() const { return initial_value; }

const double FloatNode::get_initial_value() const { return initial_value; }

const std::optional<std::vector<std::shared_ptr<Node>>>
ArrayNode::get_initial_values() const {
    return initial_values;
}

const std::string& StringNode::get_initial_value() const {
    return initial_value;
}

const std::string& VariableNode::get_name() const { return name; }

std::shared_ptr<Node> VariableNode::get_initial_value() const {
    return initial_value;
}

std::shared_ptr<Node> GlobalVariableNode::get_initial_value() const {
    return initial_value;
}

const std::string ArgumentNode::get_name() const { return name; }

std::shared_ptr<Node> AssignmentNode::get_left_hand_side() const {
    return left_hand_side;
}

std::shared_ptr<Node> AssignmentNode::get_right_hand_side() const {
    return right_hand_side;
}

BinaryExpressionKind string_to_operator_type(const std::string& name) {
    if (name == "ADD") return ADD;
    if (name == "SUB") return SUB;
    if (name == "MUL") return MUL;
    if (name == "DIV") return DIV;
    assert(false && "Unknown BinaryExpressionKind");
}

const BinaryExpressionKind BinaryExpressionNode::get_operator_kind() const {
    return operator_kind;
}

std::shared_ptr<Node> BinaryExpressionNode::get_left_hand_side() const {
    return left_hand_side;
}

std::shared_ptr<Node> BinaryExpressionNode::get_right_hand_side() const {
    return right_hand_side;
}

std::shared_ptr<GenericFunctionDeclarationNode> CallFunctionNode::get_function()
    const {
    return function;
}

std::vector<std::shared_ptr<Node>>& CallFunctionNode::get_arguments() {
    return arguments;
}

std::shared_ptr<Node> AccessElementNode::get_left_hand_side() const {
    return left_hand_side;
}

const std::string& AccessElementNode::get_element_name() const {
    return element_name;
}

std::shared_ptr<Node> DeepCopyNode::get_left_hand_side() const {
    return left_hand_side;
}

std::shared_ptr<Node> DeepCopyNode::get_right_hand_side() const {
    return right_hand_side;
}

std::vector<std::shared_ptr<Node>>& BlockNode::get_expressions() {
    return expressions;
}

std::shared_ptr<BlockNode> IfNode::get_block() const { return block; }

std::shared_ptr<Node> IfNode::get_condition() const { return condition; }

std::shared_ptr<BlockNode> ForNode::get_block() const { return block; }

std::shared_ptr<Node> ForNode::get_first_expression() const {
    return first_expression;
}

std::shared_ptr<Node> ForNode::get_condition() const { return condition; }

std::shared_ptr<Node> ForNode::get_last_expression() const {
    return last_expression;
}

const std::string& GenericFunctionDeclarationNode::get_name() const {
    return name;
}

const int GenericFunctionDeclarationNode::get_num_arguments() const {
    return num_arguments;
}

void GenericFunctionDeclarationNode::set_definition(
    std::shared_ptr<GenericFunctionNode> definition_) {
    definition = definition_;
}

std::optional<std::shared_ptr<GenericFunctionNode>>
GenericFunctionDeclarationNode::get_definition() const {
    return definition;
}

const std::string& GenericFunctionNode::get_name() const { return name; }

std::vector<std::shared_ptr<ArgumentNode>>&
GenericFunctionNode::get_arguments() {
    return arguments;
}

std::shared_ptr<BlockNode> GenericFunctionNode::get_body() const {
    return body;
}

std::shared_ptr<Node> GenericFunctionNode::get_return_value() const {
    return return_value;
}

const std::string& GenericClassNode::get_name() const { return name; }

std::vector<std::shared_ptr<ArgumentNode>>& GenericClassNode::get_arguments() {
    return arguments;
}

std::vector<std::shared_ptr<VariableNode>>
GenericClassNode::get_member_variables() const {
    return member_variables;
}

std::vector<std::shared_ptr<GenericFunctionNode>>
GenericClassNode::get_methods() const {
    return methods;
}

std::shared_ptr<Node> TypeIdNode::get_node() const { return node; }

std::shared_ptr<TypeIdNode> CastNode::get_target_type_id_node() const {
    return target_type_id_node;
}

std::shared_ptr<Node> CastNode::get_node() const { return node; }

}  // namespace ast