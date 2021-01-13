#include<stdio.h>

int n;

int gcd(int x, int y)
{
	return y ? gcd(y, x%y) : x;
}

int main()
{
	scanf("%d", &n);
	while(n--){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", a*b/gcd(a,b));
	}
}
