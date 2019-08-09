#include <llvm/IR/Value.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Argument.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/Support/raw_ostream.h>
#include "../ir_generator/ir_generator.hpp"
#include "../builtins/type.hpp"
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

void VariableNode::set_right_value(llvm::Argument* value)
{
    if (right_value == nullptr)
    {
        is_null_parent = (value->getParent() == nullptr);
        right_value = value;
    }
    else
    {
        if (is_null_parent)
        {
            right_value = value;
        }
        else
        {
            std::cout << "you can't set right_value more than two times." << std::endl;
        }
    }
}

llvm::Value* VariableNode::get_right_value()
{
    return right_value;
}

llvm::Value* VariableNode::generate()
{
    //std::cout << "start gen variable." << std::endl;
    auto value =  ir_generator.generate(*this);
    //std::cout << "succes." << std::endl;
    return value;
}

llvm::Value* BinaryExpressionNode::generate()
{
    //std::cout << "start gen bin expr." << std::endl;
    auto value =  ir_generator.generate(*this);
    //std::cout << "succes." << std::endl;
    return value;
}

void FunctionNode::register_function(std::vector<llvm::Type*> types,llvm::Function* function) 
{
    functions[types] = function;
}

llvm::Function* FunctionNode::get_function(std::vector<llvm::Type*> types)
{
    if (functions.count(types) == 0)
    {
        return nullptr;
    }
    return functions[types];
}

llvm::Function* FunctionNode::generate()
{
    auto value =  ir_generator.generate(*this);
    return value;
}

llvm::Value* CallFunctionNode::generate()
{
    auto value =  ir_generator.generate(*this);
    return value;
}