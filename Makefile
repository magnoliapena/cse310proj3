exec = gp
flags = -g -Wall -c -std=c++11

all: $(exec)

$(exec): main.o linkedList.o graph.o hashTable.o defns.o DFS.o FWalgorithm.o
	g++	-o	$(exec) $^

main.o: main.cpp
	g++ $(flags) $^

defns.o: defns.cpp
	g++	$(flags) $^

linkedList.o: linkedList.cpp
	g++	$(flags) $^

graph.o: graph.cpp
	g++ $(flags) $^

hashTable.o: hashTable.cpp
	g++ $(flags) $^

DFS.o: DFS.cpp
	g++	$(flags) $^

FWalgorithm.o: FWalgorithm.cpp
	g++ $(flags) $^

clean:
	-rm -f *.o *.out
