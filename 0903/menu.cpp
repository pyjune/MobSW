#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	int price[] = { 0, 1500, 2000, 2500, 3000};
	char menu[][21] = { "","Americano", "Latte", "Mocha", "Cappuccino" };
	int menuN = sizeof(price) / sizeof(price[0]);
	int bill[] = { 0, 10000, 5000, 1000 };
	// 메뉴 출력
	for (int i = 1; i < menuN; i++)
	{
		printf("%d.%-20s %5d\n", i, menu[i], price[i]);
	}

	// 메뉴선택
	int total = 0;
	int select = 1;
	
	do
	{
		printf("메뉴를 선택하세요(지불은 0) : ");
		scanf("%d", &select);
		total += price[select];
		printf("선택한 메뉴는 %s, 금액 %d\n", menu[select], total);
		printf("\n");
	} while (select != 0);


	// 지불 및 거스름
	int pay = 0;
	printf("1.10000원  2.5000원  3.1000원\n");
	do
	{
		scanf("%d", &select);
		pay += bill[select];
		printf("금액 %d원, 지불액 %d원\n", total, pay);
	} while (pay < total);
	printf("거스름 %d원\n", pay - total);
	system("pause");
}
