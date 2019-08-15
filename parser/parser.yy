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
%token <std::string> IDENTIFIER
%token  EQUAL
        PLUS
        MINUS
        ASTERISK
        SLASH
        USE
        COLON
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
%type <std::unique_ptr<Node>> class_definition
%type <std::vector<std::string>> definition_arguments
%type <std::vector<std::shared_ptr<Node>>> expressions
%type <std::shared_ptr<Node>> expression
%type <std::shared_ptr<Node>> term
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
        $$.push_back(std::move($2));
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
    definition
    {
        $$ = std::move($1);
    }
    |expression
    {
        $$ = std::move($1);
    };
definition:
    assign_variable
    {
        $$ = std::move($1);
    }
    |function_definition
    {
        $$ = std::move($1);
    }
    |class_definition
    {
        $$ = std::move($1);
    };
assign_variable:
    IDENTIFIER EQUAL expression
    {
        $$ = driver.ast_generator->assign($1,std::move($3));
        //std::cout << "new variable:" << std::move($1) <<"  type:" << (type->type_name) << "\n";
    };
function_definition:
    FUNCTION_DEFINITION LEFT_PARENTHESIS definition_arguments RIGHT_PARENTHESIS EOL block RETURN expression
    {
        $$ = driver.ast_generator->book_function($1,std::move($3),std::move($6),std::move($8));
        //driver.ast_generator->into_namespace($1);
        driver.ast_generator->break_out_of_namespace();
    };
class_definition:
    CLASS_DEFINITION EOL block class_definition_end
    {
        driver.ast_generator->into_namespace($1);
        $$ = std::unique_ptr<Node>(new Node(*driver.ast_generator->ir_generator));
        driver.ast_generator->break_out_of_namespace();
    };
class_definition_end:
    COLON;    
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
    expression PLUS term
    {
        $$ = driver.ast_generator->attach_operator(std::move($1),std::move($3),"+");
    }
    |expression MINUS term
    {
        $$ = driver.ast_generator->attach_operator(std::move($1),std::move($3),"-");
    }
    |term
    {
        $$ = std::move($1);
    }
    |function_call
    {
        $$ = std::move($1);
    };
term:
    monomial
    {
        $$ = std::move($1);
    }
    |term ASTERISK monomial
    {
      $$ = driver.ast_generator->attach_operator(std::move($1),std::move($3),"*");
    }
    |term SLASH monomial
    {
       $$ = driver.ast_generator->attach_operator(std::move($1),std::move($3),"/");
    };
function_call:
    IDENTIFIER LEFT_PARENTHESIS expressions RIGHT_PARENTHESIS
    {
        $$ = driver.ast_generator->call_function($1,std::move($3));
    };
monomial:
    FLOAT_LITERAL
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
variable:
    IDENTIFIER
    {
        $$ = driver.ast_generator->get_named_value($1);
        //$$->generate();
        //std::unique_ptr<Node>(new Node(type));
        //$$ = std::unique_ptr<Node>(new Node());
    };


%%

void Blawn::Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
} 