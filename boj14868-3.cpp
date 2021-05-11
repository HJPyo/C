#include<stdio.h>
#include<queue>
using namespace std;

int n, k, boss[2<<17], ar[2<<11][2<<11], civil[2<<11][2<<11];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
queue<pair<int,pair<int,int>>>q;

int max(int x, int y){
	return x > y ? x : y;
}

bool safe(int x, int y){
	return 1 <= x && 1 <= y && x <= n && y <= n;
}

int _find(int x){
	if(boss[x] == x) return x;
	else return boss[x] = _find(boss[x]);
}

void _union(int x, int y){
	x = _find(x);
	y = _find(y);
	
	if(x < y) boss[y] = x;
	else boss[x] = y;
	return;
}

void debug(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d ", ar[i][j]);
		}
		printf("|");
		for(int j = 1; j <= n; j++){
			printf("%d ", civil[i][j]);
		}
		puts("");
	}
	puts("");
}

int f(){
	int day = 0, comb = 0;
	
	while(!q.empty()){
		int now = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		
		if(comb == k-1)
			break;
		
		for(int i = 0; i < 4; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(safe(nx, ny)){
				if(ar[nx][ny] == ar[x][y] && now != civil[nx][ny]){
					if(_find(now) != _find(civil[nx][ny])){
						_union(now, civil[nx][ny]);
						day = max(day, ar[nx][ny]);
						comb++;
						//debug();
					}
				}
				else if(ar[nx][ny] == ar[x][y]+1 && now != civil[nx][ny]){
					if(_find(now) != _find(civil[nx][ny])){
						_union(now, civil[nx][ny]);
						day = max(day, ar[nx][ny]);
						comb++;
						//debug();
					}
				}
				else if(ar[nx][ny] == 0){
					q.push({now, {nx, ny}});
					ar[nx][ny] = ar[x][y] + 1;
					civil[nx][ny] = now;
				}
			}
		}
	}
	
	return day - 2;
}

int main(){
	scanf("%d %d", &n, &k);
	
	for(int i = 1; i <= k; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		q.push({i, {a, b}});
		
		boss[i] = i;
		civil[a][b] = i;
		ar[a][b] = 2;
	}
	
	printf("%d", f());
	
	return 0;
}
