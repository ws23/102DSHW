main: main.o tree.o
	gcc main.o tree.o -o main -O2 -Wall -lm -Wshadow
	rm -rf *.o *.gch
tree.o: tree.c tree.h
	gcc tree.c tree.h -c
main.o: main.c
	gcc main.c -c
