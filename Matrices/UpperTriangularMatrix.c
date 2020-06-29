#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
  int *A;
  int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
  /*
  // Row-major
  if (i<=j)
    m->A[m->n*(i-1)-(i-2)*(i-1)/2+j-i]=x;
    */

  // Column-major
  if (i<=j)
    m->A[j*(j-1)/2+i-1]=x;
}

int Get(struct Matrix m, int i, int j)
{
  /*
  // Row-major
  if (i<=j)
    return m.A[m.n*(i-1)-(i-2)*(i-1)/2+j-i];
  else
    return 0;
    */
  // Column-major
  if (i<=j)
    return m.A[j*(j-1)/2+i-1];
}

void Display(struct Matrix m)
{
  int i, j;
  for(i=1;i<=m.n;i++)
  {
    for(j=1;j<=m.n;j++)
    {
      if (i<=j)
        // Row-major
        // printf("%d ",m.A[m.n*(i-1)-(i-2)*(i-1)/2+j-i]);
        
        // Column-major
        printf("%d ",m.A[j*(j-1)/2+i-1]);
      else
        printf("0 ");
    }
    printf("\n");
  }
}

int main()
{
  struct Matrix m;
  int i, j, x;

  printf("Enter Matrix Dimension: ");
  scanf("%d", &m.n);
  m.A = (int *)malloc(m.n*(m.n+1)/2*sizeof(int));

  printf("Enter all elements: \n");
  for(i=1;i<=m.n;i++)
  {
    for(j=1;j<=m.n;j++)
    {
      scanf("%d", &x);
      printf("%d", x);
      Set(&m,i,j,x);
    }
  }
  printf("\n\n");
  Display(m);
  printf("%d\n", Get(m, 1, 3));
  return 0;
}

