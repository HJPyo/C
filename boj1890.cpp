#include<stdio.h>

int n, ar[121][121] = {}, dp[121][121] = {};

int main()
{
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &ar[i][j]);
		}
	}
	
	dp[1][1] = 1;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(dp[i][j] == 0 || (i == n && j == n)) continue;
			int dis = ar[i][j];
			if(dis + i <= n) dp[i+dis][j] += dp[i][j];
			if(dis + j <= n) dp[i][j+dis] += dp[i][j];
		}
	}
	
	printf("%d", dp[n][n]);
}
