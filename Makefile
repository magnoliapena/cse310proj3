gp = a.out
flags = -g -Wall -c -std=c++11

all: $(gp)

$(gp): main.o linkedList.o graph.o hashTable.o defns.o
	g++	-o	$(gp) $^

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

clean:
	-rm -f *.o *.out
