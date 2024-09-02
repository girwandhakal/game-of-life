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


    //printf("Created generation %d \n", generations);
    char** curState = initarray(allocarray(size_of_board,size_of_board),size_of_board,size_of_board); // create board and initialize
    //printarray(curState, size_of_board,size_of_board);
    char** nextState = createNextState(curState, size_of_board);
    char** temp;

    while(generations < num_of_generations  && !isEqual(curState,nextState, size_of_board))
    {
        generations++;
        //printf("Created generation %d \n", generations);
        //printarray(curState, size_of_board,size_of_board);
        temp = curState;
        curState = nextState;
        nextState = createNextState(curState, size_of_board);

        // free the curState
        // for(int i = 0; i < size_of_board; i++)
        // {
        //     free(temp[i]);
        // }
        // free(temp);
        //printarray(nextState, size_of_board,size_of_board);
    }
    double endTime = gettime();
    printf("Time taken = %lf seconds\n", endTime - startTime);
    return 0;
}