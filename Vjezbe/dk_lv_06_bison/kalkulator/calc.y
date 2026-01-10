%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
void yyerror(const char* s);
%}

%token T_INT
%token T_NEWLINE T_QUIT

%left '+' '-'
%left '*' '/'

%start line

%%

line: expr T_NEWLINE  { printf("SUCCESS: %d\n", $1); } line
    | T_NEWLINE line
    | T_QUIT { exit(0); }
    | %empty
    ;

expr : expr '+' expr { $$ = $1 + $3; }
     | expr '-' expr { $$ = $1 - $3; }
     | expr '*' expr { $$ = $1 * $3; }
     | expr '/' expr { $$ = $1 / $3; }
     | '(' expr ')'  { $$ = $2;      }
     | T_INT
     ;

%%

int main() {
	yyparse();
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
