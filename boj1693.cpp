#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 100001
#define INF 1<<30
#define int long long
using namespace std;

int n, dp[MAX][33], vis[MAX];
vector<int>v[MAX];

int f(int x, int y)
{
	if(dp[x][y]) return dp[x][y];
	
	int val = 0;
	
	for(int i = 0; i < v[x].size(); i++){
		int tmp = INF;
		int next = v[x][i];
		if(vis[next] == 0){
			for(int j = 1; j <= 30; j++){
				if(j != y) tmp = min(tmp,f(next,j));
			}
		}
		val += tmp;
	}
	
	return dp[x][y] = (val + y);
}

main()
{
	cin >> n;
	
	for(int i = 0; i < n-1; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	int ans = INF;
	
	for(int i = 1; i <= 30; i++){
		ans = min(ans,f(1,i));
	}
	
	cout << ans;
}
