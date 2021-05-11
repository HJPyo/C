#include<stdio.h>
#include<string.h>

int n, k, ar[105];
long long int dp[105][22];

long long int f(int x, int num){
	long long int &ret = dp[x][num];
	if(x == n) return num == k;
	if(ret != -1) return ret;
	ret = 0;
	if(num+ar[x] <= 20){
		ret += f(x+1, num+ar[x]);
	}
	if(num-ar[x] >= 0){
		ret += f(x+1, num-ar[x]);
	}
	return ret;
}

int main(){
	scanf("%d", &n);
	n--;
	for(int i = 0; i < n; i++){
		scanf("%d", &ar[i]);
	}
	scanf("%d", &k);
	memset(dp, -1, sizeof(dp));
	printf("%lld", f(0, 0));
	return 0;
}
