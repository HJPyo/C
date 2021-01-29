#include<stdio.h>

int k, n;

int main()
{
	scanf("%d", &k);
	while(k--){
		scanf("%d", &n);
		int ar[n+1] = {}, vis[n+1] = {}, cyc = 0;
		
		for(int i = 1; i <= n; i++){
			scanf("%d", &ar[i]);
		}
		
		for(int i = 1; i <= n; i++){
			if(vis[i]) continue;
			int now = i;
			vis[now] = 1;
			while(ar[now] != i){
				now = ar[now];
				if(vis[now]){
					cyc--;
					break;
				}
				vis[now] = 1;
			}
			cyc++;
		}
		printf("%d\n", cyc);
	}
}
