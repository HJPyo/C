#include<stdio.h>
#include<queue>
#define IsSafe() (0<nx&&0<ny&&nx<=n&&ny<=m)
using namespace std;

int n, m, k, ar[1001][1001];
bool vis[1001][1001][11][2];
int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};

struct st{
	int x, y, cnt, brk;
};

void f()
{
	queue<st>q;
	q.push({1,1,1,0});
	vis[1][1][0][1] = true;
	
	while(!q.empty()){
		st cur = q.front();
		q.pop();
		
		if(cur.x == n && cur.y == m){
			printf("%d", cur.cnt);
			return;
		}
		
		for(int i = 0; i < 4; i++){
			int nx = cur.x+dx[i];
			int ny = cur.y+dy[i];
			int day = cur.cnt % 2;
			
			if(IsSafe() && !vis[nx][ny][cur.brk][day]){
				if(ar[nx][ny] == 0){
					q.push({nx,ny,cur.cnt+1,cur.brk});
					vis[nx][ny][cur.brk][day] = true;
				}
				if(ar[nx][ny] == 1 && cur.brk < k){
					if(day){
						q.push({nx,ny,cur.cnt+1,cur.brk+1});
						vis[nx][ny][cur.brk+1][day] = true;
					}
					else{
						q.push({cur.x,cur.y,cur.cnt+1,cur.brk});
						vis[cur.x][cur.y][cur.brk][day] = true;
					}
				}
			}
		}
	}
	printf("-1");
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%1d", &ar[i][j]);
		}
	}
	
	f();
}
