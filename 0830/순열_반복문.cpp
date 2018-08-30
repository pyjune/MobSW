#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// 순열
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			if (i != j)
			{
				for (int k = 1; k <= 3; k++)
				{
					if ((k != i) && (k != j))
					{
						printf("%d %d %d\n", i, j, k);
					}
				}
			}
		}
	}
	printf("\n");
	// 중복 순열
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			for (int k = 1; k <= 3; k++)
			{
				printf("%d %d %d\n", i, j, k);
			}
		}
	}

	system("pause");
}
