main: main.o hash.o
	gcc main.o hash.o -o week15 -O2 -Wall -lm -Wshadow
	rm -rf *.o *.gch
hash.o: hash.c hash.h
	gcc hash.c hash.h -c
main.o: main.c
	gcc main.c -c
