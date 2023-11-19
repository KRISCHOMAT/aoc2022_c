#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

#define STACK_NUM 9


int main(){

    struct Node** stacks = (struct Node**)malloc(STACK_NUM * sizeof(struct Node));
    addNode(&stacks[0],'A');
    addNode(&stacks[0],'B');
    addNode(&stacks[0],'C');

    addNode(&stacks[1],'a');
    addNode(&stacks[1],'b');
    addNode(&stacks[1],'c');
    addNode(&stacks[1],'d');

    printList(stacks[0]);
    printList(stacks[1]);


}