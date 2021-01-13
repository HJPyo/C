#include<stdio.h>
#define INF 1999999999

int n, m, memo[101], cost[101], dp[101][10001], ans = INF;

int Max(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &memo[i]);
	for(int i = 0; i < n; i++)
		scanf("%d", &cost[i]);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 10001; j++){
			if(j >= cost[i]){
				dp[i+1][j] = Max(dp[i][j], dp[i][j-cost[i]] + memo[i]);
			}
			else{
				dp[i+1][j] = dp[i][j];
			}
		}
	}
	
	for(int i = 0; i < 10001; i++){
		if(dp[n][i] >= m && ans > i)
		ans = i;
	}
	
	printf("%d", ans);
}
