#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Support/raw_ostream.h>
#include "../builtins/type.hpp"
#include "../ast/node.hpp"
#include "../ir_generator/ir_generator.hpp"
#include "ast_generator.hpp"


ASTGenerator::~ASTGenerator() {}

ASTGenerator::ASTGenerator(
    llvm::Module &module,
    llvm::IRBuilder<> &ir_builder,
    llvm::LLVMContext &context
    )
:module(module),ir_builder(ir_builder),context(context),current_namespace({"__TOP"})
{
    ir_generator = std::shared_ptr<IRGenerator>(new IRGenerator(context,module,ir_builder));
    int_ir_generator = std::shared_ptr<IntergerIRGenerator>(new IntergerIRGenerator(context,module,ir_builder));
    float_ir_generator = std::shared_ptr<FloatIRGenerator>(new FloatIRGenerator(context,module,ir_builder));
    variable_generator = std::shared_ptr<VariableIRGenerator>(new VariableIRGenerator(context,module,ir_builder));
    binary_expression_generator = std::shared_ptr<BinaryExpressionIRGenerator>(new BinaryExpressionIRGenerator(context,module,ir_builder));
    function_generator = std::shared_ptr<FunctionIRGenerator>(new FunctionIRGenerator(context,module,ir_builder));
    calling_generator = std::shared_ptr<CallFunctionIRGenerator>(new CallFunctionIRGenerator(context,module,ir_builder));
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
    std::map<std::string,llvm::Value*> vals;
    variables[current_namespace] = vals;
}

void ASTGenerator::break_out_of_namespace()
{
    if (!current_namespace.empty())
    {
    current_namespace.pop_back();
    }
}

std::unique_ptr<VariableNode> ASTGenerator::add_variable(std::string name,std::unique_ptr<Node> right_value)
{
    auto value = right_value->generate();
    auto variable = std::unique_ptr<VariableNode>(
        new VariableNode(*variable_generator,value)
        );
    variables[current_namespace][name] = variable->generate();
  //  std::cout << "registering new variable '" << name 
  //  << "' that typed "<< variable->get_type()->type_name <<" in " 
  //  << "namespace '" << cur << "'\n";
    return std::move(variable);

}

std::unique_ptr<VariableNode> ASTGenerator::get_variable(std::string name)
{
    if (variables[current_namespace].count(name))
    {
        auto variable = std::unique_ptr<VariableNode>(
        new VariableNode(*variable_generator,variables[current_namespace][name])
        );
        return std::move(variable);
    }
    else
    {
        std::cout << "Error: variable '" << name << "' is not declared.\n";
        exit(0);
    }
}

void ASTGenerator::add_argument(std::string arg)
{
    variables[current_namespace][arg] = nullptr;
}

void ASTGenerator::book_function(std::string name,std::vector<std::string> arguments,std::vector<std::unique_ptr<Node>> body,std::unique_ptr<Node> return_value)
{
    std::cout << "booking func." << std::endl;
    auto func = std::shared_ptr<FunctionNode>(new FunctionNode(
        *function_generator,name,arguments,std::move(body),std::move(return_value))
        );
    std::vector<std::string> previous_namespace;
    std::copy(current_namespace.begin(),current_namespace.end()-1,
    std::back_inserter(previous_namespace));
    functions[previous_namespace][name] = func;
    std::copy(current_namespace.begin(),current_namespace.end()-1,
    std::back_inserter(func->self_namespace));
    func->generate();
}

std::unique_ptr<Node> ASTGenerator::call_function(std::string name,std::vector<std::unique_ptr<Node>> arguments)
{
    if (functions[current_namespace].count(name))
    {
        auto function = &functions[current_namespace][name];
        auto calling = std::unique_ptr<CallFunctionNode>(
            new CallFunctionNode(
                *calling_generator,*function,
                std::move(arguments),
                variables)
            );
        calling->generate();
        return std::move(calling);
    }
    else
    {
        std::cout << "Error: function " << name << " is not defined." << std::endl;
        exit(0);
    }
}
std::unique_ptr<IntergerNode> ASTGenerator::create_interger(int num)
{
    auto interger = std::unique_ptr<IntergerNode>(new IntergerNode(*int_ir_generator));
    interger->int_num = num;
    return std::move(interger);
}

std::unique_ptr<FloatNode> ASTGenerator::create_float(double num)
{
    auto float_ = std::unique_ptr<FloatNode>(new FloatNode(*float_ir_generator));
    float_->float_num = num;
    return std::move(float_);
}

std::unique_ptr<BinaryExpressionNode> ASTGenerator::attach_operator(std::unique_ptr<Node> left_node,std::unique_ptr<Node> right_node,const std::string operator_kind)
{
    auto expression = std::unique_ptr<BinaryExpressionNode>(new BinaryExpressionNode(*binary_expression_generator));
    expression->left_node = std::move(left_node);
    expression->right_node = std::move(right_node);
    expression->operator_kind = operator_kind;
    //auto value = expression->generate();
    return std::move(expression);
    /*try
    {
        auto special_method = node->special_methods.at(operator_type);
        std::vector<std::unique_ptr<Node>> arg;
        arg.push_back(other);   
        auto res = std::unique_ptr<Node>(new CallFunctionNode(*special_method,arg));
        return res;
    }
    catch (std::out_of_range)
    {
        return node; 
    }*/
}

std::string ASTGenerator::get_namespace_as_string()
{
    std::string cur = ".";
    for (auto &i:current_namespace)
    {
        cur += "/" + i;
    }
    return cur;
}