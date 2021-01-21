#include<stdio.h>

int n, ar[101], cyc[101], cnt = 0;

void f(int x, int y, int* vis)
{
	if(vis[x]){
		if(x == y)
		cyc[cnt++] = y;
		return;
	}
	vis[x] = 1;
	f(ar[x], y, vis);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &ar[i]);
	}
	
	for(int i = 1; i <= n; i++){
		int vis[101] = {};
		f(i,i, vis);
	}
	
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i++){
		printf("%d\n", cyc[i]);
	}
}
