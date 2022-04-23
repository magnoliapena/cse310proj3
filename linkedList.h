#ifndef CSE310PROJ3_LINKEDLIST_H
#define CSE310PROJ3_LINKEDLIST_H
#include "defns.h"
#include <cmath>

LinkedList* createList(){
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    return list;
}
LinkedList* insertList(LinkedList* list, node* item){
    if(!list){
        //allocate memory if list does not exist
        LinkedList* head = createList();
        head->node = item;
        head->next = nullptr;
        list = head;
    }
    else if(list->next == nullptr){
        LinkedList* temp = createList();
        temp->node = item;
        temp->next = nullptr;
        list->next = temp;
    }
    //otherwise move everything over one
    LinkedList* temp = createList();
    while(temp->next->next){
        temp = temp->next;
    }
    LinkedList* newList = createList();
    newList->node = item;
    newList->next = nullptr;
    // put new list as next
    temp->next = newList;

    return list;
}
#endif //CSE310PROJ3_LINKEDLIST_H
