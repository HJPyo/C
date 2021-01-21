#include<stdio.h>

int n, m, dp[1001][1001];

int f(int x, int y)
{
	if(y == m) return 1;
	if(x >= n-1) return 0;
	if(dp[x][y]) return dp[x][y];
	return dp[x][y] = (f(x+1,y) + f(x+2,y+1)) % 1000000003;
}

int main()
{
	scanf("%d %d", &n, &m);
	printf("%d", (f(0,0) * 2) % 1000000003);
}
