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
      case 50: // FLOAT_LITERAL
        value.copy< double > (other.value);
        break;

      case 49: // INT_LITERAL
        value.copy< long long > (other.value);
        break;

      case 87: // access
        value.copy< std::shared_ptr<AccessNode> > (other.value);
        break;

      case 67: // method_definition
        value.copy< std::shared_ptr<FunctionNode> > (other.value);
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
      case 27: // DOT_IDENTIFIER
      case 48: // STRING_LITERAL
      case 60: // function_start
      case 62: // class_start
      case 64: // c_type_start
      case 66: // method_start
        value.copy< std::string > (other.value);
        break;

      case 65: // methods
        value.copy< std::vector<std::shared_ptr<FunctionNode>> > (other.value);
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
        value.copy< std::vector<std::shared_ptr<Node>> > (other.value);
        break;

      case 70: // C_type_identifier
      case 74: // arguments
      case 75: // definition_arguments
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
      case 50: // FLOAT_LITERAL
        value.copy< double > (v);
        break;

      case 49: // INT_LITERAL
        value.copy< long long > (v);
        break;

      case 87: // access
        value.copy< std::shared_ptr<AccessNode> > (v);
        break;

      case 67: // method_definition
        value.copy< std::shared_ptr<FunctionNode> > (v);
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
      case 27: // DOT_IDENTIFIER
      case 48: // STRING_LITERAL
      case 60: // function_start
      case 62: // class_start
      case 64: // c_type_start
      case 66: // method_start
        value.copy< std::string > (v);
        break;

      case 65: // methods
        value.copy< std::vector<std::shared_ptr<FunctionNode>> > (v);
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
        value.copy< std::vector<std::shared_ptr<Node>> > (v);
        break;

      case 70: // C_type_identifier
      case 74: // arguments
      case 75: // definition_arguments
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
      case 50: // FLOAT_LITERAL
        value.template destroy< double > ();
        break;

      case 49: // INT_LITERAL
        value.template destroy< long long > ();
        break;

      case 87: // access
        value.template destroy< std::shared_ptr<AccessNode> > ();
        break;

      case 67: // method_definition
        value.template destroy< std::shared_ptr<FunctionNode> > ();
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
      case 27: // DOT_IDENTIFIER
      case 48: // STRING_LITERAL
      case 60: // function_start
      case 62: // class_start
      case 64: // c_type_start
      case 66: // method_start
        value.template destroy< std::string > ();
        break;

      case 65: // methods
        value.template destroy< std::vector<std::shared_ptr<FunctionNode>> > ();
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
        value.template destroy< std::vector<std::shared_ptr<Node>> > ();
        break;

      case 70: // C_type_identifier
      case 74: // arguments
      case 75: // definition_arguments
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
      case 50: // FLOAT_LITERAL
        value.move< double > (s.value);
        break;

      case 49: // INT_LITERAL
        value.move< long long > (s.value);
        break;

      case 87: // access
        value.move< std::shared_ptr<AccessNode> > (s.value);
        break;

      case 67: // method_definition
        value.move< std::shared_ptr<FunctionNode> > (s.value);
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
      case 27: // DOT_IDENTIFIER
      case 48: // STRING_LITERAL
      case 60: // function_start
      case 62: // class_start
      case 64: // c_type_start
      case 66: // method_start
        value.move< std::string > (s.value);
        break;

      case 65: // methods
        value.move< std::vector<std::shared_ptr<FunctionNode>> > (s.value);
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
        value.move< std::vector<std::shared_ptr<Node>> > (s.value);
        break;

      case 70: // C_type_identifier
      case 74: // arguments
      case 75: // definition_arguments
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
  Parser::make_UMINUS (const location_type& l)
  {
    return symbol_type (token::UMINUS, l);
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
      case 50: // FLOAT_LITERAL
        value.move< double > (that.value);
        break;

      case 49: // INT_LITERAL
        value.move< long long > (that.value);
        break;

      case 87: // access
        value.move< std::shared_ptr<AccessNode> > (that.value);
        break;

      case 67: // method_definition
        value.move< std::shared_ptr<FunctionNode> > (that.value);
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
      case 27: // DOT_IDENTIFIER
      case 48: // STRING_LITERAL
      case 60: // function_start
      case 62: // class_start
      case 64: // c_type_start
      case 66: // method_start
        value.move< std::string > (that.value);
        break;

      case 65: // methods
        value.move< std::vector<std::shared_ptr<FunctionNode>> > (that.value);
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
        value.move< std::vector<std::shared_ptr<Node>> > (that.value);
        break;

      case 70: // C_type_identifier
      case 74: // arguments
      case 75: // definition_arguments
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
      case 50: // FLOAT_LITERAL
        value.copy< double > (that.value);
        break;

      case 49: // INT_LITERAL
        value.copy< long long > (that.value);
        break;

      case 87: // access
        value.copy< std::shared_ptr<AccessNode> > (that.value);
        break;

      case 67: // method_definition
        value.copy< std::shared_ptr<FunctionNode> > (that.value);
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
      case 27: // DOT_IDENTIFIER
      case 48: // STRING_LITERAL
      case 60: // function_start
      case 62: // class_start
      case 64: // c_type_start
      case 66: // method_start
        value.copy< std::string > (that.value);
        break;

      case 65: // methods
        value.copy< std::vector<std::shared_ptr<FunctionNode>> > (that.value);
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
        value.copy< std::vector<std::shared_ptr<Node>> > (that.value);
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
      case 50: // FLOAT_LITERAL
        yylhs.value.build< double > ();
        break;

      case 49: // INT_LITERAL
        yylhs.value.build< long long > ();
        break;

      case 87: // access
        yylhs.value.build< std::shared_ptr<AccessNode> > ();
        break;

      case 67: // method_definition
        yylhs.value.build< std::shared_ptr<FunctionNode> > ();
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
      case 27: // DOT_IDENTIFIER
      case 48: // STRING_LITERAL
      case 60: // function_start
      case 62: // class_start
      case 64: // c_type_start
      case 66: // method_start
        yylhs.value.build< std::string > ();
        break;

      case 65: // methods
        yylhs.value.build< std::vector<std::shared_ptr<FunctionNode>> > ();
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
        yylhs.value.build< std::vector<std::shared_ptr<Node>> > ();
        break;

      case 70: // C_type_identifier
      case 74: // arguments
      case 75: // definition_arguments
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
#line 145 "parser.yy" // lalr1.cc:859
    {
        driver.ast_generator->break_out_of_namespace();
        driver.ast_generator->generate(std::move(yystack_[0].value.as< std::vector<std::shared_ptr<Node>> > ()));
    }
#line 1527 "parser.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 151 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[0].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(driver.ast_generator->create_block_end());
    }
