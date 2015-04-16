#include <stdio.h>
#define N 1000

int readFile(char* name, int* buf, int len)
{
	FILE *f;
	int i = 0;
	f = fopen(name, "r");
	if ( f == NULL) return i;
	while(feof(f) == 0 && i < len) 
	{
		fscanf(f,"%d",buf+i);
		//printf("[%d]=%d,",i, buf[i]);
		i++;
	}
	//printf("\n");
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
	}
	printf("\b \n");

}
void flip(int* buf, int i, int j)
{
	int cur = buf[i];
	buf[i] = buf[j];
	buf[j] = cur;
}
void qsort(int* buf, int l, int r)
{

	int mid = (buf[l] + buf[r])/2;
	int i = l, j = r;
	printf("out: mid=%d, (l=%d, r=%d)\n", mid, l,r );
	if ( l >= r) return;

	while( i+1 < j )
	{
		while( (buf[i] < mid) && (i+1<j) ) { i++; };
		while( (buf[j] >= mid) && (j>i+1) ) { j--; };
		printf("i=%d,j=%d\n", i,j);
		if (*(buf+i) > *(buf+j) )
		{
			flip(buf,i,j);
			printBuf(buf,r,0);
		}
	}
	printf("out: mid=%d, (l=%d, i=%d), (j=%d, r=%d)\n", mid, l,i,j, r );
	qsort(buf, l, i);
	qsort(buf, j, r);
}

int main (int argc, char* argv[])
{
	int buf[N];
	int n = 0;
	char* name = "input.txt";

	if( argc > 1)
	{
		name = argv[1];
	}
	n = readFile(name, buf, N);
	printf("n=%d\n", n);
	printBuf(buf,n,0);

	if( n > 0)
	{
		qsort(buf, 0, n-1);
		printBuf(buf,n,0);
	}

	return 0;
}
