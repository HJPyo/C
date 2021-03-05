#include<stdio.h>
#include<string.h>

int n, m, ar[55][55];
int dx[8] = {1,0,-1,0,1,1,-1,-1}, dy[8] = {0,1,0,-1,1,-1,-1,1};

void f(int x, int y)
{
	for(int i = 0; i < 8; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(ar[nx][ny] == 1){
			ar[nx][ny] = 0;
			f(nx,ny);
		}
	}
}

int main()
{
	while(1){
		scanf("%d %d", &m, &n);
		if(n == 0 && m == 0) break;
		
		int cnt = 0;
		memset(ar, -1, sizeof(ar));
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				scanf("%d", &ar[i][j]);
			}
		}
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(ar[i][j] == 1){
					ar[i][j] = 0;
					f(i,j);
					cnt++;
				}
			}
		}
		
		printf("%d\n", cnt);
	}
}
