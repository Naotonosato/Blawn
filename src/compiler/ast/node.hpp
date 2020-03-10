#pragma once
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>
#include <optional>
#include <variant>

namespace ast {

class Node;

class NodeBase {
    private:
    uint64_t line_number;

    public:
    NodeBase(uint64_t line_number) : line_number(line_number) {}
    NodeBase() = delete;
    NodeBase(const NodeBase&) = delete;
    NodeBase(NodeBase&&) = default;
};

class IntegerNode : public NodeBase {
    private:
    uint64_t initial_value;

    public:
    IntegerNode(uint64_t line_number, uint64_t initial_value)
        : NodeBase(line_number), initial_value(initial_value) {}
    const std::optional<uint64_t>& get_initial_value() const;
};

class FloatNode : public NodeBase {
    private:
    double initial_value;

    public:
    FloatNode(uint64_t line_number, double initial_value)
        : NodeBase(line_number), initial_value(initial_value) {}
    const std::optional<double>& get_initial_value() const;
};

class ArrayNode : public NodeBase {
    private:
    std::optional<std::vector<std::shared_ptr<Node>>> initial_values;

    public:
    ArrayNode(uint64_t line_number) : NodeBase(line_number) {}
    ArrayNode(uint64_t line_number,
              std::vector<std::shared_ptr<Node>> initial_values)
        : NodeBase(line_number), initial_values(std::move(initial_values)) {}

    const std::optional<std::vector<std::shared_ptr<Node>>> get_initial_values()
        const;
};

class StringNode : public NodeBase {
    private:
    std::string initial_value;

    public:
    StringNode(uint64_t line_number, const std::string initial_value)
        : NodeBase(line_number), initial_value(initial_value) {}
    const std::optional<std::string>& get_initial_value() const;
};

class VariableNode : public NodeBase {
    private:
    std::string name;
    std::shared_ptr<Node> initial_value;

    public:
    VariableNode(uint64_t line_number, std::string name,
                 std::shared_ptr<Node> initial_value)
        : NodeBase(line_number), name(name), initial_value(initial_value) {}
};

class GlobalVariableNode : public NodeBase {
    public:
    GlobalVariableNode(uint64_t line_number) : NodeBase(line_number) {}
};

class ArgumentNode : public NodeBase {
    public:
    ArgumentNode(uint64_t line_number) : NodeBase(line_number) {}
};

class AssignmentNode : public NodeBase {
    private:
    std::shared_ptr<Node> left_hand_side;
    std::shared_ptr<Node> right_hand_side;

    public:
    AssignmentNode(uint64_t line_number,
                   const std::shared_ptr<Node> left_hand_side,
                   std::shared_ptr<Node> right_hand_side)
        : NodeBase(line_number),
          left_hand_side(left_hand_side),
          right_hand_side(right_hand_side) {}
    std::shared_ptr<Node> get_left_hand_side() const;
    std::shared_ptr<Node> get_right_hand_side() const;
};

enum BinaryExpressionKind { ADD, SUB, MUL, DIV };

class BinaryExpressionNode : public NodeBase {
    private:
    std::shared_ptr<Node> left_hand_side;
    std::shared_ptr<Node> right_hand_side;
    BinaryExpressionKind operator_kind;

    public:
    BinaryExpressionNode(uint64_t line_number,
                         BinaryExpressionKind operator_kind,
                         std::shared_ptr<Node> left_hand_side,
                         std::shared_ptr<Node> right_hand_side)
        : NodeBase(line_number),
          operator_kind(operator_kind),
          left_hand_side(left_hand_side),
          right_hand_side(right_hand_side) {}
    const BinaryExpressionKind get_operator_kind() const;
    std::shared_ptr<Node> get_left_hand_side() const;
    std::shared_ptr<Node> get_right_hand_side() const;
};

class GenericFunctionNode;

class CallFunctionNode : public NodeBase {
    private:
    std::shared_ptr<GenericFunctionNode> function;
    std::vector<std::shared_ptr<Node>> arguments;

    public:
    CallFunctionNode(uint64_t line_number,
                     std::shared_ptr<GenericFunctionNode> function,
                     std::vector<std::shared_ptr<Node>> arguments)
        : NodeBase(line_number),
          function(function),
          arguments(std::move(arguments)) {}
    std::shared_ptr<Node> get_function() const;
    std::vector<std::shared_ptr<Node>>& get_arguments() const;
};

class AccessElementNode : public NodeBase {
    private:
    std::shared_ptr<Node> left_hand_side;
    std::string element_name;

    public:
    AccessElementNode(uint64_t line_number,
                      std::shared_ptr<Node> left_hand_side,
                      std::string element_name)
        : NodeBase(line_number),
          left_hand_side(left_hand_side),
          element_name(element_name) {}
    std::shared_ptr<Node> get_left_hand_side() const;
    const std::string& get_element_name() const;
};

class DeepCopyNode : public NodeBase {
    private:
    std::shared_ptr<Node> left_hand_side;
    std::shared_ptr<Node> right_hand_side;

    public:
    DeepCopyNode(uint64_t line_number, std::shared_ptr<Node> left_hand_side,
                 std::shared_ptr<Node> right_hand_side)
        : NodeBase(line_number),
          left_hand_side(left_hand_side),
          right_hand_side(right_hand_side) {}
    std::shared_ptr<Node> get_left_hand_side() const;
    std::shared_ptr<Node> get_right_hand_side() const;
};

class BlockNode : public NodeBase {
    private:
    std::vector<std::shared_ptr<Node>> expressions;

