#include<stdio.h>

int n, k, ar[20], cnt = 0;

void f(int x, int y)
{
	if(x == n) return;
	if(y+ar[x] == k) cnt++;
	f(x+1,y);
	f(x+1,y+ar[x]);
}

int main()
{
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; scanf("%d", &ar[i++]));
	f(0,0);
	printf("%d", cnt);
}
