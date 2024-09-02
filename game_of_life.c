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

char **allocarray(int P, int Q) {
  int i;
  char *p, **a;
  
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
char **initarray(char **a, int mrows, int ncols) {
  int i,j;
  srand(time(NULL));

  for (i=0; i<mrows; i++)
    for (j=0; j<ncols; j++)
      a[i][j] = rand()%2 ? '1' : '0';
  return a;
}

char **makeCopy(char** board, int size)
{
  int i,j;
  char* copy = (char*)malloc(sizeof(char) * size * size);
  if(copy == NULL)
  {
    printf("Error allocating memory \n");
    exit(0);
  }
  char** rowCopy = (char**)malloc(sizeof(char*)*size);
  if(rowCopy == NULL)
  {
    free(copy);
    printf("Error allocating memory \n");
    exit(0);
  }
  for(i = 0; i < size; i++)
  {
    rowCopy[i] = &copy[i*size];
    for(j = 0; j < size; j++)
    {
      //printf("in makeCopy() line : %d\n",__LINE__);
      rowCopy[i][j] = board[i][j];
      //printf("%d\n",__LINE__);
    }
  }
  return rowCopy;
}

int num_neighbors(char** board, int size, int r, int c){
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

    for(k = 0; k < 8; k++)
    {
      rd = r + directions[k][0];
      cd = c + directions[k][1];
      if(rd >= 0 && cd >= 0 && rd < size && cd < size && (board[rd][cd] == '1' || board[rd][cd] == 'X')) // check if it is within bounds
      {
        count++;
      }
    }
  return count;

}

char** createNextState(char** curBoard, int size){

  int i,j,liveCount;
  char** nextState = makeCopy(curBoard, size);
  //mark either dead or live in next state
  for(i = 0; i < size; i++)
  {
    for(j = 0; j < size; j++)
    {
      liveCount = num_neighbors(curBoard, size,i,j);
      if(curBoard[i][j] == '1')
      {
        // live cell if more than 3 or less than 2 live neigbors die
        if(liveCount < 2 || liveCount > 3){
          nextState[i][j] = 'X';
        }
      }
      else
      {
        // dead cell if has 3 live neigbors comes alive next state
        if(liveCount == 3)
        {
          nextState[i][j] = 'L';
        }
      }
    }
  }
  
  //replace X's and L's in the next state
  for(i = 0; i < size; i++)
  {
    for(j = 0; j < size; j++)
    {
      if(nextState[i][j] == 'X')
      {
        nextState[i][j] = '0';
      }
      else if(nextState[i][j] == 'L')
      {
        nextState[i][j] = '1';
      }
    }
  }
  return nextState;

 }

void printarray(char **a, int mrows, int ncols) {
  int i,j;
  
  for (i=0; i<mrows; i++) {
    for (j=0; j<ncols; j++)
      printf("%c ", a[i][j]);
    printf("\n");
  }
}
