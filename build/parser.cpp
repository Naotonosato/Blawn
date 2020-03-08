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
#line 34 "./src/compiler/parser/parser.yy"

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
namespace Blawn {
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
      case 50: // FLOAT_LITERAL
        value.move< double > (std::move (that.value));
        break;

      case 49: // INT_LITERAL
        value.move< long long > (std::move (that.value));
        break;

      case 87: // access
        value.move< std::shared_ptr<ast::AccessNode> > (std::move (that.value));
        break;

      case 67: // method_definition
        value.move< std::shared_ptr<ast::GenericFunctionNode> > (std::move (that.value));
        break;

      case 55: // line
      case 57: // line_content
      case 58: // definition
      case 59: // function_definition
      case 61: // class_definition
      case 63: // c_type_definition
      case 72: // C_returns
      case 73: // return_value
      case 76: // globals_definition
      case 79: // c_function_declaration
      case 85: // expression
      case 86: // list
      case 88: // assign_variable
      case 89: // monomial
      case 90: // call
      case 91: // variable
        value.move< std::shared_ptr<ast::NodeBase> > (std::move (that.value));
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 6: // C_TYPE_DEFINITION
      case 7: // C_FUNCTION_DECLARATION
      case 9: // C_FUNCTION
      case 10: // MEMBER_IDENTIFIER
      case 11: // IDENTIFIER
      case 27: // DOT_IDENTIFIER
      case 48: // STRING_LITERAL
      case 60: // function_start
      case 62: // class_start
      case 64: // c_type_start
      case 66: // method_start
        value.move< std::string > (std::move (that.value));
        break;

      case 65: // methods
        value.move< std::vector<std::shared_ptr<ast::GenericFunctionNode>> > (std::move (that.value));
        break;

      case 53: // block
      case 54: // lines
      case 68: // members_definition
      case 69: // C_members_definition
      case 71: // C_arguments
      case 78: // globals_variables
      case 80: // expressions
      case 83: // for_start
      case 84: // else_body
        value.move< std::vector<std::shared_ptr<ast::NodeBase>> > (std::move (that.value));
        break;

      case 70: // C_type_identifier
      case 74: // arguments
      case 75: // definition_arguments
        value.move< std::vector<std::string> > (std::move (that.value));
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
      case 50: // FLOAT_LITERAL
        value.copy< double > (YY_MOVE (that.value));
        break;

      case 49: // INT_LITERAL
        value.copy< long long > (YY_MOVE (that.value));
        break;

      case 87: // access
        value.copy< std::shared_ptr<ast::AccessNode> > (YY_MOVE (that.value));
        break;

      case 67: // method_definition
        value.copy< std::shared_ptr<ast::GenericFunctionNode> > (YY_MOVE (that.value));
        break;

      case 55: // line
      case 57: // line_content
      case 58: // definition
      case 59: // function_definition
      case 61: // class_definition
      case 63: // c_type_definition
      case 72: // C_returns
      case 73: // return_value
      case 76: // globals_definition
      case 79: // c_function_declaration
      case 85: // expression
      case 86: // list
      case 88: // assign_variable
      case 89: // monomial
      case 90: // call
      case 91: // variable
        value.copy< std::shared_ptr<ast::NodeBase> > (YY_MOVE (that.value));
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 6: // C_TYPE_DEFINITION
      case 7: // C_FUNCTION_DECLARATION
      case 9: // C_FUNCTION
      case 10: // MEMBER_IDENTIFIER
      case 11: // IDENTIFIER
      case 27: // DOT_IDENTIFIER
      case 48: // STRING_LITERAL
      case 60: // function_start
      case 62: // class_start
      case 64: // c_type_start
      case 66: // method_start
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case 65: // methods
        value.copy< std::vector<std::shared_ptr<ast::GenericFunctionNode>> > (YY_MOVE (that.value));
        break;

      case 53: // block
      case 54: // lines
      case 68: // members_definition
      case 69: // C_members_definition
      case 71: // C_arguments
      case 78: // globals_variables
      case 80: // expressions
      case 83: // for_start
      case 84: // else_body
        value.copy< std::vector<std::shared_ptr<ast::NodeBase>> > (YY_MOVE (that.value));
        break;

      case 70: // C_type_identifier
      case 74: // arguments
      case 75: // definition_arguments
        value.copy< std::vector<std::string> > (YY_MOVE (that.value));
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
      case 50: // FLOAT_LITERAL
        value.move< double > (YY_MOVE (s.value));
        break;

      case 49: // INT_LITERAL
        value.move< long long > (YY_MOVE (s.value));
        break;

      case 87: // access
        value.move< std::shared_ptr<ast::AccessNode> > (YY_MOVE (s.value));
        break;

      case 67: // method_definition
        value.move< std::shared_ptr<ast::GenericFunctionNode> > (YY_MOVE (s.value));
        break;

      case 55: // line
      case 57: // line_content
      case 58: // definition
      case 59: // function_definition
      case 61: // class_definition
      case 63: // c_type_definition
      case 72: // C_returns
      case 73: // return_value
      case 76: // globals_definition
      case 79: // c_function_declaration
      case 85: // expression
      case 86: // list
      case 88: // assign_variable
      case 89: // monomial
      case 90: // call
      case 91: // variable
        value.move< std::shared_ptr<ast::NodeBase> > (YY_MOVE (s.value));
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 6: // C_TYPE_DEFINITION
      case 7: // C_FUNCTION_DECLARATION
      case 9: // C_FUNCTION
      case 10: // MEMBER_IDENTIFIER
      case 11: // IDENTIFIER
      case 27: // DOT_IDENTIFIER
      case 48: // STRING_LITERAL
      case 60: // function_start
      case 62: // class_start
      case 64: // c_type_start
      case 66: // method_start
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case 65: // methods
        value.move< std::vector<std::shared_ptr<ast::GenericFunctionNode>> > (YY_MOVE (s.value));
        break;

