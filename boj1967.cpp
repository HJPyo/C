#include<stdio.h>
#include<vector>
#define MAX 10000
using namespace std;

int n, vis[MAX+1], vis2[MAX+1], ans = 0;
vector< pair<int,int> >len[MAX+1];
struct st{
	int index, length;
}Mdis = {-1,-1};

int max(int x, int y)
{
	return x > y ? x : y;
}

void dfs(int x, int y)
{
	vis[x] = 1;
	if(Mdis.length < y)
		Mdis = {x,y};
	for(int i = 0; i < len[x].size(); i++){
		if(vis[len[x][i].first]) continue;
		dfs(len[x][i].first,y+len[x][i].second);
	}
}

void dfs2(int x, int y)
{
	vis2[x] = 1;
	ans = max(ans,y);
	printf("%d %d\n", x, ans);
	for(int i = 0; i < len[x].size(); i++){
		if(vis2[len[x][i].first]) continue;
		dfs(len[x][i].first,y+len[x][i].second);
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		len[a].push_back({b,c});
		len[b].push_back({a,c});
	}
	dfs(1,0);
	dfs2(Mdis.index,0);
	printf("%d", ans);
}
