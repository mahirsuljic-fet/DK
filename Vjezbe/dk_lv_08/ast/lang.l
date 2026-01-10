%option noyywrap
%{
#include <stdio.h>
#include <vector>
#include "expression_tree.hpp"
#include "environment.hpp"

#include "lang.tab.h"

%}

ws         [ \t\n]
number     [0-9]
letter     [a-zA-Z_]
id         {letter}({letter}|{number})*

%%

{ws}+              ;
{number}+          { yylval.num = atoi(yytext); return NUMBER; }
"if"               { return IF; }
"else"             { return ELSE; }
{id}               { yylval.str = strdup(yytext); return ID; }
.                  { return *yytext; }

%%

