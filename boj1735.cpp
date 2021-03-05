#include<stdio.h>

int gcd(int x, int y)
{
	return y ? gcd(y, x%y) : x;
}

int main()
{
	int a,b,x,y;
	scanf("%d %d %d %d", &a, &x, &b, &y);
	
	int up = (a*y) + (b*x);
	int down = (x*y);
	int GCD = gcd(up,down);
	
	printf("%d %d", up/GCD, down/GCD);
}
