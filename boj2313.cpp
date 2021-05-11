#include<stdio.h>
#define MAX 1000005

int n, dp[33] = {0, 1, 1};

int main(){
	scanf("%d", &n);
	
	for(int i = 3; i <= 33; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	
	int idx = 32;
	
	while(idx > 3){
		printf(">>%d\n", n);
		if(n >= dp[idx]){
			n -= dp[idx];
		}
		idx--;
	}
	
	printf("%d", n);
}
