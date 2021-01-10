#include<stdio.h>

int n, m, ar[1001], dp[1001][31][3];

int Max(int x, int y)
{
	return x > y ? x : y;
}

int f(int x, int y, int z)
{
	printf("%d %d %d\n", x, y, z);
	if(x == n || y == m) return 0;
	if(dp[x][y][z]) return dp[x][y][z];
	
	return dp[x][y][z] = Max(f(x+1,y+1,z^3), f(x+1,y,z)) + (ar[x] == z ? 1:0);
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &ar[i]);
	}
	printf("%d", f(0,0,1));
}
