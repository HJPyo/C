#include<stdio.h>

int n;
long long int dp[100000001] = {0,1,1};

int main()
{
	scanf("%d", &n);
	if(n < 3){
		printf("%d", dp[n]);
		return 0;
	}
	
	for(int i = 3; i <= n; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	printf("%lld", dp[n]);
}
