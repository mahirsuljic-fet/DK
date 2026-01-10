%option noyywrap

%{

#include <vector>
#include "token.hpp"

extern unsigned short int row;
extern unsigned short int column;

%}

ws       [ \t\r]
digit    [0-9]
number   {digit}+

%%


\n               { row++; column = 1; }
{ws}             { column += yyleng;  }
:                { column += yyleng; return COLON; }
\"[^"\n]*\"      { column += yyleng; return STRING; }
\{               { column += yyleng; return OPEN_BRACES; }
\}               { column += yyleng; return CLOSED_BRACES; }
\[               { column += yyleng; return OPEN_BRACKET; }
\]               { column += yyleng; return CLOSED_BRACKET; }
,                { column += yyleng; return COMMA; }
(true|false)     { column += yyleng; return BOOLEAN; }
null             { column += yyleng; return NULLJSON; }
{number}         { column += yyleng; return NUMBER; }
.                { column += yyleng; printf("error: %c\n", yytext[0]); }

%%

unsigned short int row = 1;
unsigned short int column = 1;

int main() {
    int t;
    std::vector<Token> tokeni;
    while ((t = yylex())) {
        tokeni.push_back(Token{t, yytext, row, static_cast<unsigned short>(column - yyleng)});
        std::cout << tokeni.back() << std::endl;
    }
}

