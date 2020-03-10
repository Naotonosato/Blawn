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
      case 45: // FLOAT_LITERAL
        value.move< double > (std::move (that.value));
        break;

      case 44: // INT_LITERAL
        value.move< long long > (std::move (that.value));
        break;

      case 54: // function_name_and_argument_names
      case 56: // class_name_and_argument_names
      case 58: // method_name_and_argument_names
        value.move< std::pair<std::string,std::vector<std::string>> > (std::move (that.value));
        break;

      case 48: // block
      case 50: // line
      case 51: // line_content
      case 52: // definition
      case 53: // function_definition
      case 55: // class_definition
      case 59: // method_definition
      case 61: // return_value
      case 64: // globals_definition
      case 71: // else_body
      case 72: // expression
      case 73: // list
      case 74: // access
      case 75: // assign_variable
      case 76: // monomial
      case 77: // call
      case 78: // variable
        value.move< std::shared_ptr<ast::Node> > (std::move (that.value));
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 7: // MEMBER_IDENTIFIER
      case 8: // IDENTIFIER
      case 24: // DOT_IDENTIFIER
      case 43: // STRING_LITERAL
        value.move< std::string > (std::move (that.value));
        break;

      case 49: // lines
      case 57: // methods
      case 60: // members_definition
      case 66: // globals_variables
      case 67: // expressions
      case 70: // for_start
        value.move< std::vector<std::shared_ptr<ast::Node>> > (std::move (that.value));
        break;

      case 62: // arguments
      case 63: // definition_arguments
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
      case 45: // FLOAT_LITERAL
        value.copy< double > (YY_MOVE (that.value));
        break;

      case 44: // INT_LITERAL
        value.copy< long long > (YY_MOVE (that.value));
        break;

      case 54: // function_name_and_argument_names
      case 56: // class_name_and_argument_names
      case 58: // method_name_and_argument_names
        value.copy< std::pair<std::string,std::vector<std::string>> > (YY_MOVE (that.value));
        break;

      case 48: // block
      case 50: // line
      case 51: // line_content
      case 52: // definition
      case 53: // function_definition
      case 55: // class_definition
      case 59: // method_definition
      case 61: // return_value
      case 64: // globals_definition
      case 71: // else_body
      case 72: // expression
      case 73: // list
      case 74: // access
      case 75: // assign_variable
      case 76: // monomial
      case 77: // call
      case 78: // variable
        value.copy< std::shared_ptr<ast::Node> > (YY_MOVE (that.value));
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 7: // MEMBER_IDENTIFIER
      case 8: // IDENTIFIER
      case 24: // DOT_IDENTIFIER
      case 43: // STRING_LITERAL
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case 49: // lines
      case 57: // methods
      case 60: // members_definition
      case 66: // globals_variables
      case 67: // expressions
      case 70: // for_start
        value.copy< std::vector<std::shared_ptr<ast::Node>> > (YY_MOVE (that.value));
        break;

      case 62: // arguments
      case 63: // definition_arguments
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
      case 45: // FLOAT_LITERAL
        value.move< double > (YY_MOVE (s.value));
        break;

      case 44: // INT_LITERAL
        value.move< long long > (YY_MOVE (s.value));
        break;

      case 54: // function_name_and_argument_names
      case 56: // class_name_and_argument_names
      case 58: // method_name_and_argument_names
        value.move< std::pair<std::string,std::vector<std::string>> > (YY_MOVE (s.value));
        break;

      case 48: // block
      case 50: // line
      case 51: // line_content
      case 52: // definition
      case 53: // function_definition
      case 55: // class_definition
      case 59: // method_definition
      case 61: // return_value
      case 64: // globals_definition
      case 71: // else_body
      case 72: // expression
      case 73: // list
      case 74: // access
      case 75: // assign_variable
      case 76: // monomial
      case 77: // call
      case 78: // variable
        value.move< std::shared_ptr<ast::Node> > (YY_MOVE (s.value));
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 7: // MEMBER_IDENTIFIER
      case 8: // IDENTIFIER
      case 24: // DOT_IDENTIFIER
      case 43: // STRING_LITERAL
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case 49: // lines
      case 57: // methods
      case 60: // members_definition
      case 66: // globals_variables
      case 67: // expressions
      case 70: // for_start
        value.move< std::vector<std::shared_ptr<ast::Node>> > (YY_MOVE (s.value));
        break;

      case 62: // arguments
      case 63: // definition_arguments
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
      case 45: // FLOAT_LITERAL
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case 44: // INT_LITERAL
        value.YY_MOVE_OR_COPY< long long > (YY_MOVE (that.value));
        break;

      case 54: // function_name_and_argument_names
      case 56: // class_name_and_argument_names
      case 58: // method_name_and_argument_names
        value.YY_MOVE_OR_COPY< std::pair<std::string,std::vector<std::string>> > (YY_MOVE (that.value));
        break;

      case 48: // block
      case 50: // line
      case 51: // line_content
      case 52: // definition
      case 53: // function_definition
      case 55: // class_definition
      case 59: // method_definition
      case 61: // return_value
      case 64: // globals_definition
      case 71: // else_body
      case 72: // expression
      case 73: // list
      case 74: // access
      case 75: // assign_variable
      case 76: // monomial
      case 77: // call
      case 78: // variable
        value.YY_MOVE_OR_COPY< std::shared_ptr<ast::Node> > (YY_MOVE (that.value));
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 7: // MEMBER_IDENTIFIER
      case 8: // IDENTIFIER
      case 24: // DOT_IDENTIFIER
      case 43: // STRING_LITERAL
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 49: // lines
      case 57: // methods
      case 60: // members_definition
      case 66: // globals_variables
      case 67: // expressions
      case 70: // for_start
        value.YY_MOVE_OR_COPY< std::vector<std::shared_ptr<ast::Node>> > (YY_MOVE (that.value));
        break;

      case 62: // arguments
      case 63: // definition_arguments
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
      case 45: // FLOAT_LITERAL
        value.move< double > (YY_MOVE (that.value));
        break;

      case 44: // INT_LITERAL
        value.move< long long > (YY_MOVE (that.value));
        break;

      case 54: // function_name_and_argument_names
      case 56: // class_name_and_argument_names
      case 58: // method_name_and_argument_names
        value.move< std::pair<std::string,std::vector<std::string>> > (YY_MOVE (that.value));
        break;

      case 48: // block
      case 50: // line
      case 51: // line_content
      case 52: // definition
      case 53: // function_definition
      case 55: // class_definition
      case 59: // method_definition
      case 61: // return_value
      case 64: // globals_definition
      case 71: // else_body
      case 72: // expression
      case 73: // list
      case 74: // access
      case 75: // assign_variable
      case 76: // monomial
      case 77: // call
      case 78: // variable
        value.move< std::shared_ptr<ast::Node> > (YY_MOVE (that.value));
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 7: // MEMBER_IDENTIFIER
      case 8: // IDENTIFIER
      case 24: // DOT_IDENTIFIER
      case 43: // STRING_LITERAL
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 49: // lines
      case 57: // methods
      case 60: // members_definition
      case 66: // globals_variables
      case 67: // expressions
      case 70: // for_start
        value.move< std::vector<std::shared_ptr<ast::Node>> > (YY_MOVE (that.value));
        break;

      case 62: // arguments
      case 63: // definition_arguments
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
      case 45: // FLOAT_LITERAL
        value.copy< double > (that.value);
        break;

      case 44: // INT_LITERAL
        value.copy< long long > (that.value);
        break;

      case 54: // function_name_and_argument_names
      case 56: // class_name_and_argument_names
      case 58: // method_name_and_argument_names
        value.copy< std::pair<std::string,std::vector<std::string>> > (that.value);
        break;

      case 48: // block
      case 50: // line
      case 51: // line_content
      case 52: // definition
      case 53: // function_definition
      case 55: // class_definition
      case 59: // method_definition
      case 61: // return_value
      case 64: // globals_definition
      case 71: // else_body
      case 72: // expression
      case 73: // list
      case 74: // access
      case 75: // assign_variable
      case 76: // monomial
      case 77: // call
      case 78: // variable
        value.copy< std::shared_ptr<ast::Node> > (that.value);
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 7: // MEMBER_IDENTIFIER
      case 8: // IDENTIFIER
      case 24: // DOT_IDENTIFIER
      case 43: // STRING_LITERAL
        value.copy< std::string > (that.value);
        break;

      case 49: // lines
      case 57: // methods
      case 60: // members_definition
      case 66: // globals_variables
      case 67: // expressions
      case 70: // for_start
        value.copy< std::vector<std::shared_ptr<ast::Node>> > (that.value);
        break;

      case 62: // arguments
      case 63: // definition_arguments
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
      case 45: // FLOAT_LITERAL
        value.move< double > (that.value);
        break;

      case 44: // INT_LITERAL
        value.move< long long > (that.value);
        break;

      case 54: // function_name_and_argument_names
      case 56: // class_name_and_argument_names
      case 58: // method_name_and_argument_names
        value.move< std::pair<std::string,std::vector<std::string>> > (that.value);
        break;

      case 48: // block
      case 50: // line
      case 51: // line_content
      case 52: // definition
      case 53: // function_definition
      case 55: // class_definition
      case 59: // method_definition
      case 61: // return_value
      case 64: // globals_definition
      case 71: // else_body
      case 72: // expression
      case 73: // list
      case 74: // access
      case 75: // assign_variable
      case 76: // monomial
      case 77: // call
      case 78: // variable
        value.move< std::shared_ptr<ast::Node> > (that.value);
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 7: // MEMBER_IDENTIFIER
      case 8: // IDENTIFIER
      case 24: // DOT_IDENTIFIER
      case 43: // STRING_LITERAL
        value.move< std::string > (that.value);
        break;

      case 49: // lines
      case 57: // methods
      case 60: // members_definition
      case 66: // globals_variables
      case 67: // expressions
      case 70: // for_start
        value.move< std::vector<std::shared_ptr<ast::Node>> > (that.value);
        break;

      case 62: // arguments
      case 63: // definition_arguments
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
      case 45: // FLOAT_LITERAL
        yylhs.value.emplace< double > ();
        break;

      case 44: // INT_LITERAL
        yylhs.value.emplace< long long > ();
        break;

      case 54: // function_name_and_argument_names
      case 56: // class_name_and_argument_names
      case 58: // method_name_and_argument_names
        yylhs.value.emplace< std::pair<std::string,std::vector<std::string>> > ();
        break;

      case 48: // block
      case 50: // line
      case 51: // line_content
      case 52: // definition
      case 53: // function_definition
      case 55: // class_definition
      case 59: // method_definition
      case 61: // return_value
      case 64: // globals_definition
      case 71: // else_body
      case 72: // expression
      case 73: // list
      case 74: // access
      case 75: // assign_variable
      case 76: // monomial
      case 77: // call
      case 78: // variable
        yylhs.value.emplace< std::shared_ptr<ast::Node> > ();
        break;

      case 3: // FUNCTION_DEFINITION
      case 4: // METHOD_DEFINITION
      case 5: // CLASS_DEFINITION
      case 7: // MEMBER_IDENTIFIER
      case 8: // IDENTIFIER
      case 24: // DOT_IDENTIFIER
      case 43: // STRING_LITERAL
        yylhs.value.emplace< std::string > ();
        break;

      case 49: // lines
      case 57: // methods
      case 60: // members_definition
      case 66: // globals_variables
      case 67: // expressions
      case 70: // for_start
        yylhs.value.emplace< std::vector<std::shared_ptr<ast::Node>> > ();
        break;

      case 62: // arguments
      case 63: // definition_arguments
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
#line 146 "./src/compiler/parser/parser.yy"
    {
        driver.ast_builder->break_out_of_scope();
        driver.ast_builder->set_all_program(std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()));
    }
