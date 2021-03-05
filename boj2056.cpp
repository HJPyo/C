#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n, val[10001], table[10001], dist[10001], ans = -1;
vector<int>len[10001];
queue<int>Q;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int a, b, c;
		scanf("%d %d", &a, &b);
		
		if(b == 0){
			Q.push(i);
			dist[i] = a;
		}
		val[i] = a;
		
		while(b--){
			scanf("%d", &c);
			len[c].push_back(i);
			table[i]++;
		}
	}
	
	while(!Q.empty()){
		int now = Q.front();
		Q.pop();
		
		for(int i = 0; i < len[now].size(); i++){
			int next = len[now][i];
			dist[next] = max(dist[next], dist[now] + val[next]);
			if(--table[next]){
				Q.push(next);
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		ans = max(ans,dist[i]);
	}
	
	printf("%d", ans);
}
