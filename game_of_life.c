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
  
  p = (double *)malloc(P*Q*sizeof(double));
  a = (double **)malloc(P*sizeof(double*));

  if (p == NULL || a == NULL) 
    printf("Error allocating memory\n");

  /* for row major storage */
  for (i = 0; i < P; i++)
    a[i] = &p[i*Q];
  
  return a;
}

//initialize the array with either a 0 or 1
double **initarray(double **a, int mrows, int ncols, double value) {
  int i,j;
  srand48(time(NULL));

  for (i=0; i<mrows; i++)
    for (j=0; j<ncols; j++)
      a[i][j] = drand48() > 0.5 ? 0 : 1;  
  return a;
}

