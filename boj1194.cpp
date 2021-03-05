#include<stdio.h>
#include<queue>
using namespace std;

struct minsik{
	int x, y, bit, dis;
};

int n, m, vis[55][55];
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
char maze[55][55];
queue<minsik>Q;
1
int IsSafe(int x, int y)
{
	return 0 <= x && 0 <= y && x < n && y < m;
}

int f()
{
	while(!Q.empty()){
		int x = Q.front().x;
		int y = Q.front().y;
		int bit = Q.front().bit;
		int dis = Q.front().dis;
		Q.pop();
		
		if(maze[x][y] == '1'){
			return dis;
		}
		
		vis[x][y] |= bit;
		
		for(int i = 0; i < 4; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(IsSafe(nx,ny)){
				if(vis[nx][ny] != bit){
					char next = maze[nx][ny];
					if(next == '.' || next == '1'){
						Q.push({nx,ny,bit,dis+1});
					}
					else if('A' <= next && next <= 'Z'){
						if(bit & (1<<(next-'A'+1))){
							Q.push({nx,ny,bit,dis+1});
						}
					}
					else if('a' <= next && next <= 'z'){
						Q.push({nx,ny,bit|(1<<(next-'a'+1)),dis+1});
					}
				}
			}
		}
	}
	
	return -1;
}

int main()
{
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < n; i++){
		char tmp[55];
		scanf("%s", &tmp);
		for(int j = 0; j < m; j++){
			maze[i][j] = tmp[j];
			if(tmp[j] == '0'){
				maze[i][j] = '.';
				Q.push({i,j,1,0});
				vis[i][j] = 1;
			}
		}
	}
	
	printf("%d", f());
}
