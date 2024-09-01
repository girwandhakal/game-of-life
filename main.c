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
    char** cur_board = initarray(allocarray(size_of_board,size_of_board),size_of_board,size_of_board); // create board and initialize
    char** next_board;

    while(generations < num_of_generations && (cur_board != next_board))
    {
        // char** createNextState(char** curBoard)


    }



    return 0;
}