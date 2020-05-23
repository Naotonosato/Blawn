#pragma once
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>
#include <optional>
#include "include/utils/variant_wrapper.hpp"
#include <iostream>
#include "include/utils/unique_number.hpp"
#include "include/debug/debug_info.hpp"

namespace ast
{
class Node;

class NodeBase
{
    private:
    unsigned long id;
    debug::DebugInfo debug_info;

    public:
    NodeBase(debug::DebugInfo&& debug_info)
        : id(utils::get_unique_number()), debug_info(std::move(debug_info))
    {
    }
    NodeBase() = delete;
    NodeBase(const NodeBase&) = delete;
    NodeBase(NodeBase&&) = default;

    public:
    template <typename... Args>
    void* operator new(size_t, Args&&...)
    {
        // delay evaluation until instantiation
        constexpr bool operator_new_is_not_used = [] { return false; }();
        static_assert(operator_new_is_not_used,
                      "Class that inherits from 'NodeBase' cannot be "
                      "initialized with operator new.");
    }
    const unsigned long get_id() const;
    const debug::DebugInfo& get_debug_info() const;
};

class BlockNode;

class RootNode : public NodeBase
{
    private:
    std::vector<std::unique_ptr<Node>> children;

    public:
    RootNode(debug::DebugInfo&& debug_info,
             std::vector<std::unique_ptr<Node>>&& children)
        : NodeBase(std::move(debug_info)), children(std::move(children))
    {
    }

    const std::vector<std::unique_ptr<Node>>& get_children() const;
};

class IntegerNode : public NodeBase
{
    private:
    uint64_t initial_value;

    public:
    IntegerNode(debug::DebugInfo&& debug_info, uint64_t initial_value)
        : NodeBase(std::move(debug_info)), initial_value(initial_value)
    {
    }
    const uint64_t get_initial_value() const;
};

class FloatNode : public NodeBase
{
    private:
    double initial_value;

    public:
    FloatNode(debug::DebugInfo&& debug_info, double initial_value)
        : NodeBase(std::move(debug_info)), initial_value(initial_value)
    {
    }
    const double get_initial_value() const;
};

class ArrayNode : public NodeBase
{
    private:
    std::optional<std::vector<std::unique_ptr<Node>>> initial_values;

    public:
    ArrayNode(debug::DebugInfo&& debug_info) : NodeBase(std::move(debug_info))
    {
    }
    ArrayNode(debug::DebugInfo&& debug_info,
              std::vector<std::unique_ptr<Node>> initial_values)
        : NodeBase(std::move(debug_info)),
          initial_values(std::move(initial_values))
    {
    }

    const std::optional<std::vector<std::unique_ptr<Node>>>&
    get_initial_values() const;
};

class StringNode : public NodeBase
{
    private:
    std::string initial_value;

    public:
    StringNode(debug::DebugInfo&& debug_info, const std::string initial_value)
        : NodeBase(std::move(debug_info)), initial_value(initial_value)
    {
    }
    const std::string& get_initial_value() const;
};

class LazyNode : public NodeBase
{
    public:
    LazyNode(debug::DebugInfo&& debug_info) : NodeBase(std::move(debug_info)) {}
};

class VariableNode : public NodeBase
{
    private:
    std::string name;

    public:
    VariableNode(debug::DebugInfo&& debug_info, std::string name)
        : NodeBase(std::move(debug_info)), name(name)
    {
    }
    const std::string& get_name() const;
};

class VariableDefinitionNode : public NodeBase
{
    private:
    std::string name;
    std::unique_ptr<Node> initial_value;

    public:
    VariableDefinitionNode(debug::DebugInfo&& debug_info, std::string name,
                           std::unique_ptr<Node>&& initial_value)
        : NodeBase(std::move(debug_info)),
          name(name),
          initial_value(std::move(initial_value))
    {
    }
    const std::string& get_name() const;
    const Node& get_initial_value() const;
};

class GlobalVariableNode : public NodeBase
{
    private:
    std::string name;
    std::unique_ptr<Node> initial_value;

    public:
    GlobalVariableNode(debug::DebugInfo&& debug_info, std::string name,
                       std::unique_ptr<Node>&& initial_value)
        : NodeBase(std::move(debug_info)),
          name(name),
          initial_value(std::move(initial_value))
    {
    }

    const Node& get_initial_value() const;
};

class ArgumentNode : public NodeBase
{
    private:
    std::string name;

    public:
    ArgumentNode(debug::DebugInfo&& debug_info, std::string name)
        : NodeBase(std::move(debug_info)), name(name)
    {
    }
    const std::string get_name() const;
};

class AssignmentNode : public NodeBase
{
    private:
    std::unique_ptr<Node> left_hand_side;
    std::unique_ptr<Node> right_hand_side;

