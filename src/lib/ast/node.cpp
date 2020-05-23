#include <algorithm>
#include "include/ast/node.hpp"

namespace ast
{
const unsigned long NodeBase::get_id() const { return id; }

const debug::DebugInfo& NodeBase::get_debug_info() const { return debug_info; }

const std::vector<std::unique_ptr<Node>>& RootNode::get_children() const
{
    return children;
}

const uint64_t IntegerNode::get_initial_value() const { return initial_value; }

const double FloatNode::get_initial_value() const { return initial_value; }

const std::optional<std::vector<std::unique_ptr<Node>>>&
ArrayNode::get_initial_values() const
{
    return initial_values;
}

const std::string& StringNode::get_initial_value() const
{
    return initial_value;
}

const std::string& VariableNode::get_name() const { return name; }

const std::string& VariableDefinitionNode::get_name() const { return name; }

const Node& VariableDefinitionNode::get_initial_value() const
{
    return *initial_value;
}
/*
const std::optional<std::reference_wrapper<Node>>&
UninitializedVariableNode::get_initial_value() const {
    if (initial_value.has_value()) {
        return *initial_value.value();
    }
    return std::nullopt;
}
*/

const std::string ArgumentNode::get_name() const { return name; }

const Node& AssignmentNode::get_left_hand_side() const
{
    return *left_hand_side;
}

const Node& AssignmentNode::get_right_hand_side() const
{
    return *right_hand_side;
}

BinaryExpressionKind string_to_operator_type(const std::string& name)
{
    if (name == "ADD") return ADD;
    if (name == "SUB") return SUB;
    if (name == "MUL") return MUL;
    if (name == "DIV") return DIV;
    assert(false && "Unknown BinaryExpressionKind");
}

const BinaryExpressionKind BinaryExpressionNode::get_operator_kind() const
{
    return operator_kind;
}

const Node& BinaryExpressionNode::get_left_hand_side() const
{
    return *left_hand_side;
}

const Node& BinaryExpressionNode::get_right_hand_side() const
{
    return *right_hand_side;
}

const Node& CallFunctionNode::get_function() const { return *function; }

const std::vector<std::unique_ptr<Node>>& CallFunctionNode::get_arguments()
    const
{
    return arguments;
}

const Node& AccessElementNode::get_left_hand_side() const
{
    return *left_hand_side;
}

const std::string& AccessElementNode::get_element_name() const
{
    return element_name;
}

const Node& DeepCopyNode::get_left_hand_side() const { return *left_hand_side; }

const Node& DeepCopyNode::get_right_hand_side() const
{
    return *right_hand_side;
}

const std::vector<std::unique_ptr<Node>>& BlockNode::get_expressions() const
{
    return expressions;
}

const Node& IfNode::get_body() const { return *body; }

const Node& IfNode::get_condition() const { return *condition; }

const Node& ForNode::get_body() const { return *body; }

const Node& ForNode::get_first_expression() const { return *first_expression; }

const Node& ForNode::get_condition() const { return *condition; }

const Node& ForNode::get_last_expression() const { return *last_expression; }

const std::string& GenericFunctionDeclarationNode::get_name() const
{
    return name;
}

const int GenericFunctionDeclarationNode::get_num_arguments() const
{
    return num_arguments;
}

const std::string& GenericFunctionNode::get_name() const { return name; }

const std::vector<std::unique_ptr<Node>>& GenericFunctionNode::get_arguments()
    const
{
    return arguments;
}

const Node& GenericFunctionNode::get_body() const { return *body; }

const std::string& GenericClassNode::get_name() const { return name; }

const std::vector<std::unique_ptr<Node>>& GenericClassNode::get_arguments()
    const
{
    return arguments;
}

const std::vector<std::unique_ptr<Node>>&
GenericClassNode::get_member_variables() const
{
    return member_variables;
}

const std::vector<std::unique_ptr<Node>>&
GenericClassNode::get_member_functions() const
{
    return member_functions;
}

const Node& TypeIdNode::get_node() const { return *node; }

const Node& CastNode::get_target_type_id_node() const
{
    return *target_type_id_node;
}

const Node& CastNode::get_node() const { return *node; }

}  // namespace ast