// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

// "%code top" blocks.
#line 32 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"

    #include "location.hh"
    #include "stack.hh"
    #include "position.hh"

	#include "ast/translation_unit.hpp"
	#include "ast/function_definition.hpp"
	#include "ast/declaration.hpp"

	#include "ast/statement.hpp"
	#include "ast/compound_statement.hpp"
	#include "ast/return_statement.hpp"
	#include "ast/expression_statement.hpp"
	#include "ast/break_statement.hpp"
	#include "ast/continue_statement.hpp"
	#include "ast/selection_statement.hpp"
	#include "ast/iteration_statement.hpp"
	
	#include "ast/expression.hpp"
	#include "ast/comma_expression.hpp"
	#include "ast/assignment_expression.hpp"
	#include "ast/logical_or_expression.hpp"
	#include "ast/logical_and_expression.hpp"
	#include "ast/inclusive_or_expression.hpp"
	#include "ast/exclusive_or_expression.hpp"
	#include "ast/and_expression.hpp"
	#include "ast/eq_expression.hpp"
	#include "ast/neq_expression.hpp"
	#include "ast/less_expression.hpp"
	#include "ast/greater_expression.hpp"
	#include "ast/leq_expression.hpp"
	#include "ast/geq_expression.hpp"
	#include "ast/shl_expression.hpp"
	#include "ast/shr_expression.hpp"
	#include "ast/add_expression.hpp"
	#include "ast/sub_expression.hpp"
	#include "ast/mul_expression.hpp"
	#include "ast/div_expression.hpp"
	#include "ast/mod_expression.hpp"
	#include "ast/identifier_expression.hpp"
	#include "ast/constant_expression.hpp"
	#include "ast/string_expression.hpp"

	#include "driver.hpp"

	static yy::parser::symbol_type yylex([[maybe_unused]] nezoku::Driver& driver, nezoku::Scanner& scanner) {
        return scanner.ScanToken();
    }

#line 89 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"




