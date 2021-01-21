#include<stdio.h>

int n, k, dp[5001][2501];

int f(int x, int y)
{
	if(y < 0 || y > (n>>1)) return 0;
	if(x == 0) return y == 0 ? 1 : 0;
	if(dp[x][y] != -1) return dp[x][y];
	
	dp[x][y] = 0;
	
	return dp[x][y] = (f(x-1,y+1) + f(x-1,y-1)) % 1000000007;
}

int main()
{
	for(int i = 0; i < 5001; i++) for(int j = 0; j < 2501; j++) dp[i][j] = -1;
	
	scanf("%d", &k);
	
	while(k--){
		scanf("%d", &n);
		printf("%d\n", f(n,0));
	}
}
