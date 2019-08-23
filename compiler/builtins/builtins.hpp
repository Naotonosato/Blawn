#pragma once
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
    void create_string_type(llvm::LLVMContext& context,llvm::Module& module,llvm::IRBuilder<>& ir_builder);
}