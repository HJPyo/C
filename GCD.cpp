#include<stdio.h>

int cat(int x, int y)
{
	while(y > 0)
	{
		int tmp = y;
		y = x%y;
		x = tmp;
	}
	return x;
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int GCD = cat(a,b);
	printf("%d %d", GCD, a*b/GCD);
}
