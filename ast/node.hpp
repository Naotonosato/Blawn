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
    virtual bool is_argument(){return false;}
    virtual bool is_function(){return false;}
    virtual llvm::Value* generate();
    virtual void initialize(){}
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
    bool _is_generated;
    public:
    std::shared_ptr<Node> right_node;
    llvm::AllocaInst* alloca_inst;
    std::map<std::shared_ptr<Node>,llvm::Value*> generated_right_values;
    VariableNode(
        VariableIRGenerator& ir_generator,
        std::shared_ptr<Node> right_node,
        std::string name=""
        )
    :Node(ir_generator,name),_is_generated(false),right_node(right_node),
    alloca_inst(nullptr){}
    void assign(std::shared_ptr<Node>);
    bool is_generated();
    void generated();
    void initialize() override;
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
    llvm::Function* base_function;
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
    :Node(ir_generator,name),base_function(nullptr),arguments_names(arguments_names),
    body(std::make_move_iterator(body.begin()),std::make_move_iterator(body.end())),
    return_value(std::move(return_value)){}
    bool is_function() override{return true;};
    void register_function(std::vector<llvm::Type*>,llvm::Function*);
    void set_self_namespace(std::vector<std::string>);
    std::vector<std::string> get_self_namespace();
    void set_temporary_function(llvm::Function*);
    llvm::Function* get_temporary_function();
    void set_base_function(llvm::Function*);
    llvm::Function* get_base_function();
    llvm::Function* get_function(std::vector<llvm::Type*>);
    std::vector<llvm::Function*> get_functions();
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


class ClassNode:public Node
{
    private:
        std::vector<std::shared_ptr<Node>> body;
        std::vector<std::shared_ptr<Node>> members_definition;
        llvm::Function* temporary_constructor;
        llvm::Function* base_constructor;
        std::map<std::vector<llvm::Type*>,llvm::Function*> constructors;
        std::vector<std::string> self_namespace;
        std::vector<std::string> arguments_names;
    public:
    ClassNode(
        ClassIRGenerator& ir_generator,
        std::vector<std::shared_ptr<Node>> body,
        std::vector<std::shared_ptr<Node>> members_definition,
        std::vector<std::string> arguments_names,
        std::string name=""
        )
    :Node(ir_generator,name),body(body),
    members_definition(members_definition),
    arguments_names(arguments_names){}
    std::vector<std::string> get_arguments_names(){return arguments_names;}
    std::vector<std::shared_ptr<Node>> get_members_definition(){return members_definition;};
    std::vector<std::shared_ptr<Node>> get_body(){return body;}

    void register_constructor(std::vector<llvm::Type*>,llvm::Function*);
    llvm::Function* get_constructor(std::vector<llvm::Type*>);
    void set_self_namespace(std::vector<std::string> n){self_namespace=n;}
    std::vector<std::string> get_self_namespace(){return self_namespace;}
    void set_temporary_constructor(llvm::Function* c){temporary_constructor=c;}
    llvm::Function* get_temporary_constructor(){return temporary_constructor;}
};

class CallConstructorNode:public Node
{
    private:
    std::shared_ptr<ClassNode> class_node;
    std::vector<std::shared_ptr<Node>> passed_arguments;
    public:
    NodeCollector<ArgumentNode>& argument_collector;
    CallConstructorNode(
        CallConstructorIRGenerator& ir_generator,
        std::shared_ptr<ClassNode> class_node,
        std::vector<std::shared_ptr<Node>> passed_arguments,
        NodeCollector<ArgumentNode>& argument_collector,
        std::string name=""
        )
    :Node(ir_generator,name),class_node(class_node),
    passed_arguments(passed_arguments),argument_collector(argument_collector){}
    std::shared_ptr<ClassNode> get_class(){return class_node;}
    std::vector<std::shared_ptr<Node>> get_passed_arguments(){return passed_arguments;}
};