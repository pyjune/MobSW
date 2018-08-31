#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a[] = { 7, 2, 3, 9, 5, 4, 2, 9 };

	// 최대값은?
	int maxV = a[0];
	for (int i = 1; i < sizeof(a) / sizeof(a[0]); i++)
	{
		if (maxV < a[i])
			maxV = a[i];
	}
	printf("%d\n", maxV);

	// 최소값은?
	int minV = a[0]; 
	for (int i = 1; i < sizeof(a) / sizeof(a[0]); i++)
	{
		if (minV > a[i])
			minV = a[i];
	}
	printf("%d\n", maxV);

	// 최대값이 들어있는 인덱스 출력.
	// 최대 값이 여러개인 경우 가장 큰 값 출력.
	int maxIdx = 0;
	for (int i = 1; i < sizeof(a) / sizeof(a[0]); i++)
	{
		if (a[maxIdx] <= a[i])
			maxIdx = i;
	}
	printf("%d\n", maxIdx);

	system("pause");
}
