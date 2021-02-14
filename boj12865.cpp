#include<stdio.h>

int n, k, wei[105], val[105], dp[105][100005];

int max(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d %d", &wei[i], &val[i]);
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= k; j++){
			if(j < wei[i]) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j-wei[i]]+val[i], dp[i-1][j]);
		}
	}
	
	printf("%d", dp[n][k]);
}
