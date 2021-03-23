#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

const int INF = 1999999999;
int T;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	
	while(T--){
		int n, m, k;
		vector<pair<int,int>>minimum(101,{INF,INF});
		vector<pair<int,pair<int,int>>>v[101];
		priority_queue<pair<int,pair<int,int>>>pq;
		
		cin >> n >> m >> k;
		
		for(int i = 0; i < k; i++){
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			v[a].push_back({b,{c,d}});
		}
		
		pq.push({0,{0,1}});
		
		while(!pq.empty()){
			int dis = -pq.top().first;
			int paid = pq.top().second.first;
			int now = pq.top().second.second;
			pq.pop();
			
			if(paid > m) continue;
			if(minimum[now].first <= dis || minimum[now].second <= paid) continue;
			else minimum[now] = {dis,paid};
			
			for(int i = 0; i < v[now].size(); i++){
				int next = v[now][i].first;
				int time = v[now][i].second.first;
				int cost = v[now][i].second.second;
				pq.push({-dis-time,{paid+cost,next}});
			}
		}
		
		if(minimum[n].first == INF) cout << "Poor KCM\n";
		else cout << minimum[n].first << '\n';
	}
}
