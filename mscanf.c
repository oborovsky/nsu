#include <stdio.h>
#define K 100
int isNumber(int n)
{
	//printf("in isNumber =%c,%d\n",n,n);
	int N[10] = {'0','1','2','3','4','5','6','7','8','9'}; 
	int key = -1;
	int i = 0;
	for(; i < 10; i++ )
	{	//printf("n=%d, Ni=%d\n",n,N[i] );
		if( n == N[i])
		{
			key = 1; 
			break;
		}
	}
	//printf("key= %d\n",key );
	return key;
}
int mscanf(int* num)
{
	int n = getchar();
	int key = 1;
	int i=0;
	*num = 0;
	for( ; n != '\n'; )
	{
		//printf("read%c\n",n);
		if( isNumber(n) == 1) 
		{
			*num = (*num)*10 + (n - '0');
			key = 2;
			i++;
			//printf("in isNumber num = %d\n",*num );
		}
		else 
		{
			if (key == 2)
			{
				break;
			}
		}
		n = getchar();
	}
	return i;
}
int main()
{
	int num;
	int i = mscanf(&num);
	if( i > 0) printf("%d\n", num );
	else 
	{
		//printf("There is no number.\n");
	}
	return 0;
}