%language "c++"
%skeleton "lalr1.cc"
%locations

%define api.token.constructor
%define api.value.type variant

%define parse.assert
%define parse.trace
%define parse.error verbose

%code requires {
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
}

%code top {
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

	#include "driver.hpp"

	static yy::parser::symbol_type yylex(nezoku::Driver& driver, nezoku::Scanner& scanner) {
        return scanner.ScanToken();
    }
}

%param { nezoku::Driver& driver }
%param { nezoku::Scanner& scanner }

/* Special */

%token END

/* Keywords */

%token RETURN_KW
%token IF_KW
%token ELSE_KW
%token FOR_KW
%token CONTINUE_KW
%token BREAK_KW
%token WHILE_KW

/* Values & identifiers */

%token <std::string> IDENTIFIER "identifier"
%token <std::string> CONSTANT "constant"
%token <std::string> STRING_LITERAL "string"

/* Assignements */

%token MUL_ASSIGN
%token DIV_ASSIGN
%token MOD_ASSIGN
%token ADD_ASSIGN
%token SUB_ASSIGN
%token SHL_ASSIGN
%token SHR_ASSIGN
%token AND_ASSIGN
%token XOR_ASSIGN
%token OR_ASSIGN

/* Operators */

%token LAND_OP
%token LOR_OP
%token NEQ_OP
%token EQ_OP
%token GEQ_OP
%token LEQ_OP
%token SHL_OP
%token SHR_OP

/* Types */

%token BOOL_T
%token CHAR_T
%token FLOAT_32_T
%token FLOAT_64_T
%token INT_8_T
%token UINT_8_T
%token INT_16_T
%token UINT_16_T
%token INT_32_T
%token UINT_32_T
%token INT_64_T
%token UINT_64_T

/* Associativeness */

%right '=' MUL_ASSIGN DIV_ASSIGN
		MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN SHL_ASSIGN
		SHR_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN
%left LOR_OP
%left LAND_OP
%left '|'
%left '^'
%left '&'
%left EQ_OP NEQ_OP
%left LEQ_OP GEQ_OP '<' '>'
%left SHL_OP SHR_OP
%left '+' '-'
%left '*' '/' '%'

/* Precedence */

%precedence "then"
%precedence ELSE_KW

/* AST Types */

%nterm <nezoku::TranslationUnit*> translation_unit
%nterm <std::variant<nezoku::Declaration*, nezoku::FunctionDefinition*>> external_declaration
%nterm <nezoku::Declaration*> declaration
%nterm <nezoku::FunctionDefinition*> function_definition
%nterm <std::vector<std::pair<nezoku::TypeSpecifier, std::string>>> parameter_list
%nterm <std::vector<std::variant<nezoku::Declaration*, nezoku::Statement*>>> block_item_list
%nterm <std::variant<nezoku::Declaration*, nezoku::Statement*>> block_item
%nterm <nezoku::TypeSpecifier> type_specifier
%nterm <nezoku::AssignmentOperator> assignment_operator
%nterm <nezoku::Statement*> statement
%nterm <nezoku::Statement*> compound_statement
%nterm <nezoku::Statement*> selection_statement
%nterm <nezoku::Statement*> iteration_statement
%nterm <nezoku::Statement*> expression_statement
%nterm <nezoku::Statement*> jump_statement
%nterm <nezoku::Expression*> expression
%nterm <nezoku::Expression*> assignment_expression
%nterm <nezoku::Expression*> logical_or_expression
%nterm <nezoku::Expression*> logical_and_expression
%nterm <nezoku::Expression*> inclusive_or_expression
%nterm <nezoku::Expression*> exclusive_or_expression
%nterm <nezoku::Expression*> and_expression
%nterm <nezoku::Expression*> equality_expression
%nterm <nezoku::Expression*> relational_expression
%nterm <nezoku::Expression*> shift_expression
%nterm <nezoku::Expression*> additive_expression
%nterm <nezoku::Expression*> multiplicative_expression
%nterm <nezoku::Expression*> primary_expression

%%

%start translation_unit;

translation_unit
    : external_declaration {
		$$ = new nezoku::TranslationUnit();
		$$->add_external_declaration(std::move($1));
	};
    | translation_unit external_declaration {
		$1->add_external_declaration(std::move($2));
		$$ = $1;
	};
    ;

external_declaration
    : declaration { $$ = std::variant<nezoku::Declaration*, nezoku::FunctionDefinition*>($1); };
    | function_definition { $$ = std::variant<nezoku::Declaration*, nezoku::FunctionDefinition*>($1); };
    ;

