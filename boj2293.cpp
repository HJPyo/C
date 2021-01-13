#include<stdio.h>
#define M 103

int n, m, ar[100], dp[100][M+1];

int f(int x, int y)
{
	if(x == n || y > m) return 0;
	if(y == m) return 1;
	if(dp[x][y%M]) return dp[x][y%M];
	
	return dp[x][y%M] = f(x,(y+ar[x])%M) + f(x+1,y%M);
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &ar[i]);
	}
	printf("%d", f(0,0));
}