    public:
    AssignmentNode(debug::DebugInfo&& debug_info,
                   std::unique_ptr<Node>&& left_hand_side,
                   std::unique_ptr<Node>&& right_hand_side)
        : NodeBase(std::move(debug_info)),
          left_hand_side(std::move(left_hand_side)),
          right_hand_side(std::move(right_hand_side))
    {
    }
    const Node& get_left_hand_side() const;
    const Node& get_right_hand_side() const;
};

enum BinaryExpressionKind
{
    ADD,
    SUB,
    MUL,
    DIV
};

BinaryExpressionKind string_to_operator_type(const std::string& name);

class BinaryExpressionNode : public NodeBase
{
    private:
    std::unique_ptr<Node> left_hand_side;
    std::unique_ptr<Node> right_hand_side;
    BinaryExpressionKind operator_kind;

    public:
    BinaryExpressionNode(debug::DebugInfo&& debug_info,
                         BinaryExpressionKind operator_kind,
                         std::unique_ptr<Node>&& left_hand_side,
                         std::unique_ptr<Node>&& right_hand_side)
        : NodeBase(std::move(debug_info)),
          operator_kind(operator_kind),
          left_hand_side(std::move(left_hand_side)),
          right_hand_side(std::move(right_hand_side))
    {
    }
    const BinaryExpressionKind get_operator_kind() const;
    const Node& get_left_hand_side() const;
    const Node& get_right_hand_side() const;
};

class GenericFunctionDeclarationNode;

class CallFunctionNode : public NodeBase
{
    private:
    std::unique_ptr<Node> function;
    std::vector<std::unique_ptr<Node>> arguments;

    public:
    CallFunctionNode(debug::DebugInfo&& debug_info,
                     std::unique_ptr<Node>&& function,
                     std::vector<std::unique_ptr<Node>>&& arguments)
        : NodeBase(std::move(debug_info)),
          function(std::move(function)),
          arguments(std::move(arguments))
    {
    }

    const Node& get_function() const;
    const std::vector<std::unique_ptr<Node>>& get_arguments() const;
};

class AccessElementNode : public NodeBase
{
    private:
    std::unique_ptr<Node> left_hand_side;
    const std::string element_name;

    public:
    AccessElementNode(debug::DebugInfo&& debug_info,
                      std::unique_ptr<Node>&& left_hand_side,
                      std::string element_name)
        : NodeBase(std::move(debug_info)),
          left_hand_side(std::move(left_hand_side)),
          element_name(element_name)
    {
    }
    const Node& get_left_hand_side() const;
    const std::string& get_element_name() const;
};

class DeepCopyNode : public NodeBase
{
    private:
    std::unique_ptr<Node> left_hand_side;
    std::unique_ptr<Node> right_hand_side;

    public:
    DeepCopyNode(debug::DebugInfo&& debug_info,
                 std::unique_ptr<Node>&& left_hand_side,
                 std::unique_ptr<Node>&& right_hand_side)
        : NodeBase(std::move(debug_info)),
          left_hand_side(std::move(left_hand_side)),
          right_hand_side(std::move(right_hand_side))
    {
    }
    const Node& get_left_hand_side() const;
    const Node& get_right_hand_side() const;
};

class BlockNode : public NodeBase
{
    private:
    std::vector<std::unique_ptr<Node>> expressions;

    public:
    BlockNode(debug::DebugInfo&& debug_info,
              std::vector<std::unique_ptr<Node>>&& expressions)
        : NodeBase(std::move(debug_info)), expressions(std::move(expressions))
    {
    }
    const std::vector<std::unique_ptr<Node>>& get_expressions() const;
};

class IfNode : public NodeBase
{
    private:
    std::unique_ptr<Node> condition;
    std::unique_ptr<Node> body;

    public:
    IfNode(debug::DebugInfo&& debug_info, std::unique_ptr<Node>&& condition,
           std::unique_ptr<Node>&& body)
        : NodeBase(std::move(debug_info)),
          body(std::move(body)),
          condition(std::move(condition))
    {
    }
    const Node& get_body() const;
    const Node& get_condition() const;
};

class ForNode : public NodeBase
{
    private:
    std::unique_ptr<Node> first_expression;
    std::unique_ptr<Node> condition;
    std::unique_ptr<Node> last_expression;
    std::unique_ptr<Node> body;

    public:
    ForNode(debug::DebugInfo&& debug_info,
            std::unique_ptr<Node>&& first_expression,
            std::unique_ptr<Node>&& condition,
            std::unique_ptr<Node>&& last_expression,
            std::unique_ptr<Node>&& body)
        : NodeBase(std::move(debug_info)),
          first_expression(std::move(first_expression)),
          condition(std::move(condition)),
          last_expression(std::move(last_expression)),
          body(std::move(body))
    {
    }
    const Node& get_first_expression() const;
    const Node& get_condition() const;
    const Node& get_last_expression() const;
    const Node& get_body() const;
};

class GenericFunctionNode;

class GenericFunctionDeclarationNode : public NodeBase
{
    private:
    std::string name;
    const int num_arguments;

