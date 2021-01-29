#include<stdio.h>
#define LL long long

LL int s, e, ans = 0;
int main()
{
	scanf("%lld %lld", &s, &e);
	for(LL int i = s; i <= e; i++){
		ans += i & -i;
	}
	printf("%lld", ans);
}
