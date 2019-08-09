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
#line 38 "./parser.yy" // lalr1.cc:413

    #include <iostream>
    #include <cstdlib>
    #include <fstream>
    #include <memory>
    #include "driver.hpp"
    #undef yylex
    #define yylex scanner.yylex

#line 63 "parser.tab.cc" // lalr1.cc:413


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

#line 6 "./parser.yy" // lalr1.cc:479
namespace Blawn {
#line 149 "parser.tab.cc" // lalr1.cc:479

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
      case 22: // FLOAT_LITERAL
        value.copy< double > (other.value);
        break;

      case 21: // INT_LITERAL
        value.copy< int > (other.value);
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // CLASS_DEFINITION
      case 6: // IDENTIFIER
      case 23: // STRING_LITERAL
        value.copy< std::string > (other.value);
        break;

      case 28: // line
      case 29: // line_content
      case 30: // definition
      case 31: // variable_definition
      case 32: // function_definition
      case 33: // class_definition
      case 37: // expression
      case 38: // term
      case 39: // function_call
      case 40: // monomial
        value.copy< std::unique_ptr<Node> > (other.value);
        break;

      case 41: // variable
        value.copy< std::unique_ptr<VariableNode> > (other.value);
        break;

      case 35: // definition_arguments
        value.copy< std::vector<std::string> > (other.value);
        break;

      case 26: // block
      case 27: // lines
      case 36: // expressions
        value.copy< std::vector<std::unique_ptr<Node>> > (other.value);
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
      case 22: // FLOAT_LITERAL
        value.copy< double > (v);
        break;

      case 21: // INT_LITERAL
        value.copy< int > (v);
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // CLASS_DEFINITION
      case 6: // IDENTIFIER
      case 23: // STRING_LITERAL
        value.copy< std::string > (v);
        break;

      case 28: // line
      case 29: // line_content
      case 30: // definition
      case 31: // variable_definition
      case 32: // function_definition
      case 33: // class_definition
      case 37: // expression
      case 38: // term
      case 39: // function_call
      case 40: // monomial
        value.copy< std::unique_ptr<Node> > (v);
        break;

      case 41: // variable
        value.copy< std::unique_ptr<VariableNode> > (v);
        break;

      case 35: // definition_arguments
        value.copy< std::vector<std::string> > (v);
        break;

