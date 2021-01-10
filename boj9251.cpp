#include<stdio.h>

char n[1002], m[1002], dp[1002][1002];

int Max(int a, int b)
{
	return a > b ? a : b;
}

int f(int x, int y)
{
	if(n[x] == NULL || m[y] == NULL) return 0;
	if(dp[x][y]) return dp[x][y];
	
	return dp[x][y] = Max(f(x+1,y), f(x,y+1)) + (n[x]!=m[y]?0:1);
}

int main()
{
	scanf("%s %s", &n, &m);
	printf("%d", f(0,0));
}
