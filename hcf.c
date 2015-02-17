#include<stdio.h>
#include<stdlib.h>

int hcf(int n, int m)
{
	if( n == m ) return n;
	if( n > m ) return hcf(n-m, m);
	return hcf(n, m-n);
}

int main(void)
{
	int m,n;
	int nod;

	printf("input n,m > 0\n");
	scanf("%d%d",&n, &m);

	if( n == 0 || m == 0) {
		nod = abs(n)+abs(m);
	} else 
	{
		nod = hcf(abs(n), abs(m));
	}

	printf("(%d,%d)=%d\n", n, m, nod);
	return 0;
}
