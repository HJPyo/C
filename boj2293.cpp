#include<stdio.h>

int n, k, ar[101], dp[10001];

int main()
{
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &ar[i]);
	}
	
	dp[0] = 1;
	
	for(int i = 1; i <= n; i++){
		int now = ar[i];
		for(int j = 0; j <= k; j++){
			if(j - now >= 0){
				dp[j] += dp[j-now];
			}
		}
	}
	
	printf("%d", dp[k]);
}
