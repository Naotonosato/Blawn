// A Bison parser, made by GNU Bison 3.5.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.hpp"


// Unqualified %code blocks.
#line 35 "./src/compiler/parser/parser.yy"

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

#line 70 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "./src/compiler/parser/parser.yy"
namespace blawn {
#line 162 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"


  /// Build a parser object.
  Parser::Parser (Scanner  &scanner_yyarg, Driver  &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
    , location (std::move (that.location))
  {
    switch (this->type_get ())
    {
      case 45: // FLOAT_LITERAL
        value.move< double > (std::move (that.value));
        break;

      case 44: // INT_LITERAL
        value.move< long long > (std::move (that.value));
        break;

      case 55: // function_start
      case 60: // method_start
        value.move< std::pair<std::string,std::vector<std::shared_ptr<ast::ArgumentNode>>> > (std::move (that.value));
        break;

      case 73: // access
        value.move< std::shared_ptr<ast::AccessElementNode> > (std::move (that.value));
        break;

      case 72: // array
        value.move< std::shared_ptr<ast::ArrayNode> > (std::move (that.value));
        break;

      case 48: // block
      case 70: // else_body
        value.move< std::shared_ptr<ast::BlockNode> > (std::move (that.value));
        break;

      case 77: // call
        value.move< std::shared_ptr<ast::CallFunctionNode> > (std::move (that.value));
        break;

      case 56: // class_definition
        value.move< std::shared_ptr<ast::GenericClassNode> > (std::move (that.value));
        break;

      case 53: // function_definition
      case 61: // method_definition
        value.move< std::shared_ptr<ast::GenericFunctionNode> > (std::move (that.value));
        break;

      case 74: // global_variable_definition
        value.move< std::shared_ptr<ast::GlobalVariableNode> > (std::move (that.value));
        break;

      case 50: // line
      case 51: // line_content
      case 52: // definition
      case 63: // return_value
      case 71: // expression
      case 75: // assign_variable
      case 76: // monomial
      case 78: // named_value
        value.move< std::shared_ptr<ast::Node> > (std::move (that.value));
        break;

      case 47: // program
        value.move< std::shared_ptr<ast::RootNode> > (std::move (that.value));
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 7: // MEMBER_IDENTIFIER
      case 8: // IDENTIFIER
      case 24: // DOT_IDENTIFIER
      case 43: // STRING_LITERAL
      case 54: // function_name
      case 57: // class_name
      case 59: // method_name
        value.move< std::string > (std::move (that.value));
        break;

      case 64: // arguments
      case 65: // definition_arguments
        value.move< std::vector<std::shared_ptr<ast::ArgumentNode>> > (std::move (that.value));
        break;

      case 58: // methods
        value.move< std::vector<std::shared_ptr<ast::GenericFunctionNode>> > (std::move (that.value));
        break;

      case 49: // lines
      case 66: // expressions
      case 69: // for_start
        value.move< std::vector<std::shared_ptr<ast::Node>> > (std::move (that.value));
        break;

      case 62: // members_definition
        value.move< std::vector<std::shared_ptr<ast::VariableNode>> > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->type_get ())
    {
      case 45: // FLOAT_LITERAL
        value.copy< double > (YY_MOVE (that.value));
        break;

      case 44: // INT_LITERAL
        value.copy< long long > (YY_MOVE (that.value));
        break;

      case 55: // function_start
      case 60: // method_start
        value.copy< std::pair<std::string,std::vector<std::shared_ptr<ast::ArgumentNode>>> > (YY_MOVE (that.value));
        break;

      case 73: // access
        value.copy< std::shared_ptr<ast::AccessElementNode> > (YY_MOVE (that.value));
        break;

      case 72: // array
        value.copy< std::shared_ptr<ast::ArrayNode> > (YY_MOVE (that.value));
        break;

      case 48: // block
      case 70: // else_body
        value.copy< std::shared_ptr<ast::BlockNode> > (YY_MOVE (that.value));
        break;

      case 77: // call
        value.copy< std::shared_ptr<ast::CallFunctionNode> > (YY_MOVE (that.value));
        break;

      case 56: // class_definition
        value.copy< std::shared_ptr<ast::GenericClassNode> > (YY_MOVE (that.value));
        break;

      case 53: // function_definition
      case 61: // method_definition
        value.copy< std::shared_ptr<ast::GenericFunctionNode> > (YY_MOVE (that.value));
        break;

      case 74: // global_variable_definition
        value.copy< std::shared_ptr<ast::GlobalVariableNode> > (YY_MOVE (that.value));
        break;

      case 50: // line
      case 51: // line_content
      case 52: // definition
      case 63: // return_value
      case 71: // expression
      case 75: // assign_variable
      case 76: // monomial
      case 78: // named_value
        value.copy< std::shared_ptr<ast::Node> > (YY_MOVE (that.value));
        break;

      case 47: // program
        value.copy< std::shared_ptr<ast::RootNode> > (YY_MOVE (that.value));
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 7: // MEMBER_IDENTIFIER
      case 8: // IDENTIFIER
      case 24: // DOT_IDENTIFIER
      case 43: // STRING_LITERAL
      case 54: // function_name
      case 57: // class_name
      case 59: // method_name
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case 64: // arguments
      case 65: // definition_arguments
        value.copy< std::vector<std::shared_ptr<ast::ArgumentNode>> > (YY_MOVE (that.value));
        break;

      case 58: // methods
        value.copy< std::vector<std::shared_ptr<ast::GenericFunctionNode>> > (YY_MOVE (that.value));
        break;

      case 49: // lines
      case 66: // expressions
      case 69: // for_start
        value.copy< std::vector<std::shared_ptr<ast::Node>> > (YY_MOVE (that.value));
        break;

      case 62: // members_definition
        value.copy< std::vector<std::shared_ptr<ast::VariableNode>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 45: // FLOAT_LITERAL
        value.move< double > (YY_MOVE (s.value));
        break;

      case 44: // INT_LITERAL
        value.move< long long > (YY_MOVE (s.value));
        break;

      case 55: // function_start
      case 60: // method_start
        value.move< std::pair<std::string,std::vector<std::shared_ptr<ast::ArgumentNode>>> > (YY_MOVE (s.value));
        break;

      case 73: // access
        value.move< std::shared_ptr<ast::AccessElementNode> > (YY_MOVE (s.value));
        break;

      case 72: // array
        value.move< std::shared_ptr<ast::ArrayNode> > (YY_MOVE (s.value));
        break;

      case 48: // block
      case 70: // else_body
        value.move< std::shared_ptr<ast::BlockNode> > (YY_MOVE (s.value));
        break;

      case 77: // call
        value.move< std::shared_ptr<ast::CallFunctionNode> > (YY_MOVE (s.value));
        break;

      case 56: // class_definition
        value.move< std::shared_ptr<ast::GenericClassNode> > (YY_MOVE (s.value));
        break;

      case 53: // function_definition
      case 61: // method_definition
        value.move< std::shared_ptr<ast::GenericFunctionNode> > (YY_MOVE (s.value));
        break;

      case 74: // global_variable_definition
        value.move< std::shared_ptr<ast::GlobalVariableNode> > (YY_MOVE (s.value));
        break;

      case 50: // line
      case 51: // line_content
      case 52: // definition
      case 63: // return_value
      case 71: // expression
      case 75: // assign_variable
      case 76: // monomial
      case 78: // named_value
        value.move< std::shared_ptr<ast::Node> > (YY_MOVE (s.value));
        break;

      case 47: // program
        value.move< std::shared_ptr<ast::RootNode> > (YY_MOVE (s.value));
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 7: // MEMBER_IDENTIFIER
      case 8: // IDENTIFIER
      case 24: // DOT_IDENTIFIER
      case 43: // STRING_LITERAL
      case 54: // function_name
      case 57: // class_name
      case 59: // method_name
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case 64: // arguments
      case 65: // definition_arguments
        value.move< std::vector<std::shared_ptr<ast::ArgumentNode>> > (YY_MOVE (s.value));
        break;

      case 58: // methods
        value.move< std::vector<std::shared_ptr<ast::GenericFunctionNode>> > (YY_MOVE (s.value));
        break;

      case 49: // lines
      case 66: // expressions
      case 69: // for_start
        value.move< std::vector<std::shared_ptr<ast::Node>> > (YY_MOVE (s.value));
        break;

      case 62: // members_definition
        value.move< std::vector<std::shared_ptr<ast::VariableNode>> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_type.
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  Parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  Parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_number_type
  Parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 45: // FLOAT_LITERAL
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case 44: // INT_LITERAL
        value.YY_MOVE_OR_COPY< long long > (YY_MOVE (that.value));
        break;

      case 55: // function_start
      case 60: // method_start
        value.YY_MOVE_OR_COPY< std::pair<std::string,std::vector<std::shared_ptr<ast::ArgumentNode>>> > (YY_MOVE (that.value));
        break;

      case 73: // access
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::AccessElementNode> > (YY_MOVE (that.value));
        break;

      case 72: // array
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::ArrayNode> > (YY_MOVE (that.value));
        break;

      case 48: // block
      case 70: // else_body
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::BlockNode> > (YY_MOVE (that.value));
        break;

      case 77: // call
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::CallFunctionNode> > (YY_MOVE (that.value));
        break;

      case 56: // class_definition
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::GenericClassNode> > (YY_MOVE (that.value));
        break;

      case 53: // function_definition
      case 61: // method_definition
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::GenericFunctionNode> > (YY_MOVE (that.value));
        break;

      case 74: // global_variable_definition
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::GlobalVariableNode> > (YY_MOVE (that.value));
        break;

      case 50: // line
      case 51: // line_content
      case 52: // definition
      case 63: // return_value
      case 71: // expression
      case 75: // assign_variable
      case 76: // monomial
      case 78: // named_value
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::Node> > (YY_MOVE (that.value));
        break;

      case 47: // program
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::RootNode> > (YY_MOVE (that.value));
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 7: // MEMBER_IDENTIFIER
      case 8: // IDENTIFIER
      case 24: // DOT_IDENTIFIER
      case 43: // STRING_LITERAL
      case 54: // function_name
      case 57: // class_name
      case 59: // method_name
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 64: // arguments
      case 65: // definition_arguments
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<ast::ArgumentNode>> > (YY_MOVE (that.value));
        break;

      case 58: // methods
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<ast::GenericFunctionNode>> > (YY_MOVE (that.value));
        break;

      case 49: // lines
      case 66: // expressions
      case 69: // for_start
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<ast::Node>> > (YY_MOVE (that.value));
        break;

      case 62: // members_definition
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<ast::VariableNode>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 45: // FLOAT_LITERAL
        value.move< double > (YY_MOVE (that.value));
        break;

      case 44: // INT_LITERAL
        value.move< long long > (YY_MOVE (that.value));
        break;

      case 55: // function_start
      case 60: // method_start
        value.move< std::pair<std::string,std::vector<std::shared_ptr<ast::ArgumentNode>>> > (YY_MOVE (that.value));
        break;

      case 73: // access
        value.move< std::shared_ptr<ast::AccessElementNode> > (YY_MOVE (that.value));
        break;

      case 72: // array
        value.move< std::shared_ptr<ast::ArrayNode> > (YY_MOVE (that.value));
        break;

      case 48: // block
      case 70: // else_body
        value.move< std::shared_ptr<ast::BlockNode> > (YY_MOVE (that.value));
        break;

      case 77: // call
        value.move< std::shared_ptr<ast::CallFunctionNode> > (YY_MOVE (that.value));
        break;

      case 56: // class_definition
        value.move< std::shared_ptr<ast::GenericClassNode> > (YY_MOVE (that.value));
        break;

      case 53: // function_definition
      case 61: // method_definition
        value.move< std::shared_ptr<ast::GenericFunctionNode> > (YY_MOVE (that.value));
        break;

      case 74: // global_variable_definition
        value.move< std::shared_ptr<ast::GlobalVariableNode> > (YY_MOVE (that.value));
        break;

      case 50: // line
      case 51: // line_content
      case 52: // definition
      case 63: // return_value
      case 71: // expression
      case 75: // assign_variable
      case 76: // monomial
      case 78: // named_value
        value.move< std::shared_ptr<ast::Node> > (YY_MOVE (that.value));
        break;

      case 47: // program
        value.move< std::shared_ptr<ast::RootNode> > (YY_MOVE (that.value));
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 7: // MEMBER_IDENTIFIER
      case 8: // IDENTIFIER
      case 24: // DOT_IDENTIFIER
      case 43: // STRING_LITERAL
      case 54: // function_name
      case 57: // class_name
      case 59: // method_name
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 64: // arguments
      case 65: // definition_arguments
        value.move< std::vector<std::shared_ptr<ast::ArgumentNode>> > (YY_MOVE (that.value));
        break;

      case 58: // methods
        value.move< std::vector<std::shared_ptr<ast::GenericFunctionNode>> > (YY_MOVE (that.value));
        break;

      case 49: // lines
      case 66: // expressions
      case 69: // for_start
        value.move< std::vector<std::shared_ptr<ast::Node>> > (YY_MOVE (that.value));
        break;

      case 62: // members_definition
        value.move< std::vector<std::shared_ptr<ast::VariableNode>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 45: // FLOAT_LITERAL
        value.copy< double > (that.value);
        break;

      case 44: // INT_LITERAL
        value.copy< long long > (that.value);
        break;

      case 55: // function_start
      case 60: // method_start
        value.copy< std::pair<std::string,std::vector<std::shared_ptr<ast::ArgumentNode>>> > (that.value);
        break;

      case 73: // access
        value.copy< std::shared_ptr<ast::AccessElementNode> > (that.value);
        break;

      case 72: // array
        value.copy< std::shared_ptr<ast::ArrayNode> > (that.value);
        break;

      case 48: // block
      case 70: // else_body
        value.copy< std::shared_ptr<ast::BlockNode> > (that.value);
        break;

      case 77: // call
        value.copy< std::shared_ptr<ast::CallFunctionNode> > (that.value);
        break;

      case 56: // class_definition
        value.copy< std::shared_ptr<ast::GenericClassNode> > (that.value);
        break;

      case 53: // function_definition
      case 61: // method_definition
        value.copy< std::shared_ptr<ast::GenericFunctionNode> > (that.value);
        break;

      case 74: // global_variable_definition
        value.copy< std::shared_ptr<ast::GlobalVariableNode> > (that.value);
        break;

      case 50: // line
      case 51: // line_content
      case 52: // definition
      case 63: // return_value
      case 71: // expression
      case 75: // assign_variable
      case 76: // monomial
      case 78: // named_value
        value.copy< std::shared_ptr<ast::Node> > (that.value);
        break;

      case 47: // program
        value.copy< std::shared_ptr<ast::RootNode> > (that.value);
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 7: // MEMBER_IDENTIFIER
      case 8: // IDENTIFIER
      case 24: // DOT_IDENTIFIER
      case 43: // STRING_LITERAL
      case 54: // function_name
      case 57: // class_name
      case 59: // method_name
        value.copy< std::string > (that.value);
        break;

      case 64: // arguments
      case 65: // definition_arguments
        value.copy< std::vector<std::shared_ptr<ast::ArgumentNode>> > (that.value);
        break;

      case 58: // methods
        value.copy< std::vector<std::shared_ptr<ast::GenericFunctionNode>> > (that.value);
        break;

      case 49: // lines
      case 66: // expressions
      case 69: // for_start
        value.copy< std::vector<std::shared_ptr<ast::Node>> > (that.value);
        break;

      case 62: // members_definition
        value.copy< std::vector<std::shared_ptr<ast::VariableNode>> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 45: // FLOAT_LITERAL
        value.move< double > (that.value);
        break;

      case 44: // INT_LITERAL
        value.move< long long > (that.value);
        break;

      case 55: // function_start
      case 60: // method_start
        value.move< std::pair<std::string,std::vector<std::shared_ptr<ast::ArgumentNode>>> > (that.value);
        break;

      case 73: // access
        value.move< std::shared_ptr<ast::AccessElementNode> > (that.value);
        break;

      case 72: // array
        value.move< std::shared_ptr<ast::ArrayNode> > (that.value);
        break;

      case 48: // block
      case 70: // else_body
        value.move< std::shared_ptr<ast::BlockNode> > (that.value);
        break;

      case 77: // call
        value.move< std::shared_ptr<ast::CallFunctionNode> > (that.value);
        break;

      case 56: // class_definition
        value.move< std::shared_ptr<ast::GenericClassNode> > (that.value);
        break;

      case 53: // function_definition
      case 61: // method_definition
        value.move< std::shared_ptr<ast::GenericFunctionNode> > (that.value);
        break;

      case 74: // global_variable_definition
        value.move< std::shared_ptr<ast::GlobalVariableNode> > (that.value);
        break;

      case 50: // line
      case 51: // line_content
      case 52: // definition
      case 63: // return_value
      case 71: // expression
      case 75: // assign_variable
      case 76: // monomial
      case 78: // named_value
        value.move< std::shared_ptr<ast::Node> > (that.value);
        break;

      case 47: // program
        value.move< std::shared_ptr<ast::RootNode> > (that.value);
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 7: // MEMBER_IDENTIFIER
      case 8: // IDENTIFIER
      case 24: // DOT_IDENTIFIER
      case 43: // STRING_LITERAL
      case 54: // function_name
      case 57: // class_name
      case 59: // method_name
        value.move< std::string > (that.value);
        break;

      case 64: // arguments
      case 65: // definition_arguments
        value.move< std::vector<std::shared_ptr<ast::ArgumentNode>> > (that.value);
        break;

      case 58: // methods
        value.move< std::vector<std::shared_ptr<ast::GenericFunctionNode>> > (that.value);
        break;

      case 49: // lines
      case 66: // expressions
      case 69: // for_start
        value.move< std::vector<std::shared_ptr<ast::Node>> > (that.value);
        break;

      case 62: // members_definition
        value.move< std::vector<std::shared_ptr<ast::VariableNode>> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", static_cast<state_type> (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 45: // FLOAT_LITERAL
        yylhs.value.emplace< double > ();
        break;

      case 44: // INT_LITERAL
        yylhs.value.emplace< long long > ();
        break;

      case 55: // function_start
      case 60: // method_start
        yylhs.value.emplace< std::pair<std::string,std::vector<std::shared_ptr<ast::ArgumentNode>>> > ();
        break;

      case 73: // access
        yylhs.value.emplace< std::shared_ptr<ast::AccessElementNode> > ();
        break;

      case 72: // array
        yylhs.value.emplace< std::shared_ptr<ast::ArrayNode> > ();
        break;

      case 48: // block
      case 70: // else_body
        yylhs.value.emplace< std::shared_ptr<ast::BlockNode> > ();
        break;

      case 77: // call
        yylhs.value.emplace< std::shared_ptr<ast::CallFunctionNode> > ();
        break;

      case 56: // class_definition
        yylhs.value.emplace< std::shared_ptr<ast::GenericClassNode> > ();
        break;

      case 53: // function_definition
      case 61: // method_definition
        yylhs.value.emplace< std::shared_ptr<ast::GenericFunctionNode> > ();
        break;

      case 74: // global_variable_definition
        yylhs.value.emplace< std::shared_ptr<ast::GlobalVariableNode> > ();
        break;

      case 50: // line
      case 51: // line_content
      case 52: // definition
      case 63: // return_value
      case 71: // expression
      case 75: // assign_variable
      case 76: // monomial
      case 78: // named_value
        yylhs.value.emplace< std::shared_ptr<ast::Node> > ();
        break;

      case 47: // program
        yylhs.value.emplace< std::shared_ptr<ast::RootNode> > ();
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 7: // MEMBER_IDENTIFIER
      case 8: // IDENTIFIER
      case 24: // DOT_IDENTIFIER
      case 43: // STRING_LITERAL
      case 54: // function_name
      case 57: // class_name
      case 59: // method_name
        yylhs.value.emplace< std::string > ();
        break;

      case 64: // arguments
      case 65: // definition_arguments
        yylhs.value.emplace< std::vector<std::shared_ptr<ast::ArgumentNode>> > ();
        break;

      case 58: // methods
        yylhs.value.emplace< std::vector<std::shared_ptr<ast::GenericFunctionNode>> > ();
        break;

      case 49: // lines
      case 66: // expressions
      case 69: // for_start
        yylhs.value.emplace< std::vector<std::shared_ptr<ast::Node>> > ();
        break;

      case 62: // members_definition
        yylhs.value.emplace< std::vector<std::shared_ptr<ast::VariableNode>> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 148 "./src/compiler/parser/parser.yy"
    {
        driver.ast_builder->break_out_of_scope();
        yylhs.value.as < std::shared_ptr<ast::RootNode> > () = driver.ast_builder->create_root(yystack_[0].value.as < std::shared_ptr<ast::BlockNode> > ());
    }
#line 1364 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 3:
#line 154 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::BlockNode> > () = driver.ast_builder->create_block(std::move(yystack_[0].value.as < std::vector<std::shared_ptr<ast::Node>> > ()));
    }
#line 1372 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 4:
#line 159 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > ().push_back(yystack_[0].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1380 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 5:
#line 163 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > () = (yystack_[1].value.as < std::vector<std::shared_ptr<ast::Node>> > ());
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > ().push_back(yystack_[0].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1389 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 6:
#line 169 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = (yystack_[1].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1397 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 7:
#line 173 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = (yystack_[1].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1405 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 8:
#line 177 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = yystack_[0].value.as < std::shared_ptr<ast::Node> > ();
    }
#line 1413 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 9:
#line 183 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = (yystack_[0].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1421 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 10:
#line 188 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(yystack_[0].value.as < std::shared_ptr<ast::GenericFunctionNode> > ());;
    }
#line 1429 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 11:
#line 192 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(yystack_[0].value.as < std::shared_ptr<ast::GenericClassNode> > ());;
    }
#line 1437 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 12:
#line 197 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::GenericFunctionNode> > () = driver.ast_builder->create_generic_function_definition(yystack_[4].value.as < std::pair<std::string,std::vector<std::shared_ptr<ast::ArgumentNode>>> > ().first,std::move(yystack_[4].value.as < std::pair<std::string,std::vector<std::shared_ptr<ast::ArgumentNode>>> > ().second),yystack_[2].value.as < std::shared_ptr<ast::BlockNode> > (),yystack_[1].value.as < std::shared_ptr<ast::Node> > ());
        driver.ast_builder->break_out_of_scope();
    }
