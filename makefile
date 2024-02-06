all: main.o my_mat.o connections

connections: main.o my_mat.o
	gcc -Wall main.o my_mat.o -o connections

main.o: main.c my_mat.h
	gcc -c -Wall main.c

my_mat.o: my_mat.c my_mat.h
	gcc -c -Wall my_mat.c
clean:
	rm -f *.o connections
