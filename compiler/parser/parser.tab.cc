// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

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


// First part of user declarations.

#line 37 "parser.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.tab.hh"

// User implementation prologue.

#line 51 "parser.tab.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 34 "./parser.yy" // lalr1.cc:413

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

#line 69 "parser.tab.cc" // lalr1.cc:413


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
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

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
      *yycdebug_ << std::endl;                  \
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
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "./parser.yy" // lalr1.cc:479
namespace Blawn {
#line 155 "parser.tab.cc" // lalr1.cc:479

  /// Build a parser object.
  Parser::Parser (Scanner  &scanner_yyarg, Driver  &driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  Parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      case 41: // FLOAT_LITERAL
        value.copy< double > (other.value);
        break;

      case 40: // INT_LITERAL
        value.copy< long long > (other.value);
        break;

      case 65: // access
        value.copy< std::shared_ptr<AccessNode> > (other.value);
        break;

      case 55: // method_definition
        value.copy< std::shared_ptr<FunctionNode> > (other.value);
        break;

      case 47: // line
      case 48: // line_content
      case 49: // definition
      case 50: // function_definition
      case 52: // class_definition
      case 57: // return_value
      case 63: // expression
      case 64: // list
      case 66: // assign_variable
      case 67: // monomial
      case 68: // call
      case 69: // variable
        value.copy< std::shared_ptr<Node> > (other.value);
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 7: // C_FUNCTION
      case 8: // MEMBER_IDENTIFIER
      case 9: // IDENTIFIER
      case 23: // DOT_IDENTIFIER
      case 42: // STRING_LITERAL
      case 51: // function_start
      case 53: // class_start
        value.copy< std::string > (other.value);
        break;

      case 54: // methods
        value.copy< std::vector<std::shared_ptr<FunctionNode>> > (other.value);
        break;

      case 45: // block
      case 46: // lines
      case 56: // members_definition
      case 60: // expressions
        value.copy< std::vector<std::shared_ptr<Node>> > (other.value);
        break;

      case 58: // arguments
      case 59: // definition_arguments
        value.copy< std::vector<std::string> > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 41: // FLOAT_LITERAL
        value.copy< double > (v);
        break;

      case 40: // INT_LITERAL
        value.copy< long long > (v);
        break;

      case 65: // access
        value.copy< std::shared_ptr<AccessNode> > (v);
        break;

      case 55: // method_definition
        value.copy< std::shared_ptr<FunctionNode> > (v);
        break;

      case 47: // line
      case 48: // line_content
      case 49: // definition
      case 50: // function_definition
      case 52: // class_definition
      case 57: // return_value
      case 63: // expression
      case 64: // list
      case 66: // assign_variable
      case 67: // monomial
      case 68: // call
      case 69: // variable
        value.copy< std::shared_ptr<Node> > (v);
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 7: // C_FUNCTION
      case 8: // MEMBER_IDENTIFIER
      case 9: // IDENTIFIER
      case 23: // DOT_IDENTIFIER
      case 42: // STRING_LITERAL
      case 51: // function_start
      case 53: // class_start
        value.copy< std::string > (v);
        break;

      case 54: // methods
        value.copy< std::vector<std::shared_ptr<FunctionNode>> > (v);
        break;

      case 45: // block
      case 46: // lines
      case 56: // members_definition
      case 60: // expressions
        value.copy< std::vector<std::shared_ptr<Node>> > (v);
        break;

      case 58: // arguments
      case 59: // definition_arguments
        value.copy< std::vector<std::string> > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const double v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const long long v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<AccessNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<FunctionNode> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::shared_ptr<Node> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::vector<std::shared_ptr<FunctionNode>> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::vector<std::shared_ptr<Node>> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::vector<std::string> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 41: // FLOAT_LITERAL
        value.template destroy< double > ();
        break;

      case 40: // INT_LITERAL
        value.template destroy< long long > ();
        break;

      case 65: // access
        value.template destroy< std::shared_ptr<AccessNode> > ();
        break;

      case 55: // method_definition
        value.template destroy< std::shared_ptr<FunctionNode> > ();
        break;

      case 47: // line
      case 48: // line_content
      case 49: // definition
      case 50: // function_definition
      case 52: // class_definition
      case 57: // return_value
      case 63: // expression
      case 64: // list
      case 66: // assign_variable
      case 67: // monomial
      case 68: // call
      case 69: // variable
        value.template destroy< std::shared_ptr<Node> > ();
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 7: // C_FUNCTION
      case 8: // MEMBER_IDENTIFIER
      case 9: // IDENTIFIER
      case 23: // DOT_IDENTIFIER
      case 42: // STRING_LITERAL
      case 51: // function_start
      case 53: // class_start
        value.template destroy< std::string > ();
        break;

      case 54: // methods
        value.template destroy< std::vector<std::shared_ptr<FunctionNode>> > ();
        break;

      case 45: // block
      case 46: // lines
      case 56: // members_definition
      case 60: // expressions
        value.template destroy< std::vector<std::shared_ptr<Node>> > ();
        break;

      case 58: // arguments
      case 59: // definition_arguments
        value.template destroy< std::vector<std::string> > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  Parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 41: // FLOAT_LITERAL
        value.move< double > (s.value);
        break;

      case 40: // INT_LITERAL
        value.move< long long > (s.value);
        break;

      case 65: // access
        value.move< std::shared_ptr<AccessNode> > (s.value);
        break;

      case 55: // method_definition
        value.move< std::shared_ptr<FunctionNode> > (s.value);
        break;

      case 47: // line
      case 48: // line_content
      case 49: // definition
      case 50: // function_definition
      case 52: // class_definition
      case 57: // return_value
      case 63: // expression
      case 64: // list
      case 66: // assign_variable
      case 67: // monomial
      case 68: // call
      case 69: // variable
        value.move< std::shared_ptr<Node> > (s.value);
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 7: // C_FUNCTION
      case 8: // MEMBER_IDENTIFIER
      case 9: // IDENTIFIER
      case 23: // DOT_IDENTIFIER
      case 42: // STRING_LITERAL
      case 51: // function_start
      case 53: // class_start
        value.move< std::string > (s.value);
        break;

      case 54: // methods
        value.move< std::vector<std::shared_ptr<FunctionNode>> > (s.value);
        break;

      case 45: // block
      case 46: // lines
      case 56: // members_definition
      case 60: // expressions
        value.move< std::vector<std::shared_ptr<Node>> > (s.value);
        break;

      case 58: // arguments
      case 59: // definition_arguments
        value.move< std::vector<std::string> > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  Parser::by_type::type_get () const
  {
    return type;
  }
  // Implementation of make_symbol for each symbol type.
  Parser::symbol_type
  Parser::make_END (const location_type& l)
  {
    return symbol_type (token::END, l);
  }

  Parser::symbol_type
  Parser::make_FUNCTION_DEFINITION (const std::string& v, const location_type& l)
  {
    return symbol_type (token::FUNCTION_DEFINITION, v, l);
  }

  Parser::symbol_type
  Parser::make_METHOD_DEFINITION (const std::string& v, const location_type& l)
  {
    return symbol_type (token::METHOD_DEFINITION, v, l);
  }

  Parser::symbol_type
  Parser::make_CLASS_DEFINITION (const std::string& v, const location_type& l)
  {
    return symbol_type (token::CLASS_DEFINITION, v, l);
  }

  Parser::symbol_type
  Parser::make_RETURN (const location_type& l)
  {
    return symbol_type (token::RETURN, l);
  }

  Parser::symbol_type
  Parser::make_C_FUNCTION (const std::string& v, const location_type& l)
  {
    return symbol_type (token::C_FUNCTION, v, l);
  }

  Parser::symbol_type
  Parser::make_MEMBER_IDENTIFIER (const std::string& v, const location_type& l)
  {
    return symbol_type (token::MEMBER_IDENTIFIER, v, l);
  }

  Parser::symbol_type
  Parser::make_IDENTIFIER (const std::string& v, const location_type& l)
  {
    return symbol_type (token::IDENTIFIER, v, l);
  }

  Parser::symbol_type
  Parser::make_OP_EQUAL (const location_type& l)
  {
    return symbol_type (token::OP_EQUAL, l);
  }

  Parser::symbol_type
  Parser::make_OP_NOT_EQUAL (const location_type& l)
  {
    return symbol_type (token::OP_NOT_EQUAL, l);
  }

  Parser::symbol_type
  Parser::make_OP_MORE_EQUAL (const location_type& l)
  {
    return symbol_type (token::OP_MORE_EQUAL, l);
  }

  Parser::symbol_type
  Parser::make_OP_LESS_EQUAL (const location_type& l)
  {
    return symbol_type (token::OP_LESS_EQUAL, l);
  }

  Parser::symbol_type
  Parser::make_OP_MORE (const location_type& l)
  {
    return symbol_type (token::OP_MORE, l);
  }

  Parser::symbol_type
  Parser::make_OP_LESS (const location_type& l)
  {
    return symbol_type (token::OP_LESS, l);
  }

  Parser::symbol_type
  Parser::make_OP_AND (const location_type& l)
  {
    return symbol_type (token::OP_AND, l);
  }

  Parser::symbol_type
  Parser::make_OP_OR (const location_type& l)
  {
    return symbol_type (token::OP_OR, l);
  }

  Parser::symbol_type
  Parser::make_EQUAL (const location_type& l)
  {
    return symbol_type (token::EQUAL, l);
  }

  Parser::symbol_type
  Parser::make_PLUS (const location_type& l)
  {
    return symbol_type (token::PLUS, l);
  }

  Parser::symbol_type
  Parser::make_MINUS (const location_type& l)
  {
    return symbol_type (token::MINUS, l);
  }

  Parser::symbol_type
  Parser::make_ASTERISK (const location_type& l)
  {
    return symbol_type (token::ASTERISK, l);
  }

  Parser::symbol_type
  Parser::make_SLASH (const location_type& l)
  {
    return symbol_type (token::SLASH, l);
  }

  Parser::symbol_type
  Parser::make_DOT_IDENTIFIER (const std::string& v, const location_type& l)
  {
    return symbol_type (token::DOT_IDENTIFIER, v, l);
  }

  Parser::symbol_type
  Parser::make_USE (const location_type& l)
  {
    return symbol_type (token::USE, l);
  }

  Parser::symbol_type
  Parser::make_COLON (const location_type& l)
  {
    return symbol_type (token::COLON, l);
  }

  Parser::symbol_type
  Parser::make_SEMICOLON (const location_type& l)
  {
    return symbol_type (token::SEMICOLON, l);
  }

  Parser::symbol_type
  Parser::make_COMMA (const location_type& l)
  {
    return symbol_type (token::COMMA, l);
  }

  Parser::symbol_type
  Parser::make_LEFT_PARENTHESIS (const location_type& l)
  {
    return symbol_type (token::LEFT_PARENTHESIS, l);
  }

  Parser::symbol_type
  Parser::make_RIGHT_PARENTHESIS (const location_type& l)
  {
    return symbol_type (token::RIGHT_PARENTHESIS, l);
  }

  Parser::symbol_type
  Parser::make_LEFT_CURLY_BRACE (const location_type& l)
  {
    return symbol_type (token::LEFT_CURLY_BRACE, l);
  }

  Parser::symbol_type
  Parser::make_RIGHT_CURLY_BRACE (const location_type& l)
  {
    return symbol_type (token::RIGHT_CURLY_BRACE, l);
  }

  Parser::symbol_type
  Parser::make_LEFT_BRACKET (const location_type& l)
  {
    return symbol_type (token::LEFT_BRACKET, l);
  }

  Parser::symbol_type
  Parser::make_RIGHT_BRACKET (const location_type& l)
  {
    return symbol_type (token::RIGHT_BRACKET, l);
  }

  Parser::symbol_type
  Parser::make_IF (const location_type& l)
  {
    return symbol_type (token::IF, l);
  }

  Parser::symbol_type
  Parser::make_ELSE (const location_type& l)
  {
    return symbol_type (token::ELSE, l);
  }

  Parser::symbol_type
  Parser::make_FOR (const location_type& l)
  {
    return symbol_type (token::FOR, l);
  }

  Parser::symbol_type
  Parser::make_IN (const location_type& l)
  {
    return symbol_type (token::IN, l);
  }

  Parser::symbol_type
  Parser::make_WHILE (const location_type& l)
  {
    return symbol_type (token::WHILE, l);
  }

  Parser::symbol_type
  Parser::make_EOL (const location_type& l)
  {
    return symbol_type (token::EOL, l);
  }

  Parser::symbol_type
  Parser::make_INT_LITERAL (const long long& v, const location_type& l)
  {
    return symbol_type (token::INT_LITERAL, v, l);
  }

  Parser::symbol_type
  Parser::make_FLOAT_LITERAL (const double& v, const location_type& l)
  {
    return symbol_type (token::FLOAT_LITERAL, v, l);
  }

  Parser::symbol_type
  Parser::make_STRING_LITERAL (const std::string& v, const location_type& l)
  {
    return symbol_type (token::STRING_LITERAL, v, l);
  }



  // by_state.
  inline
  Parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 41: // FLOAT_LITERAL
        value.move< double > (that.value);
        break;

      case 40: // INT_LITERAL
        value.move< long long > (that.value);
        break;

      case 65: // access
        value.move< std::shared_ptr<AccessNode> > (that.value);
        break;

      case 55: // method_definition
        value.move< std::shared_ptr<FunctionNode> > (that.value);
        break;

      case 47: // line
      case 48: // line_content
      case 49: // definition
      case 50: // function_definition
      case 52: // class_definition
      case 57: // return_value
      case 63: // expression
      case 64: // list
      case 66: // assign_variable
      case 67: // monomial
      case 68: // call
      case 69: // variable
        value.move< std::shared_ptr<Node> > (that.value);
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 7: // C_FUNCTION
      case 8: // MEMBER_IDENTIFIER
      case 9: // IDENTIFIER
      case 23: // DOT_IDENTIFIER
      case 42: // STRING_LITERAL
      case 51: // function_start
      case 53: // class_start
        value.move< std::string > (that.value);
        break;

      case 54: // methods
        value.move< std::vector<std::shared_ptr<FunctionNode>> > (that.value);
        break;

      case 45: // block
      case 46: // lines
      case 56: // members_definition
      case 60: // expressions
        value.move< std::vector<std::shared_ptr<Node>> > (that.value);
        break;

      case 58: // arguments
      case 59: // definition_arguments
        value.move< std::vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 41: // FLOAT_LITERAL
        value.copy< double > (that.value);
        break;

      case 40: // INT_LITERAL
        value.copy< long long > (that.value);
        break;

      case 65: // access
        value.copy< std::shared_ptr<AccessNode> > (that.value);
        break;

      case 55: // method_definition
        value.copy< std::shared_ptr<FunctionNode> > (that.value);
        break;

      case 47: // line
      case 48: // line_content
      case 49: // definition
      case 50: // function_definition
      case 52: // class_definition
      case 57: // return_value
      case 63: // expression
      case 64: // list
      case 66: // assign_variable
      case 67: // monomial
      case 68: // call
      case 69: // variable
        value.copy< std::shared_ptr<Node> > (that.value);
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 7: // C_FUNCTION
      case 8: // MEMBER_IDENTIFIER
      case 9: // IDENTIFIER
      case 23: // DOT_IDENTIFIER
      case 42: // STRING_LITERAL
      case 51: // function_start
      case 53: // class_start
        value.copy< std::string > (that.value);
        break;

      case 54: // methods
        value.copy< std::vector<std::shared_ptr<FunctionNode>> > (that.value);
        break;

      case 45: // block
      case 46: // lines
      case 56: // members_definition
      case 60: // expressions
        value.copy< std::vector<std::shared_ptr<Node>> > (that.value);
        break;

      case 58: // arguments
      case 59: // definition_arguments
        value.copy< std::vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
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
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Parser::yypop_ (unsigned int n)
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

  inline Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    // State.
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

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

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
    yypush_ ("Shifting", yyn, yyla);
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
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 41: // FLOAT_LITERAL
        yylhs.value.build< double > ();
        break;

      case 40: // INT_LITERAL
        yylhs.value.build< long long > ();
        break;

      case 65: // access
        yylhs.value.build< std::shared_ptr<AccessNode> > ();
        break;

      case 55: // method_definition
        yylhs.value.build< std::shared_ptr<FunctionNode> > ();
        break;

      case 47: // line
      case 48: // line_content
      case 49: // definition
      case 50: // function_definition
      case 52: // class_definition
      case 57: // return_value
      case 63: // expression
      case 64: // list
      case 66: // assign_variable
      case 67: // monomial
      case 68: // call
      case 69: // variable
        yylhs.value.build< std::shared_ptr<Node> > ();
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 7: // C_FUNCTION
      case 8: // MEMBER_IDENTIFIER
      case 9: // IDENTIFIER
      case 23: // DOT_IDENTIFIER
      case 42: // STRING_LITERAL
      case 51: // function_start
      case 53: // class_start
        yylhs.value.build< std::string > ();
        break;

      case 54: // methods
        yylhs.value.build< std::vector<std::shared_ptr<FunctionNode>> > ();
        break;

      case 45: // block
      case 46: // lines
      case 56: // members_definition
      case 60: // expressions
        yylhs.value.build< std::vector<std::shared_ptr<Node>> > ();
        break;

      case 58: // arguments
      case 59: // definition_arguments
        yylhs.value.build< std::vector<std::string> > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 119 "./parser.yy" // lalr1.cc:859
    {
        driver.ast_generator->break_out_of_namespace();
        driver.ast_generator->generate(std::move(yystack_[0].value.as< std::vector<std::shared_ptr<Node>> > ()));
    }
#line 1372 "parser.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 125 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[0].value.as< std::vector<std::shared_ptr<Node>> > ());
    }
#line 1380 "parser.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 130 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1388 "parser.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 134 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1397 "parser.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 140 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[1].value.as< std::shared_ptr<Node> > ());
    }