    public:
    BlockNode(uint64_t line_number,
              std::vector<std::shared_ptr<Node>>&& expressions)
        : NodeBase(line_number), expressions(std::move(expressions)) {}
    std::vector<std::shared_ptr<Node>>& get_expressions() const;
};

class IfNode : public NodeBase {
    private:
    std::shared_ptr<Node> block;
    std::shared_ptr<Node> condition;

    public:
    IfNode(uint64_t line_number, std::shared_ptr<Node> block,
           std::shared_ptr<Node> condition)
        : NodeBase(line_number), block(block), condition(condition) {}
    std::shared_ptr<Node> get_block() const;
    std::shared_ptr<Node> get_condition() const;
};

class ForNode : public NodeBase {
    private:
    std::shared_ptr<Node> block;
    std::shared_ptr<Node> first_expression;
    std::shared_ptr<Node> condition;
    std::shared_ptr<Node> last_expression;

    public:
    ForNode(uint64_t line_number, std::shared_ptr<Node> block,
            std::shared_ptr<Node> first_expression,
            std::shared_ptr<Node> condition,
            std::shared_ptr<Node> last_expression)
        : NodeBase(line_number),
          block(block),
          first_expression(first_expression),
          condition(condition),
          last_expression(last_expression) {}
    std::shared_ptr<Node> get_block() const;
    std::shared_ptr<Node> get_first_expression() const;
    std::shared_ptr<Node> get_condition() const;
    std::shared_ptr<Node> get_last_expression() const;
};

class GenericFunctionNode : public NodeBase {
    private:
    std::string name;
    std::vector<std::string> argument_names;
    std::optional<std::shared_ptr<Node>> body;
    std::optional<std::shared_ptr<Node>> return_value;

    public:
    GenericFunctionNode(uint64_t line_number, std::string name,
                        std::vector<std::string> argument_names)
        : NodeBase(line_number),
          name(name),
          argument_names(std::move(argument_names)) {}
    const std::string& get_name() const;
    const std::vector<std::string>& get_argument_names() const;
    std::optional<std::shared_ptr<Node>> get_body();
    std::optional<std::shared_ptr<Node>> get_return_value();
    std::optional<std::shared_ptr<Node>> set_body(std::shared_ptr<Node> body);
    std::optional<std::shared_ptr<Node>> set_return_value(
        std::shared_ptr<Node> return_value);
};

class GenericClassNode : public NodeBase {
    private:
    std::string name;
    std::vector<std::shared_ptr<Node>> member_variables;
    std::vector<std::shared_ptr<Node>> methods;

    public:
    GenericClassNode(uint64_t line_number, std::string name,
                     std::vector<std::shared_ptr<Node>> member_variables,
                     std::vector<std::shared_ptr<Node>> methods)
        : NodeBase(line_number),
          name(name),
          member_variables(std::move(member_variables)),
          methods(std::move(methods)) {}
    const std::string& get_name() const;
    std::vector<std::shared_ptr<Node>> get_member_variables() const;
    std::vector<std::shared_ptr<GenericFunctionNode>> get_methods() const;
    void set_member_variables(std::vector<std::shared_ptr<Node>> members) const;
    void set_methods(std::vector<std::shared_ptr<Node>> methods) const;
};

class TypeIdNode : public NodeBase {
    private:
    std::shared_ptr<Node> node;

    public:
    TypeIdNode(uint64_t line_number, std::shared_ptr<Node> node)
        : NodeBase(line_number), node(node) {}

    std::shared_ptr<Node> get_node() const;
};

class CastNode : public NodeBase {
    private:
    std::shared_ptr<TypeIdNode> target_type_id_node;
    std::shared_ptr<Node> node;

    public:
    CastNode(uint64_t line_number,
             std::shared_ptr<TypeIdNode> target_type_id_node,
             std::shared_ptr<Node> node)
        : NodeBase(line_number),
          target_type_id_node(target_type_id_node),
          node(node) {}
    std::shared_ptr<TypeIdNode> get_target_type_id_node() const;
    std::shared_ptr<Node> get_node() const;
};

class Node {
    public:
    using variant_type = std::variant<
        IntegerNode, FloatNode, ArrayNode, StringNode, VariableNode,
        AssignmentNode, AssignmentNode, BinaryExpressionNode, CallFunctionNode,
        AccessElementNode, DeepCopyNode, BlockNode, IfNode, ForNode,
        GenericFunctionNode, GenericClassNode, TypeIdNode, CastNode>;

    private:
    variant_type content;

    template <typename Base>
    struct CreateHelper : Base {
        template <typename... Args>
        CreateHelper(Args&&... args) : Base(std::forward<Args>(args)...) {}
    };

    template <class T>
    Node(T&& content) : content(std::move(content)) {}

    public:
    template <typename NodeType, typename... Args>
    static std::shared_ptr<Node> create(Args&&... args) {
        auto type_variable = std::make_shared<CreateHelper<Node>>(
            std::move(NodeType(std::forward<Args>(args)...)));
        return type_variable;
    }

    template <typename VisitorType>
    auto accept(VisitorType& visitor) {
        return std::visit(visitor, content);
    }

    template <typename Type>
    bool is_type() {
        return std::holds_alternative<Type>(content);
    }

    template <typename ContentType>
    ContentType get() {
        assert(std::holds_alternative<ContentType>(content) &&
               (bool)std::string(std::string("This Instance must have ") +
                                 typeid(ContentType).name()));
        return std::get<ContentType>(content);
    }
};

}  // namespace ast