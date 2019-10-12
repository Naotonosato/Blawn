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
      case 46: // FLOAT_LITERAL
        value.copy< double > (other.value);
        break;

      case 45: // INT_LITERAL
        value.copy< long long > (other.value);
        break;

      case 80: // access
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
      case 67: // C_returns
      case 68: // return_value
      case 71: // globals_definition
      case 74: // c_function_declaration
      case 78: // expression
      case 79: // list
      case 81: // assign_variable
      case 82: // monomial
      case 83: // call
      case 84: // variable
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
      case 64: // C_members_definition
      case 66: // C_arguments
      case 73: // globals_variables
      case 75: // expressions
        value.copy< std::vector<std::shared_ptr<Node>> > (other.value);
        break;

      case 65: // C_type_identifier
      case 69: // arguments
      case 70: // definition_arguments
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

      case 80: // access
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
      case 67: // C_returns
      case 68: // return_value
      case 71: // globals_definition
      case 74: // c_function_declaration
      case 78: // expression
      case 79: // list
      case 81: // assign_variable
      case 82: // monomial
      case 83: // call
      case 84: // variable
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
      case 64: // C_members_definition
      case 66: // C_arguments
      case 73: // globals_variables
      case 75: // expressions
        value.copy< std::vector<std::shared_ptr<Node>> > (v);
        break;

      case 65: // C_type_identifier
      case 69: // arguments
      case 70: // definition_arguments
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

      case 80: // access
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
      case 67: // C_returns
      case 68: // return_value
      case 71: // globals_definition
      case 74: // c_function_declaration
      case 78: // expression
      case 79: // list
      case 81: // assign_variable
      case 82: // monomial
      case 83: // call
      case 84: // variable
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
      case 64: // C_members_definition
      case 66: // C_arguments
      case 73: // globals_variables
      case 75: // expressions
        value.template destroy< std::vector<std::shared_ptr<Node>> > ();
        break;

      case 65: // C_type_identifier
      case 69: // arguments
      case 70: // definition_arguments
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

      case 80: // access
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
      case 67: // C_returns
      case 68: // return_value
      case 71: // globals_definition
      case 74: // c_function_declaration
      case 78: // expression
      case 79: // list
      case 81: // assign_variable
      case 82: // monomial
      case 83: // call
      case 84: // variable
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
      case 64: // C_members_definition
      case 66: // C_arguments
      case 73: // globals_variables
      case 75: // expressions
        value.move< std::vector<std::shared_ptr<Node>> > (s.value);
        break;

      case 65: // C_type_identifier
      case 69: // arguments
      case 70: // definition_arguments
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

      case 80: // access
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
      case 67: // C_returns
      case 68: // return_value
      case 71: // globals_definition
      case 74: // c_function_declaration
      case 78: // expression
      case 79: // list
      case 81: // assign_variable
      case 82: // monomial
      case 83: // call
      case 84: // variable
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
      case 64: // C_members_definition
      case 66: // C_arguments
      case 73: // globals_variables
      case 75: // expressions
        value.move< std::vector<std::shared_ptr<Node>> > (that.value);
        break;

      case 65: // C_type_identifier
      case 69: // arguments
      case 70: // definition_arguments
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

      case 80: // access
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
      case 67: // C_returns
      case 68: // return_value
      case 71: // globals_definition
      case 74: // c_function_declaration
      case 78: // expression
      case 79: // list
      case 81: // assign_variable
      case 82: // monomial
      case 83: // call
      case 84: // variable
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
      case 64: // C_members_definition
      case 66: // C_arguments
      case 73: // globals_variables
      case 75: // expressions
        value.copy< std::vector<std::shared_ptr<Node>> > (that.value);
        break;

      case 65: // C_type_identifier
      case 69: // arguments
      case 70: // definition_arguments
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

      case 80: // access
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
      case 67: // C_returns
      case 68: // return_value
      case 71: // globals_definition
      case 74: // c_function_declaration
      case 78: // expression
      case 79: // list
      case 81: // assign_variable
      case 82: // monomial
      case 83: // call
      case 84: // variable
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
      case 64: // C_members_definition
      case 66: // C_arguments
      case 73: // globals_variables
      case 75: // expressions
        yylhs.value.build< std::vector<std::shared_ptr<Node>> > ();
        break;

      case 65: // C_type_identifier
      case 69: // arguments
      case 70: // definition_arguments
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
#line 141 "parser.yy" // lalr1.cc:859
    {
        driver.ast_generator->break_out_of_namespace();
        driver.ast_generator->generate(std::move(yystack_[0].value.as< std::vector<std::shared_ptr<Node>> > ()));
    }