      case 26: // block
      case 27: // lines
      case 36: // expressions
        value.copy< std::vector<std::unique_ptr<Node>> > (v);
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
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const int v, const location_type& l)
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
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::unique_ptr<Node> v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::unique_ptr<VariableNode> v, const location_type& l)
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
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::vector<std::unique_ptr<Node>> v, const location_type& l)
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
      case 22: // FLOAT_LITERAL
        value.template destroy< double > ();
        break;

      case 21: // INT_LITERAL
        value.template destroy< int > ();
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // CLASS_DEFINITION
      case 6: // IDENTIFIER
      case 23: // STRING_LITERAL
        value.template destroy< std::string > ();
        break;

      case 28: // line
      case 29: // line_content
      case 30: // definition
      case 31: // variable_definition
      case 32: // function_definition
      case 33: // class_definition
      case 37: // expression
      case 38: // term
      case 39: // function_call
      case 40: // monomial
        value.template destroy< std::unique_ptr<Node> > ();
        break;

      case 41: // variable
        value.template destroy< std::unique_ptr<VariableNode> > ();
        break;

      case 35: // definition_arguments
        value.template destroy< std::vector<std::string> > ();
        break;

      case 26: // block
      case 27: // lines
      case 36: // expressions
        value.template destroy< std::vector<std::unique_ptr<Node>> > ();
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
      case 22: // FLOAT_LITERAL
        value.move< double > (s.value);
        break;

      case 21: // INT_LITERAL
        value.move< int > (s.value);
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // CLASS_DEFINITION
      case 6: // IDENTIFIER
      case 23: // STRING_LITERAL
        value.move< std::string > (s.value);
        break;

      case 28: // line
      case 29: // line_content
      case 30: // definition
      case 31: // variable_definition
      case 32: // function_definition
      case 33: // class_definition
      case 37: // expression
      case 38: // term
      case 39: // function_call
      case 40: // monomial
        value.move< std::unique_ptr<Node> > (s.value);
        break;

      case 41: // variable
        value.move< std::unique_ptr<VariableNode> > (s.value);
        break;

      case 35: // definition_arguments
        value.move< std::vector<std::string> > (s.value);
        break;

      case 26: // block
      case 27: // lines
      case 36: // expressions
        value.move< std::vector<std::unique_ptr<Node>> > (s.value);
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
  Parser::make_COLON (const location_type& l)
  {
    return symbol_type (token::COLON, l);
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
  Parser::make_INT_LITERAL (const int& v, const location_type& l)
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
      case 22: // FLOAT_LITERAL
        value.move< double > (that.value);
        break;

      case 21: // INT_LITERAL
        value.move< int > (that.value);
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // CLASS_DEFINITION
      case 6: // IDENTIFIER
      case 23: // STRING_LITERAL
        value.move< std::string > (that.value);
        break;

      case 28: // line
      case 29: // line_content
      case 30: // definition
      case 31: // variable_definition
      case 32: // function_definition
      case 33: // class_definition
      case 37: // expression
      case 38: // term
      case 39: // function_call
      case 40: // monomial
        value.move< std::unique_ptr<Node> > (that.value);
        break;

      case 41: // variable
        value.move< std::unique_ptr<VariableNode> > (that.value);
        break;

      case 35: // definition_arguments
        value.move< std::vector<std::string> > (that.value);
        break;

      case 26: // block
      case 27: // lines
      case 36: // expressions
        value.move< std::vector<std::unique_ptr<Node>> > (that.value);
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
      case 22: // FLOAT_LITERAL
        value.copy< double > (that.value);
        break;

      case 21: // INT_LITERAL
        value.copy< int > (that.value);
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // CLASS_DEFINITION
      case 6: // IDENTIFIER
      case 23: // STRING_LITERAL
        value.copy< std::string > (that.value);
        break;

      case 28: // line
      case 29: // line_content
      case 30: // definition
      case 31: // variable_definition
      case 32: // function_definition
      case 33: // class_definition
      case 37: // expression
      case 38: // term
      case 39: // function_call
      case 40: // monomial
        value.copy< std::unique_ptr<Node> > (that.value);
        break;

      case 41: // variable
        value.copy< std::unique_ptr<VariableNode> > (that.value);
        break;

      case 35: // definition_arguments
        value.copy< std::vector<std::string> > (that.value);
        break;

      case 26: // block
      case 27: // lines
      case 36: // expressions
        value.copy< std::vector<std::unique_ptr<Node>> > (that.value);
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
      case 22: // FLOAT_LITERAL
        yylhs.value.build< double > ();
        break;

      case 21: // INT_LITERAL
        yylhs.value.build< int > ();
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // CLASS_DEFINITION
      case 6: // IDENTIFIER
      case 23: // STRING_LITERAL
        yylhs.value.build< std::string > ();
        break;

      case 28: // line
      case 29: // line_content
      case 30: // definition
      case 31: // variable_definition
      case 32: // function_definition
      case 33: // class_definition
      case 37: // expression
      case 38: // term
      case 39: // function_call
      case 40: // monomial
        yylhs.value.build< std::unique_ptr<Node> > ();
        break;

      case 41: // variable
        yylhs.value.build< std::unique_ptr<VariableNode> > ();
        break;

      case 35: // definition_arguments
        yylhs.value.build< std::vector<std::string> > ();
        break;

      case 26: // block
      case 27: // lines
      case 36: // expressions
        yylhs.value.build< std::vector<std::unique_ptr<Node>> > ();
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
#line 94 "./parser.yy" // lalr1.cc:859
    {
        driver.ast_generator->break_out_of_namespace();
    }
#line 1111 "parser.tab.cc" // lalr1.cc:859
    break;

  case 3:
#line 99 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::unique_ptr<Node>> > () = std::move(yystack_[0].value.as< std::vector<std::unique_ptr<Node>> > ());
    }
#line 1119 "parser.tab.cc" // lalr1.cc:859
    break;

  case 4:
