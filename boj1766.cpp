#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

int n, k, table[32005];
vector<int>v[32005];
priority_queue<int>q;

int main()
{
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < k; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		table[b]++;
		v[a].push_back(b);
	}
	
	for(int i = 1; i <= n; i++){
		if(table[i] == 0) q.push(-i);
	}
	
	int ans[32005];
	
	for(int i = 0; i < n; i++){
		int now = -q.top();
		q.pop();
		
		ans[i] = now;
		
		for(int j = 0; j < v[now].size(); j++){
			int next = v[now][j];
			if(--table[next] == 0){
				q.push(-next);
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		printf("%d ", ans[i]);
	}
}
