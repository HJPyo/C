#include<stdio.h>

int n, m, ar[11], cnt = 0;;

int main()
{
	scanf("%d %d", &n, &m);
	
	for(int i = n; i > 0; i--){
		scanf("%d", &ar[i]);
	}
	
	for(int i = 1; i <= n; i++){
		while(ar[i] <= m){
			m-=ar[i];
			cnt++;
		}
	}
	
	printf("%d", cnt);
}
