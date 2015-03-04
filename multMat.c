#include <stdio.h>
#define K1 3
#define K2 4
#define K3 2
void multMat(int* A, int* B, int* C, int N1, int N2, int N3)
{
	int m =0;
	int j,i,k;

	for(i = 0; i < N1; i++)
	{
		for( j = 0; j < N3; j++)
		{
			for(k = 0; k < N2; k++)
			{
				m+=*(A+i*N2+k)*(*(B + k*N3+j));
			}
			*(C+i*N3+j) = m;
			m = 0;
		}
	}
}
void printArr(int* A, int N, int M)
{
	int i,j;
	for( i=0; i < N; i++)
	{
		for(j=0; j < M; j++)
		{
			printf("%4.1d ", *(A+i*M+j));
		}
		printf("\n");
	}
	printf("\n");
}
int main()
{
	int A[K1][K2]={{0,1,2,-1},{1,0,-1,3},{1,-2,0,1}};
	int B[K2][K3]={{1,2},{3,4},{1,-1},{0,1}};
	int C[K1][K3];
	printArr(&A[0][0], K1,K2);
	printArr(&B[0][0], K2,K3);
	multMat(&A[0][0],&B[0][0],&C[0][0],K1,K2,K3);
	printArr(&C[0][0],K1,K3);
	return 0;
}