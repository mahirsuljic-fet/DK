%{
#include <string>
#include <iostream>
#include <unordered_map>
#include "complex.h"

int yylex();
void yyerror(const char*);

extern std::unordered_map<std::string, Complex> symbol_table;
%}

%union {
  std::string* str;
  Complex* cnum;
  double num;
}

%token<cnum> CNUM
%token<num> NUM
%token<str> ID
%token NEWLINE MODUL EXIT

%type<cnum> stmt expr value

%left '+' '-'
%left '*' '/'

%start start

%%

start: start stmt { std::cout << "> " << *$2 << std::endl; delete $2; }
     | %empty
     ;

stmt: expr        NEWLINE
    | ID '=' expr NEWLINE { $$ = $3; symbol_table[*$1] = *$3; delete $1; }
    | MODUL expr  NEWLINE { $$ = new Complex($2->module()); delete $2; }
    | EXIT        NEWLINE { exit(0); }
    ;

expr: value        
    | expr '+' expr { $$ = new Complex(*$1 + *$3); delete $1; delete $3; }
    | expr '-' expr { $$ = new Complex(*$1 - *$3); delete $1; delete $3; }
    | expr '*' expr { $$ = new Complex(*$1 * *$3); delete $1; delete $3; }
    | expr '/' expr { $$ = new Complex(*$1 / *$3); delete $1; delete $3; }
    ;

value: CNUM
     | NUM  { $$ = new Complex($1); }
     | ID   { $$ = new Complex(symbol_table[*$1]); delete $1; }
     ;


%%

std::unordered_map<std::string, Complex> symbol_table;

int main() {
  yyparse();
}

void yyerror(const char* str) {
  std::cout << str << std::endl;
}
