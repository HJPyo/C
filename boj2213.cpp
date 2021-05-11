#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define MAX 10005
using namespace std;

int n, val[MAX], vis[MAX], dp[MAX][2];
vector<int>v[MAX];

int f(int x, int before){
	int& ret = dp[x][before];
	if(ret != -1) return ret;
	
	ret = 0;
	vis[x] = 1;
	
	for(int i = 0; i < v[x].size(); i++){
		int next = v[x][i];
		if(!vis[next]){
			if(!before) ret = max(ret,f(next,1)+val[x]);
			ret = max(ret,f(next,0));
		}
	}
	
	vis[x] = 0;
	return ret;
}

int main(){
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		scanf("%d", &val[i]);
	}
	
	for(int i = 0; i < n-1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	memset(dp, -1, sizeof(dp));
	printf("%d", f(1,0));
	return 0;
}
