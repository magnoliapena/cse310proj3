#include "hashTable.h"
int returnVertices(std::string fileName, int y1, int y2){
    std::string getLine;
    int data = 0;
    int year = 0;
    int lineCounter = 1;
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
                data = std::stoi(getLine.substr(0, i-1));
                year = std::stoi(getLine.substr(i, getLine.length()));
                if(year >= y1 && year <= y2){
                    vertex++;
                }
            }
        }
    }
    file.close();
    return vertex;
}
int** readVertices(std::string fileName, int y1, int y2){
    std::string getLine;
    int data = 0;
    int year = 0;
    int lineCounter = 1;
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
                year = std::stoi(getLine.substr(i, getLine.length()));
                if(year >= y1 && year <= y2){
                    verticesArray[lineCounter][0] = data;
                    verticesArray[lineCounter][1] = year;
                }
            }
        }
    }
    file.close();
    return verticesArray;
}
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
Graph* createGraph(std::string edges, std::string dates, int y1, int y2){
    Graph* graph;
    graph->verticesArray = readVertices(dates, y1, y2);
    graph->vertices = returnVertices(dates, y1, y2);
    graph->adjacencyLists = createHashTable(graph->vertices);
    // instantiate num of vertices amd vertex labels to graph
    // create adjacency lists
    int vLabel[graph->vertices];
    //vLabel = new int[graph->vertices];
    //sort vertex labels in increasing order

    for(int i = 0; i < graph->vertices; i++){
        vLabel[i] = graph->verticesArray[i][0];
    }
    mergesort(vLabel, 0, graph->vertices-1);

    //add each vertex to hash table
    //in my project, i used as hash table to store the vertices and edges
    //index is used with the hash_function instead of the index in the vArray.
    for(int i = 0; i < graph->vertices; i++){
        insertHash(graph->adjacencyLists, graph->verticesArray[i][1], graph->verticesArray[i][0]);
    }

    //add all edges to graph
    addEdges(graph, edges, y1, y2);

    return graph;
}