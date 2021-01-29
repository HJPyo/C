#include<stdio.h>
using P = pair<int,int>

int n, k, dp[101][100001];
P ar[101];

int main()
{
	scanf("%d %d", &n, &k);
	for(int i = 1, a, b; i <= n; i++){
		scanf("%d %d", a, b);
		ar[i] = {a,b};
	}
	
	
}
