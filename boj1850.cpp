#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

long long int n, m, GCD;

long long int gcd(long long int x, long long int y)
{
	return y ? gcd(y, x%y) : x;
}

int main()
{
	scanf("%lld %lld", &n, &m);
	GCD = gcd(n,m);
	for(int i = 0; i < GCD; i++){
		printf("1");
	}
}
