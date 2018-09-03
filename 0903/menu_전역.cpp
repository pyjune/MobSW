#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int price[] = { 0, 1500, 2000, 2500, 3000 };
char menu[][21] = { "","Americano", "Latte", "Mocha", "Cappuccino" };
int menuN = sizeof(price) / sizeof(price[0]);
int bill[] = { 0, 10000, 5000, 1000 };

void menu_print(void);
int menu_select(void);
void menu_pay(int total);

int main(void)
{
	// 메뉴 출력
	menu_print();

	// 메뉴선택
	int total;
	total = menu_select();

	// 지불 및 거스름
	menu_pay(total);

	system("pause");
}

void menu_pay(int total)
{
	int pay = 0;
	int select;
	printf("1.10000원  2.5000원  3.1000원\n");
	do
	{
		printf("지불 금액을 선택하세요 : ");
		scanf("%d", &select);
		pay += bill[select];
		printf("금액 %d원, 지불액 %d원\n", total, pay);
		printf("\n");
	} while (pay < total);
	printf("거스름 %d원\n", pay - total);
}

int menu_select(void)
{
	int select = 1;
	int total = 0;
	do
	{
		printf("메뉴를 선택하세요(지불은 0) : ");
		scanf("%d", &select);
		if (select != 0)
		{
			total += price[select];
			printf("선택한 메뉴는 %s, 금액 %d\n", menu[select], total);
		}
		printf("\n");
	} while (select != 0);
	return total;
}

void menu_print(void)
{
	for (int i = 1; i < menuN; i++)
	{
		printf("%d.%-20s %5d\n", i, menu[i], price[i]);
	}
}
