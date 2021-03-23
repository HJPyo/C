#include<stdio.h>

int T;
int n, k, query, boss[1000005];

int Find(int x)
{
	return x == boss[x] ? x : boss[x] = Find(boss[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	
	if(x < y) boss[y] = x;
	else boss[x] = y;
	
	return;
}

int main()
{
	scanf("%d", &T);
	
	for(int Case = 1; Case <= T; Case++){		
		scanf("%d %d", &n, &k);
		
		for(int i = 0; i < n; i++){
			boss[i] = i;
		}
		
		for(int i = 0; i < k; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			Union(a,b);
		}
		
		scanf("%d", &query);
		
		printf("Scenario %d:\n", Case);
		
		for(int i = 0; i < query; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			printf("%d\n", Find(a) == Find(b));
		}
		
		puts("");
	}
	
	return 0;
}
