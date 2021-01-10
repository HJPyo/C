#include<stdio.h>
#define LL long long

int n;

bool IsPrime(LL int x)
{
	if(x < 2) return false;
	for(LL int i = 2; i*i <= x; i++){
		if(x%i) continue;
		return false;
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	
	while(n--){
		LL int a, b, c;
		scanf("%lld %lld", &a, &b);
		c = a+b;
		if(c>2 && c%2==0) printf("YES\n");
		else if(IsPrime(c-2)) printf("YES\n");
		else printf("NO\n");
	}
}
