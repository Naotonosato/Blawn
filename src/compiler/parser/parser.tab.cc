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

      case 85: // access
        value.copy< std::shared_ptr<AccessNode> > (other.value);
        break;

      case 66: // method_definition
        value.copy< std::shared_ptr<FunctionNode> > (other.value);
        break;

      case 54: // line
      case 56: // line_content
      case 57: // definition
      case 58: // function_definition
      case 60: // class_definition
      case 62: // c_type_definition
      case 71: // C_returns
      case 72: // return_value
      case 75: // globals_definition
      case 78: // c_function_declaration
      case 83: // expression
      case 84: // list
      case 86: // assign_variable
      case 87: // monomial
      case 88: // call
      case 89: // variable
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
      case 65: // method_start
        value.copy< std::string > (other.value);
        break;

      case 64: // methods
        value.copy< std::vector<std::shared_ptr<FunctionNode>> > (other.value);
        break;

      case 52: // block
      case 53: // lines
      case 67: // members_definition
      case 68: // C_members_definition
      case 70: // C_arguments
      case 77: // globals_variables
      case 79: // expressions
      case 82: // for_start
        value.copy< std::vector<std::shared_ptr<Node>> > (other.value);
        break;

      case 69: // C_type_identifier
      case 73: // arguments
      case 74: // definition_arguments
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

      case 85: // access
        value.copy< std::shared_ptr<AccessNode> > (v);
        break;

      case 66: // method_definition
        value.copy< std::shared_ptr<FunctionNode> > (v);
        break;

      case 54: // line
      case 56: // line_content
      case 57: // definition
      case 58: // function_definition
      case 60: // class_definition
      case 62: // c_type_definition
      case 71: // C_returns
      case 72: // return_value
      case 75: // globals_definition
      case 78: // c_function_declaration
      case 83: // expression
      case 84: // list
      case 86: // assign_variable
      case 87: // monomial
      case 88: // call
      case 89: // variable
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
      case 65: // method_start
        value.copy< std::string > (v);
        break;

      case 64: // methods
        value.copy< std::vector<std::shared_ptr<FunctionNode>> > (v);
        break;

      case 52: // block
      case 53: // lines
      case 67: // members_definition
      case 68: // C_members_definition
      case 70: // C_arguments
      case 77: // globals_variables
      case 79: // expressions
      case 82: // for_start
        value.copy< std::vector<std::shared_ptr<Node>> > (v);
        break;

      case 69: // C_type_identifier
      case 73: // arguments
      case 74: // definition_arguments
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

      case 85: // access
        value.template destroy< std::shared_ptr<AccessNode> > ();
        break;

      case 66: // method_definition
        value.template destroy< std::shared_ptr<FunctionNode> > ();
        break;

      case 54: // line
      case 56: // line_content
      case 57: // definition
      case 58: // function_definition
      case 60: // class_definition
      case 62: // c_type_definition
      case 71: // C_returns
      case 72: // return_value
      case 75: // globals_definition
      case 78: // c_function_declaration
      case 83: // expression
      case 84: // list
      case 86: // assign_variable
      case 87: // monomial
      case 88: // call
      case 89: // variable
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
      case 65: // method_start
        value.template destroy< std::string > ();
        break;

      case 64: // methods
        value.template destroy< std::vector<std::shared_ptr<FunctionNode>> > ();
        break;

      case 52: // block
      case 53: // lines
      case 67: // members_definition
      case 68: // C_members_definition
      case 70: // C_arguments
      case 77: // globals_variables
      case 79: // expressions
      case 82: // for_start
        value.template destroy< std::vector<std::shared_ptr<Node>> > ();
        break;

      case 69: // C_type_identifier
      case 73: // arguments
      case 74: // definition_arguments
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

      case 85: // access
        value.move< std::shared_ptr<AccessNode> > (s.value);
        break;

      case 66: // method_definition
        value.move< std::shared_ptr<FunctionNode> > (s.value);
        break;

      case 54: // line
      case 56: // line_content
      case 57: // definition
      case 58: // function_definition
      case 60: // class_definition
      case 62: // c_type_definition
      case 71: // C_returns
      case 72: // return_value
      case 75: // globals_definition
      case 78: // c_function_declaration
      case 83: // expression
      case 84: // list
      case 86: // assign_variable
      case 87: // monomial
      case 88: // call
      case 89: // variable
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
      case 65: // method_start
        value.move< std::string > (s.value);
        break;

      case 64: // methods
        value.move< std::vector<std::shared_ptr<FunctionNode>> > (s.value);
        break;

      case 52: // block
      case 53: // lines
      case 67: // members_definition
      case 68: // C_members_definition
      case 70: // C_arguments
      case 77: // globals_variables
      case 79: // expressions
      case 82: // for_start
        value.move< std::vector<std::shared_ptr<Node>> > (s.value);
        break;

      case 69: // C_type_identifier
      case 73: // arguments
      case 74: // definition_arguments
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

      case 85: // access
        value.move< std::shared_ptr<AccessNode> > (that.value);
        break;

      case 66: // method_definition
        value.move< std::shared_ptr<FunctionNode> > (that.value);
        break;

      case 54: // line
      case 56: // line_content
      case 57: // definition
      case 58: // function_definition
      case 60: // class_definition
      case 62: // c_type_definition
      case 71: // C_returns
      case 72: // return_value
      case 75: // globals_definition
      case 78: // c_function_declaration
      case 83: // expression
      case 84: // list
      case 86: // assign_variable
      case 87: // monomial
      case 88: // call
      case 89: // variable
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
      case 65: // method_start
        value.move< std::string > (that.value);
        break;

      case 64: // methods
        value.move< std::vector<std::shared_ptr<FunctionNode>> > (that.value);
        break;

      case 52: // block
      case 53: // lines
      case 67: // members_definition
      case 68: // C_members_definition
      case 70: // C_arguments
      case 77: // globals_variables
      case 79: // expressions
      case 82: // for_start
        value.move< std::vector<std::shared_ptr<Node>> > (that.value);
        break;

      case 69: // C_type_identifier
      case 73: // arguments
      case 74: // definition_arguments
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

      case 85: // access
        value.copy< std::shared_ptr<AccessNode> > (that.value);
        break;

      case 66: // method_definition
        value.copy< std::shared_ptr<FunctionNode> > (that.value);
        break;

      case 54: // line
      case 56: // line_content
      case 57: // definition
      case 58: // function_definition
      case 60: // class_definition
      case 62: // c_type_definition
      case 71: // C_returns
      case 72: // return_value
      case 75: // globals_definition
      case 78: // c_function_declaration
      case 83: // expression
      case 84: // list
      case 86: // assign_variable
      case 87: // monomial
      case 88: // call
      case 89: // variable
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
      case 65: // method_start
        value.copy< std::string > (that.value);
        break;

      case 64: // methods
        value.copy< std::vector<std::shared_ptr<FunctionNode>> > (that.value);
        break;

      case 52: // block
      case 53: // lines
      case 67: // members_definition
      case 68: // C_members_definition
      case 70: // C_arguments
      case 77: // globals_variables
      case 79: // expressions
      case 82: // for_start
        value.copy< std::vector<std::shared_ptr<Node>> > (that.value);
        break;

      case 69: // C_type_identifier
      case 73: // arguments
      case 74: // definition_arguments
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

      case 85: // access
        yylhs.value.build< std::shared_ptr<AccessNode> > ();
        break;

      case 66: // method_definition
        yylhs.value.build< std::shared_ptr<FunctionNode> > ();
        break;

      case 54: // line
      case 56: // line_content
      case 57: // definition
      case 58: // function_definition
      case 60: // class_definition
      case 62: // c_type_definition
      case 71: // C_returns
      case 72: // return_value
      case 75: // globals_definition
      case 78: // c_function_declaration
      case 83: // expression
      case 84: // list
      case 86: // assign_variable
      case 87: // monomial
      case 88: // call
      case 89: // variable
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
      case 65: // method_start
        yylhs.value.build< std::string > ();
        break;

      case 64: // methods
        yylhs.value.build< std::vector<std::shared_ptr<FunctionNode>> > ();
        break;

      case 52: // block
      case 53: // lines
      case 67: // members_definition
      case 68: // C_members_definition
      case 70: // C_arguments
      case 77: // globals_variables
      case 79: // expressions
      case 82: // for_start
        yylhs.value.build< std::vector<std::shared_ptr<Node>> > ();
        break;

      case 69: // C_type_identifier
      case 73: // arguments
      case 74: // definition_arguments
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
#line 143 "parser.yy" // lalr1.cc:859
    {
        driver.ast_generator->break_out_of_namespace();
        driver.ast_generator->generate(std::move(yystack_[0].value.as< std::vector<std::shared_ptr<Node>> > ()));
    }
