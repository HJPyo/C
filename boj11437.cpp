#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define MAX 100001
using namespace std;

int n, k, depth, table[MAX] = {-1}, dp[MAX][505];
vector<int>v[MAX];

void GetTree(int x, int parent){
	table[x] = table[parent] + 1;
	dp[x][0] = parent;
	
	for(int i = 1; i <= depth; i++){
		int tmp = dp[x][i-1];
		dp[x][i] = dp[tmp][i-1];
	}
	
	for(int i = 0; i < v[x].size(); i++){
		int next = v[x][i];
		if(next != parent){
			GetTree(next,x);
		}
	}
}

int main(){
	cin >> n;
	
	for(int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	depth = (int)floor(log2(MAX));
	
	GetTree(1,0);
	
	cin >> k;
	
	while(k--){
		int a, b;
		cin >> a >> b;
		
		if(table[a] != table[b]){
			if(table[a] < table[b]) swap(a,b);
			for(int i = depth; i >= 0; i--){
				if(table[b] <= table[dp[a][i]]) a = dp[a][i];
			}
		}
		
		int lca = a;
		
		if(a != b){
			for(int i = depth; i >= 0; i--){
				if(dp[a][i] != dp[b][i]){
					a = dp[a][i];
					b = dp[b][i];
				}
				lca = dp[a][i];
			}
		}
		
		cout << lca << '\n';
	}
}
