#include<stdio.h>

int n, ar[1001], dp[1001][1001];

int Max(int a, int b){ return a > b ? a : b; }

int f(int x, int y, int z)
{
	if(x == n) return z;
	if(dp[x][y]) return dp[x][y];
	return dp[x][y] = Max(f(x+1,(ar[x]>y ? ar[x]:y),z+(ar[x]>y ? z+1:z)), f(x+1,ar[x],1));
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &ar[i]);
	}
	
	printf("%d", f(0,0,0));
}
