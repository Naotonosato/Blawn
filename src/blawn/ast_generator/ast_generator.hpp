#pragma once
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "../errors/errors.hpp"

template <typename T>
class NodeCollector;
class Node;
class FunctionNode;
class IntegerIRGenerator;
class FloatIRGenerator;
namespace llvm {
class Module;
template <typename T, typename Inserter>
class IRBuilder;
class Value;
} // namespace llvm

class ASTGenerator {
private:
  llvm::Module& module;
  llvm::IRBuilder<>& ir_builder;
  llvm::LLVMContext& context;
  NodeCollector<VariableNode> variable_collector;
  NodeCollector<FunctionNode> function_collector;
  NodeCollector<ArgumentNode> argument_collector;
  NodeCollector<ClassNode> class_collector;
  NodeCollector<ClassNode> C_type_collector;
  std::map<std::string, std::shared_ptr<VariableNode>&> access_namespace(
      std::vector<std::string>);
  Scope current_scope;

public:
  IRGenerators ir_generators;
  int line_number;
  std::shared_ptr<Node> no_value_node;
  BlawnLogger logger;
  ASTGenerator(llvm::Module& module, llvm::IRBuilder<>& ir_builder, llvm::LLVMContext& context,
               int line_number = 1);
  void into_namespace(std::string name);
  void into_namespace();
  void break_out_of_namespace();
  std::unique_ptr<BinaryExpressionNode> attach_operator(std::shared_ptr<Node> node,
                                                        std::shared_ptr<Node> other,
                                                        const std::string operator_type);
  std::shared_ptr<Node> create_assign(std::string name, std::shared_ptr<Node> node,
                                      bool is_global);
  std::shared_ptr<Node> create_assign(std::shared_ptr<AccessNode> left,
                                      std::shared_ptr<Node> right);
  std::shared_ptr<Node> create_assign_typeid(std::string name, std::shared_ptr<Node> type_id);
  std::shared_ptr<Node> create_store(std::shared_ptr<Node> pointer,
                                     std::shared_ptr<Node> object);
  std::shared_ptr<Node> get_typeid(std::string name);
  std::shared_ptr<Node> get_named_value(std::string name);
  std::shared_ptr<Node> create_C_member(std::string name);
  std::shared_ptr<Node> add_global_variables(std::vector<std::shared_ptr<Node>>);
  std::shared_ptr<Node> declare_C_function(std::string name,
                                           std::vector<std::shared_ptr<Node>> args,
                                           std::shared_ptr<Node> return_);
  void add_argument(std::string);
  std::unique_ptr<IntegerNode> create_integer(int num);
  std::unique_ptr<FloatNode> create_float(double num);
  std::shared_ptr<Node> create_minus(std::shared_ptr<Node> expr);
  std::shared_ptr<StringNode> create_string(std::string str);
  void book_function(std::string name);
  std::shared_ptr<FunctionNode> add_function(std::string name,
                                             std::vector<std::string> arguments,
                                             std::vector<std::shared_ptr<Node>> body,
                                             std::shared_ptr<Node> return_value);
  std::unique_ptr<Node> create_call(std::string name,
                                    std::vector<std::shared_ptr<Node>> arguments);
  std::shared_ptr<Node> create_call(std::shared_ptr<AccessNode>,
                                    std::vector<std::shared_ptr<Node>> arguments);
  std::shared_ptr<ClassNode> create_class(std::string, std::vector<std::string> arguments,
                                          std::vector<std::shared_ptr<Node>> members_definition,
                                          std::vector<std::shared_ptr<FunctionNode>> body);
  std::shared_ptr<ClassNode> create_C_type(
      std::string name, std::vector<std::shared_ptr<Node>> members_definition);
  std::shared_ptr<Node> create_if(std::shared_ptr<Node> cond,
                                  std::vector<std::shared_ptr<Node>> if_body,
                                  std::vector<std::shared_ptr<Node>> else_body);
  std::shared_ptr<Node> create_for(std::shared_ptr<Node>, std::shared_ptr<Node>,
                                   std::shared_ptr<Node>,
                                   std::vector<std::shared_ptr<Node>> body);
  std::shared_ptr<AccessNode> create_access(std::string left, std::string right);
  std::shared_ptr<AccessNode> create_access(std::shared_ptr<Node> left, std::string right);
  std::shared_ptr<ListNode> create_list(std::vector<std::shared_ptr<Node>> elements);
  std::shared_ptr<ListNode> create_list();
  std::shared_ptr<Node> create_block_end();
  void generate(std::vector<std::shared_ptr<Node>>);
};