#include "driver.hpp"
#include <cassert>
#include <cctype>
#include <fstream>
#include "../ast/node.hpp"

std::shared_ptr<ast::RootNode> blawn::Driver::parse(
    const char *const filename) {
    assert(filename != nullptr);
    std::ifstream stream(filename);
    if (!stream.good()) {
        exit(1);
    }
    return parse_helper(stream);
}

std::shared_ptr<ast::RootNode> blawn::Driver::parse(std::istream &stream) {
    if (!stream.good() && stream.eof()) {
        exit(1);
    }
    return parse_helper(stream);
}

std::shared_ptr<ast::RootNode> blawn::Driver::parse_helper(
    std::istream &stream) {
    auto scanner = blawn::Scanner(&stream, *this);
    auto parser = blawn::Parser(scanner, *this);
    const int accept(0);
    if (parser.parse() != accept) {
        std::cerr << "syntax error" << std::endl;
    }
    return ast_builder->get_root_node();
}
