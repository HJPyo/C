#include<stdio.h>
#include<string.h>
#define LL long long

int tk, n, k;
LL int dp[33][33];

LL int f(int x, int y)
{
	if(dp[x][y] != -1) return dp[x][y];
	if(x > n) return 1;
	if(y > k) return 0;
	
	dp[x][y] = 0;
	
	for(int i = y; i <= k; i++){
		dp[x][y] += f(x+1,i+1);
	}
	
	return dp[x][y];
}

int main()
{
	scanf("%d", &tk);
	
	while(tk--){
		memset(dp, -1, sizeof(dp));
		scanf("%d %d", &n, &k);
		printf("%lld\n", f(1,1));
	}
}
