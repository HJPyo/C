#include<stdio.h>
#include<string.h>
#include<vector>
#define MAX 10001
#define max(x,y) (x > y ? x : y)
using namespace std;

int n, town[MAX], dp[MAX][2][2], vis[MAX];
vector<int>v[MAX];

int f(int x, int y, int z)
{
	if(dp[x][y][z] != -1) return dp[x][y][z];
	
	vis[x] = 1;
	
	int tmp = 0;
	
	if(y == 1 || z != 1){
		for(int i = 0; i < v[x].size(); i++){
			int next = v[x][i];
			if(vis[next] == 0){
				tmp += f(next,0,0);
			}
		}
		dp[x][y][z] = tmp;
	}
	
	tmp = 0;
	
	if(y == 0){
		for(int i = 0; i < v[x].size(); i++){
			int next = v[x][i];
			if(vis[next] == 0){
				tmp += f(next,1,z+1);
			}
		}
		dp[x][y][z] = max(dp[x][y][z],tmp + town[x]);
	}
	
	vis[x] = 0;
	
	return dp[x][y][z];
}

int main()
{
	memset(dp, -1, sizeof(dp));
	
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		scanf("%d", &town[i]);
	}
	
	for(int i = 0; i < n-1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	printf("%d", f(1,0,0));
}
