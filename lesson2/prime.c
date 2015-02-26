#include <stdio.h>
#define N 5

int hcf(int n, int m)
{
	if( n == m ) return n;
	if( n > m ) return hcf(n-m, m);
	return hcf(n, m-n);
}

int isPrime(int n)
{
	int nod = 1;
	int i;
	if(n == 1) 
	{
		
	}
	for( i=2; i < n; i ++)
	{
        if( hcf(n,i) != 1) 
        {
        	return 0
        }
	}
	return 1;
}
int main()
{
	int arr[N]= {1,2,3,4,5};
	int i, j, cur;
	int a = 0;
	int b = 1;

	for(i = 0; i < N; i++)
	{
		if( isPrime(arr[i]) == 1) 
		{
			a = 1;
		} 
		else 
		{
			b = 0;
		}
	}
}