#line 1514 "parser.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 149 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[0].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(driver.ast_generator->create_block_end());
    }
#line 1523 "parser.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 155 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1531 "parser.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 159 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1540 "parser.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 165 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[1].value.as< std::shared_ptr<Node> > ());
    }
#line 1548 "parser.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 169 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[1].value.as< std::shared_ptr<Node> > ());
    }
#line 1556 "parser.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 173 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = yystack_[0].value.as< std::shared_ptr<Node> > ();
    }
#line 1564 "parser.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 177 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->no_value_node;
    }
#line 1572 "parser.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 184 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1580 "parser.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 189 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1588 "parser.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 193 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1596 "parser.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 197 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1604 "parser.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 201 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1612 "parser.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 205 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1620 "parser.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 210 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->add_function(yystack_[5].value.as< std::string > (),std::move(yystack_[4].value.as< std::vector<std::string> > ()),std::move(yystack_[2].value.as< std::vector<std::shared_ptr<Node>> > ()),std::move(yystack_[1].value.as< std::shared_ptr<Node> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1629 "parser.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 215 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->add_function(yystack_[4].value.as< std::string > (),std::move(yystack_[3].value.as< std::vector<std::string> > ()),{},std::move(yystack_[1].value.as< std::shared_ptr<Node> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1638 "parser.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 221 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
        driver.ast_generator->into_namespace(yystack_[0].value.as< std::string > ());
    }
