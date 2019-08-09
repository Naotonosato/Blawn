#pragma once
#include <llvm/IR/IRBuilder.h>
#include "../ir_generator/ir_generator.hpp"
#include <string>
#include <memory>
#include <map>
#include <vector>
#include <set>

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
    class Function;
    class FunctionType;
    class Argument;
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
    private:
    llvm::Value* right_value;
    bool is_null_parent;
    public:
    std::shared_ptr<Node> right_node;
    VariableNode(
        VariableIRGenerator& ir_generator,
        std::shared_ptr<Node> right_node
        )
    :Node(ir_generator),right_node(right_node){}
    void set_right_value(llvm::Argument*);
    llvm::Value* get_right_value();
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
private:
    std::map<std::vector<llvm::Type*>,llvm::Function*> functions;
public:
    std::string name;
    std::vector<std::string> arguments;
    std::vector<std::unique_ptr<Node>> body;
    std::unique_ptr<Node> return_value;
    std::vector<std::string> self_namespace;
    FunctionNode(
        FunctionIRGenerator& ir_generator,
        std::string name,std::vector<std::string> arguments,
        std::vector<std::unique_ptr<Node>> body,
        std::unique_ptr<Node> return_value
        )
    :Node(ir_generator),name(name),arguments(arguments),
    body(std::make_move_iterator(body.begin()),std::make_move_iterator(body.end())),
    return_value(std::move(return_value)){}
    void register_function(std::vector<llvm::Type*>,llvm::Function*);
    llvm::Function* get_function(std::vector<llvm::Type*>);
    llvm::Function* generate();
};


class CallFunctionNode: public Node
{
    public:
        std::shared_ptr<FunctionNode> function;
        std::vector<std::unique_ptr<Node>> arguments;
        std::map<
        std::vector<std::string>,
        std::map<std::string,std::shared_ptr<VariableNode>>
        > & local_variables;
        CallFunctionNode(
            CallFunctionIRGenerator& ir_generator,
            std::shared_ptr<FunctionNode> function,
            std::vector<std::unique_ptr<Node>> arguments,
            std::map<
            std::vector<std::string>,
            std::map<std::string,std::shared_ptr<VariableNode>>
            >& local_variables
            )
        :Node(ir_generator),function(function),arguments(
            std::make_move_iterator(arguments.begin()),
            std::make_move_iterator(arguments.end())
            ),local_variables(local_variables){}
        llvm::Value* generate();
};