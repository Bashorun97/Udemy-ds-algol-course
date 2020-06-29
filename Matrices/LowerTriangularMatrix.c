#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
  int *A;
  int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
  //for row-major
  //if (i>=j)
  //m->A[i*(i-1)/2+j-1]=x;

  // for column-major
  if (i>=j)
    m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j]=x;
}

int Get(struct Matrix m, int i, int j)
{
  if(i>=j)
    //return m.A[i*(i-1)/2+j-1];
    return m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j];
  else
    return 0;
}

void Display(struct Matrix m)
{
  int i, j;
  for(i=1;i<=m.n;i++)
  {
    for(j=1;j<=m.n;j++)
    {
      if (i>=j)
        printf("%d ", m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j]);
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

  printf("Enter Dimension: ");
  scanf("%d", &m.n);
  m.A=(int *)malloc(m.n*(m.n-1)/2*sizeof(int));

  printf("Enter all elements: \n");
  for(i=1;i<=m.n;i++)
  {
    for(j=1;j<=m.n;j++)
    {
      scanf("%d",&x);
      Set(&m,i,j,x);
    }
  }
  printf("\n\n");
  Display(m);
  //printf("%d",Get(m,3,2));
  return 0;
}

