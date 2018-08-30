#include <stdio.h>
#include <stdlib.h>

void dec2bin(int n);

int main(void)
{
	int a = 10;

  dec2bin(a);


	printf("\n");
	system("pause");
}


void dec2bin(int n)
{
	for (int i = 31; i >= 0; i--)
	{
		printf("%d", (n&(1 << i)) >> i);
	}
	printf("\n");
}

/*
void dec2bin(int n)
{
	for (int i = 31; i >= 0; i--)
	{
		if ((n&(1 << i)) == 0)
			printf("0");
		else
			printf("1");
	}
}
*/
