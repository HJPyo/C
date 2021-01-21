#include<stdio.h>
#define INF 9999999

int n, m, ar[16][16], dp[16][1<<16];

int min(int x, int y)
{
	return x < y ? x : y;
}

int f(int x, int y)
{
	if(y == m) return 0;
	if(dp[x][y]) return dp[x][y];
	
	dp[x][y] = INF;
	
	for(int i = 0; i < n; i++){
		if(y & (1<<i) || ar[x][i] == 0) continue;
		dp[x][y] = min(dp[x][y], ar[x][i] + f(i,y | (1<<i)));
	}
	
	return dp[x][y];
}

int main()
{
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &ar[i][j]);
		}
	}
	
	printf("%d", f(0,0));
}
