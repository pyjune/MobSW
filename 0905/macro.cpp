#include <stdio.h>
#include <stdlib.h>
#define MUL(a, b)	((a)*(b))
#define SUM(a, b)	((a)+(b))
#define VER 7
//#define USEMACRO
int main(void)
{
#if VER>=6
	printf("version 6이상..\n");
#endif // #if VER>=6

#ifdef USEMACRO
	printf("%d\n", MUL(3+1, 4)); // 3+1*4
	printf("%d\n", SUM(3, 3) * 2); //3+3 *2
	printf("%s %s\n", __DATE__, __TIME__);
	printf("%s\n", __FILE__);
#else
	printf("No macro...\n");
#endif // #ifdef USEMACRO

#ifndef USEMACRO
	printf("No macro...\n");
#endif // #ifndef USEMACRO
	system("pause");
}
