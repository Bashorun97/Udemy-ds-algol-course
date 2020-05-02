#include <stdio.h>

long F[200];

long mfib(long n)
{
	if(n<=1)
	{

  		F[n]=n;
  		return n;
	}
	else
	{
		if(F[n-2]==-1)
			F[n-2]=mfib(n-2);
		if(F[n-1]==-1)
			F[n-1]=mfib(n-1);
	}
		return F[n-2]+F[n-1];
}


long main()
{
	long i;
	for(i=0;i<81;i++)
		F[i]=-1;

	printf("%ld \n", mfib(81));
	return 0;
}

