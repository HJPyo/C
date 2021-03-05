#include<stdio.h>
#include<vector>
#define MAX 500005
using namespace std;

int prime[MAX] = {1,1};
int n, ar[10005], dp[55][MAX];
vector<int>v;

int main()
{
	for(int i = 2; i < MAX; i++){
		if(prime[i]) continue;
		for(int j = i<<1; j < MAX; j+=i){
			prime[j] = 1;
		}
	}
	
	scanf("%d", &n);
	
	for(int i = 0, j; i < n; i++){
		scanf("%d", &j);
		ar[j]++;
	}
	
	for(int i = 1; i < 10005; i++){
		if(!ar[i]) continue;
		v.push_back(i);
	}
	
	dp[0][0] = 1;
	
	for(int i = 1; i <= v.size(); i++){
		int now = v[i-1];
		for(int j = 0; j < MAX; j++){
			dp[i][j] += dp[i-1][j];
			if(j - now >= 0) dp[i][j] += dp[i-1][j-now];
		}
	}
	
	for(int i = 0; i <= v.size(); i++){
		for(int j = 0; j <= 11; j++){
			printf("%d ", dp[i][j]);
		}
		puts("");
	}
	
	int ans = 0;
	
	for(int i = 2; i <= MAX; i++){
		if(prime[i]) continue;
		ans += dp[n][i];
	}
	
	printf("%d", ans * (ar[0]+1));
}
