#include<stdio.h>
#define INF 999999999

int n, m, k, ar[11][11], vis[11][11], MAX = -INF;

void Xvis(int x, int y, int val)
{
	vis[x][y] += val;
	vis[x+1][y] += val;
	vis[x-1][y] += val;
	vis[x][y+1] += val;
	vis[x][y-1] += val;
}

void f(int x, int y, int sum, int deep)
{
	if(deep == k){
		if(MAX < sum) MAX = sum;
		return;
	}
	for(int i = 1; i <= n; i++){
		if(i < x) continue;
		for(int j = 1; j <= m; j++){
			if(i == x && j < y) continue;
			if(vis[i][j] <= 0){
				Xvis(i,j,1);
				f(i,j,sum+ar[i][j],deep+1);
				Xvis(i,j,-1);
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &ar[i][j]);
		}
	}
	
	f(1,1,0,0);
	
	printf("%d", MAX);
}