      case 53: // block
      case 54: // lines
      case 68: // members_definition
      case 69: // C_members_definition
      case 71: // C_arguments
      case 78: // globals_variables
      case 80: // expressions
      case 83: // for_start
      case 84: // else_body
        value.move< std::vector<std::shared_ptr<ast::NodeBase>> > (YY_MOVE (s.value));
        break;

      case 70: // C_type_identifier
      case 74: // arguments
      case 75: // definition_arguments
        value.move< std::vector<std::string> > (YY_MOVE (s.value));
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
      case 50: // FLOAT_LITERAL
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case 49: // INT_LITERAL
        value.YY_MOVE_OR_COPY< long long > (YY_MOVE (that.value));
        break;

      case 87: // access
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::AccessNode> > (YY_MOVE (that.value));
        break;

      case 67: // method_definition
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::GenericFunctionNode> > (YY_MOVE (that.value));
        break;

      case 55: // line
      case 57: // line_content
      case 58: // definition
      case 59: // function_definition
      case 61: // class_definition
      case 63: // c_type_definition
      case 72: // C_returns
      case 73: // return_value
      case 76: // globals_definition
      case 79: // c_function_declaration
      case 85: // expression
      case 86: // list
      case 88: // assign_variable
      case 89: // monomial
      case 90: // call
      case 91: // variable
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::NodeBase> > (YY_MOVE (that.value));
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 6: // C_TYPE_DEFINITION
      case 7: // C_FUNCTION_DECLARATION
      case 9: // C_FUNCTION
      case 10: // MEMBER_IDENTIFIER
      case 11: // IDENTIFIER
      case 27: // DOT_IDENTIFIER
      case 48: // STRING_LITERAL
      case 60: // function_start
      case 62: // class_start
      case 64: // c_type_start
      case 66: // method_start
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 65: // methods
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<ast::GenericFunctionNode>> > (YY_MOVE (that.value));
        break;

      case 53: // block
      case 54: // lines
      case 68: // members_definition
      case 69: // C_members_definition
      case 71: // C_arguments
      case 78: // globals_variables
      case 80: // expressions
      case 83: // for_start
      case 84: // else_body
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<ast::NodeBase>> > (YY_MOVE (that.value));
        break;

      case 70: // C_type_identifier
      case 74: // arguments
      case 75: // definition_arguments
        value.YY_MOVE_OR_COPY< std::vector<std::string> > (YY_MOVE (that.value));
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
      case 50: // FLOAT_LITERAL
        value.move< double > (YY_MOVE (that.value));
        break;

      case 49: // INT_LITERAL
        value.move< long long > (YY_MOVE (that.value));
        break;

      case 87: // access
        value.move< std::shared_ptr<ast::AccessNode> > (YY_MOVE (that.value));
        break;

      case 67: // method_definition
        value.move< std::shared_ptr<ast::GenericFunctionNode> > (YY_MOVE (that.value));
        break;

      case 55: // line
      case 57: // line_content
      case 58: // definition
      case 59: // function_definition
      case 61: // class_definition
      case 63: // c_type_definition
      case 72: // C_returns
      case 73: // return_value
      case 76: // globals_definition
      case 79: // c_function_declaration
      case 85: // expression
      case 86: // list
      case 88: // assign_variable
      case 89: // monomial
      case 90: // call
      case 91: // variable
        value.move< std::shared_ptr<ast::NodeBase> > (YY_MOVE (that.value));
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 6: // C_TYPE_DEFINITION
      case 7: // C_FUNCTION_DECLARATION
      case 9: // C_FUNCTION
      case 10: // MEMBER_IDENTIFIER
      case 11: // IDENTIFIER
      case 27: // DOT_IDENTIFIER
      case 48: // STRING_LITERAL
      case 60: // function_start
      case 62: // class_start
      case 64: // c_type_start
      case 66: // method_start
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 65: // methods
        value.move< std::vector<std::shared_ptr<ast::GenericFunctionNode>> > (YY_MOVE (that.value));
        break;

      case 53: // block
      case 54: // lines
      case 68: // members_definition
      case 69: // C_members_definition
      case 71: // C_arguments
      case 78: // globals_variables
      case 80: // expressions
      case 83: // for_start
      case 84: // else_body
        value.move< std::vector<std::shared_ptr<ast::NodeBase>> > (YY_MOVE (that.value));
        break;

      case 70: // C_type_identifier
      case 74: // arguments
      case 75: // definition_arguments
        value.move< std::vector<std::string> > (YY_MOVE (that.value));
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
      case 50: // FLOAT_LITERAL
        value.copy< double > (that.value);
        break;

      case 49: // INT_LITERAL
        value.copy< long long > (that.value);
        break;

      case 87: // access
        value.copy< std::shared_ptr<ast::AccessNode> > (that.value);
        break;

      case 67: // method_definition
        value.copy< std::shared_ptr<ast::FunctionNode> > (that.value);
        break;

      case 55: // line
      case 57: // line_content
      case 58: // definition
      case 59: // function_definition
      case 61: // class_definition
      case 63: // c_type_definition
      case 72: // C_returns
      case 73: // return_value
      case 76: // globals_definition
      case 79: // c_function_declaration
      case 85: // expression
      case 86: // list
      case 88: // assign_variable
      case 89: // monomial
      case 90: // call
      case 91: // variable
        value.copy< std::shared_ptr<ast::Node> > (that.value);
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 6: // C_TYPE_DEFINITION
      case 7: // C_FUNCTION_DECLARATION
      case 9: // C_FUNCTION
      case 10: // MEMBER_IDENTIFIER
      case 11: // IDENTIFIER
      case 27: // DOT_IDENTIFIER
      case 48: // STRING_LITERAL
      case 60: // function_start
      case 62: // class_start
      case 64: // c_type_start
      case 66: // method_start
        value.copy< std::string > (that.value);
        break;

