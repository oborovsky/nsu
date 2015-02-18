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
int fibR(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fibR(n-1) + fibR(n-2);
}
int main(void) {
	int n = 0;
	int i;
	printf("input n>0: ");
	scanf("%d", &n);
	fib(n);
	printf("\n");
	for(i=0;i < n; i++)
	{
		printf("%d, ",fibR(i));
	}
	printf("\n");
	return 0;
}
