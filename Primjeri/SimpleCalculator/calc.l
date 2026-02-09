%option noyywrap

%{
#include <iostream>
#include <string>
#include <string.h>
#include "calc.tab.h"
%}

ID  [a-zA-Z_][a-zA-Z0-9_]*
NUM [+-]?[0-9](\.[0-9])?

%%

[\t ]
[-+*/=\n]   { return *yytext; }
"exit"      { return EXIT; }
{NUM}       { yylval.num = std::stod(yytext); return NUM; }
{ID}        { yylval.str = new std::string(yytext); return ID; }
.           { std::cout << "Unexpected character: " << *yytext << std::endl; }

%%
