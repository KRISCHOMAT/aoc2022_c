#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

struct Node* initNode(char data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

void addNode(struct Node** list, char data) {
    struct Node* newNode = initNode(data);

    if(*list == NULL){
        *list = newNode;
    } else {
    struct Node* current = *list;
    while (current->next != NULL) {
        current = current->next;
    }
        current->next = newNode;    
    }
}

struct Node* findNode(struct Node* list, char data){
    while (list != NULL){
        if(list->data == data){
            break;
        }
        list = list->next;
    } 

    if(list){
        return list;
    } else{
        return NULL;
    }
}

void printList(const struct Node* head) {
    const struct Node* current = head;
    while (current != NULL) {
        printf("%c -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

struct Node* removeHead(struct Node** list){
    struct Node* head = *list;
    struct Node* next = head->next;

    head->next = NULL;

    *list = next;
    return head;
}


void prependNode(struct Node** list, struct Node* node){
    node->next = *list;
    *list = node;
}

void removeFromList(struct Node** target, struct Node** list, int amount){
    struct Node* current = *list;
    struct Node* first = *list;
    
    for(int i = 1; i < amount; i++){
        current = current->next;
    }
    *list = current->next;
    current->next = *target;
    *target = first;
}