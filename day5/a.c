#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "linkedList.h"

#define StackNum 9
#define StackWidth 4

struct Move{
    int times;
    int from;
    int to;
};

int main(){
    FILE *input = fopen("./input.txt","r");
    struct Node** stacks = (struct Node**)malloc(StackNum * sizeof(struct Node));
    char buf[64];

    while(fgets(buf,sizeof(buf), input) && buf[0] != '\n'){
        int currentStack = 0;
        for(int i = 0; i < sizeof(buf) && buf[i] != '\0'; i++){
            if(i%StackWidth != 1)continue;
            if(isupper(buf[i])){
                addNode(&stacks[currentStack],buf[i]);
            }
            currentStack++;
        }
    }

    for(int i = 0; i < StackNum; i++){
        printList(stacks[i]);
    }

    struct Move commands;

    while(fgets(buf,sizeof(buf),input)){
        sscanf(buf,"move %d from %d to %d", &commands.times, &commands.from, &commands.to);
        // Part A
        // for(int i = 0; i < commands.times; i++){
        //     prependNode(&stacks[commands.to - 1],removeHead(&stacks[commands.from - 1]));
        // }
        // PartB
        removeFromList(&stacks[commands.to - 1],&stacks[commands.from - 1], commands.times);
    }

    printf("\n\n");

    for(int i = 0; i < StackNum; i++){
        printList(stacks[i]);
    }

    for(int i = 0; i < StackNum; i++){
        freeList(stacks[i]);
    }

    fclose(input);
}