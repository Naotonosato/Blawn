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
    std::string join(std::vector<std::string> text)
    {
        std::string type_identifier;
        for(auto& t:text){type_identifier+=" " + t;}
        return type_identifier;
    }    

#line 78 "parser.tab.cc" // lalr1.cc:413


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
#line 164 "parser.tab.cc" // lalr1.cc:479

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
      case 49: // FLOAT_LITERAL
        value.copy< double > (other.value);
        break;

      case 48: // INT_LITERAL
        value.copy< long long > (other.value);
        break;

      case 84: // access
        value.copy< std::shared_ptr<AccessNode> > (other.value);
        break;

      case 65: // method_definition
        value.copy< std::shared_ptr<FunctionNode> > (other.value);
        break;

      case 54: // line
      case 56: // line_content
      case 57: // definition
      case 58: // function_definition
      case 60: // class_definition
      case 62: // c_type_definition
      case 70: // C_returns
      case 71: // return_value
      case 74: // globals_definition
      case 77: // c_function_declaration
      case 82: // expression
      case 83: // list
      case 85: // assign_variable
      case 86: // monomial
      case 87: // call
      case 88: // variable
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
      case 26: // DOT_IDENTIFIER
      case 47: // STRING_LITERAL
      case 59: // function_start
      case 61: // class_start
      case 63: // c_type_start
        value.copy< std::string > (other.value);
        break;

      case 64: // methods
        value.copy< std::vector<std::shared_ptr<FunctionNode>> > (other.value);
        break;

      case 52: // block
      case 53: // lines
      case 66: // members_definition
      case 67: // C_members_definition
      case 69: // C_arguments
      case 76: // globals_variables
      case 78: // expressions
      case 81: // for_start
        value.copy< std::vector<std::shared_ptr<Node>> > (other.value);
        break;

      case 68: // C_type_identifier
      case 72: // arguments
      case 73: // definition_arguments
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
      case 49: // FLOAT_LITERAL
        value.copy< double > (v);
        break;

      case 48: // INT_LITERAL
        value.copy< long long > (v);
        break;

      case 84: // access
        value.copy< std::shared_ptr<AccessNode> > (v);
        break;

      case 65: // method_definition
        value.copy< std::shared_ptr<FunctionNode> > (v);
        break;

      case 54: // line
      case 56: // line_content
      case 57: // definition
      case 58: // function_definition
      case 60: // class_definition
      case 62: // c_type_definition
      case 70: // C_returns
      case 71: // return_value
      case 74: // globals_definition
      case 77: // c_function_declaration
      case 82: // expression
      case 83: // list
      case 85: // assign_variable
      case 86: // monomial
      case 87: // call
      case 88: // variable
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
      case 26: // DOT_IDENTIFIER
      case 47: // STRING_LITERAL
      case 59: // function_start
      case 61: // class_start
      case 63: // c_type_start
        value.copy< std::string > (v);
        break;

      case 64: // methods
        value.copy< std::vector<std::shared_ptr<FunctionNode>> > (v);
        break;

      case 52: // block
      case 53: // lines
      case 66: // members_definition
      case 67: // C_members_definition
      case 69: // C_arguments
      case 76: // globals_variables
      case 78: // expressions
      case 81: // for_start
        value.copy< std::vector<std::shared_ptr<Node>> > (v);
        break;

      case 68: // C_type_identifier
      case 72: // arguments
      case 73: // definition_arguments
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
      case 49: // FLOAT_LITERAL
        value.template destroy< double > ();
        break;

      case 48: // INT_LITERAL
        value.template destroy< long long > ();
        break;

      case 84: // access
        value.template destroy< std::shared_ptr<AccessNode> > ();
        break;

      case 65: // method_definition
        value.template destroy< std::shared_ptr<FunctionNode> > ();
        break;

      case 54: // line
      case 56: // line_content
      case 57: // definition
      case 58: // function_definition
      case 60: // class_definition
      case 62: // c_type_definition
      case 70: // C_returns
      case 71: // return_value
      case 74: // globals_definition
      case 77: // c_function_declaration
      case 82: // expression
      case 83: // list
      case 85: // assign_variable
      case 86: // monomial
      case 87: // call
      case 88: // variable
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
      case 26: // DOT_IDENTIFIER
      case 47: // STRING_LITERAL
      case 59: // function_start
      case 61: // class_start
      case 63: // c_type_start
        value.template destroy< std::string > ();
        break;

      case 64: // methods
        value.template destroy< std::vector<std::shared_ptr<FunctionNode>> > ();
        break;

      case 52: // block
      case 53: // lines
      case 66: // members_definition
      case 67: // C_members_definition
      case 69: // C_arguments
      case 76: // globals_variables
      case 78: // expressions
      case 81: // for_start
        value.template destroy< std::vector<std::shared_ptr<Node>> > ();
        break;

      case 68: // C_type_identifier
      case 72: // arguments
      case 73: // definition_arguments
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
      case 49: // FLOAT_LITERAL
        value.move< double > (s.value);
        break;

      case 48: // INT_LITERAL
        value.move< long long > (s.value);
        break;

      case 84: // access
        value.move< std::shared_ptr<AccessNode> > (s.value);
        break;

      case 65: // method_definition
        value.move< std::shared_ptr<FunctionNode> > (s.value);
        break;

      case 54: // line
      case 56: // line_content
      case 57: // definition
      case 58: // function_definition
      case 60: // class_definition
      case 62: // c_type_definition
      case 70: // C_returns
      case 71: // return_value
      case 74: // globals_definition
      case 77: // c_function_declaration
      case 82: // expression
      case 83: // list
      case 85: // assign_variable
      case 86: // monomial
      case 87: // call
      case 88: // variable
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
      case 26: // DOT_IDENTIFIER
      case 47: // STRING_LITERAL
      case 59: // function_start
      case 61: // class_start
      case 63: // c_type_start
        value.move< std::string > (s.value);
        break;

      case 64: // methods
        value.move< std::vector<std::shared_ptr<FunctionNode>> > (s.value);
        break;

      case 52: // block
      case 53: // lines
      case 66: // members_definition
      case 67: // C_members_definition
      case 69: // C_arguments
      case 76: // globals_variables
      case 78: // expressions
      case 81: // for_start
        value.move< std::vector<std::shared_ptr<Node>> > (s.value);
        break;

      case 68: // C_type_identifier
      case 72: // arguments
      case 73: // definition_arguments
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
  Parser::make_ARROW (const location_type& l)
  {
    return symbol_type (token::ARROW, l);
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
  Parser::make_IMPORT (const location_type& l)
  {
    return symbol_type (token::IMPORT, l);
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
  Parser::make_STRING_LITERAL (const std::string& v, const location_type& l)
  {
    return symbol_type (token::STRING_LITERAL, v, l);
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
      case 49: // FLOAT_LITERAL
        value.move< double > (that.value);
        break;

      case 48: // INT_LITERAL
        value.move< long long > (that.value);
        break;

      case 84: // access
        value.move< std::shared_ptr<AccessNode> > (that.value);
        break;

      case 65: // method_definition
        value.move< std::shared_ptr<FunctionNode> > (that.value);
        break;

      case 54: // line
      case 56: // line_content
      case 57: // definition
      case 58: // function_definition
      case 60: // class_definition
      case 62: // c_type_definition
      case 70: // C_returns
      case 71: // return_value
      case 74: // globals_definition
      case 77: // c_function_declaration
      case 82: // expression
      case 83: // list
      case 85: // assign_variable
      case 86: // monomial
      case 87: // call
      case 88: // variable
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
      case 26: // DOT_IDENTIFIER
      case 47: // STRING_LITERAL
      case 59: // function_start
      case 61: // class_start
      case 63: // c_type_start
        value.move< std::string > (that.value);
        break;

      case 64: // methods
        value.move< std::vector<std::shared_ptr<FunctionNode>> > (that.value);
        break;

      case 52: // block
      case 53: // lines
      case 66: // members_definition
      case 67: // C_members_definition
      case 69: // C_arguments
      case 76: // globals_variables
      case 78: // expressions
      case 81: // for_start
        value.move< std::vector<std::shared_ptr<Node>> > (that.value);
        break;

      case 68: // C_type_identifier
      case 72: // arguments
      case 73: // definition_arguments
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
      case 49: // FLOAT_LITERAL
        value.copy< double > (that.value);
        break;

      case 48: // INT_LITERAL
        value.copy< long long > (that.value);
        break;

      case 84: // access
        value.copy< std::shared_ptr<AccessNode> > (that.value);
        break;

      case 65: // method_definition
        value.copy< std::shared_ptr<FunctionNode> > (that.value);
        break;

      case 54: // line
      case 56: // line_content
      case 57: // definition
      case 58: // function_definition
      case 60: // class_definition
      case 62: // c_type_definition
      case 70: // C_returns
      case 71: // return_value
      case 74: // globals_definition
      case 77: // c_function_declaration
      case 82: // expression
      case 83: // list
      case 85: // assign_variable
      case 86: // monomial
      case 87: // call
      case 88: // variable
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
      case 26: // DOT_IDENTIFIER
      case 47: // STRING_LITERAL
      case 59: // function_start
      case 61: // class_start
      case 63: // c_type_start
        value.copy< std::string > (that.value);
        break;

      case 64: // methods
        value.copy< std::vector<std::shared_ptr<FunctionNode>> > (that.value);
        break;

      case 52: // block
      case 53: // lines
      case 66: // members_definition
      case 67: // C_members_definition
      case 69: // C_arguments
      case 76: // globals_variables
      case 78: // expressions
      case 81: // for_start
        value.copy< std::vector<std::shared_ptr<Node>> > (that.value);
        break;

      case 68: // C_type_identifier
      case 72: // arguments
      case 73: // definition_arguments
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
      case 49: // FLOAT_LITERAL
        yylhs.value.build< double > ();
        break;

      case 48: // INT_LITERAL
        yylhs.value.build< long long > ();
        break;

      case 84: // access
        yylhs.value.build< std::shared_ptr<AccessNode> > ();
        break;

      case 65: // method_definition
        yylhs.value.build< std::shared_ptr<FunctionNode> > ();
        break;

      case 54: // line
      case 56: // line_content
      case 57: // definition
      case 58: // function_definition
      case 60: // class_definition
      case 62: // c_type_definition
      case 70: // C_returns
      case 71: // return_value
      case 74: // globals_definition
      case 77: // c_function_declaration
      case 82: // expression
      case 83: // list
      case 85: // assign_variable
      case 86: // monomial
      case 87: // call
      case 88: // variable
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
      case 26: // DOT_IDENTIFIER
      case 47: // STRING_LITERAL
      case 59: // function_start
      case 61: // class_start
      case 63: // c_type_start
        yylhs.value.build< std::string > ();
        break;

      case 64: // methods
        yylhs.value.build< std::vector<std::shared_ptr<FunctionNode>> > ();
        break;

      case 52: // block
      case 53: // lines
      case 66: // members_definition
      case 67: // C_members_definition
      case 69: // C_arguments
      case 76: // globals_variables
      case 78: // expressions
      case 81: // for_start
        yylhs.value.build< std::vector<std::shared_ptr<Node>> > ();
        break;

      case 68: // C_type_identifier
      case 72: // arguments
      case 73: // definition_arguments
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
#line 142 "parser.yy" // lalr1.cc:859
    {
        driver.ast_generator->break_out_of_namespace();
        driver.ast_generator->generate(std::move(yystack_[0].value.as< std::vector<std::shared_ptr<Node>> > ()));
    }
#line 1507 "parser.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 148 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[0].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(driver.ast_generator->create_block_end());
    }
#line 1516 "parser.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 154 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1524 "parser.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 158 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1533 "parser.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 164 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[1].value.as< std::shared_ptr<Node> > ());
    }
#line 1541 "parser.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 168 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[1].value.as< std::shared_ptr<Node> > ());
    }
