#include<stdio.h>
#include<vector>
#include<queue>
#define MAX 100001
using namespace std;

int n, m, k, vis[MAX+1000];
vector<int>len[MAX+1000];
queue<int>Q;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= m; i++){
		for(int j = 0; j < k; j++){
			int a;
			scanf("%d", &a);
			len[i+n].push_back(a);
			len[a].push_back(i+n);
		}
	}
	
	int ans = -1;
	
	Q.push(1);
	vis[1] = 1;
	while(!Q.empty()){
		int now = Q.front();
		Q.pop();
		
		if(now == n){
			ans = vis[now];
			break;
		}
		
		for(int i = 0; i < len[now].size(); i++){
			int next = len[now][i];
			if(!vis[next]){
				vis[next] = vis[now]+1;
				Q.push(next);
			};
		}
	}
	
	printf("%d\n", ans == -1 ? -1 : (ans+1)/2);
}
