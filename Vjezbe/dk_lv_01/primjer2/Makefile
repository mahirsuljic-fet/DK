PROG_NAME=soferi

all: ${PROG_NAME}

${PROG_NAME}: vozac.o automobil.o main.o
	clang++ vozac.o automobil.o main.o -o ${PROG_NAME}

vozac.o: vozac.cpp
	clang++ -c vozac.cpp

automobil.o: automobil.cpp
	clang++ -c automobil.cpp

main.o: main.cpp
	clang++ -c main.cpp

test: input.txt ${PROG_NAME}
	./${PROG_NAME} < input.txt


clean:
	rm -f *.o ${PROG_NAME}
