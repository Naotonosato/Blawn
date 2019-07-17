#pragma once
#include <string>
#include <map>
#include <memory>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/LLVMContext.h>
#include "../ast/node.hpp"


class ASTGenerator
{
public:
    llvm::Module const& module;
    llvm::IRBuilder<> const& ir_builder;
    std::map<std::string,std::shared_ptr<Node>> variables;
    std::shared_ptr<Node> attach_operator(std::shared_ptr<Node> node,std::shared_ptr<Node> other,const std::string operator_type);
    
    ASTGenerator(llvm::Module const& module,llvm::IRBuilder<> const& ir_builder)
    :module(module),ir_builder(ir_builder){}

    void add_variable(std::string name,std::shared_ptr<Node> node);
    void generate();
};