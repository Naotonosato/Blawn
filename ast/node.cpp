#include <llvm/IR/Value.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Argument.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/Support/raw_ostream.h>
#include "../ir_generator/ir_generator.hpp"
#include "node.hpp"
#include <vector>
#include <memory>
#include <iostream>


llvm::Value* Node::generate()
{
    auto value =  ir_generator.generate(*this);
    
    //std::cout << "-----LLVM IR------(generator class: " << typeid(*ir_generator).name() << ")\n";
    //std::cout << "is value null?" << (value == 0) << "\n";
    //value->print(llvm::errs());
    //std::cout << std::endl;
    //std::cout << "\n------LLVM IR END------\n\n";
    
    return value;
}

void VariableNode::assign(std::shared_ptr<Node> node)
{
    right_node = node;
}

void ArgumentNode::set_right_value(llvm::Value* value)
{
    right_value = value;
}

llvm::Value* ArgumentNode::get_right_value()
{
    return right_value;
}

std::shared_ptr<VariableNode> AssigmentNode::get_target() const
{
    return target;
}

std::shared_ptr<Node> AssigmentNode::get_right_node() const
{
    return right_node;
}

void FunctionNode::register_function(std::vector<llvm::Type*> types,llvm::Function* function) 
{
    functions[types] = function;
}

void FunctionNode::set_temporary_function(llvm::Function* func)
{
    temporary_function = func;
}

llvm::Function* FunctionNode::get_temporary_function()
{
    return temporary_function;
}

llvm::Function* FunctionNode::get_function(std::vector<llvm::Type*> types)
{
    if (functions.count(types) == 0)
    {
        return nullptr;
    }
    return functions[types];
}

void FunctionNode::set_self_namespace(std::vector<std::string> self)
{
    self_namespace = self;
}

std::vector<std::string> FunctionNode::get_self_namespace()
{
    return self_namespace;
}

