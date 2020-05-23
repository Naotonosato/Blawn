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
#line 35 "./src/lib/blawn/parser/parser.yy"

    #include <iostream>
    #include <cstdlib>
    #include <fstream>
    #include <memory>
    #include "include/blawn/parser/driver.hpp"
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

#line 64 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"


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

#line 5 "./src/lib/blawn/parser/parser.yy"
namespace blawn {
#line 156 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"


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
      case 46: // FLOAT_LITERAL
        value.move< double > (std::move (that.value));
        break;

      case 45: // INT_LITERAL
        value.move< long long > (std::move (that.value));
        break;

      case 56: // function_start
      case 58: // class_start
      case 60: // method_start
        value.move< std::pair< std::string,std::vector<std::unique_ptr<ast::Node>>>  > (std::move (that.value));
        break;

      case 3: // MEMBER_IDENTIFIER
      case 4: // IDENTIFIER
      case 30: // DOT_IDENTIFIER
      case 44: // STRING_LITERAL
        value.move< std::string > (std::move (that.value));
        break;

      case 49: // program
      case 50: // block
      case 53: // line
      case 54: // definition
      case 55: // function_definition
      case 57: // class_definition
      case 61: // method_definition
      case 67: // else_body
      case 68: // expression
      case 69: // array
      case 70: // access
      case 71: // global_variable_definition
      case 72: // assign_variable
      case 73: // return_value
      case 74: // monomial
      case 75: // call
      case 76: // named_value
        value.move< std::unique_ptr<ast::Node> > (std::move (that.value));
        break;

      case 31: // FUNCTION_DEFINITION
      case 32: // METHOD_DEFINITION
      case 33: // CLASS_DEFINITION
        value.move< std::unique_ptr<blawn::DeclarationInfo> > (std::move (that.value));
        break;

      case 52: // lines
      case 59: // methods
      case 62: // members_definition
      case 63: // expressions
      case 66: // for_start
        value.move< std::vector<std::unique_ptr<ast::Node>> > (std::move (that.value));
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
      case 46: // FLOAT_LITERAL
        value.copy< double > (YY_MOVE (that.value));
        break;

      case 45: // INT_LITERAL
        value.copy< long long > (YY_MOVE (that.value));
        break;

      case 56: // function_start
      case 58: // class_start
      case 60: // method_start
        value.copy< std::pair< std::string,std::vector<std::unique_ptr<ast::Node>>>  > (YY_MOVE (that.value));
        break;

      case 3: // MEMBER_IDENTIFIER
      case 4: // IDENTIFIER
      case 30: // DOT_IDENTIFIER
      case 44: // STRING_LITERAL
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case 49: // program
      case 50: // block
      case 53: // line
      case 54: // definition
      case 55: // function_definition
      case 57: // class_definition
      case 61: // method_definition
      case 67: // else_body
      case 68: // expression
      case 69: // array
      case 70: // access
      case 71: // global_variable_definition
      case 72: // assign_variable
      case 73: // return_value
      case 74: // monomial
      case 75: // call
      case 76: // named_value
        value.copy< std::unique_ptr<ast::Node> > (YY_MOVE (that.value));
        break;

      case 31: // FUNCTION_DEFINITION
      case 32: // METHOD_DEFINITION
      case 33: // CLASS_DEFINITION
        value.copy< std::unique_ptr<blawn::DeclarationInfo> > (YY_MOVE (that.value));
        break;

      case 52: // lines
      case 59: // methods
      case 62: // members_definition
      case 63: // expressions
      case 66: // for_start
        value.copy< std::vector<std::unique_ptr<ast::Node>> > (YY_MOVE (that.value));
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
      case 46: // FLOAT_LITERAL
        value.move< double > (YY_MOVE (s.value));
        break;

      case 45: // INT_LITERAL
        value.move< long long > (YY_MOVE (s.value));
        break;

      case 56: // function_start
      case 58: // class_start
      case 60: // method_start
        value.move< std::pair< std::string,std::vector<std::unique_ptr<ast::Node>>>  > (YY_MOVE (s.value));
        break;

      case 3: // MEMBER_IDENTIFIER
      case 4: // IDENTIFIER
      case 30: // DOT_IDENTIFIER
      case 44: // STRING_LITERAL
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case 49: // program
      case 50: // block
      case 53: // line
      case 54: // definition
      case 55: // function_definition
      case 57: // class_definition
      case 61: // method_definition
      case 67: // else_body
      case 68: // expression
      case 69: // array
      case 70: // access
      case 71: // global_variable_definition
      case 72: // assign_variable
      case 73: // return_value
      case 74: // monomial
      case 75: // call
      case 76: // named_value
        value.move< std::unique_ptr<ast::Node> > (YY_MOVE (s.value));
        break;

      case 31: // FUNCTION_DEFINITION
      case 32: // METHOD_DEFINITION
      case 33: // CLASS_DEFINITION
        value.move< std::unique_ptr<blawn::DeclarationInfo> > (YY_MOVE (s.value));
        break;

