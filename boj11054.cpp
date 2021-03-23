#include<stdio.h>
#define max(x,y) (x > y ? x : y)
#define min(x,y) (x < y ? x : y)

int n, ar1[1001], ar2[1001];
int dp1[1001], dp2[1001];

int main()
{
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &ar1[i]);
		ar2[n-i-1] = ar1[i];
	}
	
	for(int i = 0; i < n; i++){
		dp1[i] = 1;
		for(int j = 0; j < i; j++){
			if(ar1[i] > ar1[j] && dp1[j]+1 > dp1[i]){
				dp1[i] = dp1[j]+1;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		dp2[i] = 1;
		for(int j = 0; j < i; j++){
			if(ar2[i] > ar2[j] && dp2[j]+1 > dp2[i]){
				dp2[i] = dp2[j]+1;
			}
		}
	}
	/*
	for(int i = 0; i < n; i++){
		printf("%d ", dp1[i]);
	}
	puts("");
	for(int j = 0; j < n; j++){
		printf("%d ", dp2[j]);
	}
	*/
	int ans = 0;
	
	for(int i = 0; i < n; i++){
		ans = max(ans,dp1[i]+dp2[n-i-1]);
	}
	
	printf("%d", ans-1);
}
