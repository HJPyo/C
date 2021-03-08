#include<stdio.h>
#define MOD 1000000000

int n, k, dp[202][202];

int main()
{
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i <= n; i++){
		dp[1][i] = 1;
	}
	
	for(int i = 2; i <= k; i++){
		for(int j = 0; j <= n; j++){
			for(int k = 0; k <= j; k++){
				dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % MOD;
			}
		}
	}
	
	printf("%d", dp[k][n]);
}