      case 52: // lines
      case 59: // methods
      case 62: // members_definition
      case 63: // expressions
      case 66: // for_start
        value.move< std::vector<std::unique_ptr<ast::Node>> > (YY_MOVE (s.value));
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
      case 46: // FLOAT_LITERAL
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case 45: // INT_LITERAL
        value.YY_MOVE_OR_COPY< long long > (YY_MOVE (that.value));
        break;

      case 56: // function_start
      case 58: // class_start
      case 60: // method_start
        value.YY_MOVE_OR_COPY< std::pair< std::string,std::vector<std::unique_ptr<ast::Node>>>  > (YY_MOVE (that.value));
        break;

      case 3: // MEMBER_IDENTIFIER
      case 4: // IDENTIFIER
      case 30: // DOT_IDENTIFIER
      case 44: // STRING_LITERAL
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 49: // program
      case 50: // block
      case 53: // line
      case 54: // definition
      case 55: // function_definition
      case 57: // class_definition
      case 61: // method_definition
      case 67: // else_body
      case 68: // expression
      case 69: // array
      case 70: // access
      case 71: // global_variable_definition
      case 72: // assign_variable
      case 73: // return_value
      case 74: // monomial
      case 75: // call
      case 76: // named_value
        value.YY_MOVE_OR_COPY< std::unique_ptr<ast::Node> > (YY_MOVE (that.value));
        break;

      case 31: // FUNCTION_DEFINITION
      case 32: // METHOD_DEFINITION
      case 33: // CLASS_DEFINITION
        value.YY_MOVE_OR_COPY< std::unique_ptr<blawn::DeclarationInfo> > (YY_MOVE (that.value));
        break;

      case 52: // lines
      case 59: // methods
      case 62: // members_definition
      case 63: // expressions
      case 66: // for_start
        value.YY_MOVE_OR_COPY< std::vector<std::unique_ptr<ast::Node>> > (YY_MOVE (that.value));
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
      case 46: // FLOAT_LITERAL
        value.move< double > (YY_MOVE (that.value));
        break;

      case 45: // INT_LITERAL
        value.move< long long > (YY_MOVE (that.value));
        break;

      case 56: // function_start
      case 58: // class_start
      case 60: // method_start
        value.move< std::pair< std::string,std::vector<std::unique_ptr<ast::Node>>>  > (YY_MOVE (that.value));
        break;

      case 3: // MEMBER_IDENTIFIER
      case 4: // IDENTIFIER
      case 30: // DOT_IDENTIFIER
      case 44: // STRING_LITERAL
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 49: // program
      case 50: // block
      case 53: // line
      case 54: // definition
      case 55: // function_definition
      case 57: // class_definition
      case 61: // method_definition
      case 67: // else_body
      case 68: // expression
      case 69: // array
      case 70: // access
      case 71: // global_variable_definition
      case 72: // assign_variable
      case 73: // return_value
      case 74: // monomial
      case 75: // call
      case 76: // named_value
        value.move< std::unique_ptr<ast::Node> > (YY_MOVE (that.value));
        break;

      case 31: // FUNCTION_DEFINITION
      case 32: // METHOD_DEFINITION
      case 33: // CLASS_DEFINITION
        value.move< std::unique_ptr<blawn::DeclarationInfo> > (YY_MOVE (that.value));
        break;

      case 52: // lines
      case 59: // methods
      case 62: // members_definition
      case 63: // expressions
      case 66: // for_start
        value.move< std::vector<std::unique_ptr<ast::Node>> > (YY_MOVE (that.value));
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
      case 46: // FLOAT_LITERAL
        value.copy< double > (that.value);
        break;

      case 45: // INT_LITERAL
        value.copy< long long > (that.value);
        break;

      case 56: // function_start
      case 58: // class_start
      case 60: // method_start
        value.copy< std::pair< std::string,std::vector<std::unique_ptr<ast::Node>>>  > (that.value);
        break;

      case 3: // MEMBER_IDENTIFIER
      case 4: // IDENTIFIER
      case 30: // DOT_IDENTIFIER
      case 44: // STRING_LITERAL
        value.copy< std::string > (that.value);
        break;

      case 49: // program
      case 50: // block
      case 53: // line
      case 54: // definition
      case 55: // function_definition
      case 57: // class_definition
      case 61: // method_definition
      case 67: // else_body
      case 68: // expression
      case 69: // array
      case 70: // access
      case 71: // global_variable_definition
      case 72: // assign_variable
      case 73: // return_value
      case 74: // monomial
      case 75: // call
      case 76: // named_value
        value.copy< std::unique_ptr<ast::Node> > (that.value);
        break;

      case 31: // FUNCTION_DEFINITION
      case 32: // METHOD_DEFINITION
      case 33: // CLASS_DEFINITION
        value.copy< std::unique_ptr<blawn::DeclarationInfo> > (that.value);
        break;

