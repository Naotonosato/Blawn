#include <llvm/IR/Argument.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Value.h>
#include <llvm/Support/raw_ostream.h>
#include <iostream>
#include <memory>
#include <vector>
#include "../blawn_context/blawn_context.hpp"
#include "../ir_generator/ir_generator.hpp"
#include "../utils/utils.hpp"
#include "node.hpp"

llvm::Value* Node::generate() {
    auto value = ir_generator.generate(*this);
    return value;
}

void VariableNode::assign(std::shared_ptr<Node> node) { right_node = node; }

void VariableNode::initialize() { _is_generated = false; }

bool VariableNode::is_generated() { return _is_generated; }

void VariableNode::generated() { _is_generated = true; }

llvm::Value* AccessNode::get_left_value() {
    if (left_value == nullptr) {
        left_value = left_node->generate();
    }
    return left_value;
}

void ArgumentNode::set_right_value(llvm::Value* value) { right_value = value; }

void ArgumentNode::set_right_node(std::shared_ptr<Node> node) {
    right_node = node;
}

llvm::Value* ArgumentNode::get_right_value() { return right_value; }

std::shared_ptr<VariableNode> AssigmentNode::get_target_var() const {
    return target_var;
}

std::shared_ptr<AccessNode> AssigmentNode::get_target_member() const {
    return target_member;
}

std::shared_ptr<Node> AssigmentNode::get_right_node() const {
    return right_node;
}

void FunctionNode::register_function(std::vector<llvm::Type*> types,
                                     llvm::Function* function) {
    functions[types] = function;
}

void FunctionNode::set_temporary_function(llvm::Function* func) {
    temporary_function = func;
}

llvm::Function* FunctionNode::get_temporary_function() {
    return temporary_function;
}

void FunctionNode::set_base_function(llvm::Function* base) {
    base_functions.push_back(base);
}

std::vector<llvm::Function*> FunctionNode::get_base_functions() {
    return base_functions;
}

llvm::Function* FunctionNode::get_function(std::vector<llvm::Type*> types) {
    if (functions.count(types) == 0) {
        return nullptr;
    }
    return functions[types];
}

std::vector<llvm::Function*> FunctionNode::get_functions() {
    std::vector<llvm::Function*> res;
    for (auto& pair : functions) {
        res.push_back(pair.second);
    }
    return res;
}

void FunctionNode::set_self_namespace(Scope self) {
    self_namespace = self;
}

Scope FunctionNode::get_self_namespace() {
    return self_namespace;
}

void ClassNode::register_constructor(std::vector<llvm::Type*> types,
                                     llvm::Function* constructor) {
    constructors[types] = constructor;
}

llvm::Function* ClassNode::get_constructor(std::vector<llvm::Type*> types) {
    if (constructors.count(types))
        return constructors[types];
    else
        return nullptr;
}

void ClassNode::register_destructor(std::vector<llvm::Type*> types,
                                    llvm::Function* destructor) {
    destructors[types] = destructor;
}
llvm::Function* ClassNode::get_destructor(std::vector<llvm::Type*> types) {
    if (destructors.count(types))
        return destructors[types];
    else
        return nullptr;
}