#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE * fp;

	fp = fopen("a.txt", "r");
	if (fp == NULL)
	{
		printf("파일 오픈 실패\n");
		system("pause");
		return 1;
	}

	int lang, math, eng;
	fscanf(fp, "%d %d %d", &lang, &math, &eng);
	printf("%d %d %d\n", lang, math, eng);

	fclose(fp);
	system("pause");
}
