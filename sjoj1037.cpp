#include<stdio.h>
#include<string.h>
#define int long long int
#define MOD 1000000007

int n, k, ar[105], dp[105][1005];

int link(int x, int y){
	int shift = 1;
	while(shift <= y){
		shift *= 10;
	}
	return (x * shift) + y;
}

int f(int idx, int num){
	//printf(">>%d %d %d\n", idx, num);
	
	if(idx == n) return num == k ? 1 : 0;
	if(num < 0 || num > 700) return 0;
	
	int &ret = dp[idx][num];
	if(ret != -1) return ret;
	ret = 0;
	
	ret = (ret + f(idx+1, num + ar[idx])) % MOD;
	ret = (ret + f(idx+1, num - ar[idx])) % MOD;
	
	if(idx < n-2){
		int linked = link(ar[idx], ar[idx+1]);
		ret = (ret + f(idx+2, num + linked)) % MOD;
		ret = (ret + f(idx+2, num - linked)) % MOD;
	}
	
	if(idx < n-3){
		int linked = link(ar[idx], link(ar[idx+1], ar[idx+2]));
		if(linked <= 700){
			ret = (ret + f(idx+3, num + linked)) % MOD;
			ret = (ret + f(idx+3, num - linked)) % MOD;
		}
	}
	
	return ret;
}

main(){
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &ar[i]);
	}
	
	memset(dp, -1, sizeof(dp));
	printf("%lld", f(0, 0)); 
}
