#include <llvm/IR/DataLayout.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Linker/Linker.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/raw_ostream.h>
#include <memory>
#include <string>
#include "builtins.hpp"
#include "../blawn_context/blawn_context.hpp"

void builtins::load_builtins(llvm::LLVMContext& context, llvm::Module& module,
                             std::string filename) {
    llvm::SMDiagnostic err;
    auto module_b = llvm::parseIRFile(filename, err, context);
    llvm::Linker::linkModules(module, std::move(module_b));
}

void builtins::load_builtin_functions(llvm::LLVMContext& context,llvm::Module& module,
                                      llvm::IRBuilder<>& ir_builder) {
    auto last_block = ir_builder.GetInsertBlock();
    std::vector<llvm::Type*> i64_to_i8_args;
    i64_to_i8_args.push_back(ir_builder.getInt64Ty());
    std::vector<llvm::Type*> i64_to_i32_args;
    i64_to_i32_args.push_back(ir_builder.getInt64Ty());
    std::vector<llvm::Type*> i32_to_i8_args;
    i32_to_i8_args.push_back(ir_builder.getInt32Ty());
    std::vector<llvm::Type*> i8_to_i32_args;
    i8_to_i32_args.push_back(ir_builder.getInt8Ty());
    std::vector<llvm::Type*> i32_to_i64_args;
    i32_to_i64_args.push_back(ir_builder.getInt32Ty());
    std::vector<llvm::Type*> i8_to_i64_args;
    i8_to_i64_args.push_back(ir_builder.getInt8Ty());
    auto i64_to_i8_type = llvm::FunctionType::get(
        ir_builder.getInt8Ty(),
        i64_to_i8_args,false
    );
    auto i64_to_i32_type = llvm::FunctionType::get(
        ir_builder.getInt32Ty(),
        i64_to_i32_args,false
    );
    auto i32_to_i8_type = llvm::FunctionType::get(
        ir_builder.getInt8Ty(),
        i32_to_i8_args,false
    );
    auto i8_to_i32_type = llvm::FunctionType::get(
        ir_builder.getInt32Ty(),
        i8_to_i32_args,false
    );
    auto i32_to_i64_type = llvm::FunctionType::get(
        ir_builder.getInt64Ty(),
        i32_to_i64_args,false
    );
    auto i8_to_i64_type = llvm::FunctionType::get(
        ir_builder.getInt64Ty(),
        i8_to_i64_args,false
    );
    auto i64_to_i8 = llvm::Function::Create(
        i64_to_i8_type,llvm::Function::ExternalLinkage,
        "i64_to_i8",&module
    );
    auto i64_to_i32 = llvm::Function::Create(
        i64_to_i32_type,llvm::Function::ExternalLinkage,
        "i64_to_i32",&module
    );
    auto i32_to_i8 = llvm::Function::Create(
        i32_to_i8_type,llvm::Function::ExternalLinkage,
        "i32_to_i8",&module
    );
    auto i8_to_i32 = llvm::Function::Create(
        i8_to_i32_type,llvm::Function::ExternalLinkage,
        "i8_to_i32",&module
    );
    auto i32_to_i64 = llvm::Function::Create(
        i32_to_i64_type,llvm::Function::ExternalLinkage,
        "i32_to_i64",&module
    );
    auto i8_to_i64 = llvm::Function::Create(
        i8_to_i64_type,llvm::Function::ExternalLinkage,
        "i8_to_i64",&module
    );
    auto i64_to_i8_block = llvm::BasicBlock::Create(context,"i64_to_i8",i64_to_i8);
    ir_builder.SetInsertPoint(i64_to_i8_block);
    ir_builder.CreateRet(ir_builder.CreateIntCast(i64_to_i8->arg_begin(),ir_builder.getInt8Ty(),false));
    auto i64_to_i32_block = llvm::BasicBlock::Create(context,"i64_to_i32",i64_to_i32);
    ir_builder.SetInsertPoint(i64_to_i32_block);
    ir_builder.CreateRet(ir_builder.CreateIntCast(i64_to_i32->arg_begin(),ir_builder.getInt32Ty(),false));
    auto i32_to_i8_block = llvm::BasicBlock::Create(context,"i32_to_i8",i32_to_i8);
    ir_builder.SetInsertPoint(i32_to_i8_block);
    ir_builder.CreateRet(ir_builder.CreateIntCast(i32_to_i8->arg_begin(),ir_builder.getInt8Ty(),false));
    auto i8_to_i32_block = llvm::BasicBlock::Create(context,"i8_to_i32",i8_to_i32);
    ir_builder.SetInsertPoint(i8_to_i32_block);
    ir_builder.CreateRet(ir_builder.CreateIntCast(i8_to_i32->arg_begin(),ir_builder.getInt32Ty(),false));
    auto i32_to_i64_block = llvm::BasicBlock::Create(context,"i32_to_i64",i32_to_i64);
    ir_builder.SetInsertPoint(i32_to_i64_block);
    ir_builder.CreateRet(ir_builder.CreateIntCast(i32_to_i64->arg_begin(),ir_builder.getInt64Ty(),false));
    auto i8_to_i64_block = llvm::BasicBlock::Create(context,"i8_to_i64",i8_to_i64);
    ir_builder.SetInsertPoint(i8_to_i64_block);
    ir_builder.CreateRet(ir_builder.CreateIntCast(i8_to_i64->arg_begin(),ir_builder.getInt64Ty(),false));
    
    ir_builder.SetInsertPoint(last_block);

    get_blawn_context().add_builtin_function("i64_to_i8",i64_to_i8);
    get_blawn_context().add_builtin_function("i64_to_i32",i64_to_i32);
    get_blawn_context().add_builtin_function("i32_to_i8",i32_to_i8);
    get_blawn_context().add_builtin_function("i8_to_i32",i8_to_i32);
    get_blawn_context().add_builtin_function("i32_to_i64",i32_to_i64);
    get_blawn_context().add_builtin_function("i8_to_i64",i8_to_i64);


    std::vector<llvm::Type*> blawn_memcpy_args;
    /*void* array,i64 size,i64 element_size,void *element*/
    blawn_memcpy_args.push_back(ir_builder.getInt8PtrTy());
    blawn_memcpy_args.push_back(ir_builder.getInt64Ty());
    blawn_memcpy_args.push_back(ir_builder.getInt64Ty());
    blawn_memcpy_args.push_back(ir_builder.getInt8PtrTy());
    auto blawn_memcpy_type = llvm::FunctionType::get(ir_builder.getVoidTy(),
                                                     blawn_memcpy_args, false);
    auto blawn_memcpy = llvm::Function::Create(blawn_memcpy_type,
                                               llvm::Function::ExternalLinkage,
                                               "blawn_memcpy", &module);
    get_blawn_context().add_builtin_function("__blawn_memcpy__", blawn_memcpy);

    /*void* array,i64 element_size,i64 allocated_size*/
    std::vector<llvm::Type*> blawn_realloc_args;
    blawn_realloc_args.push_back(ir_builder.getInt8PtrTy());
    blawn_realloc_args.push_back(ir_builder.getInt64Ty());
    blawn_realloc_args.push_back(ir_builder.getInt64Ty());
    auto blawn_realloc_type = llvm::FunctionType::get(
        ir_builder.getInt8PtrTy(), blawn_realloc_args, false);
    auto blawn_realloc = llvm::Function::Create(blawn_realloc_type,
                                                llvm::Function::ExternalLinkage,
                                                "blawn_realloc", &module);
    get_blawn_context().add_builtin_function("__blawn_realloc__",
                                             blawn_realloc);
    // void* blawn_index(void* array,i64 size,i64 element_size,i64 index)
    std::vector<llvm::Type*> blawn_index_args;
    blawn_index_args.push_back(ir_builder.getInt8PtrTy());
    blawn_index_args.push_back(ir_builder.getInt64Ty());
    blawn_index_args.push_back(ir_builder.getInt64Ty());
    blawn_index_args.push_back(ir_builder.getInt64Ty());
    auto blawn_index_type = llvm::FunctionType::get(ir_builder.getInt8PtrTy(),
                                                    blawn_index_args, false);
    auto blawn_index = llvm::Function::Create(blawn_index_type,
                                              llvm::Function::ExternalLinkage,
                                              "blawn_index", &module);
    get_blawn_context().add_builtin_function("__blawn_index__", blawn_index);
    // void blawn_set_element(void* array,i64 size,i64 element_size,void*
    // element,i64 index)
    std::vector<llvm::Type*> blawn_set_element_args;
    blawn_set_element_args.push_back(ir_builder.getInt8PtrTy());
    blawn_set_element_args.push_back(ir_builder.getInt64Ty());
    blawn_set_element_args.push_back(ir_builder.getInt64Ty());
    blawn_set_element_args.push_back(ir_builder.getInt8PtrTy());
    blawn_set_element_args.push_back(ir_builder.getInt64Ty());
    auto blawn_set_element_type = llvm::FunctionType::get(
        ir_builder.getInt8PtrTy(), blawn_set_element_args, false);
    auto blawn_set_element = llvm::Function::Create(
        blawn_set_element_type, llvm::Function::ExternalLinkage,
        "blawn_set_element", &module);
    get_blawn_context().add_builtin_function("__blawn_set_element__",
                                             blawn_set_element);
}

