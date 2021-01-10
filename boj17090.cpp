#include<stdio.h>

int n, m, sum = 0, ar[505][505], dp[505][505];
int dx[5] = {0,-1,1,0,0}, dy[5] = {0,0,0,-1,1};

int f(int x, int y)
{
	if(!ar[x][y])	   return 1;
	if(dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;
	return dp[x][y] = f(x+dx[ar[x][y]], y+dy[ar[x][y]]);
}

int main()
{
	scanf("%d %d", &n, &m);
	
	for(int i = 1; i <= n; i++){
		char tmp[505];
		scanf("%s", &tmp);
		for(int j = 1; j <= m; j++){
			dp[i][j] = -1;
			if		(tmp[j-1] == 'U') ar[i][j] = 1;
			else if	(tmp[j-1] == 'D') ar[i][j] = 2;
			else if	(tmp[j-1] == 'L') ar[i][j] = 3;
			else					  ar[i][j] = 4;
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			sum += f(i, j);
		}
	}
	
	printf("%d", sum);
	return 0;
}
