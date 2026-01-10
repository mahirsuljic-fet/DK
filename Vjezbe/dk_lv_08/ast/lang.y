%{
#include <stdio.h>
#include <vector>
#include <iostream>
#include "expression_tree.hpp"
#include "environment.hpp"

int yylex();
void yyerror(const char* s);

Environment env;
%}

%union {
  int num;
  char* str;
  ExpressionNode* node;
}

%start START

%token<num> NUMBER
%token<str> ID
%token IF
%nonassoc THEN
%nonassoc ELSE

%right '='
%left '+' '-'
%left '*' '/'

%type<node> STMT
%type<node> EXPR

%%

START: %empty
     | START STMT     { printf("Rezultat: %d\n", $2->evaluate(env)); }
     ;

STMT: EXPR ';'                  { $$ = $1; }
    | IF '(' EXPR ')' STMT %prec THEN  { $$ = new IfNode{$3, $5}; }
    | IF '(' EXPR ')' STMT ELSE STMT  { $$ = new IfElseNode{$3, $5, $7}; }
    ;

EXPR: NUMBER               { $$ = new NumberNode{$1}; }
    | EXPR '+' EXPR        { $$ = new PlusNode{$1, $3}; }
    | EXPR '-' EXPR        { $$ = new MinusNode{$1, $3}; }
    | EXPR '*' EXPR        { $$ = new MultiplyNode{$1, $3}; }
    | EXPR '/' EXPR        { $$ = new DivisionNode{$1, $3}; }
    | '(' EXPR ')'         { $$ = $2; }
    | ID '=' EXPR          { $$ = new AssignmentNode{$1, $3}; }
    | ID                   { $$ = new VariableNode{$1};   }
    ;

%%

int main() {
  yyparse();
}

void yyerror(const char *s) {
  extern int yylineno;  // defined and maintained in lex
  extern char *yytext;  // defined and maintained in lex
  fprintf(stderr, "Error: %s at symbol '%s' on line %d\n", s, yytext, yylineno);
}