#include "parser.hpp"




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
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 188 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"

  /// Build a parser object.
  parser::parser (nezoku::Driver& driver_yyarg, nezoku::Scanner& scanner_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      driver (driver_yyarg),
      scanner (scanner_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_assignment_operator: // assignment_operator
        value.YY_MOVE_OR_COPY< nezoku::AssignmentOperator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.YY_MOVE_OR_COPY< nezoku::Declaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
      case symbol_kind::S_and_expression: // and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_shift_expression: // shift_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_primary_expression: // primary_expression
        value.YY_MOVE_OR_COPY< nezoku::Expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_definition: // function_definition
        value.YY_MOVE_OR_COPY< nezoku::FunctionDefinition* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_compound_statement: // compound_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_selection_statement: // selection_statement
      case symbol_kind::S_iteration_statement: // iteration_statement
      case symbol_kind::S_jump_statement: // jump_statement
      case symbol_kind::S_expression_statement: // expression_statement
        value.YY_MOVE_OR_COPY< nezoku::Statement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_translation_unit: // translation_unit
        value.YY_MOVE_OR_COPY< nezoku::TranslationUnit* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.YY_MOVE_OR_COPY< nezoku::TypeSpecifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONSTANT: // CONSTANT
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_external_declaration: // external_declaration
        value.YY_MOVE_OR_COPY< std::variant<nezoku::Declaration*, nezoku::FunctionDefinition*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block_item: // block_item
        value.YY_MOVE_OR_COPY< std::variant<nezoku::Declaration*, nezoku::Statement*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.YY_MOVE_OR_COPY< std::vector<std::pair<nezoku::TypeSpecifier, std::string>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block_item_list: // block_item_list
        value.YY_MOVE_OR_COPY< std::vector<std::variant<nezoku::Declaration*, nezoku::Statement*>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_assignment_operator: // assignment_operator
        value.move< nezoku::AssignmentOperator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.move< nezoku::Declaration* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
      case symbol_kind::S_and_expression: // and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_shift_expression: // shift_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_primary_expression: // primary_expression
        value.move< nezoku::Expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_definition: // function_definition
        value.move< nezoku::FunctionDefinition* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_compound_statement: // compound_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_selection_statement: // selection_statement
      case symbol_kind::S_iteration_statement: // iteration_statement
      case symbol_kind::S_jump_statement: // jump_statement
      case symbol_kind::S_expression_statement: // expression_statement
        value.move< nezoku::Statement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_translation_unit: // translation_unit
        value.move< nezoku::TranslationUnit* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.move< nezoku::TypeSpecifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONSTANT: // CONSTANT
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_external_declaration: // external_declaration
        value.move< std::variant<nezoku::Declaration*, nezoku::FunctionDefinition*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block_item: // block_item
        value.move< std::variant<nezoku::Declaration*, nezoku::Statement*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.move< std::vector<std::pair<nezoku::TypeSpecifier, std::string>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block_item_list: // block_item_list
        value.move< std::vector<std::variant<nezoku::Declaration*, nezoku::Statement*>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_assignment_operator: // assignment_operator
        value.copy< nezoku::AssignmentOperator > (that.value);
        break;

      case symbol_kind::S_declaration: // declaration
        value.copy< nezoku::Declaration* > (that.value);
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
      case symbol_kind::S_and_expression: // and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_shift_expression: // shift_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_primary_expression: // primary_expression
        value.copy< nezoku::Expression* > (that.value);
        break;

      case symbol_kind::S_function_definition: // function_definition
        value.copy< nezoku::FunctionDefinition* > (that.value);
        break;

      case symbol_kind::S_compound_statement: // compound_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_selection_statement: // selection_statement
      case symbol_kind::S_iteration_statement: // iteration_statement
      case symbol_kind::S_jump_statement: // jump_statement
      case symbol_kind::S_expression_statement: // expression_statement
        value.copy< nezoku::Statement* > (that.value);
        break;

      case symbol_kind::S_translation_unit: // translation_unit
        value.copy< nezoku::TranslationUnit* > (that.value);
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.copy< nezoku::TypeSpecifier > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONSTANT: // CONSTANT
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_external_declaration: // external_declaration
        value.copy< std::variant<nezoku::Declaration*, nezoku::FunctionDefinition*> > (that.value);
        break;

      case symbol_kind::S_block_item: // block_item
        value.copy< std::variant<nezoku::Declaration*, nezoku::Statement*> > (that.value);
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.copy< std::vector<std::pair<nezoku::TypeSpecifier, std::string>> > (that.value);
        break;

      case symbol_kind::S_block_item_list: // block_item_list
        value.copy< std::vector<std::variant<nezoku::Declaration*, nezoku::Statement*>> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_assignment_operator: // assignment_operator
        value.move< nezoku::AssignmentOperator > (that.value);
        break;

      case symbol_kind::S_declaration: // declaration
        value.move< nezoku::Declaration* > (that.value);
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
      case symbol_kind::S_and_expression: // and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_shift_expression: // shift_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_primary_expression: // primary_expression
        value.move< nezoku::Expression* > (that.value);
        break;

      case symbol_kind::S_function_definition: // function_definition
        value.move< nezoku::FunctionDefinition* > (that.value);
        break;

      case symbol_kind::S_compound_statement: // compound_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_selection_statement: // selection_statement
      case symbol_kind::S_iteration_statement: // iteration_statement
      case symbol_kind::S_jump_statement: // jump_statement
      case symbol_kind::S_expression_statement: // expression_statement
        value.move< nezoku::Statement* > (that.value);
        break;

      case symbol_kind::S_translation_unit: // translation_unit
        value.move< nezoku::TranslationUnit* > (that.value);
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.move< nezoku::TypeSpecifier > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONSTANT: // CONSTANT
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_external_declaration: // external_declaration
        value.move< std::variant<nezoku::Declaration*, nezoku::FunctionDefinition*> > (that.value);
        break;

      case symbol_kind::S_block_item: // block_item
        value.move< std::variant<nezoku::Declaration*, nezoku::Statement*> > (that.value);
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.move< std::vector<std::pair<nezoku::TypeSpecifier, std::string>> > (that.value);
        break;

      case symbol_kind::S_block_item_list: // block_item_list
        value.move< std::vector<std::variant<nezoku::Declaration*, nezoku::Statement*>> > (that.value);
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
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
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
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (driver, scanner));
            yyla.move (yylookahead);
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

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
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
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
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
      case symbol_kind::S_assignment_operator: // assignment_operator
        yylhs.value.emplace< nezoku::AssignmentOperator > ();
        break;

      case symbol_kind::S_declaration: // declaration
        yylhs.value.emplace< nezoku::Declaration* > ();
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_inclusive_or_expression: // inclusive_or_expression
      case symbol_kind::S_exclusive_or_expression: // exclusive_or_expression
      case symbol_kind::S_and_expression: // and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_shift_expression: // shift_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_primary_expression: // primary_expression
        yylhs.value.emplace< nezoku::Expression* > ();
        break;

      case symbol_kind::S_function_definition: // function_definition
        yylhs.value.emplace< nezoku::FunctionDefinition* > ();
        break;

      case symbol_kind::S_compound_statement: // compound_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_selection_statement: // selection_statement
      case symbol_kind::S_iteration_statement: // iteration_statement
      case symbol_kind::S_jump_statement: // jump_statement
      case symbol_kind::S_expression_statement: // expression_statement
        yylhs.value.emplace< nezoku::Statement* > ();
        break;

      case symbol_kind::S_translation_unit: // translation_unit
        yylhs.value.emplace< nezoku::TranslationUnit* > ();
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        yylhs.value.emplace< nezoku::TypeSpecifier > ();
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONSTANT: // CONSTANT
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_external_declaration: // external_declaration
        yylhs.value.emplace< std::variant<nezoku::Declaration*, nezoku::FunctionDefinition*> > ();
        break;

      case symbol_kind::S_block_item: // block_item
        yylhs.value.emplace< std::variant<nezoku::Declaration*, nezoku::Statement*> > ();
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        yylhs.value.emplace< std::vector<std::pair<nezoku::TypeSpecifier, std::string>> > ();
        break;

      case symbol_kind::S_block_item_list: // block_item_list
        yylhs.value.emplace< std::vector<std::variant<nezoku::Declaration*, nezoku::Statement*>> > ();
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
  case 2: // translation_unit: external_declaration
#line 201 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                           {
		yylhs.value.as < nezoku::TranslationUnit* > () = new nezoku::TranslationUnit();
		yylhs.value.as < nezoku::TranslationUnit* > ()->add_external_declaration(std::move(yystack_[0].value.as < std::variant<nezoku::Declaration*, nezoku::FunctionDefinition*> > ()));
		driver.program = yylhs.value.as < nezoku::TranslationUnit* > ();
	}
