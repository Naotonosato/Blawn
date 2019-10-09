#pragma once

#if !defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif
#include <string>
#include "driver.hpp"
#include "location.hh"
#include "parser.tab.hh"

namespace Blawn {

class Scanner : public yyFlexLexer {
public:
    Driver *driver;
    Scanner(std::istream *in, Driver *driver)
        : yyFlexLexer(in), driver(driver){};
    virtual ~Scanner(){};

    using FlexLexer::yylex;

    virtual int yylex(Blawn::Parser::semantic_type *const lval,
                      Blawn::Parser::location_type *location);

private:
    Blawn::Parser::semantic_type *yylval = nullptr;
};

}  // namespace Blawn
