#include <stdio.h>

int main(void)
{
	int a = 10;
	int b = 10;
	
	if (a == b)
	{
		printf("a와 b가 같음\n");
	}

	if (a > b)
	{
		printf("a가 더 큼\n");
	}
	else if (a < b)
	{
		printf("b가 더 큼\n");
	}
	else // if (a==b)
	{
		printf("a와 b가 같음\n");
	}

	if (a > b)
	{
		printf("a가 더 큼\n");
	}
	else // a<b와 a==b 경우 포함
	{
		//printf("a가 더 크지 않음\n"); // a<b와 a==b인 경우의 구분은?
		if (a < b)
		{
			printf("b가 더 큼\n");
		}
		else
		{
			printf("a와 b가 같음\n");
		}
	}

	return 0;
}