#line 1647 "parser.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 227 "parser.yy" // lalr1.cc:859
    { 
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(driver.ast_generator->create_class(yystack_[4].value.as< std::string > (),yystack_[3].value.as< std::vector<std::string> > (),yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > (),yystack_[0].value.as< std::vector<std::shared_ptr<FunctionNode>> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1656 "parser.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 232 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(driver.ast_generator->create_class(yystack_[3].value.as< std::string > (),yystack_[2].value.as< std::vector<std::string> > (),yystack_[0].value.as< std::vector<std::shared_ptr<Node>> > (),{}));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1665 "parser.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 237 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(driver.ast_generator->create_class(yystack_[3].value.as< std::string > (),yystack_[2].value.as< std::vector<std::string> > (),{},yystack_[0].value.as< std::vector<std::shared_ptr<FunctionNode>> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1674 "parser.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 243 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
        driver.ast_generator->into_namespace(yystack_[0].value.as< std::string > ());
    }
#line 1683 "parser.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 249 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(driver.ast_generator->create_C_type(yystack_[2].value.as< std::string > (),yystack_[0].value.as< std::vector<std::shared_ptr<Node>> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1692 "parser.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 255 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
        driver.ast_generator->into_namespace(yystack_[0].value.as< std::string > ());
    }
#line 1701 "parser.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 261 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<FunctionNode>> > ().push_back(yystack_[1].value.as< std::shared_ptr<FunctionNode> > ());
    }
#line 1709 "parser.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 265 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<FunctionNode>> > () = std::move(yystack_[2].value.as< std::vector<std::shared_ptr<FunctionNode>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<FunctionNode>> > ().push_back(yystack_[1].value.as< std::shared_ptr<FunctionNode> > ());
    }
#line 1718 "parser.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 271 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
        driver.ast_generator->into_namespace(yystack_[0].value.as< std::string > ());
    }
