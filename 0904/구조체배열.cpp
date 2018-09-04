#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	int id;
	char name[20];
	double grade;
};

void printS(struct student s[], int size);

struct student addS(void);

int main(void)
{
	struct student s[] = {
		{ 315, "홍길동", 2.4 },
		{ 316, "이순신", 3.7 },
		{ 317, "세종대왕", 4.4 } };
	struct student s4;

	printf("%d %s %.1f\n", s[0].id, s[0].name, s[0].grade);
	for(int i=0; i<sizeof(s)/sizeof(s[0]); i++)
		printf("%d %s %.1f\n", s[i].id, s[i].name, s[i].grade);

	printS(s, sizeof(s) / sizeof(s[0]));
	system("pause");
}

void printS(struct student s[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d %s %.1f\n", s[i].id, s[i].name, s[i].grade);
		//printf("%d %s %.1f\n", (s+i)->id, (s+i)->name, (s+i)->grade);
	}
}
