#include<stdio.h>

int n, dp[10][101];
long int sum = 0;

long int f(int x, int y)
{
	if(x < 0 || 9 < x) return 0;
	if(y > n) return 1;
	if(dp[x][y]) return dp[x][y];
	return dp[x][y] = (f(x+1, y+1) + f(x-1, y+1)) % 1000000000;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i < 10; i++){
		sum += f(i,2);
	}
	printf("%d", sum % 1000000000);
}
