#pragma once
#include <string>
#include <map>
#include <vector>
#include "../ast_generator/node_collector.hpp"


namespace llvm
{
    class Type;
    class StructType;
    class ConstantInt;
}
class FunctionNode;
class ClassNode;


class BlawnContext
{
    private:
    std::map<std::string,std::map<std::string,unsigned int>> element_names;
    std::map<std::string,llvm::Function*> builtin_functions;
    std::map<std::string,std::shared_ptr<ClassNode>> classes;
    std::map<std::string,std::map<std::string,llvm::Function*>> class_with_methods;
    std::map<llvm::Type*,llvm::ConstantInt*> typeids;
    std::map<llvm::ConstantInt*,llvm::Type*> id_assigned_types;
    public:
    void register_element_name(std::string,std::string name,unsigned int index);
    int get_element_index(std::string,std::string name);
    void add_builtin_function(std::string name,llvm::Function* function);
    llvm::Function* get_builtin_function(std::string name);
    void add_builtin_class(std::string type_name,std::map<std::string,llvm::Function*> methods);
    llvm::Function* get_builtin_method(std::string type_name,std::string name);
    bool exist_builtin_function(std::string name);
    void add_class(std::string,std::shared_ptr<ClassNode>);
    std::shared_ptr<ClassNode> get_class(std::string);
    llvm::ConstantInt* get_typeid(llvm::LLVMContext& context_,llvm::Type*);
    llvm::Type* get_type_with_id(llvm::ConstantInt* id);
};


BlawnContext& get_blawn_context();