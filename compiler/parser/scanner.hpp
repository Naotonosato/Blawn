#ifndef __BlawnSCANNER_HPP__
#define __BlawnSCANNER_HPP__ 1

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif
#include <string>
#include "driver.hpp"
#include "parser.tab.hh"
#include "location.hh"

namespace Blawn{

class Scanner : public yyFlexLexer{
public:
   Driver *driver;
   Scanner(std::istream *in,Driver *driver) : yyFlexLexer(in),driver(driver)
   {
   };
   virtual ~Scanner() {
   };

   //get rid of override virtual function warning
   using FlexLexer::yylex;

   virtual
   int yylex( Blawn::Parser::semantic_type * const lval, 
              Blawn::Parser::location_type *location );
   // YY_DECL defined in lexer.l
   // Method body created by flex in lexer.yy.cc


private:
   /* yyval ptr */
   Blawn::Parser::semantic_type *yylval = nullptr;
};

} /* end namespace Blawn */

#endif /* END __BlawnSCANNER_HPP__ */
