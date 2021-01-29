#include<stdio.h>
#include<algorithm>

int n, m, k, ar[101][101], cnt = 0, size[5001];
int dx[4] = {0,1,-1,0}, dy[4] = {1,0,0,-1};

int dfs(int x, int y)
{
	ar[x][y] = 1;
	int tmp = 1;
	for(int i = 0; i < 4; i++){
		int nx = x+dx[i], ny = y+dy[i];
		if(nx >= 0 && ny >= 0 && nx < n && ny < m){
			if(ar[nx][ny] == 0){
				tmp += dfs(nx,ny);
			}
		}
	}
	return tmp;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	
	while(k--){
		int x1,y1,x2,y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for(int i = x1; i < x2; i++){
			for(int j = y1; j < y2; j++){
				ar[j][i] = 1;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(ar[i][j] == 0){
				size[cnt++] = dfs(i,j);
			}
		}
	}
	std::sort(size,size+cnt);
	
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++){
		printf("%d ", size[i]);
	}
}
