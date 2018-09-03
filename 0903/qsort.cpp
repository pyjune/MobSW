#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void * x, const void * y);
int compare2(const void * x, const void * y);

int main(void)
{
	int a[] = { 7, 2, 5, 3, 4, 9, 1, 8, 6 };
	char str[][10] = { "banana", "apple" };

	qsort(a, sizeof(a)/sizeof(a[0]), sizeof(a[0]), compare);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	qsort(str, sizeof(str) / sizeof(str[0]), 
		sizeof(str[0])/sizeof(str[0][0]), compare2);
	printf("%s %s\n", str[0], str[1]);
	system("pause");
}

int compare2(const void * x, const void * y)
{
	return strcmp((char*)x, (char*)y);
}
int compare(const void * x, const void* y)
{
	if (*(int *)x < *(int*)y)
		return -1;
	else if (*(int*)x > *(int*)y)
		return 1;
	else
		return 0;
}
