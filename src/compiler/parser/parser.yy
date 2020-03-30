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
    #include <llvm/IR/IRBuilder.h>
    #include "../src/compiler/ast/node.hpp"
    #include "../src/compiler/ast/builder.hpp"
 
    namespace blawn {
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
    #include "../src/compiler/parser/driver.hpp"
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
    std::string join(std::vector<std::string> text)
    {
        std::string type_identifier;
        for(auto& t:text){type_identifier+=" " + t;}
        return type_identifier;
    }    
}

%define api.value.type variant
%define parse.assert
%token END 0 "end of file" 
%token <std::string> FUNCTION_DEFINITION
%token <std::string> METHOD_DEFINITION
%token <std::string> CLASS_DEFINITION
%token  RETURN
%token <std::string> MEMBER_IDENTIFIER
%token <std::string> IDENTIFIER

%right EQUAL ARROW
%left OP_AND OP_OR
%left OP_EQUAL OP_NOT_EQUAL OP_MORE_EQUAL OP_LESS_EQUAL OP_MORE OP_LESS
%left PLUS MINUS
%left ASTERISK SLASH
%left UMINUS
%left <std::string> DOT_IDENTIFIER

%token  USE
        COLON
        SEMICOLON
        COMMA
        LEFT_PARENTHESIS
        RIGHT_PARENTHESIS
        LEFT_CURLY_BRACE
        RIGHT_CURLY_BRACE
        LEFT_BRACKET
        RIGHT_BRACKET
        IF
        ELSE
        FOR
        IN
        WHILE
        GLOBAL
        IMPORT
        EOL
%token <std::string> STRING_LITERAL
%token <long long> INT_LITERAL
%token <double> FLOAT_LITERAL
%type <std::shared_ptr<ast::RootNode>> program
%type <std::shared_ptr<ast::BlockNode>> block
%type <std::vector<std::shared_ptr<ast::Node>>> lines
%type <std::shared_ptr<ast::Node>> line
%type <std::shared_ptr<ast::Node>> line_content
%type <std::shared_ptr<ast::Node>> definition
%type <std::shared_ptr<ast::Node>> assign_variable
%type <std::shared_ptr<ast::GlobalVariableNode>> global_variable_definition
%type <std::shared_ptr<ast::GenericFunctionNode>> function_definition
%type <std::string> function_name
%type <std::pair<std::string,std::vector<std::shared_ptr<ast::ArgumentNode>>>> function_start
%type <std::shared_ptr<ast::GenericClassNode>> class_definition
%type <std::string> class_name
%type <std::string> method_name
%type <std::pair<std::string,std::vector<std::shared_ptr<ast::ArgumentNode>>>> method_start
%type <std::vector<std::shared_ptr<ast::GenericFunctionNode>>> methods
%type <std::shared_ptr<ast::GenericFunctionNode>> method_definition
%type <std::vector<std::shared_ptr<ast::VariableNode>>> members_definition
%type <std::vector<std::shared_ptr<ast::ArgumentNode>>> arguments
%type <std::vector<std::shared_ptr<ast::ArgumentNode>>> definition_arguments
%type <std::shared_ptr<ast::Node>> return_value
%type <std::vector<std::shared_ptr<ast::Node>>> expressions
%type <std::shared_ptr<ast::BlockNode>> else_body
%type <std::shared_ptr<ast::Node>> expression
%type <std::vector<std::shared_ptr<ast::Node>>> for_start
%type <std::shared_ptr<ast::ArrayNode>> array
%type <std::shared_ptr<ast::AccessElementNode>> access
%type <std::shared_ptr<ast::CallFunctionNode>> call
%type <std::shared_ptr<ast::Node>> monomial
%type <std::shared_ptr<ast::Node>> named_value



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
    block
    {
        driver.ast_builder->break_out_of_scope();
        $$ = driver.ast_builder->create_root($1);
    };  
block:
    lines
    {
        $$ = driver.ast_builder->create_block(std::move($1));
    };
lines:
    line
    {
        $$.push_back($1);
    }
    |lines line
    {
        $$ = ($1);
        $$.push_back($2);
    };
line:
    line_content EOL
    {
        $$ = ($1);
    }
    |line_content END
    {
        $$ = ($1);
    }
    |definition
    {
        $$ = $1;
    };

line_content:
    expression
    {
        $$ = ($1);
    };
definition:
    function_definition
    {
        $$ = ast::Node::create($1);;
    }
    |class_definition
    {
        $$ = ast::Node::create($1);;
    };
function_definition:
    function_start EOL block return_value EOL
    {
        $$ = driver.ast_builder->create_generic_function_definition($1.first,std::move($1.second),$3,$4);
        driver.ast_builder->break_out_of_scope();
    }
    |function_start EOL return_value EOL
    {
        $$ = driver.ast_builder->create_generic_function_definition($1.first,std::move($1.second),{},$3);
        driver.ast_builder->break_out_of_scope();
    };
