#pragma once
#include <memory>
#include "include/utils/visitor_wrapper.hpp"

namespace ast
{
class IntegerNode;
class FloatNode;
class ArrayNode;
class StringNode;
class VariableNode;
class BinaryExpressionNode;
class VariableNode;
class GlobalVariableNode;
class ArgumentNode;
class AssignmentNode;
class GenericFunctionNode;
class CallFunctionNode;
class AccessElementNode;
class DeepCopyNode;
class BlockNode;
class IfNode;
class ForNode;
class GenericFunctionDeclarationNode;
class GenericFunctionNode;
class GenericClassNode;
class TypeIdNode;
class CastNode;
}  // namespace ast

namespace mir
{
class MIR;
}

namespace converter
{
namespace ast_to_mir
{
class Converter : public utils::VisitorBase<Converter>
{
    public:
    Converter(utils::VisitorWrapper<Converter>& visitor_ref)
        : utils::VisitorBase<Converter>(visitor_ref)
    {
    }
    int visit(const ast::RootNode& node) const;
    int visit(const ast::IntegerNode& node) const;
    int visit(const ast::FloatNode& node) const;
    int visit(const ast::ArrayNode& node) const;
    int visit(const ast::StringNode& node) const;
    int visit(const ast::LazyNode& node) const;
    int visit(const ast::VariableNode& node) const;
    int visit(const ast::VariableDefinitionNode& node) const;
    int visit(const ast::GlobalVariableNode& node) const;
    int visit(const ast::AssignmentNode& node) const;
    int visit(const ast::ArgumentNode& node) const;
    int visit(const ast::BinaryExpressionNode& node) const;
    int visit(const ast::CallFunctionNode& node) const;
    int visit(const ast::AccessElementNode& node) const;
    int visit(const ast::DeepCopyNode& node) const;
    int visit(const ast::BlockNode& node) const;
    int visit(const ast::IfNode& node) const;
    int visit(const ast::ForNode& node) const;
    int visit(const ast::GenericFunctionDeclarationNode& node) const;
    int visit(const ast::GenericFunctionNode& node) const;
    int visit(const ast::GenericClassNode& node) const;
    int visit(const ast::TypeIdNode& node) const;
    int visit(const ast::CastNode& node) const;
};
}  // namespace ast_to_mir
}  // namespace converter