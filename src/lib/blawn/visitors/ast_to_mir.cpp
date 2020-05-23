#include <iostream>
#include "include/ast/node.hpp"
#include "include/blawn/visitors/ast_to_mir.hpp"
#include "include/mir/mir.hpp"
#include "include/mir/type.hpp"
#include "include/utils/pattern_match.hpp"

namespace converter
{
namespace ast_to_mir
{
int Converter::visit(const ast::RootNode& node) const
{
    std::cout
        << "======================Start scanning AST======================"
        << std::endl;
    auto& block = node.get_children();
    std::vector<int> result;
    size_t line_number = 1;
    for (auto& expression : block)
    {
        std::cout << "\n==========expanded from line " << line_number
                  << "==========" << std::endl;
        expression->accept(visitor_ref);
        line_number += 1;
    }

    return 0;
}
int Converter::visit(const ast::IntegerNode& node) const
{
    return node.get_initial_value();
}
int Converter::visit(const ast::FloatNode& node) const
{
    //    std::cout << node->get_initial_value() << std::endl;
    return 0;
}
int Converter::visit(const ast::ArrayNode& node) const
{
    //    std::cout << typeid(node).name() << std::endl;
    return 0;
}
int Converter::visit(const ast::StringNode& node) const
{
    //    std::cout << "string: " << node->get_initial_value() << std::endl;
    return 0;
}

int Converter::visit(const ast::LazyNode& node) const
{
    std::cout << "lazy node" << std::endl;
    return 0;
}

int Converter::visit(const ast::VariableNode& node) const
{
    std::cout << "This variable(already defined) is named " << node.get_name()
              << "(at line "
              << node.get_debug_info().get_token_info().get_line_number() << ")"
              << std::endl;
    return 0;
}

int Converter::visit(const ast::VariableDefinitionNode& node) const
{
    std::cout << "This variable is named " << node.get_name() << "(at line "
              << node.get_debug_info().get_token_info().get_line_number() << ")"
              << std::endl;
    node.get_initial_value().accept(visitor_ref);
    return 0;
}

int Converter::visit(const ast::GlobalVariableNode& node) const
{
    //    std::cout << typeid(node).name() << std::endl;
    return 0;
}
int Converter::visit(const ast::AssignmentNode& node) const
{
    //    std::cout << typeid(node).name() << std::endl;
    return 0;
}
int Converter::visit(const ast::ArgumentNode& node) const
{
    //    std::cout << typeid(node).name() << std::endl;
    return 0;
}
int Converter::visit(const ast::BinaryExpressionNode& node) const
{
    auto l = node.get_left_hand_side().accept(visitor_ref);
    auto r = node.get_right_hand_side().accept(visitor_ref);
    int res = 0;
    auto op = node.get_operator_kind();
    if (op == ast::BinaryExpressionKind::ADD) res = l + r;
    if (op == ast::BinaryExpressionKind::SUB) res = l - r;
    if (op == ast::BinaryExpressionKind::MUL) res = l * r;
    if (op == ast::BinaryExpressionKind::DIV) res = l / r;
    return res;
}
int Converter::visit(const ast::CallFunctionNode& node) const
{
    std::cout << "call function " << node.get_function().accept(visitor_ref)
              << std::endl;
    return 0;
}
int Converter::visit(const ast::AccessElementNode& node) const
{
    //    std::cout << typeid(node).name() << std::endl;
    return 0;
}
int Converter::visit(const ast::DeepCopyNode& node) const
{
    //    std::cout << typeid(node).name() << std::endl;
    return 0;
}
int Converter::visit(const ast::BlockNode& node) const
{
    for (auto& line : node.get_expressions())
    {
        line->accept(visitor_ref);
    }
    return 0;
}
int Converter::visit(const ast::IfNode& node) const
{
    //    std::cout << typeid(node).name() << std::endl;
    return 0;
}
int Converter::visit(const ast::ForNode& node) const
{
    //    std::cout << typeid(node).name() << std::endl;
    return 0;
}
int Converter::visit(const ast::GenericFunctionDeclarationNode& node) const
{
    return 0;
}
int Converter::visit(const ast::GenericFunctionNode& node) const
{
    std::cout << "definition function named " << node.get_name() << "(at line "
              << node.get_debug_info().get_token_info().get_line_number() << ")"
              << std::endl;
    node.get_body().accept(visitor_ref);
    return 0;
}
int Converter::visit(const ast::GenericClassNode& node) const
{
    //    std::cout << typeid(node).name() << std::endl;
    return 0;
}
int Converter::visit(const ast::TypeIdNode& node) const
{
    //    std::cout << typeid(node).name() << std::endl;
    return 0;
}
int Converter::visit(const ast::CastNode& node) const
{
    //    std::cout << typeid(node).name() << std::endl;
    return 0;
}
}  // namespace ast_to_mir
}  // namespace converter