      case 65: // methods
        value.copy< std::vector<std::shared_ptr<ast::FunctionNode>> > (that.value);
        break;

      case 53: // block
      case 54: // lines
      case 68: // members_definition
      case 69: // C_members_definition
      case 71: // C_arguments
      case 78: // globals_variables
      case 80: // expressions
      case 83: // for_start
      case 84: // else_body
        value.copy< std::vector<std::shared_ptr<ast::Node>> > (that.value);
        break;

      case 70: // C_type_identifier
      case 74: // arguments
      case 75: // definition_arguments
        value.copy< std::vector<std::string> > (that.value);
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
      case 50: // FLOAT_LITERAL
        value.move< double > (that.value);
        break;

      case 49: // INT_LITERAL
        value.move< long long > (that.value);
        break;

      case 87: // access
        value.move< std::shared_ptr<ast::AccessNode> > (that.value);
        break;

      case 67: // method_definition
        value.move< std::shared_ptr<ast::FunctionNode> > (that.value);
        break;

      case 55: // line
      case 57: // line_content
      case 58: // definition
      case 59: // function_definition
      case 61: // class_definition
      case 63: // c_type_definition
      case 72: // C_returns
      case 73: // return_value
      case 76: // globals_definition
      case 79: // c_function_declaration
      case 85: // expression
      case 86: // list
      case 88: // assign_variable
      case 89: // monomial
      case 90: // call
      case 91: // variable
        value.move< std::shared_ptr<ast::Node> > (that.value);
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 6: // C_TYPE_DEFINITION
      case 7: // C_FUNCTION_DECLARATION
      case 9: // C_FUNCTION
      case 10: // MEMBER_IDENTIFIER
      case 11: // IDENTIFIER
      case 27: // DOT_IDENTIFIER
      case 48: // STRING_LITERAL
      case 60: // function_start
      case 62: // class_start
      case 64: // c_type_start
      case 66: // method_start
        value.move< std::string > (that.value);
        break;

      case 65: // methods
        value.move< std::vector<std::shared_ptr<ast::FunctionNode>> > (that.value);
        break;

      case 53: // block
      case 54: // lines
      case 68: // members_definition
      case 69: // C_members_definition
      case 71: // C_arguments
      case 78: // globals_variables
      case 80: // expressions
      case 83: // for_start
      case 84: // else_body
        value.move< std::vector<std::shared_ptr<ast::Node>> > (that.value);
        break;

      case 70: // C_type_identifier
      case 74: // arguments
      case 75: // definition_arguments
        value.move< std::vector<std::string> > (that.value);
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
      case 50: // FLOAT_LITERAL
        yylhs.value.emplace< double > ();
        break;

      case 49: // INT_LITERAL
        yylhs.value.emplace< long long > ();
        break;

      case 87: // access
        yylhs.value.emplace< std::shared_ptr<ast::AccessNode> > ();
        break;

      case 67: // method_definition
        yylhs.value.emplace< std::shared_ptr<ast::GenericFunctionNode> > ();
        break;

      case 55: // line
      case 57: // line_content
      case 58: // definition
      case 59: // function_definition
      case 61: // class_definition
      case 63: // c_type_definition
      case 72: // C_returns
      case 73: // return_value
      case 76: // globals_definition
      case 79: // c_function_declaration
      case 85: // expression
      case 86: // list
      case 88: // assign_variable
      case 89: // monomial
      case 90: // call
      case 91: // variable
        yylhs.value.emplace< std::shared_ptr<ast::NodeBase> > ();
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 6: // C_TYPE_DEFINITION
      case 7: // C_FUNCTION_DECLARATION
      case 9: // C_FUNCTION
      case 10: // MEMBER_IDENTIFIER
      case 11: // IDENTIFIER
      case 27: // DOT_IDENTIFIER
      case 48: // STRING_LITERAL
      case 60: // function_start
      case 62: // class_start
      case 64: // c_type_start
      case 66: // method_start
        yylhs.value.emplace< std::string > ();
        break;

      case 65: // methods
        yylhs.value.emplace< std::vector<std::shared_ptr<ast::GenericFunctionNode>> > ();
        break;

      case 53: // block
      case 54: // lines
      case 68: // members_definition
      case 69: // C_members_definition
      case 71: // C_arguments
      case 78: // globals_variables
      case 80: // expressions
      case 83: // for_start
      case 84: // else_body
        yylhs.value.emplace< std::vector<std::shared_ptr<ast::NodeBase>> > ();
        break;

      case 70: // C_type_identifier
      case 74: // arguments
      case 75: // definition_arguments
        yylhs.value.emplace< std::vector<std::string> > ();
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
#line 145 "./src/compiler/parser/parser.yy"
    {
        driver.ast_generator->break_out_of_namespace();
        driver.ast_generator->generate(std::move(yystack_[0].value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ()));
    }
#line 1236 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 3:
#line 151 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::NodeBase>> > () = std::move(yystack_[0].value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ());
        yylhs.value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ().push_back(driver.ast_generator->create_block_end());
    }
#line 1245 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 4:
#line 157 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ().push_back(std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ()));
    }
#line 1253 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 5:
#line 161 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::NodeBase>> > () = std::move(yystack_[1].value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ());
        yylhs.value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ().push_back(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ());
    }
#line 1262 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 6:
#line 167 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = std::move(yystack_[1].value.as < std::shared_ptr<ast::NodeBase> > ());
    }
#line 1270 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 7:
#line 171 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = std::move(yystack_[1].value.as < std::shared_ptr<ast::NodeBase> > ());
    }
