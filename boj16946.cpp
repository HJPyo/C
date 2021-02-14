#include<stdio.h>
#define MAX 1005

int n, m, ar[MAX][MAX], size[MAX][MAX], val[MAX<<1], cnt = 0;
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};

int dfs(int x, int y, int col)
{
	size[x][y] = col;
	int tmp = 1;
	for(int i = 0; i < 4; i++){
		int nx = x+dx[i], ny = y+dy[i];
		if((nx>0 && ny>0 && nx<=n && ny<=m) && size[nx][ny] == 0 && ar[nx][ny] == 0){
			tmp += dfs(nx,ny,col);
		}
	}
	return tmp;
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%1d", &ar[i][j]);
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(ar[i][j] == 0 && size[i][j] == 0){
				cnt++;
				val[cnt] = dfs(i, j, cnt);
			}
		}
	}
	/*
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			printf("%d", size[i][j]);
		}
		puts("");
	}
	*/
	for(int x = 1; x <= n; x++){
		for(int y = 1; y <= m; y++){
			if(ar[x][y] == 0){
				printf("0");
			}
			else{
				int now = 1, vis[MAX<<1] = {};
				//printf("(%d, %d)\n", x, y);
				for(int i = 0; i < 4; i++){
					int nx = x+dx[i], ny = y+dy[i];
					int col = size[nx][ny];
					if(nx>0 && ny>0 && nx<=n && ny<=m && !vis[col]){
						//printf("cur : %d val : %d\n", i, val[col]);
						vis[col] = 1;
						now += val[col];
					}
				}
				//printf(">>>%d<<<\n", now);
				printf("%d", now%10);
			}
		}
		puts("");
	}
}
