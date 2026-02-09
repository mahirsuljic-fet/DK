CC = g++
CCFLAGS= -O2 -fpermissive -fsanitize=address -std=c++14
LEX = flex
LFLAGS= -8
YACC= bison
YFLAGS= -d -t -Wcounterexamples

vector: vector.tab.o lex.yy.o
	${CC} ${CCFLAGS} lex.yy.o vector.tab.o -o vector

vector.tab.o: vector.y *.h
	${YACC} ${YFLAGS} vector.y
	${CC} ${CCFLAGS} vector.tab.c -c

lex.yy.o: vector.l *.h
	${LEX} $(LFLAGS) vector.l
	${CC} ${CCFLAGS} lex.yy.c -c

.PHONY: test
test: vector
	./test/start.sh ./vector

.PHONY: update-test
update-test:
	cd test && git pull

clean:
	rm -f lex.yy.* vector.tab.* *.o vector
