//#include "test_reversestr.h"
#include <string.h>
#include "cu/cu.h"
#include <stdlib.h>
#include <stdio.h>	
#include "../reversestr.h"

TEST(emptyString)
{	char *str= malloc(sizeof(char));
	*str = '\0';
	printf("str=%s, and empty string =%s\n", str,"");	
	str = e2s(str);
	assertEquals(strcmp(str,""),0);
}

TEST(oneLetter)
{
	char* c = malloc(sizeof(char)*2);
	if ( c == NULL)
	{
		perror("no memory");
		exit(1);
	}
	*c = 'E';
	*(c+1) = '\0';
	assertEquals(e2s(c),c);
}

TEST(word)
{
	char *word = "word";
	char *rword = "drow";

	char *str = malloc(sizeof(char)*20);
	if (str == NULL) 
	{
		perror("no memory");
		exit(1);
	}
	str = strcpy(str, word);
	printf("in word first str=%s :",str );
	str = e2s(str);
	printf("in word str=%s\n",str );
	assertEquals(strcmp(str, rword),0);
}

TEST(phrase)
{
	char *str = malloc(sizeof(char)*200);
	char *phrase = "on pa";
	char *rphrase = "ap no";

	if (str == NULL) 
	{
		perror("no memory");
		exit(1);
	}
	str = strcpy(str, phrase);
	printf("in phrase first str=%s :",str );
	str = e2s(str);
	printf("in phrase str=%s\n",str );
	assertEquals(strcmp(str,rphrase),0);

}
