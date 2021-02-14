#include<stdio.h>
#include<vector>
#define INF 999999999
#define next (x+1) % n
#define up (y-1)
using namespace std;

int n, m, k;
vector<int>one[2];
vector<int>vis[2];
vector<int>dp[2];

int min(int x, int y){ return x < y ? x : y; }

void reset()
{
	for(int i = 0; i < 2; i++){
		one[i].clear();
		vis[i].clear();
		dp[i].clear();
		one[i].resize(n+1,0);
		vis[i].resize(n+1,0);
		dp[i].resize(n+1,INF);
	}
}

int f(int x, int y)
{
	if(x >= n){
		if(y == 0) return f(0,1);
		else return 0;
	}
	
	if(dp[y][x] != INF) return dp[y][x];
	
	int val = 1;
	
	if(y == 0){
		vis[y][x] += 1;
		dp[y][x] = min(val+f(x+1,y),dp[y][x]);
		vis[y][x] -= 1;
		if(one[y][x] + one[y][next] <= m && vis[y][next] < 2){
			if(vis[y][next] == 1) val--;
			vis[y][x] += 2;
			vis[y][next] += 2;
			dp[y][x] = min(val+f(x+2,y),dp[y][x]);
			vis[y][x] -= 2;
			vis[y][next] -= 2;
		}
		return dp[y][x];
	}
	else{
		vis[y][x] += 1;
		dp[y][x] = min(val+f(x+1,y),dp[y][x]);
		vis[y][x] -= 1;
		
		if(one[y][x] + one[y][next] <= m && vis[y][next] < 2){
			if(vis[y][next] == 1) val--;
			vis[y][x] += 2;
			vis[y][next] += 2;
			dp[y][x] = min(val+f(x+2,y),dp[y][x]);
			vis[y][x] = vis[y][next] = 0;
		}
		if(one[y][x] + one[up][x] <= m && vis[up][x] < 2){
			vis[y][x] += 2;
			vis[up][x] += 2;
			dp[y][x] = min(f(x+1,y),dp[y][x]);
			vis[y][x] -= 2;
			vis[up][x] -= 2;
		}
		
		return dp[y][x];
	}
}

int main()
{
	scanf("%d", &k);
	while(k--){
		scanf("%d %d", &n, &m);
		reset();
		
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < n; j++)
				scanf("%d", &one[i][j]);
		
		printf(">>>>>%d<<<<<\n", f(0,0));
	}
}
