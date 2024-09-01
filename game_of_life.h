#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

double gettime(void);
char **allocarray(int P, int Q);
char **initarray(double **a, int mrows, int ncols);
int num_neighbors(double** board, int size, int r, int c); // count num of neighbors
char** createNextState(char** curBoard, int size); 
#endif
