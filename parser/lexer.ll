%{
#include <string>
#include <algorithm>
#include "parser.tab.hh"
#include "scanner.hpp"
#undef  YY_DECL
#define YY_DECL int Blawn::Scanner::yylex( Blawn::Parser::semantic_type * const lval, Blawn::Parser::location_type *loc )
#define yyterminate() return Blawn::Parser::token::END;
#define YY_NO_UNISTD_H
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);
%}

%option yyclass="Blawn::Scanner"
%option noyywrap
%option noinput
%option nounput
%option c++

COMMENT             !.*\n
STRING_LITERAL      \".*\"
INT_LITERAL         [0-9]+
FLOAT_LITERAL       [0-9]+\.[0-9]*
USE                 use
DOT         \.
EQUAL       =
PLUS        \+
MINUS       -
ASTERISK    \*
SLASH       \/
COLON       \:
SEMICOLON   ;
COMMA       ,

IF          if
ELSE        else
FOR         for
WHILE       while
FUNCTION_DEFINITION     function[ \t]+[a-zA-Z_][0-9a-zA-Z_]*
METHOD_DEFINITION       @function[ \t]+[a-zA-Z_][0-9a-zA-Z_]*
CLASS_DEFINITION        class[ \t]+[a-zA-Z_][0-9a-zA-Z_]*
RETURN                  return
LEFT_PARENTHESIS        \(
RIGHT_PARENTHESIS       \)

CALL        .+\(.*\)
C_FUNCTION  c\.[a-zA-Z_][0-9a-zA-Z_]*
MEMBER_IDENTIFIER @[a-zA-Z_][0-9a-zA-Z_]*
IDENTIFIER  [a-zA-Z_][0-9a-zA-Z_]*
EOL                 \n


%%

^[ \t]*\r\n {loc->lines();}
[ \t] {}
{COMMENT} {}
{STRING_LITERAL} {
    lval->build<std::string>() = yytext;
    return Blawn::Parser::token::STRING_LITERAL;
}
{INT_LITERAL} {
    lval->build<long long>() = std::stoll(yytext);
    return Blawn::Parser::token::INT_LITERAL;
}
{FLOAT_LITERAL} {
    lval->build<double>() = std::stod(yytext);
    return Blawn::Parser::token::FLOAT_LITERAL;
}
{USE} {
    return Blawn::Parser::token::USE;
}
{DOT} {
    return Blawn::Parser::token::DOT;
}
{EQUAL} {
    return Blawn::Parser::token::EQUAL;
}
{PLUS} {
    return Blawn::Parser::token::PLUS;
}
{MINUS} {
    return Blawn::Parser::token::MINUS;
}
{ASTERISK} {
    return Blawn::Parser::token::ASTERISK;
}
{SLASH} {
    return Blawn::Parser::token::SLASH;
}
{COLON} {
    return Blawn::Parser::token::COLON;
}
{SEMICOLON} {
    return Blawn::Parser::token::SEMICOLON;
}
{COMMA} {
    return Blawn::Parser::token::COMMA;
}
{LEFT_PARENTHESIS} {
    return Blawn::Parser::token::LEFT_PARENTHESIS;
}
{RIGHT_PARENTHESIS} {
    return Blawn::Parser::token::RIGHT_PARENTHESIS;
}
{IF} {
    return Blawn::Parser::token::IF;
}
{ELSE} {
    return Blawn::Parser::token::ELSE;
}
{FOR} {
    return Blawn::Parser::token::FOR;
}
{WHILE} {
    return Blawn::Parser::token::WHILE;
}
{METHOD_DEFINITION} {
    std::string definition = yytext;
    std::string reversed;
    std::reverse_copy(definition.begin(),definition.end(),std::back_inserter(reversed));
    int index = definition.size() - reversed.find(" ");
    definition.erase(0,index);
    driver->ast_generator->into_namespace(definition);
    driver->ast_generator->book_function(definition);
    lval->build<std::string>() = definition;
    
    return Blawn::Parser::token::METHOD_DEFINITION;
}
{FUNCTION_DEFINITION} {
    std::string definition = yytext;
    std::string reversed;
    std::reverse_copy(definition.begin(),definition.end(),std::back_inserter(reversed));
    int index = definition.size() - reversed.find(" ");
    definition.erase(0,index);
    driver->ast_generator->into_namespace(definition);
    driver->ast_generator->book_function(definition);
    lval->build<std::string>() = definition;
    
    return Blawn::Parser::token::FUNCTION_DEFINITION;
}
{CLASS_DEFINITION} {
    std::string definition = yytext;
    std::string reversed;
    std::reverse_copy(definition.begin(),definition.end(),std::back_inserter(reversed));
    int index = definition.size() - reversed.find(" ");
    definition.erase(0,index);
    driver->ast_generator->into_namespace(definition);
    lval->build<std::string>() = definition;
    return Blawn::Parser::token::CLASS_DEFINITION;
}
{RETURN} {
    return Blawn::Parser::token::RETURN;
}
{C_FUNCTION} {
    lval->build<std::string>() = yytext;
    return Blawn::Parser::token::C_FUNCTION;
}
{MEMBER_IDENTIFIER} {
    lval->build<std::string>() = yytext;
    return Blawn::Parser::token::MEMBER_IDENTIFIER;
}
{IDENTIFIER} {
    lval->build<std::string>() = yytext;
    return Blawn::Parser::token::IDENTIFIER;
}
{EOL} {
    loc->lines();
    return Blawn::Parser::token::EOL;
}
<<EOF>> {return 0;}
%%