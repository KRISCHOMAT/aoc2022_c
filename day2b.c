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

    int outcome;
    int myChoise;
    int opponentChoise;

    while(fgets(line, sizeof(line), input)){
        opponentChoise = line[0] - 'A';
        outcome = line[2] - 'X';
        myChoise = (opponentChoise + 2 + outcome)%3;

        printf("opponent: %d, outcome: %d, myChoise: %d\n", opponentChoise,outcome,myChoise);
        // 0: lose 1: draw 2: win
        score += scoremap[myChoise][opponentChoise];
    }

    printf("\ntotal score = %d\n", score);
}