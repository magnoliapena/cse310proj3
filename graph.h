#include "hashTable.h"
#ifndef CSE310PROJ3_GRAPH_H
#define CSE310PROJ3_GRAPH_H
int returnVertices(std::string fileName, int y1, int y2);
int returnEdges(Graph* graph, std::string edges);
int** readVertices(std::string fileName, int y1, int y2);
void addEdges(Graph* graph, std::string edges);
void outDegree(Graph* graph);
void outDegreeDistribution(Graph* graph);
void diameter(Graph* graph);
void scc(Graph* graph);
Graph* createGraph(std::string edges, std::string dates, int y1, int y2);
#endif //CSE310PROJ3_GRAPH_H
