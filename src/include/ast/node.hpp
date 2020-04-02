#pragma once
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>
#include <optional>
#include "include/utils/variant_wrapper.hpp"

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

    public:
    template <typename... Args>
    void* operator new(size_t, Args&&...) {
        // delay evaluation until instantiation
        constexpr bool operator_new_is_not_used = [] { return false; }();
        static_assert(operator_new_is_not_used,
                      "Class that inherits from 'NodeBase' cannot be "
                      "instantiated with operator new.");
    }
};

class BlockNode;

class RootNode : public NodeBase {
    private:
    std::shared_ptr<BlockNode> child_block;

    public:
    RootNode(uint64_t line_number, std::shared_ptr<BlockNode> child_block)
        : NodeBase(line_number), child_block(child_block) {}

    std::shared_ptr<BlockNode> get_child_block() const;
};

class IntegerNode : public NodeBase {
    private:
    uint64_t initial_value;

    public:
    IntegerNode(uint64_t line_number, uint64_t initial_value)
        : NodeBase(line_number), initial_value(initial_value) {}
    const uint64_t get_initial_value() const;
};

class FloatNode : public NodeBase {
    private:
    double initial_value;

    public:
    FloatNode(uint64_t line_number, double initial_value)
        : NodeBase(line_number), initial_value(initial_value) {}
    const double get_initial_value() const;
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
    const std::string& get_initial_value() const;
};

class VariableNode : public NodeBase {
    private:
    std::string name;
    std::shared_ptr<Node> initial_value;

    public:
    VariableNode(uint64_t line_number, std::string name,
                 std::shared_ptr<Node> initial_value)
        : NodeBase(line_number), name(name), initial_value(initial_value) {}

    const std::string& get_name() const;
    std::shared_ptr<Node> get_initial_value() const;
};

class GlobalVariableNode : public NodeBase {
    private:
    std::string name;
    std::shared_ptr<Node> initial_value;

    public:
    GlobalVariableNode(uint64_t line_number, std::string name,
                       std::shared_ptr<Node> initial_value)
        : NodeBase(line_number), name(name), initial_value(initial_value) {}

    std::shared_ptr<Node> get_initial_value() const;
};

class ArgumentNode : public NodeBase {
    private:
    std::string name;

    public:
    ArgumentNode(uint64_t line_number, std::string name)
        : NodeBase(line_number), name(name) {}
    const std::string get_name() const;
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

BinaryExpressionKind string_to_operator_type(const std::string& name);

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

class GenericFunctionDeclarationNode;

class CallFunctionNode : public NodeBase {
    private:
    std::shared_ptr<GenericFunctionDeclarationNode> function;
    std::vector<std::shared_ptr<Node>> arguments;

    public:
    CallFunctionNode(uint64_t line_number,
                     std::shared_ptr<GenericFunctionDeclarationNode> function,
                     std::vector<std::shared_ptr<Node>> arguments)
        : NodeBase(line_number),
          function(function),
          arguments(std::move(arguments)) {}

    std::shared_ptr<GenericFunctionDeclarationNode> get_function() const;
    std::vector<std::shared_ptr<Node>>& get_arguments();
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
    std::vector<std::shared_ptr<Node>>& get_expressions();
};

class IfNode : public NodeBase {
    private:
    std::shared_ptr<Node> condition;
    std::shared_ptr<BlockNode> block;

    public:
    IfNode(uint64_t line_number, std::shared_ptr<Node> condition,
           std::shared_ptr<BlockNode> block)
        : NodeBase(line_number), block(block), condition(condition) {}
    std::shared_ptr<BlockNode> get_block() const;
    std::shared_ptr<Node> get_condition() const;
};

class ForNode : public NodeBase {
    private:
    std::shared_ptr<Node> first_expression;
    std::shared_ptr<Node> condition;
    std::shared_ptr<Node> last_expression;
    std::shared_ptr<BlockNode> block;

    public:
    ForNode(uint64_t line_number, std::shared_ptr<Node> first_expression,
            std::shared_ptr<Node> condition,
            std::shared_ptr<Node> last_expression,
            std::shared_ptr<BlockNode> block)
        : NodeBase(line_number),
          first_expression(first_expression),
          condition(condition),
          last_expression(last_expression),
          block(block) {}
    std::shared_ptr<Node> get_first_expression() const;
    std::shared_ptr<Node> get_condition() const;
    std::shared_ptr<Node> get_last_expression() const;
    std::shared_ptr<BlockNode> get_block() const;
};

class GenericFunctionNode;

class GenericFunctionDeclarationNode : public NodeBase {
    private:
    std::string name;
    int num_arguments;
    std::optional<std::shared_ptr<GenericFunctionNode>> definition;

    public:
    GenericFunctionDeclarationNode(uint64_t line_number, std::string name,
                                   int num_arguments)
        : NodeBase(line_number), name(name), num_arguments(num_arguments) {}
    const std::string& get_name() const;
    const int get_num_arguments() const;
    void set_definition(std::shared_ptr<GenericFunctionNode> definition_);
    std::optional<std::shared_ptr<GenericFunctionNode>> get_definition() const;
};

class GenericFunctionNode : public NodeBase {
    private:
    std::string name;
    std::vector<std::shared_ptr<ArgumentNode>> arguments;
    std::shared_ptr<BlockNode> body;
    std::shared_ptr<Node> return_value;

