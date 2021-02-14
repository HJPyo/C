#include<stdio.h>
#define MAX 303

int n, m, o, ar[MAX][MAX], vis[MAX], ans = 0;

void f(int x)
{
	if(x > n) return;
	for(int i = 1; i <= m; i++){
		if(vis[i] || ar[x][i]) continue;
		if(ans < x) ans = x;
		vis[i] = 1;
		f(x+1);
		vis[i] = 0;
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &o);
	for(int i = 0; i < o; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		ar[x][y] = 1;
	}
	f(1);
	printf("%d", ans);
}
