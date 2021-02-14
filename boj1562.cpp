#include<stdio.h>
#include<string.h>
#define MOD 1000000000
#define flag ((1<<10)-1)

int n, ans = 0, dp[10][101][1<<10];

int f(int x, int len, int bit)
{
	if(x < 0 || x > 9) return 0;
	printf("%d %d\n", x, len);
	if(len == n){
		printf(">>>%d<<<\n", bit);
		if(bit == flag) return 1;
		else return 0;
	}
	if(dp[x][len][bit] != -1) return dp[x][len][bit];
	dp[x][len][bit] = 0;
	return dp[x][len][bit] += 
		(f(x-1, len+1, bit|(1<<x) + f(x+1, len+1, bit|(1<<x))) % MOD);
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for(int i = 1; i <= 9; i++){
		ans = (ans + f(i,0,0)) % MOD;
	}
	printf("%d", ans);
}
