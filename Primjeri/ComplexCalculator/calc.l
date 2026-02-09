%option noyywrap

%{
#include <iostream>
#include <string>
#include "complex.h"
#include "calc.tab.h"
%}

ID    [a-zA-Z_][a-zA-Z0-9_]*
NUM   [0-9]+(\.[0-9])?
CNUM  ({NUM}[ ]*[+-][ ]*)?{NUM}"i"

%%

[\t ]
"\n"          { return NEWLINE; }
"modul"       { return MODUL; }
"exit"        { return EXIT; }
[-+*/=]       { return *yytext; }
[+-]?{CNUM}   { yylval.cnum = new Complex(yytext); return CNUM; }
[+-]?{NUM}    { yylval.num = std::stod(yytext); return NUM; }
{ID}          { yylval.str = new std::string(yytext); return ID; }
.             { std::cout << "Unexpected character: " << *yytext << std::endl; }

%%
