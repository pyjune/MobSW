#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE * fp;
	FILE * fp2;
	fp = fopen("a.txt", "r");
	if (fp == NULL)
	{
		printf("파일 오픈 실패\n");
		system("pause");
		return 1;
	}
	fp2 = fopen("b.txt", "w");
	if (fp2 == NULL)
	{
		printf("파일 오픈 실패\n");
		system("pause");
		return 1;
	}
	int lang, math, eng;
	//fscanf(fp, "%d %d %d", &lang, &math, &eng);
	//printf("%d %d %d\n", lang, math, eng);

	int ch;
	while (1)
	{
		ch = fgetc(fp);
		if (ch == EOF)
			break;
		putchar(ch);
		fputc(ch, fp2);
	}

	fclose(fp);
	fclose(fp2);
	system("pause");
}
