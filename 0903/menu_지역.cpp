#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



void menu_print(int n, char m[][21], int p[]);
int menu_select(int n, char m[][21], int p[], int *t);
void menu_pay(int total, int p[]);

int main(void)
{
	int price[] = { 0, 1500, 2000, 2500, 3000 };
	char menu[][21] = { "","Americano", "Latte", "Mocha", "Cappuccino" };
	int menuN = sizeof(price) / sizeof(price[0]);
	int bill[] = { 0, 10000, 5000, 1000 };

	// 메뉴 출력
	menu_print(menuN, menu, price);

	// 메뉴선택
	int total = 0;
	int cnt = menu_select(menuN, menu, price, &total);
	printf("선택한 음료는 %d개 입니다.\n", cnt);
	// 지불 및 거스름
	menu_pay(total, bill);

	system("pause");
}

void menu_pay(int total, int p[])
{
	int pay = 0;
	int select;
	printf("1.10000원  2.5000원  3.1000원\n");
	do
	{
		printf("지불 금액을 선택하세요 : ");
		scanf("%d", &select);
		pay += p[select];
		printf("금액 %d원, 지불액 %d원\n", total, pay);
		printf("\n");
	} while (pay < total);
	printf("거스름 %d원\n", pay - total);
}

int menu_select(int n, char m[][21], int p[], int *t)
{
	int select = 1;
	int total = 0;
	int cnt = 0;
	do
	{
		printf("메뉴를 선택하세요(지불은 0) : ");
		scanf("%d", &select);
		if (select != 0)
		{
			total += p[select];

			printf("선택한 메뉴는 %s, 금액 %d\n", m[select], total);
			printf("\n");
			cnt++;
		}
	} while (select != 0);
	*t = total;
	return cnt;
}

void menu_print(int n, char m[][21], int p[])
{
	for (int i = 1; i < n; i++)
	{
		printf("%d.%-20s %5d\n", i, m[i], p[i]);
	}
}
