#include<stdio.h>
#include<algorithm>
using namespace std;

int n, ar[33][33], cnt = 0, dan[333];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};

int dfs(int x, int y)
{
	int dir = 0;
	ar[x][y] = 0;
	for(int i = 0; i < 4; i++){
		int nx = x+dx[i], ny = y+dy[i];
		if(!ar[nx][ny]) continue;
		if(nx<0||ny<0||nx==n||ny==n) continue;
		dir += dfs(nx,ny);
	}
	return 1 + dir;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%1d", &ar[i][j]);
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!ar[i][j]) continue;
			dan[cnt++] = dfs(i,j);
		}
	}
	
	sort(dan,dan+cnt);
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++)
	printf("%d\n", dan[i]);
}
