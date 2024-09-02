#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include <sys/time.h>
#include "game_of_life.h"


int main(int argc, char* argv[])
{
    //check arg count
    if(argc != 3)
    {
        printf("Usage: ./a <int size_of_board> <int num_of_generations>");
        exit(0);
    }
    int size_of_board = atoi(argv[1]);
    int num_of_generations = atoi(argv[2]);
    int generations = 0;


    printf("Created generation %d \n", generations);
    char** cur_board = initarray(allocarray(size_of_board,size_of_board),size_of_board,size_of_board); // create board and initialize
    printarray(cur_board, size_of_board,size_of_board);
    char** nextState = createNextState(cur_board, size_of_board);
    char** temp;

    while(generations < num_of_generations  && (cur_board != nextState))
    {
        generations++;
        printf("Created generation %d \n", generations);
        printarray(cur_board, size_of_board,size_of_board);
        temp = cur_board;
        cur_board = nextState;
        nextState = createNextState(cur_board, size_of_board);

        
        //printarray(nextState, size_of_board,size_of_board);
    }
    return 0;
}