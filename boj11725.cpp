#include<stdio.h>
#include<vector>
using namespace std;

int n, vis[100001], parent[100001];
vector<int>node[100001];

void f(int x)
{
	vis[x] = 1;
	for(int i = 0; i < node[x].size(); i++){
		int next = node[x][i];
		if(vis[next]) continue;
		parent[next] = x;
		f(next);
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n-1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		node[a].push_back(b);
		node[b].push_back(a);
	}
	f(1);
	for(int i = 2; i <= n; i++){
		printf("%d\n", parent[i]);
	}
}
