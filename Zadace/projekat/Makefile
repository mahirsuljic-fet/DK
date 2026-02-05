CC = g++
CCFLAGS= -O2 -fpermissive -fsanitize=address -std=c++14
LEX = flex
LFLAGS= -8
YACC= bison
YFLAGS= -d -t -Wcounterexamples

lang: environment.cpp lang.tab.o lex.yy.o
	${CC} ${CCFLAGS} environment.cpp lex.yy.o lang.tab.o -o lang

lang.tab.o: lang.y *.hpp
	${YACC} ${YFLAGS} lang.y
	${CC} ${CCFLAGS} lang.tab.c -c

lex.yy.o: lang.l *.hpp
	${LEX} $(LFLAGS) lang.l
	${CC} ${CCFLAGS} lex.yy.c -c

.PHONY: test
test: lang
	./test/start.sh ./lang

.PHONY: update-test
update-test:
	cd test && git pull

clean:
	rm -f lex.yy.* lang.tab.* *.o lang
