//#include "test_reversestr.h"
#include <string.h>
#include "cu/cu.h"
#include <stdlib.h>
#include <stdio.h>
#include "../reversestr.h"	

TEST(emptyString)
{
	char *str= malloc(sizeof(char));
	*str = '\0';
	str = e2s(str);
	assertEquals(strcmp(str,""),0);
}

TEST(oneLetter)
{
	char *letter = "E";
	char *c = malloc(sizeof(char)*2);
	if ( c == NULL)
	{
		perror("no memory");
		exit(1);
	}
	*c = 'E';
	*(c+1) = '\0';
	c = e2s(c);
	assertEquals(strcmp(c, letter),0);
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
	str = e2s(str);
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
	str = e2s(str);
	assertEquals(strcmp(str,rphrase),0);

}
