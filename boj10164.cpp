#include<stdio.h>

int n, m, o, px, py, dp[16][16];

int main()
{
	dp[1][1] = 1;
	scanf("%d %d %d", &n, &m, &o);
	if(o == 0){
		px = py = 1;
	}
	else{
		py = o % m;
		px = o/m+1;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j] += dp[i-1][j] + dp[i][j-1];
		}
	}
	int nx = (n-px+1), ny = (m-py+1);
	printf("%d", dp[px][py] * dp[nx][ny]);
}
