NAME=calc

${NAME}: lex.yy.c
	clang++ main.cpp parser.cpp lex.yy.c -o ${NAME}
lex.yy.c:
	flex --header-file=lex.yy.h scanner.l
clean:
	rm -f lex.yy.c lex.yy.h ${NAME}
