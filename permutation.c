#include <stdio.h>
#define N 4
void printSet(int* end, int n);
void f(int* start, int* end, int n)
{
	int i;
	if( n == N) 
	{
		printSet(end,n);
		return;
	}
	for( i = 0; i < N; i++)
	{
		if( start[i] == 1) 
		{
			start[i] = 0;
			end[n] = i+1;

			f(start, end, n + 1);

			start[i] = 1;
			end[n] = 0;
		}
	}
}
void printSet(int* end , int n)
{
	int i;
	for( i = 0; i < n; i++)
	{
		printf("%d,",end[i] );
	}
	printf("\n");
}
int main()
{
	int start[N];
	int end[N];
	int i;
	for (i = 0; i < N; i++)
	{
		start[i] = 1;
		end[i] = 0;
	}

	f(start, end, 0);
}