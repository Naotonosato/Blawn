#pragma once
#include <string>
namespace llvm {
class Module;
class LLVMContext;
template <typename T, typename Inserter>
class IRBuilder;
class Value;
class Type;
}  // namespace llvm

namespace ast {
class GenericClassNode;
}

namespace utils {
std::string get_filename(std::string name);
std::string to_string(Scope&);
std::string to_string(llvm::Type*);
std::string to_string(llvm::Value*);
void split(std::string text, std::string splitter,
           std::vector<std::string>& res);
void replace(std::string& text, std::string from, std::string to,
             unsigned int from_index = 0);
bool exist(std::string text, std::string to_find);
template <typename T>
bool exist(std::vector<T> vec, T element) {
    return std::find(vec.begin(), vec.end(), element) != vec.end();
}
uint64_t get_sizeof(llvm::Type* type, llvm::Module& module);
llvm::Value* malloc_value(llvm::Type* type, llvm::LLVMContext& context,
                          llvm::Module& module, llvm::IRBuilder<>& ir_builder);
llvm::Value* free_value(llvm::Value* to_delete_ptr, llvm::Module& module,
                        llvm::IRBuilder<>& ir_builder);
llvm::Type* get_or_create_type(llvm::LLVMContext&,
                               std::shared_ptr<ast::GenericClassNode>, std::string);
}  // namespace utils