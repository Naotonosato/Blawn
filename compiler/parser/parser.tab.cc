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
#line 34 "parser.yy" // lalr1.cc:413

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

#line 72 "parser.tab.cc" // lalr1.cc:413


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

#line 5 "parser.yy" // lalr1.cc:479
namespace Blawn {
#line 158 "parser.tab.cc" // lalr1.cc:479

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
      case 46: // FLOAT_LITERAL
        value.copy< double > (other.value);
        break;

      case 45: // INT_LITERAL
        value.copy< long long > (other.value);
        break;

      case 76: // access
        value.copy< std::shared_ptr<AccessNode> > (other.value);
        break;

      case 62: // method_definition
        value.copy< std::shared_ptr<FunctionNode> > (other.value);
        break;

      case 52: // line
      case 53: // line_content
      case 54: // definition
      case 55: // function_definition
      case 57: // class_definition
      case 59: // c_type_definition
      case 64: // return_value
      case 67: // globals_definition
      case 70: // c_function_declaration
      case 74: // expression
      case 75: // list
      case 77: // assign_variable
      case 78: // monomial
      case 79: // call
      case 80: // variable
        value.copy< std::shared_ptr<Node> > (other.value);
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 6: // C_TYPE_DEFINITION
      case 7: // C_FUNCTION_DECLARATION
      case 9: // C_FUNCTION
      case 10: // MEMBER_IDENTIFIER
      case 11: // IDENTIFIER
      case 25: // DOT_IDENTIFIER
      case 47: // STRING_LITERAL
      case 56: // function_start
      case 58: // class_start
      case 60: // c_type_start
        value.copy< std::string > (other.value);
        break;

      case 61: // methods
        value.copy< std::vector<std::shared_ptr<FunctionNode>> > (other.value);
        break;

      case 50: // block
      case 51: // lines
      case 63: // members_definition
      case 69: // globals_variables
      case 71: // expressions
        value.copy< std::vector<std::shared_ptr<Node>> > (other.value);
        break;

      case 65: // arguments
      case 66: // definition_arguments
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
      case 46: // FLOAT_LITERAL
        value.copy< double > (v);
        break;

      case 45: // INT_LITERAL
        value.copy< long long > (v);
        break;

      case 76: // access
        value.copy< std::shared_ptr<AccessNode> > (v);
        break;

      case 62: // method_definition
        value.copy< std::shared_ptr<FunctionNode> > (v);
        break;

      case 52: // line
      case 53: // line_content
      case 54: // definition
      case 55: // function_definition
      case 57: // class_definition
      case 59: // c_type_definition
      case 64: // return_value
      case 67: // globals_definition
      case 70: // c_function_declaration
      case 74: // expression
      case 75: // list
      case 77: // assign_variable
      case 78: // monomial
      case 79: // call
      case 80: // variable
        value.copy< std::shared_ptr<Node> > (v);
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 6: // C_TYPE_DEFINITION
      case 7: // C_FUNCTION_DECLARATION
      case 9: // C_FUNCTION
      case 10: // MEMBER_IDENTIFIER
      case 11: // IDENTIFIER
      case 25: // DOT_IDENTIFIER
      case 47: // STRING_LITERAL
      case 56: // function_start
      case 58: // class_start
      case 60: // c_type_start
        value.copy< std::string > (v);
        break;

      case 61: // methods
        value.copy< std::vector<std::shared_ptr<FunctionNode>> > (v);
        break;

      case 50: // block
      case 51: // lines
      case 63: // members_definition
      case 69: // globals_variables
      case 71: // expressions
        value.copy< std::vector<std::shared_ptr<Node>> > (v);
        break;

      case 65: // arguments
      case 66: // definition_arguments
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
      case 46: // FLOAT_LITERAL
        value.template destroy< double > ();
        break;

      case 45: // INT_LITERAL
        value.template destroy< long long > ();
        break;

      case 76: // access
        value.template destroy< std::shared_ptr<AccessNode> > ();
        break;

      case 62: // method_definition
        value.template destroy< std::shared_ptr<FunctionNode> > ();
        break;

