#include<stdio.h>
#define INF 2111111111

int n, m, mem[101], val[101], dp[10001][101];

int Min(int x, int y)
{
	return x < y ? x : y;
}

//x == mem, y == val, z == now
int f(int x, int y, int z)
{
	if(x >= m) return y;
	if(z == n) return INF;
	if(dp[y][z]) return dp[y][z];
	
	return dp[y][z] = Min(f(x,y,z+1),f(x+mem[z],y+val[z],z+1));
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &mem[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &val[i]);
	}
	printf("%d", f(0,0,0));
}
