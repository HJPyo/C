#include<stdio.h>
#include<vector>
#define INF 99999999
using namespace std;

int n, k;
vector<int>tree[101];
vector<vector<int> >dp(101,vector<int>(21,-1));

int min(int x, int y)
{
	return x < y ? x : y;
}

int f(int x, int y, int z)
{
	if(z > k) return INF;
	if(x == n) return 0;
	if(dp[x][y] != -1) return dp[x][y];
	
	
}

int main()
{
	scanf("%d %d", &n, &k);
	for(int i = 0, hole, tmp; i < n; i++){
		scanf("%d", &hole);
		while(hole--){
			scanf("%d", &tmp);
			tree[i].push_back(tmp);
		}
	}
	
	printf("%d", f(0,1,0));
}
