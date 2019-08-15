#pragma once
#include <llvm/IR/IRBuilder.h>
#include "../ast_generator/node_collector.hpp"
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
private:
    llvm::Type* type;
    bool _is_argument;
public:  
    int int_num;
    double float_num;
    std::string string;
    IRGenerator& ir_generator;
    std::string name;
    Node(IRGenerator& ir_generator,std::string name="",bool is_argument=false)
    :_is_argument(is_argument),ir_generator(ir_generator),name(name){}
    bool is_argument(){return _is_argument;}
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
    bool is_generated;
    llvm::Value* generated_value;
    std::shared_ptr<Node> right_node;
    llvm::AllocaInst* alloca_inst;
    llvm::StoreInst* store_inst;
    llvm::LoadInst* load_inst;
    std::map<std::shared_ptr<Node>,llvm::Value*> generated_right_values;
    VariableNode(
        VariableIRGenerator& ir_generator,
        std::shared_ptr<Node> right_node,
        std::string name=""
        )
    :Node(ir_generator,name),is_generated(false),right_node(right_node),
    alloca_inst(nullptr),store_inst(nullptr),load_inst(nullptr){}
    void assign(std::shared_ptr<Node>);
};

class AssigmentNode:public Node
{
    private:
    std::shared_ptr<VariableNode> target;
    std::shared_ptr<Node> right_node;
    public:
    AssigmentNode(
        AssigmentIRGenerator& ir_generator,
        std::shared_ptr<VariableNode> target,
        std::shared_ptr<Node> right_node,
        std::string name=""
        )
    :Node(ir_generator,name),target(target),right_node(right_node){}
    std::shared_ptr<VariableNode> get_target() const;
    std::shared_ptr<Node> get_right_node() const;
};

class ArgumentNode: public Node
{
private:
    llvm::Value* right_value;
public:
    ArgumentNode(
        ArgumentIRGenerator& ir_generator,
        std::string name=""
        )
    :Node(ir_generator,name,true){}
    void set_right_value(llvm::Value*);
    llvm::Value* get_right_value();
};

class BinaryExpressionNode: public Node
{
public:
    std::shared_ptr<Node> left_node;
    std::shared_ptr<Node> right_node;
    std::string operator_kind;
    BinaryExpressionNode(BinaryExpressionIRGenerator& ir_generator)
    :Node(ir_generator){}
};


class FunctionNode: public Node
{
private:
    llvm::Function* temporary_function;
    std::map<std::vector<llvm::Type*>,llvm::Function*> functions;
    std::vector<std::string> self_namespace;
public:
    std::vector<std::string> arguments_names;
    std::vector<std::shared_ptr<Node>> body;
    std::shared_ptr<Node> return_value;
    FunctionNode(
        FunctionIRGenerator& ir_generator,
        std::string name,std::vector<std::string> arguments_names,
        std::vector<std::shared_ptr<Node>> body,
        std::shared_ptr<Node> return_value
        )
    :Node(ir_generator,name),arguments_names(arguments_names),
    body(std::make_move_iterator(body.begin()),std::make_move_iterator(body.end())),
    return_value(std::move(return_value)){}
    void register_function(std::vector<llvm::Type*>,llvm::Function*);
    void set_self_namespace(std::vector<std::string>);
    std::vector<std::string> get_self_namespace();
    void set_temporary_function(llvm::Function*);
    llvm::Function* get_temporary_function();
    llvm::Function* get_function(std::vector<llvm::Type*>);
};


class CallFunctionNode: public Node
{
    public:
        std::shared_ptr<FunctionNode> function;
        std::vector<std::shared_ptr<Node>> passed_arguments;
        NodeCollector<ArgumentNode>& argument_collector;
        CallFunctionNode(
            CallFunctionIRGenerator& ir_generator,
            std::shared_ptr<FunctionNode> function,
            std::vector<std::shared_ptr<Node>> passed_arguments,
            NodeCollector<ArgumentNode>& argument_collector
            )
        :Node(ir_generator),function(function),passed_arguments(
            std::make_move_iterator(passed_arguments.begin()),
            std::make_move_iterator(passed_arguments.end())
            ),argument_collector(argument_collector){}
};