#line 922 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 3: // translation_unit: translation_unit external_declaration
#line 206 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                            {
		yystack_[1].value.as < nezoku::TranslationUnit* > ()->add_external_declaration(std::move(yystack_[0].value.as < std::variant<nezoku::Declaration*, nezoku::FunctionDefinition*> > ()));
		yylhs.value.as < nezoku::TranslationUnit* > () = yystack_[1].value.as < nezoku::TranslationUnit* > ();
	}
#line 931 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 4: // external_declaration: declaration
#line 213 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                  { yylhs.value.as < std::variant<nezoku::Declaration*, nezoku::FunctionDefinition*> > () = std::variant<nezoku::Declaration*, nezoku::FunctionDefinition*>(yystack_[0].value.as < nezoku::Declaration* > ()); }
#line 937 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 5: // external_declaration: function_definition
#line 214 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                          { yylhs.value.as < std::variant<nezoku::Declaration*, nezoku::FunctionDefinition*> > () = std::variant<nezoku::Declaration*, nezoku::FunctionDefinition*>(yystack_[0].value.as < nezoku::FunctionDefinition* > ()); }
#line 943 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 6: // declaration: type_specifier IDENTIFIER ';'
#line 218 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                    { yylhs.value.as < nezoku::Declaration* > () = new nezoku::Declaration(yystack_[2].value.as < nezoku::TypeSpecifier > (), yystack_[1].value.as < std::string > ()); }
#line 949 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 7: // declaration: type_specifier IDENTIFIER '=' expression ';'
#line 219 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                                   { yylhs.value.as < nezoku::Declaration* > () = new nezoku::Declaration(yystack_[4].value.as < nezoku::TypeSpecifier > (), yystack_[3].value.as < std::string > (), yystack_[1].value.as < nezoku::Expression* > ()); }
#line 955 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 8: // type_specifier: INT_8_T
#line 223 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
              { yylhs.value.as < nezoku::TypeSpecifier > () = nezoku::TypeSpecifier::I8Type; }
#line 961 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 9: // type_specifier: INT_16_T
#line 224 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
               { yylhs.value.as < nezoku::TypeSpecifier > () = nezoku::TypeSpecifier::I16Type; }
#line 967 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 10: // type_specifier: INT_32_T
#line 225 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
               { yylhs.value.as < nezoku::TypeSpecifier > () = nezoku::TypeSpecifier::I32Type; }
#line 973 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 11: // type_specifier: INT_64_T
#line 226 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
               { yylhs.value.as < nezoku::TypeSpecifier > () = nezoku::TypeSpecifier::I64Type; }
#line 979 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 12: // type_specifier: UINT_8_T
#line 227 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
               { yylhs.value.as < nezoku::TypeSpecifier > () = nezoku::TypeSpecifier::U8Type; }
#line 985 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 13: // type_specifier: UINT_16_T
#line 228 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                { yylhs.value.as < nezoku::TypeSpecifier > () = nezoku::TypeSpecifier::U16Type; }
#line 991 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 14: // type_specifier: UINT_32_T
#line 229 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                { yylhs.value.as < nezoku::TypeSpecifier > () = nezoku::TypeSpecifier::U32Type; }
#line 997 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 15: // type_specifier: UINT_64_T
#line 230 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                { yylhs.value.as < nezoku::TypeSpecifier > () = nezoku::TypeSpecifier::U64Type; }
#line 1003 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 16: // type_specifier: BOOL_T
#line 231 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
             { yylhs.value.as < nezoku::TypeSpecifier > () = nezoku::TypeSpecifier::BoolType; }
#line 1009 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 17: // type_specifier: CHAR_T
#line 232 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
             { yylhs.value.as < nezoku::TypeSpecifier > () = nezoku::TypeSpecifier::CharType; }
#line 1015 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 18: // type_specifier: FLOAT_32_T
#line 233 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                 { yylhs.value.as < nezoku::TypeSpecifier > () = nezoku::TypeSpecifier::F32Type; }
#line 1021 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 19: // type_specifier: FLOAT_64_T
#line 234 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                 { yylhs.value.as < nezoku::TypeSpecifier > () = nezoku::TypeSpecifier::F64Type; }
#line 1027 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 20: // function_definition: type_specifier IDENTIFIER '(' parameter_list ')' statement
#line 238 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                                                 {
		yylhs.value.as < nezoku::FunctionDefinition* > () = new nezoku::FunctionDefinition(yystack_[5].value.as < nezoku::TypeSpecifier > (), yystack_[4].value.as < std::string > (), std::move(yystack_[2].value.as < std::vector<std::pair<nezoku::TypeSpecifier, std::string>> > ()), yystack_[0].value.as < nezoku::Statement* > ());
	}
#line 1035 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 21: // parameter_list: %empty
#line 244 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
             { yylhs.value.as < std::vector<std::pair<nezoku::TypeSpecifier, std::string>> > () = std::vector<std::pair<nezoku::TypeSpecifier, std::string>>(); }
#line 1041 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 22: // parameter_list: type_specifier IDENTIFIER
#line 245 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                {
		yylhs.value.as < std::vector<std::pair<nezoku::TypeSpecifier, std::string>> > () = std::vector<std::pair<nezoku::TypeSpecifier, std::string>>();
		yylhs.value.as < std::vector<std::pair<nezoku::TypeSpecifier, std::string>> > ().push_back(std::make_pair(yystack_[1].value.as < nezoku::TypeSpecifier > (), yystack_[0].value.as < std::string > ()));
	}
