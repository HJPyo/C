#include<stdio.h>
#include<string.h>

struct sum{ int pow, weak; }ar[18];
int n, dp[18][18];

int min(int x, int y)
{
	return x < y ? x : y;
}

int max(int x, int y)
{
	return x > y ? x : y;
}

int f(int x, int y)
{
	printf(">>%d %d %d\n", x, y, dp[x][y]);
	if(x == 15 && y == 0) return 1;
	if(dp[x][y] != -1) return dp[x][y];
	
	dp[x][y] = 0;
	
	if(x < 15){
		int moval = ar[x].pow;
		for(int i = max(0,x-moval); i <= min(15,x+moval); i++){
			if(i == x) continue;
			if(ar[i].pow != 0) dp[x][y] = (dp[x][y] + f(i,y)) % 1000;
		}
	}
	if(y > 0){
		int moval = ar[y].pow;
		for(int i = max(0,y-moval); i <= min(15,y+moval); i++){
			if(i == y || !ar[i].weak) continue;
			if(ar[i].pow != 0) dp[x][y] = (f(x,i) + dp[x][y]) % 1000;
		}
	}
	
	return dp[x][y];
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		ar[a].pow = b;
		ar[a].weak = c;
	}
	
	memset(dp,-1,sizeof(dp));
	
	printf("%d", f(0,15));
}
