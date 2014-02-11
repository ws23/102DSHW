main: main.o dlist.o
	gcc main.o dlist.o -o week16 -O2 -Wall -lm -Wshadow
	rm -rf *.o *.gch
dlist.o: dlist.c dlist.h
	gcc dlist.c dlist.h -c
main.o: main.c
	gcc main.c -c
