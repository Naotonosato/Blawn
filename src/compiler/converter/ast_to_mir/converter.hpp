#pragma once
#include <memory>

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

class Visitor;

class ConverterInterface {
    protected:
    Visitor& visitor_ref;

    public:
    ConverterInterface(Visitor& visitor_ref) : visitor_ref(visitor_ref) {}
    virtual ~ConverterInterface() = default;
    virtual std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::RootNode> node) = 0;
    virtual std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::IntegerNode> node) = 0;
    virtual std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::FloatNode> node) = 0;
    virtual std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::ArrayNode> node) = 0;
    virtual std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::StringNode> node) = 0;

    virtual std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::VariableNode> node) = 0;
    virtual std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::GlobalVariableNode> node) = 0;
    virtual std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::AssignmentNode> node) = 0;
    virtual std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::ArgumentNode> node) = 0;

    virtual std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::BinaryExpressionNode> node) = 0;
    virtual std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::CallFunctionNode> node) = 0;
    virtual std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::AccessElementNode> node) = 0;

    virtual std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::DeepCopyNode> node) = 0;
    virtual std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::BlockNode> node) = 0;
    virtual std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::IfNode> node) = 0;
    virtual std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::ForNode> node) = 0;
    virtual std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::GenericFunctionDeclarationNode> node) = 0;
    virtual std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::GenericFunctionNode> node) = 0;

    virtual std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::GenericClassNode> node) = 0;
    virtual std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::TypeIdNode> node) = 0;
    virtual std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::CastNode> node) = 0;
};

class Converter : public ConverterInterface {
    public:
    Converter(Visitor& visitor_ref) : ConverterInterface(visitor_ref) {}
    std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::RootNode> node) override;
    std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::IntegerNode> node) override;
    std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::FloatNode> node) override;
    std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::ArrayNode> node) override;
    std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::StringNode> node) override;
    std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::VariableNode> node) override;
    std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::GlobalVariableNode> node) override;
    std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::AssignmentNode> node) override;
    std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::ArgumentNode> node) override;
    std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::BinaryExpressionNode> node) override;
    std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::CallFunctionNode> node) override;
    std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::AccessElementNode> node) override;
    std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::DeepCopyNode> node) override;
    std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::BlockNode> node) override;
    std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::IfNode> node) override;
    std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::ForNode> node) override;
    std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::GenericFunctionDeclarationNode> node) override;
    std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::GenericFunctionNode> node) override;
    std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::GenericClassNode> node) override;
    std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::TypeIdNode> node) override;
    std::unique_ptr<mir::MIR> convert(
        std::shared_ptr<ast::CastNode> node) override;
};

class Visitor {
    private:
    std::unique_ptr<ConverterInterface> converter;

    public:
    Visitor() { converter = std::make_unique<Converter>(*this); }

    ~Visitor() = default;
    template <typename T>
    std::unique_ptr<mir::MIR> operator()(T& arg) {
        return converter->convert(arg);
    }
};

Visitor get_visitor();

}  // namespace ast_to_mir
}  // namespace converter