#line 1108 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 3:
#line 152 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_block(std::move(yystack_[0].value.as < std::vector<std::shared_ptr<ast::Node>> > ()));
    }
#line 1116 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 4:
#line 157 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > ().push_back(std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()));
    }
#line 1124 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 5:
#line 161 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > () = std::move(yystack_[1].value.as < std::vector<std::shared_ptr<ast::Node>> > ());
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > ().push_back(yystack_[0].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1133 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 6:
#line 167 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = std::move(yystack_[1].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1141 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 7:
#line 171 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = std::move(yystack_[1].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1149 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 8:
#line 175 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = yystack_[0].value.as < std::shared_ptr<ast::Node> > ();
    }
#line 1157 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 9:
#line 181 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1165 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 10:
#line 186 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1173 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 11:
#line 190 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1181 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 12:
#line 194 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1189 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 13:
#line 199 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_generic_function_definition(yystack_[4].value.as < std::pair<std::string,std::vector<std::string>> > ().first,std::move(yystack_[4].value.as < std::pair<std::string,std::vector<std::string>> > ().second),std::move(yystack_[2].value.as < std::shared_ptr<ast::Node> > ()),std::move(yystack_[1].value.as < std::shared_ptr<ast::Node> > ()));
        driver.ast_builder->break_out_of_scope();
    }
