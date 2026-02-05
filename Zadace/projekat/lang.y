%{
#include <stdio.h>
#include <vector>
#include <iostream>
#include "expression_tree.hpp"
#include "environment.hpp"

int yylex();
void yyerror(const char* s);

extern Environment env;
%}

%union {
  std::vector<ExpressionNode*>* exprs;
  std::vector<std::string>* ids;
  ExpressionNode* node;
  std::string* str;
  int num;
}

%start START

%token PRINT IF THEN ELSE WHILE DO FN RETURN
%token<num> NUMBER
%token '=' NOT_EQUAL '>' '<' GREATER_EQUAL LESS_EQUAL
%token '+' '-'
%token '*' '/'
%token ASSIGN
%token UMINUS

%right ASSIGN
%left '=' NOT_EQUAL '>' '<' GREATER_EQUAL LESS_EQUAL
%left '+' '-'
%left '*' '/'
%right UMINUS

%nonassoc NO_ELSE
%nonassoc ELSE

%token<str> ID

%type<ids> ID_LIST
%type<node> STMT EXPR
%type<exprs> STATEMENT_LIST EXPR_LIST SCOPE

%%

START: %empty
     | START STMT { $2->evaluate(env); delete $2; }
     ;

STMT: EXPR ';'                        { $$ = $1;                                     }
    | PRINT '(' EXPR ')' ';'          { $$ = new PrintNode{$3};                      }
    | IF EXPR THEN STMT ELSE STMT     { $$ = new IfElseNode($2, $4, $6);             }
    | IF EXPR THEN STMT %prec NO_ELSE { $$ = new IfNode($2, $4);                     }
    | WHILE EXPR DO STMT              { $$ = new WhileNode($2, $4);                  }
    | SCOPE                           { $$ = new ScopeNode($1);                      }
    | FN ID '(' ID_LIST ')' SCOPE     { $$ = new FunctionDefinitionNode($2, $4, $6); }
    | RETURN EXPR ';'                 { $$ = new ReturnNode($2);                     }
    ;

SCOPE: '{' STATEMENT_LIST '}'         { $$ = $2; } ;

STATEMENT_LIST: STATEMENT_LIST STMT   { $$->push_back($2);                       }
              | %empty                { $$ = new std::vector<ExpressionNode*>(); }
              ;

EXPR: NUMBER                          { $$ = new NumberNode{$1};           }
    | ID                              { $$ = new IDNode{$1};               }
    | ID ASSIGN EXPR                  { $$ = new AssignNode($1, $3);       }
    | '(' EXPR ')'                    { $$ = new ExprValueNode{$2};        }
    | '-' EXPR %prec UMINUS           { $$ = new UnaryMinusNode{$2};       }
    | EXPR '+' EXPR                   { $$ = new PlusNode{$1, $3};         }
    | EXPR '-' EXPR                   { $$ = new MinusNode{$1, $3};        }
    | EXPR '*' EXPR                   { $$ = new TimesNode{$1, $3};        }
    | EXPR '/' EXPR                   { $$ = new DivideNode{$1, $3};       }
    | EXPR '>' EXPR                   { $$ = new GreaterNode{$1, $3};      }
    | EXPR '<' EXPR                   { $$ = new LessNode{$1, $3};         }
    | EXPR '=' EXPR                   { $$ = new EqualNode{$1, $3};        }
    | EXPR NOT_EQUAL EXPR             { $$ = new NotEqualNode{$1, $3};     }
    | EXPR GREATER_EQUAL EXPR         { $$ = new GreaterEqualNode{$1, $3}; }
    | EXPR LESS_EQUAL EXPR            { $$ = new LessEqualNode{$1, $3};    }
    | ID '(' EXPR_LIST ')'            { $$ = new FunctionCallNode($1, $3); }
    ;

EXPR_LIST: EXPR_LIST ',' EXPR         { $$->push_back($3);                                          }
         | EXPR                       { $$ = new std::vector<ExpressionNode*>(); $$->push_back($1); }
         | %empty                     { $$ = new std::vector<ExpressionNode*>();                    }
         ;

ID_LIST: ID_LIST ',' ID               { $$ = $1; $$->push_back(*$3); delete $3;                             }
       | ID                           { $$ = new std::vector<std::string>(); $$->push_back(*$1); delete $1; }
       | %empty                       { $$ = new std::vector<std::string>();                                }
       ;

%%

Environment env;

int main() {
  yyparse();
}

void yyerror(const char *s) {
  extern int yylineno;  // defined and maintained in lex
  extern char *yytext;  // defined and maintained in lex
  fprintf(stderr, "Error: %s at symbol '%s' on line %d\n", s, yytext, yylineno);
}
