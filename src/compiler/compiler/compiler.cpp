#include <string>
#include "../ast/builder.hpp"
#include "../parser/driver.hpp"
#include "../mir/mir/mir.hpp"
#include "../converter/ast_to_mir/converter.hpp"
#include "../converter/mir_to_llvm_ir/converter.hpp"
#include <lld/Common/Driver.h>

int get_compile_options(int argc, char** argv) { return 0; }

bool link(std::vector<std::string> arguments) {
    std::vector<const char*> arguments_char_array(arguments.size());
    size_t idx = 0;
    for (auto& arg : arguments) {
        arguments_char_array[idx] = arg.c_str();
        idx += 1;
    }
    llvm::ArrayRef<const char*> lld_arguments(arguments_char_array);
    return lld::mach_o::link(lld_arguments, true);
}

int compile(int argc, char** argv) {
    // link({"-execute", "-lsystem",
    //      "/Users/ueharanaoto/Desktop/Blawn/test/cpp.o"});
    auto ast_builder = std::shared_ptr<ast::Builder>(new ast::Builder());
    blawn::Driver driver(ast_builder);
    auto filename = argv[1];
    auto ast = driver.parse(filename);
    auto ast_to_mir_converter = converter::ast_to_mir::get_visitor();
    auto mir = ast_to_mir_converter(ast);
    // mir->accept()
    std::cout << mir << std::endl;
    return 0;
}