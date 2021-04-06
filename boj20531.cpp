#include<stdio.h>
#define MOD 1000000007
#define LL long long

LL int n, k, dp[5005][5005], table[5005], boss[5005];

int Find(int x){
	if(x == boss[x]) return x;
	else return boss[x] = Find(boss[x]);
}

void Union(int x, int y){
	x = Find(x);
	y = Find(y);
	if(x != y) boss[x] = y;
}

int main(){
	scanf("%lld %lld", &n, &k);
	
	for(int i = 1; i <= n; i++){
		dp[i][1] = 1;
		boss[i] = i;
	}
	
	for(int i = 2; i <= n; i++){
		for(int j = 2; j <= i; j++){
			dp[i][j] = (dp[i-1][j] * j + dp[i-1][j-1]) % MOD;
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			table[i] = (table[i] + dp[i][j]) % MOD;
		}
	}
	
	while(k--){
		int a, b;
		scanf("%d %d", &a, &b);
		if(Find(a) != Find(b)){
			Union(a,b);
			n--;
		}
		printf("%lld\n", table[n]);
	}
}
