#pragma once
#include <llvm/IR/IRBuilder.h>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>
#include "../ast_generator/node_collector.hpp"
#include "../ir_generator/ir_generator.hpp"

//------forward declaration------
class Type;
class ClassNode;
/*
class IRGenerator;
class IntegerIRGenerator;
class FloatIRGenerator;
class VariableIRGenerator;
class BinaryExpressionIRGenerator;
*/
namespace llvm {
class Value;
class Type;
class Function;
class FunctionType;
class Argument;
}  // namespace llvm
//------forward declaration------

class Node {
private:
    llvm::Type* type;
    bool _is_argument;

public:
    int line_number;
    int int_num;
    double float_num;
    std::string string;
    IRGenerator& ir_generator;
    std::string name;
    Node(int line_number, IRGenerator& ir_generator, std::string name = "",
         bool is_argument = false)
        : _is_argument(is_argument),
          line_number(line_number),
          ir_generator(ir_generator),
          name(name) {}
    virtual llvm::ConstantInt* get_id() { return nullptr; }
    virtual bool is_argument() { return false; }
    virtual bool is_typeid() { return false; }
    virtual bool is_function() { return false; }
    virtual bool is_calling_constructor() { return false; }
    virtual std::shared_ptr<Node> get_typeid_value() { return nullptr; }
    virtual llvm::Value* generate();
    virtual void initialize() {}
};

class SizeofNode : public Node {
private:
    std::shared_ptr<Node> value;

public:
    SizeofNode(int line_number, SizeofGenerator& ir_generator,
               std::shared_ptr<Node> value)
        : Node(line_number, ir_generator), value(value) {}
    std::shared_ptr<Node> get_value() { return value; }
};

class TypeIdNode : public Node {
private:
    std::shared_ptr<Node> value;
    llvm::ConstantInt* id_;

public:
    TypeIdNode(int line_number, TypeIdGenerator& ir_generator,
               std::shared_ptr<Node> value)
        : Node(line_number, ir_generator), value(value), id_(nullptr) {}
    std::shared_ptr<Node> get_value() { return value; }
    void set_id(llvm::ConstantInt* id) { id_ = id; }
    llvm::ConstantInt* get_id() { return id_; }
    bool is_typeid() override { return true; }
    std::shared_ptr<Node> get_typeid_value() override { return value; }
};

class CastNode : public Node {
private:
    std::shared_ptr<Node> id;
    std::shared_ptr<Node> value;

public:
    CastNode(int line_number, CastIRGenerator& ir_generator,
             std::shared_ptr<Node> id, std::shared_ptr<Node> value)
        : Node(line_number, ir_generator), id(id), value(value) {}
    std::shared_ptr<Node> get_idnode() { return id; }
    std::shared_ptr<Node> get_value() { return value; }
};

class NullNode : public Node {
public:
    std::string type_name;
    std::shared_ptr<ClassNode> class_node;
    NullNode(int line_number, NullIRGenerator& ir_generator,
             std::string type_name, std::shared_ptr<ClassNode> class_node)
        : Node(line_number, ir_generator),
          type_name(type_name),
          class_node(class_node) {}
};

class IntegerNode : public Node {
public:
    IntegerNode(int line_number, IntegerIRGenerator& ir_generator)
        : Node(line_number, ir_generator) {}
};

class FloatNode : public Node {
public:
    FloatNode(int line_number, FloatIRGenerator& ir_generator)
        : Node(line_number, ir_generator) {}
};

class StringNode : public Node {
public:
    StringNode(int line_number, StringIRGenerator& ir_generator)
        : Node(line_number, ir_generator) {}
};

class VariableNode : public Node {
private:
    bool _is_generated;
    bool _is_global;

public:
    std::shared_ptr<Node> right_node;
    llvm::AllocaInst* alloca_inst;
    llvm::GlobalVariable* global_ptr;
    std::map<std::shared_ptr<Node>, llvm::Value*> generated_right_values;
    VariableNode(int line_number, VariableIRGenerator& ir_generator,
                 bool is_global, std::shared_ptr<Node> right_node,
                 std::string name = "")
        : Node(line_number, ir_generator, name),
          _is_generated(false),
          _is_global(is_global),
          right_node(right_node),
          alloca_inst(nullptr) {}
    void assign(std::shared_ptr<Node>);
    bool is_generated();
    bool is_global() { return _is_global; }
    void generated();
    void initialize() override;
};

