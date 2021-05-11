#include<stdio.h>
#include<string.h>
#define MAX 10005

struct dir{
	int cnt, lr;
}bt[MAX][10];

int n, st[MAX], en[MAX], dp[MAX][10];

int f(int x, int spin){
	int &ret = dp[x][spin];
	if(ret != -1) return ret;
	if(x == n) return 0;
	ret = 0;
	
	int cnt = en[x] - (st[x] + spin);
	if(cnt < 0)
		cnt += 10;
	
	int L = cnt + f(x+1, (spin + cnt) % 10);
	int R = 10 - cnt + f(x+1, spin);
	
	if(L < R){
		ret = L;
		bt[x][spin] = {cnt, 1};
	}
	else{
		ret = R;
		bt[x][spin] = {cnt, -1};
	}
	
	return ret;
}

int main(){
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%1d", &st[i]);
	}
	
	for(int i = 0; i < n; i++){
		scanf("%1d", &en[i]);
	}
	
	memset(dp, -1, sizeof(dp));
	
	int ans = f(0,0), idx = 0;
	
	printf("%d\n", ans);
	
	for(int i = 0; i < n; i++){
		dir &now = bt[i][idx];
		printf("%d %d\n", i+1, now.cnt + (now.lr == 1 ? 0 : -10));
		idx = (now.lr > 0 ? (idx + now.cnt) % 10 : idx);
	}
}
