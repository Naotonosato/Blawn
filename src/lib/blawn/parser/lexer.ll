%{
#include <string>
#include <algorithm>
#include "parser.hpp"
#include "include/blawn/parser/scanner.hpp"
#undef  YY_DECL
#define YY_DECL int blawn::Scanner::yylex( blawn::Parser::semantic_type * const lval, blawn::Parser::location_type *loc )
#define yyterminate() return blawn::Parser::token::END;
#define YY_NO_UNISTD_H
#define YY_USER_ACTION loc->step(); loc->columns(yyleng); driver.ast_builder->set_token(std::string(yytext)); driver.ast_builder->count_token_index(yyleng);


std::unique_ptr<blawn::DeclarationInfo> to_declaration_info(std::string token_text)
{
    //"function func  (a,b , c  )"

    char last_char = '\0';
    std::string::size_type identifier_start = 0;

    for (auto c:token_text)
    {
        if (last_char == ' ' and c != ' ') break;
        last_char = c;
        identifier_start += 1;
    }

    std::string::size_type identifier_end = token_text.find("(",identifier_start);
    std::string identifier = token_text.substr(identifier_start,identifier_end - identifier_start);
    //identifier = "func"

    std::string without_identifier = token_text.substr(identifier_end);
    std::string current_argument;
    std::vector<std::string> arguments;
    
    for (auto c:without_identifier)
    {
        if (c == ' ' or c == '(') continue;
        if (c == ')') break;
        if (c == ',')
        {
            arguments.push_back(current_argument);
            current_argument = "";
            continue;
        }
        current_argument += c;
    }
    return std::make_unique<blawn::DeclarationInfo>(identifier, std::move(arguments));
}

%}

%option yyclass="blawn::Scanner"
%option noyywrap
%option noinput
%option nounput
%option c++

COMMENT             \/\/.*\n
STRING_LITERAL      \"[^\"]*\"
INT_LITERAL         [0-9]+
FLOAT_LITERAL       [0-9]+\.[0-9]*
LAZY                lazy
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
RETURN                  return
FUNCTION_DEFINITION function[ \t]+[a-zA-Z_][0-9a-zA-Z_]*[ \t]*\(([a-zA-Z_][0-9a-zA-Z_]*)*([ \t]*,[ \t]*[a-zA-Z_][0-9a-zA-Z_]*[ \t]*)*\)
METHOD_DEFINITION   @function[ \t]+[a-zA-Z_][0-9a-zA-Z_]*[ \t]*\(([a-zA-Z_][0-9a-zA-Z_]*)*([ \t]*,[ \t]*[a-zA-Z_][0-9a-zA-Z_]*[ \t]*)*\)
CLASS_DEFINITION  class[ \t]+[a-zA-Z_][0-9a-zA-Z_]*[ \t]*\(([a-zA-Z_][0-9a-zA-Z_]*)*([ \t]*,[ \t]*[a-zA-Z_][0-9a-zA-Z_]*[ \t]*)*\)

