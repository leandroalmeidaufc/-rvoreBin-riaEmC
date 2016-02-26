all: main


main: main.o abb.o
	gcc main.o abb.o -o main

main.o: main.c abb.h
	gcc -g -c main.c

ArvoreBB.o: abb.c abb.h
	gcc -g -c abb.c


clean:
	rm -f *~ *.o main

