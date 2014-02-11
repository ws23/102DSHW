main: main.o mouse.o cat.o map.o
	gcc main.o mouse.o cat.o map.o -o main -O2 -Wall
	rm -rf *.o *.gch
mouse.o: mouse.c mouse.h
	gcc mouse.c mouse.h -c
cat.o: cat.c cat.h
	gcc cat.c cat.h -c
map.o: map.c map.h
	gcc map.c map.h -c
main.o: main.c
	gcc main.c -c