#line 1198 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 14:
#line 204 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_generic_function_definition(yystack_[3].value.as < std::pair<std::string,std::vector<std::string>> > ().first,std::move(yystack_[3].value.as < std::pair<std::string,std::vector<std::string>> > ().second),{},std::move(yystack_[1].value.as < std::shared_ptr<ast::Node> > ()));
        driver.ast_builder->break_out_of_scope();
    }
#line 1207 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 15:
#line 210 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::pair<std::string,std::vector<std::string>> > () = std::make_pair(yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::vector<std::string> > ());
        driver.ast_builder->create_generic_function_declaration(yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::vector<std::string> > ());
        driver.ast_builder->into_named_scope(yystack_[1].value.as < std::string > ());
    }
#line 1217 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 16:
#line 217 "./src/compiler/parser/parser.yy"
    { 
        yylhs.value.as < std::shared_ptr<ast::Node> > () = std::move(driver.ast_builder->create_generic_class_definition(yystack_[3].value.as < std::pair<std::string,std::vector<std::string>> > ().first,std::move(yystack_[3].value.as < std::pair<std::string,std::vector<std::string>> > ().second),yystack_[1].value.as < std::vector<std::shared_ptr<ast::Node>> > (),yystack_[0].value.as < std::vector<std::shared_ptr<ast::Node>> > ()));
        driver.ast_builder->break_out_of_scope();
    }
