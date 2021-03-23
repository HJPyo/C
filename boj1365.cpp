#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAX 200005
using namespace std;

int n, ar[MAX], dp[MAX];

int main()
{
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &ar[i]);
	}
	
	int len = 0;
	
	for(int i = 0; i < n; i++){
		int now = ar[i];
		int idx = lower_bound(dp,dp+len,now) - dp;
		if(idx == len){
			dp[idx] = now;
			len++;
		}
		else{
			dp[idx] = now;
		}
	}
	
	printf("%d", n-len);
}
