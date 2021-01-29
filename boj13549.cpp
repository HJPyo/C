#include<stdio.h>
#include<queue>
using namespace std;

int s, e, vis[200001];

int main()
{
	scanf("%d %d", &s, &e);
	priority_queue<pair<int,int> >q;
	q.push({0,-s});
	vis[s] = 1;
	while(!q.empty()){
		int time = -q.top().first;
		int now = q.top().second;
		q.pop();
		if(now == e){
			printf("%d", time);
			return 0;
		}
		
		if(now+1 < 100001 && !vis[now+1]){
			q.push({-(time+1),-(now+1)});
			vis[now+1] = 1;
		}
		if(now<<1 < 100001 && !vis[now<<1]){
			q.push({-time,-(now<<1)});
			vis[now<<1] = 1;
		}
		if(now > 0 && !vis[now-1]){
			q.push({-(time+1),-(now-1)});
			vis[now-1] = 1;
		}
	}
}
