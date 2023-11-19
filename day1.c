#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){

    FILE *input = fopen("./input/day1.txt", "r");

    char line[100];
    int topThree[] = {0,0,0};
    int current = 0;


    while(fgets(line, 100, input)){
        if(line[0] == '\n' || line[0] == '\0'){
            //highest = current > highest ? current : highest;
            topThree[0] = current > topThree[0] ? current : topThree[0];
            topThree[1] = current > topThree[1] ? current : topThree[1];
            topThree[2] = current > topThree[2] ? current : topThree[2];

            current = 0;       
        } else {
        current += atoi(line);
        }
    }

    printf("first: %d \n", topThree[0]);
    printf("second: %d \n", topThree[1]);
    printf("third: %d \n", topThree[2]);


    return 0;
}