      case 52: // lines
      case 59: // methods
      case 62: // members_definition
      case 63: // expressions
      case 66: // for_start
        value.copy< std::vector<std::unique_ptr<ast::Node>> > (that.value);
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
      case 46: // FLOAT_LITERAL
        value.move< double > (that.value);
        break;

      case 45: // INT_LITERAL
        value.move< long long > (that.value);
        break;

      case 56: // function_start
      case 58: // class_start
      case 60: // method_start
        value.move< std::pair< std::string,std::vector<std::unique_ptr<ast::Node>>>  > (that.value);
        break;

      case 3: // MEMBER_IDENTIFIER
      case 4: // IDENTIFIER
      case 30: // DOT_IDENTIFIER
      case 44: // STRING_LITERAL
        value.move< std::string > (that.value);
        break;

      case 49: // program
      case 50: // block
      case 53: // line
      case 54: // definition
      case 55: // function_definition
      case 57: // class_definition
      case 61: // method_definition
      case 67: // else_body
      case 68: // expression
      case 69: // array
      case 70: // access
      case 71: // global_variable_definition
      case 72: // assign_variable
      case 73: // return_value
      case 74: // monomial
      case 75: // call
      case 76: // named_value
        value.move< std::unique_ptr<ast::Node> > (that.value);
        break;

      case 31: // FUNCTION_DEFINITION
      case 32: // METHOD_DEFINITION
      case 33: // CLASS_DEFINITION
        value.move< std::unique_ptr<blawn::DeclarationInfo> > (that.value);
        break;

      case 52: // lines
      case 59: // methods
      case 62: // members_definition
      case 63: // expressions
      case 66: // for_start
        value.move< std::vector<std::unique_ptr<ast::Node>> > (that.value);
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
      case 46: // FLOAT_LITERAL
        yylhs.value.emplace< double > ();
        break;

      case 45: // INT_LITERAL
        yylhs.value.emplace< long long > ();
        break;

      case 56: // function_start
      case 58: // class_start
      case 60: // method_start
        yylhs.value.emplace< std::pair< std::string,std::vector<std::unique_ptr<ast::Node>>>  > ();
        break;

      case 3: // MEMBER_IDENTIFIER
      case 4: // IDENTIFIER
      case 30: // DOT_IDENTIFIER
      case 44: // STRING_LITERAL
        yylhs.value.emplace< std::string > ();
        break;

      case 49: // program
      case 50: // block
      case 53: // line
      case 54: // definition
      case 55: // function_definition
      case 57: // class_definition
      case 61: // method_definition
      case 67: // else_body
      case 68: // expression
      case 69: // array
      case 70: // access
      case 71: // global_variable_definition
      case 72: // assign_variable
      case 73: // return_value
      case 74: // monomial
      case 75: // call
      case 76: // named_value
        yylhs.value.emplace< std::unique_ptr<ast::Node> > ();
        break;

      case 31: // FUNCTION_DEFINITION
      case 32: // METHOD_DEFINITION
      case 33: // CLASS_DEFINITION
        yylhs.value.emplace< std::unique_ptr<blawn::DeclarationInfo> > ();
        break;

      case 52: // lines
      case 59: // methods
      case 62: // members_definition
      case 63: // expressions
      case 66: // for_start
        yylhs.value.emplace< std::vector<std::unique_ptr<ast::Node>> > ();
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
#line 133 "./src/lib/blawn/parser/parser.yy"
    {
        driver.ast_builder->break_out_of_scope();
        driver.ast_builder->create_root(std::move(yystack_[0].value.as < std::vector<std::unique_ptr<ast::Node>> > ()));
    }
#line 1078 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 3:
#line 139 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_block(std::move(yystack_[0].value.as < std::vector<std::unique_ptr<ast::Node>> > ()));
    }
#line 1086 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 6:
#line 146 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::unique_ptr<ast::Node>> > ().push_back(std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ()));
    }
#line 1094 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 7:
#line 150 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::unique_ptr<ast::Node>> > () = std::move(yystack_[1].value.as < std::vector<std::unique_ptr<ast::Node>> > ());
        yylhs.value.as < std::vector<std::unique_ptr<ast::Node>> > ().push_back(std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ()));
    }
#line 1103 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 8:
#line 156 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = std::move(yystack_[1].value.as < std::unique_ptr<ast::Node> > ());
    }
#line 1111 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 9:
#line 161 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ());
    }
#line 1119 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 10:
#line 165 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ());
    }
#line 1127 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 11:
#line 170 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_generic_function_definition(yystack_[4].value.as < std::pair< std::string,std::vector<std::unique_ptr<ast::Node>>>  > ().first,std::move(yystack_[4].value.as < std::pair< std::string,std::vector<std::unique_ptr<ast::Node>>>  > ().second),std::move(yystack_[1].value.as < std::unique_ptr<ast::Node> > ()));
        driver.ast_builder->break_out_of_scope();
    }