#line 1727 "parser.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 277 "parser.yy" // lalr1.cc:859
    {
        auto args = std::move(yystack_[3].value.as< std::vector<std::string> > ());
        args.insert(args.begin(),"self");
        yylhs.value.as< std::shared_ptr<FunctionNode> > () = driver.ast_generator->add_function(yystack_[4].value.as< std::string > (),std::move(args),std::move(yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1738 "parser.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 284 "parser.yy" // lalr1.cc:859
    {
        auto args = std::move(yystack_[2].value.as< std::vector<std::string> > ());
        args.insert(args.begin(),"self");
        yylhs.value.as< std::shared_ptr<FunctionNode> > () = driver.ast_generator->add_function(yystack_[3].value.as< std::string > (),std::move(args),{driver.ast_generator->create_block_end()},std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1749 "parser.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 292 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(driver.ast_generator->create_assign(yystack_[3].value.as< std::string > (),std::move(yystack_[1].value.as< std::shared_ptr<Node> > ()),false));
    }
#line 1757 "parser.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 296 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[4].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(driver.ast_generator->create_assign(yystack_[3].value.as< std::string > (),std::move(yystack_[1].value.as< std::shared_ptr<Node> > ()),false));
    }
#line 1766 "parser.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 302 "parser.yy" // lalr1.cc:859
    {
        std::string type_identifier = join(yystack_[1].value.as< std::vector<std::string> > ());
        auto assign_value = driver.ast_generator->create_C_member(type_identifier);
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(driver.ast_generator->create_assign(yystack_[3].value.as< std::string > (),std::move(assign_value),false));
    }
#line 1776 "parser.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 308 "parser.yy" // lalr1.cc:859
    {
        std::string type_identifier = join(yystack_[1].value.as< std::vector<std::string> > ());
        auto assign_value = driver.ast_generator->create_C_member(type_identifier);
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[4].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(driver.ast_generator->create_assign(yystack_[3].value.as< std::string > (),std::move(assign_value),false));
    }
#line 1787 "parser.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 316 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > ().push_back(yystack_[0].value.as< std::string > ());
    }
#line 1795 "parser.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 320 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > () = std::move(yystack_[1].value.as< std::vector<std::string> > ());
        yylhs.value.as< std::vector<std::string> > ().push_back(yystack_[0].value.as< std::string > ());
    }
#line 1804 "parser.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 326 "parser.yy" // lalr1.cc:859
    {
        std::string type_identifier = join(yystack_[0].value.as< std::vector<std::string> > ());
        auto assign_value = driver.ast_generator->create_C_member(type_identifier);
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(assign_value);
    }
#line 1814 "parser.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 332 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[2].value.as< std::vector<std::shared_ptr<Node>> > ());
        std::string type_identifier = join(yystack_[0].value.as< std::vector<std::string> > ());
        auto assign_value = driver.ast_generator->create_C_member(type_identifier);
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(assign_value);
    }
#line 1825 "parser.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 340 "parser.yy" // lalr1.cc:859
    {
        std::string type_identifier = join(yystack_[0].value.as< std::vector<std::string> > ());
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_C_member(type_identifier);
    }
#line 1834 "parser.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 346 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = yystack_[0].value.as< std::shared_ptr<Node> > ();
    }
#line 1842 "parser.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 350 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = nullptr;
    }
#line 1850 "parser.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 355 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > () = std::move(yystack_[1].value.as< std::vector<std::string> > ());
    }
#line 1858 "parser.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 359 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > () = {};
    }
#line 1866 "parser.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 364 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > ().push_back(yystack_[0].value.as< std::string > ());
        driver.ast_generator->add_argument(yystack_[0].value.as< std::string > ());
    }
#line 1875 "parser.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 369 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > () = std::move(yystack_[2].value.as< std::vector<std::string> > ());
        yylhs.value.as< std::vector<std::string> > ().push_back(yystack_[0].value.as< std::string > ());
        driver.ast_generator->add_argument(yystack_[0].value.as< std::string > ());
    }
#line 1885 "parser.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 376 "parser.yy" // lalr1.cc:859
    {
        is_global = NOT_GLOBAL;
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->no_value_node;
    }
#line 1894 "parser.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 382 "parser.yy" // lalr1.cc:859
    {
        is_global = GLOBAL;
    }
#line 1902 "parser.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 387 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1910 "parser.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 391 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[2].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1919 "parser.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 397 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->declare_C_function(yystack_[7].value.as< std::string > (),yystack_[4].value.as< std::vector<std::shared_ptr<Node>> > (),yystack_[1].value.as< std::shared_ptr<Node> > ());
    }
#line 1927 "parser.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 401 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->declare_C_function(yystack_[6].value.as< std::string > (),{},yystack_[1].value.as< std::shared_ptr<Node> > ());
    }
#line 1935 "parser.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 406 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1943 "parser.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 410 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[2].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1952 "parser.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 416 "parser.yy" // lalr1.cc:859
    {
        driver.ast_generator->into_namespace();
    }
