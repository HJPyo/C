#include<stdio.h>

int n, m, ar[505][505], dp[505][505];
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

int f(int x, int y)
{
	if(x == n && y == m) return 1;
	if(dp[x][y] != -1) return dp[x][y];
	
	dp[x][y] = 0;
	for(int i = 0; i < 4; i++){
		int nx = x+dx[i], ny = y+dy[i];
		if(ar[nx][ny] >= ar[x][y] || ar[nx][ny] == 0) continue;
		dp[x][y] += f(nx,ny);
	}
	
	return dp[x][y];
}

int main()
{
	scanf("%d %d", &n, &m);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j] = -1;
			scanf("%d", &ar[i][j]);
		}
	}
	
	printf("%d", f(1,1));
}