#line 1136 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 12:
#line 176 "./src/lib/blawn/parser/parser.yy"
    {
        auto name = yystack_[0].value.as < std::unique_ptr<blawn::DeclarationInfo> > ()->name;
        driver.ast_builder->into_named_scope(name);
        std::vector<std::unique_ptr<ast::Node>> arguments;
        for (auto& arg_name:yystack_[0].value.as < std::unique_ptr<blawn::DeclarationInfo> > ()->argument_names)
        {
            arguments.push_back(driver.ast_builder->create_argument(arg_name));
        }
        driver.ast_builder->break_out_of_scope();
        driver.ast_builder->create_generic_function_declaration(name,std::move(arguments));
        driver.ast_builder->into_named_scope(name);
        yylhs.value.as < std::pair< std::string,std::vector<std::unique_ptr<ast::Node>>>  > () = {name,std::move(arguments)};
    }
#line 1154 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 13:
#line 191 "./src/lib/blawn/parser/parser.yy"
    { 
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_generic_class_definition(yystack_[3].value.as < std::pair< std::string,std::vector<std::unique_ptr<ast::Node>>>  > ().first,std::move(yystack_[3].value.as < std::pair< std::string,std::vector<std::unique_ptr<ast::Node>>>  > ().second),std::move(yystack_[1].value.as < std::vector<std::unique_ptr<ast::Node>> > ()),std::move(yystack_[0].value.as < std::vector<std::unique_ptr<ast::Node>> > ()));
        driver.ast_builder->break_out_of_scope();
    }
#line 1163 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 14:
#line 196 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_generic_class_definition(yystack_[2].value.as < std::pair< std::string,std::vector<std::unique_ptr<ast::Node>>>  > ().first,std::move(yystack_[2].value.as < std::pair< std::string,std::vector<std::unique_ptr<ast::Node>>>  > ().second),std::move(yystack_[0].value.as < std::vector<std::unique_ptr<ast::Node>> > ()),{});
        driver.ast_builder->break_out_of_scope();
    }
#line 1172 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 15:
#line 201 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_generic_class_definition(yystack_[2].value.as < std::pair< std::string,std::vector<std::unique_ptr<ast::Node>>>  > ().first,std::move(yystack_[2].value.as < std::pair< std::string,std::vector<std::unique_ptr<ast::Node>>>  > ().second),{},std::move(yystack_[0].value.as < std::vector<std::unique_ptr<ast::Node>> > ()));
        driver.ast_builder->break_out_of_scope();
    }
#line 1181 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 16:
#line 207 "./src/lib/blawn/parser/parser.yy"
    {
        auto name = yystack_[0].value.as < std::unique_ptr<blawn::DeclarationInfo> > ()->name;
        driver.ast_builder->into_named_scope(name);
        std::vector<std::unique_ptr<ast::Node>> arguments;
        for (auto& arg_name:yystack_[0].value.as < std::unique_ptr<blawn::DeclarationInfo> > ()->argument_names)
        {
            arguments.push_back(driver.ast_builder->create_argument(arg_name));
        }
        driver.ast_builder->break_out_of_scope();
        driver.ast_builder->create_generic_function_declaration(name,std::move(arguments));
        driver.ast_builder->into_named_scope(name);
        yylhs.value.as < std::pair< std::string,std::vector<std::unique_ptr<ast::Node>>>  > () = {name,std::move(arguments)};
    }
#line 1199 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 17:
#line 222 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::unique_ptr<ast::Node>> > ().push_back(std::move(yystack_[1].value.as < std::unique_ptr<ast::Node> > ()));
    }
#line 1207 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 18:
#line 226 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::unique_ptr<ast::Node>> > () = std::move(yystack_[2].value.as < std::vector<std::unique_ptr<ast::Node>> > ());
        yylhs.value.as < std::vector<std::unique_ptr<ast::Node>> > ().push_back(std::move(yystack_[1].value.as < std::unique_ptr<ast::Node> > ()));
    }
#line 1216 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 19:
#line 232 "./src/lib/blawn/parser/parser.yy"
    {
        auto name = yystack_[0].value.as < std::unique_ptr<blawn::DeclarationInfo> > ()->name;
        driver.ast_builder->into_named_scope(name);
        std::vector<std::unique_ptr<ast::Node>> arguments;
        arguments.push_back(driver.ast_builder->create_argument("self"));
        for (auto& arg_name:yystack_[0].value.as < std::unique_ptr<blawn::DeclarationInfo> > ()->argument_names)
        {
            arguments.push_back(driver.ast_builder->create_argument(arg_name));
        }
        driver.ast_builder->break_out_of_scope();
        driver.ast_builder->create_generic_function_declaration(name,std::move(arguments));
        driver.ast_builder->into_named_scope(name);
        yylhs.value.as < std::pair< std::string,std::vector<std::unique_ptr<ast::Node>>>  > () = {name,std::move(arguments)};
    }
