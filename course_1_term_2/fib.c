#include <stdio.h>
int fib(int n)
{
	int x=0, y=1, t=0;
	for(; n > 0; n--)
	{
		// printf(" %d,", x);
		t=x+y;
		x=y;
		y=t;
	}
	return x;
}
int fibR(int n, int key)
{
	int f;
	if(n == 1)
	{
		if( key == 1 ) printf("0,");
		return 0;
	}
	if(n == 2)
	{
		fibR(1, key );
		if ( key == 1 ) printf("1,");
		return 1;
	}
	f = fibR(n-1, key) + fibR(n-2, 0);
	if( key == 1) printf("%d,", f);
	return f;
}

// int main(void) {
// 	int n = 0;
// 	printf("input n: ");
// 	scanf("%d", &n);
// <<<<<<< HEAD
// 	fib(n);
// 	printf("\n");
// 	// for(i=0;i < n; i++)
// 	// {
// 	// 	printf("%d, ",fibR(i));
// 	// }
// 	// printf("\n");
// 	//fibR2(n, 1);
// 	//printf("\n");
// =======
// 	fibR(n,1);
// 	printf("\n");
// 	//printf("%d\n", fib(n));
// >>>>>>> origin/master
// 	return 0;
// }

// // int fibR2(int n, int key)
// // {
// // 	int f;
// // 	if( n == 0 ) 
// // 	{
// // 		if( key == 1) 
// // 		{
// // 			printf("0,");
// // 		}
// // 		return 0;
// // 	}
// // 	if ( n == 1) 
// // 	{
// // 		if ( key == 1 )
// // 		{
// // 			printf("0,1,");
// // 		}
// // 		return 1;
// // 	}
// // 	f= fibR2( n - 1, 1) + fibR2( n - 2, 0);
// // 	printf("%d,",f );
// // 	return f;

// // }
