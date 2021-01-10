#include<stdio.h>

int n, m[100001], dp[100001];

int Max(int x, int y){ return x > y ? x : y; }

int f(int x, int y)
{
	if(n == x) return 0;
	dp[x] = Max(dp[x-1] + m[x], m[x]);
	return f(x+1, Max(y, dp[x]));
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &m[i]);
	}
	dp[0] = m[0];
	
	printf("%d", f(1,dp[0]));
}
