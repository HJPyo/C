#include<stdio.h>

int n, ar[501][501], ans = -1;

int Max(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			scanf("%d", &ar[i][j]);
		}
	}
	
	for(int i = 1; i < n; i++){
		for(int j = 0; j <= i; j++){
			if(j == 0){
				ar[i][j] += ar[i-1][j];
			}
			else{
				ar[i][j] += Max(ar[i-1][j], ar[i-1][j-1]);
			}
			ans = Max(ans, ar[i][j]);
		}
	}
	
	printf("%d", ans);
}