#line 1446 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 13:
#line 202 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::GenericFunctionNode> > () = driver.ast_builder->create_generic_function_definition(yystack_[3].value.as < std::pair<std::string,std::vector<std::shared_ptr<ast::ArgumentNode>>> > ().first,std::move(yystack_[3].value.as < std::pair<std::string,std::vector<std::shared_ptr<ast::ArgumentNode>>> > ().second),{},yystack_[1].value.as < std::shared_ptr<ast::Node> > ());
        driver.ast_builder->break_out_of_scope();
    }
#line 1455 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 14:
#line 208 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
        driver.ast_builder->into_named_scope(yystack_[0].value.as < std::string > ());
    }
#line 1464 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 15:
#line 214 "./src/compiler/parser/parser.yy"
    {
        driver.ast_builder->break_out_of_scope();
        driver.ast_builder->create_generic_function_declaration(yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::vector<std::shared_ptr<ast::ArgumentNode>> > ());
        driver.ast_builder->into_named_scope(yystack_[1].value.as < std::string > ());
        yylhs.value.as < std::pair<std::string,std::vector<std::shared_ptr<ast::ArgumentNode>>> > () = std::make_pair(yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::vector<std::shared_ptr<ast::ArgumentNode>> > ());
    }
#line 1475 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 16:
#line 222 "./src/compiler/parser/parser.yy"
    { 
        yylhs.value.as < std::shared_ptr<ast::GenericClassNode> > () = driver.ast_builder->create_generic_class_definition(yystack_[4].value.as < std::string > (),std::move(yystack_[3].value.as < std::vector<std::shared_ptr<ast::ArgumentNode>> > ()),yystack_[1].value.as < std::vector<std::shared_ptr<ast::VariableNode>> > (),yystack_[0].value.as < std::vector<std::shared_ptr<ast::GenericFunctionNode>> > ());
        driver.ast_builder->break_out_of_scope();
    }
