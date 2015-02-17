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
int main(void) {
	int n = 0;
	printf("input n>0: ");
	scanf("%d", &n);
	fib(n);
	printf("\n");
	return 0;
}
