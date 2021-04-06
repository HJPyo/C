#include<stdio.h>

int n, m, k, dp[100005];

int main(){
	scanf("%d %d %d", &n, &m, &k);
	
	dp[0] = 1;
	
	for(int i = 1; i <= n; i++){
		dp[i] = dp[i/m] + dp[i/k];
		printf("%d\n", dp[i]);
	}
}
