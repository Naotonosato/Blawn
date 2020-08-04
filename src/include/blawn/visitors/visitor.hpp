#pragma once
#include "include/utils/visitor_wrapper.hpp"

namespace blawn
{
namespace visitors
{
template <typename ReturnType>
class ASTVisitor : public utils::VisitorBase<ASTVisitor<ReturnType>>
{
    public:
    ASTVisitor(utils::VisitorWrapper<ASTVisitor>& visitor_ref)
        : utils::VisitorBase<ASTVisitor<ReturnType>>(visitor_ref)
    {
    }
    ReturnType visit(const ast::RootNode& node) const;
    ReturnType visit(const ast::IntegerNode& node) const;
    ReturnType visit(const ast::FloatNode& node) const;
    ReturnType visit(const ast::ArrayNode& node) const;
    ReturnType visit(const ast::StringNode& node) const;
    ReturnType visit(const ast::LazyNode& node) const;
    ReturnType visit(const ast::VariableNode& node) const;
    ReturnType visit(const ast::VariableDefinitionNode& node) const;
    ReturnType visit(const ast::GlobalVariableNode& node) const;
    ReturnType visit(const ast::AssignmentNode& node) const;
    ReturnType visit(const ast::ArgumentNode& node) const;
    ReturnType visit(const ast::BinaryExpressionNode& node) const;
    ReturnType visit(const ast::CallFunctionNode& node) const;
    ReturnType visit(const ast::AccessElementNode& node) const;
    ReturnType visit(const ast::DeepCopyNode& node) const;
    ReturnType visit(const ast::BlockNode& node) const;
    ReturnType visit(const ast::IfNode& node) const;
    ReturnType visit(const ast::ForNode& node) const;
    ReturnType visit(const ast::GenericFunctionDeclarationNode& node) const;
    ReturnType visit(const ast::GenericFunctionNode& node) const;
    ReturnType visit(const ast::GenericClassNode& node) const;
    ReturnType visit(const ast::TypeIdNode& node) const;
    ReturnType visit(const ast::CastNode& node) const;
};
}  // namespace visitors
}  // namespace blawn