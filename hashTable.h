#ifndef CSE310PROJ3_HASHTABLE_H
#define CSE310PROJ3_HASHTABLE_H
#include "linkedList.h"
//create 'vertex'
node* newPoint(int key, int data);
//hash functions
int hash_function(int key, int size);
//create adjacencyList
LinkedList** pLinkedList(HashTable* ht);
//collision handling using separate chaining
void separateChain(HashTable *table, int index, node *item);
//insert item into hashtable and check if spot exists in table
void insertHash(HashTable *table, int key, int data, int index);
// search for node in hashtable and returns value
int searchHash(HashTable *table, int key);
//create table with allocated memory and set everything to null;
HashTable* createHashTable(int size);
#endif //CSE310PROJ3_HASHTABLE_H