#line 1536 "parser.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 157 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1544 "parser.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 161 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1553 "parser.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 167 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[1].value.as< std::shared_ptr<Node> > ());
    }
#line 1561 "parser.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 171 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[1].value.as< std::shared_ptr<Node> > ());
    }
#line 1569 "parser.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 175 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = yystack_[0].value.as< std::shared_ptr<Node> > ();
    }
#line 1577 "parser.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 179 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->no_value_node;
    }
#line 1585 "parser.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 186 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1593 "parser.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 191 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1601 "parser.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 195 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1609 "parser.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 199 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1617 "parser.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 203 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1625 "parser.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 207 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1633 "parser.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 212 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->add_function(yystack_[5].value.as< std::string > (),std::move(yystack_[4].value.as< std::vector<std::string> > ()),std::move(yystack_[2].value.as< std::vector<std::shared_ptr<Node>> > ()),std::move(yystack_[1].value.as< std::shared_ptr<Node> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1642 "parser.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 217 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->add_function(yystack_[4].value.as< std::string > (),std::move(yystack_[3].value.as< std::vector<std::string> > ()),{},std::move(yystack_[1].value.as< std::shared_ptr<Node> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1651 "parser.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 223 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
        driver.ast_generator->into_namespace(yystack_[0].value.as< std::string > ());
    }
