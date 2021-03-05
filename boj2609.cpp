#include<stdio.h>

int x, y, n, m;

int gcd(int x, int y)
{
	return y ? gcd(y, x%y) : x;
}

int main()
{
	scanf("%d %d", &x, &y);
	n = gcd(x, y);
	m = (x*y) / n;
	printf("%d\n%d", n, m);
}
