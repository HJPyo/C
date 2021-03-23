#include<stdio.h>
#include<vector>
#define MAX 1000001
#define min(x,y) (x < y ? x : y)
#define max(x,y) (x > y ? x : y)
using namespace std;

int n, dp[MAX][2], vis[MAX];
vector<int>v[MAX];

int f(int x, int y)
{
	if(dp[x][y]) return dp[x][y];
	
	vis[x] = 1;
	int tmp1 = 1, tmp2 = 0;
	
	for(int i = 0; i < v[x].size(); i++){
		int next = v[x][i];
		if(!vis[next]){
			tmp1 += f(next,1);
		}
	}
	
	if(!y){
		vis[x] = 0;
		return dp[x][y] = tmp1;
	}
	
	for(int i = 0; i < v[x].size(); i++){
		int next = v[x][i];
		if(!vis[next]){
			tmp2 += f(next,0);
		}
	}
	
	vis[x] = 0;
	
	return dp[x][y] = min(tmp1,tmp2);
}

int main()
{
	scanf("%d", &n);
	
	for(int i = 0; i < n-1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	printf("%d", f(1,1));
	
	return 0;
}
