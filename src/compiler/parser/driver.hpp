#pragma once
#include <cstddef>
#include <istream>
#include <memory>
// #include "parser.tab.hh"
#include "scanner.hpp"

namespace ast {
class Builder;
class Node;
}  // namespace ast

namespace blawn {

class Driver {
    public:
    std::shared_ptr<ast::Builder> ast_builder;
    Driver(std::shared_ptr<ast::Builder> ast_builder)
        : ast_builder(ast_builder){};
    std::shared_ptr<ast::RootNode> parse(const char *const filename);
    std::shared_ptr<ast::RootNode> parse(std::istream &iss);

    private:
    std::shared_ptr<ast::RootNode> parse_helper(std::istream &stream);
};

}  // namespace blawn
