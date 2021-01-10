#include<stdio.h>
#define Val 1000000009

int k;
unsigned int dp[1000001];

unsigned int f(int x)
{
	if(x < 0) return 0;
	if(x == 0) return 1;
	if(dp[x]) return dp[x];
	
	return dp[x] = (f(x-1) + f(x-2) + f(x-3)) % Val;
}

int main()
{
	scanf("%d", &k);
	while(k--){
		int n;
		scanf("%d", &n);
		printf("%u\n", f(n));
	}
}
