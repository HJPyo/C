#include<stdio.h>

int n, ar[1001], dp[1001][1001];

int max(int x, int y)
{
	return x > y ? x : y;
}

int f(int x, int y)
{
	if(x == n) return 0;
	if(dp[x][y]) return dp[x][y];
	if(ar[x] > y) dp[x][y] = 1 + f(x+1,ar[x]);
	return dp[x][y] = max(dp[x][y],f(x+1,y));
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &ar[i]);
	}
	printf("%d", f(0,0));
}
