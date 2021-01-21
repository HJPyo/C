#include<stdio.h>
#include<vector>
#define INF 999999999
using namespace std;

int n, k, ar1[101], ar2[101], ar3[101], ar4[101];
vector<vector<int> >dp(101,vector<int>(100001,-1));

int max(int x, int y)
{
	return x > y ? x : y;
}

int f(int x, int y)
{
	if(y > k) return -INF;
	if(x == n) return 0;
	if(dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;
	
	return dp[x][y] = max(ar2[x] + f(x+1,y+ar1[x]), ar4[x] + f(x+1,y+ar3[x]));
}

int main()
{
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d %d %d %d", &ar1[i], &ar2[i], &ar3[i], &ar4[i]);
	}
	printf("%d", f(0,0));
}
