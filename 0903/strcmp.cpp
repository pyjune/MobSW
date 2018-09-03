#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strCmp(const char str1[], const char str2[]);

int main(void)
{
	char str1[] = "apple";
	char str2[100];
	char *p;

	printf("%d\n", strcmp("abc", "bcd"));
	printf("%d\n", strcmp("bcd", "abc"));
	printf("%d\n", strcmp("abc", "abc"));

	printf("%d\n", strCmp("abc", "bcd"));
	printf("%d\n", strCmp("bcd", "abc"));
	printf("%d\n", strCmp("abc", "abc"));

	p = strcpy(str2, str1);
	printf("%s %s\n", str2, p);


	system("pause");
}

int strCmp(const char str1[], const char str2[])
{
	int i = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] != str2[i])
			break;
		i++;
	}
	if (str1[i] == str2[i])
		return 0;
	else if (str1[i] < str2[i])
		return -1;
	else
		return 1;
}
