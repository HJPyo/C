#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int t, n, k, w;

int main()
{
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &k);
		vector<int>len[n+1], val(n+1,0), len_cnt(n+1,0), MAX(n+1,-1);
		queue<pair<int,int> >q;
		
		for(int i = 1; i <= n; i++){
			scanf("%d", &val[i]);
		}
		for(int i = 0, a, b; i < k; i++){
			scanf("%d %d", &a, &b);
			len[a].push_back(b);
			len_cnt[b]++;
		}
		scanf("%d", &w);
		
		for(int i = 1; i <= n; i++){
			if(len_cnt[i] == 0){
				q.push(make_pair(i,val[i]));
			}
		}
		
		while(!q.empty()){
			int now = q.front().first;
			int time = q.front().second;
			q.pop();
			
			if(now == w){
				printf("%d\n", time);
				break;
			}
			
			for(int i = 0; i < len[now].size(); i++){
				int next = len[now][i];
				MAX[next] = max(MAX[next], time+val[next]);
				if(--len_cnt[next] == 0){
					q.push(make_pair(next,MAX[next]));
				}
			}
		}
	}
}
