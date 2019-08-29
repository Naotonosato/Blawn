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
class IntegerIRGenerator;
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
    virtual bool is_calling_constructor(){return false;}
    virtual llvm::Value* generate();
    virtual void initialize(){}
};

class IntegerNode:public Node
{
    public:
    IntegerNode(
        IntegerIRGenerator& ir_generator
        ):Node(ir_generator){}
};


class FloatNode:public Node
{
    public:
    FloatNode(
        FloatIRGenerator& ir_generator
        ):Node(ir_generator){}
};


class StringNode:public Node
{
    public:
    StringNode(
        StringIRGenerator& ir_generator
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


class AccessNode:public Node
{
    private:
    std::shared_ptr<Node> left_node;
    llvm::Value* left_value;
    std::string right_name;
    llvm::Value* pointer;

    llvm::Value* generated;
    bool _is_generated;

    NodeCollector<FunctionNode>& function_collector;
    std::shared_ptr<CallFunctionNode> call_node;

    public:
    AccessNode(
        AccessIRGenerator& ir_generator,
        std::shared_ptr<Node> left_node,
        std::string right_name,
        NodeCollector<FunctionNode>& function_collector
        ):Node(ir_generator),left_node(left_node),left_value(nullptr),
        right_name(right_name),pointer(nullptr),generated(nullptr),
        function_collector(function_collector){}
    llvm::Value* get_left_value();
    std::shared_ptr<Node> get_left_node(){return left_node;}
    std::string get_right_name(){return right_name;}
    void set_pointer(llvm::Value* p){pointer = p;}
    std::string get_left_typename();
    llvm::Value* get_pointer(){return pointer;}
    void set_call_node(std::shared_ptr<CallFunctionNode> n){call_node=n;}
    std::shared_ptr<CallFunctionNode> get_call_node(){return call_node;}
    void set_generated(llvm::Value* c){generated = c;}
    llvm::Value* get_generated(){return generated;}

};


class AssigmentNode:public Node
{
    private:
    std::shared_ptr<Node> right_node;
    std::shared_ptr<VariableNode> target_var;
    std::shared_ptr<AccessNode> target_member;
    public:
    AssigmentNode(
        AssigmentIRGenerator& ir_generator,
        std::shared_ptr<Node> right_node,
        std::shared_ptr<VariableNode> target_var=nullptr,
        std::shared_ptr<AccessNode> target_member=nullptr,
        std::string name=""
        )
    :Node(ir_generator,name),right_node(right_node),
    target_var(target_var),target_member(target_member){}
    std::shared_ptr<VariableNode> get_target_var() const;
    std::shared_ptr<AccessNode> get_target_member() const;
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
    std::vector<llvm::Function*> base_functions;
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
    bool is_function() override{return true;};
    void register_function(std::vector<llvm::Type*>,llvm::Function*);
    void set_self_namespace(std::vector<std::string>);
    std::vector<std::string> get_self_namespace();
    void set_temporary_function(llvm::Function*);
    llvm::Function* get_temporary_function();
    void set_base_function(llvm::Function*);
    std::vector<llvm::Function*> get_base_functions();
    llvm::Function* get_function(std::vector<llvm::Type*>);
    std::vector<llvm::Function*> get_functions();
};


class CallFunctionNode: public Node
{
    public:
        std::shared_ptr<FunctionNode> function;
        std::vector<std::shared_ptr<Node>> passed_arguments;
        NodeCollector<ArgumentNode>& argument_collector;
        bool is_builtin;
        llvm::Function* builtin_function;
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
        CallFunctionNode(
            CallFunctionIRGenerator& ir_generator,
            std::vector<std::shared_ptr<Node>> passed_arguments,
            NodeCollector<ArgumentNode>& argument_collector,
            llvm::Function* builtin_function
            ):Node(ir_generator),
            passed_arguments(
            std::make_move_iterator(passed_arguments.begin()),
            std::make_move_iterator(passed_arguments.end())
            ),argument_collector(argument_collector),
            is_builtin(true),builtin_function(builtin_function){}
};


class ClassNode:public Node
{
    private:
        std::vector<std::shared_ptr<FunctionNode>> methods;
        std::vector<std::shared_ptr<Node>> members_definition;
        llvm::Function* temporary_constructor;
        std::vector<llvm::Function*> base_constructors;
        std::map<std::vector<llvm::Type*>,llvm::Function*> constructors;
        std::map<std::vector<llvm::Type*>,llvm::Function*> destructors;
        std::vector<std::string> self_namespace;
        std::vector<std::string> arguments_names;
    public:
    ClassNode(
        ClassIRGenerator& ir_generator,
        std::vector<std::shared_ptr<FunctionNode>> methods,
        std::vector<std::shared_ptr<Node>> members_definition,
        std::vector<std::string> arguments_names,
        std::string name=""
        )
    :Node(ir_generator,name),methods(methods),
    members_definition(members_definition),
    arguments_names(arguments_names){}
    std::vector<std::string> get_arguments_names(){return arguments_names;}
    std::vector<std::shared_ptr<Node>> get_members_definition(){return members_definition;};
    std::vector<std::shared_ptr<FunctionNode>> get_methods(){return methods;}

    void register_constructor(std::vector<llvm::Type*>,llvm::Function*);
    llvm::Function* get_constructor(std::vector<llvm::Type*>);
    void register_destructor(std::vector<llvm::Type*>,llvm::Function*);
    llvm::Function* get_destructor(std::vector<llvm::Type*>);
    void set_self_namespace(std::vector<std::string> n){self_namespace=n;}
    std::vector<std::string> get_self_namespace(){return self_namespace;}
    void set_temporary_constructor(llvm::Function* c){temporary_constructor=c;}
    llvm::Function* get_temporary_constructor(){return temporary_constructor;}
    void set_base_constructor(llvm::Function* base){base_constructors.push_back(base);}
    std::vector<llvm::Function*> get_base_constructors(){return base_constructors;}
};

class CallConstructorNode:public Node
{
    private:
    std::shared_ptr<ClassNode> class_node;
    std::vector<std::shared_ptr<Node>> passed_arguments;
    std::pair<llvm::Function*,llvm::Value*> destructor;
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
    void set_destructor(llvm::Function* destructor_,llvm::Value* instance){destructor = std::make_pair(destructor_,instance);}
    std::pair<llvm::Function*,llvm::Value*> get_destructor(){return destructor;}
    bool is_calling_constructor() override{return true;}
};


class IfNode: public Node
{
    private:
    std::shared_ptr<Node> conditions;
    std::vector<std::shared_ptr<Node>> if_body;
    std::vector<std::shared_ptr<Node>> else_body;
    public:
    IfNode(
        IfIRGenerator& ir_generator,
        std::shared_ptr<Node> conditions,
        std::vector<std::shared_ptr<Node>> if_body,
        std::vector<std::shared_ptr<Node>> else_body
        )
    :Node(ir_generator),conditions(conditions),
    if_body(if_body),else_body(else_body){}
    std::shared_ptr<Node> get_conditions(){return conditions;}
    std::vector<std::shared_ptr<Node>> get_if_body(){return if_body;}
    std::vector<std::shared_ptr<Node>> get_else_body(){return else_body;}
    void set_else_body(std::vector<std::shared_ptr<Node>> body){else_body = body;}
};

class ForNode: public Node
{
    private:
    std::shared_ptr<Node> left_expression;
    std::shared_ptr<Node> center_expression;
    std::shared_ptr<Node> right_expression;
    std::vector<std::shared_ptr<Node>> body;
    public:
    ForNode(
        ForIRGenerator& ir_generator,
        std::shared_ptr<Node> left_expression,
        std::shared_ptr<Node> center_expression,
        std::shared_ptr<Node> right_expression,
        std::vector<std::shared_ptr<Node>> body
        )
    :Node(ir_generator),left_expression(right_expression),
    center_expression(center_expression),
    right_expression(right_expression),body(body){}
    std::shared_ptr<Node> get_left_expression(){return left_expression;}
    std::shared_ptr<Node> get_center_expression(){return center_expression;}
    std::shared_ptr<Node> get_right_expression(){return right_expression;}
    std::vector<std::shared_ptr<Node>>& get_body(){return body;}
};

class ListNode:public Node
{
    private:
    std::vector<std::shared_ptr<Node>> elements;
    public:
    ListNode(
        ForIRGenerator& ir_generator,
        std::vector<std::shared_ptr<Node>> elements
        ):Node(ir_generator){}
};