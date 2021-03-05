#include<stdio.h>
#include<string.h>

int n, m, ar[303][303], vis[303][303];
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};

void dfs(int x, int y)
{
	vis[x][y] = 1;
	for(int i = 0; i < 4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(ar[nx][ny]){
			dfs(nx,ny);
		}
	}
}

int main()
{
	memset(ar, -1, sizeof(ar));
	
	scanf("%d %d", &n, &m);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &ar[i][j]);
		}
	}
	
	int ans = 0;
	
	while(1)
	{
		memset(vis, 0, sizeof(vis));
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(ar[i][j]){
					cnt++;
					dfs(i,j);
				}
			}
		}
		if(cnt == 0){
			ans = 0;
			break;
		}
		else if(cnt == 1){
			break;
		}
		else{
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= m; j++){
					if(ar[i][j]) ar[i][j]--;
				}
			}
			ans++;
		}
	}
	
	printf("%d", ans);
}
