#include<stdio.h>
#include<queue>
using namespace std;

int n, m, ar[1001][1001];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,-1,1};
struct st{
	int x, y, cnt, BOOM;
};

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++)
	for(int j=1; j<=m; j++)
	scanf("%1d", &ar[i][j]);
	
	queue<st>q;
	q.push((st){1,1,1,0});
	ar[1][1] = 2;
	while(!q.empty()){
		st c = q.front();
		q.pop();
		if(c.x==n && c.y==m){
			printf("%d", c.cnt);
			return 0;
		}
		for(int i=0; i<4; i++){
			int nx = c.x+dx[i], ny = c.y+dy[i];
			if(ar[nx][ny] == 2 || (ar[nx][ny] == 1 && c.BOOM == 1)) continue;
			if(nx<1||ny<1||n<nx||m<ny) continue;
			if(!ar[nx][ny]){
				q.push((st){nx,ny,c.cnt+1,c.BOOM});
				ar[nx][ny] = 2;
			}
			else if(!c.BOOM){
				q.push((st){nx,ny,c.cnt+1,c.BOOM+1});
				ar[nx][ny] = 2;
			}
		}
	}
	printf("%d", -1);
	return 0;
}
