%option noyywrap

%{
// #define KW 1
// #define ID 2
// #define INTEGER 3
// #define REAL 4

enum {
  KW = 1,
  ID,
  INTEGER,
  REAL
};
%}

id      [a-zA-Z_][a-zA-Z0-9_]*
cifra   [0-9]
integer {cifra}+
real	{cifra}+\.{cifra}*

%%

[\n]
"exit"          { return 0; }
"if"		{ return KW; }
"else"		{ return KW; }
"for"		{ return KW; }
"while"		{ return KW; }
{id}            { return ID; }
{integer} 	{ return INTEGER; }
{real}		{ return REAL; }
.

%%

const char* print(int t) {
  switch (t) {
    case KW:
      return "KW";
    case ID:
      return "IDENTIFIKATOR";
    case INTEGER:
      return "INTEGER";
    case REAL:
      return "REAL";
    default:
      return "?";
  }
}

int main() {
  int t;
  while (t = yylex()) {
   puts(print(t));
  }
  puts("Sad sam u mainu");
}