#line 104 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::unique_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::unique_ptr<Node> > ()));
    }
#line 1127 "parser.tab.cc" // lalr1.cc:859
    break;

  case 5:
#line 108 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::unique_ptr<Node>> > () = std::move(yystack_[1].value.as< std::vector<std::unique_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::unique_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::unique_ptr<Node> > ()));
    }
#line 1136 "parser.tab.cc" // lalr1.cc:859
    break;

  case 6:
#line 114 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::unique_ptr<Node> > () = std::move(yystack_[1].value.as< std::unique_ptr<Node> > ());
    }
#line 1144 "parser.tab.cc" // lalr1.cc:859
    break;

  case 7:
#line 118 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::unique_ptr<Node> > () = std::move(yystack_[1].value.as< std::unique_ptr<Node> > ());
    }
#line 1152 "parser.tab.cc" // lalr1.cc:859
    break;

  case 8:
#line 123 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::unique_ptr<Node> > () = std::move(yystack_[0].value.as< std::unique_ptr<Node> > ());
    }
#line 1160 "parser.tab.cc" // lalr1.cc:859
    break;

  case 9:
#line 127 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::unique_ptr<Node> > () = std::move(yystack_[0].value.as< std::unique_ptr<Node> > ());
    }
#line 1168 "parser.tab.cc" // lalr1.cc:859
    break;

  case 10:
#line 132 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::unique_ptr<Node> > () = std::move(yystack_[0].value.as< std::unique_ptr<Node> > ());
    }
#line 1176 "parser.tab.cc" // lalr1.cc:859
    break;

  case 11:
#line 136 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::unique_ptr<Node> > () = std::move(yystack_[0].value.as< std::unique_ptr<Node> > ());
    }
#line 1184 "parser.tab.cc" // lalr1.cc:859
    break;

  case 12:
#line 140 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::unique_ptr<Node> > () = std::move(yystack_[0].value.as< std::unique_ptr<Node> > ());
    }
#line 1192 "parser.tab.cc" // lalr1.cc:859
    break;

  case 13:
#line 145 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::unique_ptr<Node> > () = driver.ast_generator->add_variable(yystack_[2].value.as< std::string > (),std::move(yystack_[0].value.as< std::unique_ptr<Node> > ()));
        //std::cout << "new variable:" << std::move($1) <<"  type:" << (type->type_name) << "\n";
    }
#line 1201 "parser.tab.cc" // lalr1.cc:859
    break;

  case 14:
#line 151 "./parser.yy" // lalr1.cc:859
    {
        driver.ast_generator->book_function(yystack_[7].value.as< std::string > (),std::move(yystack_[5].value.as< std::vector<std::string> > ()),std::move(yystack_[2].value.as< std::vector<std::unique_ptr<Node>> > ()),std::move(yystack_[0].value.as< std::unique_ptr<Node> > ()));
        //driver.ast_generator->into_namespace($1);
        yylhs.value.as< std::unique_ptr<Node> > () = std::unique_ptr<Node>(new Node(*driver.ast_generator->ir_generator));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1212 "parser.tab.cc" // lalr1.cc:859
    break;

  case 15:
#line 159 "./parser.yy" // lalr1.cc:859
    {
        driver.ast_generator->into_namespace(yystack_[3].value.as< std::string > ());
        yylhs.value.as< std::unique_ptr<Node> > () = std::unique_ptr<Node>(new Node(*driver.ast_generator->ir_generator));
        driver.ast_generator->break_out_of_namespace();
    }
#line 1222 "parser.tab.cc" // lalr1.cc:859
    break;

  case 17:
#line 168 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > ().push_back(yystack_[0].value.as< std::string > ());
        driver.ast_generator->add_argument(yystack_[0].value.as< std::string > ());
    }
#line 1231 "parser.tab.cc" // lalr1.cc:859
    break;

  case 18:
#line 173 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::string> > () = std::move(yystack_[2].value.as< std::vector<std::string> > ());
        yylhs.value.as< std::vector<std::string> > ().push_back(yystack_[0].value.as< std::string > ());
        driver.ast_generator->add_argument(yystack_[0].value.as< std::string > ());
    }
