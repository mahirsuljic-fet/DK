%{
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <string>

int yylex();
void yyerror(const char* s);
extern std::unordered_map<std::string, float> vars;
%}

%union {
	int ival;
	float fval;
	std::string* cval;
}

%token<ival> T_INT
%token<fval> T_FLOAT
%token<cval> T_ID
%token T_NEWLINE T_QUIT

%right '='
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
					      | IF expression THEN mixed_expression   {  if ($2) $4; }
					      | '(' mixed_expression ')'	      			{ $$ = $2; }
					      | T_FLOAT		          									{ $$ = $1; }
								| T_ID '=' mixed_expression       { vars[*$1] = $3; $$ = $3; delete $1; }
								| T_ID														{ $$ = vars[*$1]; delete $1; }
								;

expression: expression '+' expression	{ $$ = $1 + $3; }
					| expression '-' expression { $$ = $1 - $3; }
					| expression '*' expression { $$ = $1 * $3; }
					| expression '/' expression { $$ = $1 / $3; }
					| '(' expression ')'				{ $$ = $2; }
					| T_INT											{ $$ = $1; }
					;

%%

std::unordered_map<std::string, float> vars;

int main() {
	yyparse();
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
