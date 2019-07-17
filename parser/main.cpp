#include "../commons/commons.hpp"
#include "driver.hpp"
#include "../ast_generator/ast_generator.hpp"

int main(int argc, char** argv)
{
    llvm::LLVMContext context;
    std::shared_ptr<llvm::Module> module (new llvm::Module("Blawn",context));
    llvm::IRBuilder<> ir_builder(context);
    std::shared_ptr<ASTGenerator> ast_generator = std::make_shared<ASTGenerator>(*module,ir_builder);
    Blawn::Driver driver(ast_generator);
    std::cout << "start compile.\n";
    driver.parse("../test/test_parsing/test1.blawn");
    std::cout << "done.\n";
    return 0;
}