class AccessNode : public Node {
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
    AccessNode(int line_number, AccessIRGenerator& ir_generator,
               std::shared_ptr<Node> left_node, std::string right_name,
               NodeCollector<FunctionNode>& function_collector)
        : Node(line_number, ir_generator),
          left_node(left_node),
          left_value(nullptr),
          right_name(right_name),
          pointer(nullptr),
          generated(nullptr),
          function_collector(function_collector) {}
    llvm::Value* get_left_value();
    std::shared_ptr<Node> get_left_node() { return left_node; }
    std::string get_right_name() { return right_name; }
    void set_pointer(llvm::Value* p) { pointer = p; }
    std::string get_left_typename();
    llvm::Value* get_pointer() { return pointer; }
    void set_call_node(std::shared_ptr<CallFunctionNode> n) { call_node = n; }
    std::shared_ptr<CallFunctionNode> get_call_node() { return call_node; }
    void set_generated(llvm::Value* c) { generated = c; }
    llvm::Value* get_generated() { return generated; }
};

class AssigmentNode : public Node {
private:
    std::shared_ptr<Node> right_node;
    std::shared_ptr<VariableNode> target_var;
    std::shared_ptr<AccessNode> target_member;

public:
    AssigmentNode(int line_number, AssigmentIRGenerator& ir_generator,
                  std::shared_ptr<Node> right_node,
                  std::shared_ptr<VariableNode> target_var = nullptr,
                  std::shared_ptr<AccessNode> target_member = nullptr,
                  std::string name = "")
        : Node(line_number, ir_generator, name),
          right_node(right_node),
          target_var(target_var),
          target_member(target_member) {}
    std::shared_ptr<VariableNode> get_target_var() const;
    std::shared_ptr<AccessNode> get_target_member() const;
    std::shared_ptr<Node> get_right_node() const;
};

class ArgumentNode : public Node {
private:
    llvm::Value* right_value;

public:
    ArgumentNode(int line_number, ArgumentIRGenerator& ir_generator,
                 std::string name = "")
        : Node(line_number, ir_generator, name, true) {}
    void set_right_value(llvm::Value*);
    llvm::Value* get_right_value();
};

class BinaryExpressionNode : public Node {
public:
    std::shared_ptr<Node> left_node;
    std::shared_ptr<Node> right_node;
    std::string operator_kind;
    BinaryExpressionNode(int line_number,
                         BinaryExpressionIRGenerator& ir_generator)
        : Node(line_number, ir_generator) {}
};

class FunctionNode : public Node {
private:
    llvm::Function* temporary_function;
    std::vector<llvm::Function*> base_functions;
    std::map<std::vector<llvm::Type*>, llvm::Function*> functions;
    scope self_namespace;

public:
    std::vector<std::string> arguments_names;
    std::vector<std::shared_ptr<Node>> body;
    std::shared_ptr<Node> return_value;
    FunctionNode(int line_number, FunctionIRGenerator& ir_generator,
                 std::string name, std::vector<std::string> arguments_names,
                 std::vector<std::shared_ptr<Node>> body,
                 std::shared_ptr<Node> return_value)
        : Node(line_number, ir_generator, name),
          arguments_names(arguments_names),
          body(std::make_move_iterator(body.begin()),
               std::make_move_iterator(body.end())),
          return_value(std::move(return_value)) {}
    bool is_function() override { return true; };
    void register_function(std::vector<llvm::Type*>, llvm::Function*);
    void set_self_namespace(scope);
    scope get_self_namespace();
    void set_temporary_function(llvm::Function*);
    llvm::Function* get_temporary_function();
    void set_base_function(llvm::Function*);
    std::vector<llvm::Function*> get_base_functions();
    llvm::Function* get_function(std::vector<llvm::Type*>);
    std::vector<llvm::Function*> get_functions();
};

