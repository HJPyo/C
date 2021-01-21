#include<stdio.h>

int n, k, dp[100001];

int f(int x)
{
	if(x < 0) return 0;
	if(x == 0) return 1;
	if(dp[x]) return dp[x];
	
	for(int i = x-3; i > 0; i-=2){
		dp[x] += 2*f(i);
	}
	
	return dp[x] += 1 + f(x-1) + 5 + f(x-2);
}

int main()
{
	scanf("%d", &k);
	while(k--){
		scanf("%d", &n);
		printf("%d\n", f(n));
	}
}