#line 1484 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 17:
#line 227 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::GenericClassNode> > () = driver.ast_builder->create_generic_class_definition(yystack_[3].value.as < std::string > (),std::move(yystack_[2].value.as < std::vector<std::shared_ptr<ast::ArgumentNode>> > ()),yystack_[0].value.as < std::vector<std::shared_ptr<ast::VariableNode>> > (),{});
        driver.ast_builder->break_out_of_scope();
    }
#line 1493 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 18:
#line 232 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::GenericClassNode> > () = (driver.ast_builder->create_generic_class_definition(yystack_[3].value.as < std::string > (),std::move(yystack_[2].value.as < std::vector<std::shared_ptr<ast::ArgumentNode>> > ()),{},yystack_[0].value.as < std::vector<std::shared_ptr<ast::GenericFunctionNode>> > ()));
        driver.ast_builder->break_out_of_scope();
    }
#line 1502 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 19:
#line 238 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
        driver.ast_builder->into_named_scope(yystack_[0].value.as < std::string > ());
    }
#line 1511 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 20:
#line 244 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::GenericFunctionNode>> > ().push_back(yystack_[1].value.as < std::shared_ptr<ast::GenericFunctionNode> > ());
    }
#line 1519 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 21:
#line 248 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::GenericFunctionNode>> > () = (yystack_[2].value.as < std::vector<std::shared_ptr<ast::GenericFunctionNode>> > ());
        yylhs.value.as < std::vector<std::shared_ptr<ast::GenericFunctionNode>> > ().push_back(yystack_[1].value.as < std::shared_ptr<ast::GenericFunctionNode> > ());
    }