#line 1278 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 8:
#line 175 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ();
    }
#line 1286 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 9:
#line 179 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->no_value_node;
    }
#line 1294 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 11:
#line 186 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ());
    }
#line 1302 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 12:
#line 191 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ());
    }
#line 1310 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 13:
#line 195 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ());
    }
#line 1318 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 14:
#line 199 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ());
    }
#line 1326 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 15:
#line 203 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ());
    }
#line 1334 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 16:
#line 207 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ());
    }
#line 1342 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 17:
#line 212 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->add_function(yystack_[5].value.as < std::string > (),std::move(yystack_[4].value.as < std::vector<std::string> > ()),std::move(yystack_[2].value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ()),std::move(yystack_[1].value.as < std::shared_ptr<ast::NodeBase> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1351 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 18:
#line 217 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->add_function(yystack_[4].value.as < std::string > (),std::move(yystack_[3].value.as < std::vector<std::string> > ()),{},std::move(yystack_[1].value.as < std::shared_ptr<ast::NodeBase> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1360 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 19:
#line 223 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
        driver.ast_generator->into_namespace(yystack_[0].value.as < std::string > ());
    }
#line 1369 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 20:
#line 229 "./src/compiler/parser/parser.yy"
    { 
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = std::move(driver.ast_generator->create_class(yystack_[4].value.as < std::string > (),yystack_[3].value.as < std::vector<std::string> > (),yystack_[1].value.as < std::vector<std::shared_ptr<ast::NodeBase>> > (),yystack_[0].value.as < std::vector<std::shared_ptr<ast::GenericFunctionNode>> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1378 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 21:
#line 234 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = std::move(driver.ast_generator->create_class(yystack_[3].value.as < std::string > (),yystack_[2].value.as < std::vector<std::string> > (),yystack_[0].value.as < std::vector<std::shared_ptr<ast::NodeBase>> > (),{}));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1387 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 22:
#line 239 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = std::move(driver.ast_generator->create_class(yystack_[3].value.as < std::string > (),yystack_[2].value.as < std::vector<std::string> > (),{},yystack_[0].value.as < std::vector<std::shared_ptr<ast::GenericFunctionNode>> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1396 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 23:
#line 245 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
        driver.ast_generator->into_namespace(yystack_[0].value.as < std::string > ());
    }
#line 1405 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 24:
#line 251 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = std::move(driver.ast_generator->create_C_type(yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1414 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 25:
#line 257 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
        driver.ast_generator->into_namespace(yystack_[0].value.as < std::string > ());
    }
#line 1423 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 26:
#line 263 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::GenericFunctionNode>> > ().push_back(yystack_[1].value.as < std::shared_ptr<ast::GenericFunctionNode> > ());
    }
#line 1431 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 27:
#line 267 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::GenericFunctionNode>> > () = std::move(yystack_[2].value.as < std::vector<std::shared_ptr<ast::GenericFunctionNode>> > ());
        yylhs.value.as < std::vector<std::shared_ptr<ast::GenericFunctionNode>> > ().push_back(yystack_[1].value.as < std::shared_ptr<ast::GenericFunctionNode> > ());
    }
#line 1440 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 28:
#line 273 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
        driver.ast_generator->into_namespace(yystack_[0].value.as < std::string > ());
    }
#line 1449 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 29:
#line 279 "./src/compiler/parser/parser.yy"
    {
        auto args = std::move(yystack_[3].value.as < std::vector<std::string> > ());
        args.insert(args.begin(),"self");
        yylhs.value.as < std::shared_ptr<ast::GenericFunctionNode> > () = driver.ast_generator->add_function(yystack_[4].value.as < std::string > (),std::move(args),std::move(yystack_[1].value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1460 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 30:
#line 286 "./src/compiler/parser/parser.yy"
    {
        auto args = std::move(yystack_[2].value.as < std::vector<std::string> > ());
        args.insert(args.begin(),"self");
        yylhs.value.as < std::shared_ptr<ast::GenericFunctionNode> > () = driver.ast_generator->add_function(yystack_[3].value.as < std::string > (),std::move(args),{driver.ast_generator->create_block_end()},std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1471 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 31:
#line 294 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ().push_back(driver.ast_generator->create_assign(yystack_[3].value.as < std::string > (),std::move(yystack_[1].value.as < std::shared_ptr<ast::NodeBase> > ()),false));
    }
#line 1479 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 32:
#line 298 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::NodeBase>> > () = std::move(yystack_[4].value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ());
        yylhs.value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ().push_back(driver.ast_generator->create_assign(yystack_[3].value.as < std::string > (),std::move(yystack_[1].value.as < std::shared_ptr<ast::NodeBase> > ()),false));
    }
#line 1488 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 33:
#line 304 "./src/compiler/parser/parser.yy"
    {
        std::string type_identifier = join(yystack_[1].value.as < std::vector<std::string> > ());
        auto assign_value = driver.ast_generator->create_C_member(type_identifier);
        yylhs.value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ().push_back(driver.ast_generator->create_assign(yystack_[3].value.as < std::string > (),std::move(assign_value),false));
    }
#line 1498 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 34:
#line 310 "./src/compiler/parser/parser.yy"
    {
        std::string type_identifier = join(yystack_[1].value.as < std::vector<std::string> > ());
        auto assign_value = driver.ast_generator->create_C_member(type_identifier);
        yylhs.value.as < std::vector<std::shared_ptr<ast::NodeBase>> > () = std::move(yystack_[4].value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ());
        yylhs.value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ().push_back(driver.ast_generator->create_assign(yystack_[3].value.as < std::string > (),std::move(assign_value),false));
    }
#line 1509 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 35:
#line 318 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::string> > ().push_back(yystack_[0].value.as < std::string > ());
    }
#line 1517 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 36:
#line 322 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::string> > () = std::move(yystack_[1].value.as < std::vector<std::string> > ());
        yylhs.value.as < std::vector<std::string> > ().push_back(yystack_[0].value.as < std::string > ());
    }
#line 1526 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 37:
#line 328 "./src/compiler/parser/parser.yy"
    {
        std::string type_identifier = join(yystack_[0].value.as < std::vector<std::string> > ());
        auto assign_value = driver.ast_generator->create_C_member(type_identifier);
        yylhs.value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ().push_back(assign_value);
    }
#line 1536 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 38:
#line 334 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::NodeBase>> > () = std::move(yystack_[2].value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ());
        std::string type_identifier = join(yystack_[0].value.as < std::vector<std::string> > ());
        auto assign_value = driver.ast_generator->create_C_member(type_identifier);
        yylhs.value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ().push_back(assign_value);
    }
