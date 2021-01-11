#include<stdio.h>
#define INF 1999999999
#define LL long long 

int n, oil[100001], dis[100001];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		scanf("%d", &dis[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &oil[i]);
	}
	
	LL int cost = 0, Now = 0, Loil = INF;
	
	for(int i = 0; i < n-1; i++){
		if(Loil > oil[i]) Loil = oil[i];
		cost += dis[i+1] * Loil;
	}
	printf("%lld", cost);
}
