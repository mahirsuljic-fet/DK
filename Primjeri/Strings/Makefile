strings: strings.l strings.y
	flex -8 strings.l
	bison -d strings.y
	g++ *.c -fsanitize=address -o strings

clean:
	rm -rf lex.yy.c strings.tab.c strings.tab.h strings
