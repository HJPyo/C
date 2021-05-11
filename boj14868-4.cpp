#include<stdio.h>
#include<queue>
#define MAX 2002
using namespace std;

struct xypos{
	int x, y, pos;
};

int n, k;
int ar1[MAX][MAX], ar2[MAX][MAX];
int boss[100005];

queue<xypos>q[2];

bool safe(int x, int y){
	return 0 < x && 0 < y && x <= n && y <= n;
}

int _find(int x){
	if(x == boss[x])
		return x;
	else
		return boss[x] = _find(boss[x]);
}

void _union(int x, int y){
	x = _find(x);
	y = _find(y);
	
	if(x < y) boss[y] = x;
	else boss[x] = y;
	
	return;
}

int f(){
	int day = 0, comb = 0;
	int dx[4] = {1,-1,0,0};
	int dy[4] = {0,0,1,-1};
	
	while(true){
		while(!q[0].empty()){
			int x = q[0].front().x;
			int y = q[0].front().y;
			int now = q[0].front().pos;
			q[1].push({x, y, now});
			q[0].pop();
			
			for(int i = 0; i < 4; i++){
				int nx = x+dx[i];
				int ny = y+dy[i];
				
				if(ar2[nx][ny] != 0 && _find(ar2[x][y]) != _find(ar2[nx][ny])){
					_union(ar2[x][y], ar2[nx][ny]);
					comb++;
				}
			}
		}
		
		if(comb == k-1) break;
		
		while(!q[1].empty()){
			int x = q[1].front().x;
			int y = q[1].front().y;
			int now = q[1].front().pos;
			q[1].pop();
			
			for(int i = 0; i < 4; i++){
				int nx = x+dx[i];
				int ny = y+dy[i];
				
				if(safe(nx, ny) && ar1[nx][ny] == 0){
					q[0].push({nx, ny, now});
					ar1[nx][ny] = ar1[x][y] + 1;
					ar2[nx][ny] = now;
				}
			}
		}
		
		day++;
	}
	
	return day;
}

int main(){
	scanf("%d %d", &n, &k);
	
	for(int i = 1; i <= k; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		
		q[0].push({a, b, i});
		ar1[a][b] = 2;
		ar2[a][b] = i;
		boss[i] = i;
	}
	
	printf("%d", f());
	
	return 0;
}
