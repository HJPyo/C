#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k, vis[55] = {}, cnt = 0;
	vector<int>v[55];
	stack<int>st;
	
	cin >> n;
	for(int i = 0, j; i < n; i++){
		cin >> j;
		if(j != -1){
			v[i].push_back(j);
			v[j].push_back(i);
		}
		else{
			st.push(i);
		}
	}
	cin >> k;
	
	while(!st.empty()){
		int now = st.top();
		st.pop();
		
		
		if(now == k || vis[now]++) continue;
		if(v[now].size() <= 1) cnt++;
		
		for(int i = 0; i < v[now].size(); i++){
			st.push(v[now][i]);
		}
	}
	
	cout << cnt;
	
	return 0;
}
