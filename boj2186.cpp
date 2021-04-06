#include<stdio.h>
#include<string.h>
#define IsSafe(x,y,n,m) (0 <= x && 0 <= y && x < n && y < m)

int dp[105][105][88], len, cnt = 0;
char ar[105][105], str[88];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};

int n, m, k;

int f(int x, int y, int idx){
	int &ret = dp[x][y][idx];
	if(ret != -1) return ret;
	if(idx == len - 1) return 1;
	
	ret = 0;
	
	for(int i = 0; i < 4; i++){
		for(int j = 1; j <= k; j++){
			int nx = x + (dx[i] * j);
			int ny = y + (dy[i] * j);
			if(IsSafe(nx,ny,n,m)){
				if(ar[nx][ny] == str[idx+1]){
					ret += f(nx,ny,idx+1);
				}
			}
		}
	}
	
	return ret;
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	
	for(int i = 0; i < n; i++){
		char tmp[88];
		scanf("%s", &tmp);
		for(int j = 0; j < m; j++){
			ar[i][j] = tmp[j];
		}
	}
	
	scanf("%s", &str);
	len = strlen(str);
	memset(dp, -1, sizeof(dp));
	
	for(int x = 0; x < n; x++){
		for(int y = 0; y < m; y++){
			if(ar[x][y] == str[0]){
				cnt += f(x,y,0);
			}
		}
	}
	
	printf("%d", cnt);
}
