#include<stdio.h>

int n, m[1001], dp[1001];

int MAX(int x, int y){
	return x > y ? x : y;
}

int f(int x, int y)
{
	if(x > n) return 0;
	if(y == 0 && m[x] < m[x-1]) return 0;
	if(y == 1 && m[x] > m[x-1]) return 0;
	if(dp[x]) return dp[x];
	return dp[x] = 1 + MAX(f(x+1,y), MAX(f(x+2,y), f(x+1, 1)));
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	scanf("%d", &m[i]);
	
	printf("%d", f(0,0));
}
