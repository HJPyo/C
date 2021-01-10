#include<stdio.h>
#define INF 999999999

int n, m, in[22], out[22], dp[21][1001];

int Min(int a, int b){ return a < b ? a : b; }

int f(int x, int y)
{
	if(x == m) return INF;
	if(y >= n) return 0;
	if(dp[x][y]) return dp[x][y];
	return dp[x][y] = Min((in[x]+f(x,y+out[x])), f(x+1,y));
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &in[i], &out[i]);
	}
	printf("%d", f(0,0));
}
