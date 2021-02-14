#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;

int n, vis[100001] = {};
vector< pair<int,int> >len[100001];
int dist = 0, idx = 0;

int max(int x, int y)
{
	return x > y ? x : y;
}

void deep(int x, int y)
{
	vis[x] = 1;
	if(dist < y){ dist = y; idx = x; }
	for(int i = 0; i < len[x].size(); i++){
		int next = len[x][i].first;
		if(vis[next]) continue;
		deep(next,y+len[x][i].second);
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 0 ; i < n; i++){
		int a, b, c;
		scanf("%d %d", &a, &b);
		while(b != -1){
			scanf("%d", &c);
			len[a].push_back({b,c});
			scanf("%d", &b);
		}
	}
	deep(1,0);
	memset(vis, 0, sizeof(vis)); dist = 0;
	deep(idx, 0);
	printf("%d", dist);
}