#line 1226 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 17:
#line 222 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = std::move(driver.ast_builder->create_generic_class_definition(yystack_[2].value.as < std::pair<std::string,std::vector<std::string>> > ().first,std::move(yystack_[2].value.as < std::pair<std::string,std::vector<std::string>> > ().second),yystack_[0].value.as < std::vector<std::shared_ptr<ast::Node>> > (),{}));
        driver.ast_builder->break_out_of_scope();
    }
#line 1235 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 18:
#line 227 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = std::move(driver.ast_builder->create_generic_class_definition(yystack_[2].value.as < std::pair<std::string,std::vector<std::string>> > ().first,std::move(yystack_[2].value.as < std::pair<std::string,std::vector<std::string>> > ().second),{},yystack_[0].value.as < std::vector<std::shared_ptr<ast::Node>> > ()));
        driver.ast_builder->break_out_of_scope();
    }
#line 1244 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 19:
#line 233 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::pair<std::string,std::vector<std::string>> > () = std::make_pair(yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::vector<std::string> > ());
        driver.ast_builder->create_generic_class_declaration(yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::vector<std::string> > ());
        driver.ast_builder->into_named_scope(yystack_[1].value.as < std::string > ());
    }
#line 1254 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 20:
#line 240 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > ().push_back(yystack_[1].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1262 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 21:
#line 244 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > () = std::move(yystack_[2].value.as < std::vector<std::shared_ptr<ast::Node>> > ());
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > ().push_back(yystack_[1].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1271 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 22:
#line 250 "./src/compiler/parser/parser.yy"
    {
        yystack_[0].value.as < std::vector<std::string> > ().insert(yystack_[0].value.as < std::vector<std::string> > ().begin(),"self");
        yylhs.value.as < std::pair<std::string,std::vector<std::string>> > () = std::make_pair(yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::vector<std::string> > ());
        driver.ast_builder->create_generic_function_declaration(yystack_[1].value.as < std::string > (),yystack_[0].value.as < std::vector<std::string> > ());
        driver.ast_builder->into_named_scope(yystack_[1].value.as < std::string > ());
    }
#line 1282 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 23:
#line 258 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_generic_function_definition(yystack_[3].value.as < std::pair<std::string,std::vector<std::string>> > ().first,std::move(yystack_[3].value.as < std::pair<std::string,std::vector<std::string>> > ().second),std::move(yystack_[1].value.as < std::shared_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()));
        driver.ast_builder->break_out_of_scope();
    }
#line 1291 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 24:
#line 263 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_generic_function_definition(yystack_[2].value.as < std::pair<std::string,std::vector<std::string>> > ().first,std::move(yystack_[2].value.as < std::pair<std::string,std::vector<std::string>> > ().second),{},std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()));
        driver.ast_builder->break_out_of_scope();
    }
#line 1300 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 25:
#line 269 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > ().push_back(driver.ast_builder->create_member_variable_definition(yystack_[3].value.as < std::string > (),std::move(yystack_[1].value.as < std::shared_ptr<ast::Node> > ())));
    }
#line 1308 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 26:
#line 273 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > () = std::move(yystack_[4].value.as < std::vector<std::shared_ptr<ast::Node>> > ());
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > ().push_back(driver.ast_builder->create_member_variable_definition(yystack_[3].value.as < std::string > (),std::move(yystack_[1].value.as < std::shared_ptr<ast::Node> > ())));
    }
#line 1317 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 27:
#line 279 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = yystack_[0].value.as < std::shared_ptr<ast::Node> > ();
    }
#line 1325 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 28:
#line 283 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_void();
    }
#line 1333 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 29:
#line 288 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::string> > () = std::move(yystack_[1].value.as < std::vector<std::string> > ());
    }
#line 1341 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 30:
#line 292 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::string> > () = {};
    }
#line 1349 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 31:
#line 297 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::string> > ().push_back(yystack_[0].value.as < std::string > ());
    }
