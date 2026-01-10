%option noyywrap
%{
#include <stdio.h>
#include "calc.tab.h"
%}

%%

[ \t]		; // ignore all whitespace
\n		{ return T_NEWLINE; }
[0-9]+		{ yylval = atoi(yytext); return T_INT;  }
"exit"		{ return T_QUIT; }
"quit"		{ return T_QUIT; }
[-+*/()] 	{ return *yytext; }

%%