#line 1549 "parser.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 172 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = yystack_[0].value.as< std::shared_ptr<Node> > ();
    }
#line 1557 "parser.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 176 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->no_value_node;
    }
#line 1565 "parser.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 183 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1573 "parser.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 188 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1581 "parser.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 192 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1589 "parser.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 196 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1597 "parser.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 200 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1605 "parser.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 204 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1613 "parser.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 209 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->add_function(yystack_[5].value.as< std::string > (),std::move(yystack_[4].value.as< std::vector<std::string> > ()),std::move(yystack_[2].value.as< std::vector<std::shared_ptr<Node>> > ()),std::move(yystack_[1].value.as< std::shared_ptr<Node> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1622 "parser.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 214 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->add_function(yystack_[4].value.as< std::string > (),std::move(yystack_[3].value.as< std::vector<std::string> > ()),{},std::move(yystack_[1].value.as< std::shared_ptr<Node> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1631 "parser.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 220 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
        driver.ast_generator->into_namespace(yystack_[0].value.as< std::string > ());
    }
#line 1640 "parser.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 226 "parser.yy" // lalr1.cc:859
    { 
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(driver.ast_generator->create_class(yystack_[4].value.as< std::string > (),yystack_[3].value.as< std::vector<std::string> > (),yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > (),yystack_[0].value.as< std::vector<std::shared_ptr<FunctionNode>> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1649 "parser.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 231 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(driver.ast_generator->create_class(yystack_[3].value.as< std::string > (),yystack_[2].value.as< std::vector<std::string> > (),yystack_[0].value.as< std::vector<std::shared_ptr<Node>> > (),{}));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1658 "parser.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 236 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(driver.ast_generator->create_class(yystack_[3].value.as< std::string > (),yystack_[2].value.as< std::vector<std::string> > (),{},yystack_[0].value.as< std::vector<std::shared_ptr<FunctionNode>> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1667 "parser.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 242 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
        driver.ast_generator->into_namespace(yystack_[0].value.as< std::string > ());
    }
#line 1676 "parser.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 248 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(driver.ast_generator->create_C_type(yystack_[2].value.as< std::string > (),yystack_[0].value.as< std::vector<std::shared_ptr<Node>> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1685 "parser.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 254 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
        driver.ast_generator->into_namespace(yystack_[0].value.as< std::string > ());
    }
#line 1694 "parser.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 260 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<FunctionNode>> > ().push_back(yystack_[1].value.as< std::shared_ptr<FunctionNode> > ());
    }
#line 1702 "parser.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 264 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<FunctionNode>> > () = std::move(yystack_[2].value.as< std::vector<std::shared_ptr<FunctionNode>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<FunctionNode>> > ().push_back(yystack_[1].value.as< std::shared_ptr<FunctionNode> > ());
    }
#line 1711 "parser.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 270 "parser.yy" // lalr1.cc:859
    {
        auto args = std::move(yystack_[3].value.as< std::vector<std::string> > ());
        args.insert(args.begin(),"self");
        yylhs.value.as< std::shared_ptr<FunctionNode> > () = driver.ast_generator->add_function(yystack_[4].value.as< std::string > (),std::move(args),std::move(yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1722 "parser.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 278 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(driver.ast_generator->create_assign(yystack_[3].value.as< std::string > (),std::move(yystack_[1].value.as< std::shared_ptr<Node> > ()),false));
    }
#line 1730 "parser.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 282 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[4].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(driver.ast_generator->create_assign(yystack_[3].value.as< std::string > (),std::move(yystack_[1].value.as< std::shared_ptr<Node> > ()),false));
    }
#line 1739 "parser.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 288 "parser.yy" // lalr1.cc:859
    {
        std::string type_identifier = join(yystack_[1].value.as< std::vector<std::string> > ());
        auto assign_value = driver.ast_generator->create_C_member(type_identifier);
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(driver.ast_generator->create_assign(yystack_[3].value.as< std::string > (),std::move(assign_value),false));
    }
#line 1749 "parser.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 294 "parser.yy" // lalr1.cc:859
    {
        std::string type_identifier = join(yystack_[1].value.as< std::vector<std::string> > ());
        auto assign_value = driver.ast_generator->create_C_member(type_identifier);
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[4].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(driver.ast_generator->create_assign(yystack_[3].value.as< std::string > (),std::move(assign_value),false));
    }
#line 1760 "parser.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 302 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > ().push_back(yystack_[0].value.as< std::string > ());
    }
#line 1768 "parser.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 306 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > () = std::move(yystack_[1].value.as< std::vector<std::string> > ());
        yylhs.value.as< std::vector<std::string> > ().push_back(yystack_[0].value.as< std::string > ());
    }
