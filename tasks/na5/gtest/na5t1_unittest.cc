#include "gtest/gtest.h"
#include "na5t1.h"

double A[N][N] = {{0,0,0}, {0,0,0}, {0,0,0}};
double B[N][N] = {{1,1,1}, {1,1,1}, {1,1,1}};
double E[N][N] = {{1,0,0},{0,1,0},{0,0,1}};

TEST(DISABLED_multTest, multOnZeroMatrix)
{
	
	double C[N][N];
	mult(A, B, C);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			EXPECT_EQ(A[i][j], C[i][j]);
		}

}

TEST(DISABLED_multTest, multOnOneMatrix)
{
	double C[N][N];
	mult(B,E,C);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			EXPECT_EQ(B[i][j], C[i][j]);
		}
}

TEST(DISABLED_multTest, multOnOneMatrix2)
{
	double C[N][N];
	mult(E,E,C);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			EXPECT_EQ(E[i][j], C[i][j]);
		}
}
TEST(multTest, multOnAMatrix)
{
	double C[N][N];
	double A[N][N] = {{1,2,3},{4,5,0},{0,2,1}};
	double B[N][N] = {{0,1,1},{1,2,0},{1,0,1}};
	double R[N][N] = {{5,5,4},{5,14,4},{3,4,1}};

	mult(A,B,C);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			EXPECT_EQ(R[i][j], C[i][j])<<"i:"<<i<<"j:"<<j<<std::endl;
		}
}