#line 1660 "parser.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 229 "parser.yy" // lalr1.cc:859
    { 
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(driver.ast_generator->create_class(yystack_[4].value.as< std::string > (),yystack_[3].value.as< std::vector<std::string> > (),yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > (),yystack_[0].value.as< std::vector<std::shared_ptr<FunctionNode>> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1669 "parser.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 234 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(driver.ast_generator->create_class(yystack_[3].value.as< std::string > (),yystack_[2].value.as< std::vector<std::string> > (),yystack_[0].value.as< std::vector<std::shared_ptr<Node>> > (),{}));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1678 "parser.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 239 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(driver.ast_generator->create_class(yystack_[3].value.as< std::string > (),yystack_[2].value.as< std::vector<std::string> > (),{},yystack_[0].value.as< std::vector<std::shared_ptr<FunctionNode>> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1687 "parser.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 245 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
        driver.ast_generator->into_namespace(yystack_[0].value.as< std::string > ());
    }
#line 1696 "parser.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 251 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(driver.ast_generator->create_C_type(yystack_[2].value.as< std::string > (),yystack_[0].value.as< std::vector<std::shared_ptr<Node>> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1705 "parser.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 257 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
        driver.ast_generator->into_namespace(yystack_[0].value.as< std::string > ());
    }
#line 1714 "parser.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 263 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<FunctionNode>> > ().push_back(yystack_[1].value.as< std::shared_ptr<FunctionNode> > ());
    }
#line 1722 "parser.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 267 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<FunctionNode>> > () = std::move(yystack_[2].value.as< std::vector<std::shared_ptr<FunctionNode>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<FunctionNode>> > ().push_back(yystack_[1].value.as< std::shared_ptr<FunctionNode> > ());
    }
#line 1731 "parser.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 273 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
        driver.ast_generator->into_namespace(yystack_[0].value.as< std::string > ());
    }
#line 1740 "parser.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 279 "parser.yy" // lalr1.cc:859
    {
        auto args = std::move(yystack_[3].value.as< std::vector<std::string> > ());
        args.insert(args.begin(),"self");
        yylhs.value.as< std::shared_ptr<FunctionNode> > () = driver.ast_generator->add_function(yystack_[4].value.as< std::string > (),std::move(args),std::move(yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1751 "parser.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 286 "parser.yy" // lalr1.cc:859
    {
        auto args = std::move(yystack_[2].value.as< std::vector<std::string> > ());
        args.insert(args.begin(),"self");
        yylhs.value.as< std::shared_ptr<FunctionNode> > () = driver.ast_generator->add_function(yystack_[3].value.as< std::string > (),std::move(args),{driver.ast_generator->create_block_end()},std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1762 "parser.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 294 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(driver.ast_generator->create_assign(yystack_[3].value.as< std::string > (),std::move(yystack_[1].value.as< std::shared_ptr<Node> > ()),false));
    }
#line 1770 "parser.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 298 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[4].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(driver.ast_generator->create_assign(yystack_[3].value.as< std::string > (),std::move(yystack_[1].value.as< std::shared_ptr<Node> > ()),false));
    }
#line 1779 "parser.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 304 "parser.yy" // lalr1.cc:859
    {
        std::string type_identifier = join(yystack_[1].value.as< std::vector<std::string> > ());
        auto assign_value = driver.ast_generator->create_C_member(type_identifier);
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(driver.ast_generator->create_assign(yystack_[3].value.as< std::string > (),std::move(assign_value),false));
    }
#line 1789 "parser.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 310 "parser.yy" // lalr1.cc:859
    {
        std::string type_identifier = join(yystack_[1].value.as< std::vector<std::string> > ());
        auto assign_value = driver.ast_generator->create_C_member(type_identifier);
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[4].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(driver.ast_generator->create_assign(yystack_[3].value.as< std::string > (),std::move(assign_value),false));
    }
#line 1800 "parser.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 318 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > ().push_back(yystack_[0].value.as< std::string > ());
    }
#line 1808 "parser.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 322 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > () = std::move(yystack_[1].value.as< std::vector<std::string> > ());
        yylhs.value.as< std::vector<std::string> > ().push_back(yystack_[0].value.as< std::string > ());
    }
#line 1817 "parser.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 328 "parser.yy" // lalr1.cc:859
    {
        std::string type_identifier = join(yystack_[0].value.as< std::vector<std::string> > ());
        auto assign_value = driver.ast_generator->create_C_member(type_identifier);
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(assign_value);
    }
#line 1827 "parser.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 334 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[2].value.as< std::vector<std::shared_ptr<Node>> > ());
        std::string type_identifier = join(yystack_[0].value.as< std::vector<std::string> > ());
        auto assign_value = driver.ast_generator->create_C_member(type_identifier);
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(assign_value);
    }