#line 1777 "parser.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 312 "parser.yy" // lalr1.cc:859
    {
        std::string type_identifier = join(yystack_[0].value.as< std::vector<std::string> > ());
        auto assign_value = driver.ast_generator->create_C_member(type_identifier);
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(assign_value);
    }
#line 1787 "parser.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 318 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[2].value.as< std::vector<std::shared_ptr<Node>> > ());
        std::string type_identifier = join(yystack_[0].value.as< std::vector<std::string> > ());
        auto assign_value = driver.ast_generator->create_C_member(type_identifier);
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(assign_value);
    }
#line 1798 "parser.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 326 "parser.yy" // lalr1.cc:859
    {
        std::string type_identifier = join(yystack_[0].value.as< std::vector<std::string> > ());
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_C_member(type_identifier);
    }
#line 1807 "parser.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 332 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = yystack_[0].value.as< std::shared_ptr<Node> > ();
    }
#line 1815 "parser.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 336 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = nullptr;
    }
#line 1823 "parser.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 341 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > () = std::move(yystack_[1].value.as< std::vector<std::string> > ());
    }
#line 1831 "parser.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 345 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > () = {};
    }
#line 1839 "parser.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 350 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > ().push_back(yystack_[0].value.as< std::string > ());
        driver.ast_generator->add_argument(yystack_[0].value.as< std::string > ());
    }