#line 1528 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 22:
#line 254 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
        driver.ast_builder->into_named_scope(yystack_[0].value.as < std::string > ());
    }
#line 1537 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 23:
#line 260 "./src/compiler/parser/parser.yy"
    {
        yystack_[0].value.as < std::vector<std::shared_ptr<ast::ArgumentNode>> > ().insert(yystack_[0].value.as < std::vector<std::shared_ptr<ast::ArgumentNode>> > ().begin(),driver.ast_builder->create_argument("self"));
        driver.ast_builder->break_out_of_scope();
        driver.ast_builder->create_generic_function_declaration(yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::vector<std::shared_ptr<ast::ArgumentNode>> > ());
        driver.ast_builder->into_named_scope(yystack_[1].value.as < std::string > ());
        yylhs.value.as < std::pair<std::string,std::vector<std::shared_ptr<ast::ArgumentNode>>> > () = std::make_pair(yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::vector<std::shared_ptr<ast::ArgumentNode>> > ());
    }
#line 1549 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 24:
#line 269 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::GenericFunctionNode> > () = driver.ast_builder->create_generic_function_definition(yystack_[3].value.as < std::pair<std::string,std::vector<std::shared_ptr<ast::ArgumentNode>>> > ().first,std::move(yystack_[3].value.as < std::pair<std::string,std::vector<std::shared_ptr<ast::ArgumentNode>>> > ().second),(yystack_[1].value.as < std::shared_ptr<ast::BlockNode> > ()),(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()));
        driver.ast_builder->break_out_of_scope();
    }
