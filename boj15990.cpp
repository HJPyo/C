#include<stdio.h>
#define MOD 1000000009

int n, k, dp[100001][4];

int f(int x, int before)
{
	if(x < 0) return 0;
	if(x == 0) return 1;
	if(dp[x][before]) return dp[x][before];
	for(int i = 1; i <= 3; i++){
		if(before == i) continue;
		dp[x][before] = (dp[x][before] + f(x-i,i)) % MOD;
	}
	return dp[x][before] % MOD;
}

int main()
{
	scanf("%d", &k);
	while(k--){
		scanf("%d", &n);
		printf("%d\n", f(n, 0));
	}
}
