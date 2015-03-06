#include <stdio.h>
#include <string.h>
#define K 100

int isPalindrom(char* str)
{
	int n = strlen(str);
	char* e = str+n-1;
	char* s = str;

	while( s<=e && *s++==*e--);
	return s-e > 0? 1:0;
}

char* mget(char* s)
{
	int i;
	int k = getchar();
	if( k == EOF) return NULL;

	for(i=0; i < K-1 && k != '\n' && k != EOF;i++)
	{
		s[i] = k;
		k = getchar();
		if( k == EOF && !feof(stdin) ) return NULL;
	}
	s[i] = '\0';
	return s;
}
int main()
{
	char str[K];
	printf("input a string:");
	if(mget(str))
	{
		//printf("%s\n", str);
		if( isPalindrom(str) ) 
		{
			printf("\"%s\" is a palindrom\n",str);
		}
		else 
		{
			printf("\"%s\" isn't a palindrom\n",str);
		}
	}
	return 0;
}