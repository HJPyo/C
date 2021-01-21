#include<stdio.h>

int n, k, ar[1044][1044];

int main()
{
	scanf("%d %d", &n, &k);
	
	for(int i = 2; i <= n+1; i++){
		for(int j = 2; j <= n+1; j++){
			scanf("%d", &ar[i][j]);
			ar[i][j] += ar[i][j-1] + ar[i-1][j] - ar[i-1][j-1];
		}
	}
	
	while(k--){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", ar[x2+1][y2+1] + ar[x1][y1] - ar[x2+1][y1] - ar[x1][y2+1]);
	}
}
