#include<stdio.h>
#include<vector>
#include<queue>
#define INF 60000006
#define LL long long int
using namespace std;

int n, k, table[505] = {}, vis[505] = {};
vector<LL>dis(505,INF);
vector<pair<int,LL>>v[505];
queue<int>q;

int main(){
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < k; i++){
		int a, b;
		LL c;
		scanf("%d %d %lld", &a, &b, &c);
		v[a].push_back({b,c});
	}
	
	q.push(1);
	vis[1] = 1;
	dis[1] = 0;
	table[1] = 1;
	
	while(!q.empty()){
		int now = q.front();
		q.pop();
		table[now] = 0;
		
		for(int i = 0; i < v[now].size(); i++){
			int next = v[now][i].first;
			int dist = v[now][i].second;
			
			if(dis[next] > dis[now] + dist){
				dis[next] = dis[now] + dist;
				
				if(!table[next]){
					vis[next]++;
					
					if(vis[next] >= n){
						printf("-1\n");
						return 0;
					}
					
					q.push(next);
					table[next] = 1;
				}
			}
		}
	}
	
	for(int i = 2; i <= n; i++){
		printf("%lld\n", dis[i] != INF ? dis[i] : -1);
	}
	
	return 0;
}//Á¸³ªÂ¼³× ¤·¤·.. 