class DeclareCNode : public Node {
private:
    std::vector<std::shared_ptr<Node>> _arguments_type;
    std::shared_ptr<Node> _return_type;

public:
    DeclareCNode(int line_number, DeclareCIRGenerator& ir_generator,
                 std::string name,
                 std::vector<std::shared_ptr<Node>> arguments_type,
                 std::shared_ptr<Node> return_type)
        : Node(line_number, ir_generator, name),
          _arguments_type(arguments_type),
          _return_type(return_type) {}
    std::vector<std::shared_ptr<Node>> arguments_type() {
        return _arguments_type;
    }
    std::shared_ptr<Node> return_type() { return _return_type; }
};

class CallFunctionNode : public Node {
public:
    std::shared_ptr<FunctionNode> function;
    std::vector<std::shared_ptr<Node>> passed_arguments;
    NodeCollector<ArgumentNode>& argument_collector;
    bool is_builtin;
    llvm::Function* builtin_function;
    bool is_C;
    CallFunctionNode(int line_number, CallFunctionIRGenerator& ir_generator,
                     std::shared_ptr<FunctionNode> function,
                     std::vector<std::shared_ptr<Node>> passed_arguments,
                     NodeCollector<ArgumentNode>& argument_collector)
        : Node(line_number, ir_generator),
          function(function),
          passed_arguments(std::make_move_iterator(passed_arguments.begin()),
                           std::make_move_iterator(passed_arguments.end())),
          argument_collector(argument_collector),
          is_C(false) {}
    CallFunctionNode(int line_number, CallFunctionIRGenerator& ir_generator,
                     std::vector<std::shared_ptr<Node>> passed_arguments,
                     NodeCollector<ArgumentNode>& argument_collector,
                     llvm::Function* builtin_function)
        : Node(line_number, ir_generator),
          passed_arguments(std::make_move_iterator(passed_arguments.begin()),
                           std::make_move_iterator(passed_arguments.end())),
          argument_collector(argument_collector),
          is_builtin(true),
          builtin_function(builtin_function),
          is_C(false) {}

    CallFunctionNode(int line_number, CallFunctionIRGenerator& ir_generator,
                     std::vector<std::shared_ptr<Node>> passed_arguments,
                     NodeCollector<ArgumentNode>& argument_collector,
                     std::string name)
        : Node(line_number, ir_generator, name),
          passed_arguments(passed_arguments),
          argument_collector(argument_collector),
          is_C(true) {}
};

class ClassNode : public Node {
private:
    std::vector<std::shared_ptr<FunctionNode>> methods;
    std::vector<std::shared_ptr<Node>> members_definition;
    llvm::Function* temporary_constructor;
    std::vector<llvm::Function*> base_constructors;
    std::map<std::vector<llvm::Type*>, llvm::Function*> constructors;
    std::map<std::vector<llvm::Type*>, llvm::Function*> destructors;
    scope self_namespace;
    std::vector<std::string> arguments_names;
    bool _is_C_type;

public:
    ClassNode(int line_number, ClassIRGenerator& ir_generator,
              std::vector<std::shared_ptr<FunctionNode>> methods,
              std::vector<std::shared_ptr<Node>> members_definition,
              std::vector<std::string> arguments_names, bool is_C_type,
              std::string name = "")
        : Node(line_number, ir_generator, name),
          methods(methods),
          members_definition(members_definition),
          arguments_names(arguments_names),
          _is_C_type(is_C_type) {}
    std::vector<std::string> get_arguments_names() { return arguments_names; }
    std::vector<std::shared_ptr<Node>> get_members_definition() {
        return members_definition;
    };
    std::vector<std::shared_ptr<FunctionNode>> get_methods() { return methods; }

    void register_constructor(std::vector<llvm::Type*>, llvm::Function*);
    llvm::Function* get_constructor(std::vector<llvm::Type*>);
    void register_destructor(std::vector<llvm::Type*>, llvm::Function*);
    llvm::Function* get_destructor(std::vector<llvm::Type*>);
    void set_self_namespace(scope n) { self_namespace = n; }
    scope get_self_namespace() { return self_namespace; }
    void set_temporary_constructor(llvm::Function* c) {
        temporary_constructor = c;
    }
    llvm::Function* get_temporary_constructor() {
        return temporary_constructor;
    }
    void set_base_constructor(llvm::Function* base) {
        base_constructors.push_back(base);
    }
    std::vector<llvm::Function*> get_base_constructors() {
        return base_constructors;
    }
    bool is_C_type() { return _is_C_type; }
};