#line 1357 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 32:
#line 301 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::string> > () = std::move(yystack_[2].value.as < std::vector<std::string> > ());
        yylhs.value.as < std::vector<std::string> > ().push_back(yystack_[0].value.as < std::string > ());
    }
#line 1366 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 33:
#line 307 "./src/compiler/parser/parser.yy"
    {
        is_global = NOT_GLOBAL;
        yylhs.value.as < std::shared_ptr<ast::Node> > () = yystack_[3].value.as < std::vector<std::shared_ptr<ast::Node>> > ().back();
    }
#line 1375 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 34:
#line 313 "./src/compiler/parser/parser.yy"
    {
        is_global = GLOBAL;
    }
#line 1383 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 35:
#line 318 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > ().push_back(std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()));
    }
#line 1391 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 36:
#line 322 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > () = std::move(yystack_[2].value.as < std::vector<std::shared_ptr<ast::Node>> > ());
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > ().push_back(std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()));
    }
#line 1400 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 37:
#line 329 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > ().push_back(std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()));
    }
#line 1408 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 38:
#line 333 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > () = std::move(yystack_[2].value.as < std::vector<std::shared_ptr<ast::Node>> > ());
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > ().push_back(std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()));
    }
#line 1417 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 39:
#line 339 "./src/compiler/parser/parser.yy"
    {
        driver.ast_builder->into_anonymous_scope();
    }
#line 1425 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 40:
#line 344 "./src/compiler/parser/parser.yy"
    {
        driver.ast_builder->into_anonymous_scope();
    }
#line 1433 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 41:
#line 349 "./src/compiler/parser/parser.yy"
    {
        driver.ast_builder->into_anonymous_scope();
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > ().push_back(yystack_[4].value.as < std::shared_ptr<ast::Node> > ());
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > ().push_back(yystack_[2].value.as < std::shared_ptr<ast::Node> > ());
        yylhs.value.as < std::vector<std::shared_ptr<ast::Node>> > ().push_back(yystack_[0].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1444 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 42:
#line 358 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = std::move(yystack_[1].value.as < std::shared_ptr<ast::Node> > ());
        driver.ast_builder->break_out_of_scope();
    }
#line 1453 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 43:
#line 364 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_if(yystack_[5].value.as < std::shared_ptr<ast::Node> > (),yystack_[1].value.as < std::shared_ptr<ast::Node> > (),{});
        driver.ast_builder->break_out_of_scope();
    }
#line 1462 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 44:
#line 369 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_if(yystack_[6].value.as < std::shared_ptr<ast::Node> > (),yystack_[2].value.as < std::shared_ptr<ast::Node> > (),yystack_[0].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1470 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 45:
#line 373 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_for(yystack_[5].value.as < std::vector<std::shared_ptr<ast::Node>> > ()[0],yystack_[5].value.as < std::vector<std::shared_ptr<ast::Node>> > ()[1],yystack_[5].value.as < std::vector<std::shared_ptr<ast::Node>> > ()[2],yystack_[1].value.as < std::shared_ptr<ast::Node> > ());
        driver.ast_builder->break_out_of_scope();
    }
#line 1479 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 46:
#line 378 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = yystack_[0].value.as < std::shared_ptr<ast::Node> > ();
    }
#line 1487 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 47:
#line 382 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_deep_copy(yystack_[2].value.as < std::shared_ptr<ast::Node> > (),yystack_[0].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1495 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 48:
#line 386 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_binary_expression(std::move(yystack_[2].value.as < std::shared_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()),"+");
    }
#line 1503 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 49:
#line 390 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_binary_expression(std::move(yystack_[2].value.as < std::shared_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()),"-");
    }
#line 1511 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 50:
#line 394 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_binary_expression(std::move(yystack_[2].value.as < std::shared_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()),"*");
    }
#line 1519 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 51:
#line 398 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_binary_expression(std::move(yystack_[2].value.as < std::shared_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()),"/");
    }
#line 1527 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 52:
#line 402 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_binary_expression(std::move(yystack_[2].value.as < std::shared_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()),"and");
    }
#line 1535 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 53:
#line 406 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_binary_expression(std::move(yystack_[2].value.as < std::shared_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()),"or");
    }
#line 1543 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 54:
#line 410 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_binary_expression(std::move(yystack_[2].value.as < std::shared_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()),">=");
    }
#line 1551 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 55:
#line 414 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_binary_expression(std::move(yystack_[2].value.as < std::shared_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()),"<=");
    }
#line 1559 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 56:
#line 418 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_binary_expression(std::move(yystack_[2].value.as < std::shared_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()),">");
    }
#line 1567 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 57:
#line 422 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_binary_expression(std::move(yystack_[2].value.as < std::shared_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()),"<");
    }
