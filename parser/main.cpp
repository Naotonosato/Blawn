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
    llvm::LLVMContext context;
    std::shared_ptr<llvm::Module> module (new llvm::Module("Blawn",context));
    llvm::IRBuilder<> ir_builder(context);
    std::shared_ptr<ASTGenerator> ast_generator(new ASTGenerator(*module,ir_builder));
    Blawn::Driver* driver = new Blawn::Driver(ast_generator);
    std::cout << "start compile.\n";
    driver->parse("../test/test_parsing/test1.blawn");
    std::cout << "done.\n";
    module->print(llvm::outs(),nullptr);
    return 0;
}