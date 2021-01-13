#include<stdio.h>

int n, s, e, vol[101], dp[101][1001], ans = -1;

int Max(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	scanf("%d %d %d", &n, &s, &e);
	for(int i = 0; i < n; i++){
		scanf("%d", &vol[i]);
	}
	dp[0][s] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= e; j++){
			if(dp[i-1][j] == 1){
				if(j+vol[i] <= e){
					dp[i][j+vol[i]] = 1;
				}
				if(j-vol[i] >= 0){
					dp[i][j-vol[i]] = 1;
				}
			}
		}
	}
	
	for(int i = 0; i <= e; i++){
		if(dp[1][i]){
			ans = i;
		}
	}
	printf("%d", ans);
}
