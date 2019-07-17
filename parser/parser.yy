%skeleton "lalr1.cc"
%require  "3.0"
%debug 

%defines 
%define api.namespace {Blawn}
%define parser_class_name {Parser}
%locations
%language "c++"

%code requires{
    #include "../commons/commons.hpp"
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
%type <std::shared_ptr<Node>> line
%type <std::shared_ptr<Node>> line_content
%type <std::shared_ptr<Node>> definition
%type <std::shared_ptr<Node>> variable_definition
%type <std::shared_ptr<Node>> function_definition
%type <std::shared_ptr<Node>> class_definition
%type <std::shared_ptr<Node>> expression
%type <std::shared_ptr<Node>> term
%type <std::shared_ptr<Node>> monomial
%type <std::shared_ptr<Node>> variable

/*std::vector<Type> members_type;
        std::shared_ptr<Type> type = std::make_shared<Type>("FLOAT",members_type);
        $$ = std::shared_ptr<Node>(new Node(type));*/
%%
program: block
    {
        for (auto &node:$1)
        {
            std::cout << node->type->type_name << ",";
        }
        std::cout << typeid(driver).name() << "\n"; 
    };
block: line
    {
        $$.push_back($1);
    }
    |block line
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
        auto type = $3->type;
        $$ = $$ = std::shared_ptr<Node>(new Node(type));
        //std::cout << "new variable:" << $1 <<"  type:" << (type->type_name) << "\n";
    };
function_definition:
    FUNCTION_DEFINITION LEFT_PARENTHESIS arguments RIGHT_PARENTHESIS EOL block RETURN expression
    {
         for (auto &node:$6)
        {
            std::cout << node->type->type_name << ",";
        }
        std::cout << "\n";

        std::cout << "new function " << $1 <<  "'s definition\n";
        std::shared_ptr<Type> type = std::make_shared<Type>("UNKNOW");
        $$ = std::shared_ptr<Node>(new Node(type));
    }
    |FUNCTION_DEFINITION LEFT_PARENTHESIS arguments RIGHT_PARENTHESIS EOL RETURN expression
    {
        std::cout << "new function " << $1 <<  "'s definition\n";
        std::shared_ptr<Type> type = std::make_shared<Type>("UNKNOW");
        $$ = std::shared_ptr<Node>(new Node(type));
    };
class_definition:
    CLASS_DEFINITION EOL block class_definition_end
    {
        std::cout << "start class " << $1 <<  "'s definition\n";
        std::shared_ptr<Type> type = std::make_shared<Type>("UNKNOW");
        $$ = std::shared_ptr<Node>(new Node(type));
    };
class_definition_end:
    EOL|END;
arguments:
    argument
    |arguments COMMA argument;
argument:
    IDENTIFIER;
expression: 
    expression PLUS term
    {
        $$ = driver.ast_generator->attach_operator($1,$3,"PLUS");
    }
    |expression MINUS term
    {
        $$ = driver.ast_generator->attach_operator($1,$3,"MINUS");
    }
    |term
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
    }
    |term SLASH monomial
    {
    };
monomial:
    variable
    {
        $$ = $1;
    }
    |FLOAT_LITERAL
    {
        std::shared_ptr<Type> type = std::make_shared<Type>("FLOAT");
        $$ = std::shared_ptr<Node>(new Node(type));
    }
    |INT_LITERAL
    { 
        std::shared_ptr<Type> type = std::make_shared<Type>("INT");
        $$ = std::shared_ptr<Node>(new Node(type));
    }
    |STRING_LITERAL
    {
        std::shared_ptr<Type> type = std::make_shared<Type>("STRING");
        $$ = std::shared_ptr<Node>(new Node(type));
    };
variable:
    IDENTIFIER
    {
        std::shared_ptr<Type> type = std::make_shared<Type>("UNKNOWN");
        $$ = std::shared_ptr<Node>(new Node(type));
        //$$ = std::shared_ptr<Node>(new Node());
    };


%%

void Blawn::Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
} 