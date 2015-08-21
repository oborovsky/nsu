#include <stdio.h>
#include "na5t1.h"

void mult( double A[][N], double B[][N], double C[][N]) 
{
	int i = 0, ia = 0, ib = 0;

	while ( (ia != N-1) || (ib != N-1) || (i != N) )
	{
		if (i == N)
		{
			i = 0; ib++;
		}
		if (ib == N)
		{
			ib = 0; ia++;
		}
		if (i == 0)
		{
			C[ia][ib] = A[ia][i] * B[i][ib];
		}
		else
		{
			C[ia][ib] += A[ia][i] * B[i][ib];

		}
		i++;
	}
}
void printMatrix(double A[][N])
{
	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			printf("%2.0f,", A[i][j]);
		}
		printf("\b \n");
	}
}
// int main(int argc, char const *argv[])
// {
// 	double A[N][N] = {{1,2},{3,4}};
// 	double B[N][N] = {{1,0},{2,5}};
// 	double C[N][N];

// 	mult(A, B, C);
// 	printMatrix(C);

// 	return 0;
// }