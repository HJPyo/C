#include<stdio.h>
#include<vector>
#define INF 1999999999
using namespace std;

int n, m, gas[2505], vis[2505];
vector<int>dp(2505,INF);
vector< pair<int,int> >len[2505];

int min(int x, int y){ return x < y ? x : y; }

int f(int now, int low)
{
	if(now == n) return 0;
	if(dp[now] != INF) return dp[now];
	vis[now]++;
	low = min(low,gas[now]);
	for(int i = 0; i < len[now].size(); i++){
		int next = len[now][i].first;
		int dis = len[now][i].second;
		if(vis[next] < 3)
			dp[now] = dis*low + min(dp[now], f(next,low));
	}
	vis[now]--;
	return dp[now];
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &gas[i]);
	}
	for(int i = 0, a, b, c; i < m; i++){
		scanf("%d %d %d", &a, &b, &c);
		len[a].push_back({b,c});
		len[b].push_back({a,c});
	}
	printf("%d", f(1,gas[1]));
}
