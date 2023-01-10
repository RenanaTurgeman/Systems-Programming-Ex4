CC = gcc
AR = ar 
FLAGS = -Wall -g
OBJECCTS_MAIN = main.o
OBJECTS_GRAPH = graph.o

all: graph libgraph.a

main.o: main.c algo.h edges.h graph.h nodes.h
	$(CC) $(FLAGS) -c main.c

algo.o: algo.c algo.h
	$(CC) $(FLAGS) -c algo.c

edges.o: edges.c edges.h
	$(CC) $(FLAGS) -c edges.c

graph.o: graph.c graph.h
	$(CC) $(FLAGS) -c graph.c

nodes.o: nodes.c nodes.h
	$(CC) $(FLAGS) -c nodes.c

libgraph.a: $(OBJECTS_GRAPH)
	$(AR) -rsc libgraph.a $(OBJECTS_GRAPH)

graph: $(OBJECCTS_MAIN) libgraph.a
	$(CC) $(FLAGS) -o graph $(OBJECCTS_MAIN) libgraph.a -lm

.PHONY: clean all
clean:
	rm -f *.o *.a *.so graph