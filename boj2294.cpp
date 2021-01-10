#include<stdio.h>

int n, m, ar[101], dp[10001][10001], flag = -1;

int Min(int x, int y)
{
	return x < y ? x : y;
}

//x:cnt y:sum z:cur
int f(int x, int y, int z)
{
	if(y > m || z == n) return 0;
	if(y == m){ flag = 1; return x; }
	if(dp[x][z]) return dp[x][z];
	return dp[x][z] = Min(f(x+1,y+ar[z],z), f(x,y,z+1));
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
	scanf("%d", &ar[i]);
	printf("%d", f(0,0,0));
}
