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
    //char** temp;
    char** curState = initarray(allocarray(size_of_board,size_of_board),size_of_board,size_of_board); // create board and initialize
    //char** nextState = createNextState(curState, size_of_board); // create first generation  
    while(generations < num_of_generations  /*&& !isEqual(curState,nextState, size_of_board)*/)
    {
        changed = false;
        generations++;
        // temp = curState;
        // curState = nextState;
        createNextState(curState, size_of_board, &changed);
        if(!changed)
        {
            break;
        }
        //freeArray(temp);
    }
    freeArray(curState);
    double endTime = gettime();
    printf("Time taken = %lf seconds\n", endTime - startTime);
    return 0;
}