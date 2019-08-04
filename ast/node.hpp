#pragma once
#include <string>
#include <memory>
#include <map>
#include <vector>

//------forward declaration------
class Type;
class IRGenerator;
namespace llvm
{
    class Value;
    class Type;
}
//------forward declaration------


class Node
{
private:
    std::shared_ptr<Type> type;
public:  
    std::shared_ptr<Node> left_node;
    std::shared_ptr<Node> right_node;
    std::string operator_kind;
    int int_num;
    double float_num;
    std::string string;
    std::shared_ptr<IRGenerator> ir_generator;
    Node(std::shared_ptr<IRGenerator> ir_generator)
    :ir_generator(ir_generator){}
    llvm::Value* generate();

};


class BinaryExpressionNode: public Node
{
public:
    BinaryExpressionNode(std::shared_ptr<IRGenerator> ir_generator)
    :Node(ir_generator){}
};


class FunctionNode: public Node
{
public:
    std::vector<std::string> arguments;
    std::vector<std::vector<std::shared_ptr<Node>>> arguments_kind;
    FunctionNode(std::shared_ptr<IRGenerator> ir_generator,std::vector<std::string> arguments)
    :Node(ir_generator),arguments(arguments){}
    void register_type(std::vector<std::shared_ptr<Node>>);
};


class CallFunctionNode: public Node
{
    public:
        std::shared_ptr<Node> function;
        std::vector<std::shared_ptr<Node>> arguments;
        CallFunctionNode(
            std::shared_ptr<IRGenerator> ir_generator,
            std::shared_ptr<FunctionNode> function,
            std::vector<std::shared_ptr<Node>> arguments
            )
        :Node(ir_generator),function(function),arguments(arguments){}
};