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
    #include "../builtins/type.hpp"
    #include "../ast/node.hpp"
    #include "../ast_generator/ast_generator.hpp"
    //#include "../ast/node.hpp" 
 
    #include  <memory>
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
        COLON
        COMMA
        LEFT_PARENTHESIS
        RIGHT_PARENTHESIS
        IF
        ELSE
        FOR
        WHILE
        EOL
%token <int> INT_LITERAL
%token <double> FLOAT_LITERAL
%token <std::string> STRING_LITERAL
%type <std::vector<std::shared_ptr<Node>>> block
%type <std::vector<std::shared_ptr<Node>>> lines
%type <std::shared_ptr<Node>> line
%type <std::shared_ptr<Node>> line_content
%type <std::shared_ptr<Node>> definition
%type <std::shared_ptr<Node>> variable_definition
%type <std::shared_ptr<Node>> function_definition
%type <std::shared_ptr<Node>> class_definition
%type <std::vector<std::string>> definition_arguments
%type <std::vector<std::shared_ptr<Node>>> expressions
%type <std::shared_ptr<Node>> expression
%type <std::shared_ptr<Node>> term
%type <std::shared_ptr<Node>> function_call
%type <std::shared_ptr<Node>> monomial
%type <std::shared_ptr<VariableNode>> variable

/*std::vector<Type> members_type;
        std::shared_ptr<Type> type = std::make_shared<Type>("FLOAT",members_type);
        $$ = std::shared_ptr<Node>(new Node(type));*/
%%
program: 
    block
    {
        driver.ast_generator->break_out_of_namespace();
    };
block:
    lines
    {
        $$ = std::move($1);
    };
lines:
    line
    {
        $$.push_back($1);
    }
    |lines line
    {
        $$ = $1;
        $$.push_back($2);
    };
line:
    line_content EOL
    {
        $$ = $1;
    }
    |line_content END
    {
        $$ = $1;
    };
line_content:
    definition
    {
        $$ = $1;
    }
    |expression
    {
        $$ = $1;
    };
definition:
    variable_definition
    {
        $$ = $1;
    }
    |function_definition
    {
        $$ = $1;
    }
    |class_definition
    {
        $$ = $1;
    };
variable_definition:
    IDENTIFIER EQUAL expression
    {
        $$ = driver.ast_generator->add_variable($1,$3);
        //std::cout << "new variable:" << $1 <<"  type:" << (type->type_name) << "\n";
    };
function_definition:
    FUNCTION_DEFINITION LEFT_PARENTHESIS definition_arguments RIGHT_PARENTHESIS EOL block RETURN expression
    {
        driver.ast_generator->book_function($1,$3,$6);
        driver.ast_generator->into_namespace($1);
        $$ = std::shared_ptr<Node>(new Node(*driver.ast_generator->ir_generator));
        driver.ast_generator->break_out_of_namespace();
    }
    |FUNCTION_DEFINITION LEFT_PARENTHESIS definition_arguments RIGHT_PARENTHESIS EOL RETURN expression
    {
        driver.ast_generator->into_namespace($1);
        $$ = std::shared_ptr<Node>(new Node(*driver.ast_generator->ir_generator));
        driver.ast_generator->break_out_of_namespace();
    };
class_definition:
    CLASS_DEFINITION EOL block class_definition_end
    {
        driver.ast_generator->into_namespace($1);
        $$ = std::shared_ptr<Node>(new Node(*driver.ast_generator->ir_generator));
        driver.ast_generator->break_out_of_namespace();
    };
class_definition_end:
    COLON;    
definition_arguments:
    IDENTIFIER
    {
        $$.push_back($1);
    }
    |definition_arguments COMMA IDENTIFIER
    {
        $$ = $1;
        $$.push_back($3);
    };
expressions:
    expression
    {
        $$.push_back($1);
    }
    |expressions COMMA expression
    {
        $$ = $1;
        $$.push_back($3);
    };
expression:
    expression PLUS term
    {
        $$ = driver.ast_generator->attach_operator($1,$3,"+");
         $$->generate();
    }
    |expression MINUS term
    {
        $$ = driver.ast_generator->attach_operator($1,$3,"-");
    }
    |term
    {
        $$ = $1;
    }
    |function_call
    {
        $$ = $1;
    };
term:
    monomial
    {
        $$ = $1;
    }
    |term ASTERISK monomial
    {
      $$ = driver.ast_generator->attach_operator($1,$3,"*");
    }
    |term SLASH monomial
    {
       $$ = driver.ast_generator->attach_operator($1,$3,"/");
    };
function_call:
    IDENTIFIER LEFT_PARENTHESIS expressions RIGHT_PARENTHESIS
    {
        std::cout << "func call." << std::endl;
        $$ = driver.ast_generator->call_function($1,$3);
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
        $$ = $1;
    };
variable:
    IDENTIFIER
    {
        $$ = driver.ast_generator->get_variable($1);
        //$$->generate();
        //std::shared_ptr<Node>(new Node(type));
        //$$ = std::shared_ptr<Node>(new Node());
    };


%%

void Blawn::Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
} 