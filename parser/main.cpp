#include <iostream>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/raw_ostream.h>
#include "driver.hpp"
#include "../ast_generator/ast_generator.hpp"

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


    std::shared_ptr<ASTGenerator> ast_generator(new ASTGenerator(module,ir_builder,context));
    Blawn::Driver* driver = new Blawn::Driver(ast_generator);
    std::cout << "start compile.\n";
    driver->parse("../test/test_parsing/test1.blawn");
    std::cout << "done.\n";
    module->print(llvm::outs(),nullptr);
    return 0;
}