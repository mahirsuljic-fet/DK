%option noyywrap
%option yylineno

%{
#include <iostream>
#include <string>
#include "ASTNode.h"
#include "vector.tab.h"
%}

ID    [a-zA-Z_][a-zA-Z0-9_]*
NUM   [0-9]+(\.[0-9]+)?

%%

[\r\t ]       {}
[\n]          { return NL; }
[d,:\[\]()+-] { return *yytext; }
{ID}          { yylval.str = new std::string(yytext); return ID; }
{NUM}         { yylval.num = std::stod(yytext); return NUM; }
.             { std::cout << "Unexpected character: " << *yytext << std::endl; }

%%

