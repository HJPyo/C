#include<stdio.h>

int n, m, ar[10005][505];
int dx[3] = {-1,0,1};

bool dfs(int x, int y)
{
	ar[x][y] = 1;
	if(y == m-1) return true;
	
	for(int i = 0; i < 3; i++){
		int nx = x+dx[i];
		int ny = y+1;
		
		if(0 <= nx && nx < n) if(ar[nx][ny] == 0){
			bool tmp = dfs(nx,ny);
			if(tmp){
				return tmp;
			}
		}
	}
	
	return false;
}

int main()
{
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < n; i++){
		char tmp[505];
		scanf("%s", &tmp);
		for(int j = 0; j < m; j++){
			ar[i][j] = (tmp[j] == 'x');
		}
	}
	
	int ans = 0;
	
	for(int i = 0; i < n; i++){
		ans += dfs(i,0);
	}
	
	printf("%d", ans);
}
