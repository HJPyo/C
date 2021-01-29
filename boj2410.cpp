#include<stdio.h>
#include<math.h>
#define MOD 1000000000

int n, dp[1000001];

int f(int x, int i)
{
	if(x < 0) return 0;
	if(x == (x & -x)) return log2(x)+1;
	
	int next = i << 1;
	return dp[x] = (f(x-i,i) + f(x-next,next)) % MOD;
}

int main()
{
	scanf("%d", &n);
	printf("%d", f(n,1));
}
