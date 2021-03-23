#include<stdio.h>
#define min(x,y) (x < y ? x : y)

int n, cnt = 0, dp[100001];

int main()
{
	scanf("%d", &n);
	
	for(int i = 0; i <= 100000; i++){
		dp[i] = 999999999;
	}
	
	dp[0] = 0;
	
	for(int i = n; i > 0; i--){
		int I = i*i;
		if(I > n) continue;
		for(int j = 1; j*I <= n; j++){
			int J = j*I;
			dp[J] = min(dp[J-I]+1,j);
		}
	}
	
	printf("%d", dp[n]);
}