#line 1405 "parser.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 144 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[1].value.as< std::shared_ptr<Node> > ());
    }
#line 1413 "parser.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 148 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = yystack_[0].value.as< std::shared_ptr<Node> > ();
    }
#line 1421 "parser.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 153 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1429 "parser.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 158 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1437 "parser.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 162 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1445 "parser.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 167 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->add_function(yystack_[5].value.as< std::string > (),std::move(yystack_[4].value.as< std::vector<std::string> > ()),std::move(yystack_[2].value.as< std::vector<std::shared_ptr<Node>> > ()),std::move(yystack_[1].value.as< std::shared_ptr<Node> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1454 "parser.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 173 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
        driver.ast_generator->into_namespace(yystack_[0].value.as< std::string > ());
    }
#line 1463 "parser.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 179 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(driver.ast_generator->add_class(yystack_[4].value.as< std::string > (),yystack_[3].value.as< std::vector<std::string> > (),yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > (),yystack_[0].value.as< std::vector<std::shared_ptr<FunctionNode>> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1472 "parser.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 184 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(driver.ast_generator->add_class(yystack_[3].value.as< std::string > (),yystack_[2].value.as< std::vector<std::string> > (),yystack_[0].value.as< std::vector<std::shared_ptr<Node>> > (),{}));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1481 "parser.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 189 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(driver.ast_generator->add_class(yystack_[3].value.as< std::string > (),yystack_[2].value.as< std::vector<std::string> > (),{},yystack_[0].value.as< std::vector<std::shared_ptr<FunctionNode>> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1490 "parser.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 195 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
        driver.ast_generator->into_namespace(yystack_[0].value.as< std::string > ());
    }