      case 52: // line
      case 53: // line_content
      case 54: // definition
      case 55: // function_definition
      case 57: // class_definition
      case 59: // c_type_definition
      case 64: // return_value
      case 67: // globals_definition
      case 70: // c_function_declaration
      case 74: // expression
      case 75: // list
      case 77: // assign_variable
      case 78: // monomial
      case 79: // call
      case 80: // variable
        value.template destroy< std::shared_ptr<Node> > ();
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 6: // C_TYPE_DEFINITION
      case 7: // C_FUNCTION_DECLARATION
      case 9: // C_FUNCTION
      case 10: // MEMBER_IDENTIFIER
      case 11: // IDENTIFIER
      case 25: // DOT_IDENTIFIER
      case 47: // STRING_LITERAL
      case 56: // function_start
      case 58: // class_start
      case 60: // c_type_start
        value.template destroy< std::string > ();
        break;

      case 61: // methods
        value.template destroy< std::vector<std::shared_ptr<FunctionNode>> > ();
        break;

      case 50: // block
      case 51: // lines
      case 63: // members_definition
      case 69: // globals_variables
      case 71: // expressions
        value.template destroy< std::vector<std::shared_ptr<Node>> > ();
        break;

      case 65: // arguments
      case 66: // definition_arguments
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
      case 46: // FLOAT_LITERAL
        value.move< double > (s.value);
        break;

      case 45: // INT_LITERAL
        value.move< long long > (s.value);
        break;

      case 76: // access
        value.move< std::shared_ptr<AccessNode> > (s.value);
        break;

      case 62: // method_definition
        value.move< std::shared_ptr<FunctionNode> > (s.value);
        break;

      case 52: // line
      case 53: // line_content
      case 54: // definition
      case 55: // function_definition
      case 57: // class_definition
      case 59: // c_type_definition
      case 64: // return_value
      case 67: // globals_definition
      case 70: // c_function_declaration
      case 74: // expression
      case 75: // list
      case 77: // assign_variable
      case 78: // monomial
      case 79: // call
      case 80: // variable
        value.move< std::shared_ptr<Node> > (s.value);
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 6: // C_TYPE_DEFINITION
      case 7: // C_FUNCTION_DECLARATION
      case 9: // C_FUNCTION
      case 10: // MEMBER_IDENTIFIER
      case 11: // IDENTIFIER
      case 25: // DOT_IDENTIFIER
      case 47: // STRING_LITERAL
      case 56: // function_start
      case 58: // class_start
      case 60: // c_type_start
        value.move< std::string > (s.value);
        break;

      case 61: // methods
        value.move< std::vector<std::shared_ptr<FunctionNode>> > (s.value);
        break;

      case 50: // block
      case 51: // lines
      case 63: // members_definition
      case 69: // globals_variables
      case 71: // expressions
        value.move< std::vector<std::shared_ptr<Node>> > (s.value);
        break;

      case 65: // arguments
      case 66: // definition_arguments
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
  Parser::make_C_TYPE_DEFINITION (const std::string& v, const location_type& l)
  {
    return symbol_type (token::C_TYPE_DEFINITION, v, l);
  }

