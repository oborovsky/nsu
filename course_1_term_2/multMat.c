#include <stdio.h>
#define K1 1
#define K2 3
#define K3 4
void multMat(int* A, int* B, int* C)
{
	int m =0;
	int j,i,k;

	for(i = 0; i < K1; i++)
	{
		for( j = 0; j < K3; j++)
		{
			for(k = 0; k < K2; k++)
			{
				m+=*(A+i*K2+k)*(*(B + k*K3+j));
			}
			*(C+i*K3+j) = m;
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
	int A[K1][K2];//={{0,1,2,-1},{1,0,-1,3},{1,-2,0,1}};
	int B[K2][K3];//={{1,2},{3,4},{1,-1},{0,1}};
	int C[K1][K3];
	int j,i;
	for( i=0; i < K1; i++)
	{
		for( j=0; j < K2; j++)
		{
			A[i][j] = i + j;
		}
	}
	for( i=0; i < K2; i++)
	{
		for( j=0; j < K3; j++)
		{
			B[i][j] = i + j;
		}
	}
	printArr(&A[0][0], K1,K2);
	//printArr(A,K1,K2);
	printf("\n\tX\n\n");
	printArr(&B[0][0], K2,K3);
	multMat(&A[0][0],&B[0][0],&C[0][0]);
	printf("\n\t=\n\n");
	printArr(&C[0][0],K1,K3);
	return 0;
}