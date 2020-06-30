#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
  int *A;
  int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
  if (i-j==1)
    m->A[i-2]=x;
  if (i-j==0)
    m->A[m->n-1+i-1]=x;
  if (i-j==-1)
    m->A[2*m->n-1+i-1]=x;
}

int Get(struct Matrix m, int i,int j)
{
  if (i-j==1)
    return m.A[i-2];
  if (i-j==0)
    return m.A[m.n-1+i-1];
  if (i-j==-1)
    return m.A[2*m.n-1+i-1];
  //return 0;
}

void Display(struct Matrix m)
{
  int i,j;
  for (i=1;i<=m.n;i++)
  {
    for (j=1;j<=m.n;j++)
    {
      if (i-j==1)
        printf("%d ", m.A[i-2]);
      else if (i-j==0)
        printf("%d ", m.A[m.n-1+i-1]);
      else if (i-j==-1)
        printf("%d ", m.A[2*m.n-1+i-1]);
      else
        printf("0 ");
    }
    printf("\n");
  }
}

int ListArray(struct Matrix m)
{
  int i,length;
  length = 3*m.n-2;
  for(i=0;i<length;i++)
    printf("%d ", m.A[i]);
  return 0;
}

int main()
{
  struct Matrix m;
  int i,j,x;
  
  printf("Enter Dimension: ");
  scanf("%d", &m.n);
  m.A = (int *)malloc(3*m.n-2*sizeof(int)); 
  printf("Enter Elements: \n");
  for (i=1;i<=m.n;i++)
  {
    for (j=1;j<=m.n;j++)
    {
      scanf("%d", &x);
      Set(&m,i,j,x);
    }
  }
  printf("\n\n");
  Display(m);
  ListArray(m);
  printf("\nItem at position M[%d,%d]: %d\n",2,1,Get(m,2,1));
  return 0;
}