#line 1050 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 23: // parameter_list: parameter_list ',' type_specifier IDENTIFIER
#line 249 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                                   {
		yystack_[3].value.as < std::vector<std::pair<nezoku::TypeSpecifier, std::string>> > ().push_back(std::make_pair(yystack_[1].value.as < nezoku::TypeSpecifier > (), yystack_[0].value.as < std::string > ()));
		yylhs.value.as < std::vector<std::pair<nezoku::TypeSpecifier, std::string>> > () = yystack_[3].value.as < std::vector<std::pair<nezoku::TypeSpecifier, std::string>> > ();
	}
#line 1059 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 24: // compound_statement: '{' '}'
#line 256 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
              { yylhs.value.as < nezoku::Statement* > () = new nezoku::CompoundStatement(); }
#line 1065 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 25: // compound_statement: '{' block_item_list '}'
#line 257 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                              { yylhs.value.as < nezoku::Statement* > () = new nezoku::CompoundStatement(std::move(yystack_[1].value.as < std::vector<std::variant<nezoku::Declaration*, nezoku::Statement*>> > ())); }
#line 1071 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 26: // block_item_list: block_item
#line 261 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                 {
		yylhs.value.as < std::vector<std::variant<nezoku::Declaration*, nezoku::Statement*>> > () = std::vector<std::variant<nezoku::Declaration*, nezoku::Statement*>>();
		yylhs.value.as < std::vector<std::variant<nezoku::Declaration*, nezoku::Statement*>> > ().push_back(yystack_[0].value.as < std::variant<nezoku::Declaration*, nezoku::Statement*> > ());
	}
#line 1080 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 27: // block_item_list: block_item_list block_item
#line 265 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                 {
		yystack_[1].value.as < std::vector<std::variant<nezoku::Declaration*, nezoku::Statement*>> > ().push_back(yystack_[0].value.as < std::variant<nezoku::Declaration*, nezoku::Statement*> > ());
		yylhs.value.as < std::vector<std::variant<nezoku::Declaration*, nezoku::Statement*>> > () = yystack_[1].value.as < std::vector<std::variant<nezoku::Declaration*, nezoku::Statement*>> > ();
	}
#line 1089 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 28: // block_item: declaration
#line 272 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                  { yylhs.value.as < std::variant<nezoku::Declaration*, nezoku::Statement*> > () = std::variant<nezoku::Declaration*, nezoku::Statement*>(yystack_[0].value.as < nezoku::Declaration* > ()); }
#line 1095 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 29: // block_item: statement
#line 273 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                { yylhs.value.as < std::variant<nezoku::Declaration*, nezoku::Statement*> > () = std::variant<nezoku::Declaration*, nezoku::Statement*>(yystack_[0].value.as < nezoku::Statement* > ()); }
#line 1101 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 30: // statement: compound_statement
#line 277 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                         { yylhs.value.as < nezoku::Statement* > () = yystack_[0].value.as < nezoku::Statement* > (); }
#line 1107 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 31: // statement: selection_statement
#line 278 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                          { yylhs.value.as < nezoku::Statement* > () = yystack_[0].value.as < nezoku::Statement* > (); }
#line 1113 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 32: // statement: iteration_statement
#line 279 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                          { yylhs.value.as < nezoku::Statement* > () = yystack_[0].value.as < nezoku::Statement* > (); }
#line 1119 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 33: // statement: expression_statement
#line 280 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                           { yylhs.value.as < nezoku::Statement* > () = yystack_[0].value.as < nezoku::Statement* > (); }
#line 1125 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 34: // statement: jump_statement
#line 281 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                     { yylhs.value.as < nezoku::Statement* > () = yystack_[0].value.as < nezoku::Statement* > (); }
#line 1131 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 35: // selection_statement: IF_KW '(' expression ')' statement
#line 285 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                                      { yylhs.value.as < nezoku::Statement* > () = new nezoku::SelectionStatement(yystack_[2].value.as < nezoku::Expression* > (), yystack_[0].value.as < nezoku::Statement* > ()); }
#line 1137 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 36: // selection_statement: IF_KW '(' expression ')' statement ELSE_KW statement
#line 286 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                                           { yylhs.value.as < nezoku::Statement* > () = new nezoku::SelectionStatement(yystack_[4].value.as < nezoku::Expression* > (), yystack_[2].value.as < nezoku::Statement* > (), yystack_[0].value.as < nezoku::Statement* > ()); }
#line 1143 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 37: // iteration_statement: WHILE_KW '(' expression ')' statement
#line 290 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                            {
		auto iteration_statement = new nezoku::IterationStatement();
		iteration_statement->add_condition(yystack_[2].value.as < nezoku::Expression* > ());
		iteration_statement->add_statement(yystack_[0].value.as < nezoku::Statement* > ());
		yylhs.value.as < nezoku::Statement* > () = iteration_statement;
	}
