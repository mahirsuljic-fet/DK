all: json

json.tab.c json.tab.h:	json.y
	bison -d json.y

lex.yy.c: json.l json.tab.h
	flex json.l

json: lex.yy.c json.tab.c json.tab.h
	gcc -o json json.tab.c lex.yy.c

clean:
	rm json json.tab.c lex.yy.c json.tab.h
