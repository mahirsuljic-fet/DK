%{
#include <iostream>
#include "ASTNode.h"

int yylex();
int yyerror(const char*);

extern Environment env;
%}

%union {
  ASTNode* node;
  std::string* str;
  double num;
}

%start START

%type<node> VALUE EXPR STMT

%token NL
%token<str> ID
%token<num> NUM

%left '+'
%left '-'

%%

START: START STMT     { $2->print(env); delete $2; }
     | %empty
     ;

STMT: EXPR NL         { $$ = $1; }
    | 'd' EXPR        { $$ = new NumberNode($2->eval(env).vec.getMagnitude()); delete $2; }
    | ID ':' EXPR NL  { $$ = $3; env.setValue(*$1, $3->eval(env)); delete $1; }
    | NL              { $$ = new EmptyNode(); }
    ;

EXPR: VALUE           { $$ = $1; }
    | '(' EXPR ')'    { $$ = $2; }
    | EXPR '+' EXPR  { $$ = addNodes(env, $1, $3); }
    | EXPR '-' EXPR  { $$ = subtractNodes(env, $1, $3); }
    ;

VALUE: '[' EXPR ',' EXPR ']'  { $$ = new VectorNode($2, $4); }
     | NUM                    { $$ = new NumberNode($1); }
     | ID                     { $$ = new IDNode($1); }
     ;

%%
Environment env;

int main() {
  yyparse();
}

int yyerror(const char* msg) {
  std::cout << msg << std::endl;
  return 0;
}
