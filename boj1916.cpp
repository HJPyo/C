#include<iostream>
#include<vector>
#include<queue>
#define INF 1999999999
using namespace std;

int n, k, st, en;
vector<int> dist(1001,INF);
vector<pair<int,int>> v[1001];
priority_queue<pair<int,int>> pq;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	
	for(int i = 0; i < k; i++){
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b,c});
	}
	
	cin >> st >> en;
	pq.push({0,st});
	
	while(!pq.empty()){
		int now = pq.top().second;
		int dis = -pq.top().first;
		pq.pop();
		
		if(dist[now] <= dis) continue;
		else dist[now] = dis;
		
		for(int i = 0; i < v[now].size(); i++){
			int next = v[now][i].first;
			int ndis = v[now][i].second;
			pq.push({-dis-ndis,next});
		}
	}
	
	cout << dist[en];
}
