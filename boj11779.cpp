#include<stdio.h>
#include<vector>
#include<stack>
#include<queue>
#define INF 1999999999
using namespace std;

int n, k, st, en, bt[1001];
vector<int>d(1001,INF);
vector<pair<int,int>>v[1001];
priority_queue<pair<int,int>>pq;
stack<int>s;

int main(){
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < k; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({b,c});
	}
	
	scanf("%d %d", &st, &en);
	
	pq.push({0,st});
	bt[st] = -1;
	d[st] = 0;
	
	while(!pq.empty()){
		int now = pq.top().second;
		int dis = -pq.top().first;
		pq.pop();
		
		for(int i = 0; i < v[now].size(); i++){
			int next = v[now][i].first;
			int ndis = v[now][i].second;
			if(d[next] > dis + ndis){
				pq.push({-dis-ndis, next});
				bt[next] = now;
				d[next] = dis + ndis;
			}
		}
	}
	
	int idx = en;
	
	while(idx != -1){
		s.push(idx);
		idx = bt[idx];
	}
	
	printf("%d\n%d\n", d[en], s.size());
	
	while(!s.empty()){
		printf("%d ", s.top());
		s.pop();
	}
	
	return 0;
}
