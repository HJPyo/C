#include<stdio.h>
#include<string.h>

int n, ar[18][18], dp[18][18][5];
int dx[3] = {1,1,0}, dy[3] = {0,1,1};

int f(int x, int y, int pos){
	int &ret = dp[x][y][pos];
	if(x > n || y > n || ar[x+dx[pos]][y+dy[pos]]) return 0;
	if(x == n && y == n) return 1;
	if(ret) return ret;
	
	for(int i = pos-1; i <= pos+1; i++){
		if(pos < 0 || pos > 2) continue;
		ret += f(x+dx[i],y+dy[i],i);
	}
	
	return ret;
}

int main(){
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &ar[i][j]);
		}
	}
	
	printf("%d", f(1,2,2));
}
