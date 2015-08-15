/**
Шифрование и разшифровка текста (состоющего из прописных латинчких букв и цифр)
методом сдвига букв и цифр. Если величина сдвига 2, то A->C, a 2->4 etc. 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int findIndex(char ch, const char *abc)
{
	unsigned int i = 0;
	for (; i < strlen(abc); i++)
	{
		if (*(abc + i) == ch ) return i;
	}
	return -1;
}
char code(char ch, int step)
{
	const char *abc = "0123456789abcdefghijklmnopqrstuvwxyz";
	int len = strlen(abc);
	int i = findIndex(ch, abc);

	if ( i == -1 ) return -1;

	i = (i + step) % len;

	return *(abc + i);
}
char decode(char ch, int step)
{
	const char *abc = "0123456789abcdefghijklmnopqrstuvwxyz";
	int len = strlen(abc);
	int i = findIndex(ch, abc);

	if ( i == -1 ) return -1;

	i = (i - step >= 0) ? i - step : len + i - step;

	return *(abc + i);	
}
char* catString(const char *str1, const char *str2) 
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int len = len1 + len2;

	char *ns = (char*)malloc(sizeof(char) * len + 2);
	if ( ns == NULL) 
	{
		perror("can't alloc memory in function catSring\n");
		exit(1);
	}
	strncpy(ns, str1, len);
	*(ns + len1) = '.';
	strncpy(ns + len1 + 1, str2, len + 2 - len1 - 1);
	*(ns + len + 1) = '\0';
	return ns;
}

void codingFile(const char* file, int step) 
{
	FILE *fi = fopen(file, "r");

	char * codingFile = catString(file, "coding");
	FILE *fo = fopen(codingFile, "w");
	free(codingFile);

	if ( fi == NULL || fo == NULL) 
	{
		perror("one of files can't open\n");
	}

	char ch = fgetc(fi);
	while (ch != EOF)
	{
		ch = code(ch, step);
		if (ch == -1) {
			perror("code is wrong\n");
		}
		if (fputc(ch, fo) == EOF) 
		{
			perror("fputc has an error\n");
			exit(1);
		}
		ch = fgetc(fi);
	}
	fclose(fi);
	fclose(fo);
}
void decodingFile(const char* file, int step)
{
	char *codingFile = catString(file, "coding");
	FILE *fi = fopen(codingFile, "r");

	char *decodingFile = catString(file, "decoding");
	FILE *fo = fopen(codingFile, "w");
	free(codingFile);
	free(decodingFile);

	if ( fi == NULL || fo == NULL) 
	{
		perror("one of files can't open\n");
	}

	char ch = fgetc(fi);
	while (ch != EOF)
	{
		ch = decode(ch, step);
		if (ch == -1) {
			perror("code is wrong\n");
		}
		if (fputc(ch, fo) == EOF) 
		{
			perror("fputc has an error\n");
			exit(1);
		}
		ch = fgetc(fi);
	}
	fclose(fi);
	fclose(fo);
}
// int main(int argc, char const *argv[])
// {
// 	codingFile("itext", 1);
// 	return 0;
// }