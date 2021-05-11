#include<stdio.h>
#include<queue>
#define INF 999999999
using namespace std;

int n, m, ar[101][101], dist[101][101];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};

bool safe(int x, int y){
	return 0 < x && 0 < y && x <= n && y <= m;
}

int f(){
	priority_queue<pair<int,pair<int,int>>>pq;
	pq.push({0,{1,1}});
	
	while(!pq.empty()){
		int val = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		
		if(dist[x][y] <= val) continue;
		dist[x][y] = val;
		
		if(x == n && y == m) return val;
		
		for(int i = 0; i < 4; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(safe(nx,ny)){
				if(ar[nx][ny] == 1){
					pq.push({-val-1,{nx,ny}});
				}
				else{
					pq.push({-val,{nx,ny}});
				}
			}
		}
	}
}

int main(){
	scanf("%d %d", &m, &n);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%1d", &ar[i][j]);
			dist[i][j] = INF;
		}
	}
	
	printf("%d", f());
	
	return 0;
}
