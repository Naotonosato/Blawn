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
private:
    std::shared_ptr<Type> type;
public:  
    int int_num;
    double float_num;
    std::string string;
    const IRGenerator& ir_generator;
    Node(const IRGenerator& ir_generator)
    :ir_generator(ir_generator){}
    virtual llvm::Value* generate();
};

class IntergerNode:public Node
{
    public:
    IntergerNode(
        const IntergerIRGenerator& ir_generator
        ):Node(ir_generator){}
};

class FloatNode:public Node
{
    public:
    FloatNode(
        const FloatIRGenerator& ir_generator
        ):Node(ir_generator){}
};

class VariableNode: public Node
{
    public:
    llvm::Value* right_value;
    VariableNode(
        const VariableIRGenerator& ir_generator,
        llvm::Value* right_value
        )
    :Node(ir_generator),right_value(right_value){}
    llvm::Value* generate();
};


class BinaryExpressionNode: public Node
{
public:
    std::shared_ptr<Node> left_node;
    std::shared_ptr<Node> right_node;
    std::string operator_kind;
    BinaryExpressionNode(const BinaryExpressionIRGenerator& ir_generator)
    :Node(ir_generator){}
    llvm::Value* generate();
};


class FunctionNode: public Node
{
public:
    std::vector<std::string> arguments;
    std::vector<std::vector<std::shared_ptr<Node>>> arguments_kind;
    FunctionNode(IRGenerator& ir_generator,std::vector<std::string> arguments)
    :Node(ir_generator),arguments(arguments){}
    void register_type(std::vector<std::shared_ptr<Node>>);
};


class CallFunctionNode: public Node
{
    public:
        std::shared_ptr<Node> function;
        std::vector<std::shared_ptr<Node>> arguments;
        CallFunctionNode(
            IRGenerator& ir_generator,
            std::shared_ptr<FunctionNode> function,
            std::vector<std::shared_ptr<Node>> arguments
            )
        :Node(ir_generator),function(function),arguments(arguments){}
};