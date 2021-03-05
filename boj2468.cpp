#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

int n, ar[101][101], minH = 999, maxH = -999, ans = 1, tmp[101][101];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};

void dfs(int x, int y)
{
	tmp[x][y] = 0;
	for(int i = 0; i < 4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx >= 0 && ny >= 0 && nx < n && ny < n){
			if(tmp[nx][ny] == 1) dfs(nx,ny);
		}
	}
}

int island()
{
	int asdf = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(tmp[i][j] == 1){
				dfs(i,j);
				asdf++;
			}
		}
	}
	return asdf;
}

void f(int H)
{
	memset(tmp,0,sizeof(tmp));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			tmp[i][j] = (ar[i][j] > H ? 1 : 0);
		}
	}
	
	int val = island();
	ans = max(ans, val);
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &ar[i][j]);
			minH = min(ar[i][j], minH);
			maxH = max(ar[i][j], maxH);
		}
	}
	
	for(int i = minH; i < maxH; i++){
		f(i);
	}
	
	printf("%d", ans);
}
