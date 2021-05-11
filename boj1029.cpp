#include<stdio.h>
#include<string.h>

int n, ar[16][16], dp[1<<16][10];

int max(int x, int y){
	return x > y ? x : y;
}

int f(int now, int bit, int val){
	int &ret = dp[bit][val];
	if(ret != -1) return ret;
	ret = 1;
	int tmp = 0;
	
	for(int i = 0; i < n; i++){
		if((bit & (1 << i) != bit) && (val <= ar[now][i])){
			tmp = max(tmp, f(i, bit | (1 << i), ar[now][i]));
		}
	}
	
	return ret += tmp;
}

int main(){
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%1d", &ar[i][j]);
		}
	}
	
	memset(dp, -1, sizeof(dp));
	printf("%d", f(0, 1, 0));
	
	return 0;
}
