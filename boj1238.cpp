#include<stdio.h>
#include<vector>
#include<queue>
#define MAX 1001
#define INF 999999999
using namespace std;

int n, m, k;
vector<int>table(MAX,INF), vis(MAX,0);
vector<pair<int,int>>V[MAX];
queue<pair<int,int>>Q;

int min(int x, int y)
{
	return x < y ? x : y;
}

int max(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	
	for(int i = 0; i < m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		V[a].push_back({b,c});
		V[b].push_back({a,c});
	}
	
	table[k] = 0;
	Q.push({k,0});
	vis[k] = 1;
	
	while(!Q.empty()){
		int now = Q.front().first;
		int dis = Q.front().second;
		Q.pop();
		
		table[now] = min(table[now], dis);
		
		for(int i = 0; i < V[now].size(); i++){
			int next = V[now][i].first;
			int ndis = V[now][i].second;
			if(vis[next] == 0){
				Q.push({next,dis+ndis});
				vis[next] = 1;
			}
		}
	}
	
	int ans = -1;
	
	for(int i = 1; i <= n; i++){
		ans = max(ans, table[i]);
	}
	
	printf("%d", ans << 1);
}
