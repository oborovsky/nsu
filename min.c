#include <stdio.h>
int min2(int a, int b)
{
	if( a >= b ) return b;
	return a;
}
int min( int* arr, int N)
{
	if ( N == 1) return arr[0];
	return min2(arr[N-1], min(arr, N-1));
}
int main ()
{
	int arr[10] = {13,24,35,4,2,6,7,1,9,10};
	printf("min is %d\n", min(arr,5));
	return 0;
}