#line 1558 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 25:
#line 274 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::GenericFunctionNode> > () = driver.ast_builder->create_generic_function_definition(yystack_[2].value.as < std::pair<std::string,std::vector<std::shared_ptr<ast::ArgumentNode>>> > ().first,std::move(yystack_[2].value.as < std::pair<std::string,std::vector<std::shared_ptr<ast::ArgumentNode>>> > ().second),{},(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()));
        driver.ast_builder->break_out_of_scope();
    }
#line 1567 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 26:
#line 280 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::VariableNode>> > ().push_back(driver.ast_builder->create_member_variable_definition(yystack_[3].value.as < std::string > (),(yystack_[1].value.as < std::shared_ptr<ast::Node> > ())));
    }
#line 1575 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 27:
#line 284 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::VariableNode>> > () = std::move(yystack_[4].value.as < std::vector<std::shared_ptr<ast::VariableNode>> > ());
        yylhs.value.as < std::vector<std::shared_ptr<ast::VariableNode>> > ().push_back(driver.ast_builder->create_member_variable_definition(yystack_[3].value.as < std::string > (),(yystack_[1].value.as < std::shared_ptr<ast::Node> > ())));
    }
#line 1584 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 28:
#line 290 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = yystack_[0].value.as < std::shared_ptr<ast::Node> > ();
    }
#line 1592 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 29:
#line 294 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_void();
    }
#line 1600 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 30:
#line 299 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::ArgumentNode>> > () = std::move(yystack_[1].value.as < std::vector<std::shared_ptr<ast::ArgumentNode>> > ());
    }
#line 1608 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 31:
#line 303 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::ArgumentNode>> > () = {};
    }
#line 1616 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 32:
#line 308 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::ArgumentNode>> > ().push_back(driver.ast_builder->create_argument(yystack_[0].value.as < std::string > ()));
    }
#line 1624 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 33:
#line 312 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::ArgumentNode>> > () = std::move(yystack_[2].value.as < std::vector<std::shared_ptr<ast::ArgumentNode>> > ());
        yylhs.value.as < std::vector<std::shared_ptr<ast::ArgumentNode>> > ().push_back(driver.ast_builder->create_argument(yystack_[0].value.as < std::string > ()));
    }
#line 1633 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 34:
#line 321 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > ().push_back(yystack_[0].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1641 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 35:
#line 325 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > () = (yystack_[2].value.as < std::vector<std::shared_ptr<ast::Node>> > ());
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > ().push_back((yystack_[0].value.as < std::shared_ptr<ast::Node> > ()));
    }
#line 1650 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 36:
#line 331 "./src/compiler/parser/parser.yy"
    {
        driver.ast_builder->into_anonymous_scope();
    }
#line 1658 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 37:
#line 336 "./src/compiler/parser/parser.yy"
    {
        driver.ast_builder->into_anonymous_scope();
    }
#line 1666 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 38:
#line 341 "./src/compiler/parser/parser.yy"
    {
        driver.ast_builder->into_anonymous_scope();
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > ().push_back(yystack_[4].value.as < std::shared_ptr<ast::Node> > ());
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > ().push_back(yystack_[2].value.as < std::shared_ptr<ast::Node> > ());
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > ().push_back(yystack_[0].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1677 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 39:
#line 350 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::BlockNode> > () = (yystack_[1].value.as < std::shared_ptr<ast::BlockNode> > ());
        driver.ast_builder->break_out_of_scope();
    }
#line 1686 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 40:
#line 356 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(driver.ast_builder->create_if(yystack_[5].value.as < std::shared_ptr<ast::Node> > (),yystack_[1].value.as < std::shared_ptr<ast::BlockNode> > (),{}));;
        driver.ast_builder->break_out_of_scope();
    }
