#include<stdio.h>

void f(int x, int y, int *ar, int *tmp)
{
	if(x == 6){
		for(int i = 0; i < 6; i++){
			printf("%d ", tmp[i]);
		}
		puts("");
		return;
	}
	if(ar[y] == 0) return;
	
	for(int i = y; ar[i] != 0; i++){
		tmp[x] = ar[i];
		f(x+1,i+1,ar,tmp);
	}
}

int main()
{
	while(1){
		int n, ar[15] = {}, tmp[15] = {};
		scanf("%d", &n);
		if(n == 0) return 0;
		for(int i = 0; i < n; i++){
			scanf("%d", &ar[i]);
		}
		f(0,0,ar,tmp);
		puts("");
	}
}