#line 1960 "parser.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 421 "parser.yy" // lalr1.cc:859
    {
        driver.ast_generator->into_namespace();
    }
#line 1968 "parser.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 426 "parser.yy" // lalr1.cc:859
    {
        driver.ast_generator->into_namespace();
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(yystack_[4].value.as< std::shared_ptr<Node> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(yystack_[2].value.as< std::shared_ptr<Node> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1979 "parser.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 434 "parser.yy" // lalr1.cc:859
    {
        blawn_state = EXIST_IF;
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_if(yystack_[5].value.as< std::shared_ptr<Node> > (),yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
        driver.ast_generator->break_out_of_namespace();
    }
#line 1989 "parser.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 440 "parser.yy" // lalr1.cc:859
    {
        if (blawn_state != EXIST_IF)
        {
            std::cerr << "Error: else block without if block is invalid." << std::endl;
            exit(1);
        }
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->add_else(yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
        blawn_state = NO_IF;
        driver.ast_generator->break_out_of_namespace();
    }
#line 2004 "parser.tab.cc" // lalr1.cc:859
    break;

  case 59:
#line 451 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_for(yystack_[5].value.as< std::vector<std::shared_ptr<Node>> > ()[0],yystack_[5].value.as< std::vector<std::shared_ptr<Node>> > ()[1],yystack_[5].value.as< std::vector<std::shared_ptr<Node>> > ()[2],yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
        driver.ast_generator->break_out_of_namespace();
    }
#line 2013 "parser.tab.cc" // lalr1.cc:859
    break;

  case 60:
#line 456 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = yystack_[0].value.as< std::shared_ptr<Node> > ();
    }
#line 2021 "parser.tab.cc" // lalr1.cc:859
    break;

  case 61:
#line 460 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_store(yystack_[2].value.as< std::shared_ptr<Node> > (),yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 2029 "parser.tab.cc" // lalr1.cc:859
    break;

  case 62:
#line 464 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"+");
    }
#line 2037 "parser.tab.cc" // lalr1.cc:859
    break;

  case 63:
#line 468 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"-");
    }
#line 2045 "parser.tab.cc" // lalr1.cc:859
    break;

  case 64:
#line 472 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"*");
    }
#line 2053 "parser.tab.cc" // lalr1.cc:859
    break;

  case 65:
#line 476 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"/");
    }
#line 2061 "parser.tab.cc" // lalr1.cc:859
    break;

  case 66:
#line 480 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"and");
    }
#line 2069 "parser.tab.cc" // lalr1.cc:859
    break;

  case 67:
#line 484 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"or");
    }
#line 2077 "parser.tab.cc" // lalr1.cc:859
    break;

  case 68:
#line 488 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),">=");
    }
#line 2085 "parser.tab.cc" // lalr1.cc:859
    break;

  case 69:
#line 492 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"<=");
    }
#line 2093 "parser.tab.cc" // lalr1.cc:859
    break;

  case 70:
#line 496 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),">");
    }
#line 2101 "parser.tab.cc" // lalr1.cc:859
    break;

  case 71:
#line 500 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"<");
    }
#line 2109 "parser.tab.cc" // lalr1.cc:859
    break;

  case 72:
#line 504 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"!=");
    }
#line 2117 "parser.tab.cc" // lalr1.cc:859
    break;

  case 73:
#line 508 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"==");
    }
#line 2125 "parser.tab.cc" // lalr1.cc:859
    break;

  case 74:
#line 512 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 2133 "parser.tab.cc" // lalr1.cc:859
    break;

  case 75:
#line 516 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 2141 "parser.tab.cc" // lalr1.cc:859
    break;

  case 76:
#line 520 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<AccessNode> > ());
    }
#line 2149 "parser.tab.cc" // lalr1.cc:859
    break;

  case 77:
#line 525 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_list(std::move(yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ()));
    }
#line 2157 "parser.tab.cc" // lalr1.cc:859
    break;

  case 78:
#line 529 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_list();
    }
#line 2165 "parser.tab.cc" // lalr1.cc:859
    break;

  case 79:
#line 534 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<AccessNode> > () = driver.ast_generator->create_access(yystack_[1].value.as< std::shared_ptr<Node> > (),yystack_[0].value.as< std::string > ());
    }
#line 2173 "parser.tab.cc" // lalr1.cc:859
    break;

  case 80:
