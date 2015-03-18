#include <stdio.h>

void f( int m) 
{
	if( m == 3 ) return;
	printf("%d",m);
	f(m+1);
	f(m+1);
	printf("%d",m );
}
int main()
{
	f(0);
	printf("\n");
}