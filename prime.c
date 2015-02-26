#include <stdio.h>
#include <math.h>

#define N 10

int hcf(int n, int m)
{
	if( n == m ) return n;
	if( n > m ) return hcf(n-m, m);
	return hcf(n, m-n);
}

int isPrime(int n)
{
	int i;
	if(n == 1) 
	{
		return 0;	
	}
	if( n == 2) 
	{
		return 1;
	}
	for( i=2; i < sqrt(n)+1; i ++)
	{
        if( hcf(n,i) != 1) 
        {
        	return 0;
        }
	}
	return 1;
}
int main()
{
	int arr[N]= {2,3,5,7,11,13,17,19,21,29};
	int i;
	int a = -1;
	int b = 1;

	for(i = 0; i < N; i++)
	{
		if( isPrime(arr[i]) == 1) 
		{
			a = i;
		} 
		else 
		{
			b = 0;
		}
	}
	if( b == 1 ) 
	{
		printf("all num is prime\n");
	} 
	else 
	{
		if( a != -1) 
		{
			printf("There is prime arr[%d] = %d.\n", a, arr[a]);
		} 
		else
		{
			printf("There isn't prime\n");
		}
	}
	return 0;
}