    public:
    GenericFunctionNode(uint64_t line_number, std::string name,
                        std::vector<std::shared_ptr<ArgumentNode>> arguments,
                        std::shared_ptr<BlockNode> body,
                        std::shared_ptr<Node> return_value)
        : NodeBase(line_number),
          name(name),
          arguments(std::move(arguments)),
          body(body),
          return_value(return_value) {}
    const std::string& get_name() const;
    std::vector<std::shared_ptr<ArgumentNode>>& get_arguments();
    std::shared_ptr<BlockNode> get_body() const;
    std::shared_ptr<Node> get_return_value() const;
};

class GenericClassNode : public NodeBase {
    private:
    std::string name;
    std::vector<std::shared_ptr<ArgumentNode>> arguments;
    std::vector<std::shared_ptr<VariableNode>> member_variables;
    std::vector<std::shared_ptr<GenericFunctionNode>> methods;

    public:
    GenericClassNode(
        uint64_t line_number, std::string name,
        std::vector<std::shared_ptr<ArgumentNode>> arguments,
        std::vector<std::shared_ptr<VariableNode>> member_variables,
        std::vector<std::shared_ptr<GenericFunctionNode>> methods)
        : NodeBase(line_number),
          name(name),
          arguments(arguments),
          member_variables(member_variables),
          methods(methods) {}
    const std::string& get_name() const;
    std::vector<std::shared_ptr<ArgumentNode>>& get_arguments();
    std::vector<std::shared_ptr<VariableNode>> get_member_variables() const;
    std::vector<std::shared_ptr<GenericFunctionNode>> get_methods() const;
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

class Node
    : public utils::VariantWrapper<
          std::shared_ptr<RootNode>, std::shared_ptr<IntegerNode>,
          std::shared_ptr<FloatNode>, std::shared_ptr<ArrayNode>,
          std::shared_ptr<StringNode>, std::shared_ptr<VariableNode>,
          std::shared_ptr<GlobalVariableNode>, std::shared_ptr<AssignmentNode>,
          std::shared_ptr<ArgumentNode>, std::shared_ptr<BinaryExpressionNode>,
          std::shared_ptr<CallFunctionNode>, std::shared_ptr<AccessElementNode>,
          std::shared_ptr<DeepCopyNode>, std::shared_ptr<BlockNode>,
          std::shared_ptr<IfNode>, std::shared_ptr<ForNode>,
          std::shared_ptr<GenericFunctionDeclarationNode>,
          std::shared_ptr<GenericFunctionNode>,
          std::shared_ptr<GenericClassNode>, std::shared_ptr<TypeIdNode>,
          std::shared_ptr<CastNode>> {
    private:
    using parent_type = utils::VariantWrapper<
        std::shared_ptr<RootNode>, std::shared_ptr<IntegerNode>,
        std::shared_ptr<FloatNode>, std::shared_ptr<ArrayNode>,
        std::shared_ptr<StringNode>, std::shared_ptr<VariableNode>,
        std::shared_ptr<GlobalVariableNode>, std::shared_ptr<AssignmentNode>,
        std::shared_ptr<ArgumentNode>, std::shared_ptr<BinaryExpressionNode>,
        std::shared_ptr<CallFunctionNode>, std::shared_ptr<AccessElementNode>,
        std::shared_ptr<DeepCopyNode>, std::shared_ptr<BlockNode>,
        std::shared_ptr<IfNode>, std::shared_ptr<ForNode>,
        std::shared_ptr<GenericFunctionDeclarationNode>,
        std::shared_ptr<GenericFunctionNode>, std::shared_ptr<GenericClassNode>,
        std::shared_ptr<TypeIdNode>, std::shared_ptr<CastNode>>;

    protected:
    template <class T>
    Node(T&& initial_content)
        : utils::VariantWrapper<
              std::shared_ptr<RootNode>, std::shared_ptr<IntegerNode>,
              std::shared_ptr<FloatNode>, std::shared_ptr<ArrayNode>,
              std::shared_ptr<StringNode>, std::shared_ptr<VariableNode>,
              std::shared_ptr<GlobalVariableNode>,
              std::shared_ptr<AssignmentNode>, std::shared_ptr<ArgumentNode>,
              std::shared_ptr<BinaryExpressionNode>,
              std::shared_ptr<CallFunctionNode>,
              std::shared_ptr<AccessElementNode>, std::shared_ptr<DeepCopyNode>,
              std::shared_ptr<BlockNode>, std::shared_ptr<IfNode>,
              std::shared_ptr<ForNode>,
              std::shared_ptr<GenericFunctionDeclarationNode>,
              std::shared_ptr<GenericFunctionNode>,
              std::shared_ptr<GenericClassNode>, std::shared_ptr<TypeIdNode>,
              std::shared_ptr<CastNode>>(std::move(initial_content)) {}

    public:
    template <typename NodeType, typename... Args>
    static std::shared_ptr<Node> create(Args&&... args) {
        auto node = std::make_shared<CreateHelper<Node>>(
            std::make_shared<NodeType>(std::forward<Args>(args)...));
        return node;
    }

    template <typename NodeType>
    static std::shared_ptr<Node> create(
        std::shared_ptr<NodeType> initial_value) {
        auto node = std::make_shared<CreateHelper<Node>>(initial_value);
        return node;
    }

    template <typename ContentType>
    bool is_type() {
        return parent_type::is_type<std::shared_ptr<ContentType>>();
    }

    template <typename ContentType>
    ContentType& get() {
        auto& res = parent_type::get<std::shared_ptr<ContentType>>();
        return *res;
    }

    template <typename ContentType>
    std::shared_ptr<ContentType> get_pointer() {
        return parent_type::get<std::shared_ptr<ContentType>>();
    }

    template <typename ContentType>
    Node& operator=(ContentType new_content) {
        assign(new_content);
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