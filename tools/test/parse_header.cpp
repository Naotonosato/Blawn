#include <string>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/raw_ostream.h>

void parse_and_dump_ir(std::string filename, llvm::LLVMContext& context) {
    llvm::SMDiagnostic err;
    auto declarations_module = llvm::parseIRFile(filename, err, context);
    declarations_module->print(llvm::outs(), nullptr);
}

int main(int argc, char** argv) {
    llvm::LLVMContext context;
    parse_and_dump_ir(argv[0], context);
}