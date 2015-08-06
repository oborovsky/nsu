#include <stdio.h>
#include <stdlib.h>

void getString (char *str, int i)
{	int b = getchar();
	if( b !='\n')
	{
		str[i++] = b;
		getString(str, i);
	}
	else 
	{
		str[i] ='\0';
	}
}
char* e2s(char *str) 
{
	static int i = 0;
	char c = str[i];
	if(c != '\0') 
	{
		i++;
		e2s(str);
		str[i++] = c;
	}
	else
	{
		i = 0;
	}
	return str;
}
/*
int main()
{	
	char *str = malloc(sizeof(char) * 1000);
	if (str == NULL) 
	{
		perror("no memory");
		return 1;
	}
	getString(str,0);
	str = e2s(str);
	puts(str);
	putchar('\n');
	return 0;
}
*/