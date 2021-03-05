#include<stdio.h>

int n, m, k, len = 1, dir = 0;
int ar[102][102], vis[102][102], order[10002];
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};

bool IsSafe(int x, int y)
{
	return 0 < x && 0 < y && x <= n && y <= n;
}

void print(int &time)
{
	printf(">>%d\n", time);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d ", vis[i][j]);
		}
		puts("");
	}
	puts("");
}

int main()
{
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		ar[a][b] = 1;
	}
	
	scanf("%d", &k);
	
	for(int i = 0; i < k; i++){
		int a;
		char b;
		scanf("%d %c", &a, &b);
		order[a+1] = (b == 'L' ? 3 : 1);
	}
	
	int x = 1, y = 1, time = 1;
	while(true){
		dir = (dir + order[time]) % 4;
		vis[x][y] = time;
//		print(time);
		int nx = x+dx[dir];
		int ny = y+dy[dir];
		if(vis[x][y] - vis[nx][ny]>= len && IsSafe(nx,ny)){
			time++;
			len += ar[nx][ny];
			x = nx;
			y = ny;
		}
		else break;
	}
	
	printf("%d", time);
}
