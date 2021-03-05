#include<stdio.h>
#include<string.h>
#define MOD 1000000000
#define LL long long

int n;
LL int dp[15][105][1<<11];

LL int f(int num, int len, int bit)
{
	if(len == n) return bit == (1<<10)-1 ? 1 : 0;
	if(dp[num][len][bit] != -1) return dp[num][len][bit];
	
	dp[num][len][bit] = 0;
	
	if(num == 0){
		dp[num][len][bit] = (dp[num][len][bit]) + f(num+1, len+1, bit|(1<<num+1)) % MOD;
	}
	else if(num == 9){
		dp[num][len][bit] = (dp[num][len][bit]) + f(num-1, len+1, bit|(1<<num-1)) % MOD;
	}
	else{
		dp[num][len][bit] = (dp[num][len][bit]) + f(num+1, len+1, bit|(1<<num+1)) % MOD;
		dp[num][len][bit] = (dp[num][len][bit]) + f(num-1, len+1, bit|(1<<num-1)) % MOD;
	}
	
	return dp[num][len][bit];
}

int main()
{
	scanf("%d", &n);
	
	LL int ans = 0;
	
	for(int i = 1; i < 10; i++){
		memset(dp,-1,sizeof(dp));
		ans = (ans + f(i,1,1<<i)) % MOD;
	}
	
	printf("%lld", ans);
	
	return 0;
}
