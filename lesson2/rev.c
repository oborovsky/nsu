#include <stdio.h>

void e2s ()
{
	int b = getchar();
	if( b !='\n')
	{
		e2s();
		putchar(b);
	}
}

int main()
{
	e2s();
	putchar('\n');
	return 0;
}