#line 1488 "parser.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 147 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[0].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(driver.ast_generator->create_block_end());
    }
#line 1497 "parser.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 153 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1505 "parser.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 157 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1514 "parser.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 163 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[1].value.as< std::shared_ptr<Node> > ());
    }
#line 1522 "parser.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 167 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[1].value.as< std::shared_ptr<Node> > ());
    }
#line 1530 "parser.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 171 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = yystack_[0].value.as< std::shared_ptr<Node> > ();
    }
#line 1538 "parser.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 176 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1546 "parser.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 181 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1554 "parser.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 185 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1562 "parser.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 189 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1570 "parser.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 193 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1578 "parser.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 197 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 1586 "parser.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 202 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->add_function(yystack_[5].value.as< std::string > (),std::move(yystack_[4].value.as< std::vector<std::string> > ()),std::move(yystack_[2].value.as< std::vector<std::shared_ptr<Node>> > ()),std::move(yystack_[1].value.as< std::shared_ptr<Node> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1595 "parser.tab.cc" // lalr1.cc:859
    break;

  case 16:
#line 208 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
        driver.ast_generator->into_namespace(yystack_[0].value.as< std::string > ());
    }
#line 1604 "parser.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 214 "parser.yy" // lalr1.cc:859
    { 
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(driver.ast_generator->create_class(yystack_[4].value.as< std::string > (),yystack_[3].value.as< std::vector<std::string> > (),yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > (),yystack_[0].value.as< std::vector<std::shared_ptr<FunctionNode>> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1613 "parser.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 219 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(driver.ast_generator->create_class(yystack_[3].value.as< std::string > (),yystack_[2].value.as< std::vector<std::string> > (),yystack_[0].value.as< std::vector<std::shared_ptr<Node>> > (),{}));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1622 "parser.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 224 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(driver.ast_generator->create_class(yystack_[3].value.as< std::string > (),yystack_[2].value.as< std::vector<std::string> > (),{},yystack_[0].value.as< std::vector<std::shared_ptr<FunctionNode>> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1631 "parser.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 230 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
        driver.ast_generator->into_namespace(yystack_[0].value.as< std::string > ());
    }
#line 1640 "parser.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 236 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(driver.ast_generator->create_C_type(yystack_[2].value.as< std::string > (),yystack_[0].value.as< std::vector<std::shared_ptr<Node>> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1649 "parser.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 242 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
        driver.ast_generator->into_namespace(yystack_[0].value.as< std::string > ());
    }
#line 1658 "parser.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 248 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<FunctionNode>> > ().push_back(yystack_[1].value.as< std::shared_ptr<FunctionNode> > ());
    }
#line 1666 "parser.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 252 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<FunctionNode>> > () = std::move(yystack_[2].value.as< std::vector<std::shared_ptr<FunctionNode>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<FunctionNode>> > ().push_back(yystack_[1].value.as< std::shared_ptr<FunctionNode> > ());
    }
#line 1675 "parser.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 258 "parser.yy" // lalr1.cc:859
    {
        auto args = std::move(yystack_[3].value.as< std::vector<std::string> > ());
        args.insert(args.begin(),"self");
        yylhs.value.as< std::shared_ptr<FunctionNode> > () = driver.ast_generator->add_function(yystack_[4].value.as< std::string > (),std::move(args),std::move(yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1686 "parser.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 266 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(driver.ast_generator->assign(yystack_[3].value.as< std::string > (),std::move(yystack_[1].value.as< std::shared_ptr<Node> > ()),false));
    }
#line 1694 "parser.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 270 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[4].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(driver.ast_generator->assign(yystack_[3].value.as< std::string > (),std::move(yystack_[1].value.as< std::shared_ptr<Node> > ()),false));
    }
#line 1703 "parser.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 276 "parser.yy" // lalr1.cc:859
    {
        std::string type_identifier = join(yystack_[1].value.as< std::vector<std::string> > ());
        auto assign_value = driver.ast_generator->create_C_member(type_identifier);
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(driver.ast_generator->assign(yystack_[3].value.as< std::string > (),std::move(assign_value),false));
    }
#line 1713 "parser.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 282 "parser.yy" // lalr1.cc:859
    {
        std::string type_identifier = join(yystack_[1].value.as< std::vector<std::string> > ());
        auto assign_value = driver.ast_generator->create_C_member(type_identifier);
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[4].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(driver.ast_generator->assign(yystack_[3].value.as< std::string > (),std::move(assign_value),false));
    }
#line 1724 "parser.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 290 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > ().push_back(yystack_[0].value.as< std::string > ());
    }
#line 1732 "parser.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 294 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > () = std::move(yystack_[1].value.as< std::vector<std::string> > ());
        yylhs.value.as< std::vector<std::string> > ().push_back(yystack_[0].value.as< std::string > ());
    }
