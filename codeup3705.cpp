#include<stdio.h>

int n, ar[100001], dp[100001], ans;

int max(int x, int y) {	return x > y ? x : y; }

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &ar[i]);
	ans = dp[0] = ar[0];
	for(int i = 1; i < n; i++){
		dp[i] = max(0, dp[i-1]) + ar[i];
		ans = max(ans, dp[i]);
	}
	printf("%d", ans);
}