#line 1695 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 41:
#line 361 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(driver.ast_builder->create_if(yystack_[6].value.as < std::shared_ptr<ast::Node> > (),yystack_[2].value.as < std::shared_ptr<ast::BlockNode> > (),yystack_[0].value.as < std::shared_ptr<ast::BlockNode> > ()));;
        //driver.ast_builder->break_out_of_scope();
    }
#line 1704 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 42:
#line 366 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(driver.ast_builder->create_for(yystack_[5].value.as < std::vector<std::shared_ptr<ast::Node>> > ()[0],yystack_[5].value.as < std::vector<std::shared_ptr<ast::Node>> > ()[1],yystack_[5].value.as < std::vector<std::shared_ptr<ast::Node>> > ()[2],yystack_[1].value.as < std::shared_ptr<ast::BlockNode> > ()));;
        driver.ast_builder->break_out_of_scope();
    }
#line 1713 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 43:
#line 371 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = yystack_[0].value.as < std::shared_ptr<ast::Node> > ();
    }
#line 1721 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 44:
#line 375 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(yystack_[0].value.as < std::shared_ptr<ast::GlobalVariableNode> > ());;
    }
#line 1729 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 45:
#line 379 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(driver.ast_builder->create_deep_copy(yystack_[2].value.as < std::shared_ptr<ast::Node> > (),yystack_[0].value.as < std::shared_ptr<ast::Node> > ()));;
    }
#line 1737 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 46:
#line 383 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(driver.ast_builder->create_binary_expression((yystack_[2].value.as < std::shared_ptr<ast::Node> > ()),(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()),"ADD"));;
    }
#line 1745 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 47:
#line 387 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(driver.ast_builder->create_binary_expression((yystack_[2].value.as < std::shared_ptr<ast::Node> > ()),(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()),"SUB"));;
    }
#line 1753 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 48:
#line 391 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(driver.ast_builder->create_binary_expression((yystack_[2].value.as < std::shared_ptr<ast::Node> > ()),(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()),"MUL"));;
    }
#line 1761 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 49:
#line 395 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(driver.ast_builder->create_binary_expression((yystack_[2].value.as < std::shared_ptr<ast::Node> > ()),(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()),"DIV"));;
    }
#line 1769 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 50:
#line 399 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(driver.ast_builder->create_binary_expression((yystack_[2].value.as < std::shared_ptr<ast::Node> > ()),(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()),"and"));;
    }
#line 1777 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 51:
#line 403 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(driver.ast_builder->create_binary_expression((yystack_[2].value.as < std::shared_ptr<ast::Node> > ()),(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()),"or"));;
    }
#line 1785 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 52:
#line 407 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(driver.ast_builder->create_binary_expression((yystack_[2].value.as < std::shared_ptr<ast::Node> > ()),(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()),">="));;
    }
#line 1793 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 53:
#line 411 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(driver.ast_builder->create_binary_expression((yystack_[2].value.as < std::shared_ptr<ast::Node> > ()),(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()),"<="));;
    }
#line 1801 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 54:
#line 415 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(driver.ast_builder->create_binary_expression((yystack_[2].value.as < std::shared_ptr<ast::Node> > ()),(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()),">"));;
    }
#line 1809 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 55:
#line 419 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(driver.ast_builder->create_binary_expression((yystack_[2].value.as < std::shared_ptr<ast::Node> > ()),(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()),"<"));;
    }
#line 1817 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 56:
#line 423 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(driver.ast_builder->create_binary_expression((yystack_[2].value.as < std::shared_ptr<ast::Node> > ()),(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()),"!="));;
    }
#line 1825 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 57:
#line 427 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(driver.ast_builder->create_binary_expression((yystack_[2].value.as < std::shared_ptr<ast::Node> > ()),(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()),"=="));;
    }
#line 1833 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 58:
#line 431 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = (yystack_[0].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1841 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 59:
#line 435 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(yystack_[0].value.as < std::shared_ptr<ast::ArrayNode> > ());;
    }
#line 1849 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 60:
#line 439 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(yystack_[0].value.as < std::shared_ptr<ast::AccessElementNode> > ());;
    }
#line 1857 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 61:
#line 443 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_minus(yystack_[0].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1865 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 62:
#line 447 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = (yystack_[1].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1873 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 63:
#line 452 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::ArrayNode> > () = driver.ast_builder->create_array((yystack_[1].value.as < std::vector<std::shared_ptr<ast::Node>> > ()));
    }
#line 1881 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 64:
#line 456 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::ArrayNode> > () = driver.ast_builder->create_array();
    }
#line 1889 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 65:
#line 461 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::AccessElementNode> > () = driver.ast_builder->create_access(yystack_[1].value.as < std::shared_ptr<ast::Node> > (),yystack_[0].value.as < std::string > ());
    }
#line 1897 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 66:
#line 466 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::GlobalVariableNode> > () = driver.ast_builder->create_global_variable_definition(yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1905 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 67:
#line 471 "./src/compiler/parser/parser.yy"
    {
        if (driver.ast_builder->exist(yystack_[2].value.as < std::string > ()))
        {
            auto target = driver.ast_builder->get_named_node(yystack_[2].value.as < std::string > ());
            yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(driver.ast_builder->create_assignment(target,(yystack_[0].value.as < std::shared_ptr<ast::Node> > ())));;
        }
        else
        {
            yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(driver.ast_builder->create_variable_definition(yystack_[2].value.as < std::string > (),(yystack_[0].value.as < std::shared_ptr<ast::Node> > ())));;
        }
    }
#line 1921 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 68:
#line 483 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(driver.ast_builder->create_assignment(yystack_[2].value.as < std::shared_ptr<ast::AccessElementNode> > (),(yystack_[0].value.as < std::shared_ptr<ast::Node> > ())));;
    }
#line 1929 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 69:
#line 488 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(yystack_[0].value.as < std::shared_ptr<ast::CallFunctionNode> > ());
    }
