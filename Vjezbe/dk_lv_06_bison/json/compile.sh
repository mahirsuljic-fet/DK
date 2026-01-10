#! /bin/bash -x

flex json.l
bison -d json.y
gcc json.tab.c lex.yy.c -o json