    public:
    GenericFunctionDeclarationNode(debug::DebugInfo&& debug_info,
                                   std::string name, int num_arguments)
        : NodeBase(std::move(debug_info)),
          name(name),
          num_arguments(num_arguments)
    {
    }
    const std::string& get_name() const;
    const int get_num_arguments() const;
    void register_functions(GenericFunctionNode& specialized);
};

class GenericFunctionNode : public NodeBase
{
    private:
    const std::string name;
    std::unique_ptr<Node> body;
    std::vector<std::unique_ptr<Node>> arguments;

    public:
    GenericFunctionNode(debug::DebugInfo&& debug_info, const std::string& name,
                        std::vector<std::unique_ptr<Node>>&& arguments,
                        std::unique_ptr<Node>&& body)
        : NodeBase(std::move(debug_info)),
          name(name),
          arguments(std::move(arguments)),
          body(std::move(body))
    {
    }
    const std::string& get_name() const;
    const Node& get_body() const;
    const std::vector<std::unique_ptr<Node>>& get_arguments() const;
};

class GenericClassNode : public NodeBase
{
    private:
    const std::string name;
    std::vector<std::unique_ptr<Node>> arguments;
    std::vector<std::unique_ptr<Node>> member_variables;
    std::vector<std::unique_ptr<Node>> member_functions;

    public:
    GenericClassNode(debug::DebugInfo&& debug_info, const std::string& name,
                     std::vector<std::unique_ptr<Node>>&& arguments,
                     std::vector<std::unique_ptr<Node>>&& member_variables,
                     std::vector<std::unique_ptr<Node>>&& member_functions)
        : NodeBase(std::move(debug_info)),
          name(name),
          arguments(std::move(arguments)),
          member_variables(std::move(member_variables)),
          member_functions(std::move(member_functions))
    {
    }
    const std::string& get_name() const;
    const std::vector<std::unique_ptr<Node>>& get_arguments() const;
    const std::vector<std::unique_ptr<Node>>& get_member_variables() const;
    const std::vector<std::unique_ptr<Node>>& get_member_functions() const;
};

class TypeIdNode : public NodeBase
{
    private:
    std::unique_ptr<Node> node;

    public:
    TypeIdNode(debug::DebugInfo&& debug_info, std::unique_ptr<Node> node)
        : NodeBase(std::move(debug_info)), node(std::move(node))
    {
    }

    const Node& get_node() const;
};

class CastNode : public NodeBase
{
    private:
    std::unique_ptr<Node> target_type_id_node;
    std::unique_ptr<Node> node;

    public:
    CastNode(debug::DebugInfo&& debug_info,
             std::unique_ptr<Node>&& target_type_id_node,
             std::unique_ptr<Node>&& node)
        : NodeBase(std::move(debug_info)),
          target_type_id_node(std::move(target_type_id_node)),
          node(std::move(node))
    {
    }
    const Node& get_target_type_id_node() const;
    const Node& get_node() const;
};

class Node
    : public utils::VariantWrapper<
          RootNode, IntegerNode, FloatNode, ArrayNode, StringNode, LazyNode,
          VariableNode, VariableDefinitionNode, GlobalVariableNode,
          AssignmentNode, ArgumentNode, BinaryExpressionNode, CallFunctionNode,
          AccessElementNode, DeepCopyNode, BlockNode, IfNode, ForNode,
          GenericFunctionDeclarationNode, GenericFunctionNode, GenericClassNode,
          TypeIdNode, CastNode>
{
    private:
    using parent_type = utils::VariantWrapper<
        RootNode, IntegerNode, FloatNode, ArrayNode, StringNode, LazyNode,
        VariableNode, VariableDefinitionNode, GlobalVariableNode,
        AssignmentNode, ArgumentNode, BinaryExpressionNode, CallFunctionNode,
        AccessElementNode, DeepCopyNode, BlockNode, IfNode, ForNode,
        GenericFunctionDeclarationNode, GenericFunctionNode, GenericClassNode,
        TypeIdNode, CastNode>;

    protected:
    template <typename T>
    Node(T&& initial_content) : parent_type(std::move(initial_content))
    {
    }

    public:
    template <typename NodeType, typename... Args>
    static std::unique_ptr<Node> create(Args&&... args)
    {
        auto node = std::make_unique<CreateHelper<Node>>(
            NodeType(std::forward<Args>(args)...));
        return node;
    }

    template <typename ContentType>
    Node& operator=(ContentType&& new_content)
    {
        content = std::move(new_content);
        return *this;
    }
    /*
    template <typename ContentType>
    Node& operator=(ContentType&& new_content) {
        assign(new_content);
        return *this;
    }
    */
};
}  // namespace ast