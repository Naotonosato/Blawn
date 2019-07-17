#ifndef __BlawnDRIVER_HPP__
#define __BlawnDRIVER_HPP__ 1
#include <cstddef>
#include <istream>
#include "scanner.hpp"
#include "parser.tab.hh"
#include "../ast_generator/ast_generator.hpp"


namespace Blawn{

class Driver{
public:
   std::shared_ptr<ASTGenerator> ast_generator;
   Driver(std::shared_ptr<ASTGenerator> ast_generator):ast_generator(ast_generator){};
   virtual ~Driver();
   void parse( const char * const filename );
   void parse( std::istream &iss );
   Blawn::Scanner *scanner = nullptr;
private:

   void parse_helper( std::istream &stream );
   Blawn::Parser  *parser  = nullptr;
};

} 

#endif /* END __BlawnDRIVER_HPP__ */