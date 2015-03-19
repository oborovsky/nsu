#include <stdio.h>
#define K1 2
#define K2 2

int main()
{
	int A[K1][K2] = {{1,2},{3,4}};
	int *a = &A[0][0];
	int i;
	for( i=0; i< K1*K2; i++)
	{
		*(a +i) = i;
	}
	for( i=0; i< K1*K2; i++)
	{
		if( i%K2 == 0) printf("\n");
 		printf("a[%d][%d]=%d\n", i/K2, i%K2, *(a + i) );
	}
	// for(i=0; i < K; i++)
	// {
	// 	for(j=0 ; j < K; j++ )
	// 	{
	// 		printf("A[%d][%d] = %d at %p\n",i,j,a[i][j],&a[i][j] );
	// 	}
	// }
	return 0;
}