  Parser::symbol_type
  Parser::make_C_FUNCTION_DECLARATION (const std::string& v, const location_type& l)
  {
    return symbol_type (token::C_FUNCTION_DECLARATION, v, l);
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
  Parser::make_EQUAL (const location_type& l)
  {
    return symbol_type (token::EQUAL, l);
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
  Parser::make_GLOBAL (const location_type& l)
  {
    return symbol_type (token::GLOBAL, l);
  }

  Parser::symbol_type
  Parser::make_C_FUNCTION_ARGUMENT (const location_type& l)
  {
    return symbol_type (token::C_FUNCTION_ARGUMENT, l);
  }

  Parser::symbol_type
  Parser::make_C_FUNCTION_RETURN (const location_type& l)
  {
    return symbol_type (token::C_FUNCTION_RETURN, l);
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
      case 46: // FLOAT_LITERAL
        value.move< double > (that.value);
        break;

      case 45: // INT_LITERAL
        value.move< long long > (that.value);
        break;

      case 76: // access
        value.move< std::shared_ptr<AccessNode> > (that.value);
        break;

      case 62: // method_definition
        value.move< std::shared_ptr<FunctionNode> > (that.value);
        break;

      case 52: // line
      case 53: // line_content
      case 54: // definition
      case 55: // function_definition
      case 57: // class_definition
      case 59: // c_type_definition
      case 64: // return_value
      case 67: // globals_definition
      case 70: // c_function_declaration
      case 74: // expression
      case 75: // list
      case 77: // assign_variable
      case 78: // monomial
      case 79: // call
      case 80: // variable
        value.move< std::shared_ptr<Node> > (that.value);
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 6: // C_TYPE_DEFINITION
      case 7: // C_FUNCTION_DECLARATION
      case 9: // C_FUNCTION
      case 10: // MEMBER_IDENTIFIER
      case 11: // IDENTIFIER
      case 25: // DOT_IDENTIFIER
      case 47: // STRING_LITERAL
      case 56: // function_start
      case 58: // class_start
      case 60: // c_type_start
        value.move< std::string > (that.value);
        break;

      case 61: // methods
        value.move< std::vector<std::shared_ptr<FunctionNode>> > (that.value);
        break;

      case 50: // block
      case 51: // lines
      case 63: // members_definition
      case 69: // globals_variables
      case 71: // expressions
        value.move< std::vector<std::shared_ptr<Node>> > (that.value);
        break;

      case 65: // arguments
      case 66: // definition_arguments
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
      case 46: // FLOAT_LITERAL
        value.copy< double > (that.value);
        break;

      case 45: // INT_LITERAL
        value.copy< long long > (that.value);
        break;

      case 76: // access
        value.copy< std::shared_ptr<AccessNode> > (that.value);
        break;

      case 62: // method_definition
        value.copy< std::shared_ptr<FunctionNode> > (that.value);
        break;

      case 52: // line
      case 53: // line_content
      case 54: // definition
      case 55: // function_definition
      case 57: // class_definition
      case 59: // c_type_definition
      case 64: // return_value
      case 67: // globals_definition
      case 70: // c_function_declaration
      case 74: // expression
      case 75: // list
      case 77: // assign_variable
      case 78: // monomial
      case 79: // call
      case 80: // variable
        value.copy< std::shared_ptr<Node> > (that.value);
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 6: // C_TYPE_DEFINITION
      case 7: // C_FUNCTION_DECLARATION
      case 9: // C_FUNCTION
      case 10: // MEMBER_IDENTIFIER
      case 11: // IDENTIFIER
      case 25: // DOT_IDENTIFIER
      case 47: // STRING_LITERAL
      case 56: // function_start
      case 58: // class_start
      case 60: // c_type_start
        value.copy< std::string > (that.value);
        break;

      case 61: // methods
        value.copy< std::vector<std::shared_ptr<FunctionNode>> > (that.value);
        break;

      case 50: // block
      case 51: // lines
      case 63: // members_definition
      case 69: // globals_variables
      case 71: // expressions
        value.copy< std::vector<std::shared_ptr<Node>> > (that.value);
        break;

      case 65: // arguments
      case 66: // definition_arguments
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
      case 46: // FLOAT_LITERAL
        yylhs.value.build< double > ();
        break;

      case 45: // INT_LITERAL
        yylhs.value.build< long long > ();
        break;

      case 76: // access
        yylhs.value.build< std::shared_ptr<AccessNode> > ();
        break;

      case 62: // method_definition
        yylhs.value.build< std::shared_ptr<FunctionNode> > ();
        break;

      case 52: // line
      case 53: // line_content
      case 54: // definition
      case 55: // function_definition
      case 57: // class_definition
      case 59: // c_type_definition
      case 64: // return_value
      case 67: // globals_definition
      case 70: // c_function_declaration
      case 74: // expression
      case 75: // list
      case 77: // assign_variable
      case 78: // monomial
      case 79: // call
      case 80: // variable
        yylhs.value.build< std::shared_ptr<Node> > ();
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 6: // C_TYPE_DEFINITION
      case 7: // C_FUNCTION_DECLARATION
      case 9: // C_FUNCTION
      case 10: // MEMBER_IDENTIFIER
      case 11: // IDENTIFIER
      case 25: // DOT_IDENTIFIER
      case 47: // STRING_LITERAL
      case 56: // function_start
      case 58: // class_start
      case 60: // c_type_start
        yylhs.value.build< std::string > ();
        break;

      case 61: // methods
        yylhs.value.build< std::vector<std::shared_ptr<FunctionNode>> > ();
        break;

      case 50: // block
      case 51: // lines
      case 63: // members_definition
      case 69: // globals_variables
      case 71: // expressions
        yylhs.value.build< std::vector<std::shared_ptr<Node>> > ();
        break;

      case 65: // arguments
      case 66: // definition_arguments
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
#line 131 "parser.yy" // lalr1.cc:859
    {
        driver.ast_generator->break_out_of_namespace();
        driver.ast_generator->generate(std::move(yystack_[0].value.as< std::vector<std::shared_ptr<Node>> > ()));
    }
#line 1454 "parser.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 137 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[0].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(driver.ast_generator->create_block_end());
        std::cout << "build block." << std::endl;
    }
#line 1464 "parser.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 144 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1472 "parser.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 148 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1481 "parser.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 154 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[1].value.as< std::shared_ptr<Node> > ());
    }
#line 1489 "parser.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 158 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[1].value.as< std::shared_ptr<Node> > ());
    }
#line 1497 "parser.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 162 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = yystack_[0].value.as< std::shared_ptr<Node> > ();
    }
