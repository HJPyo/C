#include<stdio.h>
#define INF 999999999

int n, ar[11][11], dp[11][1<<11];

int min(int x, int y)
{
	return x < y ? x : y;
}

int f(int x, int y)
{
	if(x == 0 && y == (1<<n) - 1) return 0;
	if(dp[x][y]) return dp[x][y];
	
	dp[x][y] = INF;
	
	for(int i = 0; i < n; i++){
		int dist = ar[x][i];
		if(dist != 0 && !(y & 1<<i)){
			dp[x][y] = min(dp[x][y],f(i,y|1<<i)+dist);
		}
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