#line 1741 "parser.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 300 "parser.yy" // lalr1.cc:859
    {
        std::string type_identifier = join(yystack_[0].value.as< std::vector<std::string> > ());
        auto assign_value = driver.ast_generator->create_C_member(type_identifier);
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(assign_value);
    }
#line 1751 "parser.tab.cc" // lalr1.cc:859
    break;

  case 33:
#line 306 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[2].value.as< std::vector<std::shared_ptr<Node>> > ());
        std::string type_identifier = join(yystack_[0].value.as< std::vector<std::string> > ());
        auto assign_value = driver.ast_generator->create_C_member(type_identifier);
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(assign_value);
    }
#line 1762 "parser.tab.cc" // lalr1.cc:859
    break;

  case 34:
#line 314 "parser.yy" // lalr1.cc:859
    {
        std::string type_identifier = join(yystack_[0].value.as< std::vector<std::string> > ());
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_C_member(type_identifier);
    }
#line 1771 "parser.tab.cc" // lalr1.cc:859
    break;

  case 35:
#line 320 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = yystack_[0].value.as< std::shared_ptr<Node> > ();
    }
#line 1779 "parser.tab.cc" // lalr1.cc:859
    break;

  case 36:
#line 324 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = nullptr;
    }
#line 1787 "parser.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 329 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > () = std::move(yystack_[1].value.as< std::vector<std::string> > ());
    }
#line 1795 "parser.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 333 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > () = {};
    }
#line 1803 "parser.tab.cc" // lalr1.cc:859
    break;

  case 39:
#line 338 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > ().push_back(yystack_[0].value.as< std::string > ());
        driver.ast_generator->add_argument(yystack_[0].value.as< std::string > ());
    }
#line 1812 "parser.tab.cc" // lalr1.cc:859
    break;

  case 40:
#line 343 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > () = std::move(yystack_[2].value.as< std::vector<std::string> > ());
        yylhs.value.as< std::vector<std::string> > ().push_back(yystack_[0].value.as< std::string > ());
        driver.ast_generator->add_argument(yystack_[0].value.as< std::string > ());
    }
#line 1822 "parser.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 350 "parser.yy" // lalr1.cc:859
    {
        //driver.ast_generator->add_global_variables($5);
        is_global = NOT_GLOBAL;
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->no_value_node;
    }
#line 1832 "parser.tab.cc" // lalr1.cc:859
    break;

  case 42:
#line 357 "parser.yy" // lalr1.cc:859
    {
        is_global = GLOBAL;
    }
#line 1840 "parser.tab.cc" // lalr1.cc:859
    break;

  case 43:
#line 362 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1848 "parser.tab.cc" // lalr1.cc:859
    break;

  case 44:
#line 366 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[2].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1857 "parser.tab.cc" // lalr1.cc:859
    break;

  case 45:
#line 372 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->declare_C_function(yystack_[7].value.as< std::string > (),yystack_[4].value.as< std::vector<std::shared_ptr<Node>> > (),yystack_[1].value.as< std::shared_ptr<Node> > ());
    }
#line 1865 "parser.tab.cc" // lalr1.cc:859
    break;

  case 46:
#line 376 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->declare_C_function(yystack_[6].value.as< std::string > (),{},yystack_[1].value.as< std::shared_ptr<Node> > ());
    }
