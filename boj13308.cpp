#include<iostream>
#include<vector>
#include<queue>
#define INF 999999999
using namespace std;

struct inqueue{
	int cost, sum, idx;
	vector<int>vis;
};

struct cmp{
	bool operator()(inqueue x, inqueue y){
		return x.sum < y.sum;
	}
};

int n, k;
int gas[2505];
vector<vector<int>>cost(2505, vector<int>(2, INF));
vector<pair<int,int>>v[4005];
priority_queue<inqueue, vector<inqueue>, cmp>pq;

int f(){
	vector<int>tmp(n+1, 0);
	tmp[1] = 1;
	pq.push({gas[1], 0, 1, tmp});
	
	while(!pq.empty()){
		int cost = pq.top().cost;
		int sum = pq.top().sum;
		int now = pq.top().idx;
		vector<int>vis = pq.top().vis;
		pq.pop();
		
		
	}
}

int main(){
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++){
		cin >> gas[i];
	}
	
	for(int i = 1; i <= k; i++){
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}
	
	printf("%d", f());
	
	return 0;
}
