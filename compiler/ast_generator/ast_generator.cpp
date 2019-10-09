#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/raw_ostream.h>
#include "../ast/node.hpp"
#include "../blawn_context/blawn_context.hpp"
#include "../ir_generator/ir_generator.hpp"
#include "../utils/utils.hpp"
#include "node_collector.hpp"
#include "ast_generator.hpp"

static unsigned int unique_number = 0;
std::string get_unique_name() {
    unsigned int n = unique_number;
    unique_number += 1;
    std::string unique_name = "#" + std::to_string(n);
    return unique_name;
}

ASTGenerator::ASTGenerator(llvm::Module& module, llvm::IRBuilder<>& ir_builder,
                           llvm::LLVMContext& context)
    : module(module),
      ir_builder(ir_builder),
      context(context),
      variable_collector("TOP"),
      function_collector("TOP"),
      argument_collector("TOP"),
      class_collector("TOP"),
      C_type_collector("TOP"),
      ir_generators(context, module, ir_builder),
      line_number(1),
      no_value_node(new Node(0, ir_generators.ir_generator)) {}

void ASTGenerator::generate(std::vector<std::shared_ptr<Node>> program) {
    std::vector<std::string> top = {"TOP"};
    for (auto& line : program) {
        line->generate();
    }
    for (auto& c : class_collector.get_all()) {
        for (auto& cv : c->get_base_constructors()) {
            std::string n = cv->getName();
            // std::cout << "erasing constructor named " << n << std::endl;
            cv->eraseFromParent();
        }
    }
    for (auto& c : C_type_collector.get_all()) {
        for (auto& cv : c->get_base_constructors()) {
            std::string n = cv->getName();
            // std::cout << "erasing ctype constructor named " << n <<
            // std::endl;
            cv->eraseFromParent();
        }
    }
    for (auto& f : function_collector.get_all()) {
        for (auto& fv : f->get_base_functions()) {
            fv->eraseFromParent();
        }
    }
}

void ASTGenerator::into_namespace(std::string name) {
    variable_collector.into_namespace(name);
    function_collector.into_namespace(name);
    argument_collector.into_namespace(name);
    class_collector.into_namespace(name);
    C_type_collector.into_namespace(name);
}

void ASTGenerator::into_namespace() {
    std::string name = get_unique_name();
    into_namespace(name);
}

void ASTGenerator::break_out_of_namespace() {
    variable_collector.break_out_of_namespace();
    function_collector.break_out_of_namespace();
    argument_collector.break_out_of_namespace();
    class_collector.break_out_of_namespace();
    C_type_collector.break_out_of_namespace();
}

std::shared_ptr<Node> ASTGenerator::assign(std::string name,
                                           std::shared_ptr<Node> right_node,
                                           bool is_global) {
    if (variable_collector.exist(name)) {
        auto variable = variable_collector.get(name);
        auto assigment = std::shared_ptr<AssigmentNode>(
            new AssigmentNode(line_number, ir_generators.assigment_generator,
                              right_node, variable, nullptr));
        return assigment;
    } else {
        auto variable = std::shared_ptr<VariableNode>(
            new VariableNode(line_number, ir_generators.variable_generator,
                             is_global, right_node, name));
        variable_collector.set(name, variable);
        return variable;
    }
}

std::shared_ptr<Node> ASTGenerator::assign(std::shared_ptr<AccessNode> left,
                                           std::shared_ptr<Node> right) {
    auto assigment = std::shared_ptr<AssigmentNode>(new AssigmentNode(
        line_number, ir_generators.assigment_generator, right, nullptr, left));
    return assigment;
}

std::shared_ptr<Node> ASTGenerator::declare_C_function(
    std::string name, std::vector<std::shared_ptr<Node>> args,
    std::shared_ptr<Node> return_) {
    std::unique_ptr<DeclareCNode> node(new DeclareCNode(
        line_number, ir_generators.declare_C_generator, name, args, return_));
    return std::move(node);
}

std::shared_ptr<Node> ASTGenerator::get_named_value(std::string name) {
    if (variable_collector.exist(name)) {
        auto o = variable_collector.get(name);
        return variable_collector.get(name);
    } else {
        if (argument_collector.exist(name)) {
            return argument_collector.get(name);
        }
        std::cout << "Error: variable '" << name << "' is not declared.\n";
        exit(0);
    }
}

std::shared_ptr<Node> ASTGenerator::create_C_member(std::string name) {
    std::string splitter =
        "__C_PTR__"
        " ";
    std::vector<std::string> parsed;
    utils::split(name, splitter, parsed);
    std::string type_name = parsed.back();
    auto class_node = C_type_collector.get(type_name);
    auto node = std::shared_ptr<Node>(new NullNode(
        line_number, ir_generators.null_generator, name, class_node));
    return node;
}

