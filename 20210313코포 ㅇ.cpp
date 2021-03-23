#include<stdio.h>
#define MAX 500001
#define LL long long

LL int n, m, k;
int ar1[MAX], ar2[MAX];

int main()
{
	scanf("%lld %lld %lld", &n, &m, &k);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &ar1[i]);
	}
	
	for(int j = 0; j < m; j++){
		scanf("%d", &ar2[j]);
	}
	
	LL int D = 0;
	
	while(k){
		if(ar1[D % n] != ar2[D % m]) k--;
		D++;
	}
	
	printf("%lld", D);
}
