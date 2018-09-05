#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int g;
// function.c의 전역변수 gf가 static인 경우 사용불가
// extern int gf; 


int main(void)
{
	int a = 10;
	f1(a);
	f2();
	printf("%d\n", g);
	
	system("pause");
}