#line 1235 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 20:
#line 248 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_generic_function_definition(yystack_[4].value.as < std::pair< std::string,std::vector<std::unique_ptr<ast::Node>>>  > ().first,std::move(yystack_[4].value.as < std::pair< std::string,std::vector<std::unique_ptr<ast::Node>>>  > ().second),std::move(yystack_[1].value.as < std::unique_ptr<ast::Node> > ()));
        driver.ast_builder->break_out_of_scope();
    }
#line 1244 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 21:
#line 254 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::unique_ptr<ast::Node>> > ().push_back(driver.ast_builder->create_member_variable_definition(yystack_[3].value.as < std::string > (),std::move(yystack_[1].value.as < std::unique_ptr<ast::Node> > ())));
    }
#line 1252 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 22:
#line 258 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::unique_ptr<ast::Node>> > () = std::move(yystack_[4].value.as < std::vector<std::unique_ptr<ast::Node>> > ());
        yylhs.value.as < std::vector<std::unique_ptr<ast::Node>> > ().push_back(driver.ast_builder->create_member_variable_definition(yystack_[3].value.as < std::string > (),std::move(yystack_[1].value.as < std::unique_ptr<ast::Node> > ())));
    }
#line 1261 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 23:
#line 265 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::unique_ptr<ast::Node>> > ().push_back(std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ()));
    }
#line 1269 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 24:
#line 269 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::unique_ptr<ast::Node>> > () = std::move(yystack_[2].value.as < std::vector<std::unique_ptr<ast::Node>> > ());
        yylhs.value.as < std::vector<std::unique_ptr<ast::Node>> > ().push_back(std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ()));
    }
#line 1278 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 25:
#line 275 "./src/lib/blawn/parser/parser.yy"
    {
        driver.ast_builder->into_anonymous_scope();
    }
#line 1286 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 26:
#line 280 "./src/lib/blawn/parser/parser.yy"
    {
        driver.ast_builder->into_anonymous_scope();
    }
#line 1294 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 27:
#line 285 "./src/lib/blawn/parser/parser.yy"
    {
        driver.ast_builder->into_anonymous_scope();
        yylhs.value.as < std::vector<std::unique_ptr<ast::Node>> > ().push_back(std::move(yystack_[4].value.as < std::unique_ptr<ast::Node> > ()));
        yylhs.value.as < std::vector<std::unique_ptr<ast::Node>> > ().push_back(std::move(yystack_[2].value.as < std::unique_ptr<ast::Node> > ()));
        yylhs.value.as < std::vector<std::unique_ptr<ast::Node>> > ().push_back(std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ()));
    }
#line 1305 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 28:
#line 294 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = std::move(yystack_[1].value.as < std::unique_ptr<ast::Node> > ());
        driver.ast_builder->break_out_of_scope();
    }
#line 1314 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 29:
#line 300 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ());
    }
#line 1322 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 30:
#line 304 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ());
    }
#line 1330 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 31:
#line 308 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_if(std::move(yystack_[4].value.as < std::unique_ptr<ast::Node> > ()),std::move(yystack_[1].value.as < std::unique_ptr<ast::Node> > ()),{});
        driver.ast_builder->break_out_of_scope();
    }
#line 1339 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 32:
#line 313 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_if(std::move(yystack_[5].value.as < std::unique_ptr<ast::Node> > ()),std::move(yystack_[2].value.as < std::unique_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ()));
        //driver.ast_builder->break_out_of_scope();
    }
#line 1348 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 33:
#line 318 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_for(std::move(yystack_[4].value.as < std::vector<std::unique_ptr<ast::Node>> > ()[0]),std::move(yystack_[4].value.as < std::vector<std::unique_ptr<ast::Node>> > ()[1]),std::move(yystack_[4].value.as < std::vector<std::unique_ptr<ast::Node>> > ()[2]),std::move(yystack_[1].value.as < std::unique_ptr<ast::Node> > ()));
        driver.ast_builder->break_out_of_scope();
    }
#line 1357 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 34:
#line 323 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ());
    }
#line 1365 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 35:
#line 327 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ());
    }
#line 1373 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 36:
#line 331 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_deep_copy(std::move(yystack_[2].value.as < std::unique_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ()));
    }
#line 1381 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 37:
#line 335 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_binary_expression(std::move(yystack_[2].value.as < std::unique_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ()),"ADD");
    }
#line 1389 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 38:
#line 339 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_binary_expression(std::move(yystack_[2].value.as < std::unique_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ()),"SUB");
    }
#line 1397 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 39:
#line 343 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_binary_expression(std::move(yystack_[2].value.as < std::unique_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ()),"MUL");
    }
#line 1405 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 40:
#line 347 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_binary_expression(std::move(yystack_[2].value.as < std::unique_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ()),"DIV");
    }
#line 1413 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 41:
#line 351 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_binary_expression(std::move(yystack_[2].value.as < std::unique_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ()),"and");
    }
#line 1421 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 42:
#line 355 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_binary_expression(std::move(yystack_[2].value.as < std::unique_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ()),"or");
    }
#line 1429 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 43:
#line 359 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_binary_expression(std::move(yystack_[2].value.as < std::unique_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ()),">=");
    }