function_name:
    FUNCTION_DEFINITION
    {
        $$ = $1;
        driver.ast_builder->into_named_scope($1);
    };
function_start:
    function_name arguments
    {
        driver.ast_builder->break_out_of_scope();
        driver.ast_builder->create_generic_function_declaration($1,$2);
        driver.ast_builder->into_named_scope($1);
        $$ = std::make_pair($1,$2);
    };
class_definition:
    class_name arguments EOL members_definition methods
    { 
        $$ = driver.ast_builder->create_generic_class_definition($1,std::move($2),$4,$5);
        driver.ast_builder->break_out_of_scope();
    }
    |class_name arguments EOL members_definition
    {
        $$ = driver.ast_builder->create_generic_class_definition($1,std::move($2),$4,{});
        driver.ast_builder->break_out_of_scope();
    }
    |class_name arguments EOL methods
    {
        $$ = (driver.ast_builder->create_generic_class_definition($1,std::move($2),{},$4));
        driver.ast_builder->break_out_of_scope();
    };
class_name:
    CLASS_DEFINITION
    {
        $$ = $1;
        driver.ast_builder->into_named_scope($1);
    };
methods:
    method_definition EOL
    {
        $$.push_back($1);
    }
    |methods method_definition EOL
    {
        $$ = ($1);
        $$.push_back($2);
    };
method_name:
    METHOD_DEFINITION
    {
        $$ = $1;
        driver.ast_builder->into_named_scope($1);
    };
method_start:
    method_name arguments
    {
        $2.insert($2.begin(),driver.ast_builder->create_argument("self"));
        driver.ast_builder->break_out_of_scope();
        driver.ast_builder->create_generic_function_declaration($1,$2);
        driver.ast_builder->into_named_scope($1);
        $$ = std::make_pair($1,$2);
    };
method_definition:
    method_start EOL block return_value
    {
        $$ = driver.ast_builder->create_generic_function_definition($1.first,std::move($1.second),($3),($4));
        driver.ast_builder->break_out_of_scope();
    }
    |method_start EOL return_value
    {
        $$ = driver.ast_builder->create_generic_function_definition($1.first,std::move($1.second),{},($3));
        driver.ast_builder->break_out_of_scope();
    };  
members_definition:
    MEMBER_IDENTIFIER EQUAL expression EOL
    {
        $$.push_back(driver.ast_builder->create_member_variable_definition($1,($3)));
    }
    |members_definition MEMBER_IDENTIFIER EQUAL expression EOL
    {
        $$ = std::move($1);
        $$.push_back(driver.ast_builder->create_member_variable_definition($2,($4)));
    };
return_value:
    RETURN expression 
    {
        $$ = $2;
    }
    |RETURN
    {
        $$ = driver.ast_builder->create_void();
    };
arguments:
    LEFT_PARENTHESIS definition_arguments RIGHT_PARENTHESIS
    {
        $$ = std::move($2);
    }
    |LEFT_PARENTHESIS RIGHT_PARENTHESIS
    {
        $$ = {};
    };
definition_arguments:
    IDENTIFIER
    {
        $$.push_back(driver.ast_builder->create_argument($1));
    }
    |definition_arguments COMMA IDENTIFIER
    {
        $$ = std::move($1);
        $$.push_back(driver.ast_builder->create_argument($3));
    };



expressions:
    expression
    {
        $$.push_back($1);
    }
    |expressions COMMA expression
    {
        $$ = ($1);
        $$.push_back(($3));
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
        $$.push_back($2);
        $$.push_back($4);
        $$.push_back($6);
    };

else_body:
    else_start EOL LEFT_PARENTHESIS EOL block RIGHT_PARENTHESIS
    {
        $$ = ($5);
        driver.ast_builder->break_out_of_scope();
    };
