#include<stdio.h>

int T;
long long dp[10001][5];

long long int f(int x, int y){
	if(x < 0) return 0;
	if(x == 1) return 1;
	if(dp[x][y]) return dp[x][y];
	
	for(int i = y; i <= 3; i++){
		dp[x][y] += f(x-i,i);
	}
	
	return dp[x][y];
}

int main(){
	scanf("%d", &T);
	
	while(T--){
		int n;
		scanf("%d", &n);
		long long int tmp = 0;
		for(int i = 1; i <= 3; i++){
			tmp += f(n-i,i);
		}
		printf("%lld\n", tmp);
	}
}
