#include<stdio.h>
#include<string.h>

int n, cnt1 = 0, cnt2 = 0, vis[101][101];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
char ar[101][101];

int IsSafe(int x, int y)
{
	return 0 <= x && 0 <= y && x < n && y < n;
}

void for_normal(int x, int y, char col)
{
	vis[x][y] = col;
	
	for(int i = 0; i < 4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(IsSafe(nx,ny)){
			if(ar[nx][ny] == col && vis[nx][ny] == 0){
				for_normal(nx, ny, col);
			}
		}
	}
}

void for_disabled(int x, int y, char col)
{
	vis[x][y] = col;
	
	for(int i = 0; i < 4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(IsSafe(nx,ny)){
			if(ar[nx][ny] == col && vis[nx][ny] == 0){
				for_disabled(nx, ny, col);
			}
		}
	}
}

int main()
{
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%s", ar[i]);
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(vis[i][j] == 0){
				for_normal(i, j, ar[i][j]);
				cnt1++;
			}
			if(ar[i][j] == 'R') ar[i][j] = 'G';
		}
	}
	
	memset(vis, 0, sizeof(vis));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(vis[i][j] == 0){
				for_disabled(i, j, ar[i][j]);
				cnt2++;
			}
		}
	}
	
	printf("%d %d", cnt1, cnt2);
}
