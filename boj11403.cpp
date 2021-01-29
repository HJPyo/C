#include<stdio.h>
#include<vector>
using namespace std;

int n, vis[101][101];
vector<int>ar[101];

void dfs(int start, int now)
{	
	for(int i = 0; i < ar[now].size(); i++){
		int next = ar[now][i];
		if(vis[start][next] == 0){
			vis[start][next] = 1;
			dfs(start, next);
		}
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0, a; j < n; j++){
			scanf("%d", &a);
			if(a) ar[i].push_back(j);
		}
	}
	
	for(int i = 0; i < n; i++){
		dfs(i,i);
		for(int j = 0; j < n; j++){
			printf("%d ", vis[i][j]);
		}
		puts("");
	}
}