#line 1241 "parser.tab.cc" // lalr1.cc:859
    break;

  case 19:
#line 180 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::unique_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::unique_ptr<Node> > ()));
    }
#line 1249 "parser.tab.cc" // lalr1.cc:859
    break;

  case 20:
#line 184 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::vector<std::unique_ptr<Node>> > () = std::move(yystack_[2].value.as< std::vector<std::unique_ptr<Node>> > ());
        yylhs.value.as< std::vector<std::unique_ptr<Node>> > ().push_back(std::move(yystack_[0].value.as< std::unique_ptr<Node> > ()));
    }
#line 1258 "parser.tab.cc" // lalr1.cc:859
    break;

  case 21:
#line 190 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::unique_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::unique_ptr<Node> > ()),std::move(yystack_[0].value.as< std::unique_ptr<Node> > ()),"+");
    }
#line 1266 "parser.tab.cc" // lalr1.cc:859
    break;

  case 22:
#line 194 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::unique_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::unique_ptr<Node> > ()),std::move(yystack_[0].value.as< std::unique_ptr<Node> > ()),"-");
    }
#line 1274 "parser.tab.cc" // lalr1.cc:859
    break;

  case 23:
#line 198 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::unique_ptr<Node> > () = std::move(yystack_[0].value.as< std::unique_ptr<Node> > ());
    }
#line 1282 "parser.tab.cc" // lalr1.cc:859
    break;

  case 24:
#line 202 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::unique_ptr<Node> > () = std::move(yystack_[0].value.as< std::unique_ptr<Node> > ());
    }
#line 1290 "parser.tab.cc" // lalr1.cc:859
    break;

  case 25:
#line 207 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::unique_ptr<Node> > () = std::move(yystack_[0].value.as< std::unique_ptr<Node> > ());
    }
#line 1298 "parser.tab.cc" // lalr1.cc:859
    break;

  case 26:
#line 211 "./parser.yy" // lalr1.cc:859
    {
      yylhs.value.as< std::unique_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::unique_ptr<Node> > ()),std::move(yystack_[0].value.as< std::unique_ptr<Node> > ()),"*");
    }
#line 1306 "parser.tab.cc" // lalr1.cc:859
    break;

  case 27:
#line 215 "./parser.yy" // lalr1.cc:859
    {
       yylhs.value.as< std::unique_ptr<Node> > () = driver.ast_generator->attach_operator(std::move(yystack_[2].value.as< std::unique_ptr<Node> > ()),std::move(yystack_[0].value.as< std::unique_ptr<Node> > ()),"/");
    }
#line 1314 "parser.tab.cc" // lalr1.cc:859
    break;

  case 28:
#line 220 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::unique_ptr<Node> > () = driver.ast_generator->call_function(yystack_[3].value.as< std::string > (),std::move(yystack_[1].value.as< std::vector<std::unique_ptr<Node>> > ()));
    }
#line 1322 "parser.tab.cc" // lalr1.cc:859
    break;

  case 29:
#line 225 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::unique_ptr<Node> > () = driver.ast_generator->create_float(yystack_[0].value.as< double > ());
    }
#line 1330 "parser.tab.cc" // lalr1.cc:859
    break;

  case 30:
#line 229 "./parser.yy" // lalr1.cc:859
    { 
        yylhs.value.as< std::unique_ptr<Node> > () = driver.ast_generator->create_interger(yystack_[0].value.as< int > ());
    }
#line 1338 "parser.tab.cc" // lalr1.cc:859
    break;

  case 31:
#line 233 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::unique_ptr<Node> > () = std::move(yystack_[0].value.as< std::unique_ptr<VariableNode> > ());
    }
#line 1346 "parser.tab.cc" // lalr1.cc:859
    break;

  case 32:
#line 238 "./parser.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::unique_ptr<VariableNode> > () = driver.ast_generator->get_variable(yystack_[0].value.as< std::string > ());
        //$$->generate();
        //std::unique_ptr<Node>(new Node(type));
        //$$ = std::unique_ptr<Node>(new Node());
    }
#line 1357 "parser.tab.cc" // lalr1.cc:859
    break;


