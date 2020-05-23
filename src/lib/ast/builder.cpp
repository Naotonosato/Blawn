#include "include/ast/node.hpp"
#include "include/scope/scoped_collector.hpp"
#include "include/blawn/module/module.hpp"
#include "include/ast/builder.hpp"
#include "include/debug/debug_info.hpp"
#include "include/scope/mangler.hpp"
#include <variant>

namespace ast
{
Builder::Builder(std::string filename)
    : filename(filename),
      current_line_number(0),
      ast_container(scope::ScopedCollector<NodeExistsState>("[GLOBAL]")),
      current_scope_id(ast_container.get_scope_id())
{
}

debug::DebugInfo Builder::create_current_debug_info()
{
    auto token_info = debug::TokenInfo(current_line_number, current_token_index,
                                       current_token);
    return debug::DebugInfo(filename, std::move(token_info), current_scope_id);
}

void Builder::count_line_number() { current_line_number += 1; }

void Builder::count_token_index(int index) { current_token_index += index; }

void Builder::set_token(std::string token) { current_token = token; }

void Builder::into_named_scope(std::string name)
{
    ast_container.into_named_scope(name);
}

void Builder::into_anonymous_scope() { ast_container.into_anonymous_scope(); }

void Builder::break_out_of_scope() { ast_container.break_out_of_namespace(); }

std::unique_ptr<Node> Builder::create_variable_definition(
    std::string name, std::unique_ptr<Node>&& right_node)
{
    auto variable = Node::create<VariableDefinitionNode>(
        create_current_debug_info(), scope::mangle(name, current_scope_id),
        std::move(right_node));
    ast_container.add(name, EXISTS);
    return variable;
}

std::unique_ptr<Node> Builder::create_integer(int num)
{
    return Node::create<IntegerNode>(create_current_debug_info(), num);
}

std::unique_ptr<Node> Builder::create_float(double num)
{
    return Node::create<FloatNode>(create_current_debug_info(), num);
}

std::unique_ptr<Node> Builder::create_minus(std::unique_ptr<Node>&& expr)
{
    auto zero = Node::create<IntegerNode>(create_current_debug_info(), 0);
    return create_binary_expression(std::move(zero), std::move(expr), "MINUS");
}

std::unique_ptr<Node> Builder::create_string(std::string str)
{
    return Node::create<StringNode>(create_current_debug_info(), str);
}

std::unique_ptr<Node> Builder::create_void() { return 0; }

std::unique_ptr<Node> Builder::create_lazy()
{
    return Node::create<LazyNode>(create_current_debug_info());
}

std::unique_ptr<Node> Builder::create_array(
    std::vector<std::unique_ptr<Node>>&& elements)
{
    return Node::create<ArrayNode>(create_current_debug_info(),
                                   std::move(elements));
}

std::unique_ptr<Node> Builder::create_array()
{
    return Node::create<ArrayNode>(create_current_debug_info());
}

std::unique_ptr<Node> Builder::create_binary_expression(
    std::unique_ptr<Node>&& node, std::unique_ptr<Node>&& other,
    const std::string& operator_type)
{
    return Node::create<BinaryExpressionNode>(
        create_current_debug_info(), string_to_operator_type(operator_type),
        std::move(node), std::move(other));
}

std::unique_ptr<Node> Builder::create_member_variable_definition(
    std::string name, std::unique_ptr<Node>&& node)
{
    auto variable = Node::create<VariableNode>(
        create_current_debug_info(), scope::mangle(name, current_scope_id));
    ast_container.add(name, EXISTS);
    return variable;
}

std::unique_ptr<Node> Builder::create_global_variable_definition(
    std::string name, std::unique_ptr<Node>&& node)
{
    auto variable = Node::create<GlobalVariableNode>(
        create_current_debug_info(), scope::mangle(name, current_scope_id),
        std::move(node));
    ast_container.add(name, EXISTS, scope::Scope::create("[GLOBAL]"));
    return variable;
}

std::unique_ptr<Node> Builder::create_argument(std::string name)
{
    auto argument = Node::create<ArgumentNode>(
        create_current_debug_info(), scope::mangle(name, current_scope_id));
    ast_container.add(name, NO_DEFINITION);
    return argument;
}

std::unique_ptr<Node> Builder::create_assignment(std::unique_ptr<Node>&& left,
                                                 std::unique_ptr<Node>&& right)
{
    return Node::create<AssignmentNode>(create_current_debug_info(),
                                        std::move(left), std::move(right));
}

std::unique_ptr<Node> Builder::create_deep_copy(std::unique_ptr<Node>&& pointer,
                                                std::unique_ptr<Node>&& object)
{
    return Node::create<DeepCopyNode>(create_current_debug_info(),
                                      std::move(pointer), std::move(object));
}

std::unique_ptr<Node> Builder::create_block(
    std::vector<std::unique_ptr<Node>>&& expressions)
{
    return Node::create<BlockNode>(create_current_debug_info(),
                                   std::move(expressions));
}

std::unique_ptr<Node> Builder::create_call(
    std::unique_ptr<Node>&& function,
    std::vector<std::unique_ptr<Node>>&& arguments)
{
    return Node::create<CallFunctionNode>(
        create_current_debug_info(), std::move(function), std::move(arguments));
}

std::unique_ptr<Node> Builder::create_call(
    const std::string& function_name,
    std::vector<std::unique_ptr<Node>>&& arguments)
{
    auto function = Node::create<VariableNode>(
        create_current_debug_info(),
        scope::mangle(function_name, current_scope_id));
    return Node::create<CallFunctionNode>(
        create_current_debug_info(), std::move(function), std::move(arguments));
}

std::unique_ptr<Node> Builder::create_if(std::unique_ptr<Node>&& cond,
                                         std::unique_ptr<Node>&& if_body,
                                         std::unique_ptr<Node>&& else_body)
{
    // ignored else yet
    return Node::create<IfNode>(create_current_debug_info(), std::move(cond),
                                std::move(if_body));
}

std::unique_ptr<Node> Builder::create_for(
    std::unique_ptr<Node>&& first_expression, std::unique_ptr<Node>&& cond,
    std::unique_ptr<Node>&& last_expression, std::unique_ptr<Node>&& body)
{
    return Node::create<ForNode>(create_current_debug_info(),
                                 std::move(first_expression), std::move(cond),
                                 std::move(last_expression), std::move(body));
}

std::unique_ptr<Node> Builder::create_access(std::unique_ptr<Node>&& left,
                                             std::string right)
{
    return Node::create<AccessElementNode>(create_current_debug_info(),
                                           std::move(left), std::move(right));
}

std::unique_ptr<Node> Builder::create_generic_function_declaration(
    std::string name, std::vector<std::unique_ptr<Node>>&& arguments)
{
    return 0;  // create_generic_function_declaration(name, arguments.size());
}

std::unique_ptr<Node> Builder::create_generic_function_declaration(
    std::string name, int num_arguments)
{
    auto declaration = Node::create<GenericFunctionDeclarationNode>(
        create_current_debug_info(), scope::mangle(name, current_scope_id),
        num_arguments);
    ast_container.add(name, NO_DEFINITION);

    return declaration;
}

std::unique_ptr<Node> Builder::create_generic_function_definition(
    const std::string& name, std::vector<std::unique_ptr<Node>>&& arguments,
    std::unique_ptr<Node>&& body)
{
    auto previous_scope_id = scope::ScopePool::get(current_scope_id).pop();

    auto definition = Node::create<GenericFunctionNode>(
        create_current_debug_info(), scope::mangle(name, previous_scope_id),
        std::move(arguments), std::move(body));
    return definition;
}

/*
std::unique_ptr<Node> Builder::create_generic_class_declaration(
    std::string name, std::vector<std::string> argument_names) {
    auto declaration = Node::create<GenericClassNode>(
        create_debug_info(),scope::mangle(name,current_scope),
std::move(argument_names)); ast_container.add(name, declaration); return
declaration;
}
*/

std::unique_ptr<Node> Builder::create_generic_class_definition(
    const std::string& name, std::vector<std::unique_ptr<Node>>&& arguments,
    std::vector<std::unique_ptr<Node>>&& members,
    std::vector<std::unique_ptr<Node>>&& methods)
{
    /*
auto definition = Node::create<GenericClassNode>(
    create_current_debug_info(), scope::mangle(name, current_scope),
    std::move(arguments), std::move(members), std::move(methods));

ast_container.add(name, Node::create(definition));
*/
    return 0;  // definition;
}

bool Builder::exist_named_expression(std::string name)
{
    return (ast_container.get(name) != std::nullopt);
}

std::unique_ptr<Node> Builder::create_named_node(std::string name)
{
    auto node = ast_container.get(name);
    if (node == NOT_EXISTS)
    {
        // print error message
        std::cout << "err" << std::endl;
        exit(1);
        return nullptr;
    }
    return Node::create<VariableNode>(create_current_debug_info(), name);
}

void Builder::create_root(std::vector<std::unique_ptr<Node>>&& program)
{
    root =
        Node::create<RootNode>(create_current_debug_info(), std::move(program));
}

Node& Builder::build() const { return *root; }

}  // namespace ast