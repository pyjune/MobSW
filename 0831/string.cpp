#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// <string.h> -> strlen()
// 문자열의 길이를 알아내는 함수(널문자를 제외한 글자 수 반환)
int strLen(const char p[]);
void strCpy(char dest[], const char src[]);

int main(void)
{
	char str[] = "apple";
	char str2[20];

	int len = strLen(str);
	printf("%d\n", len);
	printf("%d\n", strlen(str));
	strCpy(str2, str);
	printf("%s\n", str2);
	system("pause");
}

void strCpy(char dest[], const char src[])
{
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int strLen(const char p[])
{
	int i = 0;
	while (p[i] != '\0')
	{
		i++;
	}
	return i;
}
