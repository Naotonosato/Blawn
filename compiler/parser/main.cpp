#include <iostream>
#include <memory>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/Verifier.h>
#include "driver.hpp"
#include "../ast_generator/ast_generator.hpp"
#include "../builtins/builtins.hpp"

int main(int argc, char** argv)
{
    auto context = std::shared_ptr<llvm::LLVMContext>(new llvm::LLVMContext);
    std::shared_ptr<llvm::Module> module (new llvm::Module("Blawn",*context));
    auto ir_builder = std::shared_ptr<llvm::IRBuilder<>>(new llvm::IRBuilder<>(*context));
/*
    auto l = llvm::ConstantFP::get(context, llvm::APFloat(0.5));
    auto r = llvm::ConstantFP::get(context, llvm::APFloat(0.5));
    ir_builder.CreateFAdd(l,r,"a")->print(llvm::outs());
    module->print(llvm::outs(),nullptr);
*/
    /*
    auto *funcType = llvm::FunctionType::get(ir_builder->getInt64Ty(), false);
    auto *mainFunc = llvm::Function::Create(
        funcType, llvm::Function::ExternalLinkage, "main", module.get());
    auto *entrypoint = llvm::BasicBlock::Create(*context, "entrypoint", mainFunc);
    ir_builder->SetInsertPoint(entrypoint);
    auto l = llvm::ConstantFP::get(*context, llvm::APFloat(0.5));
    auto r = llvm::ConstantFP::get(*context, llvm::APFloat(0.5));
    ir_builder->CreateFAdd(l,r,"a");
    ir_builder->CreateRet(ir_builder->getInt64(0));
    */


    auto ast_generator = std::make_unique<ASTGenerator>(*module,*ir_builder,*context);
    Blawn::Driver* driver = new Blawn::Driver(std::move(ast_generator));
    driver->parse("../test/test_parsing/test1.blawn");
    auto zero = llvm::ConstantInt::get(*context, llvm::APInt(8,0));
    ir_builder->CreateRet(zero);
    builtins::load_builtins(*context,*module,"../builtins/builtins.ll");
    std::error_code error;
    llvm::raw_fd_ostream stream("result.ll",error,llvm::sys::fs::OpenFlags::F_None);
    module->print(stream,nullptr);
    llvm::verifyModule(*module,&llvm::outs());
    system("lli result.ll");
    return 0;
}