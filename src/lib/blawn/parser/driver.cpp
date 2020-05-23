#include "include/blawn/parser/driver.hpp"
#include <cassert>
#include <cctype>
#include <fstream>
#include "include/ast/node.hpp"

void blawn::Driver::parse(const char *const filename)
{
    assert(filename != nullptr);
    std::ifstream stream(filename);
    if (!stream.good())
    {
        exit(1);
    }
    parse_helper(stream);
}

void blawn::Driver::parse(std::istream &stream)
{
    if (!stream.good() && stream.eof())
    {
        exit(1);
    }
    parse_helper(stream);
}

void blawn::Driver::parse_helper(std::istream &stream)
{
    auto scanner = blawn::Scanner(&stream, *this);
    auto parser = blawn::Parser(scanner, *this);
    const int accept(0);
    if (parser.parse() != accept)
    {
        std::cerr << "syntax error" << std::endl;
    }
}
