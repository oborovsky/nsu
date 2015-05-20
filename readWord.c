#include <stdio.h>
#include <stdlib.h>
int isAlpha (int c)
{
	if ( c == '\'') return 1;
	// if ( c == '-') return 1;
	if ( c == 46) return 1;
	if ( c == ' ') return 0;
	if ( c < 'A') return 0;
	if ( c > 'z') return 0;
	return 1;
}
char* readWord( FILE* f)
{
	int c, size = 0, count = 0, chunk = 10;
	char *tmp, *w = NULL;
	while ( (c = fgetc(f)) != EOF )
	{
		if ( !isAlpha(c))
		{ 
			if( w == NULL)
			{
				continue;
			}
			break;
		} 
		count++;
		if ( count > size )
		{
			tmp = realloc(w,sizeof(char)*(size + chunk));
			if ( tmp == NULL)
			{
				perror("no memory!");
				free(w);
				return NULL;
			}
			w =  tmp; size += chunk;
		}
		w[count - 1] = c;
	}
	return w;
}
int main( int argc , char* argv[])
{
	char* name = "word_input.txt";
	char* word = NULL;
	FILE* f;
	if ( argc > 1)
	{
		name = argv[1];
	}
	f = fopen(name, "r");
	if (f == NULL)
	{
		perror("cann't open file\n");
		return 1;
	}
	while(!feof(f))
	{
		word = readWord(f);
		if( word == NULL) break;
		printf("%s\n",word );
		free(word);
		word = NULL;
	}
	return 0;
}