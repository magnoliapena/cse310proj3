//
// Created by cse310 on 4/22/22.
//
#include "linkedList.h"
#include "hashTable.h"
#ifndef CSE310PROJ3_GRAPH_H
#define CSE310PROJ3_GRAPH_H
struct Graph{
    int vertices; //num of vertices
    int edges; //num of edges
    HashTable adjacencyLists;
};
Graph createGraph(std::string edges, std::string dates){
    int** edgesArray = readEdges(edges);
    int** verticesArray = readVertices(dates);
    Graph graph;
    return graph;
}
#endif //CSE310PROJ3_GRAPH_H
