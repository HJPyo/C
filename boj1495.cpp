#include<stdio.h>

int n, m, o, ar[101], dp[101][1001];

int Max(int a, int b){ return a > b ? a : b; }

int f(int x, int y)
{
	if(y < 0 || o < y) return -1;
	if(x == n) return y;
	if(dp[x][y]) return dp[x][y];
	return dp[x][y] = Max(f(x+1, y+ar[x]), f(x+1, y-ar[x]));
}

int main()
{
	scanf("%d %d %d", &n, &m, &o);
	for(int i = 0; i < n; i++){
		scanf("%d", &ar[i]);
	}
	printf("%d", f(0,m));
}
