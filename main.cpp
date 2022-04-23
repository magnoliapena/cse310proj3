#include <iostream>
#include <string>
#include "graph.h"

int main(int argc, char *argv[]) {
    std::string command; //input line
    Graph* graph = (Graph*)malloc(sizeof(Graph*));//create graph
    std::ifstream file;
    int commands = 0;
    int index = 0;
    file.open(argv[3]);

    //find # of commands
    while(getline(file, command)){
        commands++;
    }
    //instantiate size of array
    std::string commandsArray[commands];
    file.close();
    // get all commands in array
    file.open(argv[3]);
    while(getline(file, command)){
        commandsArray[index] = command;
        index++;
    }
    file.close();
    for(int i = 0; i < index; i++){
        if (commandsArray[i].substr(0, 11) == "start-graph"){
            int year1 = stoi(commandsArray[i].substr(12, 4));
            int year2 = stoi(commandsArray[i].substr(17, 4));
            graph = createGraph(argv[1], argv[2], year1, year2);
        }
        else if(commandsArray[i].substr(0, 10) == "out-degree"){
            outDegree(graph);
        }
        else if(commandsArray[i].substr(0, 8) == "diameter"){
            diameter(graph);
        }
        else if(commandsArray[i].substr(0, 2) == "scc"){
            scc(graph);
        }
        else if(commandsArray[i].substr(0, 10) == "end-graph"){
            break;
        }
    }
    return 0;
}
