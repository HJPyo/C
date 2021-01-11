#include<stdio.h>
#define LL long long

LL int n;
int a = 1, b = 1, c;

int main()
{
	scanf("%lld", &n);
	for(LL int i = 2; i < n; i++){
		c = (a + b) % 1000000;
		b = a;
		a = c;
	}
	printf("%d", a);
}
