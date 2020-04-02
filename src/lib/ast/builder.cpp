#include "include/ast/node.hpp"
#include "include/utils/scoped_collector.hpp"
#include "include/blawn/module/module.hpp"
#include "include/ast/builder.hpp"
#include <variant>

namespace ast {

Builder::Builder(std::shared_ptr<module::Module> module, int line_number)
    : module(module),
      current_line_number(line_number),
      current_scope(module->get_ast_container().get_scope()) {}

void Builder::count_line_number() { current_line_number += 1; }

const int Builder::get_current_line_number() const {
    return current_line_number;
}

void Builder::into_named_scope(std::string name) {
    module->get_ast_container().into_named_scope(name);
}

void Builder::into_anonymous_scope() {
    module->get_ast_container().into_anonymous_scope();
}

void Builder::break_out_of_scope() {
    module->get_ast_container().break_out_of_namespace();
}

std::shared_ptr<Node> create_binary_expression(std::shared_ptr<Node> node,
                                               std::shared_ptr<Node> other,
                                               const std::string operator_type);

std::shared_ptr<VariableNode> Builder::create_variable_definition(
    std::string name, std::shared_ptr<Node> right_node) {
    auto variable =
        std::make_shared<VariableNode>(current_line_number, name, right_node);
    module->get_ast_container().add(name, Node::create(variable));
    return variable;
}

std::shared_ptr<IntegerNode> Builder::create_integer(int num) {
    return std::make_shared<IntegerNode>(current_line_number, num);
}

std::shared_ptr<FloatNode> Builder::create_float(double num) {
    return std::make_shared<FloatNode>(current_line_number, num);
}

std::shared_ptr<Node> Builder::create_minus(std::shared_ptr<Node> expr) {
    auto zero = Node::create<IntegerNode>(current_line_number, 0);
    return Node::create(create_binary_expression(zero, expr, "-"));
}

std::shared_ptr<StringNode> Builder::create_string(std::string str) {
    return std::make_shared<StringNode>(current_line_number, str);
}

std::shared_ptr<Node> Builder::create_void() { return 0; }

std::shared_ptr<ArrayNode> Builder::create_array(
    std::vector<std::shared_ptr<Node>> elements) {
    return std::make_shared<ArrayNode>(current_line_number,
                                       std::move(elements));
}

std::shared_ptr<ArrayNode> Builder::create_array() {
    return std::make_shared<ArrayNode>(current_line_number);
}

std::shared_ptr<BinaryExpressionNode> Builder::create_binary_expression(
    std::shared_ptr<Node> node, std::shared_ptr<Node> other,
    const std::string& operator_type) {
    return std::make_shared<BinaryExpressionNode>(
        current_line_number, string_to_operator_type(operator_type), node,
        other);
}

std::shared_ptr<VariableNode> Builder::create_member_variable_definition(
    std::string name, std::shared_ptr<Node> node) {
    auto variable =
        std::make_shared<VariableNode>(current_line_number, name, node);
    module->get_ast_container().add(name, Node::create(variable));
    return variable;
}

std::shared_ptr<GlobalVariableNode> Builder::create_global_variable_definition(
    std::string name, std::shared_ptr<Node> node) {
    auto variable =
        std::make_shared<GlobalVariableNode>(current_line_number, name, node);
    module->get_ast_container().add(name, Node::create(variable),
                                    utils::Scope("[GLOBAL]"));
    return variable;
}

std::shared_ptr<ArgumentNode> Builder::create_argument(
    const std::string& name) {
    auto argument = std::make_shared<ArgumentNode>(current_line_number, name);
    module->get_ast_container().add(name, Node::create(argument));
    return argument;
}

std::shared_ptr<AssignmentNode> Builder::create_assignment(
    std::shared_ptr<Node> left, std::shared_ptr<Node> right) {
    return std::make_shared<AssignmentNode>(current_line_number, left, right);
}

std::shared_ptr<AssignmentNode> Builder::create_assignment(
    std::shared_ptr<AccessElementNode> left, std::shared_ptr<Node> right) {
    return create_assignment(Node::create(left), right);
}

std::shared_ptr<DeepCopyNode> Builder::create_deep_copy(
    std::shared_ptr<Node> pointer, std::shared_ptr<Node> object) {
    return std::make_shared<DeepCopyNode>(current_line_number, pointer, object);
}

std::shared_ptr<BlockNode> Builder::create_block(
    std::vector<std::shared_ptr<Node>>&& expressions) {
    return std::make_shared<BlockNode>(current_line_number,
                                       std::move(expressions));
}

std::shared_ptr<CallFunctionNode> Builder::create_call(
    std::string function_name, std::vector<std::shared_ptr<Node>> arguments) {
    auto got_node = module->get_ast_container().get(function_name);
    if (got_node.has_value() &&
        got_node.value()->is_type<GenericFunctionDeclarationNode>()) {
        auto declaration =
            got_node.value()->get_pointer<GenericFunctionDeclarationNode>();

        return std::make_shared<CallFunctionNode>(
            current_line_number, declaration, std::move(arguments));
    }
    auto declaration =
        create_generic_function_declaration(function_name, arguments.size());

    return std::make_shared<CallFunctionNode>(current_line_number, declaration,
                                              std::move(arguments));
}

std::shared_ptr<CallFunctionNode> Builder::create_call(
    std::shared_ptr<AccessElementNode>,
    std::vector<std::shared_ptr<Node>> arguments) {
    return 0;
}

std::shared_ptr<IfNode> Builder::create_if(
    std::shared_ptr<Node> cond, std::shared_ptr<BlockNode> if_body,
    std::shared_ptr<BlockNode> else_body) {
    // ignored else yet
    return std::make_shared<IfNode>(current_line_number, cond, if_body);
}

std::shared_ptr<ForNode> Builder::create_for(
    std::shared_ptr<Node> first_expression, std::shared_ptr<Node> cond,
    std::shared_ptr<Node> last_expression, std::shared_ptr<BlockNode> body) {
    return std::make_shared<ForNode>(current_line_number, first_expression,
                                     cond, last_expression, body);
}

std::shared_ptr<AccessElementNode> Builder::create_access(
    std::shared_ptr<Node> left, std::string right) {
    return std::make_shared<AccessElementNode>(current_line_number, left,
                                               right);
}

std::shared_ptr<GenericFunctionDeclarationNode>
Builder::create_generic_function_declaration(
    std::string name, std::vector<std::shared_ptr<ArgumentNode>> arguments) {
    return create_generic_function_declaration(name, arguments.size());
}

std::shared_ptr<GenericFunctionDeclarationNode>
Builder::create_generic_function_declaration(std::string name,
                                             int num_arguments) {
    auto declaration = std::make_shared<GenericFunctionDeclarationNode>(
        current_line_number, name, num_arguments);
    module->get_ast_container().add(name, Node::create(declaration));
    return declaration;
}

std::shared_ptr<GenericFunctionNode>
Builder::create_generic_function_definition(
    std::string name, std::vector<std::shared_ptr<ast::ArgumentNode>> arguments,
    std::shared_ptr<BlockNode> body, std::shared_ptr<Node> return_value) {
    auto declaration = (*module->get_ast_container().get(name))
                           ->get_pointer<GenericFunctionDeclarationNode>();

    auto definition = std::make_shared<GenericFunctionNode>(
        current_line_number, name, arguments, body, return_value);
    declaration->set_definition(definition);

    return definition;
}

/*
std::shared_ptr<Node> Builder::create_generic_class_declaration(
    std::string name, std::vector<std::string> argument_names) {
    auto declaration = Node::create<GenericClassNode>(
        current_line_number, name, std::move(argument_names));
    module->get_ast_container().add(name, declaration);
    return declaration;
}
*/

std::shared_ptr<GenericClassNode> Builder::create_generic_class_definition(
    std::string name, std::vector<std::shared_ptr<ast::ArgumentNode>> arguments,
    std::vector<std::shared_ptr<VariableNode>> members,
    std::vector<std::shared_ptr<GenericFunctionNode>> methods) {
    auto definition = std::make_shared<GenericClassNode>(
        current_line_number, name, std::move(arguments), std::move(members),
        std::move(methods));

    module->get_ast_container().add(name, Node::create(definition));
    return definition;
}

bool Builder::exist(std::string name) {
    return (module->get_ast_container().get(name) != std::nullopt);
}

std::shared_ptr<Node> Builder::get_named_node(std::string name) {
    auto node = module->get_ast_container().get(name);
    if (!node) {
        // print error message
        std::cout << "err" << std::endl;
        return nullptr;
    }
    return node.value();
}

std::shared_ptr<RootNode> Builder::create_root(
    std::shared_ptr<BlockNode> program) {
    root = std::make_shared<RootNode>(current_line_number, program);
    return root;
}

std::shared_ptr<Node> Builder::build() const { return Node::create(root); }

}  // namespace ast