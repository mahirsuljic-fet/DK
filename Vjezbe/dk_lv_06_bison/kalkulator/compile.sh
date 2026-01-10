#! /bin/bash -x

flex calc.l
bison -d calc.y
gcc calc.tab.c lex.yy.c -o calc

