#include "node.hpp"
#include "../ir_generator/ir_generator.hpp"
#include "../utils/utils.hpp"
#include "node_collector.hpp"
#include "builder.hpp"

static unsigned int unique_number = 0;
std::string get_unique_name() {
    unsigned int n = unique_number;
    unique_number += 1;
    std::string unique_name = "#" + std::to_string(n);
    return unique_name;
}

namespace ast {

Builder::Builder(int line_number)
    : node_collector(ScopedCollector<Node>()),current_line_number(line_number)
    {
        current_scope = node_collector.get_namespace();
    }


void Builder::into_namespace(std::string name) {
    node_collector.into_namespace(name);
}

void Builder::into_anonymous_namespace() {
    std::string name = get_unique_name();
    into_namespace(name);
}

void Builder::break_out_of_namespace() {
    node_collector.break_out_of_namespace();
}

std::shared_ptr<Node> Builder::create_variable_definition(
    std::string name, std::shared_ptr<Node> right_node) {
    
}


std::shared_ptr<Node> Builder::get_named_value(std::string name) {
    if (node_collector.exist(name)) return node_collector.get(name);
    else return nullptr;
}


void Builder::create_generic_function_declaration(std::string name) {
    node_collector.set(name,Node::create<GenericFunctionNode>());
}

std::shared_ptr<GenericFunctionNode> Builder::add_function(
    std::string name, std::vector<std::string> arguments,
    std::vector<std::shared_ptr<Node>> body,
    std::shared_ptr<Node> return_value) {
    
}

std::shared_ptr<GenericClassNode> Builder::create_class(
    std::string name, std::vector<std::string> arguments,
    std::vector<std::shared_ptr<Node>> members_definition,
    std::vector<std::shared_ptr<GenericFunctionNode>> methods) {
    if (class_collector.exist(name)) {
        logger.set_line_number(line_number);
        logger.multiple_definition_error("class", name);
    }
    auto class_ = std::shared_ptr<GenericClassNode>(new GenericClassNode(
        line_number, current_scope, ir_generators.class_generator, methods,
        members_definition, arguments, false, name));
    Scope previous_scope = class_collector.get_namespace();
    previous_scope.pop_back();
    // previous_scope.pop_back();
    class_->set_self_namespace(class_collector.get_namespace());
    class_collector.set(name, class_, {"TOP"});  // previous_scope);
    return class_;
}

std::shared_ptr<GenericClassNode> Builder::create_C_type(
    std::string name,
    std::vector<std::shared_ptr<Node>> members_definition) {
    /*
    Ctype definition is alomost same with class definition.
    Ctype definition is class definition without arguments and methods.
    */
    auto c_type = std::shared_ptr<GenericClassNode>(new GenericClassNode(
        line_number, current_scope, ir_generators.class_generator, {},
        members_definition, {}, true, name));
    Scope previous_scope = C_type_collector.get_namespace();
    previous_scope.pop_back();
    // previous_scope.pop_back();
    c_type->set_self_namespace(class_collector.get_namespace());
    C_type_collector.set(name, c_type, {"TOP"});
    return c_type;
}

std::shared_ptr<Node> Builder::create_call(
    std::string name, std::vector<std::shared_ptr<Node>> arguments) {
    if (name == "sizeof" && arguments.size() == 1) {
        auto sizeof_node = std::shared_ptr<SizeofNode>(
            new SizeofNode(current_line_number, current_scope,
                                ir_generators.sizeof_generator, arguments[0]));
        return std::move(sizeof_node);
    }
    if (name == "typeid" && arguments.size() == 1) {
        auto typeid_node = std::shared_ptr<TypeIdNode>(
            new TypeIdNode(current_line_number, current_scope,
                                ir_generators.typeid_generator, arguments[0]));
        return std::move(typeid_node);
    }
    if (name == "__blawn_cast__" && arguments.size() == 2) {
        auto cast_node = std::shared_ptr<CastNode>(new CastNode(
            current_line_number, current_scope, ir_generators.cast_generator,
            arguments[0], arguments[1]));
        return std::move(cast_node);
    }
    if (get_blawn_context().exist_builtin_function(name)) {
        auto b_func = get_blawn_context().get_builtin_function(name);
        auto calling =
            std::shared_ptr<CallFunctionNode>(new CallFunctionNode(
                current_line_number, current_scope, ir_generators.calling_generator,
                arguments, argument_collector, b_func));
        return std::move(calling);
    }
    if (get_blawn_context().exist_C_function(name)) {
        auto c_func = get_blawn_context().get_C_function(name);
        auto calling =
            std::shared_ptr<CallFunctionNode>(new CallFunctionNode(
                current_line_number, current_scope, ir_generators.calling_generator,
                arguments, argument_collector, name));
        return std::move(calling);
    }
    if (function_collector.exist(name)) {
        auto function = function_collector.get(name);
        auto calling =
            std::shared_ptr<CallFunctionNode>(new CallFunctionNode(
                current_line_number, current_scope, ir_generators.calling_generator,
                function, arguments, argument_collector));
        return std::move(calling);
    }

    if (class_collector.exist(name)) {
        auto class_ = class_collector.get(name);
        auto constructor = std::shared_ptr<CallConstructorNode>(
            new CallConstructorNode(
                current_line_number, current_scope,
                ir_generators.call_constructor_generator, class_, arguments,
                class_collector.get_namespace(), argument_collector));
        return std::move(constructor);
    }
    if (C_type_collector.exist(name)) {
        auto C_type = C_type_collector.get(name);
        auto constructor = std::shared_ptr<CallConstructorNode>(
            new CallConstructorNode(
                current_line_number, current_scope,
                ir_generators.call_constructor_generator, C_type, arguments,
                class_collector.get_namespace(), argument_collector));
        return std::move(constructor);
    } else {
        auto function = function_collector.get(name);
        auto calling =
            std::shared_ptr<CallFunctionNode>(new CallFunctionNode(
                current_line_number, current_scope, ir_generators.calling_generator,
                arguments, argument_collector, name));
        return std::move(calling);
    }
}

std::shared_ptr<Node> Builder::create_call(
    std::shared_ptr<AccessNode> left,
    std::vector<std::shared_ptr<Node>> arguments) {
    arguments.insert(arguments.begin(), left->get_left_node());
    auto call_node =
        std::shared_ptr<CallFunctionNode>(new CallFunctionNode(
            current_line_number, current_scope, ir_generators.calling_generator,
            nullptr, arguments, argument_collector));
    left->set_call_node(call_node);
    return left;
}

std::shared_ptr<IntegerNode> Builder::create_integer(int num) {
    auto Integer = std::shared_ptr<IntegerNode>(new IntegerNode(
        current_line_number, current_scope, ir_generators.int_ir_generator));
    Integer->int_num = num;
    return std::move(Integer);
}

std::shared_ptr<FloatNode> Builder::create_float(double num) {
    auto float_ = std::shared_ptr<FloatNode>(new FloatNode(
        current_line_number, current_scope, ir_generators.float_ir_generator));
    float_->float_num = num;
    return std::move(float_);
}

std::shared_ptr<Node> Builder::create_minus(
    std::shared_ptr<Node> expr) {
    auto zero = std::shared_ptr<Node>(create_integer(0));
    auto minus = attach_operator(zero, expr, "-");
    return minus;
}

std::shared_ptr<StringNode> Builder::create_string(std::string str) {
    auto string = std::make_shared<StringNode>(
        current_line_number, current_scope, ir_generators.string_generator);
    string->string = str;
    return string;
}

std::shared_ptr<BinaryExpressionNode> Builder::attach_operator(
    std::shared_ptr<Node> left_node, std::shared_ptr<Node> right_node,
    const std::string operator_kind) {
    auto expression = std::shared_ptr<BinaryExpressionNode>(
        new BinaryExpressionNode(
            line_number, current_scope,
            ir_generators.binary_expression_generator));
    expression->left_node = std::move(left_node);
    expression->right_node = std::move(right_node);
    expression->operator_kind = operator_kind;
    return std::move(expression);
}

std::shared_ptr<Node> Builder::create_if(
    std::shared_ptr<Node> conditions,
    std::vector<std::shared_ptr<Node>> if_body,
    std::vector<std::shared_ptr<Node>> else_body) {
    auto if_node = std::shared_ptr<IfNode>(
        new IfNode(current_line_number, current_scope, ir_generators.if_generator,
                        conditions, if_body, else_body));
    return if_node;
}
std::shared_ptr<Node> Builder::create_for(
    std::shared_ptr<Node> left, std::shared_ptr<Node> center,
    std::shared_ptr<Node> right,
    std::vector<std::shared_ptr<Node>> body) {
    auto for_node = std::shared_ptr<ForNode>(new ForNode(
        current_line_number, current_scope, ir_generators.for_generator, left, center,
        right, body));
    return for_node;
}

std::shared_ptr<AccessNode> Builder::create_access(
    std::string left, std::string right) {
    auto left_node = get_named_value(left);
    auto accessing = std::shared_ptr<AccessNode>(new AccessNode(
        current_line_number, left_node->self_scope, ir_generators.access_generator,
        left_node, right, function_collector));
    return accessing;
}

std::shared_ptr<AccessNode> Builder::create_access(
    std::shared_ptr<Node> left, std::string right) {
    auto accessing = std::shared_ptr<AccessNode>(new AccessNode(
        current_line_number, left->self_scope, ir_generators.access_generator, left,
        right, function_collector));
    return accessing;
}

std::shared_ptr<ArrayNode> Builder::create_list(
    std::vector<std::shared_ptr<Node>> elements) {
    auto list_node = std::shared_ptr<ArrayNode>(new ArrayNode(
        line_number, current_scope, ir_generators.list_generator, elements));
    return list_node;
}
std::shared_ptr<ArrayNode> Builder::create_list() {
    auto list_node = std::shared_ptr<ArrayNode>(new ArrayNode(
        line_number, current_scope, ir_generators.list_generator, true));
    return list_node;
}

std::shared_ptr<Node> Builder::create_block_end() {
    auto end_scope = variable_collector.get_namespace();
    auto node = std::shared_ptr<BlockEndNode>(
        new BlockEndNode(current_line_number, current_scope,
                              ir_generators.block_end_generator, end_scope));
    return node;
}
}