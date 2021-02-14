#include<stdio.h>

int n, ar[1001], dp[1001], ans = 0;

int max(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &ar[i]);
	
	for(int i = 0; i < n; i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			if(ar[i] < ar[j] && dp[j]+1 > dp[i]){
				dp[i] = dp[j]+1;
			}
		}
		ans = max(ans, dp[i]);
	}
	
	printf("%d", ans);
}
