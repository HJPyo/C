#include<iostream>
#define max(x,y) (x > y ? x : y)
using namespace std;

int n, k, ar[55][55], dp[55][55], vis[55][55], ans = -1;
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};

int f(int x, int y){
	if(vis[x][y]){ printf("-1"); exit(0); }
	if(dp[x][y]) return dp[x][y];
	if(ar[x][y] == 0) return -1;
	
	vis[x][y] = 1;
	
	for(int i = 0; i < 4; i++){
		int nx = x+dx[i]*ar[x][y];
		int ny = y+dy[i]*ar[x][y];
		if(0 <= nx && 0 <= ny && nx < n && ny < k){
			dp[x][y] = max(f(nx,ny)+1,dp[x][y]);
		}
	}
	
	vis[x][y] = 0;
	
	return dp[x][y];
}

int main(){
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < n; i++){
		char tmp[55];
		scanf("%s", &tmp);
		
		for(int j = 0; j < k; j++){
			if(tmp[j] == 'H'){
				ar[i][j] = 0;
			}
			else{
				ar[i][j] = tmp[j] - '0';
			}
		}
	}
	
	printf("%d", f(0,0)+1);
	
	return 0;
}
