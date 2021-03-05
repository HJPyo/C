#include<stdio.h>
#define INF 999999999

int n, k, day[101], dp[101][101];

int min(int x, int y)
{
	return x < y ? x : y;
}

int f(int x, int y)
{
	if(x > n) return 0;
	if(dp[x][y]) return dp[x][y];
	if(day[x] == 1) return dp[x][y] = f(x+1,y);
	
	dp[x][y] = INF;
	if(y >= 3) dp[x][y] = min(dp[x][y],f(x+1,y-3));
	else dp[x][y] = min(dp[x][y],f(x+1,y)+10000);
	dp[x][y] = min(dp[x][y],f(x+3,y+1)+25000);
	dp[x][y] = min(dp[x][y],f(x+5,y+2)+37000);
	
	return dp[x][y];
}

int main()
{
	scanf("%d %d", &n, &k);
	for(int i = 0, j; i < k; i++){
		scanf("%d", &j);
		day[j] = 1;
	}
	printf("%d", f(1,0));
}