#line 539 "parser.yy" // lalr1.cc:859
    {
        if (is_global == NOT_GLOBAL)
        {yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_assign(yystack_[2].value.as< std::string > (),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),false);}
        if (is_global == GLOBAL)
        {yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_assign(yystack_[2].value.as< std::string > (),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),true);}
    }
#line 2184 "parser.tab.cc" // lalr1.cc:859
    break;

  case 81:
#line 546 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_assign(yystack_[2].value.as< std::shared_ptr<AccessNode> > (),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 2192 "parser.tab.cc" // lalr1.cc:859
    break;

  case 82:
#line 551 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = yystack_[0].value.as< std::shared_ptr<Node> > ();
    }
#line 2200 "parser.tab.cc" // lalr1.cc:859
    break;

  case 83:
#line 555 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_string(yystack_[0].value.as< std::string > ());
    }
#line 2208 "parser.tab.cc" // lalr1.cc:859
    break;

  case 84:
#line 559 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_float(yystack_[0].value.as< double > ());
    }
#line 2216 "parser.tab.cc" // lalr1.cc:859
    break;

  case 85:
#line 563 "parser.yy" // lalr1.cc:859
    { 
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_integer(yystack_[0].value.as< long long > ());
    }
#line 2224 "parser.tab.cc" // lalr1.cc:859
    break;

  case 86:
#line 567 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 2232 "parser.tab.cc" // lalr1.cc:859
    break;

  case 87:
#line 572 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_call(yystack_[3].value.as< std::string > (),yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
    }
#line 2240 "parser.tab.cc" // lalr1.cc:859
    break;

  case 88:
#line 576 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_call(yystack_[2].value.as< std::string > (),{});
    }
#line 2248 "parser.tab.cc" // lalr1.cc:859
    break;

  case 89:
#line 580 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_call(yystack_[3].value.as< std::shared_ptr<AccessNode> > (),yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
    }
#line 2256 "parser.tab.cc" // lalr1.cc:859
    break;

  case 90:
#line 584 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_call(yystack_[2].value.as< std::shared_ptr<AccessNode> > (),{});
    }
#line 2264 "parser.tab.cc" // lalr1.cc:859
    break;

  case 91:
#line 589 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->get_named_value(yystack_[0].value.as< std::string > ());
    }
#line 2272 "parser.tab.cc" // lalr1.cc:859
    break;