#line 1505 "parser.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 167 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1513 "parser.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 172 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1521 "parser.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 176 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1529 "parser.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 180 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1537 "parser.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 184 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1545 "parser.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 188 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1553 "parser.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 193 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->add_function(yystack_[5].value.as< std::string > (),std::move(yystack_[4].value.as< std::vector<std::string> > ()),std::move(yystack_[2].value.as< std::vector<std::shared_ptr<Node>> > ()),std::move(yystack_[1].value.as< std::shared_ptr<Node> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1562 "parser.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 199 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
        driver.ast_generator->into_namespace(yystack_[0].value.as< std::string > ());
    }
#line 1571 "parser.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 205 "parser.yy" // lalr1.cc:859
    { 
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(driver.ast_generator->create_class(yystack_[4].value.as< std::string > (),yystack_[3].value.as< std::vector<std::string> > (),yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > (),yystack_[0].value.as< std::vector<std::shared_ptr<FunctionNode>> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1580 "parser.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 210 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(driver.ast_generator->create_class(yystack_[3].value.as< std::string > (),yystack_[2].value.as< std::vector<std::string> > (),yystack_[0].value.as< std::vector<std::shared_ptr<Node>> > (),{}));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1589 "parser.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 215 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(driver.ast_generator->create_class(yystack_[3].value.as< std::string > (),yystack_[2].value.as< std::vector<std::string> > (),{},yystack_[0].value.as< std::vector<std::shared_ptr<FunctionNode>> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1598 "parser.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 221 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
        driver.ast_generator->into_namespace(yystack_[0].value.as< std::string > ());
    }
#line 1607 "parser.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 227 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(driver.ast_generator->create_C_type(yystack_[2].value.as< std::string > (),yystack_[0].value.as< std::vector<std::shared_ptr<Node>> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1616 "parser.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 233 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
        driver.ast_generator->into_namespace(yystack_[0].value.as< std::string > ());
    }
#line 1625 "parser.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 239 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<FunctionNode>> > ().push_back(yystack_[1].value.as< std::shared_ptr<FunctionNode> > ());
    }
#line 1633 "parser.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 243 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<FunctionNode>> > () = std::move(yystack_[2].value.as< std::vector<std::shared_ptr<FunctionNode>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<FunctionNode>> > ().push_back(yystack_[1].value.as< std::shared_ptr<FunctionNode> > ());
    }
#line 1642 "parser.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 249 "parser.yy" // lalr1.cc:859
    {
        auto args = std::move(yystack_[3].value.as< std::vector<std::string> > ());
        args.insert(args.begin(),"self");
        yylhs.value.as< std::shared_ptr<FunctionNode> > () = driver.ast_generator->add_function(yystack_[4].value.as< std::string > (),std::move(args),std::move(yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1653 "parser.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 257 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(driver.ast_generator->assign(yystack_[3].value.as< std::string > (),std::move(yystack_[1].value.as< std::shared_ptr<Node> > ()),false));
    }
#line 1661 "parser.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 261 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[4].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(driver.ast_generator->assign(yystack_[3].value.as< std::string > (),std::move(yystack_[1].value.as< std::shared_ptr<Node> > ()),false));
    }
#line 1670 "parser.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 267 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = yystack_[0].value.as< std::shared_ptr<Node> > ();
    }
#line 1678 "parser.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 271 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = nullptr;
    }
