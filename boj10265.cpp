#include<stdio.h>
#include<algorithm>
using namespace std;

int n, k, ar[1001], vis[1001], cyc[1001], ans[1001], back_edge[1001], group[1001], cnt = 1;

int dfs(int x)
{
	if(vis[x]) return x;
	if(cyc[x]) return 0;
	vis[x] = 1;
	cyc[x] = 1;
	int top = dfs(ar[x]);
	vis[x] = 0;
	if(top != 0){
		ans[x] = cnt;
		if(x != top)
			return top;
		else
			cnt++;
	}
	return 0;
}

int dp[1001][1001];

int f(int x, int y)
{
	if(y > k) return -999999999;
	if(x == cnt || y == k) return y;
	if(dp[x][y]) return dp[x][y];
	return dp[x][y] = max(f(x+1,y+group[x]), f(x+1,y));
}

int main()
{
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &ar[i]);
		back_edge[ar[i]] = 1;
	}
	
	for(int i = 1; i <= n; i++){
		dfs(i);
	}
	
	for(int i = 1; i <= n; i++){
		group[ans[i]]++;
	}
	
	for(int i = 1; i <= n; i++){
		if(!back_edge[i] && ans[ar[i]]) group[cnt++]++;
	}
	
	printf("%d", f(1,0));
}
