#define _CRT_SECURE_NO_WARNINGS
/*
	90점 이상 A
	80점 이상 B
	70점 이상 C
	60점 이상 D
	60점 미만 F
	점수를 입력하면 등급을 출력...
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int score;
	char grade;
	printf("점수 : ");
	scanf("%d", &score);

	if (score >= 90)
	{
		grade = 'A';
	}
	else if (score >= 80)
	{
		grade = 'B';
	}
	else if (score >= 70)
	{
		grade = 'C';
	}
	else if (score >= 60)
	{
		grade = 'D';
	}
	else
	{
		grade = 'F';
	}

	printf("%c\n", grade);

	score /= 10;
	switch (score)
	{
	case 10: // 100점
		//break; // 100점과 90점 같은 등급
	case 9:
		grade = 'A';
		break;
	case 8:
		grade = 'B';
		break;
	case 7:
		grade = 'C';
		break;
	case 6:
		grade = 'D';
		break;
	default:
		grade = 'F';
		break;
	}

	printf("%c\n", grade);

	system("pause");
}
