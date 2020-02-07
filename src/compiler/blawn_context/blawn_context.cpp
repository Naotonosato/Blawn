#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Type.h>
#include "../ast/node.hpp"
#include "blawn_context.hpp"

static int unique_id = 0;
static BlawnContext context;

void BlawnContext::register_element_name(std::string type, std::string name,
                                         unsigned int index) {
    element_names[type][name] = index;
}

std::map<std::string, unsigned int> BlawnContext::get_elements(
    std::string type_name) {
    if (element_names.count(type_name)) return element_names[type_name];
    return {};
}

int BlawnContext::get_element_index(std::string type, std::string name) {
    if (element_names.count(type)) {
        if (element_names[type].count(name))
            return element_names[type][name];
        else
            return -1;
    } else
        return -1;
}

BlawnContext& get_blawn_context() { return context; }

void BlawnContext::add_builtin_function(std::string name,
                                        llvm::Function* function) {
    builtin_functions[name] = function;
}

llvm::Function* BlawnContext::get_builtin_function(std::string name) {
    if (builtin_functions.count(name))
        return builtin_functions[name];
    else
        return nullptr;
}

bool BlawnContext::exist_builtin_function(std::string name) {
    if (get_builtin_function(name) == nullptr) {
        return false;
    } else
        return true;
}

void BlawnContext::add_builtin_class(
    std::string type_name, std::map<std::string, llvm::Function*> methods) {
    class_with_methods[type_name] = methods;
}

llvm::Function* BlawnContext::get_builtin_method(std::string type_name,
                                                 std::string name) {
    if (class_with_methods.count(type_name)) {
        return class_with_methods[type_name][name];
    } else {
        return nullptr;
    }
}

void BlawnContext::add_C_function(std::string name, llvm::Function* function) {
    C_functions[name] = function;
}

llvm::Function* BlawnContext::get_C_function(std::string name) {
    if (C_functions.count(name)) {
        return C_functions[name];
    } else {
        return nullptr;
    }
}

bool BlawnContext::exist_C_function(std::string name) {
    if (C_functions.count(name)) return true;
    return false;
}

void BlawnContext::add_class(std::string name,
                             std::shared_ptr<ast::ClassNode> class_) {
    classes[name] = class_;
}

std::shared_ptr<ast::ClassNode> BlawnContext::get_class(std::string name) {
    if (classes.count(name))
        return classes[name];
    else
        return nullptr;
}

void BlawnContext::add_user_type(std::string name, llvm::Type* type) {
    user_types[name] = type;
}

llvm::Type* BlawnContext::get_user_type(std::string name) {
    if (user_types.count(name))
        return user_types[name];
    else
        return nullptr;
}

llvm::ConstantInt* BlawnContext::get_typeid(llvm::LLVMContext& context_,
                                            llvm::Type* type) {
    if (!typeids.count(type)) {
        unique_id += 1;
        auto id =
            llvm::ConstantInt::get(context_, llvm::APInt(64, unique_id, true));
        typeids[type] = id;
        id_assigned_types[id] = type;
    }
    return typeids[type];
}

llvm::Type* BlawnContext::get_type_with_id(llvm::ConstantInt* id) {
    if (id_assigned_types.count(id))
        return id_assigned_types[id];
    else
        return nullptr;
}

std::vector<std::pair<llvm::Function*, llvm::Value*>>
BlawnContext::get_destructors(llvm::BasicBlock* block) {
    return destructors[block];
}

unsigned int BlawnContext::add_heap_user(Scope belong_scope,
                                         llvm::Value* user) {
    heap_users[belong_scope].push_back(user);
    return heap_users[belong_scope].size() - 1;
}

std::vector<llvm::Value*>& BlawnContext::get_heap_users(Scope belong_scope) {
    return heap_users[belong_scope];
}

void BlawnContext::set_destructor(llvm::BasicBlock* block,
                                  std::pair<llvm::Function*, llvm::Value*> d) {
    destructors[block].push_back(d);
}