#line 1547 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 39:
#line 342 "./src/compiler/parser/parser.yy"
    {
        std::string type_identifier = join(yystack_[0].value.as < std::vector<std::string> > ());
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_C_member(type_identifier);
    }
#line 1556 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 40:
#line 348 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ();
    }
#line 1564 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 41:
#line 352 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = nullptr;
    }
#line 1572 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 42:
#line 357 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::string> > () = std::move(yystack_[1].value.as < std::vector<std::string> > ());
    }
#line 1580 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 43:
#line 361 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::string> > () = {};
    }
#line 1588 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 44:
#line 366 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::string> > ().push_back(yystack_[0].value.as < std::string > ());
        driver.ast_generator->add_argument(yystack_[0].value.as < std::string > ());
    }
#line 1597 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 45:
#line 371 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::string> > () = std::move(yystack_[2].value.as < std::vector<std::string> > ());
        yylhs.value.as < std::vector<std::string> > ().push_back(yystack_[0].value.as < std::string > ());
        driver.ast_generator->add_argument(yystack_[0].value.as < std::string > ());
    }
#line 1607 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 46:
#line 378 "./src/compiler/parser/parser.yy"
    {
        is_global = NOT_GLOBAL;
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->no_value_node;
    }
#line 1616 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 47:
#line 384 "./src/compiler/parser/parser.yy"
    {
        is_global = GLOBAL;
    }
#line 1624 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 48:
#line 389 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ().push_back(std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ()));
    }
#line 1632 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 49:
#line 393 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::NodeBase>> > () = std::move(yystack_[2].value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ());
        yylhs.value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ().push_back(std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ()));
    }
#line 1641 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 50:
#line 399 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->declare_C_function(yystack_[7].value.as < std::string > (),yystack_[4].value.as < std::vector<std::shared_ptr<ast::NodeBase>> > (),yystack_[1].value.as < std::shared_ptr<ast::NodeBase> > ());
    }
#line 1649 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 51:
#line 403 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->declare_C_function(yystack_[6].value.as < std::string > (),{},yystack_[1].value.as < std::shared_ptr<ast::NodeBase> > ());
    }
#line 1657 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 52:
#line 408 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ().push_back(std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ()));
    }
#line 1665 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 53:
#line 412 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::NodeBase>> > () = std::move(yystack_[2].value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ());
        yylhs.value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ().push_back(std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ()));
    }
#line 1674 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 54:
#line 418 "./src/compiler/parser/parser.yy"
    {
        driver.ast_generator->into_anonymous_namespace();
    }
#line 1682 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 55:
#line 423 "./src/compiler/parser/parser.yy"
    {
        driver.ast_generator->into_anonymous_namespace();
    }
#line 1690 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 56:
#line 428 "./src/compiler/parser/parser.yy"
    {
        driver.ast_generator->into_anonymous_namespace();
        yylhs.value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ().push_back(yystack_[4].value.as < std::shared_ptr<ast::NodeBase> > ());
        yylhs.value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ().push_back(yystack_[2].value.as < std::shared_ptr<ast::NodeBase> > ());
        yylhs.value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ().push_back(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ());
    }
#line 1701 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 57:
#line 437 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::NodeBase>> > () = std::move(yystack_[1].value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ());
        driver.ast_generator->break_out_of_namespace();
    }
#line 1710 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 58:
#line 443 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_if(yystack_[5].value.as < std::shared_ptr<ast::NodeBase> > (),yystack_[1].value.as < std::vector<std::shared_ptr<ast::NodeBase>> > (),{});
        driver.ast_generator->break_out_of_namespace();
    }
#line 1719 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 59:
#line 448 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_if(yystack_[6].value.as < std::shared_ptr<ast::NodeBase> > (),yystack_[2].value.as < std::vector<std::shared_ptr<ast::NodeBase>> > (),yystack_[0].value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ());
    }
#line 1727 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 60:
#line 452 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_for(yystack_[5].value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ()[0],yystack_[5].value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ()[1],yystack_[5].value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ()[2],yystack_[1].value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ());
        driver.ast_generator->break_out_of_namespace();
    }
#line 1736 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 61:
#line 457 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ();
    }
#line 1744 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 62:
#line 461 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_store(yystack_[2].value.as < std::shared_ptr<ast::NodeBase> > (),yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ());
    }
#line 1752 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 63:
#line 465 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_binary_expression(std::move(yystack_[2].value.as < std::shared_ptr<ast::NodeBase> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ()),"+");
    }
#line 1760 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 64:
#line 469 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_binary_expression(std::move(yystack_[2].value.as < std::shared_ptr<ast::NodeBase> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ()),"-");
    }
#line 1768 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 65:
#line 473 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_binary_expression(std::move(yystack_[2].value.as < std::shared_ptr<ast::NodeBase> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ()),"*");
    }
#line 1776 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 66:
#line 477 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_binary_expression(std::move(yystack_[2].value.as < std::shared_ptr<ast::NodeBase> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ()),"/");
    }
