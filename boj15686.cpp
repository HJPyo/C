#include<stdio.h>
#include<queue>
#include<algorithm>
#define INF 999999999
using namespace std;

int n, k, open = 0, ar[51][51], vis[51][51], sum, ans = INF;
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
queue<pair<pair<int,int>,int> >Q;

void close(int x, int y, int closed)
{
	if(closed == k){
		sum = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				vis[i][j] = 0;
				if(ar[i][j] == 2){
					Q.push({{i,j},0});
					vis[i][j] = 1;
				}
			}
		}
		while(!Q.empty()){
			int X = Q.front().first.first;
			int Y = Q.front().first.second;
			int dis = Q.front().second;
			Q.pop();
			if(ar[X][Y] == 1){
				sum += dis;
			}
			for(int i = 0; i < 4; i++){
				int nx = X+dx[i], ny = Y+dy[i];
				if(nx>=0 && ny>=0 && nx<n && ny<n){
					if(vis[nx][ny] == 0){
						vis[nx][ny] = 1;
						Q.push({{nx,ny},dis+1});
					}
				}
			}
		}
		ans = min(ans,sum);
	}
	else{
		for(int i = 0; i < n; i++){
			if(i < x) continue;
			for(int j = 0; j < n; j++){
				if(i == x && j < y) continue;
				if(ar[i][j] == 2){
					ar[i][j] = 0;
					close(i,j,closed-1);
					ar[i][j] = 2;
				}
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &ar[i][j]);
			if(ar[i][j] == 2){
				open++;
			}
		}
	}
	close(0,0,open);
	printf("%d", ans);
}
