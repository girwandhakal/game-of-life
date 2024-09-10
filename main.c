#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include <sys/time.h>
#include "game_of_life.h"


int main(int argc, char* argv[])
{
    double startTime = gettime();
    //check arg count
    if(argc != 3)
    {
        printf("Usage: ./a <int size_of_board> <int num_of_generations>");
        exit(0);
    }
    int size_of_board = atoi(argv[1]);
    int num_of_generations = atoi(argv[2]);
    int generations = 0;
    bool changed = false;
    char** curState = initarray(allocarray(size_of_board,size_of_board),size_of_board,size_of_board); 
    while(generations < num_of_generations)
    {
        changed = false;
        createNextState(curState, size_of_board, &changed);
        if(!changed)
        {
            break;
        }
        generations++;
    }
    freeArray(curState);
    double endTime = gettime();
    printf("Time taken = %lf seconds\n", endTime - startTime);
    return 0;
}