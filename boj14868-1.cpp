#include<stdio.h>
#include<queue>
#define IsSafe(x,y,n) (0 < x && 0 < y && x <= n && y <= n)
using namespace std;

struct xycol{
	int x, y, col;
};
int n, k, col[2002][2002], boss[100001];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
queue<xycol>q[4004];

int Find(int x)
{
	return boss[x] == x ? x : boss[x] = Find(boss[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	
	if(x != y) boss[x] = y;
}

void DEBUG()
{
	puts("----------DEBUG----------");
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d ", col[i][j]);
		}
		puts("");
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	
	for(int i = 1; i <= k; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		col[a][b] = i;
		boss[i] = i;
		q[0].push({a,b,i});
	}
	
	int day, cnt = 0;
	
	for(day = 0; cnt < k-1; day++){
		DEBUG();
		while(!q[day].empty()){
			int x = q[day].front().x;
			int y = q[day].front().y;
			int now = q[day].front().col;
			q[day].pop();
			
			for(int i = 0; i < 4; i++){
				int nx = x+dx[i];
				int ny = y+dy[i];
				int next = col[nx][ny];
				
				if(IsSafe(nx,ny,n)){
					if(next == 0){
						q[day+1].push({nx,ny,now});
						col[nx][ny] = now;
					}
					else if(next != now){
						if(Find(next) != Find(now)){
							Union(next,now);
							cnt++;
						}
					}
				}
			}
		}
	}
	
	DEBUG();
	
	printf("%d", day);
}
