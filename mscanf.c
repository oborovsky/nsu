#include <stdio.h>
#define K 100
int isNumber(int n)
{
	int nul = '0';
	n -= '0';
	if( n >= 0 && n < 10) return 1;
	return 0;
}
int mscanf(int* num)
{
	int n = getchar();
	int i=0;
	*num = 0;
	for( ; n != '\n'|| i == 0; )
	{
		//printf("read%c\n",n);
		if( isNumber(n) == 1) 
		{
			*num = (*num)*10 + (n - '0');
			i++;
			//printf("in isNumber num = %d\n",*num );
		}
		else 
		{
			if (i > 0)
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
	int num = 0;
	int i = mscanf(&num);
	if( i > 0) printf("%d\n", num );
	return 0;
	
}