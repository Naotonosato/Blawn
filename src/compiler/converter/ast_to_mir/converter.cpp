#include <iostream>
#include "../../ast/node.hpp"
#include "converter.hpp"
#include "../../mir/mir/mir.hpp"

namespace converter {
namespace ast_to_mir {

std::unique_ptr<mir::MIR> Converter::convert(
    std::shared_ptr<ast::RootNode> node) {
    auto block = node->get_child_block();

    std::vector<std::unique_ptr<mir::MIR>> result;
    for (auto& expression : block->get_expressions()) {
        result.push_back(expression->accept(visitor_ref));
    }
    return 0;
}
std::unique_ptr<mir::MIR> Converter::convert(
    std::shared_ptr<ast::IntegerNode> node) {
    std::cout << node->get_initial_value() << std::endl;
    return 0;
}
std::unique_ptr<mir::MIR> Converter::convert(
    std::shared_ptr<ast::FloatNode> node) {
    std::cout << node->get_initial_value() << std::endl;
    return 0;
}
std::unique_ptr<mir::MIR> Converter::convert(
    std::shared_ptr<ast::ArrayNode> node) {
    std::cout << typeid(node).name() << std::endl;
    return 0;
}
std::unique_ptr<mir::MIR> Converter::convert(
    std::shared_ptr<ast::StringNode> node) {
    std::cout << "string: " << node->get_initial_value() << std::endl;
    return 0;
}
std::unique_ptr<mir::MIR> Converter::convert(
    std::shared_ptr<ast::VariableNode> node) {
    std::cout << "This variable is named " << node->get_name() << std::endl;
    node->get_initial_value()->accept(visitor_ref);
    return 0;
}
std::unique_ptr<mir::MIR> Converter::convert(
    std::shared_ptr<ast::GlobalVariableNode> node) {
    std::cout << typeid(node).name() << std::endl;
    return 0;
}
std::unique_ptr<mir::MIR> Converter::convert(
    std::shared_ptr<ast::AssignmentNode> node) {
    std::cout << typeid(node).name() << std::endl;
    return 0;
}
std::unique_ptr<mir::MIR> Converter::convert(
    std::shared_ptr<ast::ArgumentNode> node) {
    std::cout << typeid(node).name() << std::endl;
    return 0;
}
std::unique_ptr<mir::MIR> Converter::convert(
    std::shared_ptr<ast::BinaryExpressionNode> node) {
    std::cout << typeid(node).name() << std::endl;
    return 0;
}
std::unique_ptr<mir::MIR> Converter::convert(
    std::shared_ptr<ast::CallFunctionNode> node) {
    // std::shared_ptr<ast::GenericFunctionNode> functnion
    return 0;
}
std::unique_ptr<mir::MIR> Converter::convert(
    std::shared_ptr<ast::AccessElementNode> node) {
    std::cout << typeid(node).name() << std::endl;
    return 0;
}
std::unique_ptr<mir::MIR> Converter::convert(
    std::shared_ptr<ast::DeepCopyNode> node) {
    std::cout << typeid(node).name() << std::endl;
    return 0;
}
std::unique_ptr<mir::MIR> Converter::convert(
    std::shared_ptr<ast::BlockNode> node) {
    for (auto& line : node->get_expressions()) {
        line->accept(visitor_ref);
    }
    return 0;
}
std::unique_ptr<mir::MIR> Converter::convert(
    std::shared_ptr<ast::IfNode> node) {
    std::cout << typeid(node).name() << std::endl;
    return 0;
}
std::unique_ptr<mir::MIR> Converter::convert(
    std::shared_ptr<ast::ForNode> node) {
    std::cout << typeid(node).name() << std::endl;
    return 0;
}
std::unique_ptr<mir::MIR> Converter::convert(
    std::shared_ptr<ast::GenericFunctionDeclarationNode> node) {
    return 0;
}
std::unique_ptr<mir::MIR> Converter::convert(
    std::shared_ptr<ast::GenericFunctionNode> node) {
    std::cout << typeid(node).name() << std::endl;
    return 0;
}
std::unique_ptr<mir::MIR> Converter::convert(
    std::shared_ptr<ast::GenericClassNode> node) {
    std::cout << typeid(node).name() << std::endl;
    return 0;
}
std::unique_ptr<mir::MIR> Converter::convert(
    std::shared_ptr<ast::TypeIdNode> node) {
    std::cout << typeid(node).name() << std::endl;
    return 0;
}
std::unique_ptr<mir::MIR> Converter::convert(
    std::shared_ptr<ast::CastNode> node) {
    std::cout << typeid(node).name() << std::endl;
    return 0;
}
Visitor get_visitor() { return Visitor(); }

}  // namespace ast_to_mir
}  // namespace converter