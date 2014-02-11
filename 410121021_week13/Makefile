main: main.o sol.o
	gcc main.o sol.o -o 410121021_week13 -O2 -Wall -Wshadow -lm
	rm -rf *.gch *.o
main.o: main.c
	gcc main.c -c 
sol.o: sol.h sol.c
	gcc sol.c sol.h -c
