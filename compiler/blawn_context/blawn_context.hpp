#pragma once
#include <map>
#include <string>
#include <vector>
#include "../ast_generator/node_collector.hpp"

namespace llvm {
class Type;
class StructType;
class ConstantInt;
class BasicBlock;
}  // namespace llvm
class FunctionNode;
class CallConstructorNode;
class ClassNode;

class BlawnContext {
private:
    std::map<std::string, std::map<std::string, unsigned int>> element_names;
    std::map<std::string, llvm::Function*> builtin_functions;
    std::map<std::string, llvm::Function*> C_functions;
    std::map<std::string, std::shared_ptr<ClassNode>> classes;
    std::map<std::string, llvm::Type*> user_types;
    std::map<std::string, std::map<std::string, llvm::Function*>>
        class_with_methods;
    std::map<llvm::Type*, llvm::ConstantInt*> typeids;
    std::map<llvm::ConstantInt*, llvm::Type*> id_assigned_types;
    std::map<llvm::BasicBlock*,
             std::vector<std::pair<llvm::Function*, llvm::Value*>>>
        destructors;
    std::map<scope, std::vector<llvm::Value*>> heap_users;

public:
    void register_element_name(std::string, std::string name,
                               unsigned int index);
    int get_element_index(std::string, std::string name);
    void add_builtin_function(std::string name, llvm::Function* function);
    void add_C_function(std::string name, llvm::Function* function);
    llvm::Function* get_builtin_function(std::string name);
    llvm::Function* get_C_function(std::string name);
    void add_builtin_class(std::string type_name,
                           std::map<std::string, llvm::Function*> methods);
    llvm::Function* get_builtin_method(std::string type_name, std::string name);
    bool exist_builtin_function(std::string name);
    bool exist_C_function(std::string name);
    void add_class(std::string, std::shared_ptr<ClassNode>);
    std::shared_ptr<ClassNode> get_class(std::string);
    void add_user_type(std::string name_at_definition, llvm::Type* type);
    llvm::Type* get_user_type(std::string name_at_definition);
    llvm::ConstantInt* get_typeid(llvm::LLVMContext& context_, llvm::Type*);
    llvm::Type* get_type_with_id(llvm::ConstantInt* id);
    std::vector<std::pair<llvm::Function*, llvm::Value*>> get_destructors(
        llvm::BasicBlock*);
    void add_heap_user(scope, llvm::Value*);
    std::vector<llvm::Value*> get_heap_users(scope);
    void set_destructor(llvm::BasicBlock*,
                        std::pair<llvm::Function*, llvm::Value*>);
};

BlawnContext& get_blawn_context();