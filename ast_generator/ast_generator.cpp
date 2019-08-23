#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Support/raw_ostream.h>
#include "node_collector.hpp"
#include "../ast/node.hpp"
#include "../ir_generator/ir_generator.hpp"
#include "ast_generator.hpp"


ASTGenerator::ASTGenerator(
    llvm::Module &module,
    llvm::IRBuilder<> &ir_builder,
    llvm::LLVMContext &context
    )
:module(module),ir_builder(ir_builder),context(context),
variable_collector("TOP"),
function_collector("TOP"),
argument_collector("TOP"),
class_collector("TOP"),
if_collector("TOP"),
ir_generator(context,module,ir_builder),
int_ir_generator(context,module,ir_builder),
float_ir_generator(context,module,ir_builder),
variable_generator(context,module,ir_builder),
argument_generator(context,module,ir_builder),
assigment_generator(context,module,ir_builder),
binary_expression_generator(context,module,ir_builder),
function_generator(context,module,ir_builder),
calling_generator(context,module,ir_builder),
class_generator(context,module,ir_builder),
call_constructor_generator(context,module,ir_builder),
if_generator(context,module,ir_builder),
access_generator(context,module,ir_builder)
{
}

void ASTGenerator::generate(std::vector<std::shared_ptr<Node>> all)
{
    std::vector<std::string> top = {"TOP"};
    for (auto& line:all)
    {
        line->generate();
    }
    for (auto& f:function_collector.get_all(top))
    {
        f->get_base_function()->eraseFromParent();
    }
    for(auto& c:class_collector.get_all(top))
    {
        c->get_base_constructor()->eraseFromParent();
    }
}


void ASTGenerator::into_namespace(std::string name)
{
    variable_collector.into_namespace(name);
    function_collector.into_namespace(name);
    argument_collector.into_namespace(name);
    class_collector.into_namespace(name);
    if_collector.into_namespace(name);
}

void ASTGenerator::break_out_of_namespace()
{
    variable_collector.break_out_of_namespace();
    function_collector.break_out_of_namespace();
    argument_collector.break_out_of_namespace();
    class_collector.break_out_of_namespace();
    if_collector.break_out_of_namespace();
}

std::shared_ptr<Node> ASTGenerator::assign(std::string name,std::shared_ptr<Node> right_node)
{
    if (variable_collector.exist(name))
    {
        auto variable = variable_collector.get(name);
        auto assigment = std::shared_ptr<AssigmentNode>(new AssigmentNode(assigment_generator,right_node,variable,nullptr));
        return assigment;
    }
    else
    {
        auto variable = std::shared_ptr<VariableNode>(
            new VariableNode(variable_generator,std::move(right_node),name)
            );
        variable_collector.set(name,variable);
        return variable;
    }
}

std::shared_ptr<Node> ASTGenerator::assign(std::shared_ptr<AccessNode> left,std::shared_ptr<Node> right)
{
    auto assigment = std::shared_ptr<AssigmentNode>(new AssigmentNode(assigment_generator,right,nullptr,left));
    return assigment;
}
    

std::shared_ptr<Node> ASTGenerator::get_named_value(std::string name)
{
    if (variable_collector.exist(name))
    {
        auto o = variable_collector.get(name);
        return variable_collector.get(name);
    }
    else
    {
        if (argument_collector.exist(name))
        {
            return argument_collector.get(name);
        }
        std::cout << "Error: variable '" << name << "' is not declared.\n";
        exit(0);
    }
}

void ASTGenerator::add_argument(std::string arg_name)
{
    auto argument = std::shared_ptr<ArgumentNode>(new ArgumentNode(argument_generator,arg_name));
    argument_collector.set(arg_name,argument);
}

void ASTGenerator::book_function(std::string name)
{
}

