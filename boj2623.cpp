#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

int n, k, table[1001];
vector<int>v[1001];
queue<int>q;

int main()
{
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < k; i++){
		int a, tmp[101] = {};
		scanf("%d", &a);
		
		for(int j = 0; j < a; j++){
			scanf("%d", &tmp[j]);
		}
		
		for(int j = 1; j < a; j++){
			table[tmp[j]]++;
			v[tmp[j-1]].push_back(tmp[j]);
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(table[i] == 0) q.push(i);
	}
	
	int ans[1001];
	
	for(int i = 0; i < n; i++){
		if(q.empty()){
			printf("0\n");
			return 0;
		}
		int now = q.front();
		q.pop();
		
		ans[i] = now;
		
		for(int j = 0; j < v[now].size(); j++){
			int next = v[now][j];
			if(--table[next] == 0){
				q.push(next);
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		printf("%d\n", ans[i]);
	}
}
