#include<stdio.h>
#include<string.h>
#include<vector>
#define MOD 1000000007
using namespace std;

vector<int>v[10];
int n, dp[100001][11];

int f(int x, int y)
{
	if(x == n) return y == 1;
	if(dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;
	
	for(int i = 0; i < v[y].size(); i++){
		dp[x][y] = (f(x+1,v[y][i]) + dp[x][y]) % MOD;
	}
	
	return dp[x][y];
}

int main()
{
	v[1].push_back(2); v[2].push_back(1);
	v[1].push_back(3); v[3].push_back(1);
	v[2].push_back(3); v[3].push_back(2);
	v[2].push_back(4); v[4].push_back(2);
	v[3].push_back(4); v[4].push_back(3);
	v[3].push_back(5); v[5].push_back(3);
	v[4].push_back(5); v[5].push_back(4);
	v[4].push_back(6); v[6].push_back(4);
	v[5].push_back(6); v[6].push_back(5);
	v[5].push_back(7); v[7].push_back(5);
	v[6].push_back(8); v[8].push_back(6);
	v[7].push_back(8); v[8].push_back(7);
	memset(dp,-1,sizeof(dp));
	
	scanf("%d", &n);
	printf("%d", f(0,1));
}