#line 1937 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 70:
#line 492 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(driver.ast_builder->create_string(yystack_[0].value.as < std::string > ()));
    }
#line 1945 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 71:
#line 496 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(driver.ast_builder->create_float(yystack_[0].value.as < double > ()));
    }
#line 1953 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 72:
#line 500 "./src/compiler/parser/parser.yy"
    { 
        yylhs.value.as < std::shared_ptr<ast::Node> > () = ast::Node::create(driver.ast_builder->create_integer(yystack_[0].value.as < long long > ()));;
    }
#line 1961 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 73:
#line 504 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = yystack_[0].value.as < std::shared_ptr<ast::Node> > ();
    }
#line 1969 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 74:
#line 509 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::CallFunctionNode> > () = driver.ast_builder->create_call(yystack_[3].value.as < std::string > (),yystack_[1].value.as < std::vector<std::shared_ptr<ast::Node>> > ());
    }
#line 1977 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 75:
#line 513 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::CallFunctionNode> > () = driver.ast_builder->create_call(yystack_[2].value.as < std::string > (),{});
    }
#line 1985 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 76:
#line 517 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::CallFunctionNode> > () = driver.ast_builder->create_call(yystack_[3].value.as < std::shared_ptr<ast::AccessElementNode> > (),yystack_[1].value.as < std::vector<std::shared_ptr<ast::Node>> > ());
    }
#line 1993 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 77:
#line 521 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::CallFunctionNode> > () = driver.ast_builder->create_call(yystack_[2].value.as < std::shared_ptr<ast::AccessElementNode> > (),{});
    }
#line 2001 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 78:
#line 526 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->get_named_node(yystack_[0].value.as < std::string > ());
    }
#line 2009 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;


