%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
void yyerror(const char* s);
%}

%union {
	int ival;
	float fval;
}

%token<ival> T_INT
%token<fval> T_FLOAT
%token T_NEWLINE T_QUIT

%left '+' '-'
%left '*' '/'

%type<ival> expression;
%type<fval> mixed_expression;

%start calculation

%%

calculation: calculation T_NEWLINE line
					 | line
           ;

line: expression  { printf("Success: %d\n", $1); }
		| mixed_expression  { printf("Success: %f\n", $1); }
		| T_QUIT 			{ return 0; }
		| %empty
		;

mixed_expression: mixed_expression '+' mixed_expression	{ $$ = $1 + $3; }
					      | mixed_expression '-' mixed_expression { $$ = $1 - $3; }
					      | mixed_expression '*' mixed_expression { $$ = $1 * $3; }
					      | mixed_expression '/' mixed_expression { $$ = $1 / $3; }
								| expression '+' mixed_expression	{ $$ = $1 + $3; }
					      | expression '-' mixed_expression { $$ = $1 - $3; }
					      | expression '*' mixed_expression { $$ = $1 * $3; }
					      | expression '/' mixed_expression { $$ = $1 / $3; }
								| mixed_expression '+' expression	{ $$ = $1 + $3; }
					      | mixed_expression '-' expression { $$ = $1 - $3; }
					      | mixed_expression '*' expression { $$ = $1 * $3; }
					      | mixed_expression '/' expression { $$ = $1 / $3; }
					      | '(' mixed_expression ')'	      			{ $$ = $2; }
					      | T_FLOAT		          									{ $$ = $1; }
								;


expression: expression '+' expression	{ $$ = $1 + $3; }
					| expression '-' expression { $$ = $1 - $3; }
					| expression '*' expression { $$ = $1 * $3; }
					| expression '/' expression { $$ = $1 / $3; }
					| '(' expression ')'				{ $$ = $2; }
					| T_INT											{ $$ = $1; }
					;

%%

int main() {
	yyparse();
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
