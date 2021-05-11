#include<stdio.h>
#include<string.h>
#define MAX 10005

int n, st[MAX], en[MAX], dp[MAX][10], bt[MAX][10];

int f(int x, int spin){
	int &ret = dp[x][spin];
	
	if(ret != -1) return ret;
	if(x == n) return ret = 0;
	ret = 0;
	
	int cnt = (en[x] - st[x] - spin + 20) % 10;
	
	int L = cnt + f(x+1, (spin + cnt) % 10);
	int R = 10 - cnt + f(x+1, spin);
	
	if(L < R){
		ret = L;
		bt[x][spin] = cnt;
	}
	else{
		ret = R;
		bt[x][spin] = -cnt;
	}
	
	return ret;
}

int main(){
	memset(dp, -1, sizeof(dp));
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%1d", &st[i]);
	}
	
	for(int i = 0; i < n; i++){
		scanf("%1d", &en[i]);
	}
	
	int ans = f(0,0), idx = 0;
	
	printf("%d\n", ans);
	
	for(int i = 0; i < n; i++){
		int spin;
		
		if(bt[i][idx] >= 0){
			spin = bt[i][idx];
			idx = (idx + bt[i][idx]) % 10;
		}
		else{
			spin = -bt[i][idx] - 10;
		}
		
		printf("%d %d\n", i+1, spin);
	}
}
