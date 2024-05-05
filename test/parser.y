%language "c++"
%skeleton "lalr1.cc"
%expect 1
%locations

%code top {
	#incldue <cinttypes>
	#include <cstdlib>
    #include <cstring>
    #include <iostream>
    #include <string>
}

/* Keywords */

%token BREAK
%token CASE
%token CONST
%token CONTINUE
%token DEFAULT
%token DO
%token ELSE
%token ENUM
%token EXTERN
%token FOR
%token IF
%token RETURN
%token SIZEOF
%token STATIC
%token STRUCT
%token SWITCH
%token TYPEDEF
%token UNION
%token UNIT
%token WHILE

/* Special symbols */

%token COLON
%token COMA
%token LBRACE
%token LROUND
%token LSQUARE
%token PERIOD
%token RBRACE
%token RROUND
%token RSQUARE
%token SEMICOLON

/* Values & identifiers */

%token ENUM_CONST
%token FLOAT_CONST
%token FUNC_NAME
%token IDENTIFIER
%token INT_CONST
%token STRING_LITERAL
%token TYPEDEF_NAME

/* Assignements */

%token ADD_ASSIGN
%token AND_ASSIGN
%token ASSIGN
%token DIV_ASSIGN
%token LEFT_ASSIGN
%token MOD_ASSIGN
%token MUL_ASSIGN
%token OR_ASSIGN
%token RIGHT_ASSIGN
%token SUB_ASSIGN
%token XOR_ASSIGN

/* Operators */

%token ADD_OP
%token AND_OP
%token DEC_OP
%token DIV_OP
%token EQ_OP
%token GE_OP
%token GREATER_OP
%token INC_OP
%token LAND_OP
%token LEFT_OP
%token LESS_OP
%token LE_OP
%token LNOT_OP
%token LOR_OP
%token MOD_OP
%token ASTERISK_OP
%token NE_OP
%token NOT_OP
%token OR_OP
%token PTR_OP
%token QUESTION_OP
%token RIGHT_OP
%token SUB_OP
%token XOR_OP

/* Types */

%token BOOL
%token CHAR
%token FLOAT_32
%token FLOAT_64
%token INT_8
%token UINT_8
%token INT_16
%token UINT_16
%token INT_32
%token UINT_32
%token INT_64
%token UINT_64

%start translation_unit

%%

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	;

declaration
	: declaration_specifiers SEMICOLON
	| declaration_specifiers init_declarator_list SEMICOLON
	;

declaration_specifiers
	: storage_class_specifier declaration_specifiers
	| storage_class_specifier
	| type_specifier declaration_specifiers
	| type_specifier
	| type_qualifier declaration_specifiers
	| type_qualifier
    ;

declarator
	: pointer direct_declarator
	| direct_declarator
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

compound_statement
	: LBRACE RBRACE
	| LBRACE block_item_list RBRACE
	;

init_declarator_list
	: init_declarator
	| init_declarator_list COMA init_declarator
	;

storage_class_specifier
	: TYPEDEF
	| EXTERN
	| STATIC
	;

type_specifier
	: UNIT
	| CHAR
	| BOOL
	| TYPEDEF_NAME
	| float_type_specifier
	| int_type_specifier
	| struct_or_union_specifier
	| enum_specifier

float_type_specifier
	: FLOAT_32
	| FLOAT_64

int_type_specifier
	: INT_8
	| INT_16
	| INT_32
	| INT_64
	| UINT_8
	| UINT_16
	| UINT_32
	| UINT_64

struct_or_union
	: STRUCT
	| UNION
	;

struct_or_union_specifier
	: struct_or_union LBRACE struct_declaration_list RBRACE
	| struct_or_union IDENTIFIER LBRACE struct_declaration_list RBRACE
	| struct_or_union IDENTIFIER
	;

type_qualifier
	: CONST
	;

pointer
	: ASTERISK_OP type_qualifier_list pointer
	| ASTERISK_OP type_qualifier_list
	| ASTERISK_OP pointer
	| ASTERISK_OP
	;

direct_declarator
	: IDENTIFIER
	| LROUND declarator RROUND
	| direct_declarator LSQUARE RSQUARE
	| direct_declarator LSQUARE ASTERISK_OP RSQUARE
	| direct_declarator LSQUARE STATIC type_qualifier_list assignment_expression RSQUARE
	| direct_declarator LSQUARE STATIC assignment_expression RSQUARE
	| direct_declarator LSQUARE type_qualifier_list ASTERISK_OP RSQUARE
	| direct_declarator LSQUARE type_qualifier_list STATIC assignment_expression RSQUARE
	| direct_declarator LSQUARE type_qualifier_list assignment_expression RSQUARE
	| direct_declarator LSQUARE type_qualifier_list RSQUARE
	| direct_declarator LSQUARE assignment_expression RSQUARE
	| direct_declarator LROUND parameter_list RROUND
	| direct_declarator LROUND RROUND
	| direct_declarator LROUND identifier_list RROUND
	;

block_item_list
	: block_item
	| block_item_list block_item
	;

init_declarator
	: declarator ASSIGN initializer
	| declarator

enum_specifier
	: ENUM LBRACE enumerator_list RBRACE
	| ENUM LBRACE enumerator_list COMA RBRACE
	| ENUM IDENTIFIER LBRACE enumerator_list RBRACE
	| ENUM IDENTIFIER LBRACE enumerator_list COMA RBRACE
	| ENUM IDENTIFIER
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

identifier_list
	: IDENTIFIER
	| identifier_list COMA IDENTIFIER
	;

block_item
	: declaration
	| statement
	;