#line 1499 "parser.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 201 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<FunctionNode>> > ().push_back(yystack_[1].value.as< std::shared_ptr<FunctionNode> > ());
    }
#line 1507 "parser.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 205 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<FunctionNode>> > () = std::move(yystack_[2].value.as< std::vector<std::shared_ptr<FunctionNode>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<FunctionNode>> > ().push_back(yystack_[1].value.as< std::shared_ptr<FunctionNode> > ());
    }
#line 1516 "parser.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 211 "./parser.yy" // lalr1.cc:859
    {
        auto args = std::move(yystack_[3].value.as< std::vector<std::string> > ());
        args.insert(args.begin(),"self");
        yylhs.value.as< std::shared_ptr<FunctionNode> > () = driver.ast_generator->add_function(yystack_[4].value.as< std::string > (),std::move(args),std::move(yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1527 "parser.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 219 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(driver.ast_generator->assign(yystack_[3].value.as< std::string > (),std::move(yystack_[1].value.as< std::shared_ptr<Node> > ())));
    }
#line 1535 "parser.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 223 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[4].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(driver.ast_generator->assign(yystack_[3].value.as< std::string > (),std::move(yystack_[1].value.as< std::shared_ptr<Node> > ())));
    }
#line 1544 "parser.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 229 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = yystack_[0].value.as< std::shared_ptr<Node> > ();
    }
