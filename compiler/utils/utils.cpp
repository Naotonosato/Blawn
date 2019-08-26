#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/DataLayout.h>
#include <llvm/IR/Type.h>
#include <llvm/Support/raw_ostream.h>
#include "utils.hpp"


std::string utils::to_string(llvm::Type* type)
{
    std::string str;
    llvm::raw_string_ostream rso(str);
    type->print(rso);
    return rso.str();
}

std::string utils::to_string(llvm::Value* value)
{
    std::string str;
    llvm::raw_string_ostream rso(str);
    value->print(rso);
    return rso.str();
}

uint64_t utils::get_sizeof(llvm::Type* type,llvm::Module& module)
{
    auto layout = llvm::DataLayout(&module);
    return layout.getTypeAllocSize(type);
}

llvm::Value* utils::malloc_value(llvm::Type* type,llvm::LLVMContext& context,llvm::Module& module,llvm::IRBuilder<>& ir_builder)
{
    auto malloc_func = module.getFunction("malloc");
    uint64_t size = get_sizeof(type,module);
    auto size_ir = llvm::ConstantInt::get(context, llvm::APInt(64,size));
    std::vector<llvm::Value*> arg(1,size_ir);
    auto pointer = ir_builder.CreateCall(malloc_func,arg);
    return ir_builder.CreateBitCast(pointer,type->getPointerTo());
}

llvm::Value* utils::free_value(llvm::Value* to_delete_ptr,llvm::Module& module,llvm::IRBuilder<>& ir_builder)
{
    auto free_func = module.getFunction("free");
    auto cast_inst = ir_builder.CreateBitCast(to_delete_ptr,ir_builder.getInt64Ty()->getPointerTo());
    std::vector<llvm::Value*> arg(1,cast_inst);
    return ir_builder.CreateCall(free_func,arg);
}