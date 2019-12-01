#pragma once
#include <string>
namespace llvm {
class Module;
template <typename T, typename Inserter>
class IRBuilder;
class LLVMContext;
class Value;
class Type;
class StructType;
}  // namespace llvm

namespace builtins {
<<<<<<< HEAD
    /*
void load_builtins(llvm::LLVMContext& context, llvm::Module& module,
                   std::string);
                   */
=======
void load_builtins(llvm::LLVMContext& context, llvm::Module& module,
                   std::string);
>>>>>>> 919055abcabcf8e18121b227bb54abfa63c348ad
void load_builtin_functions(llvm::LLVMContext& context, llvm::Module& module,
                            llvm::IRBuilder<>& ir_builder);
void create_string_type(llvm::LLVMContext& context, llvm::Module& module,
                        llvm::IRBuilder<>& ir_builder);
}  // namespace builtins