#line 1552 "parser.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 233 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = nullptr;
    }
#line 1560 "parser.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 238 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > () = std::move(yystack_[1].value.as< std::vector<std::string> > ());
    }
#line 1568 "parser.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 242 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > () = {};
    }
#line 1576 "parser.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 247 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > ().push_back(yystack_[0].value.as< std::string > ());
        driver.ast_generator->add_argument(yystack_[0].value.as< std::string > ());
    }
#line 1585 "parser.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 252 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > () = std::move(yystack_[2].value.as< std::vector<std::string> > ());
        yylhs.value.as< std::vector<std::string> > ().push_back(yystack_[0].value.as< std::string > ());
        driver.ast_generator->add_argument(yystack_[0].value.as< std::string > ());
    }
#line 1595 "parser.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 259 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1603 "parser.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 263 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[2].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1612 "parser.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 269 "./parser.yy" // lalr1.cc:859
    {
        driver.ast_generator->into_namespace();
    }
#line 1620 "parser.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 274 "./parser.yy" // lalr1.cc:859
    {
        driver.ast_generator->into_namespace();
    }
#line 1628 "parser.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 279 "./parser.yy" // lalr1.cc:859
    {
        blawn_state = EXIST_IF;
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_if(yystack_[5].value.as< std::shared_ptr<Node> > (),yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
        driver.ast_generator->break_out_of_namespace();
    }
#line 1638 "parser.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 285 "./parser.yy" // lalr1.cc:859
    {
        if (blawn_state != EXIST_IF)
        {
            std::cerr << "Error: If expression is not exist." << std::endl;
            exit(1);
        }
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->add_else(yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
        blawn_state = NO_IF;
        driver.ast_generator->break_out_of_namespace();
    }
#line 1653 "parser.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 296 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_for(yystack_[9].value.as< std::shared_ptr<Node> > (),yystack_[7].value.as< std::shared_ptr<Node> > (),yystack_[5].value.as< std::shared_ptr<Node> > (),yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
        driver.ast_generator->break_out_of_namespace();
    }
#line 1662 "parser.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 301 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1670 "parser.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 305 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = yystack_[0].value.as< std::shared_ptr<Node> > ();
    }