#line 1575 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 58:
#line 426 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_binary_expression(std::move(yystack_[2].value.as < std::shared_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()),"!=");
    }
#line 1583 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 59:
#line 430 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_binary_expression(std::move(yystack_[2].value.as < std::shared_ptr<ast::Node> > ()),std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()),"==");
    }
#line 1591 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 60:
#line 434 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1599 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 61:
#line 438 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1607 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 62:
#line 442 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1615 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 63:
#line 446 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_minus(yystack_[0].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1623 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 64:
#line 450 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = std::move(yystack_[1].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1631 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 65:
#line 455 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_array(std::move(yystack_[1].value.as < std::vector<std::shared_ptr<ast::Node>> > ()));
    }
#line 1639 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 66:
#line 459 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_array();
    }
#line 1647 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 67:
#line 464 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_access(yystack_[1].value.as < std::shared_ptr<ast::Node> > (),yystack_[0].value.as < std::string > ());
    }
#line 1655 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 68:
#line 469 "./src/compiler/parser/parser.yy"
    {
        if (is_global == NOT_GLOBAL)
        {
            if (driver.ast_builder->exist(yystack_[2].value.as < std::string > ()))
            {
                yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_assignment(yystack_[2].value.as < std::string > (),std::move())
            }
            else
            {
                yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_variable_definition(yystack_[2].value.as < std::string > (),std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()));
            }

        }
        if (is_global == GLOBAL)
        {yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_global_variable_definition(yystack_[2].value.as < std::string > (),std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()));}
    }
#line 1676 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 69:
#line 486 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_assignment(yystack_[2].value.as < std::shared_ptr<ast::Node> > (),std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ()));
    }
#line 1684 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 70:
#line 491 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = yystack_[0].value.as < std::shared_ptr<ast::Node> > ();
    }
#line 1692 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 71:
#line 495 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_string(yystack_[0].value.as < std::string > ());
    }
#line 1700 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 72:
#line 499 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_float(yystack_[0].value.as < double > ());
    }
#line 1708 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 73:
#line 503 "./src/compiler/parser/parser.yy"
    { 
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_integer(yystack_[0].value.as < long long > ());
    }
#line 1716 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 74:
#line 507 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = std::move(yystack_[0].value.as < std::shared_ptr<ast::Node> > ());
    }
#line 1724 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 75:
#line 512 "./src/compiler/parser/parser.yy"
    {
        auto function = driver.ast_builder->get_named_node(yystack_[3].value.as < std::string > ());
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_call(function,yystack_[1].value.as < std::vector<std::shared_ptr<ast::Node>> > ());
    }
#line 1733 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 76:
#line 517 "./src/compiler/parser/parser.yy"
    {
        auto function = driver.ast_builder->get_named_node(yystack_[2].value.as < std::string > ());
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_call(function,{});
    }
#line 1742 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 77:
#line 522 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_call(yystack_[3].value.as < std::shared_ptr<ast::Node> > (),yystack_[1].value.as < std::vector<std::shared_ptr<ast::Node>> > ());
    }
#line 1750 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 78:
#line 526 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->create_call(yystack_[2].value.as < std::shared_ptr<ast::Node> > (),{});
    }
#line 1758 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;

  case 79:
#line 531 "./src/compiler/parser/parser.yy"
    {
        yylhs.value.as < std::shared_ptr<ast::Node> > () = driver.ast_builder->get_named_node(yystack_[0].value.as < std::string > ());
    }
#line 1766 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"
    break;


