#include<stdio.h>

int n, m, k, dp[33][80005], chk[80005];

int main(){
	scanf("%d", &n);
	
	dp[0][40000] = 1;
	
	for(int i = 0; i < n; i++){
		int now;
		scanf("%d", &now);
		
		for(int j = 20000; j <= 60000; j++){
			if(dp[i][j] == 1){
				dp[i+1][j-now] = dp[i+1][j] = dp[i+1][j+now] = 1;
				chk[j-now] = chk[j] = chk[j+now] = 1;
			}
		}
	}
	
	scanf("%d", &k);
	
	while(k--){
		scanf("%d", &m);
		printf("%c ", chk[m+40000] == 1 ? 'Y' : 'N');
	}
	
	return 0;
}
