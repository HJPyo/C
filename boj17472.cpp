#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int n, m, ar[12][12], MAP[12][12], island = 0;
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
vector<pair<int,pair<int,int>>>v;

void dfs(int x, int y)
{
	ar[x][y] = 0;
	MAP[x][y] = island;
	
	for(int i = 0; i < 4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(ar[nx][ny] == 1){
			dfs(nx,ny);
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%1d", &ar[i][j]);
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(ar[i][j] == 1){
				island++;
				dfs(i,j);
			}
			printf("%d ", MAP[i][j]);
		}
		puts("");
	}
	
	
	
	for(int i = 0; i < v.size(); i++){
		int dis = v[i].first;
		int A = v[i].second.first;
		int B = v[i].second.second;
		printf(">>%d %d %d\n", A, B, dis);
	}
}
