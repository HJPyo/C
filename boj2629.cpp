#include<stdio.h>
#define X x+555

int n, m, w, ar[31], dp[44444];

//x = weight y = choo z = count
int f(int x, int y, int z)
{
	if(x < -500 || x > w+500 || y == m || z == n) return 0;
	if(dp[x] != -1) return dp[x];
	if(x == w) return 1;
	
	dp[x] = 0;
	return dp[x] = f(x+ar[y], y+1, z+1) + f(x-ar[y], y+1, z+1) + f(x,y+1,z);
}

int main()
{
	for(int i = 0; i < 44444; i++)
	dp[i] = -1;
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	scanf("%d", &ar[i]);
	
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &w);
		printf("%c ", f(0,0,0) > 0 ? 'Y' : 'N');
	}
}
