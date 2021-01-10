#include<stdio.h>
#define INF 999999999

int n, ar[10005], dp[10005][3];

int MAX(int x, int y){ return x > y ? x : y; }

int f(int x, int y)
{
	if(y > 2) return -INF;
	if(x == n) return 0;
	if(dp[x][y]) return dp[x][y];
	return dp[x][y] = MAX(f(x+1,0), ar[x]+f(x+1,y+1));
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &ar[i]);
	
	printf("%d", f(0,0));
}
