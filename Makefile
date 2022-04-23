gp = main
flags = -c -g -Wall
all: $(gp)

$(gp): adjacencyList.o createGraph.o

adjacencyList.o: adjacencyList.cpp
	g++ $(flags) $^

createGraph.o: graph.cpp
	g++ $(flags) $^

clean:
	rm *.o main