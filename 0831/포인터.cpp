#include <stdio.h>
#include <stdlib.h>
// n을 출력
void f1(int n);
void f2(int *p);

int main(void)
{
	int a = 10;

	printf("%p\n", &a);
	f1(a);
	f2(&a);
	printf("%d\n", a);
	system("pause");
}

void f2(int *p)
{
	*p = (*p) * 2; // p에 저장된 주소를 찾아가서 내용물을 2배로 만듦
}

void f1(int n)
{
	printf("%d\n", n);
}
