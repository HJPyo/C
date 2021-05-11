#include<iostream>
#include<string.h>
#define MOD 1000000007
#define LL long long int
using namespace std;

int n, k;
LL ar[105], dp[105][1005];

LL f(int x, LL num){
	LL &ret = dp[x][num];
	
	//printf(">>%d %lld\n", x, num);
	
	if(x == n) return (num == k ? 1 : 0);
	if(ret != -1) return ret;
	if(num > 700) return 0;
	ret = 0;
	
	if(num + ar[x] <= 800){
		ret = (ret + f(x+1, num + ar[x])) % MOD;
	}
	if(num - ar[x] >= 0){
		ret = (ret + f(x+1, num - ar[x])) % MOD;
	}
	
	if(x < n-1){
		LL link = ar[x] * 10 + ar[x+1];
		if(num + link <= 800){
			ret = (ret + f(x+2, num + link)) % MOD;
		}
		if(num - link >= 0){
			ret = (ret + f(x+2, num - link)) % MOD;
		}
	}
	
	if(x < n-2){
		LL link = ar[x] * 100 + ar[x+1] * 10 + ar[x+2];
		if(num + link <= 800){
			ret = (ret + f(x+3, num + link)) % MOD;
		}
		if(num - link >= 0){
			ret = (ret + f(x+3, num - link)) % MOD;
		}
	}
	
	return ret;
}

int main(){
	cin >> n >> k;
	
	for(int i = 0; i < n; i++){
		cin >> ar[i];
	}
	
	memset(dp, -1, sizeof(dp));
	cout << f(0, 0);
	
	return 0;
}
