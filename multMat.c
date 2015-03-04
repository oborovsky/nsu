#include <stdio.h>

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
			printf("%d ", *(A+i*M+j));
		}
		printf("\n");
	}
	printf("\n");
}
int main()
{
	int A[2][3]={{0,1,2},{1,0,-1}};
	int B[3][2]={{1,2},{3,4},{1,-1}};
	int C[2][2];
	printArr(&A[0][0], 2,3);
	printArr(&B[0][0], 3,2);
	multMat(&A[0][0],&B[0][0],&C[0][0],2,3,2);
	printArr(&C[0][0],2,2);
	return 0;
}