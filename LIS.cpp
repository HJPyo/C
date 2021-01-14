#include<stdio.h>
#define INF -1111111111

int n, ar[1000001], dp[1000001], lis[1000001];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &ar[i]);
		lis[i] = INF;
	}
	
	for(int i = 1; i <= n; i++){
		int low = 1;
		while(lis[low] != INF && ar[i] > lis[low]) low++;
		lis[low] = ar[i];
		dp[i] = low;
	}
	
	int Max = -1;
	for(int i = 1; i <= n; i++){
		if(Max < dp[i]) Max = dp[i];
	}
	
	printf("%d", Max);
}
