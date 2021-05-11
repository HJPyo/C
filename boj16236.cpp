#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
using namespace std;

struct xy{
	int x, y;
};

int n, x, y, size = 2, _exp = 0, dist = 0;
int ar[22][22], vis[22][22];
int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1};

xy food(int _x, int _y){
	queue<xy>q;
	q.push({_x,_y});
	memset(vis, 0, sizeof(vis));
	vis[_x][_y] = 1;
	
	while(!q.empty()){
		int cx = q.front().x;
		int cy = q.front().y;
		q.pop();
		
		if(ar[cx][cy] != 0 && ar[cx][cy] < size){
			_exp++;
			if(_exp == size){
				_exp = 0;
				size ++;
			}
			ar[cx][cy] = 0;
			return {cx, cy};
		}
		
		for(int i = 0; i < 4; i++){
			int nx = cx+dx[i];
			int ny = cy+dy[i];
			if(ar[nx][ny] <= size && ar[nx][ny] != -1 && vis[nx][ny] == 0){
				q.push({nx,ny});
				vis[nx][ny] = 1;
			}
		}
	}
	
	return {-99, -99};
}

int main(){
	scanf("%d", &n);
	
	memset(ar, -1, sizeof(ar));
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int tmp;
			scanf("%d", &tmp);
			
			if(tmp == 9){
				x = i;
				y = j;
				tmp = 0;
			}
			
			ar[i][j] = tmp;
		}
	}
	
	while(1){
		xy pos = food(x, y);
		printf("%d %d\n", pos.x, pos.y);
		if(pos.x == -99){
			break;
		}
		
		dist += abs(x-pos.x) + abs(y-pos.y);
		x = pos.x;
		y = pos.y;
	}
	
	printf("%d", dist);
}
