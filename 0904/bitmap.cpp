#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int bmpSize;
	short rdy1;
	short rdy2;
	int offset;
	int headerSize;
	int horizontal;
	int vertical;
}BMPType;

int main(void)
{
	BMPType bmpheader;
	char str[3] = { 0 };

	FILE *fp = fopen("a.bmp", "rb");
	if (fp == NULL)
	{
		return 1;
	}
	fread(str, 1, 2, fp);
	printf("%s\n", str);
	fread(&bmpheader, sizeof(bmpheader), 1, fp);
	fclose(fp);
	printf("파일크기 : %d\n", bmpheader.bmpSize);
	printf("가로 세로 : %d x %d\n", bmpheader.horizontal, bmpheader.vertical);
	system("pause");
}
