#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 1005

struct xypos{
	int x, y;
}ar[MAX];

int n, k, dp[MAX][MAX], bt[MAX][MAX];

int dist(xypos A, xypos B){
	return abs(A.x - B.x) + abs(A.y - B.y);
}

int min(int x, int y){
	return x < y ? x : y;
}

int f(xypos A, xypos B, int x, int y, int idx){
	int &ret = dp[x][y];
	
	if(ret != -1) return ret;
	if(idx > k) return 0;
	
	int Adis = dist(A, ar[idx-1]);
	int Bdis = dist(B, ar[idx-1]);
	int Ago = Adis + f(ar[idx-1], B, idx, y, idx+1);
	int Bgo = Bdis + f(A, ar[idx-1], x, idx, idx+1);
	
	if(Ago < Bgo){
		ret = Ago;
		bt[x][y] = 1;
	}
	else{
		ret = Bgo;
		bt[x][y] = 2;
	}
	
	return ret;
}

int main(){
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < k; i++){
		scanf("%d %d", &ar[i].x, &ar[i].y);
	}
	
	memset(dp, -1, sizeof(dp));
	
	int ans = f({1,1},{n,n},0,0,1), iA = 0, iB = 0;
	
	printf("%d\n", ans);
	
	for(int i = 1; i <= k; i++){
		printf("%d\n", bt[iA][iB]);
		
		if(bt[iA][iB] == 1){
			iA = i;
		}
		else{
			iB = i;
		}
	}
	
	return 0;
}
