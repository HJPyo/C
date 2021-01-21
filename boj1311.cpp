#include<stdio.h>
#define INF 999999999

int n, ar[21][21], dp[21][2222222];

int min(int x, int y)
{
	return x < y ? x : y;
}

int f(int x, int y)
{
	if(x > n) return 0;
	if(dp[x][y]) return dp[x][y];
	
	dp[x][y] = INF;
	
	for(int i = 0; i < n; i++){
		if(y & (1<<i)) continue;
		dp[x][y] = min(dp[x][y], ar[x][i+1] + f(x+1, y | (1<<i)));
	}
	return dp[x][y];
}

int main()
{
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &ar[i][j]);
		}
	}
	
	printf("%d", f(1,0));
}