#line 1437 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 44:
#line 363 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_binary_expression(std::move(yystack_[2].value.as < std::unique_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ()),"<=");
    }
#line 1445 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 45:
#line 367 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_binary_expression(std::move(yystack_[2].value.as < std::unique_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ()),">");
    }
#line 1453 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 46:
#line 371 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_binary_expression(std::move(yystack_[2].value.as < std::unique_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ()),"<");
    }
#line 1461 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 47:
#line 375 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_binary_expression(std::move(yystack_[2].value.as < std::unique_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ()),"!=");
    }
#line 1469 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 48:
#line 379 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_binary_expression(std::move(yystack_[2].value.as < std::unique_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ()),"==");
    }
#line 1477 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 49:
#line 383 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ());
    }
#line 1485 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 50:
#line 387 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ());
    }
#line 1493 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 51:
#line 391 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ());
    }
#line 1501 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 52:
#line 395 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_minus(std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ()));
    }
#line 1509 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 53:
#line 399 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = std::move(yystack_[1].value.as < std::unique_ptr<ast::Node> > ());
    }
#line 1517 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 54:
#line 404 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_array();
    }
#line 1525 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 55:
#line 409 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_access(std::move(yystack_[1].value.as < std::unique_ptr<ast::Node> > ()),yystack_[0].value.as < std::string > ());
    }
#line 1533 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 56:
#line 414 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_global_variable_definition(yystack_[2].value.as < std::string > (),std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ()));
    }
#line 1541 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 57:
#line 419 "./src/lib/blawn/parser/parser.yy"
    {
        if (driver.ast_builder->exist_named_expression(yystack_[2].value.as < std::string > ()))
        {
            auto named_expression = driver.ast_builder->create_named_node(yystack_[2].value.as < std::string > ());
            yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_assignment(std::move(named_expression),std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ()));
        }
        else
        {
            yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_variable_definition(yystack_[2].value.as < std::string > (),std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ()));
        }
    }
#line 1557 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 58:
#line 431 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_assignment(std::move(yystack_[2].value.as < std::unique_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ()));
    }
#line 1565 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 59:
#line 436 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ());
    }
#line 1573 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 60:
#line 441 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ());
    }
#line 1581 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 61:
#line 445 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_string(yystack_[0].value.as < std::string > ());
    }
#line 1589 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 62:
#line 449 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_float(yystack_[0].value.as < double > ());
    }
#line 1597 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 63:
#line 453 "./src/lib/blawn/parser/parser.yy"
    { 
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_integer(yystack_[0].value.as < long long > ());
    }
#line 1605 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 64:
#line 457 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_lazy();
    }
#line 1613 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 65:
#line 461 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = std::move(yystack_[0].value.as < std::unique_ptr<ast::Node> > ());
    }
#line 1621 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 66:
#line 467 "./src/lib/blawn/parser/parser.yy"
    {
        if (driver.ast_builder->exist_named_expression(yystack_[3].value.as < std::string > ()))
        {
            auto function_object = driver.ast_builder->create_named_node(yystack_[3].value.as < std::string > ());
            yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_call(std::move(function_object),std::move(yystack_[1].value.as < std::vector<std::unique_ptr<ast::Node>> > ()));
        }
        else
        {
            yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_call(yystack_[3].value.as < std::string > (),std::move(yystack_[1].value.as < std::vector<std::unique_ptr<ast::Node>> > ()));
        }
    }
#line 1637 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 67:
#line 479 "./src/lib/blawn/parser/parser.yy"
    {
        if (driver.ast_builder->exist_named_expression(yystack_[2].value.as < std::string > ()))
        {
            auto function_object = driver.ast_builder->create_named_node(yystack_[2].value.as < std::string > ());
            yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_call(std::move(function_object),{});
        }
        else
        {
            yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_call(yystack_[2].value.as < std::string > (),{});
        }
    }
#line 1653 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 68:
#line 491 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_call(std::move(yystack_[3].value.as < std::unique_ptr<ast::Node> > ()),std::move(yystack_[1].value.as < std::vector<std::unique_ptr<ast::Node>> > ()));
    }
#line 1661 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 69:
#line 495 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_call(std::move(yystack_[2].value.as < std::unique_ptr<ast::Node> > ()),{});
    }
#line 1669 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 70:
#line 500 "./src/lib/blawn/parser/parser.yy"
    {
        yylhs.value.as < std::unique_ptr<ast::Node> > () = driver.ast_builder->create_named_node(yystack_[0].value.as < std::string > ());
    }
#line 1677 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;


