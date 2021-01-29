#include<stdio.h>

int n, m, ar[1001][1001], dp[1001][1001];

int max(int x, int y){ return x > y ? x : y; }

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &ar[i][j]);
			dp[i][j] += ar[i][j] + max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1]));
		}
	}
	printf("%d", dp[n][m]);
}
