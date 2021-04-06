#include<stdio.h>
#define INF 999999999
#define min(x,y) (x < y ? x : y)
#define max(x,y) (x > y ? x : y)

int n, ar[55][55];

int main(){
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		char tmp[55];
		scanf("%s", &tmp);
		for(int j = 0; j < n; j++){
			ar[i][j] = (tmp[j] == 'Y' ? 1 : INF);
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			for(int k = 0; k < n; k++){
				if(i == k || j == k) continue;
				ar[i][k] = min(ar[i][k], ar[i][j] + ar[j][k]);
			}
		}
	}
	
	int ans = 0;
	
	for(int i = 0; i < n; i++){
		int tmp = 0;
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			if(ar[i][j] <= 2) tmp++;
		}
		ans = max(ans,tmp);
	}
	
	printf("%d", ans);
}
