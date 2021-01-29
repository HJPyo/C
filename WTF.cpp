#include<stdio.h>
char ar[149] = {};
int main()
{
	FILE *fp = fopen("WTF.cpp", "r");
	fread(ar, sizeof(ar), 1, fp);
	printf("%s", ar);
	fclose(fp);
}
