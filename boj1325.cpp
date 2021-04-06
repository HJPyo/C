#include<stdio.h>
#include<string.h>
#include<vector>
#define max(x,y) (x > y ? x : y)
using namespace std;

int n, k, dp[10005], vis[10005];
vector<int>v[10005];

int f(int x){
	if(dp[x] != -1) return dp[x];
	dp[x] = 0;
	
	int tmp = 0;
	vis[x] = 1;
	
	for(int i = 0; i < v[x].size(); i++){
		int next = v[x][i];
		if(vis[next] == 0){
			tmp += f(next);
		}
	}
	
	vis[x] = 0;
	return dp[x] = tmp + 1;
}

int main(){
	memset(dp, -1, sizeof(dp));
	
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < k; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[b].push_back(a);
	}
	
	int ans = -1;
	
	for(int i = 1; i <= n; i++){
		int now = f(i);
		ans = max(ans,now);
		memset(vis, 0, sizeof(vis));
	}
	
	for(int i = 1; i <= n; i++){
		if(ans == dp[i]) printf("%d ", i);
	}
}
