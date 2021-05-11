#include<bits/stdc++.h>
#define INF 999999999
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while(true){
		int n, k, st, en, bt[505] = {};
		vector<int> d(505, INF);
		vector<pair<int,int>> v[505];
		priority_queue<pair<int,int>> pq;
		
		cin >> n >> k;
		if(n == 0 && k == 0) break;
		cin >> st >> en;
		
		for(int i = 0; i < k; i++){
			int a, b, c;
			cin >> a >> b >> c;
			v[a].push_back({b, c});
		}
		
		pq.push({0, st});
		d[st] = 0;
		bt[st] = -1;
		
		while(!pq.empty()){
			int dis = -pq.top().first;
			int now = pq.top().second;
			pq.pop();
			
			for(int i = 0; i < v[now].size(); i++){
				int next = v[now][i].first;
				int ndis = v[now][i].second + dis;
				if(ndis < d[next]){
					pq.push({-ndis, next});
					d[next] = ndis;
					bt[next] = now;
				}
			}
		}
		
		int idx = bt[en];
		
		while(bt[idx] != -1){
			table[idx][bt[idx]] = INF;
			idx = bt[idx];
		}
		
		d.resize(505,INF);
		d[st] = 0;
		
		while(!pq.empty()){
			int dis = -pq.top().first;
			int now = pq.top().second;
			pq.pop();
			
			for(int i = 0; i < v[now].size(); i++){
				int next = v[now][i].first;
				int ndis = v[now][i].second + dis;
				
				if(ndis < d[next]){
					pq.push({-ndis, next});
					d[next] = ndis;
				}
			}
		}
		
		cout << d[en] << '\n';
	}
	
	return 0;
}