#line 1678 "parser.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 309 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"+");
    }
#line 1686 "parser.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 313 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"-");
    }
#line 1694 "parser.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 317 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"*");
    }
#line 1702 "parser.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 321 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"/");
    }
#line 1710 "parser.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 325 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"and");
    }
#line 1718 "parser.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 329 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"or");
    }
#line 1726 "parser.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 333 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),">=");
    }
#line 1734 "parser.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 337 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"<=");
    }
#line 1742 "parser.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 341 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),">");
    }
#line 1750 "parser.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 345 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"<");
    }
#line 1758 "parser.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 349 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"==");
    }
#line 1766 "parser.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 353 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"!=");
    }
#line 1774 "parser.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 357 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1782 "parser.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 361 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<AccessNode> > ());
    }
#line 1790 "parser.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 366 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_list(std::move(yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ()));
    }
#line 1798 "parser.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 370 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_list();
    }
#line 1806 "parser.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 376 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<AccessNode> > () = driver.ast_generator->create_access(yystack_[1].value.as< std::shared_ptr<Node> > (),yystack_[0].value.as< std::string > ());
    }
#line 1814 "parser.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 381 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->assign(yystack_[2].value.as< std::string > (),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1822 "parser.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 385 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->assign(yystack_[2].value.as< std::shared_ptr<AccessNode> > (),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1830 "parser.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 390 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = yystack_[0].value.as< std::shared_ptr<Node> > ();
    }
