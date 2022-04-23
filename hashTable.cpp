#include "linkedList.h"
#include "hashTable.h"
#include <cmath>

using namespace std;

//create 'vertex'
node* newPoint(int key, int data){
    node* item = (node*)malloc(sizeof(node));
    item->key = (int*) malloc(sizeof(key) + 1);
    item->value = (int*)malloc(sizeof(data) + 1);
    //allocate memory
    item->key = &key;
    item->value = &data;
}
//hash functions
int hash_function(int *key, int size){
    return *key % size; //index of where key is at using key % tablesize function
    //example size = 37 and key = year 2000, hash_function returns, 2, should be in spot 2
}
//creat adjacencyList
LinkedList** pLinkedList(HashTable* ht){
    LinkedList** adjList = (LinkedList**)calloc(ht->size, sizeof(LinkedList*));
    //allocate memory for adjacencyList
    for(int i = 0; i < ht->size; i++){
        adjList[i] = nullptr; //set everything in list as null
    }
}
//collision handling using separate chaining
void separateChain(HashTable *table, int index, node *item){
    LinkedList* temp = table->LinkedList[index];
    if(temp== nullptr){
        temp = createList();
        temp->node = item;
        table->LinkedList[index] = temp;
    }
    else{
        //add to existing linked list
        table->LinkedList[index] = insertList(temp, item);
    }
}
//insert item into hashtable and check if spot exists in table
void insertHash(HashTable *table, int *key, int data){
    node* item = newPoint(*key, data);
    int hashIndex = hash_function(key, table->size);
    node* temp = table->nodes[hashIndex];
    if(temp == nullptr){
        //check if there is anything in the spot
        if(table->count != table->size){
            table->nodes[hashIndex] = item;
            table->count++; //update how many items in hashtable
            //only works as long as the hash table is not full
        }
    }
    else{ //collision handling for hashtable
        separateChain(table, hashIndex, item);
    }
}
// search for node in hashtable and returns value
bool searchHash(HashTable *table, int *key){
    int hashIndex = hash_function(key, table->size);
    node* temp = table->nodes[hashIndex];
    if(temp != nullptr && (temp->key == key)){
        return true;
    }
    return false;
}
//create table with allocated memory and set everything to null;
HashTable* createHashTable(int size){
    int newSize = 1.3*size;
    bool found = false;
    bool isPrime = true;

    //calculate nearest prime for optimal hash table size
    while(!found){
        newSize++;
        for(int i = 2; i <= newSize/2; i++){
            if(newSize % i == 0){
                isPrime = false;
            }
        }
        if(isPrime){
            found = true;
            isPrime = true;
        }
    }
    //allocate memory for HashTable
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = newSize;
    ht->count = 0;
    ht->nodes = (node**)calloc(ht->size, sizeof(node*));
    for(int i = 0; i < ht->size; i++){
        ht->nodes[i] = nullptr; //set everything as null
        //create linked list for each node in hash table at each index
        ht->LinkedList = pLinkedList(ht);
    }

}