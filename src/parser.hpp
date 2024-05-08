// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file /home/stanislav/Mipt/compilers-course/nezoku/src/parser.hpp
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_HOME_STANISLAV_MIPT_COMPILERS_COURSE_NEZOKU_SRC_PARSER_HPP_INCLUDED
# define YY_YY_HOME_STANISLAV_MIPT_COMPILERS_COURSE_NEZOKU_SRC_PARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 12 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.y"

	#include <cinttypes>
	#include <cstdlib>
	#include <cstring>
	#include <iostream>
	#include <string>
	#include <vector>
	#include <variant>
	#include <utility>

	#include "ast/common.hpp"
	#include "ast/type_specifier.hpp"
	#include "ast/assignment_operator.hpp"

	namespace nezoku {
		class Driver;
		class Scanner;
	}; // namespace nezoku

#line 69 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.hpp"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

namespace yy {
#line 209 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.hpp"




  /// A Bison parser.
  class parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
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
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // assignment_operator
      char dummy1[sizeof (nezoku::AssignmentOperator)];

      // declaration
      char dummy2[sizeof (nezoku::Declaration*)];

      // expression
      // assignment_expression
      // logical_or_expression
      // logical_and_expression
      // inclusive_or_expression
      // exclusive_or_expression
      // and_expression
      // equality_expression
      // relational_expression
      // shift_expression
      // additive_expression
      // multiplicative_expression
      // primary_expression
      char dummy3[sizeof (nezoku::Expression*)];

      // function_definition
      char dummy4[sizeof (nezoku::FunctionDefinition*)];

      // compound_statement
      // statement
      // selection_statement
      // iteration_statement
      // jump_statement
      // expression_statement
      char dummy5[sizeof (nezoku::Statement*)];

      // translation_unit
      char dummy6[sizeof (nezoku::TranslationUnit*)];

      // type_specifier
      char dummy7[sizeof (nezoku::TypeSpecifier)];

      // IDENTIFIER
      // CONSTANT
      // STRING_LITERAL
      char dummy8[sizeof (std::string)];

      // external_declaration
      char dummy9[sizeof (std::variant<nezoku::Declaration*, nezoku::FunctionDefinition*>)];

      // block_item
      char dummy10[sizeof (std::variant<nezoku::Declaration*, nezoku::Statement*>)];

      // parameter_list
      char dummy11[sizeof (std::vector<std::pair<nezoku::TypeSpecifier, std::string>>)];

