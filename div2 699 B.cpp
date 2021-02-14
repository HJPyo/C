#include<stdio.h>

int t;

int main()
{
	scanf("%d", &t);
	while(t--){
		int n, k, ar[111] = {}, ans;
		scanf("%d %d", &n, &k);
		for(int i = 1; i <= n; i++){
			scanf("%d", &ar[i]);
		}
		
		for(int i = 0, j; i < k; i++){
			for(j = 1; j <= n+1; j++){
				if(ar[j] < ar[j+1]) break;
				if(j > n){
					ans = -1;
					goto END;
				}
			}
			ar[j]++;
			ans = j;
		}
		
		END:
		
		printf("%d\n", ans);
	}
}
