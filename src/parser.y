%language "c++"
%skeleton "lalr1.cc"
%expect 1
%locations

%code top {
	#include <cinttypes>
	#include <cstdlib>
    #include <cstring>
    #include <iostream>
    #include <string>

    #include "location.hh"
    #include "stack.hh"
    #include "position.hh"
}

/* Keywords */

%token RETURN_KW
%token IF_KW
%token ELSE_KW
%token FOR_KW
%token CONTINUE_KW
%token BREAK_KW
%token WHILE_KW
%token SIZEOF_KW
%token ENUM_KW
%token CONST_KW
%token STRUCT_KW

/* Values & identifiers */

%token IDENTIFIER
%token CONSTANT
%token STRING_LITERAL

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
%token INC_OP
%token DEC_OP
%token PTR_OP

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

%start translation_unit

%%

translation_unit
    : external_declaraion
    | translation_unit external_declaraion
    ;

external_declaraion
    : declaration
    | function_definition
    ;

declaration
    : type_specifier IDENTIFIER ';'
    ;

type_specifier
    : INT_32_T
    ;

function_definition
    : type_specifier IDENTIFIER '(' argument_list ')' compound_statement
    ;

argument_list
    : %empty
    | type_specifier IDENTIFIER
    | argument_list ',' type_specifier IDENTIFIER
    ;

compound_statement
    : '{' '}'
    | '{' block_item_list '}'
    ;

block_item_list
    : block_item
    | block_item_list block_item
    ;

block_item
    : declaration
    | statement
    ;

statement
    : compound_statement
    | selection_statement
    | iteration_statement
    | expression_statement
    | jump_statement
    ;

selection_statement
    : IF_KW '(' expression ')' statement
    | IF_KW '(' expression ')' statement ELSE_KW statement
    ;

iteration_statement
    : WHILE_KW '(' expression ')' statement
    | FOR_KW '(' expression_statement expression_statement ')' statement
	| FOR_KW '(' expression_statement expression_statement expression ')' statement
	| FOR_KW '(' declaration expression_statement ')' statement
	| FOR_KW '(' declaration expression_statement expression ')' statement
    ;

jump_statement
    : CONTINUE_KW ';'
    | BREAK_KW ';'
    | RETURN_KW ';'
    | RETURN_KW expression ';'
    ;

expression_statement
    : ';'
    | expression ';'
    ;

expression
	: assignment_expression
	| expression ',' assignment_expression
	;

assignment_expression
	: logical_or_expression
	| primary_expression assignment_operator assignment_expression
	;

assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| SHL_ASSIGN
	| SHR_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression LOR_OP logical_and_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression LAND_OP inclusive_or_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NEQ_OP relational_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LEQ_OP shift_expression
	| relational_expression GEQ_OP shift_expression
	;

shift_expression
	: additive_expression
	| shift_expression SHL_OP additive_expression
	| shift_expression SHR_OP additive_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

multiplicative_expression
    : primary_expression
	| multiplicative_expression '*' primary_expression
	| multiplicative_expression '/' primary_expression
	| multiplicative_expression '%' primary_expression
	;

primary_expression
    : IDENTIFIER
    | CONSTANT
	| STRING_LITERAL
	| '(' expression ')'
    ;

%%

void yy::parser::error(const yy::parser::syntax_error& error) {
    std::cerr << error.location << ": " << error.what() << std::endl;
}