std::shared_ptr<FunctionNode> ASTGenerator::add_function(std::string name,std::vector<std::string> arguments,std::vector<std::shared_ptr<Node>> body,std::shared_ptr<Node> return_value)
{
    auto func = std::shared_ptr<FunctionNode>(new FunctionNode(
        function_generator,name,arguments,std::move(body),std::move(return_value))
        );
    std::vector<std::string> previous_namespace = function_collector.get_namespace();
    previous_namespace.pop_back();
    function_collector.set(name,func,previous_namespace);
    func->set_self_namespace(function_collector.get_namespace());
    return func;
}

std::shared_ptr<ClassNode> ASTGenerator::add_class(std::string name,std::vector<std::string> arguments,std::vector<std::shared_ptr<Node>> members_definition,std::vector<std::shared_ptr<Node>> body)
{
    auto class_ = std::shared_ptr<ClassNode>(
        new ClassNode(
        class_generator,
        body,
        members_definition,
        arguments,
        name)
        );
    std::vector<std::string> previous_namespace = class_collector.get_namespace();
    previous_namespace.pop_back();
    class_->set_self_namespace(class_collector.get_namespace());
    class_collector.set(name,class_,previous_namespace);
    return class_;
}

std::unique_ptr<Node> ASTGenerator::create_call(std::string name,std::vector<std::shared_ptr<Node>> arguments)
{
    if (function_collector.exist(name))
    {
        auto function = function_collector.get(name);
        auto calling = std::unique_ptr<CallFunctionNode>(
            new CallFunctionNode(
                calling_generator,function,arguments,argument_collector
                )
            );
        return std::move(calling);
    }
    
    if (class_collector.exist(name))
    {
        auto class_ = class_collector.get(name);
        auto constructor = std::unique_ptr<CallConstructorNode>(
            new CallConstructorNode(
                call_constructor_generator,
                class_,
                arguments,
                argument_collector
            ));
        return std::move(constructor);
    }
    else
    {
        std::cout << "Error: function or class '" << name << "' is not defined." << std::endl;
        exit(0);
    }
}
std::unique_ptr<IntegerNode> ASTGenerator::create_integer(int num)
{
    auto Integer = std::unique_ptr<IntegerNode>(new IntegerNode(int_ir_generator));
    Integer->int_num = num;
    return std::move(Integer);
}

std::unique_ptr<FloatNode> ASTGenerator::create_float(double num)
{
    auto float_ = std::unique_ptr<FloatNode>(new FloatNode(float_ir_generator));
    float_->float_num = num;
    return std::move(float_);
}

std::unique_ptr<BinaryExpressionNode> ASTGenerator::attach_operator(std::shared_ptr<Node> left_node,std::shared_ptr<Node> right_node,const std::string operator_kind)
{
    auto expression = std::unique_ptr<BinaryExpressionNode>(new BinaryExpressionNode(binary_expression_generator));
    expression->left_node = std::move(left_node);
    expression->right_node = std::move(right_node);
    expression->operator_kind = operator_kind;
    return std::move(expression);
}

std::shared_ptr<Node> ASTGenerator::create_if(std::shared_ptr<Node> conditions,std::vector<std::shared_ptr<Node>> body)
{
    std::vector<std::shared_ptr<Node>> empty;
    auto if_node = std::shared_ptr<IfNode>(
        new IfNode(
            if_generator,
            conditions,
            body,
            empty
        ));
    if_collector.set(if_collector.get_unique_name(),if_node);
    return if_node;
}

std::shared_ptr<Node> ASTGenerator::add_else(std::vector<std::shared_ptr<Node>> body)
{
    auto if_node = if_collector.get_previous();
    if_node->set_else_body(body);
    auto res = std::make_shared<Node>(ir_generator);
    return res;
}  

std::shared_ptr<AccessNode> ASTGenerator::create_access(std::string left,std::string right)
{
    auto left_node = get_named_value(left);
    auto accessing = std::shared_ptr<AccessNode>(
        new AccessNode(
            access_generator,
            left_node,
            right
        ));
    return accessing;
}

std::shared_ptr<AccessNode> ASTGenerator::create_access(std::shared_ptr<Node> left,std::string right)
{
    auto accessing = std::shared_ptr<AccessNode>(
        new AccessNode(
            access_generator,
            left,
            right
        ));
    return accessing;
}