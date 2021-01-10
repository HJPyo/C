#include<stdio.h>

int n, m[1001][3], dp[1001][3];

int Min(int a, int b){ return a < b ? a : b; }

int f(int x, int y)
{
	if(x == n) return 0;
	if(dp[x][y]) return dp[x][y];
	return dp[x][y] = m[x][y] + Min(f(x+1,(y+1)%3), f(x+1,(y+2)%3));
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	for(int j = 0; j < 3; j++)
	scanf("%d", &m[i][j]);
	
	printf("%d", Min(Min(f(0,0), f(0,1)), f(0,2)));
}
