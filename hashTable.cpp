#include <iostream>
#include "linkedList.h"

node* newPoint(int key, int data){
    node* item = (node*)malloc(sizeof(node));
    //allocate memory
    item->key = key;
    item->value = data;
    return item;
}
//create adjacencyList
LinkedList* pLinkedList(HashTable* ht){
    LinkedList* adjList = (LinkedList*)calloc(ht->size, sizeof(LinkedList*));
    //allocate memory for adjacencyList
    for(int i = 0; i < ht->size; i++){
        adjList = nullptr; //set everything in list as null
    }
    return adjList;
}
//collision handling using separate chaining
//void separateChain(HashTable *table, int index, node *item){
//    LinkedList* temp = table->LinkedList[index];
//    if(temp== nullptr){
//        temp = createList();
//        temp->node = item;
//        table->LinkedList[index] = temp;
//    }
//    else{
//        //add to existing linked list
//        table->LinkedList[index] = insertList(temp, item);
//    }
//}
//insert item into hashtable and check if spot exists in table
void insertHash(HashTable *table, int key, int data, int index){
    node* item = newPoint(key, data);
//    int hashIndex = hash_function(key, table->size);
    node* temp = table->items[index];
    if(temp == nullptr){
        //check if there is anything in the spot
        if(table->count != table->size){
            table->items[index] = item;
            table->count++; //update how many items in hashtable
            //only works as long as the hash table is not full
        }
    }
    else{ //collision handling for hashtable
//        separateChain(table, index, item);
    }
}
// search for node in hashtable and returns value
int searchHash(HashTable *table, int key){
    for(int i = 0; i < table->size; i++){
        if(table->items[i]->key == key){
            return i; //returns index
        }
    }
    return -1;
}
//create table with allocated memory and set everything to null;
HashTable* createHashTable(int size){
    //allocate memory for HashTable
    auto* ht = (HashTable*)malloc(sizeof(HashTable*));
    ht->size = size;
    ht->count = 0;
    ht->items = (node**)calloc(ht->size, sizeof(node**));
    for(int i = 0; i < ht->size; i++){
        ht->items[i] = nullptr; //set everything as null
        //create linked list for each node in hash table at each index
        ht->nodes = pLinkedList(ht);
    }
    return ht;
}