#line 1154 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 38: // jump_statement: CONTINUE_KW ';'
#line 327 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                      { yylhs.value.as < nezoku::Statement* > () = new nezoku::ContinueStatement(); }
#line 1160 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 39: // jump_statement: BREAK_KW ';'
#line 328 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                   { yylhs.value.as < nezoku::Statement* > () = new nezoku::BreakStatement(); }
#line 1166 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 40: // jump_statement: RETURN_KW ';'
#line 329 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                    { yylhs.value.as < nezoku::Statement* > () = new nezoku::ReturnStatement(); }
#line 1172 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 41: // jump_statement: RETURN_KW expression ';'
#line 330 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                               { yylhs.value.as < nezoku::Statement* > () = new nezoku::ReturnStatement(yystack_[1].value.as < nezoku::Expression* > ()); }
#line 1178 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 42: // expression_statement: ';'
#line 334 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
          { yylhs.value.as < nezoku::Statement* > () = new nezoku::ExpressionStatement(); }
#line 1184 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 43: // expression_statement: expression ';'
#line 335 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                     { yylhs.value.as < nezoku::Statement* > () = new nezoku::ExpressionStatement(yystack_[1].value.as < nezoku::Expression* > ()); }
#line 1190 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 44: // expression: assignment_expression
#line 339 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                { yylhs.value.as < nezoku::Expression* > () = yystack_[0].value.as < nezoku::Expression* > (); }
#line 1196 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 45: // expression: expression ',' assignment_expression
#line 340 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                               { yylhs.value.as < nezoku::Expression* > () = new nezoku::CommaExpression(yystack_[2].value.as < nezoku::Expression* > (), yystack_[0].value.as < nezoku::Expression* > ()); }
#line 1202 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 46: // assignment_expression: logical_or_expression
#line 344 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                { yylhs.value.as < nezoku::Expression* > () = yystack_[0].value.as < nezoku::Expression* > (); }
#line 1208 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 47: // assignment_expression: primary_expression assignment_operator assignment_expression
#line 345 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                                                       {
		yylhs.value.as < nezoku::Expression* > () = new nezoku::AssignmentExpression(yystack_[2].value.as < nezoku::Expression* > (), yystack_[1].value.as < nezoku::AssignmentOperator > (), yystack_[0].value.as < nezoku::Expression* > ());
	}
#line 1216 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 48: // assignment_operator: '='
#line 351 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
              { yylhs.value.as < nezoku::AssignmentOperator > () = nezoku::AssignmentOperator::Assign; }