#line 1686 "parser.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 276 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > () = std::move(yystack_[1].value.as< std::vector<std::string> > ());
    }
#line 1694 "parser.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 280 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > () = {};
    }
#line 1702 "parser.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 285 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > ().push_back(yystack_[0].value.as< std::string > ());
        driver.ast_generator->add_argument(yystack_[0].value.as< std::string > ());
    }
#line 1711 "parser.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 290 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > () = std::move(yystack_[2].value.as< std::vector<std::string> > ());
        yylhs.value.as< std::vector<std::string> > ().push_back(yystack_[0].value.as< std::string > ());
        driver.ast_generator->add_argument(yystack_[0].value.as< std::string > ());
    }
#line 1721 "parser.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 297 "parser.yy" // lalr1.cc:859
    {
        //driver.ast_generator->add_global_variables($5);
        is_global = NOT_GLOBAL;
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->no_value_node;
    }
#line 1731 "parser.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 304 "parser.yy" // lalr1.cc:859
    {
        is_global = GLOBAL;
    }
#line 1739 "parser.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 309 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1747 "parser.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 313 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[2].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1756 "parser.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 319 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->declare_C_function(yystack_[7].value.as< std::string > (),yystack_[4].value.as< std::vector<std::shared_ptr<Node>> > (),yystack_[1].value.as< std::shared_ptr<Node> > ());
    }
#line 1764 "parser.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 323 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->declare_C_function(yystack_[6].value.as< std::string > (),{},yystack_[1].value.as< std::shared_ptr<Node> > ());
    }
#line 1772 "parser.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 328 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1780 "parser.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 332 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[2].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1789 "parser.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 338 "parser.yy" // lalr1.cc:859
    {
        driver.ast_generator->into_namespace();
    }
#line 1797 "parser.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 343 "parser.yy" // lalr1.cc:859
    {
        driver.ast_generator->into_namespace();
    }
#line 1805 "parser.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 348 "parser.yy" // lalr1.cc:859
    {
        blawn_state = EXIST_IF;
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_if(yystack_[5].value.as< std::shared_ptr<Node> > (),yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
        driver.ast_generator->break_out_of_namespace();
    }
#line 1815 "parser.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 354 "parser.yy" // lalr1.cc:859
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
#line 1830 "parser.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 365 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_for(yystack_[9].value.as< std::shared_ptr<Node> > (),yystack_[7].value.as< std::shared_ptr<Node> > (),yystack_[5].value.as< std::shared_ptr<Node> > (),yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
        driver.ast_generator->break_out_of_namespace();
    }
#line 1839 "parser.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 370 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = yystack_[0].value.as< std::shared_ptr<Node> > ();
    }
#line 1847 "parser.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 374 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"+");
    }
#line 1855 "parser.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 378 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"-");
    }
#line 1863 "parser.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 382 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"*");
    }
#line 1871 "parser.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 386 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"/");
    }
#line 1879 "parser.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 390 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"and");
    }
#line 1887 "parser.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 394 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"or");
    }
#line 1895 "parser.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 398 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),">=");
    }
#line 1903 "parser.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 402 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"<=");
    }
#line 1911 "parser.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 406 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),">");
    }
#line 1919 "parser.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 410 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"<");
    }
#line 1927 "parser.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 414 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"!=");
    }
#line 1935 "parser.tab.cc" // lalr1.cc:859
    break;

  case 59:
#line 418 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"==");
    }
#line 1943 "parser.tab.cc" // lalr1.cc:859
    break;

  case 60:
#line 422 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1951 "parser.tab.cc" // lalr1.cc:859
    break;

  case 61:
#line 426 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1959 "parser.tab.cc" // lalr1.cc:859
    break;

  case 62:
#line 430 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<AccessNode> > ());
    }
#line 1967 "parser.tab.cc" // lalr1.cc:859
    break;

  case 63:
#line 435 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_list(std::move(yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ()));
    }
#line 1975 "parser.tab.cc" // lalr1.cc:859
    break;

  case 64:
#line 439 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_list();
    }
#line 1983 "parser.tab.cc" // lalr1.cc:859
    break;

  case 65:
#line 444 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<AccessNode> > () = driver.ast_generator->create_access(yystack_[1].value.as< std::shared_ptr<Node> > (),yystack_[0].value.as< std::string > ());
    }