#line 1848 "parser.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 355 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > () = std::move(yystack_[2].value.as< std::vector<std::string> > ());
        yylhs.value.as< std::vector<std::string> > ().push_back(yystack_[0].value.as< std::string > ());
        driver.ast_generator->add_argument(yystack_[0].value.as< std::string > ());
    }
#line 1858 "parser.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 362 "parser.yy" // lalr1.cc:859
    {
        is_global = NOT_GLOBAL;
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->no_value_node;
    }
#line 1867 "parser.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 368 "parser.yy" // lalr1.cc:859
    {
        is_global = GLOBAL;
    }
#line 1875 "parser.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 373 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1883 "parser.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 377 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[2].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1892 "parser.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 383 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->declare_C_function(yystack_[7].value.as< std::string > (),yystack_[4].value.as< std::vector<std::shared_ptr<Node>> > (),yystack_[1].value.as< std::shared_ptr<Node> > ());
    }
#line 1900 "parser.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 387 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->declare_C_function(yystack_[6].value.as< std::string > (),{},yystack_[1].value.as< std::shared_ptr<Node> > ());
    }
#line 1908 "parser.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 392 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1916 "parser.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 396 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[2].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1925 "parser.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 402 "parser.yy" // lalr1.cc:859
    {
        driver.ast_generator->into_namespace();
    }
