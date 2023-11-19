#include <stdio.h>


int main(){

    int scoremap[3][3] = {
        {1 + 3, 1 + 0, 1 + 6},
        {2 + 6, 2 + 3, 2 + 0},
        {3 + 0, 3 + 6, 3 + 3}
    };

    FILE *input = fopen("./input/day2.txt","r");

    char line[5];
    int score = 0;

    int myChoise;
    int opponentChoise;

    while(fgets(line, sizeof(line), input)){
        opponentChoise = line[0] - 'A';
        myChoise = line[2] - 'X';
        score += scoremap[myChoise][opponentChoise];
    }

    printf("total score = %d\n", score);
}