%skeleton "lalr1.cc"
%require  "3.0"

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
    enum BLAWN_STATE
    {
        EXIST_IF = 0,
        NO_IF = 1
    };
    BLAWN_STATE blawn_state = NO_IF;
}

%define api.value.type variant
%define parse.assert
%token END 0 "end of file" 
%token <std::string> FUNCTION_DEFINITION
%token <std::string> METHOD_DEFINITION
%token <std::string> CLASS_DEFINITION
%token  RETURN
%token <std::string> C_FUNCTION
%token <std::string> MEMBER_IDENTIFIER
%token <std::string> IDENTIFIER
%right EQUAL
%left PLUS MINUS
%left ASTERISK SLASH
%left  <std::string> DOT_IDENTIFIER

%left OP_EQUAL OP_NOT_EQUAL
%left OP_AND OP_OR

%token  USE
        COLON
        SEMICOLON
        COMMA
        LEFT_PARENTHESIS
        RIGHT_PARENTHESIS
        LEFT_BRACKET
        RIGHT_BRACKET
        IF
        ELSE
        FOR
        IN
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
%type <std::vector<std::shared_ptr<FunctionNode>>> methods
%type <std::shared_ptr<FunctionNode>> method_definition
%type <std::vector<std::shared_ptr<Node>>> members_definition
%type <std::vector<std::string>> definition_arguments
%type <std::vector<std::shared_ptr<Node>>> expressions
%type <std::shared_ptr<Node>> expression
%type <std::shared_ptr<Node>> list
%type <std::shared_ptr<AccessNode>> access
%type <std::shared_ptr<Node>> call
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
        driver.ast_generator->generate(std::move($1));
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
    }
    |definition
    {
        $$ = $1;
    };
line_content:
    expression
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
    FUNCTION_DEFINITION LEFT_PARENTHESIS definition_arguments RIGHT_PARENTHESIS EOL lines RETURN expression EOL
    {
        $$ = driver.ast_generator->add_function($1,std::move($3),std::move($6),std::move($8));
        driver.ast_generator->break_out_of_namespace();
    };
class_definition:
    CLASS_DEFINITION LEFT_PARENTHESIS definition_arguments RIGHT_PARENTHESIS EOL members_definition methods
    {
        $$ = std::move(driver.ast_generator->add_class($1,$3,$6,$7));
        driver.ast_generator->break_out_of_namespace();
    };
methods:
    method_definition EOL
    {
        $$.push_back($1);
    }
    |methods method_definition EOL
    {
        $$ = std::move($1);
        $$.push_back($2);
    };
method_definition:
    METHOD_DEFINITION LEFT_PARENTHESIS definition_arguments RIGHT_PARENTHESIS EOL lines RETURN expression
    {
        auto args = std::move($3);
        args.insert(args.begin(),"self");
        $$ = driver.ast_generator->add_function($1,std::move(args),std::move($6),std::move($8));
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
    IF expression EOL LEFT_PARENTHESIS EOL block RIGHT_PARENTHESIS
    {
        blawn_state = EXIST_IF;
        $$ = driver.ast_generator->create_if($2,$6);
    }
    |ELSE EOL LEFT_PARENTHESIS block RIGHT_PARENTHESIS
    {
        if (blawn_state != EXIST_IF)
        {
            std::cerr << "Error: If expression is not exist." << std::endl;
            exit(1);
        }
        $$ = driver.ast_generator->add_else($4);
        blawn_state = NO_IF;
    }
    |FOR expression COMMA expression COMMA expression EOL LEFT_PARENTHESIS EOL block RIGHT_PARENTHESIS
    {
        $$ = driver.ast_generator->create_for($2,$4,$6,$10);
        driver.ast_generator->break_out_of_namespace();
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
    }
    |expression OP_AND expression
    {
        $$ = driver.ast_generator->attach_operator(std::move($1),std::move($3),"and");
    }
    |expression OP_OR expression
    {
        $$ = driver.ast_generator->attach_operator(std::move($1),std::move($3),"or");
    }
    |expression OP_EQUAL expression
    {
        $$ = driver.ast_generator->attach_operator(std::move($1),std::move($3),"==");
    }
    |expression OP_NOT_EQUAL expression
    {
        $$ = driver.ast_generator->attach_operator(std::move($1),std::move($3),"!=");
    }
    |list
    {
        $$ = std::move($1);
    }
    |access
    {
        $$ = std::move($1);
    };
list:
    LEFT_BRACKET expressions RIGHT_BRACKET
    {

    };
access:
    expression DOT_IDENTIFIER
    {
        $$ = driver.ast_generator->create_access($1,$2);
    };
assign_variable:
    IDENTIFIER EQUAL expression
    {
        $$ = driver.ast_generator->assign($1,std::move($3));
    }
    |access EQUAL expression
    {
        $$ = driver.ast_generator->assign($1,std::move($3));
    };
monomial:
    call
    {
        $$ = $1;
    }
    |STRING_LITERAL
    {
        $$ = driver.ast_generator->create_string($1);
    }
    |FLOAT_LITERAL
    {
        $$ = driver.ast_generator->create_float($1);
    }
    |INT_LITERAL
    { 
        $$ = driver.ast_generator->create_integer($1);
    }
    |variable
    {
        $$ = std::move($1);
    };
call:
    IDENTIFIER LEFT_PARENTHESIS expressions RIGHT_PARENTHESIS
    {
        $$ = driver.ast_generator->create_call($1,std::move($3));
    }
    |access LEFT_PARENTHESIS expressions RIGHT_PARENTHESIS
    {
        $$ = driver.ast_generator->create_call($1,$3);
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