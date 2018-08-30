#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a = 10;
	//int i;

	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", i);
	}

	int i = 0;
	while (i < 3)
	{
		printf("while %d\n", i);
		i++;
	}

	for (int i = 1; i <= 3; i++)
	{
		printf("%d\n", i);
	}


	while (a < 10)
	{
		a *= 2;
	}
	printf("%d\n", a);

	a = 10;
	do
	{
		a *= 2;
	} while (a < 10);
	printf("%d\n", a);

	system("pause");
}
