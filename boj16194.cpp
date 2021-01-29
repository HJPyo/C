#include<stdio.h>
#include<algorithm>
#define INF 999999999
using namespace std;

int n, ar[1001], dp[1001][1001];

int f(int x, int y)
{
	if(x > n || y > n) return -INF;
	if(y == n) return 0;
	if(dp[x][y]) return dp[x][y];
	return dp[x][y] = max(f(x+1,y), ar[x]+f(x,y+x));
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &ar[i]);
	}
	printf("%d", f(1,0));
}
