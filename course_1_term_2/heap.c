#include <stdio.h>
#define N  1000

void norm(int* buf, int n, int i);	
void printBuf(int* buf, int n, int k);
int maxi(int n1, int n2, int* buf)
{
	if( buf[n1] > buf[n2]) return n1;
	return n2;
}
int readFile(char* name, int* buf, int len)
{
	FILE *f;
	int i = 0;
	f = fopen(name, "r");
	if ( f == NULL) return i;
	while(feof(f) == 0 && i < len) 
	{
		fscanf(f,"%d",buf+i);
		i++;
	}
	fclose(f);
	return i;
}
void printBuf(int* buf, int n, int k)
{
	int i;
	for ( i = 0; i < n; i++)
	{
		if(k == 1 ) printf("[%d]=%d,",i, buf[i]);
		if(k == 0 ) printf("%d,",buf[i]);
	}	printf("\b \n");
}
void flip(int* buf, int i, int j)
{
	int cur = buf[i];
	buf[i] = buf[j];
	buf[j] = cur;
}
void sort(int* buf, int n)
{
	int i;
	for ( i = n/2; i >= 0; i-- )
	{
		norm(buf,n,i);
	}
	for ( i = n-1; i > 0; i--)
	{
		flip(buf, 0, i);
		norm(buf, i,0);
	}
}
void norm(int* buf, int n, int i)
{
	int n1 = i*2+1, n2 = i*2+2;
	int im;
 	if( n1 < n )
 	{
 		if ( n2 < n ) 
 		{
 			im = maxi(n1, n2, buf);
 		}
 		else
 		{
 			im = n1;
 		}
 		im = maxi( i, im, buf);
 		if ( im != i) 
 		{
			flip(buf, i, im);
			norm(buf, n, im);
		}
 	} 
}
int main (int argc, char* argv[])
{
	int buf[N];
	int n = 0;
	char* name = "heap_input.txt";

	if( argc > 1)
	{
		name = argv[1];
	}
	n = readFile(name, buf, N);
	printf("n=%d\n", n);
	printBuf(buf,n,0);

	if( n > 0)
	{
		sort(buf, n);
		printBuf(buf,n,0);
	}

	return 0;
}
