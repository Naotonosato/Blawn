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

%option debug
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
EOL                 \n
EQUAL       =
PLUS        \+
MINUS       -
ASTERISK    \*
SLASH       \/
COLON       \:
COMMA       ,

IF          if
ELSE        else
FOR         for
WHILE       while
FUNCTION_DEFINITION function[ \t]+[a-zA-Z_][0-9a-zA-Z_]*
CLASS_DEFINITION class[ \t]+[a-zA-Z_][0-9a-zA-Z_]*
RETURN      return
LEFT_PARENTHESIS \(
RIGHT_PARENTHESIS \)

CALL        .+\(.*\)
IDENTIFIER  [a-zA-Z_][0-9a-zA-Z_]*


%%

{COMMENT} {}
{STRING_LITERAL} {
    lval->build<std::string>() = yytext;
    return Blawn::Parser::token::STRING_LITERAL;
}
{EOL} {
    loc->lines();
    return Blawn::Parser::token::EOL;
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
{FUNCTION_DEFINITION} {
    std::string definition = yytext;
    std::string reversed;
    std::reverse_copy(definition.begin(),definition.end(),std::back_inserter(reversed));
    int index = definition.size() - reversed.find(" ");
    definition.erase(0,index);
    driver->ast_generator->into_namespace(definition);
    lval->build<std::string>() = definition;
    
    return Blawn::Parser::token::FUNCTION_DEFINITION;
}
{CLASS_DEFINITION} {
    std::string definition = yytext;
    std::string reversed;
    std::reverse_copy(definition.begin(),definition.end(),std::back_inserter(reversed));
    int index = definition.size() - reversed.find(" ");
    definition.erase(0,index);
    lval->build<std::string>() = definition;
    return Blawn::Parser::token::CLASS_DEFINITION;
}
{RETURN} {
    return Blawn::Parser::token::RETURN;
}
{IDENTIFIER} {
    lval->build<std::string>() = yytext;
    return Blawn::Parser::token::IDENTIFIER;
}

[ \t] {}
<<EOF>> {return 0;}
%%