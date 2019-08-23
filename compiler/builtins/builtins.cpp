#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/DataLayout.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Function.h>
#include "builtins.hpp"
#include "../blawn_context/blawn_context.hpp"


void builtins::create_string_type(llvm::LLVMContext& context,llvm::Module& module,llvm::IRBuilder<>& ir_builder)
{
    std::string type_name = "struct.String";
    std::vector<llvm::Type*> fields;
    fields.push_back(ir_builder.getInt8PtrTy());//string
    fields.push_back(ir_builder.getInt64Ty());//size
    auto string_type = llvm::StructType::create(context,fields,type_name);
    get_blawn_context().register_element_name(type_name,"@string",0);
    get_blawn_context().register_element_name(type_name,"@size",1);
    std::vector<llvm::Type*> constructor_args;
    constructor_args.push_back(ir_builder.getInt8PtrTy());//string
    constructor_args.push_back(ir_builder.getInt64Ty());//length
    auto constructor_type = llvm::FunctionType::get(string_type->getPointerTo(),constructor_args,false);
    llvm::Function::Create(
        constructor_type,
        llvm::Function::ExternalLinkage,
        "string_constructor",
        &module
    );    
    std::vector<llvm::Type*> add_method_args;
    add_method_args.push_back(string_type->getPointerTo());
    add_method_args.push_back(string_type->getPointerTo());
    auto add_method_type = llvm::FunctionType::get(ir_builder.getVoidTy(),add_method_args,false);
    llvm::Function::Create(
        add_method_type,
        llvm::Function::ExternalLinkage,
        "add_string",
        &module
        );
}