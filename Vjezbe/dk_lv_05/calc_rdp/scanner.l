%option noyywrap

%{
#include "token.hpp"
%}

ws            [ \t\n]
letter        [a-zA-Z_]
digit         [0-9]
number        {digit}+
identifier    {letter}({letter}|{digit})*

%%

{ws}
{number}                      { return NUMBER; }
\"{identifier}\"              { return STRING; }
"("                           { return OPENPAREN; }
")"                           { return CLOSEDPAREN; }
"+"                           { return PLUS; }
"-"                           { return MINUS; }
"*"                           { return TIMES; }
"/"                           { return DIVISION; }

%%
