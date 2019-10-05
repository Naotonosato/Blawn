#include <iostream>
#include <memory>
#include <unistd.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/PassManager.h>
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include <llvm/IR/Verifier.h>
#include "driver.hpp"
#include "../ast_generator/ast_generator.hpp"
#include "../builtins/builtins.hpp"

std::vector<std::string> get_compile_commands(int argc,char**argv)
{
    if (argc == 1)
    {
        std::cerr << "no input!" << std::endl;
        exit(1);
    }
    std::string filename = argv[1];
    bool is_link = false;
    std::string to_link;
    std::string output = "result";
    const char* opstring = "l:o:";
    int opt;
    while ((opt = getopt(argc,argv,opstring)) != -1)
    {
        switch(opt)
        {
            case 'l':
                is_link = true;
                to_link = optarg;
                break;
            case 'o':
                output = optarg;
                break;
            default:
                std::cerr << "invalid command." << std::endl;
                exit(1);
        }
    }
    std::vector<std::string> commands;
    commands.push_back("./data/llc -O3 ./result.ll");
    if (is_link)
    {
        commands.push_back("gcc -c ./result.s -o tmp/obj.o -no-pie");
        std::string cmd = ("gcc -no-pie tmp/obj.o " + to_link + " -o " + output);
        commands.push_back(cmd.c_str());
    }else{
        commands.push_back("gcc ./result.s -no-pie -o result");
    }
    std::string do_cmds = ("./" + output);
    const char* do_cmd = ("./" + output).c_str();
    commands.push_back(do_cmd);
    return commands;
}

int main(int argc, char** argv)
{
    
    std::string filename = argv[1];
    auto context = std::shared_ptr<llvm::LLVMContext>(new llvm::LLVMContext);
    std::shared_ptr<llvm::Module> module (new llvm::Module("Blawn",*context));
    auto ir_builder = std::shared_ptr<llvm::IRBuilder<>>(new llvm::IRBuilder<>(*context));

    /* 
    llvm::InitializeNativeTarget();
    auto target_triple = llvm::sys::getDefaultTargetTriple();
    module->setTargetTriple(target_triple);
    std::string Error;
    auto target = llvm::TargetRegistry::lookupTarget(target_triple, Error);
    if (!target) 
    {
        std::cerr << "Error: " << Error << std::endl;
        exit(1);
    }
    auto CPU = "generic";
    auto features = "";

    llvm::TargetOptions opt;
    auto RM = llvm::Optional<llvm::Reloc::Model>();
    auto TargetMachine =
        target->createTargetMachine(target_triple, CPU, features, opt, RM);

    module->setDataLayout(TargetMachine->createDataLayout());
    
    */

    auto ast_generator = std::make_unique<ASTGenerator>(*module,*ir_builder,*context);
    Blawn::Driver* driver = new Blawn::Driver(std::move(ast_generator));
    driver->parse(filename.c_str());
    auto zero = llvm::ConstantInt::get(*context, llvm::APInt(8,0));
    ir_builder->CreateRet(zero);
    builtins::load_builtins(*context,*module,"./data/builtins.ll");
    
    std::error_code error;
    llvm::raw_fd_ostream stream("result.ll",error,llvm::sys::fs::OpenFlags::F_None);
    module->print(stream,nullptr);
    //llvm::verifyModule(*module,&llvm::outs());
    
    auto commands = get_compile_commands(argc,argv);
    for (auto& command:commands)
    {
        std::cout << "this command is being done >> " << command << std::endl;
        system(command.c_str());
    }
    /*
    std::string filename = "../test/test_parsing/test1.blawn";
    std::error_code error;
    llvm::raw_fd_ostream dest(filename,error,llvm::sys::fs::OpenFlags::F_None);
    if (error) 
    {
        std::cout << "Error: couldn't open file " << filename << std::endl;
        exit(1);
    }

    llvm::legacy::PassManager pass;
    auto file_type = llvm::TargetMachine::CGFT_ObjectFile;

    if (TargetMachine->addPassesToEmitFile(pass,dest,file_type)) {
      std::cerr << "TheTargetMachine can't emit a file of this type" << std::endl;
      return 1;
    }
    pass.run(*module);
    dest.flush();*/

    return 0;
}