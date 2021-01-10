#include<stdio.h>

int n, ar[501][501], dp[501][501];

int Max(int x, int y)
{
	return x > y ? x : y;
}

int f(int x, int y)
{
	if(x == n) return 0;
	if(dp[x][y]) return dp[x][y];
	return dp[x][y] = ar[x][y] + Max(f(x+1,y), f(x+1,y+1));
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			scanf("%d", &ar[i][j]);
		}
	}
	
	printf("%d", f(0,0));
}
