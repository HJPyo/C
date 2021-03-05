#include<stdio.h>

int n, k, ans;

int min(int x, int y)
{
	return x < y ? x : y;
}

int main()
{
	scanf("%d %d", &n, &k);
	
	int L = 1, R = k;
	
	while(L <= R){
		int cnt = 0, M = (L+R) >> 1;
		
		for(int i = 1; i <= n; i++){
			cnt += min(M/i,n);
		}
		
		if(cnt < k){
			L = M+1;
		}
		else{
			ans = M;
			R = M-1;
		}
	}
	
	printf("%d", ans);
	
	return 0;
}