#line 1873 "parser.tab.cc" // lalr1.cc:859
    break;

  case 47:
#line 381 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1881 "parser.tab.cc" // lalr1.cc:859
    break;

  case 48:
#line 385 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > () = std::move(yystack_[2].value.as< std::vector<std::shared_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::shared_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 1890 "parser.tab.cc" // lalr1.cc:859
    break;

  case 49:
#line 391 "parser.yy" // lalr1.cc:859
    {
        driver.ast_generator->into_namespace();
    }
#line 1898 "parser.tab.cc" // lalr1.cc:859
    break;

  case 50:
#line 396 "parser.yy" // lalr1.cc:859
    {
        driver.ast_generator->into_namespace();
    }
#line 1906 "parser.tab.cc" // lalr1.cc:859
    break;

  case 51:
#line 401 "parser.yy" // lalr1.cc:859
    {
        blawn_state = EXIST_IF;
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_if(yystack_[5].value.as< std::shared_ptr<Node> > (),yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
        driver.ast_generator->break_out_of_namespace();
    }
#line 1916 "parser.tab.cc" // lalr1.cc:859
    break;

  case 52:
#line 407 "parser.yy" // lalr1.cc:859
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
#line 1931 "parser.tab.cc" // lalr1.cc:859
    break;

  case 53:
#line 418 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_for(yystack_[9].value.as< std::shared_ptr<Node> > (),yystack_[7].value.as< std::shared_ptr<Node> > (),yystack_[5].value.as< std::shared_ptr<Node> > (),yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
        driver.ast_generator->break_out_of_namespace();
    }
#line 1940 "parser.tab.cc" // lalr1.cc:859
    break;

  case 54:
#line 423 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = yystack_[0].value.as< std::shared_ptr<Node> > ();
    }
#line 1948 "parser.tab.cc" // lalr1.cc:859
    break;

  case 55:
#line 427 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"+");
    }
#line 1956 "parser.tab.cc" // lalr1.cc:859
    break;

  case 56:
#line 431 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"-");
    }
#line 1964 "parser.tab.cc" // lalr1.cc:859
    break;

  case 57:
#line 435 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"*");
    }
#line 1972 "parser.tab.cc" // lalr1.cc:859
    break;

  case 58:
#line 439 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"/");
    }
#line 1980 "parser.tab.cc" // lalr1.cc:859
    break;

  case 59:
#line 443 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"and");
    }
#line 1988 "parser.tab.cc" // lalr1.cc:859
    break;

  case 60:
#line 447 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"or");
    }
#line 1996 "parser.tab.cc" // lalr1.cc:859
    break;

  case 61:
#line 451 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),">=");
    }
#line 2004 "parser.tab.cc" // lalr1.cc:859
    break;

  case 62:
#line 455 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"<=");
    }
#line 2012 "parser.tab.cc" // lalr1.cc:859
    break;

  case 63:
#line 459 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),">");
    }
#line 2020 "parser.tab.cc" // lalr1.cc:859
    break;

  case 64:
#line 463 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"<");
    }
#line 2028 "parser.tab.cc" // lalr1.cc:859
    break;

  case 65:
#line 467 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"!=");
    }
#line 2036 "parser.tab.cc" // lalr1.cc:859
    break;

  case 66:
#line 471 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::shared_ptr<Node> > ()),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),"==");
    }
#line 2044 "parser.tab.cc" // lalr1.cc:859
    break;

  case 67:
#line 475 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 2052 "parser.tab.cc" // lalr1.cc:859
    break;

  case 68:
#line 479 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 2060 "parser.tab.cc" // lalr1.cc:859
    break;

  case 69:
#line 483 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<AccessNode> > ());
    }
#line 2068 "parser.tab.cc" // lalr1.cc:859
    break;

  case 70:
#line 488 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_list(std::move(yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ()));
    }
#line 2076 "parser.tab.cc" // lalr1.cc:859
    break;

  case 71:
#line 492 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_list();
    }
#line 2084 "parser.tab.cc" // lalr1.cc:859
    break;

  case 72:
#line 497 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<AccessNode> > () = driver.ast_generator->create_access(yystack_[1].value.as< std::shared_ptr<Node> > (),yystack_[0].value.as< std::string > ());
    }
