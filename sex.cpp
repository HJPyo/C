#include<stdio.h>

int n, k, ar[101][101], num = 1;

int main(){
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			ar[k-j-1][i] = num++;
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			printf("%d ", ar[i][j]);
		}
		puts("");
	}
}