void builtins::create_string_type(llvm::LLVMContext& context,
                                  llvm::Module& module,
                                  llvm::IRBuilder<>& ir_builder) {
    std::string type_name = "struct.String";
    std::vector<llvm::Type*> fields;
    fields.push_back(ir_builder.getInt8PtrTy());  // string
    fields.push_back(ir_builder.getInt64Ty());    // size
    auto string_type = llvm::StructType::create(context, fields, type_name);
    get_blawn_context().register_element_name(type_name, "@string", 0);
    get_blawn_context().register_element_name(type_name, "@size", 1);
    std::vector<llvm::Type*> constructor_args;
    constructor_args.push_back(ir_builder.getInt8PtrTy());  // string
    constructor_args.push_back(ir_builder.getInt64Ty());    // length
    auto constructor_type = llvm::FunctionType::get(string_type->getPointerTo(),
                                                    constructor_args, false);
    llvm::Function::Create(constructor_type, llvm::Function::ExternalLinkage,
                           "string_constructor", &module);
    std::vector<llvm::Type*> append_method_args;
    append_method_args.push_back(string_type->getPointerTo());
    append_method_args.push_back(string_type->getPointerTo());
    auto append_method_type = llvm::FunctionType::get(
        ir_builder.getVoidTy(), append_method_args, false);
    auto append_method = llvm::Function::Create(append_method_type,
                                                llvm::Function::ExternalLinkage,
                                                "append_string", &module);
    std::map<std::string, llvm::Function*> methods;
    methods["append"] = append_method;
    get_blawn_context().add_builtin_class(type_name, methods);
    std::vector<llvm::Type*> print_args(1, string_type->getPointerTo());
    auto print_type =
        llvm::FunctionType::get(ir_builder.getVoidTy(), print_args, false);
    auto print = llvm::Function::Create(
        print_type, llvm::Function::ExternalLinkage, "print", &module);
    get_blawn_context().add_builtin_function("print", print);

    std::vector<llvm::Type*> to_char_ptr_args(1,string_type->getPointerTo());
    auto to_char_ptr_type = llvm::FunctionType::get(
        ir_builder.getInt8PtrTy(),
        to_char_ptr_args,false
        );
    auto to_char_ptr = llvm::Function::Create(
        to_char_ptr_type,llvm::Function::ExternalLinkage,"to_char_ptr",&module
    );
    get_blawn_context().add_builtin_function("to_char_ptr",to_char_ptr);

    std::vector<llvm::Type*> int_to_str_args(1, ir_builder.getInt64Ty());
    auto int_to_str_type = llvm::FunctionType::get(string_type->getPointerTo(),
                                                   int_to_str_args, false);
    auto int_to_str =
        llvm::Function::Create(int_to_str_type, llvm::Function::ExternalLinkage,
                               "int_to_str", &module);
    get_blawn_context().add_builtin_function("int_to_str", int_to_str);

    std::vector<llvm::Type*> float_to_str_args(1, ir_builder.getDoubleTy());
    auto float_to_str_type = llvm::FunctionType::get(
        string_type->getPointerTo(), float_to_str_args, false);
    auto float_to_str = llvm::Function::Create(float_to_str_type,
                                               llvm::Function::ExternalLinkage,
                                               "float_to_str", &module);
    get_blawn_context().add_builtin_function("float_to_str", float_to_str);
}
