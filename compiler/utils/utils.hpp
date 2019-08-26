#pragma once
#include <string>
namespace llvm
{
    class Module;
    template<typename T,typename Inserter>
    class IRBuilder;
    class Value;
    class Type;
}

namespace utils
{
    std::string to_string(llvm::Type*);
    std::string to_string(llvm::Value*);
    uint64_t get_sizeof(llvm::Type* type,llvm::Module& module);
    llvm::Value* malloc_value(llvm::Type* type,llvm::LLVMContext& context,llvm::Module& module,llvm::IRBuilder<>& ir_builder);
    llvm::Value* free_value(llvm::Value* to_delete_ptr,llvm::Module& module,llvm::IRBuilder<>& ir_builder);
}