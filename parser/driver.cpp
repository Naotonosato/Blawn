#include <cctype>
#include <fstream>
#include <cassert>

#include "driver.hpp"

Blawn::Driver::~Driver()
{
   delete(scanner);
   scanner = nullptr;
   delete(parser);
   parser = nullptr;
}

void 
Blawn::Driver::parse( const char * const filename )
{
   assert( filename != nullptr );
   std::ifstream in_file( filename );
   if( ! in_file.good() )
   {
       exit( EXIT_FAILURE );
   }
   parse_helper( in_file );
   return;
}

void
Blawn::Driver::parse( std::istream &stream )
{
   if( ! stream.good()  && stream.eof() )
   {
       return;
   }
   //else
   parse_helper( stream ); 
   return;
}


void 
Blawn::Driver::parse_helper( std::istream &stream )
{
   
   delete(scanner);
   try
   {
      scanner = new Blawn::Scanner( &stream );
   }
   catch( std::bad_alloc &ba )
   {
      std::cerr << "Failed to allocate scanner: (" <<
         ba.what() << "), exiting!!\n";
      exit( EXIT_FAILURE );
   }
   
   delete(parser); 
   try
   {
      parser = new Blawn::Parser( (*scanner) /* scanner */, 
                                  (*this) /* driver */ );
   }
   catch( std::bad_alloc &ba )
   {
      std::cerr << "Failed to allocate parser: (" << 
         ba.what() << "), exiting!!\n";
      exit( EXIT_FAILURE );
   }
   const int accept( 0 );
   if( parser->parse() != accept )
   {
      std::cerr 
      << "\033[38;2;0;0;255m"
      << "YOU LOSE\033[0m\n" << "構文解析器の勝ち！\n"
      << "何で負けたか、明日まで考えといてください。\n"
      <<"そしたら何かが見えてくるはずです。\n"
      << "ほな、いただきます!!\n";
   }
   return;
}

