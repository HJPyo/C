#include<stdio.h>
#define LL long long int

LL a, b, c;

LL f(LL x, LL y)
{
	if(y == 0) return 0;
	if(y == 1) return x;
	if(y&1) return (f(x,y-1) * x) % c;
	LL m = f(x,y>>1) % c;
	return (m*m) % c;
}

int main()
{
	scanf("%lld %lld %lld", &a, &b, &c);
	printf("%lld", f(a,b) % c);
}
