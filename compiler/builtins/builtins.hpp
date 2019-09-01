#pragma once
#include <string>
namespace llvm
{
    class Module;
    template<typename T,typename Inserter>
    class IRBuilder;
    class Value;
    class Type;
    class StructType;
}


namespace builtins
{
    void load_builtins(llvm::LLVMContext& context,llvm::Module& module,std::string);
    void create_string_type(llvm::LLVMContext& context,llvm::Module& module,llvm::IRBuilder<>& ir_builder);
    void create_list_type(llvm::LLVMContext& context,llvm::Module& module,llvm::IRBuilder<>& ir_builder);
}