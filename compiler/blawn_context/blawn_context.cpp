#include <llvm/IR/Type.h>
#include <llvm/IR/Function.h>
#include "blawn_context.hpp"
#include "../ast/node.hpp"

static BlawnContext context;

void BlawnContext::register_element_name(std::string type,std::string name,unsigned int index)
{
    element_names[type][name] = index;
}

int BlawnContext::get_element_index(std::string type,std::string name)
{
    if (element_names.count(type))
    {
        if (element_names[type].count(name)) return element_names[type][name];
        else return -1;
    }
    else return -1;
}

BlawnContext& get_blawn_context()
{
    return context;
}

void BlawnContext::add_builtin_function(std::string name,llvm::Function* function)
{
    builtin_functions[name] = function;
}

llvm::Function* BlawnContext::get_builtin_function(std::string name)
{
    if (builtin_functions.count(name)) return builtin_functions[name];
    else return nullptr;
}

bool BlawnContext::exist_builtin_function(std::string name)
{
    if (get_builtin_function(name) == nullptr)
    {
        return false;
    }
    else return true;
}

void BlawnContext::add_builtin_class(std::string type_name,std::map<std::string,llvm::Function*> methods)
{
    class_with_methods[type_name] = methods;
}

llvm::Function* BlawnContext::get_builtin_method(std::string type_name,std::string name)
{
    if (class_with_methods.count(type_name))
    {
        return class_with_methods[type_name][name];
    }
    else {return nullptr;}
}

void BlawnContext::add_class(std::string name,std::shared_ptr<ClassNode> class_)
{
    classes[name] = class_;
}
std::shared_ptr<ClassNode> BlawnContext::get_class(std::string name)
{
    if (classes.count(name)) return classes[name];
    else return nullptr;
}