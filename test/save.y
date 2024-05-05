expression
	: assignment_expression { $$ = new Expression($1); };
	| expression ',' assignment_expression {
		$1->add_expression($3);
		$$ = $1;
	}
	;

assignment_expression
	: logical_or_expression { $$ = new AssignmentExpression($1); };
	| primary_expression assignment_operator assignment_expression { $$ = new AssignementExpression($1, $2, $3); };
	;

assignment_operator
	: '=' { $$ = $1 };
	| MUL_ASSIGN { $$ = $1 };
	| DIV_ASSIGN { $$ = $1 };
	| MOD_ASSIGN { $$ = $1 };
	| ADD_ASSIGN { $$ = $1 };
	| SUB_ASSIGN { $$ = $1 };
	| SHL_ASSIGN { $$ = $1 };
	| SHR_ASSIGN { $$ = $1 };
	| AND_ASSIGN { $$ = $1 };
	| XOR_ASSIGN { $$ = $1 };
	| OR_ASSIGN { $$ = $1 };
	;

logical_or_expression
	: logical_and_expression { $$ = new LogicalOrExpression($1); };
	| logical_or_expression LOR_OP logical_and_expression { 
		$1->add_expression($2, $3);
		$$ = $1;
	};
	;

logical_and_expression
	: inclusive_or_expression { $$ = new LogicalAndExpression($1); };
	| logical_and_expression LAND_OP inclusive_or_expression {
		$1->add_expression($2, $3);
		$$ = $1;
	};
	;

inclusive_or_expression
	: exclusive_or_expression { $$ = new InclusiveOrExpression($1); };
	| inclusive_or_expression '|' exclusive_or_expression {
		$1->add_expression($2, $3);
		$$ = $1;
	};
	;

exclusive_or_expression
	: and_expression { $$ = new ExclusiveOrExpression($1); };
	| exclusive_or_expression '^' and_expression {
		$1->add_expression($2, $3);
		$$ = $1;
	};
	;

and_expression
	: equality_expression { $$ = new AndExpression($1); };
	| and_expression '&' equality_expression {
		$1->add_expression($2, $3);
		$$ = $1;
	};
	;

equality_expression
	: relational_expression { $$ = new EqualityExpression($1); };
	| equality_expression EQ_OP relational_expression {
		$1->add_expression($2, $3);
		$$ = $1;
	};
	| equality_expression NEQ_OP relational_expression {
		$1->add_expression($2, $3);
		$$ = $1;
	};
	;

relational_expression
	: shift_expression { $$ = new RelationalExpression($1); };
	| relational_expression '<' shift_expression {
		$1->add_expression($2, $3);
		$$ = $1;
	};
	| relational_expression '>' shift_expression {
		$1->add_expression($2, $3);
		$$ = $1;
	};
	| relational_expression LEQ_OP shift_expression {
		$1->add_expression($2, $3);
		$$ = $1;
	};
	| relational_expression GEQ_OP shift_expression {
		$1->add_expression($2, $3);
		$$ = $1;
	};
	;

shift_expression
	: additive_expression { $$ = new ShiftExpression($1); };
	| shift_expression SHL_OP additive_expression {
		$1->add_expression($2, $3);
		$$ = $1;
	};
	| shift_expression SHR_OP additive_expression {
		$1->add_expression($2, $3);
		$$ = $1;
	};
	;

additive_expression
	: multiplicative_expression { $$ = new AdditiveExpression($1); };
	| additive_expression '+' multiplicative_expression {
		$1->add_expression($2, $3);
		$$ = $1;
	};
	| additive_expression '-' multiplicative_expression {
		$1->add_expression($2, $3);
		$$ = $1;
	};
	;

multiplicative_expression
    : primary_expression { $$ = new MultiplicativeExpression($1); };
	| multiplicative_expression '*' primary_expression {
		$1->add_expression($2, $3);
		$$ = $1;
	};
	| multiplicative_expression '/' primary_expression {
		$1->add_expression($2, $3);
		$$ = $1;
	};
	| multiplicative_expression '%' primary_expression {
		$1->add_expression($2, $3);
		$$ = $1;
	};
	;














expression
	: primary_expression { $$ = $1; };
	| primary_expression '=' expression { $$ = $1 };
	| primary_expression MUL_ASSIGN expression { $$ = $1 };
	| primary_expression DIV_ASSIGN expression { $$ = $1 };
	| primary_expression MOD_ASSIGN expression { $$ = $1 };
	| primary_expression ADD_ASSIGN expression { $$ = $1 };
	| primary_expression SUB_ASSIGN expression { $$ = $1 };
	| primary_expression SHL_ASSIGN expression { $$ = $1 };
	| primary_expression SHR_ASSIGN expression { $$ = $1 };
	| primary_expression AND_ASSIGN expression { $$ = $1 };
	| primary_expression XOR_ASSIGN expression { $$ = $1 };
	| primary_expression OR_ASSIGN expression { $$ = $1 };
	| expression LOR_OP expression {};
	| expression LAND_OP expression {};
	| expression '|' expression {};
	| expression '^' expression {};
	| expression '&' expression {};
	| expression EQ_OP expression {};
	| expression NEQ_OP expression {};
	| expression LEQ_OP expression {};
	| expression GEQ_OP expression {};
	| expression '<' expression {};
	| expression '>' expression {};
	| expression SHL_OP expression {};
	| expression SHR_OP expression {};
	| expression '+' expression {};
	| expression '-' expression {};
	| expression '*' expression {};
	| expression '/' expression {};
	| expression '%' expression {};
	;
