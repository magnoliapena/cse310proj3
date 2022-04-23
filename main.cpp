#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include "graph.h"

int main(int argc, char *argv[]) {
    std::string command; //input line
    Graph graph = createGraph(argv[1], argv[2]); //create graph with parameters of the
    std::ifstream file;
    file.open(argv[3]);
    // cases for each command
    while(getline(file, command)){
        if(command.substr(0, 10) == "start-graph"){
            std::cout<<"Command: "<< command; //echo command
            std::cout<<"\nThe graph G for the years " << command.substr(12,15) << " " << command.substr(17, 20);
            std::cout<<"\n\t|V| = " << graph.returnVertices << "vertices";
            std::cout<<"\n\t|E| = " << graph.returnEdges << "edges";
            std::cout<<"\n";

        }
        else if(command.substr(0, 9) == "out-degree"){
            std::cout<<"Command: " << command;
            std::cout<<"\nThe graph G has average out-degree " << graph.returnEdges << "/"<< graph.returnVertices <<
            " = " << graph.returnEdges/graph.returnVertices << ".";
            std::cout<<"\nThe out-degree distribution is:";
            std::cout<<"\n\tOut-degree : Number of vertices ";
            std::cout<< graph.outDegree()<<"\n";
        }
        else if(command.substr(0, 7) == "diameter"){
            std::cout<<"Command: ";
            std::cout<<"\nThe graph G has diameter " << graph.returnDiameter;
        }
        else if(command.substr(0, 2) == "scc"){
            std::cout<<"Command: ";
            std::cout<<"\nThe graph G has " << graph.returnComponents << " strongly connected components: ";
            std::cout<<"\n\tSize : Number";
            std::cout<<graph.scc()<<"\n";
        }
        else if(command.substr(0, 8) == "end-graph"){
            break;
        }
    }
    return 0;
}