LEFT_PARENTHESIS  \(
LEFT_PARENTHESIS_AND_EOL \(\n
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

^[ \t]*\n {loc->lines();driver.ast_builder->count_line_number();}
^[ \t]*\r\n {loc->lines();driver.ast_builder->count_line_number();}
{EOL} {
    loc->lines();
    driver.ast_builder->count_line_number();
    return blawn::Parser::token::EOL;
}
{COMMENT} {loc->lines();driver.ast_builder->count_line_number();}
{STRING_LITERAL} {
    std::string text = yytext;
    text = text.substr(1,text.size()-2);
    lval->build<std::string>() = text;
    return blawn::Parser::token::STRING_LITERAL;
}
{INT_LITERAL} {
    lval->build<long long>() = std::stoll(yytext);
    return blawn::Parser::token::INT_LITERAL;
}
{FLOAT_LITERAL} {
    lval->build<double>() = std::stod(yytext);
    return blawn::Parser::token::FLOAT_LITERAL;
}
{LAZY} {
    return blawn::Parser::token::LAZY;
}
{USE} {
    return blawn::Parser::token::USE;
}
{DOT_IDENTIFIER} {
    std::string text = yytext;
    text = text.substr(1,text.size()-1);
    lval->build<std::string>() = text;
    return blawn::Parser::token::DOT_IDENTIFIER;
}
{ASTERISK} {
    return blawn::Parser::token::ASTERISK;
}
{SLASH} {
    return blawn::Parser::token::SLASH;
}
{PLUS} {
    return blawn::Parser::token::PLUS;
}
{MINUS} {
    return blawn::Parser::token::MINUS;
}
{EQUAL} {
    return blawn::Parser::token::EQUAL;
}
{ARROW} {
    return blawn::Parser::token::ARROW;
}
{OP_EQUAL} {
    return blawn::Parser::token::OP_EQUAL;
}
{OP_NOT_EQUAL} {
    return blawn::Parser::token::OP_NOT_EQUAL;
}
{OP_MORE_EQUAL} {
    return blawn::Parser::token::OP_MORE_EQUAL;
}
{OP_LESS_EQUAL} {
    return blawn::Parser::token::OP_LESS_EQUAL;
}
{OP_MORE} {
    return blawn::Parser::token::OP_MORE;
}
{OP_LESS} {
    return blawn::Parser::token::OP_LESS;
}
{OP_AND} {
    return blawn::Parser::token::OP_AND;
}
{OP_OR} {
    return blawn::Parser::token::OP_OR;
}

{METHOD_DEFINITION} {
    lval->build<std::unique_ptr<blawn::DeclarationInfo>>() = to_declaration_info(yytext);
    
    return blawn::Parser::token::METHOD_DEFINITION;
}
{FUNCTION_DEFINITION} {
    lval->build<std::unique_ptr<blawn::DeclarationInfo>>() = to_declaration_info(yytext);
    return blawn::Parser::token::FUNCTION_DEFINITION;
}
{CLASS_DEFINITION} {
    lval->build<std::unique_ptr<blawn::DeclarationInfo>>() = to_declaration_info(yytext);
    return blawn::Parser::token::CLASS_DEFINITION;
}

{COLON} {
    return blawn::Parser::token::COLON;
}
{SEMICOLON} {
    return blawn::Parser::token::SEMICOLON;
}
{COMMA} {
    return blawn::Parser::token::COMMA;
}
{LEFT_PARENTHESIS} {
    return blawn::Parser::token::LEFT_PARENTHESIS;
}
{LEFT_PARENTHESIS_AND_EOL} {
    loc->lines();
    driver.ast_builder->count_line_number();
    return blawn::Parser::token::LEFT_PARENTHESIS_AND_EOL;
}
{RIGHT_PARENTHESIS} {
    return blawn::Parser::token::RIGHT_PARENTHESIS;
}
{LEFT_BRACKET} {
    return blawn::Parser::token::LEFT_BRACKET;
}
{RIGHT_BRACKET} {
    return blawn::Parser::token::RIGHT_BRACKET;
}
{LEFT_CURLY_BRACE} {
    return blawn::Parser::token::LEFT_CURLY_BRACE;
}
{RIGHT_CURLY_BRACE} {
    return blawn::Parser::token::RIGHT_CURLY_BRACE;
}
{IF} {
    return blawn::Parser::token::IF;
}
{ELSE} {
    return blawn::Parser::token::ELSE;
}
{FOR} {
    return blawn::Parser::token::FOR;
}
{IN} {
    return blawn::Parser::token::IN;
}
{WHILE} {
    return blawn::Parser::token::WHILE;
}
{GLOBAL} {
    return blawn::Parser::token::GLOBAL;
}
{IMPORT} {
    return blawn::Parser::token::IMPORT;
}

{RETURN} {
    return blawn::Parser::token::RETURN;
}

{MEMBER_IDENTIFIER} {
    lval->build<std::string>() = yytext;
    return blawn::Parser::token::MEMBER_IDENTIFIER;
}
{IDENTIFIER} {
    lval->build<std::string>() = yytext;
    return blawn::Parser::token::IDENTIFIER;
}
[ \t] {}
<<EOF>> {return 0;}
%%