%skeleton "lalr1.cc"
%require  "3.0"

%defines 
%define api.namespace {blawn}
%define api.parser.class {Parser}
%locations
%language "c++"

%code requires{
    #include <utility>
    #include <memory>
    #include "include/ast/node.hpp"
    #include "include/ast/builder.hpp"
 
    namespace blawn {
        class Driver;
        class Scanner;
        class DeclarationInfo;
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
    #include "include/blawn/parser/driver.hpp"
    #undef yylex
    #define yylex scanner.yylex
    enum BLAWN_STATE
    {
        EXIST_IF = 0,
        NO_IF = 1,
        GLOBAL = 2,
        NOT_GLOBAL = 3
    };
    BLAWN_STATE blawn_state = NO_IF;
    BLAWN_STATE is_global = NOT_GLOBAL;
}

%define api.value.type variant
%define parse.assert
%token <std::string> MEMBER_IDENTIFIER
%token <std::string> IDENTIFIER
%right RETURN
%token  COLON
%token  SEMICOLON
        LEFT_BRACKET RIGHT_BRACKET
        LEFT_CURLY_BRACE RIGHT_CURLY_BRACE
%left   LEFT_PARENTHESIS RIGHT_PARENTHESIS
%token  LEFT_PARENTHESIS_AND_EOL
%right EQUAL ARROW
%left OP_AND OP_OR
%left OP_EQUAL OP_NOT_EQUAL OP_MORE_EQUAL OP_LESS_EQUAL OP_MORE OP_LESS
%left PLUS MINUS
%left ASTERISK SLASH
%left UMINUS
%left <std::string> DOT_IDENTIFIER
%token <std::unique_ptr<blawn::DeclarationInfo>> FUNCTION_DEFINITION
%token <std::unique_ptr<blawn::DeclarationInfo>> METHOD_DEFINITION
%token <std::unique_ptr<blawn::DeclarationInfo>> CLASS_DEFINITION

%token  USE
%token  LAZY
%token  COMMA
        IF
        ELSE
        FOR
        IN
        WHILE
        GLOBAL
        IMPORT
%token <std::string> STRING_LITERAL
%token <long long> INT_LITERAL
%token <double> FLOAT_LITERAL
%type <std::unique_ptr<ast::Node>> program
%type <std::unique_ptr<ast::Node>> block
%type <std::vector<std::unique_ptr<ast::Node>>> lines
%type <std::unique_ptr<ast::Node>> line
%type <std::unique_ptr<ast::Node>> definition
%type <std::unique_ptr<ast::Node>> assign_variable
%type <std::unique_ptr<ast::Node>> global_variable_definition
%type <std::unique_ptr<ast::Node>> function_definition
%type <std::pair< std::string,std::vector<std::unique_ptr<ast::Node>>> > function_start
%type <std::unique_ptr<ast::Node>> class_definition
%type <std::pair< std::string,std::vector<std::unique_ptr<ast::Node>>> > class_start
%type <std::pair< std::string,std::vector<std::unique_ptr<ast::Node>>> > method_start
%type <std::vector<std::unique_ptr<ast::Node>>> methods
%type <std::unique_ptr<ast::Node>> method_definition
%type <std::vector<std::unique_ptr<ast::Node>>> members_definition
%type <std::vector<std::unique_ptr<ast::Node>>> expressions
%type <std::unique_ptr<ast::Node>> else_body
%type <std::unique_ptr<ast::Node>> expression
%type <std::vector<std::unique_ptr<ast::Node>>> for_start
%type <std::unique_ptr<ast::Node>> array
%type <std::unique_ptr<ast::Node>> access
%type <std::unique_ptr<ast::Node>> call
%type <std::unique_ptr<ast::Node>> monomial
%type <std::unique_ptr<ast::Node>> return_value
%type <std::unique_ptr<ast::Node>> named_value
%token EOL
%token END 0 "end of file" 

/*
def f()
    retunr val;

def f()
    if:
        return val;
    else:
        return val;
    return val;
*/


%%
program: 
    lines
    {
        driver.ast_builder->break_out_of_scope();
        driver.ast_builder->create_root(std::move($1));
    };  
block:
    lines
    {
        $$ = driver.ast_builder->create_block(std::move($1));
    };
EOL_OR_EOF: EOL | END;

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
    expression EOL_OR_EOF
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
    function_start EOL LEFT_PARENTHESIS_AND_EOL block RIGHT_PARENTHESIS
    {
        $$ = driver.ast_builder->create_generic_function_definition($1.first,std::move($1.second),std::move($4));
        driver.ast_builder->break_out_of_scope();
    };
function_start:
    FUNCTION_DEFINITION
    {
        auto name = $1->name;
        driver.ast_builder->into_named_scope(name);
        std::vector<std::unique_ptr<ast::Node>> arguments;
        for (auto& arg_name:$1->argument_names)
        {
            arguments.push_back(driver.ast_builder->create_argument(arg_name));
        }
        driver.ast_builder->break_out_of_scope();
        driver.ast_builder->create_generic_function_declaration(name,std::move(arguments));
        driver.ast_builder->into_named_scope(name);
        $$ = {name,std::move(arguments)};
    };
class_definition:
    class_start EOL members_definition methods
    { 
        $$ = driver.ast_builder->create_generic_class_definition($1.first,std::move($1.second),std::move($3),std::move($4));
        driver.ast_builder->break_out_of_scope();
    }
    |class_start EOL members_definition
    {
        $$ = driver.ast_builder->create_generic_class_definition($1.first,std::move($1.second),std::move($3),{});
        driver.ast_builder->break_out_of_scope();
    }
    |class_start EOL methods
    {
        $$ = driver.ast_builder->create_generic_class_definition($1.first,std::move($1.second),{},std::move($3));
        driver.ast_builder->break_out_of_scope();
    };
class_start:
    CLASS_DEFINITION
    {
        auto name = $1->name;
        driver.ast_builder->into_named_scope(name);
        std::vector<std::unique_ptr<ast::Node>> arguments;
        for (auto& arg_name:$1->argument_names)
        {
            arguments.push_back(driver.ast_builder->create_argument(arg_name));
        }
        driver.ast_builder->break_out_of_scope();
        driver.ast_builder->create_generic_function_declaration(name,std::move(arguments));
        driver.ast_builder->into_named_scope(name);
        $$ = {name,std::move(arguments)};
    };
methods:
    method_definition EOL_OR_EOF
    {
        $$.push_back(std::move($1));
    }
    |methods method_definition EOL_OR_EOF
    {
        $$ = std::move($1);
        $$.push_back(std::move($2));
    };
method_start:
    METHOD_DEFINITION
    {
        auto name = $1->name;
        driver.ast_builder->into_named_scope(name);
        std::vector<std::unique_ptr<ast::Node>> arguments;
        arguments.push_back(driver.ast_builder->create_argument("self"));
        for (auto& arg_name:$1->argument_names)
        {
            arguments.push_back(driver.ast_builder->create_argument(arg_name));
        }
        driver.ast_builder->break_out_of_scope();
        driver.ast_builder->create_generic_function_declaration(name,std::move(arguments));
        driver.ast_builder->into_named_scope(name);
        $$ = {name,std::move(arguments)};
    };
method_definition:
    method_start EOL LEFT_PARENTHESIS_AND_EOL block RIGHT_PARENTHESIS
    {
        $$ = driver.ast_builder->create_generic_function_definition($1.first,std::move($1.second),std::move($4));
        driver.ast_builder->break_out_of_scope();
    };  
members_definition:
    MEMBER_IDENTIFIER EQUAL expression EOL_OR_EOF
    {
        $$.push_back(driver.ast_builder->create_member_variable_definition($1,std::move($3)));
    }
    |members_definition MEMBER_IDENTIFIER EQUAL expression EOL_OR_EOF
    {
        $$ = std::move($1);
        $$.push_back(driver.ast_builder->create_member_variable_definition($2,std::move($4)));
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
if_start:
    IF
    {
        driver.ast_builder->into_anonymous_scope();
    };
else_start:
    ELSE
    {
        driver.ast_builder->into_anonymous_scope();
    };
for_start:
    FOR expression COMMA expression COMMA expression
    {
        driver.ast_builder->into_anonymous_scope();
        $$.push_back(std::move($2));
        $$.push_back(std::move($4));
        $$.push_back(std::move($6));
    };

else_body:
    else_start EOL LEFT_PARENTHESIS_AND_EOL block RIGHT_PARENTHESIS
    {
        $$ = std::move($4);
        driver.ast_builder->break_out_of_scope();
    };
expression:
    definition
    {
        $$ = std::move($1);
    }
    |return_value
    {
        $$ = std::move($1);
    }
    |if_start expression EOL LEFT_PARENTHESIS_AND_EOL block RIGHT_PARENTHESIS
    {
        $$ = driver.ast_builder->create_if(std::move($2),std::move($5),{});
        driver.ast_builder->break_out_of_scope();
    }
    |if_start expression EOL LEFT_PARENTHESIS_AND_EOL block RIGHT_PARENTHESIS else_body
    {
        $$ = driver.ast_builder->create_if(std::move($2),std::move($5),std::move($7));
        //driver.ast_builder->break_out_of_scope();
    }
    |for_start EOL LEFT_PARENTHESIS_AND_EOL block RIGHT_PARENTHESIS
    {
        $$ = driver.ast_builder->create_for(std::move($1[0]),std::move($1[1]),std::move($1[2]),std::move($4));
        driver.ast_builder->break_out_of_scope();
    }
    |assign_variable
    {
        $$ = std::move($1);
    }
    |global_variable_definition
    {
        $$ = std::move($1);
    }
    |expression ARROW expression
    {
        $$ = driver.ast_builder->create_deep_copy(std::move($1),std::move($3));
    }
    |expression PLUS expression
    {
        $$ = driver.ast_builder->create_binary_expression(std::move($1),std::move($3),"ADD");
    }
    |expression MINUS expression
    {
        $$ = driver.ast_builder->create_binary_expression(std::move($1),std::move($3),"SUB");
    }
    |expression ASTERISK expression
    {
        $$ = driver.ast_builder->create_binary_expression(std::move($1),std::move($3),"MUL");
    }
    |expression SLASH expression
    {
        $$ = driver.ast_builder->create_binary_expression(std::move($1),std::move($3),"DIV");
    }
    |expression OP_AND expression
    {
        $$ = driver.ast_builder->create_binary_expression(std::move($1),std::move($3),"and");
    }
    |expression OP_OR expression
    {
        $$ = driver.ast_builder->create_binary_expression(std::move($1),std::move($3),"or");
    }
    |expression OP_MORE_EQUAL expression
    {
        $$ = driver.ast_builder->create_binary_expression(std::move($1),std::move($3),">=");
    }
    |expression OP_LESS_EQUAL expression
    {
        $$ = driver.ast_builder->create_binary_expression(std::move($1),std::move($3),"<=");
    }
    |expression OP_MORE expression
    {
        $$ = driver.ast_builder->create_binary_expression(std::move($1),std::move($3),">");
    }
    |expression OP_LESS expression
    {
        $$ = driver.ast_builder->create_binary_expression(std::move($1),std::move($3),"<");
    }
    |expression OP_NOT_EQUAL expression
    {
        $$ = driver.ast_builder->create_binary_expression(std::move($1),std::move($3),"!=");
    }
    |expression OP_EQUAL expression
    {
        $$ = driver.ast_builder->create_binary_expression(std::move($1),std::move($3),"==");
    }
    |monomial
    {
        $$ = std::move($1);
    }
    |array
    {
        $$ = std::move($1);
    }
    |access
    {
        $$ = std::move($1);
    }
    | MINUS expression %prec UMINUS
    {
        $$ = driver.ast_builder->create_minus(std::move($2));
    }
    |LEFT_PARENTHESIS expression RIGHT_PARENTHESIS
    {
        $$ = std::move($2);
    };
array:
    LEFT_BRACKET RIGHT_BRACKET
    {
        $$ = driver.ast_builder->create_array();
    };
access:
    expression DOT_IDENTIFIER
    {
        $$ = driver.ast_builder->create_access(std::move($1),$2);
    };
global_variable_definition:
    GLOBAL IDENTIFIER EQUAL expression
    {
        $$ = driver.ast_builder->create_global_variable_definition($2,std::move($4));
    };
assign_variable:
    IDENTIFIER EQUAL expression
    {
        if (driver.ast_builder->exist_named_expression($1))
        {
            auto named_expression = driver.ast_builder->create_named_node($1);
            $$ = driver.ast_builder->create_assignment(std::move(named_expression),std::move($3));
        }
        else
        {
            $$ = driver.ast_builder->create_variable_definition($1,std::move($3));
        }
    }
    |expression EQUAL expression
    {
        $$ = driver.ast_builder->create_assignment(std::move($1),std::move($3));
    };
return_value:
    RETURN expression 
    {
        $$ = std::move($2);
    };
monomial:
    call
    {
        $$ = std::move($1);
    }
    |STRING_LITERAL
    {
        $$ = driver.ast_builder->create_string($1);
    }
    |FLOAT_LITERAL
    {
        $$ = driver.ast_builder->create_float($1);
    }
    |INT_LITERAL
    { 
        $$ = driver.ast_builder->create_integer($1);
    }
    |LAZY
    {
        $$ = driver.ast_builder->create_lazy();
    }
    |named_value
    {
        $$ = std::move($1);
    };
    
call:
    IDENTIFIER LEFT_PARENTHESIS expressions RIGHT_PARENTHESIS
    {
        if (driver.ast_builder->exist_named_expression($1))
        {
            auto function_object = driver.ast_builder->create_named_node($1);
            $$ = driver.ast_builder->create_call(std::move(function_object),std::move($3));
        }
        else
        {
            $$ = driver.ast_builder->create_call($1,std::move($3));
        }
    }
    |IDENTIFIER LEFT_PARENTHESIS RIGHT_PARENTHESIS
    {
        if (driver.ast_builder->exist_named_expression($1))
        {
            auto function_object = driver.ast_builder->create_named_node($1);
            $$ = driver.ast_builder->create_call(std::move(function_object),{});
        }
        else
        {
            $$ = driver.ast_builder->create_call($1,{});
        }
    }
    |expression LEFT_PARENTHESIS expressions RIGHT_PARENTHESIS
    {
        $$ = driver.ast_builder->create_call(std::move($1),std::move($3));
    }
    |expression LEFT_PARENTHESIS RIGHT_PARENTHESIS
    {
        $$ = driver.ast_builder->create_call(std::move($1),{});
    };
named_value:
    IDENTIFIER
    {
        $$ = driver.ast_builder->create_named_node($1);
    };
%%

void blawn::Parser::error( const location_type &l, const std::string &err_message )
{
    auto debug_info = driver.ast_builder->create_current_debug_info();
    auto& token_info = debug_info.get_token_info();
    //auto& scope = debug_info.get_scope_id();
    auto& filename = debug_info.get_filename();
    std::cerr << "Error at '" <<
    token_info.get_token_string() <<
    "' in line " << token_info.get_line_number() << " in file '"
    << filename << "'" << std::endl;
    exit(1);
} 