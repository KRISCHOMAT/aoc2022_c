#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void populateHalf(int *half, int size, char *line) {
    for (int i = 0; i < size; i++) {
        half[i] = line[i] - 'A' + 1;
    }
}


int findCommonElement(int *firstHalf, int *secondHalf, int size){
    for (int i = 0; i < size; i++){
        int currentA = firstHalf[i];
        for(int j = 0; j < size; j++){
            int currentB = secondHalf[j];
            if(currentA == currentB){                
                return currentA <= 26 ? currentA + 26 : currentA - (int)('a' - 'A') ;
            }
        }
    }

    return -1;
}

int main() {
    FILE *input = fopen("./input.txt", "r");
    char buf[100];
    int halfSize;
    int total = 0;

    while (fgets(buf, sizeof(buf), input)) {
        
        halfSize = strlen(buf) / 2;

        int *firstHalf = (int *)malloc(halfSize * sizeof(int));
        int *secondHalf = (int *)malloc(halfSize * sizeof(int));

        populateHalf(firstHalf, halfSize, buf);
        populateHalf(secondHalf, halfSize, buf + halfSize);

        total += findCommonElement(firstHalf,secondHalf,halfSize);

        free(firstHalf);
        free(secondHalf);

    }

    fclose(input);

    printf("Result is: %d\n", total);

    return 0;
}
