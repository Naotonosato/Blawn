#pragma once
#include <llvm/IR/IRBuilder.h>
#include "../ir_generator/ir_generator.hpp"
#include <string>
#include <memory>
#include <map>
#include <vector>

//------forward declaration------
class Type;
/*
class IRGenerator;
class IntergerIRGenerator;
class FloatIRGenerator;
class VariableIRGenerator;
class BinaryExpressionIRGenerator;
*/
namespace llvm
{
    class Value;
    class Type;
}
//------forward declaration------


class Node
{
public:  
    int int_num;
    double float_num;
    std::string string;
    IRGenerator& ir_generator;
    Node(IRGenerator& ir_generator)
    :ir_generator(ir_generator){}
    virtual llvm::Value* generate();
};

class IntergerNode:public Node
{
    public:
    IntergerNode(
        IntergerIRGenerator& ir_generator
        ):Node(ir_generator){}
};

class FloatNode:public Node
{
    public:
    FloatNode(
        FloatIRGenerator& ir_generator
        ):Node(ir_generator){}
};

class VariableNode: public Node
{
    public:
    llvm::Value* right_value;
    VariableNode(
        VariableIRGenerator& ir_generator,
        llvm::Value* right_value
        )
    :Node(ir_generator),right_value(right_value){}
    llvm::Value* generate();
};


class BinaryExpressionNode: public Node
{
public:
    std::unique_ptr<Node> left_node;
    std::unique_ptr<Node> right_node;
    std::string operator_kind;
    BinaryExpressionNode(BinaryExpressionIRGenerator& ir_generator)
    :Node(ir_generator){}
    llvm::Value* generate();
};


class FunctionNode: public Node
{
public:
    std::string name;
    std::vector<std::string> arguments;
    std::unique_ptr<Node> return_value;
    std::vector<std::vector<std::unique_ptr<Node>>> arguments_kind;
    std::vector<std::string> self_namespace;
    FunctionNode(
        FunctionIRGenerator& ir_generator,
        std::string name,std::vector<std::string> arguments,
        std::unique_ptr<Node> return_value
        )
    :Node(ir_generator),name(name),arguments(arguments),return_value(std::move(return_value)){}
    void register_type(std::vector<std::unique_ptr<Node>>);
    std::string get_name(std::vector<std::unique_ptr<Node>>);
};


class CallFunctionNode: public Node
{
    public:
        std::shared_ptr<FunctionNode> function;
        std::vector<std::unique_ptr<Node>> arguments;
        std::map<std::vector<std::string>,std::map<std::string,llvm::Value*>>& local_variables;
        CallFunctionNode(
            IRGenerator& ir_generator,
            std::shared_ptr<FunctionNode> function,
            std::vector<std::unique_ptr<Node>> arguments,
            std::map<std::vector<std::string>,std::map<std::string,llvm::Value*>>& local_variables
            )
        :Node(ir_generator),function(function),arguments(
            std::make_move_iterator(arguments.begin()),
            std::make_move_iterator(arguments.begin())
            ),local_variables(local_variables){}
};