#line 1991 "parser.tab.cc" // lalr1.cc:859
    break;

  case 66:
#line 449 "parser.yy" // lalr1.cc:859
    {
        if (is_global == NOT_GLOBAL)
        {yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->assign(yystack_[2].value.as< std::string > (),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),false);}
        if (is_global == GLOBAL)
        {yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->assign(yystack_[2].value.as< std::string > (),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),true);}
    }
#line 2002 "parser.tab.cc" // lalr1.cc:859
    break;

  case 67:
#line 456 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->assign(yystack_[2].value.as< std::shared_ptr<AccessNode> > (),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 2010 "parser.tab.cc" // lalr1.cc:859
    break;

  case 68:
#line 461 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = yystack_[0].value.as< std::shared_ptr<Node> > ();
    }
#line 2018 "parser.tab.cc" // lalr1.cc:859
    break;

  case 69:
#line 465 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_string(yystack_[0].value.as< std::string > ());
    }
#line 2026 "parser.tab.cc" // lalr1.cc:859
    break;

  case 70:
#line 469 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_float(yystack_[0].value.as< double > ());
    }
#line 2034 "parser.tab.cc" // lalr1.cc:859
    break;

  case 71:
#line 473 "parser.yy" // lalr1.cc:859
    { 
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_integer(yystack_[0].value.as< long long > ());
    }
#line 2042 "parser.tab.cc" // lalr1.cc:859
    break;

  case 72:
#line 477 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 2050 "parser.tab.cc" // lalr1.cc:859
    break;

  case 73:
#line 482 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_call(yystack_[3].value.as< std::string > (),std::move(yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ()));
    }
#line 2058 "parser.tab.cc" // lalr1.cc:859
    break;

  case 74:
#line 486 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_call(yystack_[2].value.as< std::string > (),{});
    }
#line 2066 "parser.tab.cc" // lalr1.cc:859
    break;

  case 75:
#line 490 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_call(yystack_[3].value.as< std::shared_ptr<AccessNode> > (),yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
    }
#line 2074 "parser.tab.cc" // lalr1.cc:859
    break;

  case 76:
#line 494 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_call(yystack_[2].value.as< std::shared_ptr<AccessNode> > (),{});
    }
#line 2082 "parser.tab.cc" // lalr1.cc:859
    break;

  case 77:
#line 499 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->get_named_value(yystack_[0].value.as< std::string > ());
    }
#line 2090 "parser.tab.cc" // lalr1.cc:859
    break;


