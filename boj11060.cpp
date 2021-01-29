#include<stdio.h>
#define INF 1999999999

int n, ar[1001], dp[1001];

int min(int x, int y){ return x < y ? x : y; }

int f(int x)
{
	printf("\n[%d] ", x);
	if(ar[x] == 0) return INF;
	if(x > n) return 0;
	if(dp[x]) return dp[x];
	dp[x] = INF;
	for(int i = 1; i <= ar[x]; i++)
		dp[x] = min(dp[x],1+f(x+i));
	return dp[x];
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &ar[i]);
	printf("%d", f(1));
}
