#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp = fopen("a.bin", "wb");
	if (fp == NULL)
	{
		return 1;
	}

	int a = 0x12345678;
	int b = 0x11223344;
	double f = 3.14159265;
	double g;

	fwrite(&a, 4, 1, fp);
	fwrite(&b, 4, 1, fp);
	fwrite(&f, 8, 1, fp);
	fclose(fp);

	fp = fopen("a.bin", "rb");
	if (fp == NULL)
	{
		return 1;
	}
	fread(&b, 4, 1, fp);
	fread(&a, 4, 1, fp);
	fread(&g, 8, 1, fp);
	printf("%x %x %f\n", a, b, g);
	fclose(fp);
	system("pause");
}
