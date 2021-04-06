#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;

struct xyz{
	int x, y, z;
};

int n, m, w, day = -1;
int box[102][102][102], vis[102][102][102];
int dx[6] = {1,-1,0,0,0,0}, dy[6] = {0,0,1,-1,0,0}, dz[6] = {0,0,0,0,1,-1};
queue<xyz>q;

int main(){
	memset(box, -1, sizeof(box));
	
	cin >> n >> m >> w;
	
	for(int i = 1; i <= w; i++){
		for(int j = 1; j <= m; j++){
			for(int k = 1; k <= n; k++){
				cin >> box[i][j][k];
				if(box[i][j][k] == 1){
					q.push({i,j,k});
					vis[i][j][k] = 1;
				}
			}
		}
	}
	
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();
		
		day = max(day,vis[x][y][z]);
		
		for(int i = 0; i < 6; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			int nz = z+dz[i];
			if(box[nx][ny][nz] == 0 && vis[nx][ny][nz] == 0){
				vis[nx][ny][nz] = vis[x][y][z] + 1;
				q.push({nx,ny,nz});
			}
		}
	}
	
	day--;
	
	for(int i = 1; i <= w; i++){
		for(int j = 1; j <= m; j++){
			for(int k = 1; k <= n; k++){
				if(box[i][j][k] == 0 && vis[i][j][k] == 0){
					day = -1;
					goto END;
				}
			}
		}
	}
	
	END:
	
	cout << day;
}
