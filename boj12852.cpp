#include<stdio.h>
#define MAX 1000000

int n, dp[MAX+1], ans[MAX+1];

int main()
{
	scanf("%d", &n);
	
	dp[1] = 0;
	ans[1] = -1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i-1] + 1;
		ans[i] = i-1;
		if (i%2 == 0 && dp[i] > dp[i/2] + 1) {
			dp[i] = dp[i/2] + 1;
			ans[i] = i/2;
		}
		if (i%3 == 0 && dp[i] > dp[i/3] + 1) {
			dp[i] = dp[i/3] + 1;
			ans[i] = i/3;
		}
	}
	
	printf("%d\n", dp[n]);
	for(int i = n; i != -1; i = ans[i]){
		printf("%d ", i);
	}
}
