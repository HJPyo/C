#include<stdio.h>
#define MOD 1000000007
#define max(x,y) (x > y ? x : y)

int T;

long long int pow(int x)
{
	if(!x) return 1;
	long long int tmp = pow(x>>1);
	return (tmp * tmp * (x % 2+1)) % MOD;
}

int main()
{
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		printf("%lld\n", n < 3 ? 1 : pow(n-2));
	}
}