declaration
    : type_specifier "identifier" ';' { $$ = new nezoku::Declaration($1, $2); };
    | type_specifier "identifier" '=' expression ';' { $$ = new nezoku::Declaration($1, $2, $4); };
    ;

type_specifier
    : INT_8_T { $$ = nezoku::TypeSpecifier::I8Type; };
    | INT_16_T { $$ = nezoku::TypeSpecifier::I16Type; };
    | INT_32_T { $$ = nezoku::TypeSpecifier::I32Type; };
    | INT_64_T { $$ = nezoku::TypeSpecifier::I64Type; };
    | UINT_8_T { $$ = nezoku::TypeSpecifier::U8Type; };
    | UINT_16_T { $$ = nezoku::TypeSpecifier::U16Type; };
    | UINT_32_T { $$ = nezoku::TypeSpecifier::U32Type; };
    | UINT_64_T { $$ = nezoku::TypeSpecifier::U64Type; };
    | BOOL_T { $$ = nezoku::TypeSpecifier::BoolType; };
    | CHAR_T { $$ = nezoku::TypeSpecifier::CharType; };
    | FLOAT_32_T { $$ = nezoku::TypeSpecifier::F32Type; };
    | FLOAT_64_T { $$ = nezoku::TypeSpecifier::F64Type; };
    ;

function_definition
    : type_specifier "identifier" '(' parameter_list ')' statement {
		$$ = new nezoku::FunctionDefinition($1, $2, std::move($4), $6);
	};
    ;

parameter_list
    : %empty { $$ = std::vector<std::pair<nezoku::TypeSpecifier, std::string>>(); };
    | type_specifier "identifier" {
		$$ = std::vector<std::pair<nezoku::TypeSpecifier, std::string>>();
		$$.push_back(std::make_pair($1, $2));
	};
    | parameter_list ',' type_specifier "identifier" {
		$1.push_back(std::make_pair($3, $4));
		$$ = $1;
	};
    ;

compound_statement
    : '{' '}' { $$ = new nezoku::CompoundStatement(); };
    | '{' block_item_list '}' { $$ = new nezoku::CompoundStatement(std::move($2)); };
    ;

block_item_list
    : block_item {
		$$ = std::vector<std::variant<nezoku::Declaration*, nezoku::Statement*>>();
		$$.push_back($1);
	};
    | block_item_list block_item {
		$1.push_back($2);
		$$ = $1;
	};
    ;

block_item
    : declaration { $$ = std::variant<nezoku::Declaration*, nezoku::Statement*>($1); };
    | statement { $$ = std::variant<nezoku::Declaration*, nezoku::Statement*>($1); };
    ;

statement
    : compound_statement { $$ = $1; };
    | selection_statement { $$ = $1; };
    | iteration_statement { $$ = $1; };
    | expression_statement { $$ = $1; };
    | jump_statement { $$ = $1; };
    ;

selection_statement
    : IF_KW '(' expression ')' statement %prec "then" { $$ = new nezoku::SelectionStatement($3, $5); };
    | IF_KW '(' expression ')' statement ELSE_KW statement { $$ = new nezoku::SelectionStatement($3, $5, $7); };
    ;

iteration_statement
    : WHILE_KW '(' expression ')' statement {
		auto iteration_statement = new nezoku::IterationStatement();
		iteration_statement->add_condition($3);
		iteration_statement->add_statement($5);
		$$ = iteration_statement;
	};
    /*
	| FOR_KW '(' expression_statement expression_statement ')' statement {
		$$ = new nezoku::IterationStatement();
		$$->add_initialization($3);
		$$->add_condition($4);
		$$->add_statement($6);
	};
	| FOR_KW '(' expression_statement expression_statement expression ')' statement {
		$$ = new nezoku::IterationStatement();
		$$->add_initialization($3);
		$$->add_condition($4);
		$$->add_updation($5);
		$$->add_statement($7);
	};
	| FOR_KW '(' declaration expression_statement ')' statement {
		$$ = new nezoku::IterationStatement();
		$$->add_initialization($3);
		$$->add_condition($4);
		$$->add_statement($6);
	};
	| FOR_KW '(' declaration expression_statement expression ')' statement {
		$$ = new nezoku::IterationStatement();
		$$->add_initialization($3);
		$$->add_condition($4);
		$$->add_updation($5);
		$$->add_statement($7);
	};
	*/
    ;

jump_statement
    : CONTINUE_KW ';' { $$ = nezoku::JumpStatement::create_continue(); };
    | BREAK_KW ';' { $$ = nezoku::JumpStatement::create_break(); };
    | RETURN_KW ';' { $$ = nezoku::JumpStatement::create_return(); };
    | RETURN_KW expression ';' { $$ = nezoku::JumpStatement::create_return($2); };
    ;