#line 1222 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 49: // assignment_operator: MUL_ASSIGN
#line 352 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                     { yylhs.value.as < nezoku::AssignmentOperator > () = nezoku::AssignmentOperator::MulAssign; }
#line 1228 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 50: // assignment_operator: DIV_ASSIGN
#line 353 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                     { yylhs.value.as < nezoku::AssignmentOperator > () = nezoku::AssignmentOperator::DivAssign; }
#line 1234 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 51: // assignment_operator: MOD_ASSIGN
#line 354 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                     { yylhs.value.as < nezoku::AssignmentOperator > () = nezoku::AssignmentOperator::ModAssign; }
#line 1240 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 52: // assignment_operator: ADD_ASSIGN
#line 355 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                     { yylhs.value.as < nezoku::AssignmentOperator > () = nezoku::AssignmentOperator::AddAssign; }
#line 1246 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 53: // assignment_operator: SUB_ASSIGN
#line 356 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                     { yylhs.value.as < nezoku::AssignmentOperator > () = nezoku::AssignmentOperator::SubAssign; }
#line 1252 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 54: // assignment_operator: SHL_ASSIGN
#line 357 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                     { yylhs.value.as < nezoku::AssignmentOperator > () = nezoku::AssignmentOperator::ShlAssign; }
#line 1258 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 55: // assignment_operator: SHR_ASSIGN
#line 358 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                     { yylhs.value.as < nezoku::AssignmentOperator > () = nezoku::AssignmentOperator::ShrAssign; }
#line 1264 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 56: // assignment_operator: AND_ASSIGN
#line 359 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                     { yylhs.value.as < nezoku::AssignmentOperator > () = nezoku::AssignmentOperator::AndAssign; }
#line 1270 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 57: // assignment_operator: XOR_ASSIGN
#line 360 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                     { yylhs.value.as < nezoku::AssignmentOperator > () = nezoku::AssignmentOperator::XorAssign; }
#line 1276 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 58: // assignment_operator: OR_ASSIGN
#line 361 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                    { yylhs.value.as < nezoku::AssignmentOperator > () = nezoku::AssignmentOperator::OrAssign; }
#line 1282 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 59: // logical_or_expression: logical_and_expression
#line 365 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                 { yylhs.value.as < nezoku::Expression* > () = yystack_[0].value.as < nezoku::Expression* > (); }
#line 1288 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 60: // logical_or_expression: logical_or_expression LOR_OP logical_and_expression
#line 366 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                                              { yylhs.value.as < nezoku::Expression* > () = new nezoku::LorExpression(yystack_[2].value.as < nezoku::Expression* > (), yystack_[0].value.as < nezoku::Expression* > ()); }
#line 1294 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 61: // logical_and_expression: inclusive_or_expression
#line 370 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                  { yylhs.value.as < nezoku::Expression* > () = yystack_[0].value.as < nezoku::Expression* > (); }
#line 1300 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 62: // logical_and_expression: logical_and_expression LAND_OP inclusive_or_expression
#line 371 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                                                 { yylhs.value.as < nezoku::Expression* > () = new nezoku::LandExpression(yystack_[2].value.as < nezoku::Expression* > (), yystack_[0].value.as < nezoku::Expression* > ()); }
#line 1306 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 63: // inclusive_or_expression: exclusive_or_expression
#line 375 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                  { yylhs.value.as < nezoku::Expression* > () = yystack_[0].value.as < nezoku::Expression* > (); }
#line 1312 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 64: // inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression
#line 376 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                                              { yylhs.value.as < nezoku::Expression* > () = new nezoku::OrExpression(yystack_[2].value.as < nezoku::Expression* > (), yystack_[0].value.as < nezoku::Expression* > ()); }
#line 1318 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 65: // exclusive_or_expression: and_expression
#line 380 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                         { yylhs.value.as < nezoku::Expression* > () = yystack_[0].value.as < nezoku::Expression* > (); }
#line 1324 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 66: // exclusive_or_expression: exclusive_or_expression '^' and_expression
#line 381 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                                     { yylhs.value.as < nezoku::Expression* > () = new nezoku::XorExpression(yystack_[2].value.as < nezoku::Expression* > (), yystack_[0].value.as < nezoku::Expression* > ()); }
#line 1330 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 67: // and_expression: equality_expression
#line 385 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                              { yylhs.value.as < nezoku::Expression* > () = yystack_[0].value.as < nezoku::Expression* > (); }
#line 1336 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 68: // and_expression: and_expression '&' equality_expression
#line 386 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                                 { yylhs.value.as < nezoku::Expression* > () = new nezoku::AndExpression(yystack_[2].value.as < nezoku::Expression* > (), yystack_[0].value.as < nezoku::Expression* > ()); }
#line 1342 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 69: // equality_expression: relational_expression
#line 390 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                { yylhs.value.as < nezoku::Expression* > () = yystack_[0].value.as < nezoku::Expression* > (); }
#line 1348 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 70: // equality_expression: equality_expression EQ_OP relational_expression
#line 391 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                                          { yylhs.value.as < nezoku::Expression* > () = new nezoku::EqExpression(yystack_[2].value.as < nezoku::Expression* > (), yystack_[0].value.as < nezoku::Expression* > ()); }
#line 1354 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 71: // equality_expression: equality_expression NEQ_OP relational_expression
#line 392 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                                           { yylhs.value.as < nezoku::Expression* > () = new nezoku::NeqExpression(yystack_[2].value.as < nezoku::Expression* > (), yystack_[0].value.as < nezoku::Expression* > ()); }
#line 1360 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 72: // relational_expression: shift_expression
#line 396 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                           { yylhs.value.as < nezoku::Expression* > () = yystack_[0].value.as < nezoku::Expression* > (); }
#line 1366 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 73: // relational_expression: relational_expression '<' shift_expression
#line 397 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                                     { yylhs.value.as < nezoku::Expression* > () = new nezoku::LessExpression(yystack_[2].value.as < nezoku::Expression* > (), yystack_[0].value.as < nezoku::Expression* > ()); }
#line 1372 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 74: // relational_expression: relational_expression '>' shift_expression
#line 398 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                                     { yylhs.value.as < nezoku::Expression* > () = new nezoku::GreaterExpression(yystack_[2].value.as < nezoku::Expression* > (), yystack_[0].value.as < nezoku::Expression* > ()); }
#line 1378 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 75: // relational_expression: relational_expression LEQ_OP shift_expression
#line 399 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                                        { yylhs.value.as < nezoku::Expression* > () = new nezoku::LeqExpression(yystack_[2].value.as < nezoku::Expression* > (), yystack_[0].value.as < nezoku::Expression* > ()); }
#line 1384 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 76: // relational_expression: relational_expression GEQ_OP shift_expression
#line 400 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                                        { yylhs.value.as < nezoku::Expression* > () = new nezoku::GeqExpression(yystack_[2].value.as < nezoku::Expression* > (), yystack_[0].value.as < nezoku::Expression* > ()); }
#line 1390 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 77: // shift_expression: additive_expression
#line 404 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                              { yylhs.value.as < nezoku::Expression* > () = yystack_[0].value.as < nezoku::Expression* > (); }
#line 1396 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 78: // shift_expression: shift_expression SHL_OP additive_expression
#line 405 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                                      { yylhs.value.as < nezoku::Expression* > () = new nezoku::ShlExpression(yystack_[2].value.as < nezoku::Expression* > (), yystack_[0].value.as < nezoku::Expression* > ()); }
#line 1402 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 79: // shift_expression: shift_expression SHR_OP additive_expression
#line 406 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                                      { yylhs.value.as < nezoku::Expression* > () = new nezoku::ShrExpression(yystack_[2].value.as < nezoku::Expression* > (), yystack_[0].value.as < nezoku::Expression* > ()); }
#line 1408 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 80: // additive_expression: multiplicative_expression
#line 410 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                    { yylhs.value.as < nezoku::Expression* > () = yystack_[0].value.as < nezoku::Expression* > (); }
#line 1414 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 81: // additive_expression: additive_expression '+' multiplicative_expression
#line 411 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                                            { yylhs.value.as < nezoku::Expression* > () = new nezoku::AddExpression(yystack_[2].value.as < nezoku::Expression* > (), yystack_[0].value.as < nezoku::Expression* > ()); }
#line 1420 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 82: // additive_expression: additive_expression '-' multiplicative_expression
#line 412 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                                            { yylhs.value.as < nezoku::Expression* > () = new nezoku::SubExpression(yystack_[2].value.as < nezoku::Expression* > (), yystack_[0].value.as < nezoku::Expression* > ()); }
#line 1426 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 83: // multiplicative_expression: primary_expression
#line 416 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                         { yylhs.value.as < nezoku::Expression* > () = yystack_[0].value.as < nezoku::Expression* > (); }
#line 1432 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 84: // multiplicative_expression: multiplicative_expression '*' primary_expression
#line 417 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                                           { yylhs.value.as < nezoku::Expression* > () = new nezoku::MulExpression(yystack_[2].value.as < nezoku::Expression* > (), yystack_[0].value.as < nezoku::Expression* > ()); }
#line 1438 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 85: // multiplicative_expression: multiplicative_expression '/' primary_expression
#line 418 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                                           { yylhs.value.as < nezoku::Expression* > () = new nezoku::DivExpression(yystack_[2].value.as < nezoku::Expression* > (), yystack_[0].value.as < nezoku::Expression* > ()); }
#line 1444 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 86: // multiplicative_expression: multiplicative_expression '%' primary_expression
#line 419 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                                                           { yylhs.value.as < nezoku::Expression* > () = new nezoku::ModExpression(yystack_[2].value.as < nezoku::Expression* > (), yystack_[0].value.as < nezoku::Expression* > ()); }
#line 1450 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 87: // primary_expression: IDENTIFIER
#line 423 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                 { yylhs.value.as < nezoku::Expression* > () = new nezoku::IdentifierExpression(yystack_[0].value.as < std::string > ()); }
#line 1456 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 88: // primary_expression: CONSTANT
#line 424 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
               { yylhs.value.as < nezoku::Expression* > () = new nezoku::ConstantExpression(yystack_[0].value.as < std::string > ()); }