#line 1784 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 67:
#line 481 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_binary_expression(std::move(yystack_[2].value.as < std::shared_ptr<ast::NodeBase> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ()),"and");
    }
#line 1792 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 68:
#line 485 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_binary_expression(std::move(yystack_[2].value.as < std::shared_ptr<ast::NodeBase> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ()),"or");
    }
#line 1800 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 69:
#line 489 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_binary_expression(std::move(yystack_[2].value.as < std::shared_ptr<ast::NodeBase> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ()),">=");
    }
#line 1808 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 70:
#line 493 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_binary_expression(std::move(yystack_[2].value.as < std::shared_ptr<ast::NodeBase> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ()),"<=");
    }
#line 1816 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 71:
#line 497 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_binary_expression(std::move(yystack_[2].value.as < std::shared_ptr<ast::NodeBase> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ()),">");
    }
#line 1824 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 72:
#line 501 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_binary_expression(std::move(yystack_[2].value.as < std::shared_ptr<ast::NodeBase> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ()),"<");
    }
#line 1832 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 73:
#line 505 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_binary_expression(std::move(yystack_[2].value.as < std::shared_ptr<ast::NodeBase> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ()),"!=");
    }
#line 1840 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 74:
#line 509 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_binary_expression(std::move(yystack_[2].value.as < std::shared_ptr<ast::NodeBase> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ()),"==");
    }
#line 1848 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 75:
#line 513 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ());
    }
#line 1856 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 76:
#line 517 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ());
    }
#line 1864 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 77:
#line 521 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = std::move(yystack_[0].value.as < std::shared_ptr<ast::AccessNode> > ());
    }
#line 1872 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 78:
#line 525 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_minus(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ());
    }
#line 1880 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 79:
#line 529 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = std::move(yystack_[1].value.as < std::shared_ptr<ast::NodeBase> > ());
    }
#line 1888 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 80:
#line 534 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_list(std::move(yystack_[1].value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ()));
    }
#line 1896 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 81:
#line 538 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_list();
    }
#line 1904 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 82:
#line 543 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::AccessNode> > () = driver.ast_generator->create_access(yystack_[1].value.as < std::shared_ptr<ast::NodeBase> > (),yystack_[0].value.as < std::string > ());
    }
#line 1912 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 83:
#line 548 "./src/compiler/parser/parser.yy"
    {
        if (is_global == NOT_GLOBAL)
        {yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_assign(yystack_[2].value.as < std::string > (),std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ()),false);}
        if (is_global == GLOBAL)
        {yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_assign(yystack_[2].value.as < std::string > (),std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ()),true);}
    }
#line 1923 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 84:
#line 555 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_assign(yystack_[2].value.as < std::shared_ptr<ast::AccessNode> > (),std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ()));
    }
#line 1931 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 85:
#line 560 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ();
    }
#line 1939 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 86:
#line 564 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_string(yystack_[0].value.as < std::string > ());
    }
#line 1947 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 87:
#line 568 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_float(yystack_[0].value.as < double > ());
    }
#line 1955 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 88:
#line 572 "./src/compiler/parser/parser.yy"
    { 
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_integer(yystack_[0].value.as < long long > ());
    }
#line 1963 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 89:
#line 576 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = std::move(yystack_[0].value.as < std::shared_ptr<ast::NodeBase> > ());
    }
#line 1971 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 90:
#line 581 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_call(yystack_[3].value.as < std::string > (),yystack_[1].value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ());
    }
#line 1979 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 91:
#line 585 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_call(yystack_[2].value.as < std::string > (),{});
    }
#line 1987 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 92:
#line 589 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_call(yystack_[3].value.as < std::shared_ptr<ast::AccessNode> > (),yystack_[1].value.as < std::vector<std::shared_ptr<ast::NodeBase>> > ());
    }
#line 1995 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 93:
#line 593 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->create_call(yystack_[2].value.as < std::shared_ptr<ast::AccessNode> > (),{});
    }
#line 2003 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 94:
#line 598 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::NodeBase> > () = driver.ast_generator->get_named_value(yystack_[0].value.as < std::string > ());
    }
#line 2011 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;


