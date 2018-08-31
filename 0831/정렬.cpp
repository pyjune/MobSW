#include <stdio.h>
#include <stdlib.h>

// 오름차순 정렬
// 1, 2, 3, 4, 5, 7, 9
// 내림차순은 반대...

int main(void)
{
	int a[] = { 7, 2, 4, 5, 3, 9, 1 };
	int N = sizeof(a) / sizeof(a[0]);
	// 선택정렬 .. 내림차순
	for (int i = 0; i <= N - 2; i++) // 구간의 시작
	{
		int maxIdx = i;
		for (int j = i + 1; j < N; j++) // 최소값을 찾는 구간
		{
			if (a[maxIdx] < a[j])
				maxIdx = j;
		}
		int t = a[i]; // 구간의 맨 앞자리와 최소값 바꿈
		a[i] = a[maxIdx];
		a[maxIdx] = t;
	}
	for (int i = 0; i < N; i++)
		printf("%d ", a[i]);
	printf("\n");
	// 선택정렬 .. 오름차순
	for (int i = 0; i <= N - 2; i++) // 구간의 시작
	{
		int minIdx = i;
		for (int j = i + 1; j < N; j++) // 최소값을 찾는 구간
		{
			if (a[minIdx] > a[j])
				minIdx = j;
		}
		int t = a[i]; // 구간의 맨 앞자리와 최소값 바꿈
		a[i] = a[minIdx];
		a[minIdx] = t;
	}
	for (int i = 0; i < N; i++)
		printf("%d ", a[i]);
	printf("\n");
	// 버블 소트
	for (int i = N - 1; i >= 1; i--) // 구간의 끝
	{
		for (int j = 0; j < i; j++) // 비교 대상 중 왼쪽 인덱스
		{
			int t;
			if (a[j] > a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}

	system("pause");
}