#line 2092 "parser.tab.cc" // lalr1.cc:859
    break;

  case 73:
#line 502 "parser.yy" // lalr1.cc:859
    {
        if (is_global == NOT_GLOBAL)
        {yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->assign(yystack_[2].value.as< std::string > (),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),false);}
        if (is_global == GLOBAL)
        {yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->assign(yystack_[2].value.as< std::string > (),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()),true);}
    }
#line 2103 "parser.tab.cc" // lalr1.cc:859
    break;

  case 74:
#line 509 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->assign(yystack_[2].value.as< std::shared_ptr<AccessNode> > (),std::move(yystack_[0].value.as< std::shared_ptr<Node> > ()));
    }
#line 2111 "parser.tab.cc" // lalr1.cc:859
    break;

  case 75:
#line 514 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = yystack_[0].value.as< std::shared_ptr<Node> > ();
    }
#line 2119 "parser.tab.cc" // lalr1.cc:859
    break;

  case 76:
#line 518 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_string(yystack_[0].value.as< std::string > ());
    }
#line 2127 "parser.tab.cc" // lalr1.cc:859
    break;

  case 77:
#line 522 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_float(yystack_[0].value.as< double > ());
    }
#line 2135 "parser.tab.cc" // lalr1.cc:859
    break;

  case 78:
#line 526 "parser.yy" // lalr1.cc:859
    { 
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_integer(yystack_[0].value.as< long long > ());
    }
#line 2143 "parser.tab.cc" // lalr1.cc:859
    break;

  case 79:
#line 530 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = std::move(yystack_[0].value.as< std::shared_ptr<Node> > ());
    }
#line 2151 "parser.tab.cc" // lalr1.cc:859
    break;

  case 80:
#line 535 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_call(yystack_[3].value.as< std::string > (),std::move(yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ()));
    }
#line 2159 "parser.tab.cc" // lalr1.cc:859
    break;

  case 81:
#line 539 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_call(yystack_[2].value.as< std::string > (),{});
    }
#line 2167 "parser.tab.cc" // lalr1.cc:859
    break;

  case 82:
#line 543 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_call(yystack_[3].value.as< std::shared_ptr<AccessNode> > (),yystack_[1].value.as< std::vector<std::shared_ptr<Node>> > ());
    }
#line 2175 "parser.tab.cc" // lalr1.cc:859
    break;

  case 83:
#line 547 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->create_call(yystack_[2].value.as< std::shared_ptr<AccessNode> > (),{});
    }
#line 2183 "parser.tab.cc" // lalr1.cc:859
    break;

  case 84:
#line 552 "parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::shared_ptr<Node> > () = driver.ast_generator->get_named_value(yystack_[0].value.as< std::string > ());
    }
#line 2191 "parser.tab.cc" // lalr1.cc:859
    break;