#line 1838 "parser.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 394 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_string(yystack_[0].value.as< std::string > ());
    }
#line 1846 "parser.tab.cc" // lalr1.cc:859
    break;

  case 59:
#line 398 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_float(yystack_[0].value.as< double > ());
    }
#line 1854 "parser.tab.cc" // lalr1.cc:859
    break;

  case 60:
#line 402 "./parser.yy" // lalr1.cc:859
    { 
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_integer(yystack_[0].value.as< long long > ());
    }
#line 1862 "parser.tab.cc" // lalr1.cc:859
    break;

  case 61:
#line 406 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1870 "parser.tab.cc" // lalr1.cc:859
    break;

  case 62:
#line 411 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_call(yystack_[3].value.as< std::string > (),std::move(yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ()));
    }
#line 1878 "parser.tab.cc" // lalr1.cc:859
    break;

  case 63:
#line 415 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_call(yystack_[2].value.as< std::string > (),{});
    }
#line 1886 "parser.tab.cc" // lalr1.cc:859
    break;

  case 64:
#line 419 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_call(yystack_[3].value.as< std::shared_ptr<AccessNode> > (),yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
    }
#line 1894 "parser.tab.cc" // lalr1.cc:859
    break;

  case 65:
#line 423 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_call(yystack_[2].value.as< std::shared_ptr<AccessNode> > (),{});
    }
#line 1902 "parser.tab.cc" // lalr1.cc:859
    break;

  case 66:
#line 428 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->get_named_value(yystack_[0].value.as< std::string > ());
    }
#line 1910 "parser.tab.cc" // lalr1.cc:859
    break;


