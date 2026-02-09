%option noyywrap

%{
#include <string.h>
#include <iostream>
#include "strings.tab.h"
%}

NUM [0-9]+
ID  [a-zA-Z_][a-zA-Z0-9_]*

%%

[\t ]
"\n"    { return NEWLINE; }
{NUM}   { yylval.num = std::stoi(yytext); return NUM; }
\".*\"  { yylval.str = strdup(yytext + 1); yylval.str[strlen(yylval.str) - 1] = '\0'; return STRING; }
{ID}    { yylval.str = strdup(yytext); return ID; }
[=+*]   { return *yytext; }
.       { std::cout << "Unexpedted character: " << yytext << std::endl; }

%%
