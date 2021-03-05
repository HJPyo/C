#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stack>
#define MAX 10001
using namespace std;

int n, k, cnt = 0;
vector<int>con[MAX], rev[MAX], vis(MAX,0), SCC[MAX];
stack<int>S;

void dfs(int x)
{
	vis[x] = 1;
	
	sort(con[x].begin(),con[x].end());
	for(int i = 0; i < con[x].size(); i++){
		int next = con[x][i];
		if(vis[next] == 0){
			dfs(next);
		}
	}
	S.push(x);
}

void rev_dfs(int x)
{
	vis[x] = 1;
	SCC[cnt].push_back(x);
	
	sort(rev[x].begin(),rev[x].end());
	for(int i = 0; i < rev[x].size(); i++){
		int next = rev[x][i];
		if(vis[next] == 0){
			rev_dfs(next);
		}
	}
}

bool cmp(vector<int> x, vector<int> y)
{
	return x[0] < y[0];
}

int main()
{
	scanf("%d %d", &n, &k);
	for(int i = 0; i < k; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		con[a].push_back(b);
		rev[b].push_back(a);
	}
	
	for(int i = 1; i <= n; i++){
		if(vis[i] == 0){
			dfs(i);
		}
	}
	
	vis.clear();
	vis.resize(MAX,0);
	
	while(!S.empty()){
		int now = S.top();
		S.pop();
		if(vis[now] == 0){
			rev_dfs(now);
			sort(SCC[cnt].begin(),SCC[cnt].end());
			cnt++;
		}
	}
	sort(SCC,SCC+cnt,cmp);
	
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++){
		for(int j = 0; j < SCC[i].size(); j++){
			printf("%d ", SCC[i][j]);
		}
		puts("-1");
	}
}
