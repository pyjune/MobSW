#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[21];
	int price;
}MenuType;

union stu {
	int num;
	char ch[4];
};

void printMenu(MenuType p[], int n);

int main(void)
{
	union stu s;
	s.num = 0x12345678;
	// 포인터를 사용해 바이트 단위로 분리..
	int num = 0x12345678;
	char *p = (char*)&num;
	printf("%x\n", p[0]);
	printf("%x\n", p[1]); // *(p+1)
	printf("%x\n", p[2]);
	printf("%x\n", p[3]);
	printf("\n");
	// union을 사용해 바이트 단위로 분리..
	printf("%x\n", s.ch[0]);
	printf("%x\n", s.ch[1]);
	printf("%x\n", s.ch[2]);
	printf("%x\n", s.ch[3]);

	MenuType menu[] = {
		{},
		{"Americano", 1500},
		{"Latte", 2000},
		{"Mocha", 2500}
	};
	printMenu(menu, sizeof(menu) / sizeof(menu[0]));

	for (int i = 1; i < sizeof(menu) / sizeof(menu[0]); i++)
	{
		printf("%d.%-20s %5d\n", i, menu[i].name, menu[i].price);
	}
	system("pause");
}

void printMenu(MenuType p[], int n)
{
	for (int i = 1; i < n; i++)
	{
		printf("%d.%-20s %5d\n", i, p[i].name, p[i].price);
	}
}
