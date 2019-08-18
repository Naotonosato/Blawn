%skeleton "lalr1.cc"
%require  "3.0"
%debug 

%defines 
%define api.namespace {Blawn}
%define parser_class_name {Parser}
%locations
%language "c++"

%code requires{
    #include <memory>
    #include <llvm/IR/IRBuilder.h>
    #include "../ast/node.hpp"
    #include "../ast_generator/ast_generator.hpp"
    //#include "../ast/node.hpp" 
 
    namespace Blawn {
        class Driver;
        class Scanner;
    }

    // The following definitions is missing when %locations isn't used
    # ifndef YY_NULLPTR
    #  if defined __cplusplus && 201103L <= __cplusplus
    #   define YY_NULLPTR nullptr
    #  else
    #   define YY_NULLPTR 0
    #  endif
    # endif

}

%parse-param { Scanner  &scanner  }
%parse-param { Driver  &driver  }

%code{
    #include <iostream>
    #include <cstdlib>
    #include <fstream>
    #include <memory>
    #include "driver.hpp"
    #undef yylex
    #define yylex scanner.yylex
}

%define api.value.type variant
%define parse.assert
%token END 0 "end of file" 
%token <std::string> FUNCTION_DEFINITION
%token <std::string> CLASS_DEFINITION
%token  RETURN
%token <std::string> C_FUNCTION
%token <std::string> MEMBER_IDENTIFIER
%token <std::string> IDENTIFIER
%right EQUAL
%left PLUS MINUS
%left ASTERISK SLASH
%token   USE
        COLON
        SEMICOLON
        COMMA
        LEFT_PARENTHESIS
        RIGHT_PARENTHESIS
        IF
        ELSE
        FOR
        WHILE
        EOL
%token <long long> INT_LITERAL
%token <double> FLOAT_LITERAL
%token <std::string> STRING_LITERAL
%type <std::vector<std::shared_ptr<Node>>> block
%type <std::vector<std::shared_ptr<Node>>> lines
%type <std::shared_ptr<Node>> line
%type <std::shared_ptr<Node>> line_content
%type <std::shared_ptr<Node>> definition
%type <std::shared_ptr<Node>> assign_variable
%type <std::shared_ptr<Node>> function_definition
%type <std::shared_ptr<Node>> class_definition
%type <std::vector<std::shared_ptr<Node>>> members_definition
%type <std::vector<std::string>> definition_arguments
%type <std::vector<std::shared_ptr<Node>>> expressions
%type <std::shared_ptr<Node>> expression
%type <std::shared_ptr<Node>> function_call
%type <std::shared_ptr<Node>> monomial
%type <std::shared_ptr<Node>> variable

/*std::vector<Type> members_type;
        std::unique_ptr<Type> type = std::make_shared<Type>("FLOAT",members_type);
        $$ = std::unique_ptr<Node>(new Node(type));*/
%%
program: 
    block
    {
        driver.ast_generator->break_out_of_namespace();
        for (auto &node:$1)
        {
            node->generate();
        }
    };
block:
    lines
    {
        $$ = std::move($1);
    };
lines:
    line
    {
        $$.push_back(std::move($1));
    }
    |lines line
    {
        $$ = std::move($1);
        $$.push_back($2);
    };
line:
    line_content EOL
    {
        $$ = std::move($1);
    }
    |line_content END
    {
        $$ = std::move($1);
    };
line_content:
    expression
    {
        $$ = std::move($1);
    }
    |definition
    {
        $$ = std::move($1);
    };
definition:
    function_definition
    {
        $$ = std::move($1);
    }
    |class_definition
    {
        $$ = std::move($1);
    };
function_definition:
    FUNCTION_DEFINITION LEFT_PARENTHESIS definition_arguments RIGHT_PARENTHESIS EOL lines RETURN expression
    {
        $$ = driver.ast_generator->book_function($1,std::move($3),std::move($6),std::move($8));
        driver.ast_generator->break_out_of_namespace();
    };
class_definition:
    CLASS_DEFINITION LEFT_PARENTHESIS definition_arguments RIGHT_PARENTHESIS EOL LEFT_PARENTHESIS EOL members_definition block RIGHT_PARENTHESIS
    {
        $$ = std::move(driver.ast_generator->add_class($1,$3,$8,$9));
        driver.ast_generator->break_out_of_namespace();
    };
members_definition:
    MEMBER_IDENTIFIER EQUAL expression EOL
    {
        $$.push_back(driver.ast_generator->assign($1,std::move($3)));
    }
    |members_definition MEMBER_IDENTIFIER EQUAL expression EOL
    {
        $$ = std::move($1);
        $$.push_back(driver.ast_generator->assign($2,std::move($4)));
    };
definition_arguments:
    IDENTIFIER
    {
        $$.push_back($1);
        driver.ast_generator->add_argument($1);
    }
    |definition_arguments COMMA IDENTIFIER
    {
        $$ = std::move($1);
        $$.push_back($3);
        driver.ast_generator->add_argument($3);
    };
expressions:
    expression
    {
        $$.push_back(std::move($1));
    }
    |expressions COMMA expression
    {
        $$ = std::move($1);
        $$.push_back(std::move($3));
    };
expression:
    IF expression EOL block
    {
        $$ = std::shared_ptr<Node>(new Node(driver.ast_generator->ir_generator));
    }
    |monomial
    {
        $$ = std::move($1);
    }
    |assign_variable
    {
        $$ = $1;
    }
    |expression PLUS expression
    {
        $$ = driver.ast_generator->attach_operator(std::move($1),std::move($3),"+");
    }
    |expression MINUS expression
    {
        $$ = driver.ast_generator->attach_operator(std::move($1),std::move($3),"-");
    }
    |expression ASTERISK expression
    {
        $$ = driver.ast_generator->attach_operator(std::move($1),std::move($3),"*");
    }
    |expression SLASH expression
    {
        $$ = driver.ast_generator->attach_operator(std::move($1),std::move($3),"/");
    };
assign_variable:
    IDENTIFIER EQUAL expression
    {
        $$ = driver.ast_generator->assign($1,std::move($3));
        //std::cout << "new variable:" << std::move($1) <<"  type:" << (type->type_name) << "\n";
    };
monomial:
    function_call
    {
        $$ = $1;
    }
    |FLOAT_LITERAL
    {
        $$ = driver.ast_generator->create_float($1);
    }
    |INT_LITERAL
    { 
        $$ = driver.ast_generator->create_interger($1);
    }
    |variable
    {
        $$ = std::move($1);
    };
function_call:
    IDENTIFIER LEFT_PARENTHESIS expressions RIGHT_PARENTHESIS
    {
        $$ = driver.ast_generator->create_call($1,std::move($3));
    };
variable:
    IDENTIFIER
    {
        $$ = driver.ast_generator->get_named_value($1);
    };
%%

void Blawn::Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
} 