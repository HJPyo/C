#include<stdio.h>
#include<string.h>

int n, k, dp[1000001];

int fibo(int x)
{
	if(dp[x] != -1) return dp[x];
	
	dp[x] = 0;
	return dp[x] = (fibo(x-1) + fibo(x-2)) % k;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	dp[1] = dp[2] = 1;
	
	scanf("%d %d", &n, &k);
	fibo(n);
	
	for(int i = 0; i <= n; i++){
		printf(">>%d\n", dp[i]);
	}
}