#line 1914 "parser.tab.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
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

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
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
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
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
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

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
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char Parser::yypact_ninf_ = -97;

  const signed char Parser::yytable_ninf_ = -1;

  const short int
  Parser::yypact_[] =
  {
      79,   -97,   -97,    -8,    92,   -97,   -97,   131,   -97,   -97,
     -97,    13,   -97,    79,   -97,    18,   -97,   -97,   -14,   -97,
     -14,   131,   -16,   270,   -97,    -6,   -97,   -97,   -97,   -97,
     131,    95,   -97,   -20,   270,   234,   -97,   -97,   -97,   -97,
       0,    21,    27,   164,    -3,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   -97,   131,   109,
      52,   -97,     3,   131,   -97,   131,   -97,   -97,    38,    79,
      11,    55,    39,    70,    70,    70,    70,    70,    70,    52,
      52,    17,    17,    33,    33,    52,   -97,    50,   -97,   270,
     252,    71,   -97,    28,   -14,    67,    90,    56,    20,    57,
      79,   -97,   131,   -97,   131,    58,    60,   131,    63,   -97,
      87,    90,    79,    77,   178,   270,   -97,    79,   199,   -97,
     131,    78,   -97,    80,    28,   -97,   213,   -97,    72,   -97,
     -97,    79,    81,   -97
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,    13,    17,    66,     0,    31,    32,     0,    60,    59,
      58,     0,     2,     3,     4,     0,     8,    10,     0,    11,
       0,     0,     0,     9,    50,    51,    37,    36,    57,    61,
       0,     0,    53,     0,    29,     0,     1,     5,     7,     6,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,     0,     0,
      55,    63,     0,     0,    52,     0,    27,    26,     0,     0,
       0,     0,     0,    48,    49,    44,    45,    46,    47,    42,
      43,    38,    39,    40,    41,    56,    65,     0,    62,    30,
       0,     0,    25,     0,     0,     0,    16,     0,    15,     0,
       0,    64,     0,    28,    24,     0,     0,     0,     0,    18,
       0,    14,     0,     0,     0,    23,    12,     0,     0,    19,
       0,     0,    34,     0,     0,    21,     0,    33,     0,    20,
      22,     0,     0,    35
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -97,   -97,   -96,   -64,   -12,   -97,   -97,   -97,   -97,   -97,
     -97,    19,   -90,   -97,    22,   -18,   -97,   -23,   -97,   -97,
      -4,   -97,   -97,   -97,   -97,   -97,   -97
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    96,    97,    98,   105,    41,    68,    33,    21,    22,
      23,    24,    25,    26,    27,    28,    29
  };

  const unsigned char
  Parser::yytable_[] =
  {
      34,    37,    42,    35,   113,    93,   108,    63,    62,    66,
      30,    64,    58,    36,    40,    94,   121,    43,    38,    95,
      31,   108,    59,    44,    94,    72,    60,    34,   110,    67,
      63,     1,    88,     2,   104,   132,    87,     3,    55,    56,
      57,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,   124,    85,    34,    57,    39,     4,    89,
      69,    90,     5,     6,     7,    91,    70,    92,     8,     9,
      10,    53,    54,    55,    56,    57,   106,    63,   100,   101,
     103,    37,     1,    99,     2,   107,    51,    52,     3,    53,
      54,    55,    56,    57,    94,   109,   112,   116,   114,   117,
     115,     3,   119,   118,     3,   120,   122,   127,   128,     4,
     133,   131,    37,     5,     6,     7,   126,   111,     3,     8,
       9,    10,     4,    32,    61,     4,     5,     6,     7,     5,
       6,     7,     8,     9,    10,     8,     9,    10,    86,     4,
       3,     0,     0,     5,     6,     7,   129,     0,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     0,     0,     0,     5,     6,     7,     0,     0,
       0,     8,     9,    10,    45,    46,    47,    48,    49,    50,
      51,    52,     0,    53,    54,    55,    56,    57,    45,    46,
      47,    48,    49,    50,    51,    52,     0,    53,    54,    55,
      56,    57,     0,    71,     0,     0,     0,     0,     0,    45,
      46,    47,    48,    49,    50,    51,    52,   123,    53,    54,
      55,    56,    57,    45,    46,    47,    48,    49,    50,    51,
      52,     0,    53,    54,    55,    56,    57,     0,   125,     0,
       0,     0,     0,     0,    45,    46,    47,    48,    49,    50,
      51,    52,   130,    53,    54,    55,    56,    57,     0,     0,
       0,    65,    45,    46,    47,    48,    49,    50,    51,    52,
       0,    53,    54,    55,    56,    57,     0,     0,     0,   102,
      45,    46,    47,    48,    49,    50,    51,    52,     0,    53,
      54,    55,    56,    57
  };

  const short int
  Parser::yycheck_[] =
  {
       4,    13,    20,     7,   100,    69,    96,    27,    31,     9,
      18,    31,    18,     0,    28,     4,   112,    21,     0,     8,
      28,   111,    28,    39,     4,    28,    30,    31,     8,    29,
      27,     3,    29,     5,     6,   131,    59,     9,    21,    22,
      23,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,   117,    58,    59,    23,    39,    30,    63,
      39,    65,    34,    35,    36,    27,    39,    29,    40,    41,
      42,    19,    20,    21,    22,    23,    94,    27,    39,    29,
       9,    93,     3,    28,     5,    18,    16,    17,     9,    19,
      20,    21,    22,    23,     4,    39,    39,    39,   102,    39,
     104,     9,    39,   107,     9,    18,    29,    29,    28,    30,
      29,    39,   124,    34,    35,    36,   120,    98,     9,    40,
      41,    42,    30,    31,    29,    30,    34,    35,    36,    34,
      35,    36,    40,    41,    42,    40,    41,    42,    29,    30,
       9,    -1,    -1,    34,    35,    36,   124,    -1,    -1,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    34,    35,    36,    -1,    -1,
      -1,    40,    41,    42,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    19,    20,    21,    22,    23,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    19,    20,    21,
      22,    23,    -1,    39,    -1,    -1,    -1,    -1,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    39,    19,    20,
      21,    22,    23,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    19,    20,    21,    22,    23,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    39,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    27,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    19,    20,    21,    22,    23,    -1,    -1,    -1,    27,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    19,
      20,    21,    22,    23
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     3,     5,     9,    30,    34,    35,    36,    40,    41,
      42,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      18,    28,    31,    60,    63,    63,     0,    47,     0,    39,
      28,    58,    58,    63,    39,    10,    11,    12,    13,    14,
      15,    16,    17,    19,    20,    21,    22,    23,    18,    28,
      63,    29,    60,    27,    31,    27,     9,    29,    59,    39,
      39,    39,    28,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    29,    60,    29,    63,
      63,    27,    29,    46,     4,     8,    54,    55,    56,    28,
      39,    29,    27,     9,     6,    57,    58,    18,    55,    39,
       8,    54,    39,    45,    63,    63,    39,    39,    63,    39,
      18,    45,    29,    39,    46,    39,    63,    29,    28,    57,
      39,    39,    45,    29
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    43,    44,    45,    46,    46,    47,    47,    47,    48,
      49,    49,    50,    51,    52,    52,    52,    53,    54,    54,
      55,    56,    56,    57,    57,    58,    58,    59,    59,    60,
      60,    61,    62,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    64,    64,    65,    66,    66,    67,    67,    67,
      67,    67,    68,    68,    68,    68,    69
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     2,     2,     2,     1,     1,
       1,     1,     6,     1,     5,     4,     4,     1,     2,     3,
       5,     4,     5,     2,     1,     3,     2,     1,     3,     1,
       3,     1,     1,     7,     6,    11,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     3,     2,     2,     3,     3,     1,     1,     1,
       1,     1,     4,     3,     4,     3,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "FUNCTION_DEFINITION",
  "METHOD_DEFINITION", "CLASS_DEFINITION", "RETURN", "C_FUNCTION",
  "MEMBER_IDENTIFIER", "IDENTIFIER", "OP_EQUAL", "OP_NOT_EQUAL",
  "OP_MORE_EQUAL", "OP_LESS_EQUAL", "OP_MORE", "OP_LESS", "OP_AND",
  "OP_OR", "EQUAL", "PLUS", "MINUS", "ASTERISK", "SLASH", "DOT_IDENTIFIER",
  "USE", "COLON", "SEMICOLON", "COMMA", "LEFT_PARENTHESIS",
  "RIGHT_PARENTHESIS", "LEFT_CURLY_BRACE", "RIGHT_CURLY_BRACE",
  "LEFT_BRACKET", "RIGHT_BRACKET", "IF", "ELSE", "FOR", "IN", "WHILE",
  "EOL", "INT_LITERAL", "FLOAT_LITERAL", "STRING_LITERAL", "$accept",
  "program", "block", "lines", "line", "line_content", "definition",
  "function_definition", "function_start", "class_definition",
  "class_start", "methods", "method_definition", "members_definition",
  "return_value", "arguments", "definition_arguments", "expressions",
  "if_start", "else_start", "expression", "list", "access",
  "assign_variable", "monomial", "call", "variable", YY_NULLPTR
  };


  const unsigned short int
  Parser::yyrline_[] =
  {
       0,   118,   118,   124,   129,   133,   139,   143,   147,   152,
     157,   161,   166,   172,   178,   183,   188,   194,   200,   204,
     210,   218,   222,   228,   232,   237,   241,   246,   251,   258,
     262,   268,   273,   278,   284,   295,   300,   304,   308,   312,
     316,   320,   324,   328,   332,   336,   340,   344,   348,   352,
     356,   360,   365,   369,   375,   380,   384,   389,   393,   397,
     401,   405,   410,   414,   418,   422,   427
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
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
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
      35,    36,    37,    38,    39,    40,    41,    42
    };
    const unsigned int user_token_number_max_ = 297;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 5 "./parser.yy" // lalr1.cc:1167
} // Blawn
#line 2370 "parser.tab.cc" // lalr1.cc:1167
#line 431 "./parser.yy" // lalr1.cc:1168


void Blawn::Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
} 
