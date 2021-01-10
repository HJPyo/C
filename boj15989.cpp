#include<stdio.h>

int k;
long int dp[10001][4];

unsigned int f(int x, int y)
{
	if(x < 0 || y > 3) return 0;
	if(x == 0) return 1;
	if(dp[x][y]) return dp[x][y];
	return dp[x][y] = f(x-y,y) + f(x-(y+1),y+1);
}

int main()
{
	scanf("%d", &k);
	while(k--){
		int n;
		scanf("%d", &n);
		printf("%u\n", f(n,1));
	}
}