#line 1770 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"

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


  const signed char Parser::yypact_ninf_ = -118;

  const signed char Parser::yytable_ninf_ = -37;

  const short
  Parser::yypact_[] =
  {
     113,   -16,   -16,     9,   189,   189,     0,  -118,   189,  -118,
    -118,  -118,  -118,    16,  -118,   113,  -118,     5,  -118,  -118,
     -30,  -118,   -25,  -118,   -12,   189,     7,   333,  -118,    10,
    -118,  -118,  -118,  -118,     6,  -118,  -118,   189,   131,    24,
     274,  -118,   -17,   333,   295,  -118,  -118,  -118,  -118,    66,
      18,    34,   225,    39,   189,   189,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   189,  -118,   189,   151,
    -118,  -118,    12,   333,  -118,    50,  -118,   189,  -118,   189,
     189,    75,    40,   -16,    76,    87,    51,    52,    63,    57,
      73,    62,   333,   345,   345,    68,    68,    68,    68,    68,
      68,     2,     2,    24,    24,   333,  -118,    70,    97,  -118,
    -118,   333,   314,   333,    65,  -118,  -118,   189,    72,    66,
    -118,    99,    87,   189,    78,   113,  -118,  -118,   189,  -118,
     240,  -118,    75,  -118,   189,    80,   333,    81,   113,    82,
     333,  -118,  -118,   259,   169,    95,  -118,  -118,    84,    85,
      92,  -118,  -118,    89,  -118,    88,    90,   113,   104,  -118
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     0,     0,    79,     0,     0,     0,    39,     0,    34,
      71,    73,    72,     0,     2,     3,     4,     0,     8,    10,
       0,    11,     0,    12,     0,     0,     0,     9,    61,    62,
      46,    60,    70,    74,     0,    15,    19,     0,     0,    63,
       0,    66,     0,    37,     0,     1,     5,     7,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    67,     0,     0,
      31,    30,     0,    68,    76,     0,    64,     0,    65,     0,
      28,     0,     0,     0,     0,    18,     0,     0,    17,     0,
       0,     0,    47,    52,    53,    59,    58,    54,    55,    56,
      57,    48,    49,    50,    51,    69,    78,     0,     0,    29,
      75,    38,     0,    27,     0,    14,    22,     0,     0,     0,
      20,     0,    16,     0,     0,     0,    77,    32,     0,    13,
       0,    21,     0,    24,     0,     0,     0,    46,     0,     0,
      41,    25,    23,     0,     0,     0,    45,    26,     0,    46,
      43,    33,    40,     0,    44,     0,     0,     0,     0,    42
  };

  const signed char
  Parser::yypgoto_[] =
  {
    -118,  -118,   -42,  -118,   114,  -118,  -118,  -118,  -118,  -118,
    -118,    47,  -118,   -76,  -118,   -53,     1,  -118,  -118,  -118,
    -118,   -28,  -118,  -118,  -118,  -118,    -4,  -118,  -118,  -117,
    -118,  -118,  -118
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    85,    86,    87,    88,    82,    35,    72,    23,    24,
     135,    42,    25,   153,    26,   154,    27,    28,    29,    30,
      31,    32,    33
  };

  const short
  Parser::yytable_[] =
  {
      39,    40,    43,    36,    44,    47,   137,    81,     3,   118,
      75,    77,    49,    34,    70,    78,    45,    50,    37,    68,
       4,    52,    83,    65,    66,    84,    67,   149,   114,     5,
      51,     6,    41,    73,    43,     7,    71,     8,    38,    69,
     108,   107,   109,    10,    11,    12,   118,    48,    67,    53,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    89,   105,    43,   133,    83,    91,     1,
     121,     2,    80,   111,     3,   112,   113,   132,    77,   142,
     110,    80,   115,   139,   116,   117,     4,    63,    64,    65,
      66,    83,    67,   119,   120,     5,   145,     6,    77,   123,
     126,     7,   124,     8,   125,   127,     9,   129,   134,    10,
      11,    12,   146,   130,   131,   158,     1,   156,     2,   136,
     138,     3,   144,   -35,   140,   150,   151,   -36,   152,    46,
     143,   155,   157,     4,   159,   122,     0,     0,     0,     3,
     136,     0,     5,     0,     6,     0,     0,     0,     7,     0,
       8,     4,     0,     9,     0,     0,    10,    11,    12,     3,
       5,    74,     6,     0,     0,     0,     7,     0,     8,     0,
       0,     4,     0,     0,    10,    11,    12,     3,     0,     0,
       5,   106,     6,     0,     0,     0,     7,     0,     8,     4,
       0,     0,     0,     0,    10,    11,    12,     3,     5,   148,
       6,     0,     0,     0,     7,     0,     8,     0,     0,     4,
       0,     0,    10,    11,    12,     0,     0,     0,     5,     0,
       6,     0,     0,     0,     7,     0,     8,     0,     0,     0,
       0,     0,    10,    11,    12,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,    67,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,     0,    67,     0,     0,    90,     0,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,   141,    67,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,    67,     0,
       0,   147,     0,     0,    76,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,    67,
       0,     0,     0,    79,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,    67,     0,
       0,     0,   128,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,     0,    67,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,    67
  };

  const short
  Parser::yycheck_[] =
  {
       4,     5,     6,     2,     8,     0,   123,    49,     8,    85,
      38,    28,    42,    29,     8,    32,     0,    42,     9,     9,
      20,    25,     4,    21,    22,     7,    24,   144,    81,    29,
      42,    31,    32,    37,    38,    35,    30,    37,    29,    29,
      28,    69,    30,    43,    44,    45,   122,    42,    24,    42,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    29,    68,    69,   119,     4,    29,     3,
       7,     5,     6,    77,     8,    79,    80,   119,    28,   132,
      30,     6,    42,   125,    83,     9,    20,    19,    20,    21,
      22,     4,    24,    42,    42,    29,   138,    31,    28,    42,
      30,    35,    29,    37,    42,     8,    40,    42,     9,    43,
      44,    45,    30,   117,    42,   157,     3,    29,     5,   123,
      42,     8,    42,    42,   128,    30,    42,    42,    36,    15,
     134,    42,    42,    20,    30,    88,    -1,    -1,    -1,     8,
     144,    -1,    29,    -1,    31,    -1,    -1,    -1,    35,    -1,
      37,    20,    -1,    40,    -1,    -1,    43,    44,    45,     8,
      29,    30,    31,    -1,    -1,    -1,    35,    -1,    37,    -1,
      -1,    20,    -1,    -1,    43,    44,    45,     8,    -1,    -1,
      29,    30,    31,    -1,    -1,    -1,    35,    -1,    37,    20,
      -1,    -1,    -1,    -1,    43,    44,    45,     8,    29,    30,
      31,    -1,    -1,    -1,    35,    -1,    37,    -1,    -1,    20,
      -1,    -1,    43,    44,    45,    -1,    -1,    -1,    29,    -1,
      31,    -1,    -1,    -1,    35,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    24,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    -1,    42,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    42,    24,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      -1,    42,    -1,    -1,    30,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    -1,    -1,    28,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      -1,    -1,    28,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    24,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    24
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     3,     5,     8,    20,    29,    31,    35,    37,    40,
      43,    44,    45,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    64,    65,    68,    70,    72,    73,    74,
      75,    76,    77,    78,    29,    62,    62,     9,    29,    72,
      72,    32,    67,    72,    72,     0,    50,     0,    42,    42,
      42,    42,    72,    42,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    24,     9,    29,
       8,    30,    63,    72,    30,    67,    30,    28,    32,    28,
       6,    48,    61,     4,     7,    57,    58,    59,    60,    29,
      42,    29,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    30,    67,    28,    30,
      30,    72,    72,    72,    61,    42,    62,     9,    59,    42,
      42,     7,    57,    42,    29,    42,    30,     8,    28,    42,
      72,    42,    48,    61,     9,    66,    72,    75,    42,    48,
      72,    42,    61,    72,    42,    48,    30,    42,    30,    75,
      30,    42,    36,    69,    71,    42,    29,    42,    48,    30
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    46,    47,    48,    49,    49,    50,    50,    50,    51,
      52,    52,    52,    53,    53,    54,    55,    55,    55,    56,
      57,    57,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    63,    63,    64,    65,    66,    66,    67,    67,    68,
      69,    70,    71,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    73,    73,    74,    75,    75,
      76,    76,    76,    76,    76,    77,    77,    77,    77,    78
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     2,     2,     2,     1,     1,
       1,     1,     1,     5,     4,     2,     4,     3,     3,     2,
       2,     3,     2,     4,     3,     4,     5,     2,     1,     3,
       2,     1,     3,     8,     1,     1,     3,     1,     3,     1,
       1,     6,     6,     7,     8,     6,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     2,     3,     3,     2,     2,     3,     3,
       1,     1,     1,     1,     1,     4,     3,     4,     3,     1
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
  "function_definition", "function_name_and_argument_names",
  "class_definition", "class_name_and_argument_names", "methods",
  "method_name_and_argument_names", "method_definition",
  "members_definition", "return_value", "arguments",
  "definition_arguments", "globals_definition", "global_start",
  "globals_variables", "expressions", "if_start", "else_start",
  "for_start", "else_body", "expression", "list", "access",
  "assign_variable", "monomial", "call", "variable", YY_NULLPTR
  };


  const short
  Parser::yyrline_[] =
  {
       0,   145,   145,   151,   156,   160,   166,   170,   174,   180,
     185,   189,   193,   198,   203,   209,   216,   221,   226,   232,
     239,   243,   249,   257,   262,   268,   272,   278,   282,   287,
     291,   296,   300,   306,   312,   317,   321,   328,   332,   338,
     343,   348,   357,   363,   368,   372,   377,   381,   385,   389,
     393,   397,   401,   405,   409,   413,   417,   421,   425,   429,
     433,   437,   441,   445,   449,   454,   458,   463,   468,   485,
     490,   494,   498,   502,   506,   511,   516,   521,   525,   530
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
} // Blawn
#line 2269 "/Users/ueharanaoto/Desktop/Blawn/build/parser.cpp"

#line 534 "./src/compiler/parser/parser.yy"


void Blawn::Parser::error( const location_type &l, const std::string &err_message )
{
    std::cerr << "Error: " << err_message << " at " << l << "\n";
    exit(1);
} 
