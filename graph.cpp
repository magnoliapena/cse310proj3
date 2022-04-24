#include <iostream>
#include "hashTable.h"

using namespace std;

//counts # of edges in graph and adds them to graph
int returnEdges(Graph* graph, std::string edges){
    int vertex1 = 0;
    int vertex2 = 0;
    int pos1 = 0;
    int pos2 = 0;
    int totalEdges = 0;
    std::string getLine;
    int lineCounter = 0;
    std::ifstream file;
    file.open(edges);
    while(getline(file, getLine)){
        lineCounter++;
        for(int i = 0; i < getLine.length(); i++){
            if(getLine.at(i) == ' '){
                vertex2 = std::stoi(getLine.substr(0, i));
                vertex1 = std::stoi(getLine.substr(i, getLine.length()-i));
            }
        }
        pos2 = searchHash(graph->hashTable, vertex2);
        pos1 = searchHash(graph->hashTable, vertex1);
        if(pos2 != -1){
            if(pos1 != -1){
                totalEdges++;
                node* temp = new node;
                temp->key = vertex2;
                temp->value = graph->hashTable->items[pos2]->value;
                insertList(graph->hashTable[pos1].nodes, temp);
            }
        }
    }
    file.close();
    return totalEdges;
}

//counts # of vertices in graph from y1 to y2
int returnVertices(std::string fileName, int y1, int y2){
    std::string getLine;
    int data = 0;
    int year = 0;
    int vertex = 0;
    std::ifstream file;
    file.open(fileName);
    while(getline(file, getLine)){
        for(int i = 0; i < getLine.length(); i++){
            if(getLine.at(i) == ' '){
                year = std::stoi(getLine.substr(i, getLine.length()-i));
                if(year >= y1 && year <= y2){
                    vertex++;
                }
            }
        }
    }
    file.close();
    return vertex;
}
//returns # of vertices per out-degree that exists in graph
void outDegreeDistribution(Graph* graph){
    std::cout<<"\nThe out-degree distribution is:";
    std::cout<<"\n\tOut-degree : Number of vertices ";
}
//computes outdegree from edges/vertices in graph
void outDegree(Graph* graph){
    double result = 0.0;
    result = graph->edges/graph->vertices;
    std::cout<<"Command: out-degree\n";
    std::cout<<"\nThe graph G has average out-degree " << graph->edges << "/"<< graph->vertices <<
             " = " << result << ".";
    outDegreeDistribution(graph);

}
//print diameter of graph
void diameter(Graph* graph){
    std::cout<<"Command: ";
    std::cout<<"\nThe graph G has diameter " << graph->diameter;
}
//store vertices from between y1 to y2 in 2d array with their data
node* readVertices(std::string fileName, int y1, int y2, int vertices){
    std::string getLine;
    int data = 0;
    int year = 0;
    int lineCounter = 0;
    std::ifstream file;
    file.open(fileName);
    while(getline(file, getLine)){
        lineCounter++;
    }
    file.close();
    node* verticesArray = nullptr;
    verticesArray =  new node[vertices];
    lineCounter = 0;
    file.open(fileName);
    while(getline(file, getLine)){
        for(int i = 0; i < getLine.length(); i++){
            if(getLine.at(i) == ' '){
                data = std::stoi(getLine.substr(0, i));
                year = std::stoi(getLine.substr(i, getLine.length()-i));
                if(year >= y1 && year <= y2){
                    verticesArray[lineCounter].value = data;
                    verticesArray[lineCounter].key = year;
                    lineCounter++;
                }
            }
        }
    }
    file.close();
    return verticesArray;
}
void scc(Graph* graph){
    std::cout<<"Command: ";
    std::cout<<"\nThe graph G has " << graph->sccNum << " strongly connected components: ";
    std::cout<<"\n\tSize : Number";
    //print out each scc using graph->sccArray
}
//main function for graph
Graph* createGraph(std::string edges, std::string dates, int y1, int y2){
    //allocate memory
    Graph* graph = (Graph*)malloc(sizeof(Graph*));
    //calculate # of vertices
    graph->vertices = returnVertices(dates, y1, y2);
    //store vertices with their key (year)
    graph->verticesArray = readVertices(dates, y1, y2, graph->vertices); //vertices Array
    //sort vertex labels in increasing order
    mergesort(graph->verticesArray, 0, graph->vertices-1);
    //create hash table
    graph->hashTable = createHashTable(graph->vertices); //adjacency list
    //add each vertex to hash table using hash function and separate chaining
    for(int i = 0; i < graph->vertices; i++){
        insertHash(graph->hashTable, graph->verticesArray[i].value, graph->verticesArray[i].key, i);
    }
    //add all edges to graph and return number of total edges
    graph->edges = returnEdges(graph, edges);

    //output
    std::cout<<"Command: start-graph " << y1 << " " <<y2<<"\n"; //echo command
    std::cout<<"\nThe graph G for the years " << y1 << "-" << y2 << " has:";
    std::cout<<"\n\t|V| = " << graph->vertices << " vertices";
    std::cout<<"\n\t|E| = " << graph->edges << " edges";

    return graph;
}