#line 2276 "parser.tab.cc" // lalr1.cc:859
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


  const signed char Parser::yypact_ninf_ = -128;

  const signed char Parser::yytable_ninf_ = -50;

  const short int
  Parser::yypact_[] =
  {
      99,  -128,  -128,  -128,   -33,    -4,    -5,  -128,  -128,   140,
    -128,   -26,  -128,  -128,  -128,    26,  -128,    99,  -128,  -128,
       4,  -128,  -128,   -17,  -128,   -17,  -128,    -8,  -128,    27,
    -128,   140,    30,    34,   280,  -128,     8,  -128,  -128,  -128,
    -128,    -3,   140,   120,  -128,    44,   280,   242,    38,  -128,
    -128,  -128,  -128,    -2,    43,    47,    84,    70,   180,    85,
      89,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,  -128,   140,   123,     0,   280,  -128,
      60,   140,  -128,   140,  -128,  -128,  -128,    77,    80,    13,
      96,   101,    75,    93,    79,    87,   280,   211,   211,    74,
      74,    74,    74,    74,    74,    28,    28,   104,   104,   280,
    -128,    82,  -128,    94,   132,   -15,  -128,   280,   262,   133,
    -128,   140,   137,   103,  -128,   138,   160,   -17,   119,    14,
     163,   171,   140,   139,    99,    99,  -128,   163,  -128,   163,
     141,   140,  -128,   280,   175,  -128,   140,   176,   177,  -128,
     172,   160,     1,   163,   178,   280,   179,    99,   206,   207,
     132,   223,   132,   163,   280,  -128,   194,  -128,    80,   140,
    -128,     5,   143,   238,  -128,  -128,  -128,   225,  -128,   137,
    -128,   228,  -128,   227,   243,  -128,  -128,  -128,  -128,  -128
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,    19,    23,    25,     0,    91,     0,    54,    55,     0,
      47,     0,    83,    85,    84,     0,     2,     3,     4,     9,
       0,     8,    12,     0,    13,     0,    14,     0,    15,     0,
      16,     0,     0,     0,    11,    75,    76,    60,    74,    82,
      86,     0,     0,     0,    78,     0,    52,     0,     0,     1,
       5,     7,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,     0,     0,     0,    80,    88,
       0,     0,    77,     0,    10,    44,    43,     0,     0,     0,
       0,    24,     0,     0,     0,     0,    61,    66,    67,    73,
      72,    68,    69,    70,    71,    62,    63,    64,    65,    81,
      90,     0,    35,     0,    37,     0,    87,    53,     0,     0,
      42,    41,     0,     0,    28,     0,    22,     0,     0,    21,
       0,     0,     0,     0,     0,     0,    89,     0,    36,     0,
       0,     0,    45,    40,     0,    18,     0,     0,     0,    26,
       0,    20,     0,     0,     0,     0,    60,     0,     0,     0,
      39,     0,    38,     0,    56,    17,     0,    27,     0,     0,
      33,     0,     0,     0,    58,    59,    51,     0,    31,     0,
      30,     0,    34,     0,    60,    57,    50,    29,    32,    46
  };

  const short int
  Parser::yypgoto_[] =
  {
    -128,  -128,   -86,  -128,   273,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,   162,  -128,  -116,  -128,  -128,   -58,
    -128,   144,  -100,   -24,  -128,  -128,  -128,  -128,  -128,   -36,
    -128,  -128,  -128,    -6,  -128,  -128,  -127,  -128,  -128,  -128
  };

  const short int
  Parser::yydefgoto_[] =
  {
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   126,   127,   128,   129,    91,   160,
     115,   161,   123,    54,    87,    28,    29,   154,    30,    45,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40
  };

  const short int
  Parser::yytable_[] =
  {
      46,    55,   122,    47,    51,   156,     5,    80,    42,    85,
     147,   112,   138,    41,    53,   139,   138,   124,   124,   114,
      75,    48,   144,   125,   150,    58,    49,    43,     6,    44,
      86,   140,     7,     8,     9,   147,    78,    46,    56,    76,
     111,    77,    12,    13,    14,   184,   113,   170,   158,   159,
      52,   182,    72,    73,    74,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   180,   109,
      46,   173,   152,    57,    81,   117,    59,   118,    82,   187,
      60,   162,   179,     1,    84,     2,     3,     4,   121,    88,
      81,     5,   116,    89,    90,   171,    70,    71,    72,    73,
      74,    92,     1,   148,     2,     3,     4,   119,   130,   120,
       5,   131,    81,     6,   136,   143,    94,     7,     8,     9,
      95,   132,    10,    11,   133,   134,   155,    12,    13,    14,
      74,     5,     6,   135,     5,   164,     7,     8,     9,   137,
     166,    10,    11,   138,   142,   121,    12,    13,    14,   145,
     146,     5,    79,     6,     5,   110,     6,     7,     8,     9,
       7,     8,     9,   181,   124,   149,   155,    12,    13,    14,
      12,    13,    14,     6,   112,   183,     6,     7,     8,     9,
       7,     8,     9,   153,   169,   157,   163,    12,    13,    14,
      12,    13,    14,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,   165,   167,   168,   172,   -48,    93,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,   174,   175,
     178,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,   176,
     185,   186,    83,   189,   188,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,   -49,
      50,   151,   141,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,   177
  };

  const unsigned char
  Parser::yycheck_[] =
  {
       6,    25,    88,     9,     0,   132,    11,    43,    12,    11,
     126,    11,    11,    46,    31,    30,    11,     4,     4,    77,
      12,    47,   122,    10,    10,    31,     0,    31,    33,    34,
      32,    46,    37,    38,    39,   151,    42,    43,    46,    31,
      76,    44,    47,    48,    49,   172,    46,    46,   134,   135,
      46,    46,    24,    25,    26,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,   168,    75,
      76,   157,   130,    46,    30,    81,    46,    83,    34,   179,
      46,   139,   168,     3,    46,     5,     6,     7,     8,    46,
      30,    11,    32,    46,    10,   153,    22,    23,    24,    25,
      26,    31,     3,   127,     5,     6,     7,    30,    12,    32,
      11,    10,    30,    33,    32,   121,    31,    37,    38,    39,
      31,    46,    42,    43,    31,    46,   132,    47,    48,    49,
      26,    11,    33,    46,    11,   141,    37,    38,    39,    45,
     146,    42,    43,    11,    11,     8,    47,    48,    49,    46,
      12,    11,    32,    33,    11,    32,    33,    37,    38,    39,
      37,    38,    39,   169,     4,    46,   172,    47,    48,    49,
      47,    48,    49,    33,    11,    32,    33,    37,    38,    39,
      37,    38,    39,    12,    12,    46,    45,    47,    48,    49,
      47,    48,    49,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    46,    46,    46,    46,    46,    46,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    32,    32,
      46,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    46,
      32,    46,    30,    46,    46,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    46,
      17,   129,    30,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   163
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     3,     5,     6,     7,    11,    33,    37,    38,    39,
      42,    43,    47,    48,    49,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    75,    76,
      78,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    46,    12,    31,    34,    79,    83,    83,    47,     0,
      54,     0,    46,    31,    73,    73,    46,    46,    83,    46,
      46,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    12,    31,    44,    83,    32,
      79,    30,    34,    30,    46,    11,    32,    74,    46,    46,
      10,    68,    31,    46,    31,    31,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      32,    79,    11,    46,    69,    70,    32,    83,    83,    30,
      32,     8,    52,    72,     4,    10,    64,    65,    66,    67,
      12,    10,    46,    31,    46,    46,    32,    45,    11,    30,
      46,    30,    11,    83,    72,    46,    12,    66,    73,    46,
      10,    64,    69,    12,    77,    83,    86,    46,    52,    52,
      69,    71,    69,    45,    83,    46,    83,    46,    46,    12,
      46,    69,    46,    52,    32,    32,    46,    71,    46,    52,
      72,    83,    46,    32,    86,    32,    46,    72,    46,    46
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    50,    51,    52,    53,    53,    54,    54,    54,    54,
      55,    56,    57,    57,    57,    57,    57,    58,    58,    59,
      60,    60,    60,    61,    62,    63,    64,    64,    65,    66,
      66,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      72,    72,    73,    73,    74,    74,    75,    76,    77,    77,
      78,    78,    79,    79,    80,    81,    82,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    84,    84,    85,
      86,    86,    87,    87,    87,    87,    87,    88,    88,    88,
      88,    89
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     2,     2,     2,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     6,     5,     1,
       5,     4,     4,     1,     3,     1,     2,     3,     1,     5,
       4,     4,     5,     4,     5,     1,     2,     1,     3,     1,
       2,     1,     3,     2,     1,     3,     8,     1,     1,     3,
       8,     7,     1,     3,     1,     1,     6,     7,     6,     6,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     3,     2,     2,
       3,     3,     1,     1,     1,     1,     1,     4,     3,     4,
       3,     1
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
  "c_type_start", "methods", "method_start", "method_definition",
  "members_definition", "C_members_definition", "C_type_identifier",
  "C_arguments", "C_returns", "return_value", "arguments",
  "definition_arguments", "globals_definition", "global_start",
  "globals_variables", "c_function_declaration", "expressions", "if_start",
  "else_start", "for_start", "expression", "list", "access",
  "assign_variable", "monomial", "call", "variable", YY_NULLPTR
  };


  const unsigned short int
  Parser::yyrline_[] =
  {
       0,   142,   142,   148,   154,   158,   164,   168,   172,   176,
     181,   183,   188,   192,   196,   200,   204,   209,   214,   220,
     226,   231,   236,   242,   248,   254,   260,   264,   270,   276,
     283,   291,   295,   301,   307,   315,   319,   325,   331,   339,
     345,   349,   354,   358,   363,   368,   375,   381,   386,   390,
     396,   400,   405,   409,   415,   420,   425,   433,   439,   450,
     455,   459,   463,   467,   471,   475,   479,   483,   487,   491,
     495,   499,   503,   507,   511,   515,   519,   524,   528,   533,
     538,   545,   550,   554,   558,   562,   566,   571,   575,   579,
     583,   588
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
#line 2766 "parser.tab.cc" // lalr1.cc:1167
#line 592 "parser.yy" // lalr1.cc:1168


void Blawn::Parser::error( const location_type &l, const std::string &err_message )
{
    std::cerr << "Error: " << err_message << " at " << l << "\n";
    exit(1);
} 
