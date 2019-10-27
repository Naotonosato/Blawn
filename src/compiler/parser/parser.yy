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
%token <std::string> C_TYPE_DEFINITION
%token <std::string> C_FUNCTION_DECLARATION
%token  RETURN
%token <std::string> C_FUNCTION
%token <std::string> MEMBER_IDENTIFIER
%token <std::string> IDENTIFIER

%right EQUAL ARROW
%left OP_AND OP_OR
%left OP_EQUAL OP_NOT_EQUAL OP_MORE_EQUAL OP_LESS_EQUAL OP_MORE OP_LESS
%left PLUS MINUS
%left ASTERISK SLASH
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
        C_FUNCTION_ARGUMENT
        C_FUNCTION_RETURN
        EOL
%token <std::string> STRING_LITERAL
%token <long long> INT_LITERAL
%token <double> FLOAT_LITERAL
%type <std::vector<std::shared_ptr<Node>>> block
%type <std::vector<std::shared_ptr<Node>>> lines
%type <std::shared_ptr<Node>> line
%type <std::shared_ptr<Node>> line_content
%type <std::shared_ptr<Node>> definition
%type <std::shared_ptr<Node>> assign_variable
%type <std::shared_ptr<Node>> function_definition
%type <std::string> function_start
%type <std::shared_ptr<Node>> class_definition
%type <std::string> class_start
%type <std::shared_ptr<Node>> c_type_definition
%type <std::string> c_type_start
%type <std::shared_ptr<Node>> c_function_declaration
%type <std::vector<std::shared_ptr<FunctionNode>>> methods
%type <std::shared_ptr<FunctionNode>> method_definition
%type <std::string> method_start
%type <std::vector<std::shared_ptr<Node>>> C_members_definition
%type <std::vector<std::string>> C_type_identifier
%type <std::vector<std::shared_ptr<Node>>> C_arguments
%type <std::shared_ptr<Node>> C_returns
%type <std::vector<std::shared_ptr<Node>>> members_definition
%type <std::vector<std::string>> arguments
%type <std::vector<std::string>> definition_arguments
%type <std::shared_ptr<Node>> globals_definition
%type <std::vector<std::shared_ptr<Node>>> globals_variables
%type <std::shared_ptr<Node>> return_value
%type <std::vector<std::shared_ptr<Node>>> expressions
%type <std::shared_ptr<Node>> expression
%type <std::vector<std::shared_ptr<Node>>> for_start
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
        $$.push_back(driver.ast_generator->create_block_end());
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
    }
    |import
    {
        $$ = driver.ast_generator->no_value_node;
    };
import:
    IMPORT STRING_LITERAL EOL;
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
    }
    |c_type_definition
    {
        $$ = std::move($1);
    }
    |globals_definition
    {
        $$ = std::move($1);
    }
    |c_function_declaration
    {
        $$ = std::move($1);
    };
function_definition:
    function_start arguments EOL block return_value EOL
    {
        $$ = driver.ast_generator->add_function($1,std::move($2),std::move($4),std::move($5));
        driver.ast_generator->break_out_of_namespace();
    }
    |function_start arguments EOL return_value EOL
    {
        $$ = driver.ast_generator->add_function($1,std::move($2),{},std::move($4));
        driver.ast_generator->break_out_of_namespace();
    };
function_start:
    FUNCTION_DEFINITION
    {
        $$ = $1;
        driver.ast_generator->into_namespace($1);
    };
class_definition:
    class_start arguments EOL members_definition methods
    { 
        $$ = std::move(driver.ast_generator->create_class($1,$2,$4,$5));
        driver.ast_generator->break_out_of_namespace();
    }
    |class_start arguments EOL members_definition
    {
        $$ = std::move(driver.ast_generator->create_class($1,$2,$4,{}));
        driver.ast_generator->break_out_of_namespace();
    }
    |class_start arguments EOL methods
    {
        $$ = std::move(driver.ast_generator->create_class($1,$2,{},$4));
        driver.ast_generator->break_out_of_namespace();
    };
class_start:
    CLASS_DEFINITION
    {
        $$ = $1;
        driver.ast_generator->into_namespace($1);
    };
