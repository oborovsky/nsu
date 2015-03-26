#include <stdio.h>
#define M 1000

int readFile(char* name, int* buf, int len)
{
	FILE *f;
	int i = 0;
	f = fopen(name, "r");
	if ( f == NULL) return i;
	while(feof(f) == 0 && i < len) 
	{
		fscanf(f,"%d",buf+i);
		printf("[%d]=%d,",i, buf[i]);
		i++;
	}
	printf("\n");
	return i;
}
int bsearch(int elem, int* buf, int len)
{
	int left = 0, right = len-1;
	int m = len/2;
	//printf("l:%d, r:%d, m:%d\n",left, right, m );
	while(right - left > 0)
	{
		if( buf[m] < elem ) 
		{ 
			left = m + 1;
			//printf("l:%d [l]=%d\n",left, buf[left] );
			if( buf[m+1] == elem ) return m+1;
		}
		else
		{
			right = m;
			//printf("r:%d [r]=%d\n",right, buf[right] );
			if( buf[m] == elem ) return m;
		}
		m = (left + right) / 2;
	}
	return -1;
}

int main()
{
	int buf[M];
	int len = M;
	int elem;
	char* name = "input.txt";
	int pos = -1;
	len = readFile(name, buf, len);
	if( len == 0 )
	{
		printf(" file is empty or error.\n");
		return 0;
	}
	printf("search:");
	scanf("%d", &elem);

	pos = bsearch(elem, buf, len);
	if( pos != -1) 
	{
		printf("%d\n", pos);
		return 0;
	}
	printf("there is no such element\n");
	return 0;
}
