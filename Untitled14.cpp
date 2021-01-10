#include<stdio.h>
#define MOD 10000000

int n, m;
bool ar[20000002];

int main()
{
	scanf("%d", &n);
	while(n--){
		scanf("%d", &m);
		ar[m+MOD] = true;
	}
	
	scanf("%d", &n);
	while(n--){
		scanf("%d", &m);
		printf("%d ", ar[m+MOD]);
	}
}
