#include<stdio.h>
#define INF 999999999

int n, ar[1001][3], dp[1001][4][4];

int min(int x, int y)
{
	return x < y ? x : y;
}

int f(int x, int y, int z)
{
	if(x == 0){
		dp[x][y][z] = INF;
		for(int i = 0; i < 3; i++){
			dp[x][y][z] = min(dp[x][y][z],ar[x][i]+f(x+1,i,i));
		}
	}
	else if(x == n-1){
		dp[x][y][z] = INF;
		for(int i = 0; i < 3; i++){
			if(y == i || z == i) continue;
			dp[x][y][z] = min(dp[x][y][z],ar[x][i]);
		}
	}
	else{
		if(dp[x][y][z]) return dp[x][y][z];
		dp[x][y][z] = INF;
		for(int i = 0; i < 3; i++){
			if(y == i) continue;
			dp[x][y][z] = min(dp[x][y][z],ar[x][i]+f(x+1,i,z));
		}
	}
	return dp[x][y][z];
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++){
			scanf("%d", &ar[i][j]);
		}
	}
	
	printf("%d", f(0,3,3));
}
