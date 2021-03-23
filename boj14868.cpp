#include<stdio.h>
#include<queue>
#define MAX1 2002
#define MAX2 100005
#define IsSafe(x,y,n) (0 < x && 0 < y && x <= n && y <= n)
#define max(x,y) (x > y ? x : y)
using namespace std;

struct civil{ int x, y, col; };
int n, k, ar[MAX1][MAX1], T[MAX1][MAX1];
int boss[MAX2], dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
queue<civil>q;

int Find(int x)
{
	return (x == boss[x] ? x : boss[x] = Find(boss[x]));
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	
	if(x < y) boss[y] = x;
	else boss[x] = y;
	return;
}

void DEBUG()
{
	puts("----------DEBUG----------");
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d ", ar[i][j]);
		}
		puts("");
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < MAX2; i++){
		boss[i] = i;
	}
	
	for(int i = 1; i <= k; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		q.push({a,b,i});
		T[a][b] = i;
		ar[a][b] = 1;
	}
	
	int cnt = 0;
	
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int col = q.front().col;
		q.pop();
		
		if(cnt == k-1){
			printf("%d\n", ar[x][y]);
			break;
		}
		
		for(int i = 0; i < 4; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(IsSafe(nx,ny,n)){
				if(ar[nx][ny] == 0){
					ar[nx][ny] = ar[x][y] + 1;
					q.push({nx,ny,col});
				}
				if(T[nx][ny] == 0){
					T[nx][ny] = col;
				}
				if(T[nx][ny] != col){
					Union(T[nx][ny], col);
					cnt++;
				}
			}
		}
	}
}
