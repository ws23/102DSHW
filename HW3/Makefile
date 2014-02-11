main: main.o depend.o
	gcc main.o depend.o -o HW3 -O2 -Wall -lm -Wshadow
	rm -rf *.o *.gch
depend.o: depend.c depend.h
	gcc depend.c depend.h -c
main.o: main.c
	gcc main.c -c
