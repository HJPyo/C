#include<stdio.h>
#include<vector>
#include<algorithm>
#define INF 987654321
using namespace std;

int n;
vector<int>ar(1555,INF);
vector<int>dp(1555,INF);

int main()
{
	dp[0] = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &ar[i]);
		for(int j = 0; j < ar[i]; j++){
			int next = i+j+1;
			dp[next] = min(dp[next],dp[i]+1);
		}
	}
	printf("%d ", (dp[n-1] == INF) ? -1 : dp[n-1]);
}
