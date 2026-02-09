%{
#include <unordered_map>
#include <iostream>
#include <string>
#include <string.h>

int yylex();
void yyerror(const char*);

extern std::unordered_map<std::string, double> symbol_table;
%}

%union {
  std::string* str;
  double num;
}

%token EXIT
%token<num> NUM
%token<str> ID

%type<num> value expr stmt

%right '='
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%start program

%%

program: program stmt { std::cout << "> " << $2 << std::endl; }
       | %empty
       ;

stmt: expr '\n' { $$ = $1; }
    | EXIT '\n' { exit(0); }
    ;

expr: value
    | ID '=' expr           { $$ = symbol_table[*$1] = $3; delete $1; }
    | expr '+' expr         { $$ = $1 + $3; }
    | expr '-' expr         { $$ = $1 - $3; }
    | expr '*' expr         { $$ = $1 * $3; }
    | expr '/' expr         { $$ = $1 / $3; }
    | '-' expr %prec UMINUS { $$ = -$2; }
    ;

value: NUM
     | ID   { $$ = symbol_table[*$1]; delete $1; }
     ;

%%

std::unordered_map<std::string, double> symbol_table;

int main() {
  yyparse();
}

void yyerror(const char* msg) {
  std::cout << msg << std::endl;
}
