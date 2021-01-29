#include<stdio.h>
#include<queue>
#include<vector>
#define IsSafe (nx >= 0 && ny >= 0 && nx < n && ny < n)
using namespace std;

int k, n;
int dx[8] = {1,2,2,1,-1,-2,-2,-1}, dy[8] = {2,1,-1,-2,-2,-1,1,2};

int main()
{
	scanf("%d", &k);
	while(k--){
		scanf("%d", &n);
		vector<vector<int> >vis(n+1, vector<int>(n+1,0));
		queue<pair<int,int> >q;
		int sx, sy, fx, fy;
		
		scanf("%d %d", &sx, &sy);
		scanf("%d %d", &fx, &fy);
		
		q.push({sx,sy});
		vis[sx][sy] = 1;
		while(!q.empty()){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			
			if(x == fx && y == fy){
				printf("%d\n", vis[x][y]-1);
				break;
			}
			
			for(int i = 0; i < 8; i++){
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(IsSafe){
					if(vis[nx][ny] == 0){
						vis[nx][ny] = vis[x][y]+1;
						q.push({nx,ny});
					}
				}
			}
		}
	}
}
