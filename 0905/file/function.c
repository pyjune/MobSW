#include <stdio.h>
#include "main.h"
//extern int g;
static int gf = 10; // function.c에서만 사용
// static을 붙여 function.c에서만 사용..
// static이 붙은 함수는 .h에 넣지 않음
static void f2(void);

void f1(int n)
{
	f2();
	printf("%d\n", n);
	g = 20;
}

static void f2(void)
{
	printf("function.c\n");
}
