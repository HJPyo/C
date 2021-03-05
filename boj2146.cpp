#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define INF 999999999
using namespace std;

struct xycol{ int x, y, col, dis; };
int n, ar[105][105], vis[105][105];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
int cnt = 0, ans = INF;
queue<xycol>Q;

void dfs(int x, int y, int col)
{
	ar[x][y] = col;
	vis[x][y] = 1;
	Q.push({x,y,col,0});
	
	for(int i = 0; i < 4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(ar[nx][ny] == INF){
			dfs(nx,ny,col);
		}
	}
}

int main()
{
	memset(ar,-1,sizeof(ar));
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &ar[i][j]);
			if(ar[i][j] == 1) ar[i][j] = INF;
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(ar[i][j] == INF){
				dfs(i,j,++cnt);
			}
			printf("%d ", ar[i][j]);
		}
		puts("");
	}
	
	while(!Q.empty()){
		int x = Q.front().x;
		int y = Q.front().y;
		int col = Q.front().col;
		int dis = Q.front().dis;
		int now_col = ar[x][y];
		Q.pop();
		
		
		printf(">>%d %d %d %d\n", x, y, col, dis);
		
		if(now_col != 0 && now_col != col){
			ans = min(ans,dis);
			continue;
		}
		
		for(int i = 0; i < 4; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(ar[nx][ny] != -1 && ar[nx][ny] != col && !vis[nx][ny]){
				Q.push({nx,ny,col,dis+1});
				vis[nx][ny] = 1;
			}
		}
	}
	
	printf("%d", ans-1);
}
