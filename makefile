all: my_graph.o my_mat.o my_graph my_Knapsack.o my_Knapsack

my_graph: my_graph.o my_mat.o
	gcc -Wall my_graph.o my_mat.o -o my_graph

my_graph.o: my_graph.c my_mat.h
	gcc -c -Wall my_graph.c

my_mat.o: my_mat.c my_mat.h
	gcc -c -Wall my_mat.c

my_Knapsack: my_Knapsack.o
	gcc -Wall my_Knapsack.o -o my_Knapsack

my_Knapsack.o: my_Knapsack.c
	gcc -c -Wall my_Knapsack.c

clean:
	rm -f *.o my_graph my_Knapsack
