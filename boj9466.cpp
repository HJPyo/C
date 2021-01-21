#include<iostream>
#include<vector>
using namespace std;

int k, cnt;
vector<int>V;

int dfs(int x, int *ar, int *cyc, int *vis)
{
	if(vis[x]) return x;
	if(cyc[x]) return 0;
	
	vis[x] = 1;
	cyc[x] = 1;
	int top = dfs(ar[x], ar, cyc, vis);
	vis[x] = 0;
	if(top != 0){
		cnt++;
		if(top != x){
			return top;
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;
	while(k--){
		int n; cnt = 0;
		int ar[100001] = {}, cyc[100001] = {}, vis[100001] = {};
		cnt = 0;
		cin >> n;
		
		for(int i = 1; i <= n; i++){
			cin >> ar[i];
		}
		
		for(int i = 1; i <= n; i++){
			dfs(i, ar, cyc, vis);
		}
		
		cout << n-cnt << '\n';
	}
}
