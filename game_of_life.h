/*
 Name: Girwan Dhakal
 Email: gdhakal@crimson.ua.edu
 Course Section: CS 481 
 Homework #: 1
 Instructions to compile the program: gcc -Wall -O main.c game_of_life.c
 Instructions to run the program: ./a board_size num_of_generations
*/


#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H
#include <stdbool.h>

double gettime(void);
char **allocarray(int P, int Q);
char **initarray(char **a, int mrows, int ncols);
int num_neighbors(char** board, int size, int r, int c); // count num of neighbors
void createNextState(char** curBoard, int size, bool* changed); // generates next state given current State
char** makeCopy(char** board, int size); 
bool isEqual(char** board1, char** board2, int size);
void printarray(char **a, int mrows, int ncols);
void freeArray(char** array);

#endif
