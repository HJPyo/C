#include<bits/stdc++.h>
#define MAX 200002
using namespace std;

int n, k;
vector<pair<int,int>>d(MAX, pair<int,int>(MAX,0));
queue<pair<int,pair<int,int>>>q;

int dp[3] = {1,-1, 0};
int dm[3] = {0, 0, 1};

int main(){
	cin >> n >> k;
	
	q.push({0,{n,-1}});
	
	while(!q.empty()){
		int dis 	= q.front().first;
		int now 	= q.front().second.first;
		int before 	= q.front().second.second;
		q.pop();
		
		if(d[now].first <= dis)
			continue;
		
		d[now].first 	= dis;
		d[now].second 	= before;
		
		if(now == k)
			break;
		
		for(int i = 0; i < 3; i++){
			int next = (now + dp[i]) << dm[i];
			if(0 <= next && next < MAX){
				q.push({dis+1,{next,now}});
			}
		}
	}
	
	printf("%d\n", d[k].first);
	
	stack<int>ans;
	
	ans.push(k);
	
	while(d[k].second != -1){
		ans.push(d[k].second);
		k = d[k].second;
	}
	
	while(!ans.empty()){
		printf("%d ", ans.top());
		ans.pop();
	}
	
	return 0;
}