#line 1838 "parser.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 342 "parser.yy" // lalr1.cc:859
    {
        std::string type_identifier = join(yystack_[0].value.as< std::vector<std::string> > ());
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_C_member(type_identifier);
    }
#line 1847 "parser.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 348 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = yystack_[0].value.as< std::shared_ptr<Node> > ();
    }
#line 1855 "parser.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 352 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = nullptr;
    }
#line 1863 "parser.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 357 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > () = std::move(yystack_[1].value.as< std::vector<std::string> > ());
    }
#line 1871 "parser.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 361 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > () = {};
    }
#line 1879 "parser.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 366 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > ().push_back(yystack_[0].value.as< std::string > ());
        driver.ast_generator->add_argument(yystack_[0].value.as< std::string > ());
    }
#line 1888 "parser.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 371 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > () = std::move(yystack_[2].value.as< std::vector<std::string> > ());
        yylhs.value.as< std::vector<std::string> > ().push_back(yystack_[0].value.as< std::string > ());
        driver.ast_generator->add_argument(yystack_[0].value.as< std::string > ());
    }
#line 1898 "parser.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 378 "parser.yy" // lalr1.cc:859
    {
        is_global = NOT_GLOBAL;
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->no_value_node;
    }
#line 1907 "parser.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 384 "parser.yy" // lalr1.cc:859
    {
        is_global = GLOBAL;
    }
#line 1915 "parser.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 389 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1923 "parser.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 393 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[2].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1932 "parser.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 399 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->declare_C_function(yystack_[7].value.as< std::string > (),yystack_[4].value.as< std::vector<std::shared_ptr<Node>> > (),yystack_[1].value.as< std::shared_ptr<Node> > ());
    }
#line 1940 "parser.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 403 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->declare_C_function(yystack_[6].value.as< std::string > (),{},yystack_[1].value.as< std::shared_ptr<Node> > ());
    }
#line 1948 "parser.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 408 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1956 "parser.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 412 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[2].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1965 "parser.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 418 "parser.yy" // lalr1.cc:859
    {
        driver.ast_generator->into_namespace();
    }
#line 1973 "parser.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 423 "parser.yy" // lalr1.cc:859
    {
        driver.ast_generator->into_namespace();
    }
#line 1981 "parser.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 428 "parser.yy" // lalr1.cc:859
    {
        driver.ast_generator->into_namespace();
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(yystack_[4].value.as< std::shared_ptr<Node> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(yystack_[2].value.as< std::shared_ptr<Node> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1992 "parser.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 437 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ();
    }
#line 2000 "parser.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 442 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_if(yystack_[5].value.as< std::shared_ptr<Node> > (),yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > (),{});
        driver.ast_generator->break_out_of_namespace();
    }
#line 2009 "parser.tab.cc" // lalr1.cc:859
    break;

  case 59:
#line 447 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_if(yystack_[6].value.as< std::shared_ptr<Node> > (),yystack_[2].value.as< std::vector<std::shared_ptr<Node>> > (),yystack_[0].value.as< std::vector<std::shared_ptr<Node>> > ());
        driver.ast_generator->break_out_of_namespace();
    }
