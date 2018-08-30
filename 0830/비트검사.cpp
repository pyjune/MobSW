#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a = 10;

	for (int i = 31; i >= 0; i--)
	{
		printf("%d", (a&(1 << i)) >> i);
	}
	printf("\n");
	for (int i = 31; i >= 0; i--)
	{
		if ((a&(1 << i)) == 0)
			printf("0");
		else
			printf("1");
	}

	printf("\n");
	a &= ~(1 << 3);

	for (int i = 31; i >= 0; i--)
	{
		if ((a&(1 << i)) == 0)
			printf("0");
		else
			printf("1");
	}
	printf("\n");
	system("pause");
}
