#include <stdio.h>
#define K 2

int main()
{
	int a[K][K] = {{1,2},{3,4}};

	int j,i;
	for(i=0; i < K; i++)
	{
		for(j=0 ; j < K; j++ )
		{
			printf("A[%d][%d] = %d at %p\n",i,j,a[i][j],&a[i][j] );
		}
	}
	return 0;
}