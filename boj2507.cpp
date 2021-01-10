#include<stdio.h>

int k, vis[16], spring[16], orange[16], dp[16][16];

int f(int p1, int p2)
{
	vis[0] = vis[15] = 0;
	
	if(p1 == 15 && p2 == 0) return 1;
	if(dp[p1][p2]) return dp[p1][p2];
	
	for(int i = p1-spring[p1]; i <= p1+spring[p1]; i++){
		if(i < 0 || i > 15 || i == p1) continue;
		if(!spring[i] || vis[i]) continue;
		for(int j = p2-spring[p2]; j <= p2+spring[p2]; j++){
			if(j < 0 || j > 15 || j == p2 || j == i) continue;
			if(!spring[j] || vis[j]) continue;
			if(!orange[j]) continue;
			
			vis[p1] = vis[p2] = 1;
			dp[p1][p2] += f(i,j) % 1000;
			vis[p1] = vis[p2] = 0;
		}
	}
	return dp[p1][p2] % 1000;
}

int main()
{
	scanf("%d", &k);
	while(k--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		spring[a] = b;
		orange[a] = c;
	}
	printf("%d", f(0,15));
 } 
