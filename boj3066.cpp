#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int T,n;
	
	scanf("%d", &T);
	
	while(T--){
		scanf("%d", &n);
		int ar[n+1] = {};
		int dp[n+1] = {};
		
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
		
		printf("%d\n", len);
	}
}
