#include<stdio.h>
#include<string.h>
#define INF 999999999
#define min(x, y) (x < y ? x : y)

int n, k, ar[55][55], pf[55][55];
int dp[55][55][55][55];

int f(int x1, int y1, int x2, int y2){
	int &ret = dp[x1][y1][x2][y2];
	
	if(ret != -1) return ret;
	if(x1 == x2 && y1 == y2) return 0;
	
	ret = 0;
	int tmp = INF, now = pf[x2][y2] + pf[x1-1][y1-1] - pf[x1-1][y2] - pf[x2][y1-1];
	
	for(int i = x1; i < x2; i++){
		tmp = min(tmp, f(x1, y1, i, y2) + f(i+1, y1, x2, y2));
	}
	
	for(int i = y1; i < y2; i++){
		tmp = min(tmp, f(x1, y1, x2, i) + f(x1, i+1, x2, y2));
	}
	
	ret = tmp + now;
	return ret;
}

int main(){
	scanf("%d %d", &n, &k);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			scanf("%d", &ar[i][j]);
			pf[i][j] = ar[i][j] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
		}
	}
	
	memset(dp, -1, sizeof(dp));
	
	printf("%d", f(1, 1, n, k));
	
	return 0;
}
