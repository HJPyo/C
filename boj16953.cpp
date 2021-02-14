#include<stdio.h>
#include<queue>
using namespace std;

int n, m, ans = -1;
priority_queue< pair<int,int> >q;

int main()
{
	scanf("%d %d", &n, &m);
	q.push(make_pair(n,0));
	while(!q.empty()){
		int now = q.top().first;
		int cnt = q.top().second;
		printf("%d\n", now);
		q.pop();
		if(now > m) continue;
		if(now == m){
			ans = cnt;
			break;
		}
		q.push(make_pair(now<<1, cnt+1));
		q.push(make_pair(now*10+1, cnt+1));
	}
	printf("%d", ans);
}
