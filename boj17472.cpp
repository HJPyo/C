#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#define IsSafe(x,y,n,m) (0 <= x && 0 <= y && x < n && y < m)
using namespace std;

int n, m, ar[11][11], map[11][11], cnt = 0, ans = 0;
int boss[11];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
vector<pair<int,pair<int,int>>>V;
queue<pair<int,pair<int,int>>>Q;

void dfs(int x, int y)
{
	map[x][y] = cnt;
	Q.push({cnt,{x,y}});
	
	for(int i = 0; i < 4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(IsSafe(nx,ny,n,m)){
			if(ar[nx][ny] == 1 && map[nx][ny] == 0){
				dfs(nx,ny);
			}
		}
	}
	return;
}

void GetBridge(int x, int y, int col, int dir, int dis)
{
	if(IsSafe(x,y,n,m)){
		int nx = x+dx[dir];
		int ny = y+dy[dir];
		if(IsSafe(nx,ny,n,m)){
			if(map[nx][ny] == col) return;
			if(map[nx][ny] != col && map[nx][ny] != 0){
				if(dis >= 2) V.push_back({dis,{col,map[nx][ny]}});
				return;
			}
			GetBridge(nx,ny,col,dir,dis+1);
		}
	}
}

int Find(int x)
{
	if(boss[x] == x) return x;
	else return boss[x] = Find(boss[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	
	if(x < y) boss[y] = x;
	else boss[x] = y;
	return;
}

int main()
{
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &ar[i][j]);
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(ar[i][j] == 1 && map[i][j] == 0){
				cnt++;
				dfs(i,j);
			}
		}
	}
	
	while(!Q.empty()){
		int col = Q.front().first;
		int x = Q.front().second.first;
		int y = Q.front().second.second;
		Q.pop();
		
		for(int i = 0; i < 4; i++){
			GetBridge(x,y,col,i,0);
		}
	}
	
	sort(V.begin(),V.end());
	
	for(int i = 0; i < 10; i++){
		boss[i] = i;
	}
	
	for(int i = 0, flag = 0; flag < cnt-1; i++){
		if(i == V.size()){
			ans = -1;
			break;
		}
		
		int dis = V[i].first;
		int N1 = V[i].second.first;
		int N2 = V[i].second.second;
		
		if(Find(N1) != Find(N2)){
			Union(N1,N2);
			ans += dis;
			flag++;
		}
	}
	
	printf("%d", ans);
}