void ASTGenerator::add_argument(std::string arg_name) {
    auto argument = std::shared_ptr<ArgumentNode>(new ArgumentNode(
        line_number, ir_generators.argument_generator, arg_name));
    argument_collector.set(arg_name, argument);
}

void ASTGenerator::book_function(std::string name) {}

std::shared_ptr<FunctionNode> ASTGenerator::add_function(
    std::string name, std::vector<std::string> arguments,
    std::vector<std::shared_ptr<Node>> body,
    std::shared_ptr<Node> return_value) {
    auto func = std::shared_ptr<FunctionNode>(
        new FunctionNode(line_number, ir_generators.function_generator, name,
                         arguments, std::move(body), std::move(return_value)));
    std::vector<std::string> previous_namespace =
        function_collector.get_namespace();
    previous_namespace.pop_back();
    function_collector.set(name, func, previous_namespace);
    func->set_self_namespace(function_collector.get_namespace());
    return func;
}

std::shared_ptr<ClassNode> ASTGenerator::create_class(
    std::string name, std::vector<std::string> arguments,
    std::vector<std::shared_ptr<Node>> members_definition,
    std::vector<std::shared_ptr<FunctionNode>> methods) {
    auto class_ = std::shared_ptr<ClassNode>(
        new ClassNode(line_number, ir_generators.class_generator, methods,
                      members_definition, arguments, false, name));
    std::vector<std::string> previous_namespace =
        class_collector.get_namespace();
    previous_namespace.pop_back();
    // previous_namespace.pop_back();
    class_->set_self_namespace(class_collector.get_namespace());
    class_collector.set(name, class_, previous_namespace);
    return class_;
}

std::shared_ptr<ClassNode> ASTGenerator::create_C_type(
    std::string name, std::vector<std::shared_ptr<Node>> members_definition) {
    /*
    Ctype definition is alomost same with class definition.
    Ctype definition is class definition without arguments and methods.
    */
    auto c_type = std::shared_ptr<ClassNode>(
        new ClassNode(line_number, ir_generators.class_generator, {},
                      members_definition, {}, true, name));
    std::vector<std::string> previous_namespace =
        C_type_collector.get_namespace();
    previous_namespace.pop_back();
    // previous_namespace.pop_back();
    c_type->set_self_namespace(class_collector.get_namespace());
    C_type_collector.set(name, c_type, previous_namespace);
    return c_type;
}

std::unique_ptr<Node> ASTGenerator::create_call(
    std::string name, std::vector<std::shared_ptr<Node>> arguments) {
    if (name == "sizeof" && arguments.size() == 1) {
        auto sizeof_node = std::unique_ptr<SizeofNode>(new SizeofNode(
            line_number, ir_generators.sizeof_generator, arguments[0]));
        return std::move(sizeof_node);
    }
    if (name == "typeid" && arguments.size() == 1) {
        auto typeid_node = std::unique_ptr<TypeIdNode>(new TypeIdNode(
            line_number, ir_generators.typeid_generator, arguments[0]));
        return std::move(typeid_node);
    }
    if (name == "__blawn_cast__" && arguments.size() == 2) {
        auto cast_node = std::unique_ptr<CastNode>(
            new CastNode(line_number, ir_generators.cast_generator,
                         arguments[0], arguments[1]));
        return std::move(cast_node);
    }
    if (get_blawn_context().exist_builtin_function(name)) {
        auto b_func = get_blawn_context().get_builtin_function(name);
        auto calling = std::unique_ptr<CallFunctionNode>(
            new CallFunctionNode(line_number, ir_generators.calling_generator,
                                 arguments, argument_collector, b_func));
        return std::move(calling);
    }
    if (get_blawn_context().exist_C_function(name)) {
        auto c_func = get_blawn_context().get_C_function(name);
        auto calling = std::unique_ptr<CallFunctionNode>(
            new CallFunctionNode(line_number, ir_generators.calling_generator,
                                 arguments, argument_collector, c_func));
        return std::move(calling);
    }
    if (function_collector.exist(name)) {
        auto function = function_collector.get(name);
        auto calling = std::unique_ptr<CallFunctionNode>(
            new CallFunctionNode(line_number, ir_generators.calling_generator,
                                 function, arguments, argument_collector));
        return std::move(calling);
    }

    if (class_collector.exist(name)) {
        auto class_ = class_collector.get(name);
        auto constructor =
            std::unique_ptr<CallConstructorNode>(new CallConstructorNode(
                line_number, ir_generators.call_constructor_generator, class_,
                arguments, class_collector.get_namespace(),
                argument_collector));
        return std::move(constructor);
    }
    if (C_type_collector.exist(name)) {
        auto C_type = C_type_collector.get(name);
        auto constructor =
            std::unique_ptr<CallConstructorNode>(new CallConstructorNode(
                line_number, ir_generators.call_constructor_generator, C_type,
                arguments, class_collector.get_namespace(),
                argument_collector));
        return std::move(constructor);
    } else {
        auto function = function_collector.get(name);
        auto calling = std::unique_ptr<CallFunctionNode>(
            new CallFunctionNode(line_number, ir_generators.calling_generator,
                                 arguments, argument_collector, name));
        return std::move(calling);
        // std::cout << "Error: function or class '" << name << "' is not
        // defined."
        // << std::endl; exit(0);
    }
}

