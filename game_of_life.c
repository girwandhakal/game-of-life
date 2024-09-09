#include "game_of_life.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>

double gettime(void)
{
  struct timeval tval;

  gettimeofday(&tval, NULL);

  return ((double)tval.tv_sec + (double)tval.tv_usec / 1000000.0);
}

char **allocarray(int P, int Q)
{
  int i;
  char *p, **a;

  p = (char *)malloc(P * Q * sizeof(char));
  a = (char **)malloc(P * sizeof(char *));

  if (p == NULL || a == NULL)
    printf("Error allocating memory\n");

  /* for row major storage */
  for (i = 0; i < P; i++)
    a[i] = &p[i * Q];

  return a;
}

// initialize the array with either a 0 or 1
char **initarray(char **a, int mrows, int ncols)
{
  int i, j;
  srand(time(NULL));

  for (i = 0; i < mrows; i++)
    for (j = 0; j < ncols; j++)
      a[i][j] = rand() % 2 ? '1' : '0';
  return a;
}

// creates deep copy of board
char **makeCopy(char **board, int size)
{
  int i, j;
  char *copy = (char *)malloc(sizeof(char) * size * size);
  if (copy == NULL)
  {
    printf("Error allocating memory \n");
    exit(0);
  }
  char **rowCopy = (char **)malloc(sizeof(char *) * size);
  if (rowCopy == NULL)
  {
    free(copy);
    printf("Error allocating memory \n");
    exit(0);
  }
  for (i = 0; i < size; i++)
  {
    rowCopy[i] = &copy[i * size];
    for (j = 0; j < size; j++)
    {
      rowCopy[i][j] = board[i][j];
    }
  }
  return rowCopy;
}

//returns number of live neighbors
int num_neighbors(char **board, int size, int r, int c)
{
  int i, j, k, rd, cd;
  int count = 0;
  int directions[][2] =
      {
          {1, 0},
          {-1, 0},
          {0, 1},
          {0, -1},
          {1, 1},
          {1, -1},
          {-1, 1},
          {-1, -1}};

  for (k = 0; k < 8; k++)
  {
    // new index
    rd = r + directions[k][0];
    cd = c + directions[k][1];
    if (rd >= 0 && cd >= 0 && rd < size && cd < size && (board[rd][cd] == '1' || board[rd][cd] == 'X')) // check if it is within bounds
    {
      count++;
    }
  }
  return count;
}

void createNextState(char **curBoard, int size, bool *changed)
{

  int i, j, live_neighbor_count;
  // char** nextState = makeCopy(curBoard, size); // more memory allocated here
  // mark either dead or live in next state
  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      live_neighbor_count = num_neighbors(curBoard, size, i, j);
      if (curBoard[i][j] == '1')
      {
        // live cell if more than 3 or less than 2 live neigbors die
        if (live_neighbor_count < 2 || live_neighbor_count > 3)
        {
          curBoard[i][j] = 'X'; // alive -> dead = X
          *changed = true;
        }
      }
      else
      {
        // dead cell if has 3 live neigbors comes alive next state
        if (live_neighbor_count == 3)
        {
          curBoard[i][j] = 'L'; // dead -> alive = L
          *changed = true;
        }
      }
    }
  }
  // make the updates
  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      if (curBoard[i][j] == 'X')
      {
        curBoard[i][j] = '0';
      }
      if (curBoard[i][j] == 'L')
      {
        curBoard[i][j] = '1';
      }
    }
  }
}

void printarray(char **a, int mrows, int ncols)
{
  int i, j;

  for (i = 0; i < mrows; i++)
  {
    for (j = 0; j < ncols; j++)
      printf("%c ", a[i][j]);
    printf("\n");
  }
}

bool isEqual(char **board1, char **board2, int size)
{
  int i, j;
  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      if (board1[i][j] != board2[i][j])
      {
        return false;
      }
    }
  }
  return true;
}

void freeArray(char **array)
{
  if (array != NULL)
  {
    free(array[0]); // Free the contiguous memory block that holds the actual data
    free(array);    // Free the memory block that holds the pointers to each row
  }
}