#line 2018 "parser.tab.cc" // lalr1.cc:859
    break;

  case 60:
#line 452 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_for(yystack_[5].value.as< std::vector<std::shared_ptr<Node>> > ()[0],yystack_[5].value.as< std::vector<std::shared_ptr<Node>> > ()[1],yystack_[5].value.as< std::vector<std::shared_ptr<Node>> > ()[2],yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
        driver.ast_generator->break_out_of_namespace();
    }
#line 2027 "parser.tab.cc" // lalr1.cc:859
    break;

  case 61:
#line 457 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = yystack_[0].value.as< std::shared_ptr<Node> > ();
    }
#line 2035 "parser.tab.cc" // lalr1.cc:859
    break;

  case 62:
#line 461 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_store(yystack_[2].value.as< std::shared_ptr<Node> > (),yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 2043 "parser.tab.cc" // lalr1.cc:859
    break;

  case 63:
#line 465 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"+");
    }
#line 2051 "parser.tab.cc" // lalr1.cc:859
    break;

  case 64:
#line 469 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"-");
    }
#line 2059 "parser.tab.cc" // lalr1.cc:859
    break;

  case 65:
#line 473 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"*");
    }
#line 2067 "parser.tab.cc" // lalr1.cc:859
    break;

  case 66:
#line 477 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"/");
    }
#line 2075 "parser.tab.cc" // lalr1.cc:859
    break;

  case 67:
#line 481 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"and");
    }
#line 2083 "parser.tab.cc" // lalr1.cc:859
    break;

  case 68:
#line 485 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"or");
    }
#line 2091 "parser.tab.cc" // lalr1.cc:859
    break;

  case 69:
#line 489 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),">=");
    }
#line 2099 "parser.tab.cc" // lalr1.cc:859
    break;

  case 70:
#line 493 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"<=");
    }
#line 2107 "parser.tab.cc" // lalr1.cc:859
    break;

  case 71:
#line 497 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),">");
    }
#line 2115 "parser.tab.cc" // lalr1.cc:859
    break;

  case 72:
#line 501 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"<");
    }
#line 2123 "parser.tab.cc" // lalr1.cc:859
    break;

  case 73:
#line 505 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"!=");
    }
#line 2131 "parser.tab.cc" // lalr1.cc:859
    break;

  case 74:
#line 509 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"==");
    }
#line 2139 "parser.tab.cc" // lalr1.cc:859
    break;

  case 75:
#line 513 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 2147 "parser.tab.cc" // lalr1.cc:859
    break;

  case 76:
#line 517 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 2155 "parser.tab.cc" // lalr1.cc:859
    break;

  case 77:
#line 521 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<AccessNode> > ());
    }
#line 2163 "parser.tab.cc" // lalr1.cc:859
    break;

  case 78:
#line 525 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_minus(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 2171 "parser.tab.cc" // lalr1.cc:859
    break;

  case 79:
#line 529 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[1].value.as< std::shared_ptr<Node> > ());
    }
#line 2179 "parser.tab.cc" // lalr1.cc:859
    break;

  case 80:
#line 534 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_list(std::move(yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ()));
    }
#line 2187 "parser.tab.cc" // lalr1.cc:859
    break;

  case 81:
#line 538 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_list();
    }
#line 2195 "parser.tab.cc" // lalr1.cc:859
    break;

  case 82:
#line 543 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<AccessNode> > () = driver.ast_generator->create_access(yystack_[1].value.as< std::shared_ptr<Node> > (),yystack_[0].value.as< std::string > ());
    }
#line 2203 "parser.tab.cc" // lalr1.cc:859
    break;

  case 83:
#line 548 "parser.yy" // lalr1.cc:859
    {
        if (is_global == NOT_GLOBAL)
        {yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_assign(yystack_[2].value.as< std::string > (),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),false);}
        if (is_global == GLOBAL)
        {yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_assign(yystack_[2].value.as< std::string > (),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),true);}
    }