class CallConstructorNode : public Node {
private:
    std::shared_ptr<ClassNode> class_node;
    std::vector<std::shared_ptr<Node>> passed_arguments;
    std::pair<llvm::Function*, llvm::Value*> destructor;

public:
    scope belong_to;
    NodeCollector<ArgumentNode>& argument_collector;

    CallConstructorNode(int line_number,
                        CallConstructorIRGenerator& ir_generator,
                        std::shared_ptr<ClassNode> class_node,
                        std::vector<std::shared_ptr<Node>> passed_arguments,
                        scope belong_to,
                        NodeCollector<ArgumentNode>& argument_collector,
                        std::string name = "")
        : Node(line_number, ir_generator, name),
          class_node(class_node),
          passed_arguments(passed_arguments),
          belong_to(belong_to),
          argument_collector(argument_collector) {}
    std::shared_ptr<ClassNode> get_class() { return class_node; }
    std::vector<std::shared_ptr<Node>> get_passed_arguments() {
        return passed_arguments;
    }
    void set_destructor(llvm::Function* destructor_, llvm::Value* instance) {
        destructor = std::make_pair(destructor_, instance);
    }
    std::pair<llvm::Function*, llvm::Value*> get_destructor() {
        return destructor;
    }
    bool is_calling_constructor() override { return true; }
};

class IfNode : public Node {
private:
    std::shared_ptr<Node> conditions;
    std::vector<std::shared_ptr<Node>> if_body;
    std::vector<std::shared_ptr<Node>> else_body;

public:
    IfNode(int line_number, IfIRGenerator& ir_generator,
           std::shared_ptr<Node> conditions,
           std::vector<std::shared_ptr<Node>> if_body,
           std::vector<std::shared_ptr<Node>> else_body)
        : Node(line_number, ir_generator),
          conditions(conditions),
          if_body(if_body),
          else_body(else_body) {}
    std::shared_ptr<Node> get_conditions() { return conditions; }
    std::vector<std::shared_ptr<Node>> get_if_body() { return if_body; }
    std::vector<std::shared_ptr<Node>> get_else_body() { return else_body; }
    void set_else_body(std::vector<std::shared_ptr<Node>> body) {
        else_body = body;
    }
};

class ForNode : public Node {
private:
    std::shared_ptr<Node> left_expression;
    std::shared_ptr<Node> center_expression;
    std::shared_ptr<Node> right_expression;
    std::vector<std::shared_ptr<Node>> body;

public:
    ForNode(int line_number, ForIRGenerator& ir_generator,
            std::shared_ptr<Node> left_expression,
            std::shared_ptr<Node> center_expression,
            std::shared_ptr<Node> right_expression,
            std::vector<std::shared_ptr<Node>> body)
        : Node(line_number, ir_generator),
          left_expression(right_expression),
          center_expression(center_expression),
          right_expression(right_expression),
          body(body) {}
    std::shared_ptr<Node> get_left_expression() { return left_expression; }
    std::shared_ptr<Node> get_center_expression() { return center_expression; }
    std::shared_ptr<Node> get_right_expression() { return right_expression; }
    std::vector<std::shared_ptr<Node>>& get_body() { return body; }
};

class ListNode : public Node {
private:
    std::vector<std::shared_ptr<Node>> elements;
    bool _is_null;

public:
    ListNode(int line_number, ListIRGenerator& ir_generator,
             std::vector<std::shared_ptr<Node>> elements)
        : Node(line_number, ir_generator), elements(elements) {}
    ListNode(int line_number, ListIRGenerator& ir_generator, bool is_null)
        : Node(line_number, ir_generator), _is_null(is_null) {}
    std::vector<std::shared_ptr<Node>> get_elements() { return elements; }
    bool is_null() { return _is_null; }
};

class BlockEndNode : public Node {
public:
    scope block_scope;
    BlockEndNode(int line_number, BlockEndIRGenerator& ir_generator,
                 scope block_scope)
        : Node(line_number, ir_generator), block_scope(block_scope) {}
};