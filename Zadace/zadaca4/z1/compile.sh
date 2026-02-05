#! /bin/bash

flex --header-file=lex.yy.h scanner.l
clang++ -std=c++11 main.cpp parser.cpp lex.yy.c -o json-parser
