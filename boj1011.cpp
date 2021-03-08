#include<stdio.h>
#include<queue>
using namespace std;

int k;

int main()
{
	scanf("%d", &k);
	
	while(k--){
		int a, b;
		queue<pair<int,pair<int,int>>>Q;
		
		scanf("%d %d", &a, &b);
		Q.push({a,{0,0}});
		
		while(!Q.empty()){
			int now = Q.front().first;
			int dis = Q.front().second.first;
			int cnt = Q.front().second.second;
			Q.pop();
			
			printf(">>%d\n", now);
			
			if(now < 0)  continue;
			
			if(now == b){
				printf("%d\n", cnt);
				break;
			}
			
			Q.push({a+dis-1,{dis-1,cnt+1}});
			if(dis != 0)Q.push({a+dis,{dis,cnt+1}});
			Q.push({a+dis+1,{dis+1,cnt+1}});
		}
	}
}
