#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include "../ir_generator/ir_generator.hpp"
#include "../builtins/type.hpp"
#include "node.hpp"
#include <vector>
#include <memory>


llvm::Value* Node::generate()
{
    return ir_generator->generate(*this);
} 