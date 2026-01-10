%option noyywrap
%{

#include<stdio.h>

#include "json.tab.h"

%}

ws            [ \t\n]
letter        [a-zA-Z]
digit         [0-9]
number        {digit}+
string        ({letter}|{digit})*

%%

{ws}

[{},:\[\]]                    { return *yytext; }
{number}                      { return NUMBER; }
"null"                        { return NULLABLE; }
"true"                        { return TRUE; }
"false"                       { return FALSE;}
\"{string}\"                  { return STRING; }

%%
