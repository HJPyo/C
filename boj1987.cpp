#include<stdio.h>
#define ABC 65

int n, m, ar[21][21], vis[31];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};

int max(int x, int y)
{
	return x > y ? x : y;
}

int f(int x, int y)
{
	vis[ar[x][y]-ABC] = 1;
	int deep = 0;
	for(int i = 0; i < 4; i++){
		int nx = x+dx[i], ny = y+dy[i];
		if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if(vis[ar[nx][ny]-ABC] == 1) continue;
		deep = max(deep,f(nx,ny));
	}
	vis[ar[x][y]-ABC] = 0;
	return 1+deep;
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		char tmp[31];
		scanf("%s", &tmp);
		for(int j = 0; j < m; j++){
			ar[i][j] = tmp[j];
		}
	}
	
	printf("%d", f(0,0));
}
