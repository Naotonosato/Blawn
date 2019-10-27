// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton interface for Bison LALR(1) parsers in C++

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

/**
 ** \file parser.tab.hh
 ** Define the Blawn::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_YY_PARSER_TAB_HH_INCLUDED
# define YY_YY_PARSER_TAB_HH_INCLUDED
// //                    "%code requires" blocks.
#line 10 "parser.yy" // lalr1.cc:377

    #include <memory>
    #include <llvm/IR/IRBuilder.h>
    #include "../ast/node.hpp"
    #include "../ast_generator/ast_generator.hpp"
 
    namespace Blawn {
        class Driver;
        class Scanner;
    }

    // The following definitions is missing when %locations isn't used
    # ifndef YY_NULLPTR
    #  if defined __cplusplus && 201103L <= __cplusplus
    #   define YY_NULLPTR nullptr
    #  else
    #   define YY_NULLPTR 0
    #  endif
    # endif

#line 65 "parser.tab.hh" // lalr1.cc:377

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>
# include "stack.hh"
# include "location.hh"
#include <typeinfo>
#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
#endif


#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

#line 5 "parser.yy" // lalr1.cc:377
namespace Blawn {
#line 142 "parser.tab.hh" // lalr1.cc:377



  /// A char[S] buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current state.
  template <size_t S>
  struct variant
  {
    /// Type of *this.
    typedef variant<S> self_type;

    /// Empty construction.
    variant ()
      : yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    variant (const T& t)
      : yytypeid_ (&typeid (T))
    {
      YYASSERT (sizeof (T) <= S);
      new (yyas_<T> ()) T (t);
    }

    /// Destruction, allowed only if empty.
    ~variant ()
    {
      YYASSERT (!yytypeid_);
    }

    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    build ()
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= S);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T;
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    build (const T& t)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= S);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::move((T&)t));
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as ()
    {
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const
    {
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= S);
      return *yyas_<T> ();
    }

    /// Swap the content with \a other, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsability.
    /// Swapping between built and (possibly) non-built is done with
    /// variant::move ().
    template <typename T>
    void
    swap (self_type& other)
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == *other.yytypeid_);
      std::swap (as<T> (), other.as<T> ());
    }

    /// Move the content of \a other to this.
    ///
    /// Destroys \a other.
    template <typename T>
    void
    move (self_type& other)
    {
      build<T> ();
      swap<T> (other);
      other.destroy<T> ();
    }

    /// Copy the content of \a other to this.
    template <typename T>
    void
    copy (const self_type& other)
    {
      build<T> (other.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator=(const self_type&);
    variant (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ ()
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[S];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };


  /// A Bison parser.
  class Parser
  {
  public:
#ifndef YYSTYPE
    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // FLOAT_LITERAL
      char dummy1[sizeof(double)];

      // INT_LITERAL
      char dummy2[sizeof(long long)];

      // access
      char dummy3[sizeof(std::shared_ptr<AccessNode>)];

      // method_definition
      char dummy4[sizeof(std::shared_ptr<FunctionNode>)];

      // line
      // line_content
      // definition
      // function_definition
      // class_definition
      // c_type_definition
      // C_returns
      // return_value
      // globals_definition
      // c_function_declaration
      // expression
      // list
      // assign_variable
      // monomial
      // call
      // variable
      char dummy5[sizeof(std::shared_ptr<Node>)];

      // FUNCTION_DEFINITION
      // METHOD_DEFINITION
      // CLASS_DEFINITION
      // C_TYPE_DEFINITION
      // C_FUNCTION_DECLARATION
      // C_FUNCTION
      // MEMBER_IDENTIFIER
      // IDENTIFIER
      // DOT_IDENTIFIER
      // STRING_LITERAL
      // function_start
      // class_start
      // c_type_start
      // method_start
      char dummy6[sizeof(std::string)];

      // methods
      char dummy7[sizeof(std::vector<std::shared_ptr<FunctionNode>>)];

      // block
      // lines
      // members_definition
      // C_members_definition
      // C_arguments
      // globals_variables
      // expressions
      // for_start
      char dummy8[sizeof(std::vector<std::shared_ptr<Node>>)];

      // C_type_identifier
      // arguments
      // definition_arguments
      char dummy9[sizeof(std::vector<std::string>)];
};

    /// Symbol semantic values.
    typedef variant<sizeof(union_type)> semantic_type;
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m);
      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        END = 0,
        FUNCTION_DEFINITION = 258,
        METHOD_DEFINITION = 259,
        CLASS_DEFINITION = 260,
        C_TYPE_DEFINITION = 261,
        C_FUNCTION_DECLARATION = 262,
        RETURN = 263,
        C_FUNCTION = 264,
        MEMBER_IDENTIFIER = 265,
        IDENTIFIER = 266,
        EQUAL = 267,
        ARROW = 268,
        OP_AND = 269,
        OP_OR = 270,
        OP_EQUAL = 271,
        OP_NOT_EQUAL = 272,
        OP_MORE_EQUAL = 273,
        OP_LESS_EQUAL = 274,
        OP_MORE = 275,
        OP_LESS = 276,
        PLUS = 277,
        MINUS = 278,
        ASTERISK = 279,
        SLASH = 280,
        DOT_IDENTIFIER = 281,
        USE = 282,
        COLON = 283,
        SEMICOLON = 284,
        COMMA = 285,
        LEFT_PARENTHESIS = 286,
        RIGHT_PARENTHESIS = 287,
        LEFT_CURLY_BRACE = 288,
        RIGHT_CURLY_BRACE = 289,
        LEFT_BRACKET = 290,
        RIGHT_BRACKET = 291,
        IF = 292,
        ELSE = 293,
        FOR = 294,
        IN = 295,
        WHILE = 296,
        GLOBAL = 297,
        IMPORT = 298,
        C_FUNCTION_ARGUMENT = 299,
        C_FUNCTION_RETURN = 300,
        EOL = 301,
        STRING_LITERAL = 302,
        INT_LITERAL = 303,
        FLOAT_LITERAL = 304
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols, and symbols from each type.

  basic_symbol (typename Base::kind_type t, const location_type& l);

  basic_symbol (typename Base::kind_type t, const double v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const long long v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::shared_ptr<AccessNode> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::shared_ptr<FunctionNode> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::shared_ptr<Node> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::vector<std::shared_ptr<FunctionNode>> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::vector<std::shared_ptr<Node>> v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::vector<std::string> v, const location_type& l);


      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v,
                    const location_type& l);

      /// Destroy the symbol.
      ~basic_symbol ();

      /// Destroy contents, and record that is empty.
      void clear ();

      /// Whether empty.
      bool empty () const;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;

    // Symbol constructors declarations.
    static inline
    symbol_type
    make_END (const location_type& l);

    static inline
    symbol_type
    make_FUNCTION_DEFINITION (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_METHOD_DEFINITION (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_CLASS_DEFINITION (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_C_TYPE_DEFINITION (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_C_FUNCTION_DECLARATION (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_RETURN (const location_type& l);

    static inline
    symbol_type
    make_C_FUNCTION (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_MEMBER_IDENTIFIER (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_IDENTIFIER (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_EQUAL (const location_type& l);

    static inline
    symbol_type
    make_ARROW (const location_type& l);

    static inline
    symbol_type
    make_OP_AND (const location_type& l);

    static inline
    symbol_type
    make_OP_OR (const location_type& l);

    static inline
    symbol_type
    make_OP_EQUAL (const location_type& l);

    static inline
    symbol_type
    make_OP_NOT_EQUAL (const location_type& l);

    static inline
    symbol_type
    make_OP_MORE_EQUAL (const location_type& l);

    static inline
    symbol_type
    make_OP_LESS_EQUAL (const location_type& l);

    static inline
    symbol_type
    make_OP_MORE (const location_type& l);

    static inline
    symbol_type
    make_OP_LESS (const location_type& l);

    static inline
    symbol_type
    make_PLUS (const location_type& l);

    static inline
    symbol_type
    make_MINUS (const location_type& l);

    static inline
    symbol_type
    make_ASTERISK (const location_type& l);

    static inline
    symbol_type
    make_SLASH (const location_type& l);

    static inline
    symbol_type
    make_DOT_IDENTIFIER (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_USE (const location_type& l);

    static inline
    symbol_type
    make_COLON (const location_type& l);

    static inline
    symbol_type
    make_SEMICOLON (const location_type& l);

    static inline
    symbol_type
    make_COMMA (const location_type& l);

    static inline
    symbol_type
    make_LEFT_PARENTHESIS (const location_type& l);

    static inline
    symbol_type
    make_RIGHT_PARENTHESIS (const location_type& l);

    static inline
    symbol_type
    make_LEFT_CURLY_BRACE (const location_type& l);

    static inline
    symbol_type
    make_RIGHT_CURLY_BRACE (const location_type& l);

    static inline
    symbol_type
    make_LEFT_BRACKET (const location_type& l);

    static inline
    symbol_type
    make_RIGHT_BRACKET (const location_type& l);

    static inline
    symbol_type
    make_IF (const location_type& l);

    static inline
    symbol_type
    make_ELSE (const location_type& l);

    static inline
    symbol_type
    make_FOR (const location_type& l);

    static inline
    symbol_type
    make_IN (const location_type& l);

    static inline
    symbol_type
    make_WHILE (const location_type& l);

    static inline
    symbol_type
    make_GLOBAL (const location_type& l);

    static inline
    symbol_type
    make_IMPORT (const location_type& l);

    static inline
    symbol_type
    make_C_FUNCTION_ARGUMENT (const location_type& l);

    static inline
    symbol_type
    make_C_FUNCTION_RETURN (const location_type& l);

    static inline
    symbol_type
    make_EOL (const location_type& l);

    static inline
    symbol_type
    make_STRING_LITERAL (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_INT_LITERAL (const long long& v, const location_type& l);

    static inline
    symbol_type
    make_FLOAT_LITERAL (const double& v, const location_type& l);


    /// Build a parser object.
    Parser (Scanner  &scanner_yyarg, Driver  &driver_yyarg);
    virtual ~Parser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

  private:
    /// This class is not copyable.
    Parser (const Parser&);
    Parser& operator= (const Parser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (int t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short int yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short int yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short int yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const short int yytable_[];

  static const unsigned char yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


#if YYDEBUG
    /// For a symbol, its name in clear.
    static const char* const yytname_[];

  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short int yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, symbol_type& sym);
      /// Assignment, needed by push_back.
      stack_symbol_type& operator= (const stack_symbol_type& that);
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, stack_symbol_type& s);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, state_type s, symbol_type& sym);

    /// Pop \a n symbols the three stacks.
    void yypop_ (unsigned int n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 307,     ///< Last index in yytable_.
      yynnts_ = 40,  ///< Number of nonterminal symbols.
      yyfinal_ = 49, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 50  ///< Number of tokens.
    };


    // User arguments.
    Scanner  &scanner;
    Driver  &driver;
  };


#line 5 "parser.yy" // lalr1.cc:377
} // Blawn
#line 975 "parser.tab.hh" // lalr1.cc:377




#endif // !YY_YY_PARSER_TAB_HH_INCLUDED