expression_statement
    : ';' { $$ = new nezoku::ExpressionStatement(); };
    | expression ';' { $$ = new nezoku::ExpressionStatement($1); };
    ;

expression
	: assignment_expression { $$ = $1; };
	| expression ',' assignment_expression { $$ = new nezoku::CommaExpression($1, $3); };
	;

assignment_expression
	: logical_or_expression { $$ = $1; };
	| primary_expression assignment_operator assignment_expression {
		$$ = new nezoku::AssignmentExpression($1, $2, $3);
	};
	;

assignment_operator
	: '=' { $$ = nezoku::AssignmentOperator::Assign; };
	| MUL_ASSIGN { $$ = nezoku::AssignmentOperator::MulAssign; };
	| DIV_ASSIGN { $$ = nezoku::AssignmentOperator::DivAssign; };
	| MOD_ASSIGN { $$ = nezoku::AssignmentOperator::ModAssign; };
	| ADD_ASSIGN { $$ = nezoku::AssignmentOperator::AddAssign; };
	| SUB_ASSIGN { $$ = nezoku::AssignmentOperator::SubAssign; };
	| SHL_ASSIGN { $$ = nezoku::AssignmentOperator::ShlAssign; };
	| SHR_ASSIGN { $$ = nezoku::AssignmentOperator::ShrAssign; };
	| AND_ASSIGN { $$ = nezoku::AssignmentOperator::AndAssign; };
	| XOR_ASSIGN { $$ = nezoku::AssignmentOperator::XorAssign; };
	| OR_ASSIGN { $$ = nezoku::AssignmentOperator::OrAssign; };
	;

logical_or_expression
	: logical_and_expression { $$ = $1; };
	| logical_or_expression LOR_OP logical_and_expression { $$ = new nezoku::LorExpression($1, $3); };
	;

logical_and_expression
	: inclusive_or_expression { $$ = $1; };
	| logical_and_expression LAND_OP inclusive_or_expression { $$ = new nezoku::LandExpression($1, $3); };
	;

inclusive_or_expression
	: exclusive_or_expression { $$ = $1; };
	| inclusive_or_expression '|' exclusive_or_expression { $$ = new nezoku::OrExpression($1, $3); };
	;

exclusive_or_expression
	: and_expression { $$ = $1; };
	| exclusive_or_expression '^' and_expression { $$ = new nezoku::XorExpression($1, $3); };
	;

and_expression
	: equality_expression { $$ = $1; };
	| and_expression '&' equality_expression { $$ = new nezoku::AndExpression($1, $3); };
	;

equality_expression
	: relational_expression { $$ = $1; };
	| equality_expression EQ_OP relational_expression { $$ = new nezoku::EqExpression($1, $3); };
	| equality_expression NEQ_OP relational_expression { $$ = new nezoku::NeqExpression($1, $3); };
	;

relational_expression
	: shift_expression { $$ = $1; };
	| relational_expression '<' shift_expression { $$ = new nezoku::LessExpression($1, $3); };
	| relational_expression '>' shift_expression { $$ = new nezoku::GreaterExpression($1, $3); };
	| relational_expression LEQ_OP shift_expression { $$ = new nezoku::LeqExpression($1, $3); };
	| relational_expression GEQ_OP shift_expression { $$ = new nezoku::GeqExpression($1, $3); };
	;

shift_expression
	: additive_expression { $$ = $1; };
	| shift_expression SHL_OP additive_expression { $$ = new nezoku::ShlExpression($1, $3); };
	| shift_expression SHR_OP additive_expression { $$ = new nezoku::ShrExpression($1, $3); };
	;

additive_expression
	: multiplicative_expression { $$ = $1; };
	| additive_expression '+' multiplicative_expression { $$ = new nezoku::AddExpression($1, $3); };
	| additive_expression '-' multiplicative_expression { $$ = new nezoku::SubExpression($1, $3); };
	;

multiplicative_expression
    : primary_expression { $$ = $1; };
	| multiplicative_expression '*' primary_expression { $$ = new nezoku::MulExpression($1, $3); };
	| multiplicative_expression '/' primary_expression { $$ = new nezoku::DivExpression($1, $3); };
	| multiplicative_expression '%' primary_expression { $$ = new nezoku::ModExpression($1, $3); };
	;

primary_expression
    : "identifier" { $$ = new nezoku::IdentifierExpression($1); };
    | "constant" { $$ = new nezoku::ConstantExpression($1); };
	| "string" { $$ = new nezoku::StringExpression($1); };
	| '(' expression ')' { $$ = $2; };
    ;

%%

void yy::parser::error(const location_type& location, const std::string& message) {
	std::cerr << location << ": " << message << std::endl;
}
