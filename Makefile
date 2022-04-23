gp = main
flags = -g -Wall

all: $(gp)

$(gp):  defns.h	linkedList.h hashTable.h graph.h
	g++	$(gp) $(flags) $<

clean:
	rm -f main