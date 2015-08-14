#include <stdio.h>
#define K 100

char* mstrcat(char* dest, char* append)
{
	int i=0;
	char* d = dest;
	while(*dest++);
	dest--;
	while(*append && (dest-d) < K-1)
	{
		*dest++ = *append++;
	}
	*dest = '\0';
	return d;
}

int main()
{
	char dest[K] ;//= "dest ";
	char append[K];// = "+append";
	printf("input dest string:" );
	scanf("%s",dest);
	printf("input append string:");
	scanf("%s",append);
	printf("%s\n", mstrcat(dest, append) );

	return 0;
}