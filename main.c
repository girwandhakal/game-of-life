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


    return 0;
}