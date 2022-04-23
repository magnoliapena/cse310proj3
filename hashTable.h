#ifndef CSE310PROJ3_HASHTABLE_H
#define CSE310PROJ3_HASHTABLE_H
#include "defns.h"
#include "linkedList.h"
struct HashTable{
    node** nodes;
    LinkedList** LinkedList;
    int size;
    int count;
};
#endif //CSE310PROJ3_HASHTABLE_H
