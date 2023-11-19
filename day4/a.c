#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* parseLine(char *line);

int main(){

    FILE *input = fopen("./input.txt","r");
    char buf[32];

    int result = 0;
    int resultB = 0;

    while(fgets(buf, sizeof(buf), input)){
        int *rangeA = parseLine(buf);
        int *rangeB = rangeA + 2;
        if(
            rangeA[0] <= rangeB[0] && rangeA[1] >= rangeB[1] ||
            rangeA[0] >= rangeB[0] && rangeA[1] <= rangeB[1] 
        ){
            result ++;
        }

        if(
            rangeA[0] <= rangeB[0] && rangeA[1] >= rangeB[0] ||
            rangeA[0] >= rangeB[0] && rangeA[0] <= rangeB[1] 
        ){
            resultB ++;
        }
        free(rangeA);
    }
    printf("resultA: %d\n", result);
    printf("resultB: %d\n", resultB);

    fclose(input);
}

int* parseLine(char *line){

    int *ranges = malloc(4 * sizeof(int));    
    char current[64] = "";
    int count = 0;


    while(*line != '\0'){
        if(*line == '-' || *line == ','){
            ranges[count] = strtol(current,NULL,10);
            count++;
            current[0] = '\0';
        }else{
            strncat(current, line, 1);
        }
        line ++;
    }

    if (strlen(current) > 0) {
        ranges[count] = strtol(current, NULL, 10);
        count++;
    }

    return ranges;
}