c_type_definition:
    c_type_start EOL C_members_definition
    {
        $$ = std::move(driver.ast_generator->create_C_type($1,$3));
        driver.ast_generator->break_out_of_namespace();
    };
c_type_start:
    C_TYPE_DEFINITION
    {
        $$ = $1;
        driver.ast_generator->into_namespace($1);
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
method_start:
    METHOD_DEFINITION
    {
        $$ = $1;
        driver.ast_generator->into_namespace($1);
    };
method_definition:
    method_start arguments EOL block return_value
    {
        auto args = std::move($2);
        args.insert(args.begin(),"self");
        $$ = driver.ast_generator->add_function($1,std::move(args),std::move($4),std::move($5));
        driver.ast_generator->break_out_of_namespace();
    }
    |method_start arguments EOL return_value
    {
        auto args = std::move($2);
        args.insert(args.begin(),"self");
        $$ = driver.ast_generator->add_function($1,std::move(args),{driver.ast_generator->create_block_end()},std::move($4));
        driver.ast_generator->break_out_of_namespace();
    };  
members_definition:
    MEMBER_IDENTIFIER EQUAL expression EOL
    {
        $$.push_back(driver.ast_generator->create_assign($1,std::move($3),false));
    }
    |members_definition MEMBER_IDENTIFIER EQUAL expression EOL
    {
        $$ = std::move($1);
        $$.push_back(driver.ast_generator->create_assign($2,std::move($4),false));
    };
C_members_definition:
    MEMBER_IDENTIFIER EQUAL C_type_identifier EOL
    {
        std::string type_identifier = join($3);
        auto assign_value = driver.ast_generator->create_C_member(type_identifier);
        $$.push_back(driver.ast_generator->create_assign($1,std::move(assign_value),false));
    }
    |C_members_definition MEMBER_IDENTIFIER EQUAL C_type_identifier EOL
    {
        std::string type_identifier = join($4);
        auto assign_value = driver.ast_generator->create_C_member(type_identifier);
        $$ = std::move($1);
        $$.push_back(driver.ast_generator->create_assign($2,std::move(assign_value),false));
    };
C_type_identifier:
    IDENTIFIER
    {
        $$.push_back($1);
    }
    |C_type_identifier IDENTIFIER
    {
        $$ = std::move($1);
        $$.push_back($2);
    };
C_arguments:
    C_type_identifier
    {
        std::string type_identifier = join($1);
        auto assign_value = driver.ast_generator->create_C_member(type_identifier);
        $$.push_back(assign_value);
    }
    |C_arguments COMMA C_type_identifier
    {
        $$ = std::move($1);
        std::string type_identifier = join($3);
        auto assign_value = driver.ast_generator->create_C_member(type_identifier);
        $$.push_back(assign_value);
    };
C_returns:
    C_type_identifier
    {
        std::string type_identifier = join($1);
        $$ = driver.ast_generator->create_C_member(type_identifier);
    };
return_value:
    RETURN expression 
    {
        $$ = $2;
    }
    |RETURN
    {
        $$ = nullptr;
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
        $$.push_back($1);
        driver.ast_generator->add_argument($1);
    }
    |definition_arguments COMMA IDENTIFIER
    {
        $$ = std::move($1);
        $$.push_back($3);
        driver.ast_generator->add_argument($3);
    };
globals_definition:
    global_start EOL LEFT_PARENTHESIS EOL globals_variables EOL RIGHT_PARENTHESIS EOL
    {
        is_global = NOT_GLOBAL;
        $$ = driver.ast_generator->no_value_node;
    };
global_start:
    GLOBAL
    {
        is_global = GLOBAL;
    };
globals_variables:
    assign_variable
    {
        $$.push_back(std::move($1));
    }
    |globals_variables EOL assign_variable
    {
        $$ = std::move($1);
        $$.push_back(std::move($3));
    };
c_function_declaration:
    C_FUNCTION_DECLARATION EOL C_FUNCTION_ARGUMENT C_arguments EOL C_FUNCTION_RETURN C_returns EOL
    {
        $$ = driver.ast_generator->declare_C_function($1,$4,$7);
    }
    |C_FUNCTION_DECLARATION EOL C_FUNCTION_ARGUMENT EOL C_FUNCTION_RETURN C_returns EOL
    {
        $$ = driver.ast_generator->declare_C_function($1,{},$6);
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
        driver.ast_generator->into_namespace();
    };
else_start:
    ELSE
    {
        driver.ast_generator->into_namespace();
    };
for_start:
    FOR expression COMMA expression COMMA expression
    {
        driver.ast_generator->into_namespace();
        $$.push_back($2);
        $$.push_back($4);
        $$.push_back($6);
    };
expression:
    if_start expression EOL LEFT_PARENTHESIS EOL block RIGHT_PARENTHESIS
    {
        blawn_state = EXIST_IF;
        $$ = driver.ast_generator->create_if($2,$6);
        driver.ast_generator->break_out_of_namespace();
    }
    |else_start EOL LEFT_PARENTHESIS EOL block RIGHT_PARENTHESIS
    {
        if (blawn_state != EXIST_IF)
        {
            std::cerr << "Error: else block without if block is invalid." << std::endl;
            exit(1);
        }
        $$ = driver.ast_generator->add_else($5);
        blawn_state = NO_IF;
        driver.ast_generator->break_out_of_namespace();
    }
    |for_start EOL LEFT_PARENTHESIS EOL block RIGHT_PARENTHESIS
    {
        $$ = driver.ast_generator->create_for($1[0],$1[1],$1[2],$5);
        driver.ast_generator->break_out_of_namespace();
    }
    |assign_variable
    {
        $$ = $1;
    }
    |expression ARROW expression
    {
        $$ = driver.ast_generator->create_store($1,$3);
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
    |expression OP_MORE_EQUAL expression
    {
        $$ = driver.ast_generator->attach_operator(std::move($1),std::move($3),">=");
    }
    |expression OP_LESS_EQUAL expression
    {
        $$ = driver.ast_generator->attach_operator(std::move($1),std::move($3),"<=");
    }
    |expression OP_MORE expression
    {
        $$ = driver.ast_generator->attach_operator(std::move($1),std::move($3),">");
    }
    |expression OP_LESS expression
    {
        $$ = driver.ast_generator->attach_operator(std::move($1),std::move($3),"<");
    }
    |expression OP_NOT_EQUAL expression
    {
        $$ = driver.ast_generator->attach_operator(std::move($1),std::move($3),"!=");
    }
    |expression OP_EQUAL expression
    {
        $$ = driver.ast_generator->attach_operator(std::move($1),std::move($3),"==");
    }
    |monomial
    {
        $$ = std::move($1);
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
    LEFT_CURLY_BRACE expressions RIGHT_CURLY_BRACE
    {
        $$ = driver.ast_generator->create_list(std::move($2));
    }
    |LEFT_CURLY_BRACE RIGHT_CURLY_BRACE
    {
        $$ = driver.ast_generator->create_list();
    };
access:
    expression DOT_IDENTIFIER
    {
        $$ = driver.ast_generator->create_access($1,$2);
    };
assign_variable:
    IDENTIFIER EQUAL expression
    {
        if (is_global == NOT_GLOBAL)
        {$$ = driver.ast_generator->create_assign($1,std::move($3),false);}
        if (is_global == GLOBAL)
        {$$ = driver.ast_generator->create_assign($1,std::move($3),true);}
    }
    |access EQUAL expression
    {
        $$ = driver.ast_generator->create_assign($1,std::move($3));
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
        $$ = driver.ast_generator->create_call($1,$3);
    }
    |IDENTIFIER LEFT_PARENTHESIS RIGHT_PARENTHESIS
    {
        $$ = driver.ast_generator->create_call($1,{});
    }
    |access LEFT_PARENTHESIS expressions RIGHT_PARENTHESIS
    {
        $$ = driver.ast_generator->create_call($1,$3);
    }
    |access LEFT_PARENTHESIS RIGHT_PARENTHESIS
    {
        $$ = driver.ast_generator->create_call($1,{});
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
    exit(1);
} 