expression:
    if_start expression EOL LEFT_PARENTHESIS EOL block RIGHT_PARENTHESIS
    {
        $$ = ast::Node::create(driver.ast_builder->create_if($2,$6,{}));;
        driver.ast_builder->break_out_of_scope();
    }
    |if_start expression EOL LEFT_PARENTHESIS EOL block RIGHT_PARENTHESIS else_body
    {
        $$ = ast::Node::create(driver.ast_builder->create_if($2,$6,$8));;
        //driver.ast_builder->break_out_of_scope();
    }
    |for_start EOL LEFT_PARENTHESIS EOL block RIGHT_PARENTHESIS
    {
        $$ = ast::Node::create(driver.ast_builder->create_for($1[0],$1[1],$1[2],$5));;
        driver.ast_builder->break_out_of_scope();
    }
    |assign_variable
    {
        $$ = $1;
    }
    |global_variable_definition
    {
        $$ = ast::Node::create($1);;
    }
    |expression ARROW expression
    {
        $$ = ast::Node::create(driver.ast_builder->create_deep_copy($1,$3));;
    }
    |expression PLUS expression
    {
        $$ = ast::Node::create(driver.ast_builder->create_binary_expression(($1),($3),"ADD"));;
    }
    |expression MINUS expression
    {
        $$ = ast::Node::create(driver.ast_builder->create_binary_expression(($1),($3),"SUB"));;
    }
    |expression ASTERISK expression
    {
        $$ = ast::Node::create(driver.ast_builder->create_binary_expression(($1),($3),"MUL"));;
    }
    |expression SLASH expression
    {
        $$ = ast::Node::create(driver.ast_builder->create_binary_expression(($1),($3),"DIV"));;
    }
    |expression OP_AND expression
    {
        $$ = ast::Node::create(driver.ast_builder->create_binary_expression(($1),($3),"and"));;
    }
    |expression OP_OR expression
    {
        $$ = ast::Node::create(driver.ast_builder->create_binary_expression(($1),($3),"or"));;
    }
    |expression OP_MORE_EQUAL expression
    {
        $$ = ast::Node::create(driver.ast_builder->create_binary_expression(($1),($3),">="));;
    }
    |expression OP_LESS_EQUAL expression
    {
        $$ = ast::Node::create(driver.ast_builder->create_binary_expression(($1),($3),"<="));;
    }
    |expression OP_MORE expression
    {
        $$ = ast::Node::create(driver.ast_builder->create_binary_expression(($1),($3),">"));;
    }
    |expression OP_LESS expression
    {
        $$ = ast::Node::create(driver.ast_builder->create_binary_expression(($1),($3),"<"));;
    }
    |expression OP_NOT_EQUAL expression
    {
        $$ = ast::Node::create(driver.ast_builder->create_binary_expression(($1),($3),"!="));;
    }
    |expression OP_EQUAL expression
    {
        $$ = ast::Node::create(driver.ast_builder->create_binary_expression(($1),($3),"=="));;
    }
    |monomial
    {
        $$ = ($1);
    }
    |array
    {
        $$ = ast::Node::create($1);;
    }
    |access
    {
        $$ = ast::Node::create($1);;
    }
    | MINUS expression %prec UMINUS
    {
        $$ = driver.ast_builder->create_minus($2);
    }
    |LEFT_PARENTHESIS expression RIGHT_PARENTHESIS
    {
        $$ = ($2);
    };
array:
    LEFT_CURLY_BRACE expressions RIGHT_CURLY_BRACE
    {
        $$ = driver.ast_builder->create_array(($2));
    }
    |LEFT_CURLY_BRACE RIGHT_CURLY_BRACE
    {
        $$ = driver.ast_builder->create_array();
    };
access:
    expression DOT_IDENTIFIER
    {
        $$ = driver.ast_builder->create_access($1,$2);
    };
global_variable_definition:
    GLOBAL IDENTIFIER EQUAL expression
    {
        $$ = driver.ast_builder->create_global_variable_definition($2,$4);
    };
assign_variable:
    IDENTIFIER EQUAL expression
    {
        if (driver.ast_builder->exist($1))
        {
            auto target = driver.ast_builder->get_named_node($1);
            $$ = ast::Node::create(driver.ast_builder->create_assignment(target,($3)));;
        }
        else
        {
            $$ = ast::Node::create(driver.ast_builder->create_variable_definition($1,($3)));;
        }
    }
    |access EQUAL expression
    {
        $$ = ast::Node::create(driver.ast_builder->create_assignment($1,($3)));;
    };
monomial:
    call
    {
        $$ = ast::Node::create($1);
    }
    |STRING_LITERAL
    {
        $$ = ast::Node::create(driver.ast_builder->create_string($1));
    }
    |FLOAT_LITERAL
    {
        $$ = ast::Node::create(driver.ast_builder->create_float($1));
    }
    |INT_LITERAL
    { 
        $$ = ast::Node::create(driver.ast_builder->create_integer($1));;
    }
    |named_value
    {
        $$ = $1;
    };
call:
    IDENTIFIER LEFT_PARENTHESIS expressions RIGHT_PARENTHESIS
    {
        $$ = driver.ast_builder->create_call($1,$3);
    }
    |IDENTIFIER LEFT_PARENTHESIS RIGHT_PARENTHESIS
    {
        $$ = driver.ast_builder->create_call($1,{});
    }
    |access LEFT_PARENTHESIS expressions RIGHT_PARENTHESIS
    {
        $$ = driver.ast_builder->create_call($1,$3);
    }
    |access LEFT_PARENTHESIS RIGHT_PARENTHESIS
    {
        $$ = driver.ast_builder->create_call($1,{});
    };
named_value:
    IDENTIFIER
    {
        $$ = driver.ast_builder->get_named_node($1);
    };
%%

void blawn::Parser::error( const location_type &l, const std::string &err_message )
{
    std::cerr << "Error: " << err_message << " at " << l << "\n";
    exit(1);
} 