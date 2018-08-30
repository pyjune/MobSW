#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n = 100;
	int sum = 0;
	int i;

	for (i = 1; i<=n; i++)
	{
		sum += i;
		printf("%d\n", sum);
		if (sum >= 100)
			break;
	}
	printf("%d\n", i);
	sum = 0;
	for (i = 1; i <= n, sum<100; i++)
	{
		sum += i;
		printf("%d\n", sum);
		
	}
	printf("%d\n", i - 1);

	int cnt = 0;
	sum = 0;
	for (i = 1; i <= n; i++)
	{
		sum += i;
		printf("%d\n", sum);
		if (sum >= 100 && cnt == 0)
			cnt = i;
	}
	printf("%d\n", cnt);


	system("pause");
}