#line 1361 "parser.tab.cc" // lalr1.cc:859
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


  const signed char Parser::yypact_ninf_ = -23;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
       3,    -9,    10,     1,   -23,   -23,    18,   -23,     3,   -23,
       2,   -23,   -23,   -23,   -23,     5,     0,   -23,   -23,   -23,
      30,     3,    -2,    -2,   -23,   -23,   -23,   -23,     6,     6,
       6,     6,   -23,     8,    25,    24,     5,    16,     5,   -23,
       0,     0,   -23,   -23,    33,    20,   -23,   -23,    -2,   -23,
     -23,     3,     5,    36,    -2,     5
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,     0,     0,    32,    30,    29,     0,     2,     3,     4,
       0,     8,    10,    11,    12,     9,    23,    24,    25,    31,
       0,     0,     0,     0,     1,     5,     7,     6,     0,     0,
       0,     0,    17,     0,     0,    32,    13,     0,    19,    32,
      21,    22,    26,    27,     0,     0,    16,    15,     0,    28,
      18,     0,    20,     0,     0,    14
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -23,   -23,   -18,   -23,    34,   -23,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   -22,   -12,   -23,     4,   -23
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      47,    33,    37,    15,    16,    17,    18,    19
  };

  const unsigned char
  Parser::yytable_[] =
  {
      36,    38,    26,    34,    35,    20,     1,     2,    22,     3,
      30,    31,    39,    28,    29,    23,    40,    41,    24,     4,
       5,    44,    27,    45,     4,     5,    52,     4,     5,    48,
      21,    49,    55,    53,    42,    43,    32,    46,    23,    50,
      51,    54,    25
  };

  const unsigned char
  Parser::yycheck_[] =
  {
      22,    23,     0,    21,     6,    14,     3,     4,     7,     6,
      10,    11,     6,     8,     9,    14,    28,    29,     0,    21,
      22,    13,    20,    15,    21,    22,    48,    21,    22,    13,
      20,    15,    54,    51,    30,    31,     6,    12,    14,     6,
      20,     5,     8
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     3,     4,     6,    21,    22,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    37,    38,    39,    40,    41,
      14,    20,     7,    14,     0,    28,     0,    20,     8,     9,
      10,    11,     6,    35,    26,     6,    37,    36,    37,     6,
      38,    38,    40,    40,    13,    15,    12,    34,    13,    15,
       6,    20,    37,    26,     5,    37
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    24,    25,    26,    27,    27,    28,    28,    29,    29,
      30,    30,    30,    31,    32,    33,    34,    35,    35,    36,
      36,    37,    37,    37,    37,    38,    38,    38,    39,    40,
      40,    40,    41
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     2,     2,     2,     1,     1,
       1,     1,     1,     3,     8,     4,     1,     1,     3,     1,
       3,     3,     3,     1,     1,     1,     3,     3,     4,     1,
       1,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "FUNCTION_DEFINITION",
  "CLASS_DEFINITION", "RETURN", "IDENTIFIER", "EQUAL", "PLUS", "MINUS",
  "ASTERISK", "SLASH", "COLON", "COMMA", "LEFT_PARENTHESIS",
  "RIGHT_PARENTHESIS", "IF", "ELSE", "FOR", "WHILE", "EOL", "INT_LITERAL",
  "FLOAT_LITERAL", "STRING_LITERAL", "$accept", "program", "block",
  "lines", "line", "line_content", "definition", "variable_definition",
  "function_definition", "class_definition", "class_definition_end",
  "definition_arguments", "expressions", "expression", "term",
  "function_call", "monomial", "variable", YY_NULLPTR
  };


  const unsigned char
  Parser::yyrline_[] =
  {
       0,    93,    93,    98,   103,   107,   113,   117,   122,   126,
     131,   135,   139,   144,   150,   158,   165,   167,   172,   179,
     183,   189,   193,   197,   201,   206,   210,   214,   219,   224,
     228,   232,   237
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
    };
    const unsigned int user_token_number_max_ = 278;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 6 "./parser.yy" // lalr1.cc:1167
} // Blawn
#line 1724 "parser.tab.cc" // lalr1.cc:1167
#line 246 "./parser.yy" // lalr1.cc:1168


void Blawn::Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
} 
