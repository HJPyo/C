#include<stdio.h>
#define INF -999999999
#define IsSafe (x > 0 && y > 0 && x <= n && y <= m)

int n, m, ar[1001][1001], dp[3][1001][1001], vis[1001][1001];

int max(int x, int y){ return x > y ? x : y; }

int f(int dir, int x, int y)
{
	if(x == n && y == m) return ar[x][y];
	if(!IsSafe || vis[x][y]) return INF;
	if(dp[dir][x][y]) return dp[dir][x][y];
	vis[x][y] = 1;
	dp[dir][x][y] = ar[x][y];
	dp[dir][x][y] += max(max(f(0,x,y+1),f(1,x,y-1)),f(2,x+1,y));
	vis[x][y] = 0;
	return dp[dir][x][y];
}

int main()
{
	scanf("%d %d", &n, &m);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &ar[i][j]);
		}
	}
	
	printf("%d", f(0,1,1));
}
