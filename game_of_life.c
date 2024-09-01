#include "game_of_life.h"
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include <sys/time.h>

double gettime(void) {
  struct timeval tval;

  gettimeofday(&tval, NULL);

  return( (double)tval.tv_sec + (double)tval.tv_usec/1000000.0 );
}

double **allocarray(int P, int Q) {
  int i;
  double *p, **a;
  
  p = (char *)malloc(P*Q*sizeof(char));
  a = (char **)malloc(P*sizeof(char*));

  if (p == NULL || a == NULL) 
    printf("Error allocating memory\n");

  /* for row major storage */
  for (i = 0; i < P; i++)
    a[i] = &p[i*Q];
  
  return a;
}

//initialize the array with either a 0 or 1
double **initarray(double **a, int mrows, int ncols) {
  int i,j;
  srand48(time(NULL));

  for (i=0; i<mrows; i++)
    for (j=0; j<ncols; j++)
      a[i][j] = drand48() > 0.5 ? 0 : 1;  
  return a;
}

int num_neighbors(double** board, int size, int r, int c){
  int i,j,k,rd,cd;
  int count = 0;
  int directions[][2] = 
  {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1},
    {1,1},
    {1,-1},
    {-1,1},
    {-1,-1}
  };

    for(k = 0; k < 7; k++)
    {
      rd = r + directions[k][0];
      cd = c + directions[k][1];
      if(rd >= 0 && cd >= 0 && rd < size && cd < size && board[rd][cd] == '1') // check if it is within bounds
      {
        count++;
      }
    }
  return count;

}


 char** createNextState(char** curBoard, int size){
  int i,j,liveCount;
  for(i = 0; i < size; i++)
  {
    for(j = 0; j < size; j++)
    {
      liveCount = num_neighbors(curBoard, size,i,j);
      if(liveCount < )

    }
  }

 }