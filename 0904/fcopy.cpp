#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE * fp1;
	FILE * fp2;
	if (argc < 3)
	{
		printf("매개변수 부족!\n");
		return 1;
	}
	fp1 = fopen(argv[1], "r");
	if (fp1 == NULL)
	{
		printf("%s 파일 열기 실패.\n", argv[1]);
		return 1;
	}
	fp2 = fopen(argv[2], "w");
	if (fp1 == NULL)
	{
		printf("%s 파일 열기 실패.\n", argv[2]);
		return 1;
	}
	int ch;
	while (1)
	{
		ch = fgetc(fp1);
		if (ch == EOF)
			break;
		fputc(ch, fp2);
	}
	fclose(fp1);
	fclose(fp2);
}
