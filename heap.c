#include <stdio.h>
#define N  1000

void norm(int* buf, int n, int i);	
void printBuf(int* buf, int n, int k);

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
	//printBuf(buf, n, 0);
	for ( i = n-1; i > 0; i--)
	{
		flip(buf, 0, i);
		//printBuf(buf, n, 0);
		norm(buf, i,0);
		//printBuf(buf, n, 0);
	}
}
void norm(int* buf, int n, int i)
{
	// int k[] = {i*2+1,i*2+2};
	// int j,s;

	// if ( k[0] > n) return; 
	// for(s=1; s >= 0; s-- ) 
	// {
	// 	j = k[s];
 
	// 	if ( j < n && buf[i] < buf[j] ) 
	// 	{
	// 		flip(buf, i, j);
	// 		norm(buf, n, j);
	// 	}
 //    }
	int n1 = i*2+1, n2 = i*2+2;
 	if( n1 < n )
 	{
 		if ( n2 < n ) 
 		{
 			if( buf[n1] > buf[n2] )
 			{
 				if( buf[i] < buf[n1] ) 
 				{	
	 				flip(buf, i, n1);
	 				norm(buf, n, n1);
	 			}
 			}
 			else
 			{
 				if ( buf[i] < buf[n2] )
 				{
 					flip(buf, i, n2);
 					norm(buf, n, n2);
 				}
 			}
 		}
 		else
 		{
 			if( buf[i] < buf[n1] ) 
 				{	
	 				flip(buf, i, n1);
	 				norm(buf, n, n1);
	 			}
 		}
 	} 
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
		sort(buf, n);
		printBuf(buf,n,0);
	}

	return 0;
}