#line 2195 "parser.tab.cc" // lalr1.cc:859
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


  const signed char Parser::yypact_ninf_ = -116;

  const signed char Parser::yytable_ninf_ = -45;

  const short int
  Parser::yypact_[] =
  {
      71,  -116,  -116,  -116,   -12,     5,    93,  -116,  -116,   150,
    -116,  -116,  -116,  -116,    16,  -116,    71,  -116,     2,  -116,
    -116,     7,  -116,     7,  -116,     0,  -116,    24,  -116,   150,
      28,   309,  -116,     6,  -116,  -116,  -116,  -116,    31,   150,
     110,  -116,    -8,   309,   275,  -116,  -116,  -116,  -116,    -1,
      35,    37,    38,     8,   185,    50,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,  -116,   150,
     122,    -5,   309,  -116,    -7,   150,  -116,   150,  -116,  -116,
      18,    71,     9,    77,    80,    48,    64,    49,   215,   215,
      63,    63,    63,    63,    63,    63,     4,     4,    70,    70,
     309,  -116,    36,  -116,    53,    86,   -18,  -116,   309,   292,
      87,  -116,    92,     7,    89,    98,    61,    10,    95,    99,
     150,    66,    71,  -116,    95,  -116,    95,    72,   150,  -116,
     150,    69,    75,   150,    76,  -116,   111,    98,    -4,    95,
      84,   309,    88,    71,   103,    86,    91,    86,    95,   198,
     309,  -116,    71,   230,  -116,   150,  -116,    -3,   134,   105,
    -116,  -116,   100,   107,    92,  -116,   243,  -116,   106,   118,
    -116,  -116,   119,  -116,  -116,  -116,    71,   112,  -116
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,    16,    20,    22,     0,    84,     0,    49,    50,     0,
      42,    78,    77,    76,     0,     2,     3,     4,     0,     8,
      10,     0,    11,     0,    12,     0,    13,     0,    14,     0,
       0,     9,    68,    69,    54,    67,    75,    79,     0,     0,
       0,    71,     0,    47,     0,     1,     5,     7,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    72,     0,
       0,     0,    73,    81,     0,     0,    70,     0,    39,    38,
       0,     0,     0,     0,    21,     0,     0,     0,    59,    60,
      66,    65,    61,    62,    63,    64,    55,    56,    57,    58,
      74,    83,     0,    30,     0,    32,     0,    80,    48,     0,
       0,    37,     0,     0,     0,    19,     0,    18,     0,     0,
       0,     0,     0,    82,     0,    31,     0,     0,     0,    40,
      36,     0,     0,     0,     0,    23,     0,    17,     0,     0,
       0,     0,    54,     0,     0,    34,     0,    33,     0,     0,
      35,    15,     0,     0,    24,     0,    28,     0,     0,     0,
      52,    46,     0,     0,     0,    26,     0,    29,     0,    54,
      51,    45,     0,    25,    27,    41,     0,     0,    53
  };

  const short int
  Parser::yypgoto_[] =
  {
    -116,  -116,   -77,  -116,   135,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,  -116,    47,  -106,  -116,  -116,   -56,  -116,    25,
      11,   -22,  -116,  -116,  -116,  -116,  -116,   -28,  -116,  -116,
      -6,  -116,  -116,  -115,  -116,  -116,  -116
  };

  const short int
  Parser::yydefgoto_[] =
  {
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   115,   116,   117,    84,   145,   106,   146,
     131,    50,    80,    26,    27,   140,    28,    42,    29,    30,
      31,    32,    33,    34,    35,    36,    37
  };

  const short int
  Parser::yytable_[] =
  {
      43,    51,    47,    44,   112,   142,   103,   125,   125,   134,
      78,   126,    74,   113,   113,   105,    45,    39,    69,   114,
     136,    75,    75,    54,   107,    76,   127,    66,    67,    68,
      79,   134,    38,    72,    43,    40,    70,    49,    85,   104,
     156,   167,   102,   169,    52,   144,    48,   110,    83,   111,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   138,   100,    43,    75,   159,   123,    53,   108,
     147,   109,    55,    71,     1,   164,     2,     3,     4,    81,
      87,    82,     5,   157,    64,    65,    66,    67,    68,   118,
     119,   132,   120,   122,   121,    68,   124,   125,   129,   177,
     130,   133,   113,     6,     5,   135,   103,     7,     8,     9,
     143,   139,    10,   151,   141,   148,    11,    12,    13,   152,
     154,     5,   149,   155,   150,     6,    41,   153,   158,     7,
       8,     9,   -43,     5,   160,   161,   170,   172,    11,    12,
      13,    73,     6,   178,   171,     5,     7,     8,     9,   166,
     175,    46,   141,   101,     6,    11,    12,    13,     7,     8,
       9,     5,   -44,   176,   137,   168,     6,    11,    12,    13,
       7,     8,     9,   162,     0,   173,     0,     0,     0,    11,
      12,    13,     6,     0,     0,     0,     7,     8,     9,     0,
       0,     0,     0,     0,     0,    11,    12,    13,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,     0,     0,     0,     0,    86,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,   163,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
       0,     0,     0,     0,   165,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   174,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,     0,     0,    77,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,     0,
       0,   128,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68
  };

  const short int
  Parser::yycheck_[] =
  {
       6,    23,     0,     9,    81,   120,    11,    11,    11,   115,
      11,    29,    40,     4,     4,    71,     0,    12,    12,    10,
      10,    29,    29,    29,    31,    33,    44,    23,    24,    25,
      31,   137,    44,    39,    40,    30,    30,    30,    30,    44,
      44,    44,    70,   158,    44,   122,    44,    29,    10,    31,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,   118,    69,    70,    29,   143,    31,    44,    75,
     126,    77,    44,    42,     3,   152,     5,     6,     7,    44,
      30,    44,    11,   139,    21,    22,    23,    24,    25,    12,
      10,   113,    44,    44,    30,    25,    43,    11,    11,   176,
       8,    12,     4,    32,    11,    44,    11,    36,    37,    38,
      44,    12,    41,    44,   120,    43,    45,    46,    47,    44,
      44,    11,   128,    12,   130,    32,    33,   133,    44,    36,
      37,    38,    44,    11,    31,    44,    31,    30,    45,    46,
      47,    31,    32,    31,    44,    11,    36,    37,    38,   155,
      44,    16,   158,    31,    32,    45,    46,    47,    36,    37,
      38,    11,    44,    44,   117,    31,    32,    45,    46,    47,
      36,    37,    38,   148,    -1,   164,    -1,    -1,    -1,    45,
      46,    47,    32,    -1,    -1,    -1,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    44,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    44,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    29,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    29,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     3,     5,     6,     7,    11,    32,    36,    37,    38,
      41,    45,    46,    47,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    71,    72,    74,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    44,    12,
      30,    33,    75,    78,    78,     0,    52,     0,    44,    30,
      69,    69,    44,    44,    78,    44,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    12,
      30,    42,    78,    31,    75,    29,    33,    29,    11,    31,
      70,    44,    44,    10,    64,    30,    44,    30,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    31,    75,    11,    44,    65,    66,    31,    78,    78,
      29,    31,    50,     4,    10,    61,    62,    63,    12,    10,
      44,    30,    44,    31,    43,    11,    29,    44,    29,    11,
       8,    68,    69,    12,    62,    44,    10,    61,    65,    12,
      73,    78,    81,    44,    50,    65,    67,    65,    43,    78,
      78,    44,    44,    78,    44,    12,    44,    65,    44,    50,
      31,    44,    67,    44,    50,    44,    78,    44,    31,    81,
      31,    44,    30,    68,    44,    44,    44,    50,    31
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    48,    49,    50,    51,    51,    52,    52,    52,    53,
      54,    54,    54,    54,    54,    55,    56,    57,    57,    57,
      58,    59,    60,    61,    61,    62,    63,    63,    64,    64,
      65,    65,    66,    66,    67,    68,    68,    69,    69,    70,
      70,    71,    72,    73,    73,    74,    74,    75,    75,    76,
      77,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      79,    79,    80,    81,    81,    82,    82,    82,    82,    82,
      83,    83,    83,    83,    84
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     6,     1,     5,     4,     4,
       1,     3,     1,     2,     3,     5,     4,     5,     4,     5,
       1,     2,     1,     3,     1,     2,     1,     3,     2,     1,
       3,     8,     1,     1,     3,     8,     7,     1,     3,     1,
       1,     7,     6,    11,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
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
  "methods", "method_definition", "members_definition",
  "C_members_definition", "C_type_identifier", "C_arguments", "C_returns",
  "return_value", "arguments", "definition_arguments",
  "globals_definition", "global_start", "globals_variables",
  "c_function_declaration", "expressions", "if_start", "else_start",
  "expression", "list", "access", "assign_variable", "monomial", "call",
  "variable", YY_NULLPTR
  };


  const unsigned short int
  Parser::yyrline_[] =
  {
       0,   140,   140,   146,   152,   156,   162,   166,   170,   175,
     180,   184,   188,   192,   196,   201,   207,   213,   218,   223,
     229,   235,   241,   247,   251,   257,   265,   269,   275,   281,
     289,   293,   299,   305,   313,   319,   323,   328,   332,   337,
     342,   349,   356,   361,   365,   371,   375,   380,   384,   390,
     395,   400,   406,   417,   422,   426,   430,   434,   438,   442,
     446,   450,   454,   458,   462,   466,   470,   474,   478,   482,
     487,   491,   496,   501,   508,   513,   517,   521,   525,   529,
     534,   538,   542,   546,   551
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
#line 2685 "parser.tab.cc" // lalr1.cc:1167
#line 555 "parser.yy" // lalr1.cc:1168


void Blawn::Parser::error( const location_type &l, const std::string &err_message )
{
    std::cerr << "Error: " << err_message << " at " << l << "\n";
    exit(1);
} 
