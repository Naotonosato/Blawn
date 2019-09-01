#include <memory>
#include <string>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/DataLayout.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Function.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Linker/Linker.h>
#include "builtins.hpp"
#include "../blawn_context/blawn_context.hpp"

void builtins::load_builtins(llvm::LLVMContext& context,llvm::Module& module,std::string filename)
{
    llvm::SMDiagnostic err;
    auto module_b = llvm::parseIRFile(filename,err,context);
    llvm::Linker::linkModules(module,std::move(module_b));
}

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
    std::vector<llvm::Type*> append_method_args;
    append_method_args.push_back(string_type->getPointerTo());
    append_method_args.push_back(string_type->getPointerTo());
    auto append_method_type = llvm::FunctionType::get(ir_builder.getVoidTy(),append_method_args,false);
    auto append_method = llvm::Function::Create(
        append_method_type,
        llvm::Function::ExternalLinkage,
        "append_string",
        &module
        ); 
    std::map<std::string,llvm::Function*> methods;
    methods["append"] = append_method;
    get_blawn_context().add_builtin_class(type_name,methods);
    std::vector<llvm::Type*> print_args(1,string_type->getPointerTo());
    auto print_type = llvm::FunctionType::get(ir_builder.getVoidTy(),print_args,false);
    auto print = llvm::Function::Create(
        print_type,
        llvm::Function::ExternalLinkage,
        "print",
        &module
    );
    get_blawn_context().add_builtin_function("print",print);
}

void builtins::create_list_type(llvm::LLVMContext& context,llvm::Module& module,llvm::IRBuilder<>& ir_builder)
{
    std::map<std::string,llvm::Function*> methods;
    std::string type_name = "struct.List";
    std::vector<llvm::Type*> fields;
    fields.push_back(ir_builder.getInt64Ty());
    fields.push_back(ir_builder.getInt64Ty());
    fields.push_back(ir_builder.getInt64Ty());
    fields.push_back(ir_builder.getInt8PtrTy());
    auto list_type = llvm::StructType::create(context,fields,type_name);
    get_blawn_context().register_element_name(type_name,"@size",1);
    
    std::vector<llvm::Type*> constructor_args;
    constructor_args.push_back(ir_builder.getInt64Ty());
    auto constructor_type = llvm::FunctionType::get(list_type->getPointerTo(),constructor_args,false);
    llvm::Function::Create(
        constructor_type,
        llvm::Function::ExternalLinkage,
        "list_constructor",
        &module
    );    
    std::vector<llvm::Type*> append_method_args;
    append_method_args.push_back(list_type->getPointerTo());//pointer to self
    append_method_args.push_back(ir_builder.getInt8PtrTy());//new element
    auto append_method_type = llvm::FunctionType::get(ir_builder.getVoidTy(),append_method_args,false);
    auto append_method = llvm::Function::Create(
        append_method_type,
        llvm::Function::ExternalLinkage,
        "append_to_list",
        &module
        ); 
    methods["append"] = append_method;
    get_blawn_context().add_builtin_class(type_name,methods);

    std::vector<llvm::Type*> get_method_args;
    get_method_args.push_back(list_type->getPointerTo());//pointer to self
    get_method_args.push_back(ir_builder.getInt64Ty());//new element
    auto get_method_type = llvm::FunctionType::get(ir_builder.getInt8PtrTy(),get_method_args,false);
    auto get_method = llvm::Function::Create(
        get_method_type,
        llvm::Function::ExternalLinkage,
        "get_element",
        &module
        ); 
    methods["#get"] = get_method;
    get_blawn_context().add_builtin_class(type_name,methods);
}