initializer
	: LBRACE initializer_list RBRACE
	| LBRACE initializer_list COMA RBRACE
	| assignment_expression
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

enumerator_list
	: enumerator
	| enumerator_list COMA enumerator
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression QUESTION_OP expression COLON conditional_expression
	;

unary_expression
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF LROUND type_name RROUND
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list COMA assignment_expression
	;

type_name
	: specifier_qualifier_list abstract_declarator
	| specifier_qualifier_list
	;

unary_operator
	: AND_OP
	| ASTERISK_OP
	| ADD_OP
	| SUB_OP
	| NOT_OP
	| LNOT_OP
	;

assignment_operator
	: ASSIGN
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

parameter_list
	: parameter_declaration
	| parameter_list COMA parameter_declaration
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

initializer_list
	: designation initializer
	| initializer
	| initializer_list COMA designation initializer
	| initializer_list COMA initializer
	;

struct_declaration
	: specifier_qualifier_list SEMICOLON
	| specifier_qualifier_list struct_declarator_list SEMICOLON
	;

enumerator
	: enum_const ASSIGN constant_expression
	| enum_const
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression LOR_OP logical_and_expression
	;

expression
	: assignment_expression
	| expression COMA assignment_expression
	;

postfix_expression
	: primary_expression
	| postfix_expression LSQUARE expression RSQUARE
	| postfix_expression LROUND RROUND
	| postfix_expression LROUND argument_expression_list RROUND
	| postfix_expression PERIOD IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	| LROUND type_name RROUND LBRACE initializer_list RBRACE
	| LROUND type_name RROUND LBRACE initializer_list COMA RBRACE
	;

cast_expression
	: unary_expression
	| LROUND type_name RROUND cast_expression
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

abstract_declarator
	: pointer direct_abstract_declarator
	| pointer
	| direct_abstract_declarator
	;

direct_abstract_declarator
	: LROUND abstract_declarator RROUND
	| LSQUARE RSQUARE
	| LSQUARE ASTERISK_OP RSQUARE
	| LSQUARE STATIC type_qualifier_list assignment_expression RSQUARE
	| LSQUARE STATIC assignment_expression RSQUARE
	| LSQUARE type_qualifier_list STATIC assignment_expression RSQUARE
	| LSQUARE type_qualifier_list assignment_expression RSQUARE
	| LSQUARE type_qualifier_list RSQUARE
	| LSQUARE assignment_expression RSQUARE
	| direct_abstract_declarator LSQUARE RSQUARE
	| direct_abstract_declarator LSQUARE ASTERISK_OP RSQUARE
	| direct_abstract_declarator LSQUARE STATIC type_qualifier_list assignment_expression RSQUARE
	| direct_abstract_declarator LSQUARE STATIC assignment_expression RSQUARE
	| direct_abstract_declarator LSQUARE type_qualifier_list assignment_expression RSQUARE
	| direct_abstract_declarator LSQUARE type_qualifier_list STATIC assignment_expression RSQUARE
	| direct_abstract_declarator LSQUARE type_qualifier_list RSQUARE
	| direct_abstract_declarator LSQUARE assignment_expression RSQUARE
	| LROUND RROUND
	| LROUND parameter_list RROUND
	| direct_abstract_declarator LROUND RROUND
	| direct_abstract_declarator LROUND parameter_list RROUND
	;

labeled_statement
	: IDENTIFIER COLON statement
	| CASE constant_expression COLON statement
	| DEFAULT COLON statement
	;

expression_statement
	: SEMICOLON
	| expression SEMICOLON
	;

selection_statement
	: IF LROUND expression RROUND statement ELSE statement
	| IF LROUND expression RROUND statement
	| SWITCH LROUND expression RROUND statement
	;

iteration_statement
	: WHILE LROUND expression RROUND statement
	| DO statement WHILE LROUND expression RROUND SEMICOLON
	| FOR LROUND expression_statement expression_statement RROUND statement
	| FOR LROUND expression_statement expression_statement expression RROUND statement
	| FOR LROUND declaration expression_statement RROUND statement
	| FOR LROUND declaration expression_statement expression RROUND statement
	;

jump_statement
	: CONTINUE SEMICOLON
	| BREAK SEMICOLON
	| RETURN SEMICOLON
	| RETURN expression SEMICOLON
	;

designation
	: designator_list ASSIGN
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list COMA struct_declarator
	;

enum_const
	: IDENTIFIER
	;

constant_expression
	: conditional_expression
	;

primary_expression
	: IDENTIFIER
	| constant
	| string
	| LROUND expression RROUND
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression LAND_OP inclusive_or_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression OR_OP exclusive_or_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression XOR_OP and_expression
	;

and_expression
	: equality_expression
	| and_expression AND_OP equality_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

relational_expression
	: shift_expression
	| relational_expression LESS_OP shift_expression
	| relational_expression GREATER_OP shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression ADD_OP multiplicative_expression
	| additive_expression SUB_OP multiplicative_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression ASTERISK_OP cast_expression
	| multiplicative_expression DIV_OP cast_expression
	| multiplicative_expression MOD_OP cast_expression
	;

designator_list
	: designator
	| designator_list designator
	;

struct_declarator
	: COLON constant_expression
	| declarator COLON constant_expression
	| declarator
	;

constant
	: INT_CONST
	| FLOAT_CONST
	| ENUM_CONST
	;

string
	: STRING_LITERAL
	| FUNC_NAME
	;

designator
	: LSQUARE constant_expression RSQUARE
	| PERIOD IDENTIFIER
	;

%%
