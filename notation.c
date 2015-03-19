#include<stdio.h>

int checkBase(int bas) 
{
	if ( bas > 1 && bas < 11) return 1;
	printf("the base must be one of [2..10]\n" );
	return 0;
}
int toDecimal(int num, int ibas )
{
	int mod;
	int onum = 0;
	int iibas = 1;

	while( num > 0 )
	{
		mod = num % 10;
		onum += (mod * iibas);
		iibas *= ibas;
		num /=10; 
		//printf("mod:%d, onum:%d, iibas:%d\n", mod, onum, iibas);
	}
	return onum;
}

int main()
{
	int ibas;
	int num;
	int onum;

	printf("input the base of notation:");
	scanf("%d", &ibas);
	//printf("\n"); 

	if( checkBase(ibas) != 1 ) return 1;

	printf("input a number:");
	scanf("%d", &num);
	if (ibas != 10 )
	{
		onum = toDecimal(num,ibas);
	} 
	else
	{
		onum = num;
	} 
	printf(" %d\n", onum);
	return 0;
}