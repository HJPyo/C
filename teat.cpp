#include<stdio.h>
int main()
{
	char ar[1<<20];
	FILE *fp = fopen("test.cpp", "r");
	fread(ar, sizeof(ar), 1, fp);
	printf("%s", ar);
	fclose(fp);
}
