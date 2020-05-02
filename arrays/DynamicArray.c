#include <stdio.h>

int main ()
{
	int i;
	int *p;
	p = (int *)malloc(5*sizeof(int));
	p[0]=1;
	p[1]=2;
	p[2]=3;
	p[3]=4;
	p[4]=5;

	printf("\n");
	for(i=0;i<5;i++)
	{
		printf("%d ", p[i]);
	}
	return 0;
}

