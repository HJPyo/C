#include<stdio.h>
#define IsSafe (0<nx&&0<ny&&nx<=n&&ny<=n)

int n, ar[505][505], dp[505][505], ans = -1;
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};

int Max(int x, int y)
{
	return x > y ? x : y;
}

int f(int x, int y)
{
	if(dp[x][y]) return dp[x][y];
	
	dp[x][y] = 1;
	
	for(int i = 0; i < 4; i++){
		int nx = x+dx[i], ny = y+dy[i];
		if(ar[nx][ny] > ar[x][y] && IsSafe){
			dp[x][y] = Max(f(nx,ny)+1,dp[x][y]);
		}
	}
	return dp[x][y];
}

int main()
{
	scanf("%d", &n);
	
	for(int i = 1 ; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &ar[i][j]);
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1 ; j <= n; j++){
			ans = Max(ans, f(i,j));
		}
	}
	
	printf("%d", ans);
}
