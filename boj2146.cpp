#include<stdio.h>
#include<queue>
#define MAX 101
#define IsSafe(x,y,n) (0 <= x && 0 <= y && x < n && y < n)
using namespace std;

struct xycol{
	int x, y, col, dis;
};
int n, ar[MAX][MAX], map[MAX][MAX], vis[MAX][MAX], cnt = 0;
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
queue<xycol>Q;

void island(int x, int y)
{
	map[x][y] = cnt;
	Q.push({x,y,cnt,0});
	
	for(int i = 0; i < 4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(IsSafe(nx,ny,n)){
			if(ar[nx][ny] == 1 && map[nx][ny] == 0){
				island(nx,ny);
			}
		}
	}
}

int main()
{
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &ar[i][j]);
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(ar[i][j] == 1 && map[i][j] == 0){
				cnt++;
				island(i,j);
			}
		}
	}
	
	while(!Q.empty()){
		int x = Q.front().x;
		int y = Q.front().y;
		int col = Q.front().col;
		int dis = Q.front().dis;
		Q.pop();
		
		if(map[x][y] != col && map[x][y] != 0){
			printf("%d", dis-1);
			break;
		}
		if(vis[x][y] == col) continue;
		vis[x][y] = col;
		
		for(int i = 0; i < 4; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(IsSafe(nx,ny,n)){
				if(map[nx][ny] != col && vis[nx][ny] != col){
					Q.push({nx,ny,col,dis+1});
				}
			}
		}
	}
}
