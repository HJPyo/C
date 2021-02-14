#include<stdio.h>

long long int n, m;
long double ans = 1;

long long int min(long long int x, long long int y)
{
	return x < y ? x : y;
}

int main()
{
	scanf("%lld %lld", &n, &m);
	m = min(m, n-m);
	for(int i = 0; i < m; i++){
		ans *= (double)n-i;
		ans /= (double)m-i;
	}
	printf("%lld", (long long int)ans);
}