#line 2214 "parser.tab.cc" // lalr1.cc:859
    break;

  case 84:
#line 555 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_assign(yystack_[2].value.as< std::shared_ptr<AccessNode> > (),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 2222 "parser.tab.cc" // lalr1.cc:859
    break;

  case 85:
#line 560 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = yystack_[0].value.as< std::shared_ptr<Node> > ();
    }
#line 2230 "parser.tab.cc" // lalr1.cc:859
    break;

  case 86:
#line 564 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_string(yystack_[0].value.as< std::string > ());
    }
#line 2238 "parser.tab.cc" // lalr1.cc:859
    break;

  case 87:
#line 568 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_float(yystack_[0].value.as< double > ());
    }
#line 2246 "parser.tab.cc" // lalr1.cc:859
    break;

  case 88:
#line 572 "parser.yy" // lalr1.cc:859
    { 
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_integer(yystack_[0].value.as< long long > ());
    }
#line 2254 "parser.tab.cc" // lalr1.cc:859
    break;

  case 89:
#line 576 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 2262 "parser.tab.cc" // lalr1.cc:859
    break;

  case 90:
#line 581 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_call(yystack_[3].value.as< std::string > (),yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
    }
#line 2270 "parser.tab.cc" // lalr1.cc:859
    break;

  case 91:
#line 585 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_call(yystack_[2].value.as< std::string > (),{});
    }
#line 2278 "parser.tab.cc" // lalr1.cc:859
    break;

  case 92:
#line 589 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_call(yystack_[3].value.as< std::shared_ptr<AccessNode> > (),yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
    }
#line 2286 "parser.tab.cc" // lalr1.cc:859
    break;

  case 93:
#line 593 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_call(yystack_[2].value.as< std::shared_ptr<AccessNode> > (),{});
    }
#line 2294 "parser.tab.cc" // lalr1.cc:859
    break;

  case 94:
#line 598 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->get_named_value(yystack_[0].value.as< std::string > ());
    }
#line 2302 "parser.tab.cc" // lalr1.cc:859
    break;


#line 2306 "parser.tab.cc" // lalr1.cc:859
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

  const signed char Parser::yytable_ninf_ = -50;

  const short int
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

  const unsigned char
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

  const short int
  Parser::yypgoto_[] =
  {
    -127,  -127,   -85,  -127,   138,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,    34,  -127,  -113,  -127,  -127,   -58,
    -127,     5,   -93,   -23,  -127,  -127,  -127,  -127,  -127,   -34,
    -127,  -127,  -127,  -127,    -6,  -127,  -127,  -126,  -127,  -127,
    -127
  };

  const short int
  Parser::yydefgoto_[] =
  {
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,   127,   128,   129,   130,    93,   159,
     116,   160,   124,    56,    89,    29,    30,   154,    31,    47,
      32,   189,    33,   190,    34,    35,    36,    37,    38,    39,
      40
  };

  const short int
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

  const short int
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

  const unsigned char
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

  const unsigned char
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

  const unsigned char
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


  const unsigned short int
  Parser::yyrline_[] =
  {
       0,   144,   144,   150,   156,   160,   166,   170,   174,   178,
     183,   185,   190,   194,   198,   202,   206,   211,   216,   222,
     228,   233,   238,   244,   250,   256,   262,   266,   272,   278,
     285,   293,   297,   303,   309,   317,   321,   327,   333,   341,
     347,   351,   356,   360,   365,   370,   377,   383,   388,   392,
     398,   402,   407,   411,   417,   422,   427,   436,   441,   446,
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
      45,    46,    47,    48,    49,    50
    };
    const unsigned int user_token_number_max_ = 305;
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
#line 2815 "parser.tab.cc" // lalr1.cc:1167
#line 601 "parser.yy" // lalr1.cc:1168


void Blawn::Parser::error( const location_type &l, const std::string &err_message )
{
    std::cerr << "Error: " << err_message << " at " << l << "\n";
    exit(1);
} 
