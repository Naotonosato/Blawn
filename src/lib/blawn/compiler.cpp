#include <string>
#include "include/ast/builder.hpp"
#include "include/blawn/parser/driver.hpp"
#include "include/mir/mir.hpp"
#include "include/blawn/module/module.hpp"
#include "include/blawn/visitors/ast_to_mir.hpp"
#include "include/blawn/visitors/mir_to_llvm_ir.hpp"
#include <lld/Common/Driver.h>

int get_compile_options(int argc, char** argv) { return 0; }

bool link(std::vector<std::string> arguments)
{
    std::vector<const char*> arguments_char_array(arguments.size());
    size_t idx = 0;
    for (auto& arg : arguments)
    {
        arguments_char_array[idx] = arg.c_str();
        idx += 1;
    }
    llvm::ArrayRef<const char*> lld_arguments(arguments_char_array);
    return lld::mach_o::link(lld_arguments, true);
}

// link({"-execute", "-lsystem",
//      "/Users/ueharanaoto/Desktop/Blawn/test/cpp.o"});

int compile(int argc, char** argv)
{
    auto filename = argv[1];
    auto module = std::make_shared<module::Module>(filename);
    auto ast_builder = std::make_shared<ast::Builder>(filename);
    blawn::Driver driver(ast_builder);
    driver.parse(filename);
    auto& ast = ast_builder->build();
    auto ast_to_mir_converter =
        utils::VisitorWrapper<converter::ast_to_mir::Converter>::create();
    auto mir = ast.accept(*ast_to_mir_converter);
    return 0;
}