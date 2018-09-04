#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[21];
	int price;
}MenuType;

void printMenu(MenuType p[], int n);

int main(void)
{
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