#line 2094 "parser.tab.cc" // lalr1.cc:859
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


  const signed char Parser::yypact_ninf_ = -106;

  const signed char Parser::yytable_ninf_ = -38;

  const short int
  Parser::yypact_[] =
  {
      -1,  -106,  -106,  -106,   -27,     2,    61,  -106,  -106,   129,
    -106,  -106,  -106,  -106,    22,  -106,    -1,  -106,    18,  -106,
    -106,     0,  -106,     0,  -106,     4,  -106,    23,  -106,   129,
      30,   319,  -106,    13,  -106,  -106,  -106,  -106,    53,   129,
      91,  -106,   -13,   319,    62,  -106,  -106,  -106,  -106,    -4,
      52,    56,    31,    71,   167,    82,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,  -106,   129,
     113,   110,   319,  -106,    -3,   129,  -106,   129,  -106,  -106,
      39,    -1,     9,    98,   103,    70,    86,    74,   197,   197,
     185,   185,   185,   185,   185,   185,    80,    80,    95,    95,
     319,  -106,    59,    87,   -20,  -106,   319,   302,   114,  -106,
     123,     0,   128,    90,    11,   129,   127,   129,   108,    -1,
    -106,   129,    92,   129,  -106,   129,   109,   118,   179,  -106,
     128,   180,   129,   207,   319,   208,    -1,   140,   212,   129,
     225,   319,  -106,    -1,  -106,  -106,   257,   132,   141,  -106,
    -106,   270,   143,   123,  -106,   209,   210,  -106,  -106,   211,
    -106,  -106,    -1,   226,  -106
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,    16,    20,    22,     0,    77,     0,    42,    43,     0,
      35,    71,    70,    69,     0,     2,     3,     4,     0,     8,
      10,     0,    11,     0,    12,     0,    13,     0,    14,     0,
       0,     9,    61,    62,    47,    60,    68,    72,     0,     0,
       0,    64,     0,    40,     0,     1,     5,     7,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    65,     0,
       0,     0,    66,    74,     0,     0,    63,     0,    32,    31,
       0,     0,     0,     0,    21,     0,     0,     0,    52,    53,
      59,    58,    54,    55,    56,    57,    48,    49,    50,    51,
      67,    76,     0,     0,     0,    73,    41,     0,     0,    30,
       0,     0,    19,     0,    18,     0,     0,     0,     0,     0,
      75,     0,     0,     0,    33,    29,     0,     0,     0,    23,
      17,     0,     0,     0,     0,    47,     0,     0,     0,     0,
       0,    28,    15,     0,    24,    26,     0,     0,     0,    45,
      39,     0,     0,     0,    27,     0,    47,    44,    38,     0,
      25,    34,     0,     0,    46
  };

  const short int
  Parser::yypgoto_[] =
  {
    -106,  -106,   -70,  -106,   242,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,   145,   -83,   178,   111,   -22,  -106,  -106,
    -106,  -106,  -106,   -32,  -106,  -106,    -6,  -106,  -106,  -105,
    -106,  -106,  -106
  };

  const short int
  Parser::yydefgoto_[] =
  {
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   112,   113,    84,   126,    50,    80,    26,
      27,   133,    28,    42,    29,    30,    31,    32,    33,    34,
      35,    36,    37
  };

  const short int
  Parser::yytable_[] =
  {
      43,    51,     1,    44,     2,     3,     4,    78,    74,    75,
       5,   110,   135,   111,    39,   111,    75,    38,    47,    83,
      76,   116,    45,    54,   122,    69,    75,    79,   105,   128,
      49,     6,    40,    72,    43,     7,     8,     9,   102,   104,
      10,    83,   156,    70,    11,    12,    13,   128,    52,   137,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,    48,   100,    43,    43,   148,    53,   108,   106,
     109,   107,     5,   153,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    75,   127,
     120,    77,   163,     6,    41,    71,    81,     7,     8,     9,
      82,    85,     5,    66,    67,    68,    11,    12,    13,   131,
     115,   134,    87,   116,   117,   138,   118,   140,   119,   141,
      68,     5,    73,     6,     5,   124,   146,     7,     8,     9,
     121,   125,   111,   151,   129,   139,    11,    12,    13,   132,
       5,   134,     6,     5,   101,     6,     7,     8,     9,     7,
       8,     9,   136,   142,   103,    11,    12,    13,    11,    12,
      13,     6,   143,   155,     6,     7,     8,     9,     7,     8,
       9,   149,   157,   159,    11,    12,    13,    11,    12,    13,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    64,    65,    66,    67,
      68,    86,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   144,   145,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   147,   -36,   161,   -37,   162,   150,   164,    46,   130,
     114,     0,     0,     0,   160,     0,     0,     0,     0,   152,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,     0,     0,     0,
       0,   154,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   158,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,     0,
       0,   123,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68
  };

  const short int
  Parser::yycheck_[] =
  {
       6,    23,     3,     9,     5,     6,     7,    11,    40,    29,
      11,    81,   117,     4,    12,     4,    29,    44,     0,    10,
      33,    10,     0,    29,    44,    12,    29,    31,    31,   112,
      30,    32,    30,    39,    40,    36,    37,    38,    70,    71,
      41,    10,   147,    30,    45,    46,    47,   130,    44,   119,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    44,    69,    70,    71,   136,    44,    29,    75,
      31,    77,    11,   143,    44,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    29,   111,
      31,    29,   162,    32,    33,    42,    44,    36,    37,    38,
      44,    30,    11,    23,    24,    25,    45,    46,    47,   115,
      12,   117,    30,    10,    44,   121,    30,   123,    44,   125,
      25,    11,    31,    32,    11,    11,   132,    36,    37,    38,
      43,     8,     4,   139,    44,    43,    45,    46,    47,    12,
      11,   147,    32,    11,    31,    32,    36,    37,    38,    36,
      37,    38,    44,    44,    44,    45,    46,    47,    45,    46,
      47,    32,    44,    31,    32,    36,    37,    38,    36,    37,
      38,    31,    31,    30,    45,    46,    47,    45,    46,    47,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    21,    22,    23,    24,
      25,    44,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    44,    44,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    44,    44,    44,    44,    44,    44,    31,    16,   114,
      82,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,    44,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    29,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     3,     5,     6,     7,    11,    32,    36,    37,    38,
      41,    45,    46,    47,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    67,    68,    70,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    44,    12,
      30,    33,    71,    74,    74,     0,    52,     0,    44,    30,
      65,    65,    44,    44,    74,    44,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    12,
      30,    42,    74,    31,    71,    29,    33,    29,    11,    31,
      66,    44,    44,    10,    63,    30,    44,    30,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    31,    71,    44,    71,    31,    74,    74,    29,    31,
      50,     4,    61,    62,    63,    12,    10,    44,    30,    44,
      31,    43,    44,    29,    11,     8,    64,    65,    62,    44,
      61,    74,    12,    69,    74,    77,    44,    50,    74,    43,
      74,    74,    44,    44,    44,    44,    74,    44,    50,    31,
      44,    74,    44,    50,    44,    31,    77,    31,    44,    30,
      64,    44,    44,    50,    31
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    48,    49,    50,    51,    51,    52,    52,    52,    53,
      54,    54,    54,    54,    54,    55,    56,    57,    57,    57,
      58,    59,    60,    61,    61,    62,    63,    63,    64,    64,
      65,    65,    66,    66,    67,    68,    69,    69,    70,    70,
      71,    71,    72,    73,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    75,    75,    76,    77,    77,    78,    78,
      78,    78,    78,    79,    79,    79,    79,    80
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     6,     1,     5,     4,     4,
       1,     3,     1,     2,     3,     5,     4,     5,     2,     1,
       3,     2,     1,     3,     8,     1,     1,     3,     8,     7,
       1,     3,     1,     1,     7,     6,    11,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     3,     2,     2,     3,     3,     1,     1,
       1,     1,     1,     4,     3,     4,     3,     1
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
  "IDENTIFIER", "EQUAL", "OP_AND", "OP_OR", "OP_EQUAL", "OP_NOT_EQUAL",
  "OP_MORE_EQUAL", "OP_LESS_EQUAL", "OP_MORE", "OP_LESS", "PLUS", "MINUS",
  "ASTERISK", "SLASH", "DOT_IDENTIFIER", "USE", "COLON", "SEMICOLON",
  "COMMA", "LEFT_PARENTHESIS", "RIGHT_PARENTHESIS", "LEFT_CURLY_BRACE",
  "RIGHT_CURLY_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET", "IF", "ELSE",
  "FOR", "IN", "WHILE", "GLOBAL", "C_FUNCTION_ARGUMENT",
  "C_FUNCTION_RETURN", "EOL", "INT_LITERAL", "FLOAT_LITERAL",
  "STRING_LITERAL", "$accept", "program", "block", "lines", "line",
  "line_content", "definition", "function_definition", "function_start",
  "class_definition", "class_start", "c_type_definition", "c_type_start",
  "methods", "method_definition", "members_definition", "return_value",
  "arguments", "definition_arguments", "globals_definition",
  "global_start", "globals_variables", "c_function_declaration",
  "expressions", "if_start", "else_start", "expression", "list", "access",
  "assign_variable", "monomial", "call", "variable", YY_NULLPTR
  };


  const unsigned short int
  Parser::yyrline_[] =
  {
       0,   130,   130,   136,   143,   147,   153,   157,   161,   166,
     171,   175,   179,   183,   187,   192,   198,   204,   209,   214,
     220,   226,   232,   238,   242,   248,   256,   260,   266,   270,
     275,   279,   284,   289,   296,   303,   308,   312,   318,   322,
     327,   331,   337,   342,   347,   353,   364,   369,   373,   377,
     381,   385,   389,   393,   397,   401,   405,   409,   413,   417,
     421,   425,   429,   434,   438,   443,   448,   455,   460,   464,
     468,   472,   476,   481,   485,   489,   493,   498
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
    };
    const unsigned int user_token_number_max_ = 302;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 5 "parser.yy" // lalr1.cc:1167
} // Blawn
#line 2578 "parser.tab.cc" // lalr1.cc:1167
#line 502 "parser.yy" // lalr1.cc:1168


void Blawn::Parser::error( const location_type &l, const std::string &err_message )
{
    std::cerr << "Error: " << err_message << " at " << l << "\n";
    exit(1);
} 
