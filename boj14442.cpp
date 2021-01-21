#include<stdio.h>
#include<queue>
#define IsSafe() (0<nx&&0<ny&&nx<=n&&ny<=m)
using namespace std;

int n, m, k, ar[1005][1005], vis[1005][1005][11];
int dy[4] = {1,0,-1,0}, dx[4] = {0,1,0,-1};

int f()
{
	queue<pair<pair<int,int>, pair<int,int> > >q;
	q.push({{1,1},{1,0}});
	vis[1][1][0] = 1;
	
	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second.first;
		int brk = q.front().second.second;
		q.pop();
		
		if(x == n && y == m) return cnt;
		
		for(int i = 0; i < 4; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(IsSafe()){
				if(vis[nx][ny][brk] == 0){
						if(ar[nx][ny] == 0){
						q.push({{nx,ny},{cnt+1,brk}});
						vis[nx][ny][brk] = 1;
					}
					if(ar[nx][ny] == 1 && brk < k){
						q.push({{nx,ny},{cnt+1,brk+1}});
						vis[nx][ny][brk+1] = 1;
					}
				}
			}
		}
	}
	return -1;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%1d", &ar[i][j]);
		}
	}
	
	printf("%d\n", f());
}