#line 2013 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = static_cast<state_type> (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char Parser::yypact_ninf_ = -104;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
      79,  -104,  -104,     4,   155,   155,    98,  -104,   155,     8,
    -104,  -104,  -104,    17,  -104,    79,  -104,    24,  -104,  -104,
      -8,     0,  -104,    -8,   155,    20,   299,  -104,     6,  -104,
    -104,  -104,  -104,  -104,   155,   117,    43,   240,  -104,   -14,
     299,   261,    70,  -104,  -104,  -104,  -104,    -1,  -104,     3,
      36,   191,    51,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,  -104,   155,   136,   299,
    -104,    -2,  -104,   155,  -104,   155,   155,  -104,  -104,    40,
     155,    77,    44,    18,    63,    52,   299,   311,   311,    69,
      69,    69,    69,    69,    69,    15,    15,    43,    43,   299,
    -104,    47,  -104,   299,   280,   299,    87,  -104,   299,    55,
    -104,  -104,    89,    96,    -8,    59,    60,    37,    61,    79,
    -104,   155,  -104,  -104,   155,    62,  -104,     3,  -104,   100,
      96,    79,    81,   299,   206,  -104,    77,  -104,   155,    82,
    -104,  -104,  -104,   225,    71,  -104,  -104,    73,  -104,    84,
      86,    79,    91,  -104
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,    14,    19,    78,     0,     0,     0,    36,     0,     0,
      70,    72,    71,     0,     2,     3,     4,     0,     8,    10,
       0,     0,    11,     0,     0,     0,     9,    59,    60,    44,
      43,    58,    69,    73,     0,     0,    61,     0,    64,     0,
      34,     0,     0,     1,     5,     7,     6,     0,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    65,     0,     0,    67,
      75,     0,    62,     0,    63,     0,     0,    32,    31,     0,
      29,     0,     0,     0,     0,     0,    45,    50,    51,    57,
      56,    52,    53,    54,    55,    46,    47,    48,    49,    68,
      77,     0,    74,    35,     0,    66,     0,    30,    28,     0,
      13,    22,     0,    18,     0,     0,     0,    17,     0,     0,
      76,     0,    33,    12,     0,     0,    23,     0,    20,     0,
      16,     0,     0,    38,     0,    21,     0,    25,     0,     0,
      42,    26,    24,     0,    40,    27,    37,     0,    41,     0,
       0,     0,     0,    39
  };

  const signed char
  Parser::yypgoto_[] =
  {
    -104,  -104,   -46,  -104,   111,  -104,  -104,  -104,  -104,  -104,
    -104,  -104,    14,  -104,  -104,  -103,  -104,   -62,   -18,  -104,
     -23,  -104,  -104,  -104,  -104,    -4,  -104,  -104,  -104,  -104,
    -104,  -104,  -104
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   113,   114,   115,   116,   117,    82,    48,    79,
      39,    24,   147,    25,   148,    26,    27,    28,    29,    30,
      31,    32,    33
  };

  const unsigned char
  Parser::yytable_[] =
  {
      36,    37,    40,    81,    41,    50,     1,    77,     2,    80,
     125,     3,    71,    34,    73,    67,    42,    43,    74,   109,
      51,    47,   111,     4,    45,   112,    73,   125,   102,    78,
      69,    40,     5,    35,     6,    68,    64,    65,     7,    66,
       8,   111,    49,     9,   129,   101,    10,    11,    12,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    52,    99,    40,   137,    46,    66,   106,   103,
     107,   104,   105,   132,   142,    73,   108,   120,    83,    76,
      85,   136,     1,    80,     2,   139,   110,     3,    62,    63,
      64,    65,   118,    66,   119,   122,   126,   123,   124,     4,
     111,   127,   128,   131,   135,   152,     3,   146,     5,   138,
       6,   140,   144,   150,     7,   149,     8,   133,     4,     9,
     134,   153,    10,    11,    12,     3,    44,     5,   151,     6,
      38,   130,     0,     7,   143,     8,     0,     4,     9,     0,
       0,    10,    11,    12,     3,     0,     5,    70,     6,     0,
       0,     0,     7,     0,     8,     0,     4,     9,     0,     0,
      10,    11,    12,     3,     0,     5,   100,     6,     0,     0,
       0,     7,     0,     8,     0,     4,     9,     0,     0,    10,
      11,    12,     0,     0,     5,     0,     6,     0,     0,     0,
       7,     0,     8,     0,     0,     9,     0,     0,    10,    11,
      12,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,     0,    66,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     0,
      66,     0,     0,    84,     0,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   141,    66,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,     0,    66,     0,     0,   145,     0,     0,
      72,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,     0,    66,     0,     0,     0,    75,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,     0,    66,     0,     0,     0,   121,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,     0,    66,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,     0,    66
  };

  const short
  Parser::yycheck_[] =
  {
       4,     5,     6,    49,     8,    23,     3,     8,     5,     6,
     113,     8,    35,     9,    28,     9,     8,     0,    32,    81,
      24,    29,     4,    20,     0,     7,    28,   130,    30,    30,
      34,    35,    29,    29,    31,    29,    21,    22,    35,    24,
      37,     4,    42,    40,     7,    68,    43,    44,    45,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    42,    67,    68,   127,    42,    24,    28,    73,
      30,    75,    76,   119,   136,    28,    80,    30,    42,     9,
      29,   127,     3,     6,     5,   131,    42,     8,    19,    20,
      21,    22,    29,    24,    42,     8,   114,    42,     9,    20,
       4,    42,    42,    42,    42,   151,     8,    36,    29,     9,
      31,    30,    30,    29,    35,    42,    37,   121,    20,    40,
     124,    30,    43,    44,    45,     8,    15,    29,    42,    31,
      32,   117,    -1,    35,   138,    37,    -1,    20,    40,    -1,
      -1,    43,    44,    45,     8,    -1,    29,    30,    31,    -1,
      -1,    -1,    35,    -1,    37,    -1,    20,    40,    -1,    -1,
      43,    44,    45,     8,    -1,    29,    30,    31,    -1,    -1,
      -1,    35,    -1,    37,    -1,    20,    40,    -1,    -1,    43,
      44,    45,    -1,    -1,    29,    -1,    31,    -1,    -1,    -1,
      35,    -1,    37,    -1,    -1,    40,    -1,    -1,    43,    44,
      45,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    24,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    -1,    42,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    42,    24,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    -1,    42,    -1,    -1,
      30,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    -1,    -1,    28,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    -1,    -1,    28,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    24,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    24
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     3,     5,     8,    20,    29,    31,    35,    37,    40,
      43,    44,    45,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    67,    69,    71,    72,    73,    74,
      75,    76,    77,    78,     9,    29,    71,    71,    32,    66,
      71,    71,     8,     0,    50,     0,    42,    29,    64,    42,
      64,    71,    42,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    24,     9,    29,    71,
      30,    66,    30,    28,    32,    28,     9,     8,    30,    65,
       6,    48,    63,    42,    42,    29,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      30,    66,    30,    71,    71,    71,    28,    30,    71,    63,
      42,     4,     7,    58,    59,    60,    61,    62,    29,    42,
      30,    28,     8,    42,     9,    61,    64,    42,    42,     7,
      58,    42,    48,    71,    71,    42,    48,    63,     9,    48,
      30,    42,    63,    71,    30,    42,    36,    68,    70,    42,
      29,    42,    48,    30
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    46,    47,    48,    49,    49,    50,    50,    50,    51,
      52,    52,    53,    53,    54,    55,    56,    56,    56,    57,
      58,    58,    59,    60,    61,    61,    62,    62,    63,    63,
      64,    64,    65,    65,    66,    66,    67,    68,    69,    70,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    72,    72,    73,    74,    75,    75,    76,
      76,    76,    76,    76,    77,    77,    77,    77,    78
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     2,     2,     2,     1,     1,
       1,     1,     5,     4,     1,     2,     5,     4,     4,     1,
       2,     3,     1,     2,     4,     3,     4,     5,     2,     1,
       3,     2,     1,     3,     1,     3,     1,     1,     6,     6,
       7,     8,     6,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     2,     3,     3,     2,     2,     4,     3,     3,     1,
       1,     1,     1,     1,     4,     3,     4,     3,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "FUNCTION_DEFINITION",
  "METHOD_DEFINITION", "CLASS_DEFINITION", "RETURN", "MEMBER_IDENTIFIER",
  "IDENTIFIER", "EQUAL", "ARROW", "OP_AND", "OP_OR", "OP_EQUAL",
  "OP_NOT_EQUAL", "OP_MORE_EQUAL", "OP_LESS_EQUAL", "OP_MORE", "OP_LESS",
  "PLUS", "MINUS", "ASTERISK", "SLASH", "UMINUS", "DOT_IDENTIFIER", "USE",
  "COLON", "SEMICOLON", "COMMA", "LEFT_PARENTHESIS", "RIGHT_PARENTHESIS",
  "LEFT_CURLY_BRACE", "RIGHT_CURLY_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET",
  "IF", "ELSE", "FOR", "IN", "WHILE", "GLOBAL", "IMPORT", "EOL",
  "STRING_LITERAL", "INT_LITERAL", "FLOAT_LITERAL", "$accept", "program",
  "block", "lines", "line", "line_content", "definition",
  "function_definition", "function_name", "function_start",
  "class_definition", "class_name", "methods", "method_name",
  "method_start", "method_definition", "members_definition",
  "return_value", "arguments", "definition_arguments", "expressions",
  "if_start", "else_start", "for_start", "else_body", "expression",
  "array", "access", "global_variable_definition", "assign_variable",
  "monomial", "call", "named_value", YY_NULLPTR
  };


  const short
  Parser::yyrline_[] =
  {
       0,   147,   147,   153,   158,   162,   168,   172,   176,   182,
     187,   191,   196,   201,   207,   213,   221,   226,   231,   237,
     243,   247,   253,   259,   268,   273,   279,   283,   289,   293,
     298,   302,   307,   311,   320,   324,   330,   335,   340,   349,
     355,   360,   365,   370,   374,   378,   382,   386,   390,   394,
     398,   402,   406,   410,   414,   418,   422,   426,   430,   434,
     438,   442,   446,   451,   455,   460,   465,   470,   482,   487,
     491,   495,   499,   503,   508,   512,   516,   520,   525
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
    };
    const int user_token_number_max_ = 300;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 5 "./src/compiler/parser/parser.yy"
} // blawn
#line 2505 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"

#line 529 "./src/compiler/parser/parser.yy"


void blawn::Parser::error( const location_type &l, const std::string &err_message )
{
    std::cerr << "Error: " << err_message << " at " << l << "\n";
    exit(1);
} 
