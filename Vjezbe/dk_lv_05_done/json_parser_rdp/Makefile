json-parser: lex.yy.c
	clang++ -std=c++11 main.cpp parser.cpp lex.yy.c -o json-parser
lex.yy.c:
	flex --header-file=lex.yy.h scanner.l
clean:
	rm -f lex.yy.c lex.yy.h json-parser