#line 2015 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"

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


  const signed char Parser::yypact_ninf_ = -127;

  const signed char Parser::yytable_ninf_ = -50;

  const short
  Parser::yypact_[] =
  {
     136,  -127,  -127,  -127,   -29,     3,   189,   189,   123,  -127,
     189,  -127,   -24,  -127,  -127,  -127,    27,  -127,   136,  -127,
    -127,     6,  -127,  -127,    -4,  -127,    -4,  -127,   -16,  -127,
     -15,  -127,   189,   -14,   337,  -127,     7,  -127,  -127,  -127,
    -127,    10,   189,   155,    14,   278,  -127,   -10,   337,   299,
      22,  -127,  -127,  -127,  -127,     1,    28,    33,    79,    58,
     227,    60,   189,   189,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,  -127,   189,   158,    -3,   337,
    -127,     9,  -127,   189,  -127,   189,  -127,  -127,  -127,    21,
      80,    12,    81,    84,    53,    70,    57,   337,   349,   349,
      74,    74,    74,    74,    74,    74,    24,    24,    14,    14,
     337,  -127,    45,  -127,    61,    95,   -18,  -127,   337,   318,
      98,  -127,   189,   102,    64,  -127,   101,   111,    -4,    72,
      13,   106,   109,   189,    75,   136,  -127,   106,  -127,   106,
      85,   189,  -127,   337,    78,  -127,   189,    86,    89,  -127,
     114,   111,    -1,   106,    90,   337,    91,   136,    99,    95,
      97,    95,   106,   337,  -127,   242,  -127,    80,   189,  -127,
       0,   186,   112,  -127,  -127,   103,  -127,   102,  -127,   263,
    -127,   104,   105,   110,  -127,  -127,  -127,  -127,  -127,   107,
    -127,   116,   113,   136,   120,  -127
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,    19,    23,    25,     0,    94,     0,     0,     0,    54,
       0,    47,     0,    86,    88,    87,     0,     2,     3,     4,
       9,     0,     8,    12,     0,    13,     0,    14,     0,    15,
       0,    16,     0,     0,    11,    76,    77,    61,    75,    85,
      89,     0,     0,     0,    78,     0,    81,     0,    52,     0,
       0,     1,     5,     7,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,     0,     0,     0,    83,
      91,     0,    79,     0,    80,     0,    10,    44,    43,     0,
       0,     0,     0,    24,     0,     0,     0,    62,    67,    68,
      74,    73,    69,    70,    71,    72,    63,    64,    65,    66,
      84,    93,     0,    35,     0,    37,     0,    90,    53,     0,
       0,    42,    41,     0,     0,    28,     0,    22,     0,     0,
      21,     0,     0,     0,     0,     0,    92,     0,    36,     0,
       0,     0,    45,    40,     0,    18,     0,     0,     0,    26,
       0,    20,     0,     0,     0,     0,    61,     0,     0,    39,
       0,    38,     0,    56,    17,     0,    27,     0,     0,    33,
       0,     0,     0,    60,    51,     0,    31,     0,    30,     0,
      34,     0,    61,    58,    50,    29,    32,    46,    55,     0,
      59,     0,     0,     0,     0,    57
  };

  const short
  Parser::yypgoto_[] =
  {
    -127,  -127,   -85,  -127,   138,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,    34,  -127,  -113,  -127,  -127,   -58,
    -127,     5,   -93,   -23,  -127,  -127,  -127,  -127,  -127,   -34,
    -127,  -127,  -127,  -127,    -6,  -127,  -127,  -126,  -127,  -127,
    -127
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,   127,   128,   129,   130,    93,   159,
     116,   160,   124,    56,    89,    29,    30,   154,    31,    47,
      32,   189,    33,   190,    34,    35,    36,    37,    38,    39,
      40
  };

  const short
  Parser::yytable_[] =
  {
      44,    45,    48,    57,    49,   123,    53,   156,   113,    81,
     138,   138,    87,   139,   147,    42,   125,   125,    41,    76,
     115,    83,   126,   150,    50,    84,    60,    51,    55,   140,
     144,    58,    59,    61,    88,    43,    79,    48,   147,    77,
      83,    75,   117,   112,   114,   182,   169,   180,    73,    74,
     158,    75,   120,    54,   121,    78,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,    86,
     110,    48,   172,   152,   178,    90,    83,   118,   136,   119,
      91,   161,   177,     1,   185,     2,     3,     4,   122,    92,
      94,     5,    96,   131,   132,   170,    71,    72,    73,    74,
     133,    75,   134,     6,   135,   148,   138,   137,   194,   142,
     122,   145,     7,   146,     8,   125,   143,   113,     9,   149,
      10,   153,   157,    11,    12,   164,   168,   155,    13,    14,
      15,   162,   173,   166,     5,   163,   167,   171,   -48,     1,
     165,     2,     3,     4,   174,   183,     6,     5,   192,   188,
     184,   187,   -49,   195,   191,     7,    52,     8,    46,     6,
     193,     9,   179,    10,   151,   155,     5,   175,     7,     5,
       8,    13,    14,    15,     9,     0,    10,     0,     6,    11,
      12,     6,     0,     0,    13,    14,    15,     7,    80,     8,
       7,   111,     8,     9,     0,    10,     9,     5,    10,     0,
       5,     0,     0,    13,    14,    15,    13,    14,    15,     6,
       0,     0,     6,     0,     0,     0,     0,     0,     7,   181,
       8,     7,     0,     8,     9,     0,    10,     9,     0,    10,
       0,     0,     0,     0,    13,    14,    15,    13,    14,    15,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,     0,    75,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,     0,    75,
       0,     0,     0,     0,    95,     0,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,   176,
      75,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,     0,    75,     0,     0,     0,     0,
     186,    82,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,     0,    75,     0,     0,     0,
      85,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,     0,    75,     0,     0,     0,   141,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,     0,    75,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,     0,    75
  };

  const short
  Parser::yycheck_[] =
  {
       6,     7,     8,    26,    10,    90,     0,   133,    11,    43,
      11,    11,    11,    31,   127,    12,     4,     4,    47,    12,
      78,    31,    10,    10,    48,    35,    32,     0,    32,    47,
     123,    47,    47,    47,    33,    32,    42,    43,   151,    32,
      31,    27,    33,    77,    47,   171,    47,    47,    24,    25,
     135,    27,    31,    47,    33,    45,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    47,
      76,    77,   157,   131,   167,    47,    31,    83,    33,    85,
      47,   139,   167,     3,   177,     5,     6,     7,     8,    10,
      32,    11,    32,    12,    10,   153,    22,    23,    24,    25,
      47,    27,    32,    23,    47,   128,    11,    46,   193,    11,
       8,    47,    32,    12,    34,     4,   122,    11,    38,    47,
      40,    12,    47,    43,    44,    47,    12,   133,    48,    49,
      50,    46,    33,    47,    11,   141,    47,    47,    47,     3,
     146,     5,     6,     7,    47,    33,    23,    11,    32,    39,
      47,    47,    47,    33,    47,    32,    18,    34,    35,    23,
      47,    38,   168,    40,   130,   171,    11,   162,    32,    11,
      34,    48,    49,    50,    38,    -1,    40,    -1,    23,    43,
      44,    23,    -1,    -1,    48,    49,    50,    32,    33,    34,
      32,    33,    34,    38,    -1,    40,    38,    11,    40,    -1,
      11,    -1,    -1,    48,    49,    50,    48,    49,    50,    23,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    32,    -1,    34,    38,    -1,    40,    38,    -1,    40,
      -1,    -1,    -1,    -1,    48,    49,    50,    48,    49,    50,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    27,
      -1,    -1,    -1,    -1,    47,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    47,
      27,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,    -1,    -1,    -1,    -1,
      47,    33,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    27,    -1,    -1,    -1,
      31,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,    -1,    -1,    -1,    31,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    27
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     3,     5,     6,     7,    11,    23,    32,    34,    38,
      40,    43,    44,    48,    49,    50,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    76,
      77,    79,    81,    83,    85,    86,    87,    88,    89,    90,
      91,    47,    12,    32,    85,    85,    35,    80,    85,    85,
      48,     0,    55,     0,    47,    32,    74,    74,    47,    47,
      85,    47,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    27,    12,    32,    45,    85,
      33,    80,    33,    31,    35,    31,    47,    11,    33,    75,
      47,    47,    10,    69,    32,    47,    32,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    33,    80,    11,    47,    70,    71,    33,    85,    85,
      31,    33,     8,    53,    73,     4,    10,    65,    66,    67,
      68,    12,    10,    47,    32,    47,    33,    46,    11,    31,
      47,    31,    11,    85,    73,    47,    12,    67,    74,    47,
      10,    65,    70,    12,    78,    85,    88,    47,    53,    70,
      72,    70,    46,    85,    47,    85,    47,    47,    12,    47,
      70,    47,    53,    33,    47,    72,    47,    53,    73,    85,
      47,    33,    88,    33,    47,    73,    47,    47,    39,    82,
      84,    47,    32,    47,    53,    33
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    51,    52,    53,    54,    54,    55,    55,    55,    55,
      56,    57,    58,    58,    58,    58,    58,    59,    59,    60,
      61,    61,    61,    62,    63,    64,    65,    65,    66,    67,
      67,    68,    68,    69,    69,    70,    70,    71,    71,    72,
      73,    73,    74,    74,    75,    75,    76,    77,    78,    78,
      79,    79,    80,    80,    81,    82,    83,    84,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      86,    86,    87,    88,    88,    89,    89,    89,    89,    89,
      90,    90,    90,    90,    91
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     2,     2,     2,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     6,     5,     1,
       5,     4,     4,     1,     3,     1,     2,     3,     1,     5,
       4,     4,     5,     4,     5,     1,     2,     1,     3,     1,
       2,     1,     3,     2,     1,     3,     8,     1,     1,     3,
       8,     7,     1,     3,     1,     1,     6,     6,     7,     8,
       6,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     2,     3,
       3,     2,     2,     3,     3,     1,     1,     1,     1,     1,
       4,     3,     4,     3,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "FUNCTION_DEFINITION",
  "METHOD_DEFINITION", "CLASS_DEFINITION", "C_TYPE_DEFINITION",
  "C_FUNCTION_DECLARATION", "RETURN", "C_FUNCTION", "MEMBER_IDENTIFIER",
  "IDENTIFIER", "EQUAL", "ARROW", "OP_AND", "OP_OR", "OP_EQUAL",
  "OP_NOT_EQUAL", "OP_MORE_EQUAL", "OP_LESS_EQUAL", "OP_MORE", "OP_LESS",
  "PLUS", "MINUS", "ASTERISK", "SLASH", "UMINUS", "DOT_IDENTIFIER", "USE",
  "COLON", "SEMICOLON", "COMMA", "LEFT_PARENTHESIS", "RIGHT_PARENTHESIS",
  "LEFT_CURLY_BRACE", "RIGHT_CURLY_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET",
  "IF", "ELSE", "FOR", "IN", "WHILE", "GLOBAL", "IMPORT",
  "C_FUNCTION_ARGUMENT", "C_FUNCTION_RETURN", "EOL", "STRING_LITERAL",
  "INT_LITERAL", "FLOAT_LITERAL", "$accept", "program", "block", "lines",
  "line", "import", "line_content", "definition", "function_definition",
  "function_start", "class_definition", "class_start", "c_type_definition",
  "c_type_start", "methods", "method_start", "method_definition",
  "members_definition", "C_members_definition", "C_type_identifier",
  "C_arguments", "C_returns", "return_value", "arguments",
  "definition_arguments", "globals_definition", "global_start",
  "globals_variables", "c_function_declaration", "expressions", "if_start",
  "else_start", "for_start", "else_body", "expression", "list", "access",
  "assign_variable", "monomial", "call", "variable", YY_NULLPTR
  };


  const short
  Parser::yyrline_[] =
  {
       0,   144,   144,   150,   156,   160,   166,   170,   174,   178,
     183,   185,   190,   194,   198,   202,   206,   211,   216,   222,
     228,   233,   238,   244,   250,   256,   262,   266,   272,   278,
     285,   293,   297,   303,   309,   317,   321,   327,   333,   341,
     347,   351,   356,   360,   365,   370,   377,   383,   388,   392,
     398,   402,   407,   411,   417,   422,   427,   436,   442,   447,
     451,   456,   460,   464,   468,   472,   476,   480,   484,   488,
     492,   496,   500,   504,   508,   512,   516,   520,   524,   528,
     533,   537,   542,   547,   554,   559,   563,   567,   571,   575,
     580,   584,   588,   592,   597
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
      45,    46,    47,    48,    49,    50
    };
    const int user_token_number_max_ = 305;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 5 "./src/compiler/parser/parser.yy"
} // Blawn
#line 2538 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"

#line 601 "./src/compiler/parser/parser.yy"


void Blawn::Parser::error( const location_type &l, const std::string &err_message )
{
    std::cerr << "Error: " << err_message << " at " << l << "\n";
    exit(1);
} 
