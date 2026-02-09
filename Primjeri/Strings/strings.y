%{
#include <string>
#include <iostream>
#include <unordered_map>
#include <string.h>

int yylex();
void yyerror(const char*);

extern std::unordered_map<std::string, std::string> symbol_table;
%}

%union {
  char* str;
  int num;
}

%token NEWLINE
%token <num> NUM
%token <str> STRING ID

%type <str> expr stmt value

%left '+'
%left '*'

%start program

%%

program: program stmt { std::cout << "> \"" << $2 << "\"" << std::endl; free($2); }
       | stmt         { std::cout << "> \"" << $1 << "\"" << std::endl; free($1); }
       ;

stmt: expr NEWLINE
    | ID '=' expr NEWLINE {
        $$ = $3;
        symbol_table[$1] = $3; 
        free($1);
      }
    ; 

expr: value
    | NUM '*' expr {
        std::string result;
        for (int i = 0; i < $1; ++i)
          result += $3;
        $$ = strdup(result.c_str());
        free($3);
      }
    | expr '*' NUM {
        std::string result;
        for (int i = 0; i < $3; ++i)
          result += $1;
        $$ = strdup(result.c_str());
        free($1);
      }
    | expr '+' expr {
        $$ = strdup((std::string($1) + std::string($3)).c_str());
        free($1);
        free($3);
      }
    ;

value: STRING
     | ID { 
         $$ = strdup(symbol_table[$1].c_str());
         free($1);
       }
     ;


%%

std::unordered_map<std::string, std::string> symbol_table;

int main() {
  yyparse();

  std::cout << "Final values:" << std::endl;
  for (const auto& [id, value] : symbol_table)
    std::cout << id << " = " << value << std::endl;
}

void yyerror(const char* msg) { std::cout << msg << std::endl; }
