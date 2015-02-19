#include <stdio.h>
void fib(int n)
{
	int x=0, y=1, t=0;
	for(; n > 0; n--)
	{
		printf(" %d,", x);
		t=x+y;
		x=y;
		y=t;
	}
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
int main(void) {
	int n = 0;
	printf("input n: ");
	scanf("%d", &n);
	fibR(n,1);
	printf("\n");
	//printf("%d\n", fib(n));
	return 0;
}
