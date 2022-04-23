#include "hashTable.h"
#ifndef CSE310PROJ3_GRAPH_H
#define CSE310PROJ3_GRAPH_H
int returnVertices(std::string fileName, int y1, int y2);
int** readVertices(std::string fileName, int y1, int y2);
void addEdges(Graph* graph, std::string fileName, int y1, int y2);
Graph* createGraph(std::string edges, std::string dates, int y1, int y2);
#endif //CSE310PROJ3_GRAPH_H
