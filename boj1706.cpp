#include<stdio.h>
#include<string.h>

int n, ar[35][35];
long long int dp[35][35][3];

long long int f(int x, int y, int type){
	long long int &ret = dp[x][y][type];
	
	if(ret != -1) return ret;
	if(x == n || y == n) return 0;
	if(x == n-1 && y == n-1) return 1;
	ret = 0;
	
	if((type == 0 || type == 1) && ar[x][y+1] == 0){
		ret += f(x, y+1, 0);
	}
	if((type == 1 || type == 2) && ar[x+1][y] == 0){
		ret += f(x+1, y, 2);
	}
	if(ar[x][y+1] == 0 && ar[x+1][y+1] == 0 && ar[x+1][y] == 0){
		ret += f(x+1, y+1, 1);
	}
	
	return ret;
}

int main(){
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &ar[i][j]);
		}
	}
	
	memset(dp, -1, sizeof(dp));
	printf("%lld", f(0, 1, 0));
}
