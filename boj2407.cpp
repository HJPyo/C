#include<stdio.h>

__int64 n, m, dp[101];

__int64 fac(__int64 x)
{
	if(x < 3) return x;
	if(dp[x]) return dp[x];
	return dp[x] = x * fac(x-1);
}

int main()
{
	scanf("%I64d %I64d", &n, &m);
	printf("%I64d", fac(n));
	/*
	long long int top = fac(n);
	long long int down = fac(m) * fac(n-m);
	printf("%lld", top/down);
	*/
}
