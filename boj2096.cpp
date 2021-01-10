#include<stdio.h>
#define INF 999999999

int n, ar[100001][3], dp[100001][3], _dp[100001][3];

int Max(int x, int y)
{
	return x > y ? x : y;
}

int f(int x, int y)
{
	if(x == n) return 0;
	if(dp[x][y]) return dp[x][y];
	
	return dp[x][y] = Max((y==2 ? 0:f(x+1,0)+ar[x][0]), Max(f(x+1,1)+ar[x][1], (y==0 ? 0:f(x+1,2)+ar[x][2])));
}

int Min(int x, int y)
{
	return x < y ? x : y;
}

int _f(int x, int y)
{
	if(x == n) return INF;
	if(_dp[x][y]) return _dp[x][y];
	
	return _dp[x][y] = Min((y==2 ? INF:_f(x+1,0)+ar[x][0]), Min(_f(x+1,1)+ar[x][1], (y==0 ? INF:_f(x+1,2)+ar[x][2])));
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++)
		scanf("%d", &ar[i][j]);
	}
	
	printf("%d ", f(0,1));
	printf("%d", _f(0,1));
}
