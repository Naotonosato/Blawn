#include <iostream>
#include "include/ast/node.hpp"
#include "include/blawn/visitors/visitor.hpp"
#include "include/blawn/visitors/ast_to_mir.hpp"
#include "include/mir/mir.hpp"
#include "include/mir/type.hpp"
#include "include/utils/pattern_match.hpp"

namespace blawn
{
namespace visitors
{
//--forward declarations--------------------------------
template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::IntegerNode& node) const;
template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::FloatNode& node) const;
template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::ArrayNode& node) const;
template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::StringNode& node) const;
template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::LazyNode& node) const;
template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::VariableNode& node) const;
template <>
std::unique_ptr<mir::MIR> Converter::visit(
    const ast::VariableDefinitionNode& node) const;
template <>
std::unique_ptr<mir::MIR> Converter::visit(
    const ast::GlobalVariableNode& node) const;
template <>
std::unique_ptr<mir::MIR> Converter::visit(
    const ast::AssignmentNode& node) const;
template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::ArgumentNode& node) const;
template <>
std::unique_ptr<mir::MIR> Converter::visit(
    const ast::BinaryExpressionNode& node) const;
template <>
std::unique_ptr<mir::MIR> Converter::visit(
    const ast::CallFunctionNode& node) const;
template <>
std::unique_ptr<mir::MIR> Converter::visit(
    const ast::AccessElementNode& node) const;
template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::DeepCopyNode& node) const;
template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::BlockNode& node) const;
template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::IfNode& node) const;
template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::ForNode& node) const;
template <>
std::unique_ptr<mir::MIR> Converter::visit(
    const ast::GenericFunctionDeclarationNode& node) const;
template <>
std::unique_ptr<mir::MIR> Converter::visit(
    const ast::GenericFunctionNode& node) const;
template <>
std::unique_ptr<mir::MIR> Converter::visit(
    const ast::GenericClassNode& node) const;
template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::TypeIdNode& node) const;
template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::CastNode& node) const;

//---------end forward declarations-------------------------------
//----------------------------------------------------------------
//----------------------------------------------------------------

template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::RootNode& node) const
{
    auto& block = node.get_children();
    std::vector<std::unique_ptr<mir::MIR>> result;
    for (auto& expression : block)
    {
        expression->accept(visitor_ref);
    }
    return mir::MIR::create<mir::Root>(node.get_debug_info(),
                                       std::move(result));
}

template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::IntegerNode& node) const
{
    return mir::MIR::create<mir::Integer>(node.get_debug_info(),
                                          node.get_initial_value());
}

template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::FloatNode& node) const
{
    return mir::MIR::create<mir::Float>(node.get_debug_info(),
                                          node.get_initial_value());
    return 0;
}

template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::ArrayNode& node) const
{
    //    std::cout << typeid(node).name() << std::endl;
    return 0;
}

template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::StringNode& node) const
{
    //    std::cout << "string: " << node->get_initial_value() << std::endl;
    return 0;
}

template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::LazyNode& node) const
{
    std::cout << "lazy node" << std::endl;
    return 0;
}

template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::VariableNode& node) const
{
    return 0;
}

template <>
std::unique_ptr<mir::MIR> Converter::visit(
    const ast::VariableDefinitionNode& node) const
{
    std::cout << "This variable is named " << node.get_name() << "(at line "
              << node.get_debug_info().get_token_info().get_line_number() << ")"
              << std::endl;
    node.get_initial_value().accept(visitor_ref);
    return 0;
}

template <>
std::unique_ptr<mir::MIR> Converter::visit(
    const ast::GlobalVariableNode& node) const
{
    //    std::cout << typeid(node).name() << std::endl;
    return 0;
}

template <>
std::unique_ptr<mir::MIR> Converter::visit(
    const ast::AssignmentNode& node) const
{
    //    std::cout << typeid(node).name() << std::endl;
    return 0;
}

template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::ArgumentNode& node) const
{
    //    std::cout << typeid(node).name() << std::endl;
    return 0;
}

template <>
std::unique_ptr<mir::MIR> Converter::visit(
    const ast::BinaryExpressionNode& node) const
{
    auto l = node.get_left_hand_side().accept(visitor_ref);
    auto r = node.get_right_hand_side().accept(visitor_ref);
    int res = 0;
    auto op = node.get_operator_kind();
    return 0;
}

template <>
std::unique_ptr<mir::MIR> Converter::visit(
    const ast::CallFunctionNode& node) const
{
    std::cout << "call function " << node.get_function().accept(visitor_ref)
              << std::endl;
    return 0;
}

template <>
std::unique_ptr<mir::MIR> Converter::visit(
    const ast::AccessElementNode& node) const
{
    //    std::cout << typeid(node).name() << std::endl;
    return 0;
}

template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::DeepCopyNode& node) const
{
    //    std::cout << typeid(node).name() << std::endl;
    return 0;
}

template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::BlockNode& node) const
{
    for (auto& line : node.get_expressions())
    {
        line->accept(visitor_ref);
    }
    return 0;
}

template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::IfNode& node) const
{
    //    std::cout << typeid(node).name() << std::endl;
    return 0;
}

template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::ForNode& node) const
{
    //    std::cout << typeid(node).name() << std::endl;
    return 0;
}

template <>
std::unique_ptr<mir::MIR> Converter::visit(
    const ast::GenericFunctionDeclarationNode& node) const
{
    return 0;
}

template <>
std::unique_ptr<mir::MIR> Converter::visit(
    const ast::GenericFunctionNode& node) const
{
    std::cout << "definition function named " << node.get_name() << "(at line "
              << node.get_debug_info().get_token_info().get_line_number() << ")"
              << std::endl;
    node.get_body().accept(visitor_ref);
    return 0;
}

template <>
std::unique_ptr<mir::MIR> Converter::visit(
    const ast::GenericClassNode& node) const
{
    //    std::cout << typeid(node).name() << std::endl;
    return 0;
}

template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::TypeIdNode& node) const
{
    //    std::cout << typeid(node).name() << std::endl;
    return 0;
}

template <>
std::unique_ptr<mir::MIR> Converter::visit(const ast::CastNode& node) const
{
    //    std::cout << typeid(node).name() << std::endl;
    return 0;
}
}  // namespace visitors
}  // namespace blawn