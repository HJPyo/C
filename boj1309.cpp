#include<stdio.h>

int n, dp[100001][2];

int f(int x, int y)
{
	if(x >= n) return 0;
	if(dp[x][y]) return dp[x][y];
	return dp[x][y] = (1 + f(x+1,(y+1)%2)*2 + f(x+2, y)) % 9901;
}

int main()
{
	scanf("%d", &n);
	printf("%d", (f(0,0)*2+1) % 9901);
}