#line 1933 "parser.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 407 "parser.yy" // lalr1.cc:859
    {
        driver.ast_generator->into_namespace();
    }
#line 1941 "parser.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 412 "parser.yy" // lalr1.cc:859
    {
        driver.ast_generator->into_namespace();
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(yystack_[4].value.as< std::shared_ptr<Node> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(yystack_[2].value.as< std::shared_ptr<Node> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1952 "parser.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 420 "parser.yy" // lalr1.cc:859
    {
        blawn_state = EXIST_IF;
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_if(yystack_[5].value.as< std::shared_ptr<Node> > (),yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
        driver.ast_generator->break_out_of_namespace();
    }
#line 1962 "parser.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 426 "parser.yy" // lalr1.cc:859
    {
        if (blawn_state != EXIST_IF)
        {
            std::cerr << "Error: else block without if block is valid." << std::endl;
            exit(1);
        }
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->add_else(yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
        blawn_state = NO_IF;
        driver.ast_generator->break_out_of_namespace();
    }
#line 1977 "parser.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 437 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_for(yystack_[5].value.as< std::vector<std::shared_ptr<Node>> > ()[0],yystack_[5].value.as< std::vector<std::shared_ptr<Node>> > ()[1],yystack_[5].value.as< std::vector<std::shared_ptr<Node>> > ()[2],yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
        driver.ast_generator->break_out_of_namespace();
    }
#line 1986 "parser.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 442 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = yystack_[0].value.as< std::shared_ptr<Node> > ();
    }
#line 1994 "parser.tab.cc" // lalr1.cc:859
    break;

  case 59:
#line 446 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_store(yystack_[2].value.as< std::shared_ptr<Node> > (),yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 2002 "parser.tab.cc" // lalr1.cc:859
    break;

  case 60:
#line 450 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"+");
    }
#line 2010 "parser.tab.cc" // lalr1.cc:859
    break;

  case 61:
#line 454 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"-");
    }
#line 2018 "parser.tab.cc" // lalr1.cc:859
    break;

  case 62:
#line 458 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"*");
    }
#line 2026 "parser.tab.cc" // lalr1.cc:859
    break;

  case 63:
#line 462 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"/");
    }
#line 2034 "parser.tab.cc" // lalr1.cc:859
    break;

  case 64:
#line 466 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"and");
    }
#line 2042 "parser.tab.cc" // lalr1.cc:859
    break;

  case 65:
#line 470 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"or");
    }
#line 2050 "parser.tab.cc" // lalr1.cc:859
    break;

  case 66:
#line 474 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),">=");
    }
#line 2058 "parser.tab.cc" // lalr1.cc:859
    break;

  case 67:
#line 478 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"<=");
    }
#line 2066 "parser.tab.cc" // lalr1.cc:859
    break;

  case 68:
#line 482 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),">");
    }
#line 2074 "parser.tab.cc" // lalr1.cc:859
    break;

  case 69:
#line 486 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"<");
    }
#line 2082 "parser.tab.cc" // lalr1.cc:859
    break;

  case 70:
#line 490 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"!=");
    }
#line 2090 "parser.tab.cc" // lalr1.cc:859
    break;

  case 71:
#line 494 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"==");
    }
#line 2098 "parser.tab.cc" // lalr1.cc:859
    break;

  case 72:
#line 498 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 2106 "parser.tab.cc" // lalr1.cc:859
    break;

  case 73:
#line 502 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 2114 "parser.tab.cc" // lalr1.cc:859
    break;

  case 74:
#line 506 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<AccessNode> > ());
    }
#line 2122 "parser.tab.cc" // lalr1.cc:859
    break;

  case 75:
#line 511 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_list(std::move(yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ()));
    }
#line 2130 "parser.tab.cc" // lalr1.cc:859
    break;

  case 76:
#line 515 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_list();
    }
#line 2138 "parser.tab.cc" // lalr1.cc:859
    break;

  case 77:
