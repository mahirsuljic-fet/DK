%option noyywrap
%{
#include <stdio.h>
#include "calc.tab.h"
%}

%%

[ \t]			; // ignore all whitespace
\n				{ return T_NEWLINE; }
[0-9]+		{ yylval.ival = atoi(yytext); return T_INT; }
[0-9]+\.[0-9]+		{ yylval.fval = atof(yytext); return T_FLOAT; }
"exit"		{ return T_QUIT; }
"quit"		{ return T_QUIT; }
[-+*/()=]  { return *yytext; }
[a-z]     { yylval.cval = *yytext; return T_ID; }

%%
