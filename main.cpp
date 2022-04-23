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
            std::cout<<"Command: "<< commandsArray[i]; //echo command
            std::cout<<"\nThe graph G for the years " << year1 << "-" << year2 << " has:";
            graph = createGraph(argv[1], argv[2],year1, year2);
            std::cout<<"\n\t|V| = " << returnVertices(argv[2], year1, year2)<< " vertices";
            std::cout<<"\n";
            //std::cout<<"\n\t|E| = " << graph->edges << " edges";
        }
//        else if(commandsArray[i].substr(0, 9) == "out-degree"){
//            std::cout<<"Command: " << command;
//            std::cout<<"\nThe graph G has average out-degree " << returnEdges(argv[1])<< "/"<< returnVertices(argv[2]) <<
//            " = " << graph->edges/graph->vertices << ".";
//            std::cout<<"\nThe out-degree distribution is:";
//            std::cout<<"\n\tOut-degree : Number of vertices ";
//            std::cout<< outDegree()<<"\n";
//        }
//        else if(commandsArray[i].substr(0, 7) == "diameter"){
//            std::cout<<"Command: ";
//            std::cout<<"\nThe graph G has diameter " << returnDiameter();
//        }
//        else if(commandsArray[i].substr(0, 2) == "scc"){
//            std::cout<<"Command: ";
//            std::cout<<"\nThe graph G has " << returnComponents() << " strongly connected components: ";
//            std::cout<<"\n\tSize : Number";
//            std::cout<<scc()<<"\n";
//        }
        else if(commandsArray[i].substr(0, 9) == "end-graph"){
            break;
        }
    }
    return 0;
}
