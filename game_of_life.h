#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H
#include <stdbool.h>

double gettime(void);
char **allocarray(int P, int Q);
char **initarray(char **a, int mrows, int ncols);
int num_neighbors(char** board, int size, int r, int c); // count num of neighbors
char** createNextState(char** curBoard, int size); // generates next state given current State
char** makeCopy(char** board, int size); 
bool isEqual(char** board1, char** board2, int size);
void printarray(char **a, int mrows, int ncols);
void freeArray(char** array);

#endif
