#include<iostream>
#include<vector>
#include<stack>
#define MAX 100001
using namespace std;

void dfs(int x, vector<int> vis, vector<vector<int>> v, stack<int> st){
	vis[x] = 1;
	for(int i = 0; i < v[x].size(); i++){
		int next = v[x][i];
		if(!vis[next]){
			dfs(x,vis,v,st);
		}
	}
	st.push(x);
	return;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	
	cin >> T;
	
	while(T--){
		int n, k;
		cin >> n >> k;
		
		stack<int>st;
		vector<int>vis(n+1,0);
		vector<vector<int>>v(n+1,vector<int>());
		
		for(int i = 0; i < k; i++){
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
		}
		
		dfs(1,vis,v,st);
		
		while(!st.empty()){
			cout << st.top() << '\n';
			st.pop();
		}
	}
}
