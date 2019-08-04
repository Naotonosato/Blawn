#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/LLVMContext.h>
#include "../builtins/type.hpp"
#include "../ast/node.hpp"
#include "../ir_generator/ir_generator.hpp"
#include "ast_generator.hpp"


ASTGenerator::~ASTGenerator() {}

ASTGenerator::ASTGenerator(
    std::shared_ptr<llvm::Module> module,
    std::shared_ptr<llvm::IRBuilder<>> ir_builder,
    std::shared_ptr<llvm::LLVMContext> context
    )
:module(module),ir_builder(ir_builder),context(context),current_namespace({"__TOP"})
{
    ir_generator = std::shared_ptr<IRGenerator>(new IRGenerator(context,module,ir_builder));
    int_ir_generator = std::shared_ptr<IntergerIRGenerator>(new IntergerIRGenerator(context,module,ir_builder));
    float_ir_generator = std::shared_ptr<FloatIRGenerator>(new FloatIRGenerator(context,module,ir_builder));
    binary_expression_generator = std::shared_ptr<BinaryExpressionIRGenerator>(new BinaryExpressionIRGenerator(context,module,ir_builder));
}

void ASTGenerator::generate()
{
/*
    for (int i=0;i<nodes.size();i++)
    {
        //nodes[i]->generate();
    }
*/
}

void ASTGenerator::into_namespace(std::string name)
{
    current_namespace.push_back(name);
    std::map<std::string,std::shared_ptr<Node>> vals;
    variables[current_namespace] = vals;
}

void ASTGenerator::break_out_of_namespace()
{
    if (!current_namespace.empty())
    {
    current_namespace.pop_back();
    }
}

std::shared_ptr<Node> ASTGenerator::add_variable(std::string name,std::shared_ptr<Node> right_value)
{
    std::string cur = ".";
    for (auto &i:current_namespace)
    {
        cur += "/" + i;
    }
    auto variable = std::shared_ptr<Node>(new Node(*right_value));
    variables[current_namespace][name] = variable;
  //  std::cout << "registering new variable '" << name 
  //  << "' that typed "<< variable->get_type()->type_name <<" in " 
  //  << "namespace '" << cur << "'\n";
    return variable;

}

std::shared_ptr<Node> ASTGenerator::get_variable(std::string name)
{
    if (variables[current_namespace].count(name))
    {
        //auto type = variables[current_namespace][name]->type;
        //auto ir_generator = variables[current_namespace][name]->ir_generator;
        //return std::shared_ptr<Node>(new Node(type,ir_generator));
        return variables[current_namespace][name];
    }
    else
    {
        std::cout << "Error: variable '" << name << "' is not declared.\n";
        exit(0);
    }
}

void ASTGenerator::book_function(std::string name,std::vector<std::string> arguments,std::vector<std::shared_ptr<Node>> body)
{
    auto func = std::shared_ptr<FunctionNode>(new FunctionNode(ir_generator,arguments));
    unsolved_functions[current_namespace][name] = func;
    into_namespace(name);
    //for 
}

std::shared_ptr<Node> ASTGenerator::call_function(std::string name,std::vector<std::shared_ptr<Node>> arguments)
{
    if (unsolved_functions[current_namespace].count(name))
    {
        unsolved_functions[current_namespace][name]->register_type(arguments);
        auto calling = std::shared_ptr<CallFunctionNode>(
            new CallFunctionNode(ir_generator,unsolved_functions[current_namespace][name],arguments)
            );
        return calling;
    }
    else
    {
        std::cout << "Error: function " << name << " is not defined." << std::endl;
        exit(0);
    }
}

std::shared_ptr<Node> ASTGenerator::attach_operator(std::shared_ptr<Node> left_node,std::shared_ptr<Node> right_node,const std::string operator_kind)
{
    auto expression = std::shared_ptr<Node>(new Node(binary_expression_generator));
    expression->left_node = left_node;
    expression->right_node = right_node;
    expression->operator_kind = operator_kind;
    //auto value = expression->generate();
    return expression;
    /*try
    {
        auto special_method = node->special_methods.at(operator_type);
        std::vector<std::shared_ptr<Node>> arg;
        arg.push_back(other);   
        auto res = std::shared_ptr<Node>(new CallFunctionNode(special_method,arg));
        return res;
    }
    catch (std::out_of_range)
    {
        return node; 
    }*/
}
