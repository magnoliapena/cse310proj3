#include <iostream>
#include "hashTable.h"

using namespace std;

//counts # of edges in graph
int returnEdges(Graph* graph, std::string edges){
    return 0;
}

//counts # of vertices in graph from y1 to y2
int returnVertices(std::string fileName, int y1, int y2){
    std::string getLine;
    int data = 0;
    int year = 0;
    int lineCounter = 0;
    int vertex = 0;
    std::ifstream file;
    file.open(fileName);
    while(getline(file, getLine)){
        lineCounter++;
    }
    file.close();
    int** verticesArray = nullptr;
    lineCounter = 0;
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
int** readVertices(std::string fileName, int y1, int y2){
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
    int** verticesArray = nullptr;

    lineCounter = 0;
    file.open(fileName);
    while(getline(file, getLine)){
        for(int i = 0; i < getLine.length(); i++){
            if(getLine.at(i) == ' '){
                data = std::stoi(getLine.substr(0, i-1));
                year = std::stoi(getLine.substr(i, getLine.length()-i));
                if(year >= y1 && year <= y2){
                    verticesArray[lineCounter][0] = data;
                    verticesArray[lineCounter][1] = year;
                    std::cout<<data<<"\t"<<year<<"\n";
                }
            }
        }
    }
    file.close();
    return verticesArray;
}
//add edges to graph that have vertices between y1 and y2
void addEdges(Graph* graph, std::string fileName, int y1, int y2){
    std::ifstream file;
    file.open(fileName);
    std::string getLine;
    int totalEdges = 0;
    while(getline(file, getLine)){
        totalEdges++;
    }
    file.close();

    for(int i = 0; i < graph->edges; i++){

    }
}
void scc(Graph* graph){
    std::cout<<"Command: ";
    std::cout<<"\nThe graph G has " << graph->sccNum << " strongly connected components: ";
    std::cout<<"\n\tSize : Number";
    //print out each scc using graph->sccArray
}
//main function for graph
Graph* createGraph(std::string edges, std::string dates, int y1, int y2){
    Graph* graph = (Graph*)malloc(sizeof(Graph*));
    graph->vertices = 0;
    graph->edges = 0;
    graph->verticesArray = nullptr;
    graph->adjacencyLists = nullptr;
    graph->diameter = 0;
    graph->sccNum = 0;
    graph->sccArray = nullptr;
    //allocate memory and store everything as null first
    graph->vertices = returnVertices(dates, y1, y2); //num of vertices
    graph->adjacencyLists = createHashTable(graph->vertices); //adjacency list
    graph->verticesArray = readVertices(dates, y1, y2); //vertices Array
    graph->vLabel[graph->vertices]; //only vertex no data
    for(int i = 0; i < graph->vertices; i++){
        graph->vLabel[i] = graph->verticesArray[i][0];
    }
    //sort vertex labels in increasing order
    mergesort(graph->vLabel, 0, graph->vertices-1);
    //add each vertex to hash table using hash function and separate chaining
    for(int i = 0; i < graph->vertices; i++){
        insertHash(graph->adjacencyLists, graph->verticesArray[i][1], graph->verticesArray[i][0]);
    }
    //add all edges to graph
    addEdges(graph, edges, y1, y2);
    graph->edges = returnEdges(graph, edges); //num of edges

    //output
    std::cout<<"Command: start-graph " << " "<< y1 << " " <<y2<<"\n"; //echo command
    std::cout<<"\nThe graph G for the years " << y1 << "-" << y2 << " has:";
    std::cout<<"\n\t|V| = " << graph->vertices << " vertices";
    std::cout<<"\n\t|E| = " << graph->edges << " edges";

    return graph;
}
