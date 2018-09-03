#include <stdio.h>
#include <string.h>

int main()
{
 	char str[][20] = { "abc", "def", "ghi" };
	int N = sizeof(str) / sizeof(str[0]);
	char *p[5] ; // VS2017은 const 추가

	p[0] = "abc";
	p[1] = "apple";
	strcpy(str[0], "Abc");
	printf("%s\n", p[0]);
	printf("%s\n", p[1]);
	//str[0][0] = 'A';
	printf("%s\n", str[0]);
}
