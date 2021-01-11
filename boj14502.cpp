#include<stdio.h>
#include<queue>
#define IsSafe (0<=nx&&0<=ny&&nx<n&&ny<m)
using namespace std;

int n, m, ar[9][9], lab[9][9], safe = -3, ans = -1;
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
struct dir{ int x, y; };

void reset()
{
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			lab[i][j] = ar[i][j];
		}
	}
}

void wall(int x, int y, int cnt)
{
	if(cnt == 3){
		reset();
		queue<dir>q;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(lab[i][j] == 2) q.push((dir){i,j});
			}
		}
		
		int INF = 0;
		
		while(!q.empty()){
			dir now = q.front();
			q.pop();
			for(int i = 0; i < 4; i++){
				int nx = now.x+dx[i], ny = now.y+dy[i];
				if(IsSafe && lab[nx][ny] == 0){
					q.push((dir){nx,ny});
					lab[nx][ny] = 2;
					INF++;
				}
			}
		}
		
		if(safe - INF > ans) ans = safe - INF;
		return;
	}
	
	for(int i = 0; i < n; i++){
		if(i < x) continue;
		for(int j = 0; j < m; j++){
			if(j < y && i <= x) continue;
			if(ar[i][j] == 0){
				ar[i][j] = 1;
				wall(i,j,cnt+1);
				ar[i][j] = 0;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &ar[i][j]);
			if(ar[i][j] == 0) safe++;
		}
	}
	
	wall(0,0,0);
	printf("%d", ans);
}
