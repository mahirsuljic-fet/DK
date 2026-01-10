all:
	flex scanner.l
	clang++ -c lex.yy.c
	clang++ -c token.cpp
	clang++ lex.yy.o token.o -o lexer

clean:
	rm -rf lex.yy.o token.o lexer lex.yy.c