#line 520 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<AccessNode> > () = driver.ast_generator->create_access(yystack_[1].value.as< std::shared_ptr<Node> > (),yystack_[0].value.as< std::string > ());
    }
#line 2146 "parser.tab.cc" // lalr1.cc:859
    break;

  case 78:
#line 525 "parser.yy" // lalr1.cc:859
    {
        if (is_global == NOT_GLOBAL)
        {yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_assign(yystack_[2].value.as< std::string > (),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),false);}
        if (is_global == GLOBAL)
        {yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_assign(yystack_[2].value.as< std::string > (),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),true);}
    }
#line 2157 "parser.tab.cc" // lalr1.cc:859
    break;

  case 79:
#line 532 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_assign(yystack_[2].value.as< std::shared_ptr<AccessNode> > (),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 2165 "parser.tab.cc" // lalr1.cc:859
    break;

  case 80:
#line 537 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = yystack_[0].value.as< std::shared_ptr<Node> > ();
    }
#line 2173 "parser.tab.cc" // lalr1.cc:859
    break;

  case 81:
#line 541 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_string(yystack_[0].value.as< std::string > ());
    }
#line 2181 "parser.tab.cc" // lalr1.cc:859
    break;

  case 82:
#line 545 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_float(yystack_[0].value.as< double > ());
    }
#line 2189 "parser.tab.cc" // lalr1.cc:859
    break;

  case 83:
#line 549 "parser.yy" // lalr1.cc:859
    { 
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_integer(yystack_[0].value.as< long long > ());
    }
#line 2197 "parser.tab.cc" // lalr1.cc:859
    break;

  case 84:
#line 553 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 2205 "parser.tab.cc" // lalr1.cc:859
    break;

  case 85:
#line 558 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_call(yystack_[3].value.as< std::string > (),yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
    }
#line 2213 "parser.tab.cc" // lalr1.cc:859
    break;

  case 86:
#line 562 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_call(yystack_[2].value.as< std::string > (),{});
    }
#line 2221 "parser.tab.cc" // lalr1.cc:859
    break;

  case 87:
#line 566 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_call(yystack_[3].value.as< std::shared_ptr<AccessNode> > (),yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
    }
#line 2229 "parser.tab.cc" // lalr1.cc:859
    break;

  case 88:
#line 570 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_call(yystack_[2].value.as< std::shared_ptr<AccessNode> > (),{});
    }
#line 2237 "parser.tab.cc" // lalr1.cc:859
    break;

  case 89:
#line 575 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->get_named_value(yystack_[0].value.as< std::string > ());
    }
#line 2245 "parser.tab.cc" // lalr1.cc:859
    break;


