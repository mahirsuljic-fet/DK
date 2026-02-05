all:
	flex lox.l
	clang++ -c lex.yy.c
	clang++ -c token.cpp
	clang++ lex.yy.o token.o -o lox_lexer

clean:
	rm -rf lex.yy.o token.o lox_lexer lex.yy.c

