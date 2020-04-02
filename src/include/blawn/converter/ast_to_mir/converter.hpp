#pragma once
#include <memory>
#include "include/utils/visitor_wrapper.hpp"

namespace ast {
class IntegerNode;
class FloatNode;
class ArrayNode;
class StringNode;
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

namespace mir {
class MIR;
}

namespace converter {
namespace ast_to_mir {

class Converter : public utils::VisitorBase<Converter> {
    public:
    Converter(utils::VisitorWrapper<Converter>& visitor_ref)
        : utils::VisitorBase<Converter>(visitor_ref) {}
    std::unique_ptr<mir::MIR> visit(std::shared_ptr<ast::RootNode> node);
    std::unique_ptr<mir::MIR> visit(std::shared_ptr<ast::IntegerNode> node);
    std::unique_ptr<mir::MIR> visit(std::shared_ptr<ast::FloatNode> node);
    std::unique_ptr<mir::MIR> visit(std::shared_ptr<ast::ArrayNode> node);
    std::unique_ptr<mir::MIR> visit(std::shared_ptr<ast::StringNode> node);
    std::unique_ptr<mir::MIR> visit(std::shared_ptr<ast::VariableNode> node);
    std::unique_ptr<mir::MIR> visit(
        std::shared_ptr<ast::GlobalVariableNode> node);
    std::unique_ptr<mir::MIR> visit(std::shared_ptr<ast::AssignmentNode> node);
    std::unique_ptr<mir::MIR> visit(std::shared_ptr<ast::ArgumentNode> node);
    std::unique_ptr<mir::MIR> visit(
        std::shared_ptr<ast::BinaryExpressionNode> node);
    std::unique_ptr<mir::MIR> visit(
        std::shared_ptr<ast::CallFunctionNode> node);
    std::unique_ptr<mir::MIR> visit(
        std::shared_ptr<ast::AccessElementNode> node);
    std::unique_ptr<mir::MIR> visit(std::shared_ptr<ast::DeepCopyNode> node);
    std::unique_ptr<mir::MIR> visit(std::shared_ptr<ast::BlockNode> node);
    std::unique_ptr<mir::MIR> visit(std::shared_ptr<ast::IfNode> node);
    std::unique_ptr<mir::MIR> visit(std::shared_ptr<ast::ForNode> node);
    std::unique_ptr<mir::MIR> visit(
        std::shared_ptr<ast::GenericFunctionDeclarationNode> node);
    std::unique_ptr<mir::MIR> visit(
        std::shared_ptr<ast::GenericFunctionNode> node);
    std::unique_ptr<mir::MIR> visit(
        std::shared_ptr<ast::GenericClassNode> node);
    std::unique_ptr<mir::MIR> visit(std::shared_ptr<ast::TypeIdNode> node);
    std::unique_ptr<mir::MIR> visit(std::shared_ptr<ast::CastNode> node);
};
}  // namespace ast_to_mir
}  // namespace converter