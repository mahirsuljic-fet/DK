CC = g++
CCFLAGS= -O2 -fpermissive -fsanitize=address -std=c++14
LEX = flex
LFLAGS= -8
YACC= bison
YFLAGS= -d -t -Wcounterexamples

calc: calc.tab.o lex.yy.o
	${CC} ${CCFLAGS} lex.yy.o calc.tab.o -o calc

calc.tab.o: calc.y *.h
	${YACC} ${YFLAGS} calc.y
	${CC} ${CCFLAGS} calc.tab.c -c

lex.yy.o: calc.l *.h
	${LEX} $(LFLAGS) calc.l
	${CC} ${CCFLAGS} lex.yy.c -c

clean:
	rm -f lex.yy.* calc.tab.* *.o calc
