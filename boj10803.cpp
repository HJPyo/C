#include<stdio.h>
#define INF 999999999

int n, m, dp[10001][101];

int Min(int x, int y)
{
	return x < y ? x : y;
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int f(int x, int y)
{
	if(x < y) swap(&x, &y);
//	printf("%d %d\n", x, y);
	if(x % y == 0) return x/y;
	if(dp[x][y]) return dp[x][y];
	
	dp[x][y] = INF;
	for(int i = 1; i <= x/2; i++){
		dp[x][y] = Min(dp[x][y], f(i,y) + f(x-i,y));
	}
	for(int i = 1; i <= y/2; i++){
		dp[x][y] = Min(dp[x][y], f(x,i) + f(x,y-i));
	}
	return dp[x][y];
}

int main()
{
	scanf("%d %d", &n, &m);
	printf("%d", f(n, m));
}