#line 1681 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"

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


  const signed char Parser::yypact_ninf_ = -74;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
     191,     7,   191,     1,   191,   191,   -74,   -74,   -74,   -74,
     191,    19,   -74,   -74,   -74,    24,   191,   -74,   -74,   -74,
     -22,   -74,   -21,   191,   -20,   104,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   131,   191,   320,   -74,   303,     9,
     259,    13,   -74,   -74,    17,     2,   226,    26,   -74,   148,
     191,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   -74,   -74,   -74,   -74,    -7,   320,
     242,   -74,   191,   191,   191,    27,   -74,    11,    -3,    15,
       6,    31,   191,   -74,    -6,   242,   242,   185,   185,   -14,
     -14,   -14,   -14,   -14,   -14,   -10,   -10,     9,     9,   -74,
     191,   281,   242,    28,   191,   191,    15,    32,   -74,    50,
      11,   191,    53,   -74,   320,   191,   -74,   104,   -74,   191,
     191,    54,   -74,   320,   -74,    55,   104,    35,   -74,   -74,
     -74,    22,   -74,    61,   191,    63,   -74
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,    70,     0,     0,     0,     0,    12,    16,    64,    25,
       0,     0,    61,    63,    62,     0,     2,     6,    29,     9,
       0,    10,     0,     0,     0,     0,    50,    51,    35,    34,
      30,    49,    60,    65,     0,     0,    59,    54,     0,    52,
       0,     0,     1,     7,     0,     0,     0,     0,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,     4,     8,    67,     0,    23,
      57,    53,     0,     0,     0,     0,    19,    15,     0,     0,
      14,     0,     0,    69,     0,    58,    36,    41,    42,    48,
      47,    43,    44,    45,    46,    37,    38,    39,    40,    66,
       0,     0,    56,     0,     3,     0,     0,     0,    17,     0,
      13,     0,     0,    68,    24,     0,    11,     0,    18,     0,
       0,     0,    33,    27,    21,     0,     0,    31,    20,    22,
      26,     0,    32,     0,     0,     0,    28
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -74,   -74,   -47,   -43,    77,   -15,   -74,   -74,   -74,   -74,
     -74,    -1,   -74,   -73,   -74,    29,   -74,   -74,   -74,   -74,
      -2,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,    15,   103,    66,   104,    17,    18,    19,    20,    21,
      22,    77,    78,    79,    80,    68,    23,   131,    24,   132,
      25,    26,    27,    28,    29,    30,    31,    32,    33
  };

  const unsigned char
  Parser::yytable_[] =
  {
      36,    43,    38,    39,   106,    75,    99,   113,    40,   109,
      37,    60,    61,    62,    63,    48,    64,    62,    63,    34,
      64,    46,    35,    41,    42,    44,    45,    47,    73,   100,
     100,    74,    69,    70,    76,   112,   108,   106,    76,    64,
      82,   116,   105,    76,   107,   111,   119,    69,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    65,   118,   121,   120,   122,   127,   128,   133,
     101,   102,   125,   130,   124,   134,   136,    16,    84,   110,
       0,     0,     0,   129,     0,     0,     0,   135,     0,    43,
       0,     0,     0,     0,     0,     0,     0,     0,   114,     0,
       0,     0,     0,   117,    48,     0,     0,     0,     0,     0,
       0,     0,     0,   123,     0,     0,    49,     0,   126,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     0,    64,     1,     2,     0,     0,     3,
       0,     0,     0,     4,    67,     0,     0,     0,     0,     0,
       0,    65,     1,     2,     0,     0,     3,     5,     0,     0,
       4,    83,     6,     0,     7,     0,     8,     0,     9,     0,
      10,     0,     0,    11,     5,    12,    13,    14,     0,     6,
       0,     7,     0,     8,     0,     9,     0,    10,     0,     0,
      11,     0,    12,    13,    14,     1,     2,     0,     0,     3,
       0,     0,     0,     4,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     0,    64,     0,     5,     0,     0,
       0,     0,     6,     0,     7,     0,     8,     0,     9,     0,
      10,     0,     0,    11,     0,    12,    13,    14,    49,     0,
       0,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,     0,    64,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    49,    64,    81,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,     0,    64,
       0,     0,     0,    49,     0,    72,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
       0,    64,     0,     0,     0,    49,    71,   115,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    49,    64,     0,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,     0,
      64
  };

  const short
  Parser::yycheck_[] =
  {
       2,    16,     4,     5,    77,     3,    13,    13,    10,     3,
       9,    25,    26,    27,    28,     0,    30,    27,    28,    12,
      30,    23,    15,     4,     0,    47,    47,    47,    15,    36,
      36,    14,    34,    35,    32,    82,    79,   110,    32,    30,
      14,    13,    15,    32,    47,    14,    14,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    47,   106,   111,    15,    13,    13,    13,    47,
      72,    73,   119,    38,   117,    14,    13,     0,    49,    80,
      -1,    -1,    -1,   126,    -1,    -1,    -1,   134,    -1,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,
      -1,    -1,    -1,   105,     0,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,    -1,    -1,    12,    -1,   120,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,     4,     5,    -1,    -1,     8,
      -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    47,     4,     5,    -1,    -1,     8,    26,    -1,    -1,
      12,    13,    31,    -1,    33,    -1,    35,    -1,    37,    -1,
      39,    -1,    -1,    42,    26,    44,    45,    46,    -1,    31,
      -1,    33,    -1,    35,    -1,    37,    -1,    39,    -1,    -1,
      42,    -1,    44,    45,    46,     4,     5,    -1,    -1,     8,
      -1,    -1,    -1,    12,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    -1,    26,    -1,    -1,
      -1,    -1,    31,    -1,    33,    -1,    35,    -1,    37,    -1,
      39,    -1,    -1,    42,    -1,    44,    45,    46,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    12,    30,    47,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      -1,    -1,    -1,    12,    -1,    36,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    -1,    -1,    -1,    12,    13,    36,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    12,    30,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     4,     5,     8,    12,    26,    31,    33,    35,    37,
      39,    42,    44,    45,    46,    49,    52,    53,    54,    55,
      56,    57,    58,    64,    66,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    12,    15,    68,     9,    68,    68,
      68,     4,     0,    53,    47,    47,    68,    47,     0,    12,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    30,    47,    51,    13,    63,    68,
      68,    13,    36,    15,    14,     3,    32,    59,    60,    61,
      62,    47,    14,    13,    63,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    13,
      36,    68,    68,    50,    52,    15,    61,    47,    51,     3,
      59,    14,    50,    13,    68,    36,    13,    68,    51,    14,
      15,    50,    13,    68,    51,    50,    68,    13,    13,    51,
      38,    65,    67,    47,    14,    50,    13
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    48,    49,    50,    51,    51,    52,    52,    53,    54,
      54,    55,    56,    57,    57,    57,    58,    59,    59,    60,
      61,    62,    62,    63,    63,    64,    65,    66,    67,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    69,    70,    71,    72,    72,    73,
      74,    74,    74,    74,    74,    74,    75,    75,    75,    75,
      76
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     5,     1,     4,     3,     3,     1,     2,     3,     1,
       5,     4,     5,     1,     3,     1,     1,     6,     5,     1,
       1,     6,     7,     5,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     2,     3,     2,     2,     4,     3,     3,     2,
       1,     1,     1,     1,     1,     1,     4,     3,     4,     3,
       1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "MEMBER_IDENTIFIER",
  "IDENTIFIER", "RETURN", "COLON", "SEMICOLON", "LEFT_BRACKET",
  "RIGHT_BRACKET", "LEFT_CURLY_BRACE", "RIGHT_CURLY_BRACE",
  "LEFT_PARENTHESIS", "RIGHT_PARENTHESIS", "LEFT_PARENTHESIS_AND_EOL",
  "EQUAL", "ARROW", "OP_AND", "OP_OR", "OP_EQUAL", "OP_NOT_EQUAL",
  "OP_MORE_EQUAL", "OP_LESS_EQUAL", "OP_MORE", "OP_LESS", "PLUS", "MINUS",
  "ASTERISK", "SLASH", "UMINUS", "DOT_IDENTIFIER", "FUNCTION_DEFINITION",
  "METHOD_DEFINITION", "CLASS_DEFINITION", "USE", "LAZY", "COMMA", "IF",
  "ELSE", "FOR", "IN", "WHILE", "GLOBAL", "IMPORT", "STRING_LITERAL",
  "INT_LITERAL", "FLOAT_LITERAL", "EOL", "$accept", "program", "block",
  "EOL_OR_EOF", "lines", "line", "definition", "function_definition",
  "function_start", "class_definition", "class_start", "methods",
  "method_start", "method_definition", "members_definition", "expressions",
  "if_start", "else_start", "for_start", "else_body", "expression",
  "array", "access", "global_variable_definition", "assign_variable",
  "return_value", "monomial", "call", "named_value", YY_NULLPTR
  };


  const short
  Parser::yyrline_[] =
  {
       0,   132,   132,   138,   142,   142,   145,   149,   155,   160,
     164,   169,   175,   190,   195,   200,   206,   221,   225,   231,
     247,   253,   257,   264,   268,   274,   279,   284,   293,   299,
     303,   307,   312,   317,   322,   326,   330,   334,   338,   342,
     346,   350,   354,   358,   362,   366,   370,   374,   378,   382,
     386,   390,   394,   398,   403,   408,   413,   418,   430,   435,
     440,   444,   448,   452,   456,   460,   466,   478,   490,   494,
     499
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
      45,    46,    47
    };
    const int user_token_number_max_ = 302;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 5 "./src/lib/blawn/parser/parser.yy"
} // blawn
#line 2168 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"

#line 503 "./src/lib/blawn/parser/parser.yy"


void blawn::Parser::error( const location_type &l, const std::string &err_message )
{
    auto debug_info = driver.ast_builder->create_current_debug_info();
    auto& token_info = debug_info.get_token_info();
    //auto& scope = debug_info.get_scope_id();
    auto& filename = debug_info.get_filename();
    std::cerr << "Error at '" <<
    token_info.get_token_string() <<
    "' in line " << token_info.get_line_number() << " in file '"
    << filename << "'" << std::endl;
    exit(1);
} 
