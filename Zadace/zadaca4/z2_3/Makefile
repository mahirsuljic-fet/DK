all:
	flex --header-file=lex.yy.h lox.l
	clang++ lex.yy.c token.cpp parser.cpp main.cpp -o lox_parser

test: all
	./lox_parser < prog.txt

ctest: all
	clear
	./lox_parser < prog.txt

clean:
	rm -rf lox_parser lex.yy.c lex.yy.h