      // block_item_list
      char dummy12[sizeof (std::vector<std::variant<nezoku::Declaration*, nezoku::Statement*>>)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    END = 0,                       // END
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    RETURN_KW = 258,               // RETURN_KW
    IF_KW = 259,                   // IF_KW
    ELSE_KW = 260,                 // ELSE_KW
    FOR_KW = 261,                  // FOR_KW
    CONTINUE_KW = 262,             // CONTINUE_KW
    BREAK_KW = 263,                // BREAK_KW
    WHILE_KW = 264,                // WHILE_KW
    IDENTIFIER = 265,              // IDENTIFIER
    CONSTANT = 266,                // CONSTANT
    STRING_LITERAL = 267,          // STRING_LITERAL
    MUL_ASSIGN = 268,              // MUL_ASSIGN
    DIV_ASSIGN = 269,              // DIV_ASSIGN
    MOD_ASSIGN = 270,              // MOD_ASSIGN
    ADD_ASSIGN = 271,              // ADD_ASSIGN
    SUB_ASSIGN = 272,              // SUB_ASSIGN
    SHL_ASSIGN = 273,              // SHL_ASSIGN
    SHR_ASSIGN = 274,              // SHR_ASSIGN
    AND_ASSIGN = 275,              // AND_ASSIGN
    XOR_ASSIGN = 276,              // XOR_ASSIGN
    OR_ASSIGN = 277,               // OR_ASSIGN
    LAND = 278,                    // LAND
    LOR = 279,                     // LOR
    NEQ = 280,                     // NEQ
    EQ = 281,                      // EQ
    GEQ = 282,                     // GEQ
    LEQ = 283,                     // LEQ
    SHL = 284,                     // SHL
    SHR = 285,                     // SHR
    BOOL_T = 286,                  // BOOL_T
    CHAR_T = 287,                  // CHAR_T
    FLOAT_32_T = 288,              // FLOAT_32_T
    FLOAT_64_T = 289,              // FLOAT_64_T
    INT_8_T = 290,                 // INT_8_T
    UINT_8_T = 291,                // UINT_8_T
    INT_16_T = 292,                // INT_16_T
    UINT_16_T = 293,               // UINT_16_T
    INT_32_T = 294,                // INT_32_T
    UINT_32_T = 295,               // UINT_32_T
    INT_64_T = 296,                // INT_64_T
    UINT_64_T = 297,               // UINT_64_T
    OR = 298,                      // OR
    XOR = 299,                     // XOR
    AND = 300,                     // AND
    LESS = 301,                    // LESS
    GREATER = 302,                 // GREATER
    ADD = 303,                     // ADD
    SUB = 304,                     // SUB
    MUL = 305,                     // MUL
    DIV = 306,                     // DIV
    MOD = 307,                     // MOD
    SEMICOLON = 308,               // SEMICOLON
    ASSIGN = 309,                  // ASSIGN
    LPAREN = 310,                  // LPAREN
    RPAREN = 311,                  // RPAREN
    COMA = 312,                    // COMA
    LBRACKET = 313,                // LBRACKET
    RBRACKET = 314                 // RBRACKET
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 78, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // END
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_RETURN_KW = 3,                         // RETURN_KW
        S_IF_KW = 4,                             // IF_KW
        S_ELSE_KW = 5,                           // ELSE_KW
        S_FOR_KW = 6,                            // FOR_KW
        S_CONTINUE_KW = 7,                       // CONTINUE_KW
        S_BREAK_KW = 8,                          // BREAK_KW
        S_WHILE_KW = 9,                          // WHILE_KW
        S_IDENTIFIER = 10,                       // IDENTIFIER
        S_CONSTANT = 11,                         // CONSTANT
        S_STRING_LITERAL = 12,                   // STRING_LITERAL
        S_MUL_ASSIGN = 13,                       // MUL_ASSIGN
        S_DIV_ASSIGN = 14,                       // DIV_ASSIGN
        S_MOD_ASSIGN = 15,                       // MOD_ASSIGN
        S_ADD_ASSIGN = 16,                       // ADD_ASSIGN
        S_SUB_ASSIGN = 17,                       // SUB_ASSIGN
        S_SHL_ASSIGN = 18,                       // SHL_ASSIGN
        S_SHR_ASSIGN = 19,                       // SHR_ASSIGN
        S_AND_ASSIGN = 20,                       // AND_ASSIGN
        S_XOR_ASSIGN = 21,                       // XOR_ASSIGN
        S_OR_ASSIGN = 22,                        // OR_ASSIGN
        S_LAND = 23,                             // LAND
        S_LOR = 24,                              // LOR
        S_NEQ = 25,                              // NEQ
        S_EQ = 26,                               // EQ
        S_GEQ = 27,                              // GEQ
        S_LEQ = 28,                              // LEQ
        S_SHL = 29,                              // SHL
        S_SHR = 30,                              // SHR
        S_BOOL_T = 31,                           // BOOL_T
        S_CHAR_T = 32,                           // CHAR_T
        S_FLOAT_32_T = 33,                       // FLOAT_32_T
        S_FLOAT_64_T = 34,                       // FLOAT_64_T
        S_INT_8_T = 35,                          // INT_8_T
        S_UINT_8_T = 36,                         // UINT_8_T
        S_INT_16_T = 37,                         // INT_16_T
        S_UINT_16_T = 38,                        // UINT_16_T
        S_INT_32_T = 39,                         // INT_32_T
        S_UINT_32_T = 40,                        // UINT_32_T
        S_INT_64_T = 41,                         // INT_64_T
        S_UINT_64_T = 42,                        // UINT_64_T
        S_43_ = 43,                              // '|'
        S_OR = 44,                               // OR
        S_45_ = 45,                              // '^'
        S_XOR = 46,                              // XOR
        S_47_ = 47,                              // '&'
        S_AND = 48,                              // AND
        S_49_ = 49,                              // '<'
        S_LESS = 50,                             // LESS
        S_51_ = 51,                              // '>'
        S_GREATER = 52,                          // GREATER
        S_53_ = 53,                              // '+'
        S_ADD = 54,                              // ADD
        S_55_ = 55,                              // '-'
        S_SUB = 56,                              // SUB
        S_57_ = 57,                              // '*'
        S_MUL = 58,                              // MUL
        S_59_ = 59,                              // '/'
        S_DIV = 60,                              // DIV
        S_61_ = 61,                              // '%'
        S_MOD = 62,                              // MOD
        S_63_ = 63,                              // ';'
        S_SEMICOLON = 64,                        // SEMICOLON
        S_65_ = 65,                              // '='
        S_ASSIGN = 66,                           // ASSIGN
        S_67_ = 67,                              // '('
        S_LPAREN = 68,                           // LPAREN
        S_69_ = 69,                              // ')'
        S_RPAREN = 70,                           // RPAREN
        S_71_ = 71,                              // ','
        S_COMA = 72,                             // COMA
        S_73_ = 73,                              // '{'
        S_LBRACKET = 74,                         // LBRACKET
        S_75_ = 75,                              // '}'
        S_RBRACKET = 76,                         // RBRACKET
        S_77_then_ = 77,                         // "then"
        S_YYACCEPT = 78,                         // $accept
        S_translation_unit = 79,                 // translation_unit
        S_external_declaration = 80,             // external_declaration
        S_declaration = 81,                      // declaration
        S_type_specifier = 82,                   // type_specifier
        S_function_definition = 83,              // function_definition
        S_parameter_list = 84,                   // parameter_list
        S_compound_statement = 85,               // compound_statement
        S_block_item_list = 86,                  // block_item_list
        S_block_item = 87,                       // block_item
        S_statement = 88,                        // statement
        S_selection_statement = 89,              // selection_statement
        S_iteration_statement = 90,              // iteration_statement
        S_jump_statement = 91,                   // jump_statement
        S_expression_statement = 92,             // expression_statement
        S_expression = 93,                       // expression
        S_assignment_expression = 94,            // assignment_expression
        S_assignment_operator = 95,              // assignment_operator
        S_logical_or_expression = 96,            // logical_or_expression
        S_logical_and_expression = 97,           // logical_and_expression
        S_inclusive_or_expression = 98,          // inclusive_or_expression
        S_exclusive_or_expression = 99,          // exclusive_or_expression
        S_and_expression = 100,                  // and_expression
        S_equality_expression = 101,             // equality_expression
        S_relational_expression = 102,           // relational_expression
        S_shift_expression = 103,                // shift_expression
        S_additive_expression = 104,             // additive_expression
        S_multiplicative_expression = 105,       // multiplicative_expression
        S_primary_expression = 106               // primary_expression
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_assignment_operator: // assignment_operator
        value.move< nezoku::AssignmentOperator > (std::move (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.move< nezoku::Declaration* > (std::move (that.value));
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
        value.move< nezoku::Expression* > (std::move (that.value));
        break;

      case symbol_kind::S_function_definition: // function_definition
        value.move< nezoku::FunctionDefinition* > (std::move (that.value));
        break;

      case symbol_kind::S_compound_statement: // compound_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_selection_statement: // selection_statement
      case symbol_kind::S_iteration_statement: // iteration_statement
      case symbol_kind::S_jump_statement: // jump_statement
      case symbol_kind::S_expression_statement: // expression_statement
        value.move< nezoku::Statement* > (std::move (that.value));
        break;

      case symbol_kind::S_translation_unit: // translation_unit
        value.move< nezoku::TranslationUnit* > (std::move (that.value));
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.move< nezoku::TypeSpecifier > (std::move (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONSTANT: // CONSTANT
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_external_declaration: // external_declaration
        value.move< std::variant<nezoku::Declaration*, nezoku::FunctionDefinition*> > (std::move (that.value));
        break;

      case symbol_kind::S_block_item: // block_item
        value.move< std::variant<nezoku::Declaration*, nezoku::Statement*> > (std::move (that.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.move< std::vector<std::pair<nezoku::TypeSpecifier, std::string>> > (std::move (that.value));
        break;

      case symbol_kind::S_block_item_list: // block_item_list
        value.move< std::vector<std::variant<nezoku::Declaration*, nezoku::Statement*>> > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, nezoku::AssignmentOperator&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const nezoku::AssignmentOperator& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, nezoku::Declaration*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const nezoku::Declaration*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, nezoku::Expression*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const nezoku::Expression*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, nezoku::FunctionDefinition*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const nezoku::FunctionDefinition*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, nezoku::Statement*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const nezoku::Statement*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, nezoku::TranslationUnit*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const nezoku::TranslationUnit*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, nezoku::TypeSpecifier&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const nezoku::TypeSpecifier& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::variant<nezoku::Declaration*, nezoku::FunctionDefinition*>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::variant<nezoku::Declaration*, nezoku::FunctionDefinition*>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::variant<nezoku::Declaration*, nezoku::Statement*>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::variant<nezoku::Declaration*, nezoku::Statement*>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<std::pair<nezoku::TypeSpecifier, std::string>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<std::pair<nezoku::TypeSpecifier, std::string>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<std::variant<nezoku::Declaration*, nezoku::Statement*>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<std::variant<nezoku::Declaration*, nezoku::Statement*>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_assignment_operator: // assignment_operator
        value.template destroy< nezoku::AssignmentOperator > ();
        break;

      case symbol_kind::S_declaration: // declaration
        value.template destroy< nezoku::Declaration* > ();
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
        value.template destroy< nezoku::Expression* > ();
        break;

      case symbol_kind::S_function_definition: // function_definition
        value.template destroy< nezoku::FunctionDefinition* > ();
        break;

      case symbol_kind::S_compound_statement: // compound_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_selection_statement: // selection_statement
      case symbol_kind::S_iteration_statement: // iteration_statement
      case symbol_kind::S_jump_statement: // jump_statement
      case symbol_kind::S_expression_statement: // expression_statement
        value.template destroy< nezoku::Statement* > ();
        break;

      case symbol_kind::S_translation_unit: // translation_unit
        value.template destroy< nezoku::TranslationUnit* > ();
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.template destroy< nezoku::TypeSpecifier > ();
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONSTANT: // CONSTANT
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_external_declaration: // external_declaration
        value.template destroy< std::variant<nezoku::Declaration*, nezoku::FunctionDefinition*> > ();
        break;

      case symbol_kind::S_block_item: // block_item
        value.template destroy< std::variant<nezoku::Declaration*, nezoku::Statement*> > ();
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.template destroy< std::vector<std::pair<nezoku::TypeSpecifier, std::string>> > ();
        break;

      case symbol_kind::S_block_item_list: // block_item_list
        value.template destroy< std::vector<std::variant<nezoku::Declaration*, nezoku::Statement*>> > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::END
                   || (token::YYerror <= tok && tok <= token::WHILE_KW)
                   || (token::MUL_ASSIGN <= tok && tok <= token::UINT_64_T)
                   || tok == 124
                   || tok == token::OR
                   || tok == 94
                   || tok == token::XOR
                   || tok == 38
                   || tok == token::AND
                   || tok == 60
                   || tok == token::LESS
                   || tok == 62
                   || tok == token::GREATER
                   || tok == 43
                   || tok == token::ADD
                   || tok == 45
                   || tok == token::SUB
                   || tok == 42
                   || tok == token::MUL
                   || tok == 47
                   || tok == token::DIV
                   || tok == 37
                   || tok == token::MOD
                   || tok == 59
                   || tok == token::SEMICOLON
                   || tok == 61
                   || tok == token::ASSIGN
                   || tok == 40
                   || tok == token::LPAREN
                   || tok == 41
                   || tok == token::RPAREN
                   || tok == 44
                   || tok == token::COMA
                   || tok == 123
                   || tok == token::LBRACKET
                   || tok == 125
                   || (token::RBRACKET <= tok && tok <= 315));
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT ((token::IDENTIFIER <= tok && tok <= token::STRING_LITERAL));
#endif
      }
    };

    /// Build a parser object.
    parser (nezoku::Driver& driver_yyarg, nezoku::Scanner& scanner_yyarg);
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

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

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN_KW (location_type l)
      {
        return symbol_type (token::RETURN_KW, std::move (l));
      }
#else
      static
      symbol_type
      make_RETURN_KW (const location_type& l)
      {
        return symbol_type (token::RETURN_KW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF_KW (location_type l)
      {
        return symbol_type (token::IF_KW, std::move (l));
      }
#else
      static
      symbol_type
      make_IF_KW (const location_type& l)
      {
        return symbol_type (token::IF_KW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE_KW (location_type l)
      {
        return symbol_type (token::ELSE_KW, std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE_KW (const location_type& l)
      {
        return symbol_type (token::ELSE_KW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOR_KW (location_type l)
      {
        return symbol_type (token::FOR_KW, std::move (l));
      }
#else
      static
      symbol_type
      make_FOR_KW (const location_type& l)
      {
        return symbol_type (token::FOR_KW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONTINUE_KW (location_type l)
      {
        return symbol_type (token::CONTINUE_KW, std::move (l));
      }
#else
      static
      symbol_type
      make_CONTINUE_KW (const location_type& l)
      {
        return symbol_type (token::CONTINUE_KW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BREAK_KW (location_type l)
      {
        return symbol_type (token::BREAK_KW, std::move (l));
      }
#else
      static
      symbol_type
      make_BREAK_KW (const location_type& l)
      {
        return symbol_type (token::BREAK_KW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE_KW (location_type l)
      {
        return symbol_type (token::WHILE_KW, std::move (l));
      }
#else
      static
      symbol_type
      make_WHILE_KW (const location_type& l)
      {
        return symbol_type (token::WHILE_KW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFIER (std::string v, location_type l)
      {
        return symbol_type (token::IDENTIFIER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IDENTIFIER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::IDENTIFIER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONSTANT (std::string v, location_type l)
      {
        return symbol_type (token::CONSTANT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CONSTANT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::CONSTANT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING_LITERAL (std::string v, location_type l)
      {
        return symbol_type (token::STRING_LITERAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING_LITERAL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::STRING_LITERAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MUL_ASSIGN (location_type l)
      {
        return symbol_type (token::MUL_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_MUL_ASSIGN (const location_type& l)
      {
        return symbol_type (token::MUL_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV_ASSIGN (location_type l)
      {
        return symbol_type (token::DIV_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_DIV_ASSIGN (const location_type& l)
      {
        return symbol_type (token::DIV_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD_ASSIGN (location_type l)
      {
        return symbol_type (token::MOD_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_MOD_ASSIGN (const location_type& l)
      {
        return symbol_type (token::MOD_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADD_ASSIGN (location_type l)
      {
        return symbol_type (token::ADD_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_ADD_ASSIGN (const location_type& l)
      {
        return symbol_type (token::ADD_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_ASSIGN (location_type l)
      {
        return symbol_type (token::SUB_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_SUB_ASSIGN (const location_type& l)
      {
        return symbol_type (token::SUB_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SHL_ASSIGN (location_type l)
      {
        return symbol_type (token::SHL_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_SHL_ASSIGN (const location_type& l)
      {
        return symbol_type (token::SHL_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SHR_ASSIGN (location_type l)
      {
        return symbol_type (token::SHR_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_SHR_ASSIGN (const location_type& l)
      {
        return symbol_type (token::SHR_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND_ASSIGN (location_type l)
      {
        return symbol_type (token::AND_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_AND_ASSIGN (const location_type& l)
      {
        return symbol_type (token::AND_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XOR_ASSIGN (location_type l)
      {
        return symbol_type (token::XOR_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_XOR_ASSIGN (const location_type& l)
      {
        return symbol_type (token::XOR_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR_ASSIGN (location_type l)
      {
        return symbol_type (token::OR_ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_OR_ASSIGN (const location_type& l)
      {
        return symbol_type (token::OR_ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LAND (location_type l)
      {
        return symbol_type (token::LAND, std::move (l));
      }
#else
      static
      symbol_type
      make_LAND (const location_type& l)
      {
        return symbol_type (token::LAND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOR (location_type l)
      {
        return symbol_type (token::LOR, std::move (l));
      }
#else
      static
      symbol_type
      make_LOR (const location_type& l)
      {
        return symbol_type (token::LOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEQ (location_type l)
      {
        return symbol_type (token::NEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_NEQ (const location_type& l)
      {
        return symbol_type (token::NEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQ (location_type l)
      {
        return symbol_type (token::EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_EQ (const location_type& l)
      {
        return symbol_type (token::EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GEQ (location_type l)
      {
        return symbol_type (token::GEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_GEQ (const location_type& l)
      {
        return symbol_type (token::GEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEQ (location_type l)
      {
        return symbol_type (token::LEQ, std::move (l));
      }
#else
      static
      symbol_type
      make_LEQ (const location_type& l)
      {
        return symbol_type (token::LEQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SHL (location_type l)
      {
        return symbol_type (token::SHL, std::move (l));
      }
#else
      static
      symbol_type
      make_SHL (const location_type& l)
      {
        return symbol_type (token::SHL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SHR (location_type l)
      {
        return symbol_type (token::SHR, std::move (l));
      }
#else
      static
      symbol_type
      make_SHR (const location_type& l)
      {
        return symbol_type (token::SHR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOL_T (location_type l)
      {
        return symbol_type (token::BOOL_T, std::move (l));
      }
#else
      static
      symbol_type
      make_BOOL_T (const location_type& l)
      {
        return symbol_type (token::BOOL_T, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHAR_T (location_type l)
      {
        return symbol_type (token::CHAR_T, std::move (l));
      }
#else
      static
      symbol_type
      make_CHAR_T (const location_type& l)
      {
        return symbol_type (token::CHAR_T, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOAT_32_T (location_type l)
      {
        return symbol_type (token::FLOAT_32_T, std::move (l));
      }
#else
      static
      symbol_type
      make_FLOAT_32_T (const location_type& l)
      {
        return symbol_type (token::FLOAT_32_T, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOAT_64_T (location_type l)
      {
        return symbol_type (token::FLOAT_64_T, std::move (l));
      }
#else
      static
      symbol_type
      make_FLOAT_64_T (const location_type& l)
      {
        return symbol_type (token::FLOAT_64_T, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT_8_T (location_type l)
      {
        return symbol_type (token::INT_8_T, std::move (l));
      }
#else
      static
      symbol_type
      make_INT_8_T (const location_type& l)
      {
        return symbol_type (token::INT_8_T, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UINT_8_T (location_type l)
      {
        return symbol_type (token::UINT_8_T, std::move (l));
      }
#else
      static
      symbol_type
      make_UINT_8_T (const location_type& l)
      {
        return symbol_type (token::UINT_8_T, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT_16_T (location_type l)
      {
        return symbol_type (token::INT_16_T, std::move (l));
      }
#else
      static
      symbol_type
      make_INT_16_T (const location_type& l)
      {
        return symbol_type (token::INT_16_T, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UINT_16_T (location_type l)
      {
        return symbol_type (token::UINT_16_T, std::move (l));
      }
#else
      static
      symbol_type
      make_UINT_16_T (const location_type& l)
      {
        return symbol_type (token::UINT_16_T, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT_32_T (location_type l)
      {
        return symbol_type (token::INT_32_T, std::move (l));
      }
#else
      static
      symbol_type
      make_INT_32_T (const location_type& l)
      {
        return symbol_type (token::INT_32_T, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UINT_32_T (location_type l)
      {
        return symbol_type (token::UINT_32_T, std::move (l));
      }
#else
      static
      symbol_type
      make_UINT_32_T (const location_type& l)
      {
        return symbol_type (token::UINT_32_T, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT_64_T (location_type l)
      {
        return symbol_type (token::INT_64_T, std::move (l));
      }
#else
      static
      symbol_type
      make_INT_64_T (const location_type& l)
      {
        return symbol_type (token::INT_64_T, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UINT_64_T (location_type l)
      {
        return symbol_type (token::UINT_64_T, std::move (l));
      }
#else
      static
      symbol_type
      make_UINT_64_T (const location_type& l)
      {
        return symbol_type (token::UINT_64_T, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR (location_type l)
      {
        return symbol_type (token::OR, std::move (l));
      }
#else
      static
      symbol_type
      make_OR (const location_type& l)
      {
        return symbol_type (token::OR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XOR (location_type l)
      {
        return symbol_type (token::XOR, std::move (l));
      }
#else
      static
      symbol_type
      make_XOR (const location_type& l)
      {
        return symbol_type (token::XOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (location_type l)
      {
        return symbol_type (token::AND, std::move (l));
      }
#else
      static
      symbol_type
      make_AND (const location_type& l)
      {
        return symbol_type (token::AND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESS (location_type l)
      {
        return symbol_type (token::LESS, std::move (l));
      }
#else
      static
      symbol_type
      make_LESS (const location_type& l)
      {
        return symbol_type (token::LESS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GREATER (location_type l)
      {
        return symbol_type (token::GREATER, std::move (l));
      }
#else
      static
      symbol_type
      make_GREATER (const location_type& l)
      {
        return symbol_type (token::GREATER, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADD (location_type l)
      {
        return symbol_type (token::ADD, std::move (l));
      }
#else
      static
      symbol_type
      make_ADD (const location_type& l)
      {
        return symbol_type (token::ADD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB (location_type l)
      {
        return symbol_type (token::SUB, std::move (l));
      }
#else
      static
      symbol_type
      make_SUB (const location_type& l)
      {
        return symbol_type (token::SUB, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MUL (location_type l)
      {
        return symbol_type (token::MUL, std::move (l));
      }
#else
      static
      symbol_type
      make_MUL (const location_type& l)
      {
        return symbol_type (token::MUL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV (location_type l)
      {
        return symbol_type (token::DIV, std::move (l));
      }
#else
      static
      symbol_type
      make_DIV (const location_type& l)
      {
        return symbol_type (token::DIV, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD (location_type l)
      {
        return symbol_type (token::MOD, std::move (l));
      }
#else
      static
      symbol_type
      make_MOD (const location_type& l)
      {
        return symbol_type (token::MOD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON (location_type l)
      {
        return symbol_type (token::SEMICOLON, std::move (l));
      }
#else
      static
      symbol_type
      make_SEMICOLON (const location_type& l)
      {
        return symbol_type (token::SEMICOLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN (location_type l)
      {
        return symbol_type (token::ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN (const location_type& l)
      {
        return symbol_type (token::ASSIGN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAREN (location_type l)
      {
        return symbol_type (token::LPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_LPAREN (const location_type& l)
      {
        return symbol_type (token::LPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPAREN (location_type l)
      {
        return symbol_type (token::RPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_RPAREN (const location_type& l)
      {
        return symbol_type (token::RPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMA (location_type l)
      {
        return symbol_type (token::COMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMA (const location_type& l)
      {
        return symbol_type (token::COMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACKET (location_type l)
      {
        return symbol_type (token::LBRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACKET (const location_type& l)
      {
        return symbol_type (token::LBRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACKET (location_type l)
      {
        return symbol_type (token::RBRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACKET (const location_type& l)
      {
        return symbol_type (token::RBRACKET, l);
      }
#endif


    class context
    {
    public:
      context (const parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const unsigned char yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
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
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

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
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 224,     ///< Last index in yytable_.
      yynnts_ = 29,  ///< Number of nonterminal symbols.
      yyfinal_ = 18 ///< Termination state number.
    };


    // User arguments.
    nezoku::Driver& driver;
    nezoku::Scanner& scanner;

  };

  inline
  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    61,    47,     2,
      67,    69,    57,    53,    71,    55,     2,    59,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    63,
      49,    65,    51,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    73,    43,    75,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    44,    46,
      48,    50,    52,    54,    56,    58,    60,    62,    64,    66,
      68,    70,    72,    74,    76,    77
    };
    // Last valid token kind.
    const int code_max = 315;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_assignment_operator: // assignment_operator
        value.copy< nezoku::AssignmentOperator > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.copy< nezoku::Declaration* > (YY_MOVE (that.value));
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
        value.copy< nezoku::Expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_definition: // function_definition
        value.copy< nezoku::FunctionDefinition* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_compound_statement: // compound_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_selection_statement: // selection_statement
      case symbol_kind::S_iteration_statement: // iteration_statement
      case symbol_kind::S_jump_statement: // jump_statement
      case symbol_kind::S_expression_statement: // expression_statement
        value.copy< nezoku::Statement* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_translation_unit: // translation_unit
        value.copy< nezoku::TranslationUnit* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.copy< nezoku::TypeSpecifier > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONSTANT: // CONSTANT
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_external_declaration: // external_declaration
        value.copy< std::variant<nezoku::Declaration*, nezoku::FunctionDefinition*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block_item: // block_item
        value.copy< std::variant<nezoku::Declaration*, nezoku::Statement*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.copy< std::vector<std::pair<nezoku::TypeSpecifier, std::string>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block_item_list: // block_item_list
        value.copy< std::vector<std::variant<nezoku::Declaration*, nezoku::Statement*>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_assignment_operator: // assignment_operator
        value.move< nezoku::AssignmentOperator > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_declaration: // declaration
        value.move< nezoku::Declaration* > (YY_MOVE (s.value));
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
        value.move< nezoku::Expression* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_function_definition: // function_definition
        value.move< nezoku::FunctionDefinition* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_compound_statement: // compound_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_selection_statement: // selection_statement
      case symbol_kind::S_iteration_statement: // iteration_statement
      case symbol_kind::S_jump_statement: // jump_statement
      case symbol_kind::S_expression_statement: // expression_statement
        value.move< nezoku::Statement* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_translation_unit: // translation_unit
        value.move< nezoku::TranslationUnit* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_type_specifier: // type_specifier
        value.move< nezoku::TypeSpecifier > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_CONSTANT: // CONSTANT
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_external_declaration: // external_declaration
        value.move< std::variant<nezoku::Declaration*, nezoku::FunctionDefinition*> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_block_item: // block_item
        value.move< std::variant<nezoku::Declaration*, nezoku::Statement*> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.move< std::vector<std::pair<nezoku::TypeSpecifier, std::string>> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_block_item_list: // block_item_list
        value.move< std::vector<std::variant<nezoku::Declaration*, nezoku::Statement*>> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


} // yy
#line 2833 "/home/stanislav/Mipt/compilers-course/nezoku/src/parser.hpp"




#endif // !YY_YY_HOME_STANISLAV_MIPT_COMPILERS_COURSE_NEZOKU_SRC_PARSER_HPP_INCLUDED
