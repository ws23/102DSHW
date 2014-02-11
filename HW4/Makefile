main: main.o hashfuncs.o hash.o
	gcc main.o hashfuncs.o hash.o -o HW4 -O2 -Wall -lm -Wshadow
	rm -rf *.o *.gch
hash.o: hash.c hash.h
	gcc hash.c hash.h -c
hashfuncs.o: hashfuncs.c hashfuncs.h
	gcc hashfuncs.c hashfuncs.h -c
main.o: main.c
	gcc main.c -c
