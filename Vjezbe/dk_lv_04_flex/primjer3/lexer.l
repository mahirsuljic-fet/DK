%option noyywrap

%{
#include <iostream>
#include <vector>
#include <string>

enum TokenID {
  KW = 1,
  ID,
  INTEGER,
  REAL,
};

struct Token {
  int id;
  std::string lexem;
};
%}

id      [a-zA-Z_][a-zA-Z0-9_]*
cifra   [0-9]
integer {cifra}+
real    {cifra}+\.{cifra}*

%%

[\n]
"if"      { return KW; }
"else"    { return KW; }
"for"     { return KW; }
"while"   { return KW; }
{id}      { return ID; }
{integer} { return INTEGER; }
{real}    { return REAL; }
.

%%

int main() {
  int r;
  std::vector<Token> tokeni;

  while (r = yylex()) {
    Token t { r, yytext };
    tokeni.push_back(std::move(t));
  }

  std::cout << "\nTokeni:\n";
  for (const auto& t : tokeni)
    std::cout << t.id << " " << t.lexem << std::endl;
}
