%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
void yyerror(const char* s);

extern float vars[26];

%}

%union {
  int ival;
	float fval;
	char cval;
}

%type<ival> expression
%type<fval> float_expression

%token<cval> T_ID
%token<ival> T_INT
%token<fval> T_FLOAT
%token T_NEWLINE T_QUIT

%right '='
%left '+' '-'
%left '*' '/'

%start calculation

%%

calculation: calculation T_NEWLINE line
					 | line
           ;

line: expression  { printf("Success: %d\n", $1); }
		| float_expression { printf("Success: %f\n", $1); }
		| T_QUIT 			{ return 0; }
		| %empty
		;

expression: expression '+' expression { $$ = $1 + $3; }
					| expression '-' expression { $$ = $1 - $3; }
					| expression '*' expression	{ $$ = $1 * $3; }
					| expression '/' expression	{ $$ = $1 / $3; }
					| '(' expression ')'        { $$ = $2; }
					| T_INT											{ $$ = $1; }
					;

float_expression:
								float_expression '+' float_expression { $$ = $1 + $3; }
								| float_expression '-' float_expression { $$ = $1 - $3; }
								| float_expression '*' float_expression	{ $$ = $1 * $3; }
								| float_expression '/' float_expression	{ $$ = $1 / $3; }

								| expression '+' float_expression { $$ = $1 + $3; }
								| expression '-' float_expression { $$ = $1 - $3; }
								| expression '*' float_expression	{ $$ = $1 * $3; }
								| expression '/' float_expression	{ $$ = $1 / $3; }
								| float_expression '+' expression { $$ = $1 + $3; }
								| float_expression '-' expression { $$ = $1 - $3; }
								| float_expression '*' expression	{ $$ = $1 * $3; }
								| float_expression '/' expression	{ $$ = $1 / $3; }

								| T_ID '=' float_expression       { $$ = vars[$1 - 'a'] = $3; }
								| T_ID                            { $$ = vars[$1 - 'a']; }

								| '(' float_expression ')'        { $$ = $2; }
								| T_FLOAT											{ $$ = $1; }
					;

%%

float vars[26];

int main() {
	yyparse();
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