#line 2249 "parser.tab.cc" // lalr1.cc:859
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


  const signed char Parser::yypact_ninf_ = -127;

  const signed char Parser::yytable_ninf_ = -48;

  const short int
  Parser::yypact_[] =
  {
       5,  -127,  -127,  -127,   -26,     2,    98,  -127,  -127,   139,
    -127,   -19,  -127,  -127,  -127,    21,  -127,     5,  -127,  -127,
      27,  -127,  -127,     1,  -127,     1,  -127,   -17,  -127,     0,
    -127,   139,    32,    37,   279,  -127,     3,  -127,  -127,  -127,
    -127,    -4,   139,   119,  -127,    -8,   279,   241,    42,  -127,
    -127,  -127,  -127,    -2,    43,    51,    41,    76,   179,    82,
      83,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,  -127,   139,   122,    -5,   279,  -127,
      66,   139,  -127,   139,  -127,  -127,  -127,    69,    79,    13,
     107,   110,    77,    93,    92,    95,   279,   210,   210,    80,
      80,    80,    80,    80,    80,    67,    67,   103,   103,   279,
    -127,    78,  -127,    94,   131,    49,  -127,   279,   261,   132,
    -127,   139,   136,   102,     1,   137,   159,   118,    14,   162,
     170,   139,   138,     5,     5,  -127,   162,  -127,   162,   140,
     139,  -127,   279,   174,  -127,   175,   139,   176,  -127,   171,
     159,    28,   162,   177,   279,   178,     5,   205,   206,   131,
     222,   131,   162,   279,  -127,     5,   193,  -127,   139,  -127,
      65,   142,   237,  -127,  -127,  -127,   224,   136,  -127,   227,
    -127,   226,   242,  -127,  -127,  -127,  -127,  -127
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,    19,    23,    25,     0,    89,     0,    52,    53,     0,
      45,     0,    81,    83,    82,     0,     2,     3,     4,     9,
       0,     8,    12,     0,    13,     0,    14,     0,    15,     0,
      16,     0,     0,     0,    11,    73,    74,    58,    72,    80,
      84,     0,     0,     0,    76,     0,    50,     0,     0,     1,
       5,     7,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,     0,     0,     0,    78,    86,
       0,     0,    75,     0,    10,    42,    41,     0,     0,     0,
       0,    24,     0,     0,     0,     0,    59,    64,    65,    71,
      70,    66,    67,    68,    69,    60,    61,    62,    63,    79,
      88,     0,    33,     0,    35,     0,    85,    51,     0,     0,
      40,    39,     0,     0,     0,     0,    22,     0,    21,     0,
       0,     0,     0,     0,     0,    87,     0,    34,     0,     0,
       0,    43,    38,     0,    18,     0,     0,     0,    26,     0,
      20,     0,     0,     0,     0,    58,     0,     0,     0,    37,
       0,    36,     0,    54,    17,     0,     0,    27,     0,    31,
       0,     0,     0,    56,    57,    49,     0,     0,    29,     0,
      32,     0,    58,    55,    48,    28,    30,    44
  };

  const short int
  Parser::yypgoto_[] =
  {
    -127,  -127,   -84,  -127,   272,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,   180,  -119,  -127,  -127,   -58,  -127,
     128,  -109,   -24,  -127,  -127,  -127,  -127,  -127,   -41,  -127,
    -127,  -127,    -6,  -127,  -127,  -126,  -127,  -127,  -127
  };

  const short int
  Parser::yydefgoto_[] =
  {
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   126,   127,   128,    91,   159,   115,
     160,   123,    54,    87,    28,    29,   153,    30,    45,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40
  };

  const short int
  Parser::yytable_[] =
  {
      46,    55,    80,    47,   122,   155,   112,   147,     1,    85,
       2,     3,     4,   143,    42,    75,     5,   124,   124,   114,
      41,    49,    81,   125,   149,    58,    82,    51,    48,    56,
      86,   147,    53,    43,    76,   111,    78,    46,     6,   137,
      77,   113,     7,     8,     9,   182,    57,    10,    11,   157,
     158,    90,    12,    13,    14,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   185,   109,
      46,   151,   172,    52,   169,   117,   137,   118,    59,   138,
     161,   177,     1,    60,     2,     3,     4,   121,    84,    88,
       5,    72,    73,    74,   170,   139,    81,    89,   116,   119,
     145,   120,    70,    71,    72,    73,    74,    92,    81,     5,
     135,   180,     6,    94,    95,   142,     7,     8,     9,   129,
     130,    10,    11,   131,   132,   154,    12,    13,    14,    74,
       5,     6,    44,     5,   163,     7,     8,     9,   133,   136,
     166,   134,   137,   141,   121,    12,    13,    14,   144,   146,
       5,    79,     6,     5,   110,     6,     7,     8,     9,     7,
       8,     9,   179,   124,   148,   154,    12,    13,    14,    12,
      13,    14,     6,   112,   181,     6,     7,     8,     9,     7,
       8,     9,   152,   168,   156,   162,    12,    13,    14,    12,
      13,    14,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
     164,   165,   167,   171,   -46,    93,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,   173,   174,   178,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,   175,   183,
     184,    83,   187,   186,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,   -47,    50,
     176,   140,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,     0,     0,   150
  };

  const short int
  Parser::yycheck_[] =
  {
       6,    25,    43,     9,    88,   131,    11,   126,     3,    11,
       5,     6,     7,   122,    12,    12,    11,     4,     4,    77,
      46,     0,    30,    10,    10,    31,    34,     0,    47,    46,
      32,   150,    31,    31,    31,    76,    42,    43,    33,    11,
      44,    46,    37,    38,    39,   171,    46,    42,    43,   133,
     134,    10,    47,    48,    49,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,   177,    75,
      76,   129,   156,    46,    46,    81,    11,    83,    46,    30,
     138,   165,     3,    46,     5,     6,     7,     8,    46,    46,
      11,    24,    25,    26,   152,    46,    30,    46,    32,    30,
     124,    32,    22,    23,    24,    25,    26,    31,    30,    11,
      32,    46,    33,    31,    31,   121,    37,    38,    39,    12,
      10,    42,    43,    46,    31,   131,    47,    48,    49,    26,
      11,    33,    34,    11,   140,    37,    38,    39,    46,    45,
     146,    46,    11,    11,     8,    47,    48,    49,    46,    12,
      11,    32,    33,    11,    32,    33,    37,    38,    39,    37,
      38,    39,   168,     4,    46,   171,    47,    48,    49,    47,
      48,    49,    33,    11,    32,    33,    37,    38,    39,    37,
      38,    39,    12,    12,    46,    45,    47,    48,    49,    47,
      48,    49,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      46,    46,    46,    46,    46,    46,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    32,    32,    46,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    46,    32,
      46,    30,    46,    46,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    46,    17,
     162,    30,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,   128
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     3,     5,     6,     7,    11,    33,    37,    38,    39,
      42,    43,    47,    48,    49,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    74,    75,
      77,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    46,    12,    31,    34,    78,    82,    82,    47,     0,
      54,     0,    46,    31,    72,    72,    46,    46,    82,    46,
      46,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    12,    31,    44,    82,    32,
      78,    30,    34,    30,    46,    11,    32,    73,    46,    46,
      10,    67,    31,    46,    31,    31,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      32,    78,    11,    46,    68,    69,    32,    82,    82,    30,
      32,     8,    52,    71,     4,    10,    64,    65,    66,    12,
      10,    46,    31,    46,    46,    32,    45,    11,    30,    46,
      30,    11,    82,    71,    46,    72,    12,    65,    46,    10,
      64,    68,    12,    76,    82,    85,    46,    52,    52,    68,
      70,    68,    45,    82,    46,    46,    82,    46,    12,    46,
      68,    46,    52,    32,    32,    46,    70,    52,    46,    82,
      46,    32,    85,    32,    46,    71,    46,    46
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    50,    51,    52,    53,    53,    54,    54,    54,    54,
      55,    56,    57,    57,    57,    57,    57,    58,    58,    59,
      60,    60,    60,    61,    62,    63,    64,    64,    65,    66,
      66,    67,    67,    68,    68,    69,    69,    70,    71,    71,
      72,    72,    73,    73,    74,    75,    76,    76,    77,    77,
      78,    78,    79,    80,    81,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    83,    83,    84,    85,    85,
      86,    86,    86,    86,    86,    87,    87,    87,    87,    88
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     2,     2,     2,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     6,     5,     1,
       5,     4,     4,     1,     3,     1,     2,     3,     5,     4,
       5,     4,     5,     1,     2,     1,     3,     1,     2,     1,
       3,     2,     1,     3,     8,     1,     1,     3,     8,     7,
       1,     3,     1,     1,     6,     7,     6,     6,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     3,     2,     2,     3,     3,
       1,     1,     1,     1,     1,     4,     3,     4,     3,     1
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
  "PLUS", "MINUS", "ASTERISK", "SLASH", "DOT_IDENTIFIER", "USE", "COLON",
  "SEMICOLON", "COMMA", "LEFT_PARENTHESIS", "RIGHT_PARENTHESIS",
  "LEFT_CURLY_BRACE", "RIGHT_CURLY_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET",
  "IF", "ELSE", "FOR", "IN", "WHILE", "GLOBAL", "IMPORT",
  "C_FUNCTION_ARGUMENT", "C_FUNCTION_RETURN", "EOL", "STRING_LITERAL",
  "INT_LITERAL", "FLOAT_LITERAL", "$accept", "program", "block", "lines",
  "line", "import", "line_content", "definition", "function_definition",
  "function_start", "class_definition", "class_start", "c_type_definition",
  "c_type_start", "methods", "method_definition", "members_definition",
  "C_members_definition", "C_type_identifier", "C_arguments", "C_returns",
  "return_value", "arguments", "definition_arguments",
  "globals_definition", "global_start", "globals_variables",
  "c_function_declaration", "expressions", "if_start", "else_start",
  "for_start", "expression", "list", "access", "assign_variable",
  "monomial", "call", "variable", YY_NULLPTR
  };


  const unsigned short int
  Parser::yyrline_[] =
  {
       0,   141,   141,   147,   153,   157,   163,   167,   171,   175,
     180,   182,   187,   191,   195,   199,   203,   208,   213,   219,
     225,   230,   235,   241,   247,   253,   259,   263,   269,   277,
     281,   287,   293,   301,   305,   311,   317,   325,   331,   335,
     340,   344,   349,   354,   361,   367,   372,   376,   382,   386,
     391,   395,   401,   406,   411,   419,   425,   436,   441,   445,
     449,   453,   457,   461,   465,   469,   473,   477,   481,   485,
     489,   493,   497,   501,   505,   510,   514,   519,   524,   531,
     536,   540,   544,   548,   552,   557,   561,   565,   569,   574
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
      45,    46,    47,    48,    49
    };
    const unsigned int user_token_number_max_ = 304;
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
#line 2736 "parser.tab.cc" // lalr1.cc:1167
#line 578 "parser.yy" // lalr1.cc:1168


void Blawn::Parser::error( const location_type &l, const std::string &err_message )
{
    std::cerr << "Error: " << err_message << " at " << l << "\n";
    exit(1);
} 
