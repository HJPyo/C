#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

int n, time[505], table[505], ans[505];
vector<int>len[505];
queue<int>Q;

int max(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1, j; i <= n; i++){
		scanf("%d", &time[i]);
		while(1){
			scanf("%d", &j);
			if(j == -1) break;
			len[j].push_back(i);
			table[i]++;
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(table[i] == 0) Q.push(i);
	}
	
	while(!Q.empty()){
		int now = Q.front();
		Q.pop();
		
		for(int i = 0; i < len[now].size(); i++){
			int next = len[now][i];
			ans[next] = max(ans[next], ans[now]+time[now]);
			if(--table[next] == 0){
				Q.push(next);
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		printf("%d\n", time[i]+ans[i]);
	}
}
