#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/raw_ostream.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <memory>
#include <experimental/filesystem>
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "../builtins/builtins.hpp"
#include "../parser/driver.hpp"
#include "../ast_generator/ast_generator.hpp"
#include "../utils/utils.hpp"
#include "compiler.hpp"

using namespace std::experimental;

std::string self_app_path;

std::string abs(std::string path) { return self_app_path + "/" + path; }

std::vector<std::string> get_compile_commands(int argc, char** argv) {
    if (argc == 1) {
        std::cerr << "no input!" << std::endl;
        exit(1);
    }
    std::string filename = abs(argv[1]);
    std::string ir_filename =
        abs("tmp/" + utils::get_filename(argv[1]) + ".ll");
    bool is_link = false;
    std::string to_link;
    std::string output_filename = utils::get_filename(filename) + ".out";
    std::string arguments;
    const char* opstring = "l:o:a:";
    int opt;
    while ((opt = getopt(argc, argv, opstring)) != -1) {
        switch (opt) {
            case 'l':
                is_link = true;
                to_link = optarg;
                continue;
            case 'o':
                output_filename = optarg;
                continue;
            case 'a':
                arguments = optarg;
                continue;
            default:
                std::cerr << "invalid command." << std::endl;
                exit(1);
        }
    }
    std::vector<std::string> commands;
    std::string cmd1 = "llc -O3 " + ir_filename + " -o " +
                       abs("tmp/result.s");
    commands.push_back(cmd1.c_str());
    if (is_link) {
        commands.push_back("gcc -c " + abs("tmp/result.s") + " -o " +
                           abs("tmp/obj.o") + " -no-pie");
        std::string cmd =
            ("gcc -no-pie " + abs("tmp/obj.o") + " " + abs("data/builtins.o") +
             " " + to_link + " -o " + output_filename + " " + arguments);
        commands.push_back(cmd.c_str());
    } else {
        std::string cmd = "gcc " + arguments + " " + abs("tmp/result.s") + " " +
                          abs("data/builtins.o") + " -no-pie -o " +
                          output_filename;
        commands.push_back(cmd.c_str());
    }
    std::string cmd = ("./" + output_filename);
    commands.push_back(cmd.c_str());
    // commands.push_back("rm tmp/*.ll");
    commands.push_back("rm " + abs("tmp") + "/*.s");
    commands.push_back("rm " + abs("tmp") + "/*.blawn");
    commands.push_back("rm " + abs("tmp") + "/*.ll");
    if (is_link) commands.push_back("rm " + abs("tmp") + "/*.o");
    return commands;
}

std::vector<std::string> get_imports(std::string filename) {
    std::ifstream file(filename);
    std::string line;
    std::string source_code;
    while (getline(file, line)) source_code += line + "\n";
    std::string current_token;
    std::vector<std::string> tokens;
    for (auto& c : source_code) {
        if (c == ' ' || c == '\n' || c == '\r') {
            tokens.push_back(current_token);
            current_token = "";
            continue;
        }
        current_token += c;
    }
    std::string last_token;
    std::vector<std::string> imports;
    for (auto& token : tokens) {
        if (token == "") continue;
        if (last_token == "import" && token.front() == '"' &&
            token.back() == '"') {
            imports.push_back(token.substr(1, token.size() - 2));
        }
        last_token = token;
    }
    return imports;
}

int compile(int argc, char** argv) {
    if (argc == 1) {
        std::cerr << "no input file!" << std::endl;
        exit(1);
    }
    std::string filename = argv[1];
    char buf[1000];
    readlink("/proc/self/exe", buf, 1000);
    self_app_path = filesystem::absolute(buf).parent_path().string();
    std::string expanded_filename =
        abs("tmp/" + utils::get_filename(filename) + ".blawn");
    std::ofstream expand_file(expanded_filename);
    if (!expand_file) {
        std::cerr << "cannot open temporary file " << expanded_filename << std::endl;
        exit(1);
    }
    auto imports = get_imports(filename);
    int imported_line = 0;
    for (auto& name : imports) {
        std::ifstream file(abs(name));
        if (!file) {
            file = std::ifstream(name);
            if (!file) {
                std::cerr << "cannot open file " << name << std::endl;
                exit(1);
            }
        }
        std::string source_code;
        while (getline(file, source_code)) {
            expand_file << source_code << std::endl;
            imported_line += 1;
        }
    }

    std::ifstream source_file(filename);
    std::string source_code;
    while (getline(source_file, source_code)) {
        expand_file << source_code << std::endl;
        ;
    }

    auto context = std::shared_ptr<llvm::LLVMContext>(new llvm::LLVMContext);
    std::shared_ptr<llvm::Module> module(new llvm::Module("Blawn", *context));
    auto ir_builder =
        std::shared_ptr<llvm::IRBuilder<>>(new llvm::IRBuilder<>(*context));
    auto ast_generator = std::shared_ptr<ASTGenerator>(
        new ASTGenerator(*module, *ir_builder, *context, -imported_line));
    Blawn::Driver* driver = new Blawn::Driver(std::move(ast_generator));

    driver->parse(expanded_filename.c_str());

    auto zero = llvm::ConstantInt::get(*context, llvm::APInt(8, 0));
    ir_builder->CreateRet(zero);

    std::string output_filename =
        abs("tmp/" + utils::get_filename(filename) + ".ll");
    std::error_code error;
    llvm::raw_fd_ostream stream(output_filename.c_str(), error,
                                llvm::sys::fs::OpenFlags::F_None);
    module->print(stream, nullptr);

    auto commands = get_compile_commands(argc, argv);
    for (auto& command : commands) {
        bool is_failed = system(command.c_str());
        if (is_failed) {
            std::cout << "compilation failed.\n....Don't mind!" << std::endl;
            commands.push_back("rm " + abs("tmp") + "/*.s");
            commands.push_back("rm " + abs("tmp") + "/*.blawn");
            commands.push_back("rm " + abs("tmp") + "/*.ll");
            commands.push_back("rm " + abs("tmp") + "/*.o");
            return 1;
        }
    }
    return 0;
    // llvm::verifyModule(*module,&llvm::outs());
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
      std::cerr << "TheTargetMachine can't emit a file of this type" <<
    std::endl; return 1;
    }
    pass.run(*module);
    dest.flush();*/
}