std::shared_ptr<Node> ASTGenerator::create_call(
    std::shared_ptr<AccessNode> left,
    std::vector<std::shared_ptr<Node>> arguments) {
    arguments.insert(arguments.begin(), left->get_left_node());
    auto call_node = std::shared_ptr<CallFunctionNode>(
        new CallFunctionNode(line_number, ir_generators.calling_generator,
                             nullptr, arguments, argument_collector));
    left->set_call_node(call_node);
    return left;
}

std::unique_ptr<IntegerNode> ASTGenerator::create_integer(int num) {
    auto Integer = std::unique_ptr<IntegerNode>(
        new IntegerNode(line_number, ir_generators.int_ir_generator));
    Integer->int_num = num;
    return std::move(Integer);
}

std::unique_ptr<FloatNode> ASTGenerator::create_float(double num) {
    auto float_ = std::unique_ptr<FloatNode>(
        new FloatNode(line_number, ir_generators.float_ir_generator));
    float_->float_num = num;
    return std::move(float_);
}

std::unique_ptr<StringNode> ASTGenerator::create_string(std::string str) {
    auto string = std::make_unique<StringNode>(line_number,
                                               ir_generators.string_generator);
    string->string = str;
    return std::move(string);
}

std::unique_ptr<BinaryExpressionNode> ASTGenerator::attach_operator(
    std::shared_ptr<Node> left_node, std::shared_ptr<Node> right_node,
    const std::string operator_kind) {
    auto expression =
        std::unique_ptr<BinaryExpressionNode>(new BinaryExpressionNode(
            line_number, ir_generators.binary_expression_generator));
    expression->left_node = std::move(left_node);
    expression->right_node = std::move(right_node);
    expression->operator_kind = operator_kind;
    return std::move(expression);
}

std::shared_ptr<Node> ASTGenerator::create_if(
    std::shared_ptr<Node> conditions, std::vector<std::shared_ptr<Node>> body) {
    std::vector<std::shared_ptr<Node>> empty;
    auto if_node = std::shared_ptr<IfNode>(new IfNode(
        line_number, ir_generators.if_generator, conditions, body, empty));
    previous_if_node = if_node;
    return if_node;
}
std::shared_ptr<Node> ASTGenerator::create_for(
    std::shared_ptr<Node> left, std::shared_ptr<Node> center,
    std::shared_ptr<Node> right, std::vector<std::shared_ptr<Node>> body) {
    auto for_node = std::shared_ptr<ForNode>(new ForNode(
        line_number, ir_generators.for_generator, left, center, right, body));
    return for_node;
}

std::shared_ptr<Node> ASTGenerator::add_else(
    std::vector<std::shared_ptr<Node>> body) {
    previous_if_node->set_else_body(body);
    auto res = std::make_shared<Node>(line_number, ir_generators.ir_generator);
    return res;
}

std::shared_ptr<AccessNode> ASTGenerator::create_access(std::string left,
                                                        std::string right) {
    auto left_node = get_named_value(left);
    auto accessing = std::shared_ptr<AccessNode>(
        new AccessNode(line_number, ir_generators.access_generator, left_node,
                       right, function_collector));
    return accessing;
}

std::shared_ptr<AccessNode> ASTGenerator::create_access(
    std::shared_ptr<Node> left, std::string right) {
    auto accessing = std::shared_ptr<AccessNode>(
        new AccessNode(line_number, ir_generators.access_generator, left, right,
                       function_collector));
    return accessing;
}

std::shared_ptr<ListNode> ASTGenerator::create_list(
    std::vector<std::shared_ptr<Node>> elements) {
    auto list_node = std::shared_ptr<ListNode>(
        new ListNode(line_number, ir_generators.list_generator, elements));
    return list_node;
}
std::shared_ptr<ListNode> ASTGenerator::create_list() {
    auto list_node = std::shared_ptr<ListNode>(
        new ListNode(line_number, ir_generators.list_generator, true));
    return list_node;
}

std::shared_ptr<Node> ASTGenerator::create_block_end() {
    auto end_scope = variable_collector.get_namespace();
    auto node = std::shared_ptr<BlockEndNode>(new BlockEndNode(
        line_number, ir_generators.block_end_generator, end_scope));
    return node;
}