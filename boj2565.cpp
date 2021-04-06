#include<stdio.h>
#include<algorithm>
using namespace std;

struct st{
	int a, b;
}ar[505];

int main(){
	int n, dp[505] = {};
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d %d", &ar[i].a, &ar[i].b);
	}
	
	sort(ar,ar+n,[](st x, st y){
		return x.a < y.a;
	});
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		int idx = lower_bound(dp,dp+ans,ar[i].b) - dp;
		dp[idx] = ar[i].b;
		if(idx == ans){
			ans++;
		}
	}
	
	printf("%d", n-ans);
}
