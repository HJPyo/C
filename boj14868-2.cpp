#include<stdio.h>
#include<queue>
#define MAX1 2001
#define MAX2 100001
#define IsSafe(x,y,n) (x > 0 && y > 0 && x <= n && y <= n)
using namespace std;

struct xycol{ int x, y, col; };
int n, k, ar1[MAX1][MAX1], ar2[MAX1][MAX1], boss[MAX2];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
queue<xycol>q;

int Find(int x)
{
	if(boss[x] == x) return x;
	else return boss[x] = Find(boss[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	
	if(x < y) boss[y] = x;
	else boss[x] = y;
	
	return;
}

int main()
{
	scanf("%d %d", &n, &k);
	
	for(int i = 1; i <= k; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		q.push({a,b,i});
		ar1[a][b] = 1;
		ar2[a][b] = i;
	}
	
	int cnt = 0;
	
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int col = q.front().col;
		q.pop();
		
		if(cnt == k-1){
			printf("%d", ar1[x][y]);
			break;
		}
		
		for(int i = 0; i < 4; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(IsSafe(nx,ny,n)){
				if(ar1[nx][ny] == 0){
					ar1[nx][ny] = ar1[x][y] + 1;
					ar2[nx][ny] = col;
					q.push({nx,ny,Find(col)});
				}
				else if(Find(ar2[nx][ny]) != Find(ar2[x][y])){
					Union(ar2[nx][ny],ar2[x][y]);
					cnt++;
				}
			}
		}
	}
	
	return 0;
}
