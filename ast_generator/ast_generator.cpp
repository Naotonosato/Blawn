#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Support/raw_ostream.h>
#include "node_collector.hpp"
#include "../ast/node.hpp"
#include "../ir_generator/ir_generator.hpp"
#include "ast_generator.hpp"


ASTGenerator::~ASTGenerator() {}

ASTGenerator::ASTGenerator(
    llvm::Module &module,
    llvm::IRBuilder<> &ir_builder,
    llvm::LLVMContext &context
    )
:module(module),ir_builder(ir_builder),context(context)
{
    variable_collector = std::shared_ptr<NodeCollector<VariableNode>>(new NodeCollector<VariableNode>("TOP"));
    function_collector = std::shared_ptr<NodeCollector<FunctionNode>>(new NodeCollector<FunctionNode>("TOP"));
    argument_collector = std::shared_ptr<NodeCollector<ArgumentNode>>(new NodeCollector<ArgumentNode>("TOP")); 
    
    ir_generator = std::shared_ptr<IRGenerator>(new IRGenerator(context,module,ir_builder));
    int_ir_generator = std::shared_ptr<IntergerIRGenerator>(new IntergerIRGenerator(context,module,ir_builder));
    float_ir_generator = std::shared_ptr<FloatIRGenerator>(new FloatIRGenerator(context,module,ir_builder));
    variable_generator = std::shared_ptr<VariableIRGenerator>(new VariableIRGenerator(context,module,ir_builder));
    argument_generator = std::shared_ptr<ArgumentIRGenerator>(new ArgumentIRGenerator(context,module,ir_builder));
    assigment_generator = std::shared_ptr<AssigmentIRGenerator>(new AssigmentIRGenerator(context,module,ir_builder));
    binary_expression_generator = std::shared_ptr<BinaryExpressionIRGenerator>(new BinaryExpressionIRGenerator(context,module,ir_builder));
    function_generator = std::shared_ptr<FunctionIRGenerator>(new FunctionIRGenerator(context,module,ir_builder));
    calling_generator = std::shared_ptr<CallFunctionIRGenerator>(new CallFunctionIRGenerator(context,module,ir_builder));
}

void ASTGenerator::generate()
{}


void ASTGenerator::into_namespace(std::string name)
{
    variable_collector->into_namespace(name);
    function_collector->into_namespace(name);
    variable_collector->into_namespace(name);
}

void ASTGenerator::break_out_of_namespace()
{
    variable_collector->break_out_of_namespace();
    function_collector->break_out_of_namespace();
    variable_collector->break_out_of_namespace();
}

std::shared_ptr<Node> ASTGenerator::assign(std::string name,std::shared_ptr<Node> right_node)
{
    if (variable_collector->exist(name))
    {
        /*std::cout << "assign " << name << std::endl;
        right_node->generate()->print(llvm::outs());
        std::cout << std::endl;
        */
        auto variable = variable_collector->get(name);
        //variable->assign(right_node);
        auto assigment = std::shared_ptr<AssigmentNode>(new AssigmentNode(*assigment_generator,variable,right_node));
        return assigment;
    }
    else
    {
        auto variable = std::shared_ptr<VariableNode>(
            new VariableNode(*variable_generator,std::move(right_node),name)
            );
        variable_collector->set(name,variable);
        //  std::cout << "registering new variable '" << name 
        //  << "' that typed "<< variable->get_type()->type_name <<" in " 
        //  << "namespace '" << cur << "'\n";
        return variable;
    }
}

std::shared_ptr<Node> ASTGenerator::get_named_value(std::string name)
{
    if (variable_collector->exist(name))
    {
        auto o = variable_collector->get(name);
        //o->generate();
        //auto right_node = std::shared_ptr<Node>(new Node(*o->right_node));
        //auto copy = std::shared_ptr<VariableNode>(new VariableNode(*variable_generator,right_node));
        //variable_collector->set(name,copy);
        return variable_collector->get(name);
    }
    else
    {
        if (argument_collector->exist(name))
        {
            return argument_collector->get(name);
        }
        std::cout << "Error: variable '" << name << "' is not declared.\n";
        exit(0);
    }
}

void ASTGenerator::add_argument(std::string arg_name)
{
    auto argument = std::shared_ptr<ArgumentNode>(new ArgumentNode(*argument_generator,arg_name));
    argument_collector->set(arg_name,argument);
}

std::shared_ptr<FunctionNode> ASTGenerator::book_function(std::string name,std::vector<std::string> arguments,std::vector<std::shared_ptr<Node>> body,std::shared_ptr<Node> return_value)
{
    auto func = std::shared_ptr<FunctionNode>(new FunctionNode(
        *function_generator,name,arguments,std::move(body),std::move(return_value))
        );
    std::vector<std::string> previous_namespace = function_collector->get_namespace();
    previous_namespace.pop_back();
    function_collector->set(name,func,previous_namespace);
    func->set_self_namespace(function_collector->get_namespace());
    return func;
}

std::unique_ptr<Node> ASTGenerator::call_function(std::string name,std::vector<std::shared_ptr<Node>> arguments)
{
    if (function_collector->exist(name))
    {
        auto function = function_collector->get(name);
        auto calling = std::unique_ptr<CallFunctionNode>(
            new CallFunctionNode(
                *calling_generator,function,arguments,*argument_collector
                )
            );
        /*auto copy = *calling;
        auto copy2 = std::shared_ptr<CallFunctionNode>(new CallFunctionNode(copy));
        top_exprs.push_back(copy2);
        */
        //calling->generate();
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

std::unique_ptr<BinaryExpressionNode> ASTGenerator::attach_operator(std::shared_ptr<Node> left_node,std::shared_ptr<Node> right_node,const std::string operator_kind)
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