#line 1462 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 89: // primary_expression: STRING_LITERAL
#line 425 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                         { yylhs.value.as < nezoku::Expression* > () = new nezoku::StringExpression(yystack_[0].value.as < std::string > ()); }
#line 1468 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;

  case 90: // primary_expression: '(' expression ')'
#line 426 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"
                             { yylhs.value.as < nezoku::Expression* > () = yystack_[1].value.as < nezoku::Expression* > (); }
#line 1474 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"
    break;


#line 1478 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"

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
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
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
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
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
    YY_STACK_PRINT ();
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
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -80;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     155,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   171,   -80,   -80,    -6,   -80,   -80,   -80,
      21,    10,   -80,   155,   -80,   -80,   -80,    10,   -52,   -80,
      -5,    33,     0,    30,    49,   -14,    20,    43,    38,    31,
      15,    68,    32,    34,   -80,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,    10,   -80,     6,   155,   -80,
     -80,    33,   -80,     0,    30,    49,   -14,    20,    20,    43,
      43,    43,    43,    38,    38,    31,    31,   -80,   -80,   -80,
     -80,    14,    24,    42,    45,    46,   -80,   113,   -80,   -80,
     -80,   -80,   -80,   -80,   -12,   101,   -80,    16,    10,   -80,
     -80,    10,   -80,   -80,   109,   125,   -80,   -80,   -80,   -80,
     -80,    36,    48,    -1,   -80,   -80,     6,     6,   121,   -80,
       6,   -80
  };

  const signed char
  parser::yydefact_[] =
  {
       0,    16,    17,    18,    19,     8,    12,     9,    13,    10,
      14,    11,    15,     0,     2,     4,     0,     5,     1,     3,
       0,     0,     6,    21,    87,    88,    89,     0,     0,    44,
      46,    59,    61,    63,    65,    67,    69,    72,    77,    80,
      83,     0,     0,     0,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    48,     0,    22,     0,     0,    90,
      45,    60,    83,    62,    64,    66,    68,    71,    70,    76,
      75,    73,    74,    78,    79,    81,    82,    84,    85,    86,
      47,     0,     0,     0,     0,     0,    42,     0,    30,    20,
      31,    32,    34,    33,     0,     0,    40,     0,     0,    38,
      39,     0,    24,    28,     0,     0,    26,    29,    43,    23,
      41,     0,     0,     0,    25,    27,     0,     0,    35,    37,
       0,    36
  };

  const signed char
  parser::yypgoto_[] =
  {
     -80,   -80,   115,   -79,   -20,   -80,   -80,   -80,   -80,     7,
     -76,   -80,   -80,   -80,   -80,   -19,   -36,   -80,   -80,    85,
      92,    93,    91,    94,    57,    -3,    53,    54,   -21
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,    13,    14,    15,    16,    17,    42,   108,   125,   126,
     127,   110,   111,   112,   113,   114,    29,    75,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    82
  };

  const unsigned char
  parser::yytable_[] =
  {
      40,   109,    28,    41,    44,    20,    40,    45,    43,    80,
     101,   102,    51,    52,   103,   104,   105,    24,    25,    26,
      46,    24,    25,    26,    40,    24,    25,    26,   123,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,   100,
      97,    98,    99,    21,   128,    48,   123,    45,    53,    54,
      89,    90,    91,    92,    40,    22,    40,    47,   115,    74,
     138,   139,   106,    27,   141,    21,   107,    27,    55,    56,
     116,    27,   130,    57,    58,    45,    49,    22,    23,    76,
      40,   118,   117,    61,    62,    63,    40,   124,    59,    60,
      77,    78,    79,    45,   136,    45,    50,    40,   119,   131,
      40,   120,   132,   121,    40,   124,   137,    45,    87,    88,
      93,    94,   129,    95,    96,    40,    40,   101,   102,    40,
     133,   103,   104,   105,    24,    25,    26,   140,    19,   101,
     102,    81,   135,   103,   104,   105,    24,    25,    26,    83,
      85,    84,     0,     0,    86,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,   106,
      27,    18,     0,   107,   122,     0,     0,     0,     0,     0,
       0,   106,    27,     0,     0,   107,   134,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12
  };

  const short
  parser::yycheck_[] =
  {
      21,    77,    21,    23,    56,    11,    27,    59,    27,    45,
       4,     5,    26,    27,     8,     9,    10,    11,    12,    13,
      25,    11,    12,    13,    45,    11,    12,    13,   107,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    75,
      61,    62,    63,    44,    56,    45,   125,    59,    28,    29,
      53,    54,    55,    56,    75,    56,    77,    24,    78,    44,
     136,   137,    56,    57,   140,    44,    60,    57,    48,    49,
      56,    57,    56,    30,    31,    59,    46,    56,    57,    11,
     101,    57,   101,    52,    53,    54,   107,   107,    50,    51,
      58,    59,    58,    59,    58,    59,    47,   118,    56,   118,
     121,    56,   121,    57,   125,   125,    58,    59,    51,    52,
      57,    58,    11,    59,    60,   136,   137,     4,     5,   140,
      11,     8,     9,    10,    11,    12,    13,     6,    13,     4,
       5,    46,   125,     8,     9,    10,    11,    12,    13,    47,
      49,    48,    -1,    -1,    50,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    56,
      57,     0,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    -1,    -1,    60,    61,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43
  };

  const signed char
  parser::yystos_[] =
  {
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    63,    64,    65,    66,    67,     0,    64,
      11,    44,    56,    57,    11,    12,    13,    57,    77,    78,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    66,    68,    77,    56,    59,    25,    24,    45,    46,
      47,    26,    27,    28,    29,    48,    49,    30,    31,    50,
      51,    52,    53,    54,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    44,    79,    11,    58,    59,    58,
      78,    81,    90,    82,    83,    84,    85,    86,    86,    87,
      87,    87,    87,    88,    88,    89,    89,    90,    90,    90,
      78,     4,     5,     8,     9,    10,    56,    60,    69,    72,
      73,    74,    75,    76,    77,    66,    56,    77,    57,    56,
      56,    57,    61,    65,    66,    70,    71,    72,    56,    11,
      56,    77,    77,    11,    61,    71,    58,    58,    72,    72,
       6,    72
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    62,    63,    63,    64,    64,    65,    65,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      67,    68,    68,    68,    69,    69,    70,    70,    71,    71,
      72,    72,    72,    72,    72,    73,    73,    74,    75,    75,
      75,    75,    76,    76,    77,    77,    78,    78,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    80,
      80,    81,    81,    82,    82,    83,    83,    84,    84,    85,
      85,    85,    86,    86,    86,    86,    86,    87,    87,    87,
      88,    88,    88,    89,    89,    89,    89,    90,    90,    90,
      90
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     3,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       6,     0,     2,     4,     2,     3,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     5,     7,     5,     2,     2,
       2,     3,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     1,     1,
       3
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "END", "RETURN_KW",
  "IF_KW", "ELSE_KW", "FOR_KW", "CONTINUE_KW", "BREAK_KW", "WHILE_KW",
  "IDENTIFIER", "CONSTANT", "STRING_LITERAL", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "SHL_ASSIGN", "SHR_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "LAND_OP", "LOR_OP", "NEQ_OP",
  "EQ_OP", "GEQ_OP", "LEQ_OP", "SHL_OP", "SHR_OP", "BOOL_T", "CHAR_T",
  "FLOAT_32_T", "FLOAT_64_T", "INT_8_T", "UINT_8_T", "INT_16_T",
  "UINT_16_T", "INT_32_T", "UINT_32_T", "INT_64_T", "UINT_64_T", "'='",
  "'|'", "'^'", "'&'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "\"then\"", "';'", "'('", "')'", "','", "'{'", "'}'", "$accept",
  "translation_unit", "external_declaration", "declaration",
  "type_specifier", "function_definition", "parameter_list",
  "compound_statement", "block_item_list", "block_item", "statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "expression_statement", "expression", "assignment_expression",
  "assignment_operator", "logical_or_expression", "logical_and_expression",
  "inclusive_or_expression", "exclusive_or_expression", "and_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "primary_expression", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   201,   201,   206,   213,   214,   218,   219,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     238,   244,   245,   249,   256,   257,   261,   265,   272,   273,
     277,   278,   279,   280,   281,   285,   286,   290,   327,   328,
     329,   330,   334,   335,   339,   340,   344,   345,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   365,
     366,   370,   371,   375,   376,   380,   381,   385,   386,   390,
     391,   392,   396,   397,   398,   399,   400,   404,   405,   406,
     410,   411,   412,   416,   417,   418,   419,   423,   424,   425,
     426
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
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


} // yy
#line 2069 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.cpp"

#line 429 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"


void yy::parser::error(const location_type& location, const std::string& message) {
	std::cerr << location << ": " << message << std::endl;
}
