#pragma once
#include <cstddef>
#include <istream>
#include <memory>
// #include "parser.tab.hh"
#include "include/blawn/parser/scanner.hpp"

namespace ast
{
class Builder;
class Node;
}  // namespace ast

namespace blawn
{
class Driver
{
    public:
    std::shared_ptr<ast::Builder> ast_builder;

    public:
    Driver(std::shared_ptr<ast::Builder> ast_builder)
        : ast_builder(ast_builder){};
    void parse(const char* const filename);
    void parse(std::istream& iss);

    private:
    void parse_helper(std::istream& stream);
};

}  // namespace blawn
