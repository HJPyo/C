#include<stdio.h>

int n, k, ans = 0, boss[500005];

int Find(int x)
{
	if(boss[x] == x) return x;
	return boss[x] = Find(boss[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if(x != y) boss[x] = y;
}

int main()
{
	scanf("%d %d", &n, &k);
	for(int i = 0; i <= n; i++){
		boss[i] = i;
	}
	for(int i = 1; i <= k; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		if(Find(a) != Find(b)) Union(a, b);
		else{ ans = i; break; }
	}
	printf("%d", ans);
}
