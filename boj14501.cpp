#include<stdio.h>
#define INF 999999999

int n, in[1001], out[1001], dp[1001];

int MAX(int x, int y){ return x > y ? x : y; }

int f(int x)
{
	if(x == n) return 0;
	if(dp[x]) return dp[x];
	return dp[x] = MAX(f(x+1), 
		x+in[x] > n ? 0 : 
		f(x+in[x])+out[x]);
}

int main()
{
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d %d", &in[i], &out[i]);
	}
	
	printf("%d", f(0));
}
