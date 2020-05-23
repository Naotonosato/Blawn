#pragma once

#if !defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif
#include <string>
#include "driver.hpp"
#include "location.hh"
#include "parser.hpp"

namespace blawn
{
struct DeclarationInfo
{
    std::string name;
    std::vector<std::string> argument_names;
    DeclarationInfo() = default;
    DeclarationInfo(std::string name, std::vector<std::string> &&argument_names)
        : name(name), argument_names(std::move(argument_names))
    {
    }
};

class Scanner : public yyFlexLexer
{
    public:
    Driver &driver;
    Scanner(std::istream *in, Driver &driver)
        : yyFlexLexer(in), driver(driver){};

    using FlexLexer::yylex;

    virtual int yylex(blawn::Parser::semantic_type *const lval,
                      blawn::Parser::location_type *location);

    private:
    blawn::Parser::semantic_type *yylval = nullptr;
};

}  // namespace blawn
