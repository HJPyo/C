#include<stdio.h>
#include<algorithm>
#define MAX 1000005
#define INF 1999999999
using namespace std;

int n, ar[MAX], dp[MAX];

int main(){
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &ar[i]);
		dp[i] = -INF;
	}
	
	int idx = 0;
	
	for(int i = 0; i < n; i++){
		int now = lower_bound(dp, dp+idx, ar[i]) - dp;
		dp[now] = ar[i];
		if(now == idx){
			idx++;
		}
	}
	
	printf("%d", idx);
	
	return 0;
}
