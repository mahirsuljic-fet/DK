%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

extern int yylex();
void yyerror(const char* s);
%}

%token STRING
%token NUMBER
%token TRUE
%token FALSE
%token NULLABLE

%%

START: OBJECT { printf("Success\n"); };

OBJECT: '{' PAIRS '}'
      | '{' '}'
      ;

PAIRS: PAIRS ',' PAIR
     | PAIR
     ;

PAIR: STRING ':' VALUE;

VALUE: STRING
     | NUMBER
     | TRUE
     | FALSE
     | NULLABLE
     | ARRAY
     | OBJECT
     ;

ARRAY : '[' SADRZAJ ']'
      | '[' ']'
      ;

SADRZAJ : SADRZAJ ',' VALUE
       | VALUE
       ;

%%

int main()
{
   printf("\n");
   yyparse();
   printf("\n");
   return 0;
}

void yyerror(char const *s) {
   fprintf (stderr, "Error u json parseru: %s\n", s);
}

