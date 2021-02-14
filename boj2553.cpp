#include<stdio.h>

int n, dp[20001];

int fac(int x)
{
	if(dp[x]) return dp[x];
	if(x <= 2) return x;
	return dp[x] = (x * fac(x-1)) % 100000;
}

int main()
{
	scanf("%d", &n);
	printf("%d", fac(n));
}
