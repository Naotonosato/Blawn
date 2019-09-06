#pragma once
#include <vector>
#include <string>
#include <map>
#include <memory>
#include <iostream>

template<typename T>
class NodeCollector;
class Node;
class FunctionNode;
class IntegerIRGenerator;
class FloatIRGenerator;
namespace llvm
{
    class Module;
    template<typename T,typename Inserter>
    class IRBuilder;
    class Value;
}

 
class ASTGenerator
{
private:
    llvm::Module &module;
    llvm::IRBuilder<> &ir_builder;
    llvm::LLVMContext &context;
    NodeCollector<VariableNode> variable_collector;
    NodeCollector<FunctionNode> function_collector;
    NodeCollector<ArgumentNode> argument_collector;
    NodeCollector<ClassNode> class_collector;
    std::shared_ptr<IfNode> previous_if_node;
    std::map<std::string,std::shared_ptr<VariableNode>&> access_namespace(std::vector<std::string>);
public:
    IRGenerator ir_generator;
    SizeofGenerator sizeof_generator;
    TypeIdGenerator typeid_generator;
    CastIRGenerator cast_generator;
    IntegerIRGenerator int_ir_generator;
    FloatIRGenerator float_ir_generator;
    StringIRGenerator string_generator;
    VariableIRGenerator variable_generator;
    ArgumentIRGenerator argument_generator;
    AssigmentIRGenerator assigment_generator;
    BinaryExpressionIRGenerator binary_expression_generator;
    FunctionIRGenerator function_generator;
    CallFunctionIRGenerator calling_generator;
    ClassIRGenerator class_generator;
    CallConstructorIRGenerator call_constructor_generator;
    IfIRGenerator if_generator;
    ForIRGenerator for_generator;
    AccessIRGenerator access_generator;
    ListIRGenerator list_generator;
    int line_number;
    ASTGenerator(llvm::Module &module,
    llvm::IRBuilder<> &ir_builder,
    llvm::LLVMContext &context);
    void into_namespace(std::string name);
    void into_namespace();
    void break_out_of_namespace();
    std::unique_ptr<BinaryExpressionNode> attach_operator(std::shared_ptr<Node> node,std::shared_ptr<Node> other,const std::string operator_type);
    std::shared_ptr<Node> assign(std::string name,std::shared_ptr<Node> node);
    std::shared_ptr<Node> assign(std::shared_ptr<AccessNode> left,std::shared_ptr<Node> right);
    std::shared_ptr<Node> assign_typeid(std::string name,std::shared_ptr<Node> type_id);
    std::shared_ptr<Node> get_typeid(std::string name);
    std::shared_ptr<Node> get_named_value(std::string name);
    void add_argument(std::string);
    std::unique_ptr<IntegerNode> create_integer(int num);
    std::unique_ptr<FloatNode> create_float(double num);
    std::unique_ptr<StringNode> create_string(std::string str);
    void book_function(std::string name);
    std::shared_ptr<FunctionNode> add_function(std::string name,std::vector<std::string> arguments,std::vector<std::shared_ptr<Node>> body,std::shared_ptr<Node> return_value);
    std::unique_ptr<Node> create_call(std::string name,std::vector<std::shared_ptr<Node>> arguments);
    std::shared_ptr<Node> create_call(std::shared_ptr<AccessNode>,std::vector<std::shared_ptr<Node>> arguments);
    std::shared_ptr<ClassNode> add_class(std::string,std::vector<std::string> arguments,std::vector<std::shared_ptr<Node>> members_definition,std::vector<std::shared_ptr<FunctionNode>> body);
    std::shared_ptr<Node> create_if(std::shared_ptr<Node>,std::vector<std::shared_ptr<Node>>);
    std::shared_ptr<Node> create_for(std::shared_ptr<Node>,std::shared_ptr<Node>,std::shared_ptr<Node>,std::vector<std::shared_ptr<Node>> body);
    std::shared_ptr<Node> add_else(std::vector<std::shared_ptr<Node>>);
    std::shared_ptr<AccessNode> create_access(std::string left,std::string right);
    std::shared_ptr<AccessNode> create_access(std::shared_ptr<Node> left,std::string right);
    std::shared_ptr<ListNode> create_list(std::vector<std::shared_ptr<Node>> elements);
    std::shared_ptr<ListNode> create_list();
    void generate(std::vector<std::shared_ptr<Node>>);
};