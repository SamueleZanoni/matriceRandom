#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIM 15

void genera(int m[][DIM], int dim)
{
  srand(time(NULL));
  for(int i=0; i<dim; i++)
    {
      for(int j=0; j<dim; j++)
        m[i][j]=(rand()%100)+1;
    }
}

void scriviSuFile(int m[][DIM], int dim)
{
  FILE *fp = fopen("matrice.csv", "w");

  for(int i=0; i<dim; i++)
    {
      for(int j=0; j<dim; j++)
        {
          fprintf(fp, "%d,", m[i][j]);
        }
      fprintf(fp, "\n");
    }
  fclose(fp);
}

void stampaCsv(int dim)
{
  int m[dim][dim];
  FILE *fp = fopen("matrice.csv", "r");

  if (fp == NULL)
    printf("\nERRORE");

  for(int i=0; i<dim; i++)
    {
      printf("\n");
      for(int j=0; j<dim; j++)
        {
          fscanf(fp, "%d,", &m[i][j]);
          printf("%d\t", m[i][j]);
        }
    }
  fclose(fp);
}

int main(void) 
{
  int n;

  do 
    {
      printf("\ninserire la grandezza della matrice: ");
      scanf("%d", &n);
    }
    while(n<0);

  int mat[n][n], scelta;

  do 
    {
      printf("\ninserire la scelta: ");
      scanf("%d", &scelta);
      switch(scelta){
        case 1:
        genera(mat, n);
        break;
        
        case 2:
        scriviSuFile(mat, n);
        break;
        
        case 3:
        stampaCsv(n);
        break;

        default:
        break;
      }
      
    }
    while(scelta!=0);
}