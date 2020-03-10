%{
#include <string>
#include <algorithm>
#include "parser.hpp"
#include "../src/compiler/parser/scanner.hpp"
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

COMMENT             \/\/.*\n
STRING_LITERAL      \"[^\"]*\"
INT_LITERAL         [0-9]+
FLOAT_LITERAL       [0-9]+\.[0-9]*
USE                 use

OP_EQUAL    ==
OP_NOT_EQUAL \!=
OP_MORE_EQUAL >=
OP_LESS_EQUAL <=
OP_MORE     >
OP_LESS     <
OP_AND      and
OP_OR       or
EQUAL       =
ARROW       <-
PLUS        \+
MINUS       -
ASTERISK    \*
SLASH       \/
DOT_IDENTIFIER \.[a-zA-Z_][0-9a-zA-Z_]*
COLON       \:
SEMICOLON   ;
COMMA       ,

IF          if
ELSE        else
FOR         for
IN          in
WHILE       while
GLOBAL      global
IMPORT      import
FUNCTION_DEFINITION     function[ \t]+[a-zA-Z_][0-9a-zA-Z_]*
METHOD_DEFINITION       @function[ \t]+[a-zA-Z_][0-9a-zA-Z_]*
CLASS_DEFINITION        class[ \t]+[a-zA-Z_][0-9a-zA-Z_]*
RETURN                  return
LEFT_PARENTHESIS  \(
RIGHT_PARENTHESIS \)
LEFT_BRACKET    \[
RIGHT_BRACKET   \]
LEFT_CURLY_BRACE \{
RIGHT_CURLY_BRACE \}

CALL        .+\(.*\)
MEMBER_IDENTIFIER @[a-zA-Z_][0-9a-zA-Z_]* 
IDENTIFIER  [a-zA-Z_][0-9a-zA-Z_]*
EOL                 \n|\r\n

%%

^[ \t]*\n {loc->lines();driver->ast_builder->count_line_number();}
^[ \t]*\r\n {loc->lines();driver->ast_builder->count_line_number();}
[ \t] {}
{COMMENT} {loc->lines();driver->ast_builder->count_line_number();}
{STRING_LITERAL} {
    std::string text = yytext;
    text = text.substr(1,text.size()-2);
    lval->build<std::string>() = text;
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
{DOT_IDENTIFIER} {
    std::string text = yytext;
    text = text.substr(1,text.size()-1);
    lval->build<std::string>() = text;
    return Blawn::Parser::token::DOT_IDENTIFIER;
}
{ASTERISK} {
    return Blawn::Parser::token::ASTERISK;
}
{SLASH} {
    return Blawn::Parser::token::SLASH;
}
{PLUS} {
    return Blawn::Parser::token::PLUS;
}
{MINUS} {
    return Blawn::Parser::token::MINUS;
}
{EQUAL} {
    return Blawn::Parser::token::EQUAL;
}
{ARROW} {
    return Blawn::Parser::token::ARROW;
}
{OP_EQUAL} {
    return Blawn::Parser::token::OP_EQUAL;
}
{OP_NOT_EQUAL} {
    return Blawn::Parser::token::OP_NOT_EQUAL;
}
{OP_MORE_EQUAL} {
    return Blawn::Parser::token::OP_MORE_EQUAL;
}
{OP_LESS_EQUAL} {
    return Blawn::Parser::token::OP_LESS_EQUAL;
}
{OP_MORE} {
    return Blawn::Parser::token::OP_MORE;
}
{OP_LESS} {
    return Blawn::Parser::token::OP_LESS;
}
{OP_AND} {
    return Blawn::Parser::token::OP_AND;
}
{OP_OR} {
    return Blawn::Parser::token::OP_OR;
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
{LEFT_BRACKET} {
    return Blawn::Parser::token::LEFT_BRACKET;
}
{RIGHT_BRACKET} {
    return Blawn::Parser::token::RIGHT_BRACKET;
}
{LEFT_CURLY_BRACE} {
    return Blawn::Parser::token::LEFT_CURLY_BRACE;
}
{RIGHT_CURLY_BRACE} {
    return Blawn::Parser::token::RIGHT_CURLY_BRACE;
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
{IN} {
    return Blawn::Parser::token::IN;
}
{WHILE} {
    return Blawn::Parser::token::WHILE;
}
{GLOBAL} {
    return Blawn::Parser::token::GLOBAL;
}
{IMPORT} {
    return Blawn::Parser::token::IMPORT;
}
{METHOD_DEFINITION} {
    std::string definition = yytext;
    std::string reversed;
    std::reverse_copy(definition.begin(),definition.end(),std::back_inserter(reversed));
    int index = definition.size() - reversed.find(" ");
    definition.erase(0,index);
    lval->build<std::string>() = definition;
    
    return Blawn::Parser::token::METHOD_DEFINITION;
}
{FUNCTION_DEFINITION} {
    std::string definition = yytext;
    std::string reversed;
    std::reverse_copy(definition.begin(),definition.end(),std::back_inserter(reversed));
    int index = definition.size() - reversed.find(" ");
    definition.erase(0,index);
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
    driver->ast_builder->count_line_number();
    return Blawn::Parser::token::EOL;
}
<<EOF>> {return 0;}
%%