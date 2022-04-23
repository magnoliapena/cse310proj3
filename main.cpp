#include <iostream>
#include <string>
#include "graph.h"

int main(int argc, char *argv[]) {
    std::string command; //input line
    Graph* graph;//create graph
    std::ifstream file;
    char* commandArray;
    int commands = 0;
    int index = 0;
    file.open(argv[3]);

    while(getline(file, command)){
        if(command.substr(0, 11) == "start-graph"){
            int year1 = stoi(command.substr(12, 4));
            int year2 = stoi(command.substr(17, 4));
            std::cout<<"Command: "<< command; //echo command
            std::cout<<"\nThe graph G for the years " << year1 << "-" << year2 << " has:";
            graph = createGraph(argv[1], argv[2],year1, year2);
//            std::cout<<"\n\t|V| = " << graph->vertices << "vertices";
//            std::cout<<"\n\t|E| = " << graph->edges<< "edges";
//            std::cout<<"\n";

        }
//        else if(command.substr(0, 9) == "out-degree"){
//            std::cout<<"Command: " << command;
//            std::cout<<"\nThe graph G has average out-degree " << returnEdges(argv[1])<< "/"<< returnVertices(argv[2]) <<
//            " = " << graph->edges/graph->vertices << ".";
//            std::cout<<"\nThe out-degree distribution is:";
//            std::cout<<"\n\tOut-degree : Number of vertices ";
//            std::cout<< outDegree()<<"\n";
//        }
//        else if(command.substr(0, 7) == "diameter"){
//            std::cout<<"Command: ";
//            std::cout<<"\nThe graph G has diameter " << returnDiameter();
//        }
//        else if(command.substr(0, 2) == "scc"){
//            std::cout<<"Command: ";
//            std::cout<<"\nThe graph G has " << returnComponents() << " strongly connected components: ";
//            std::cout<<"\n\tSize : Number";
//            std::cout<<scc()<<"\n";
//        }
        else if(command.substr(0, 9) == "end-graph"){
            break;
        }
    }
    return 0;
}
