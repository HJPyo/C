#include<stdio.h>

int n, k;

int gcd(int x, int y)
{
	return y ? gcd(y,x%y) : x;
}

int main()
{
	int ans1 = 0, ans2;
	int GCD = 0, LCM = 0;
	
	scanf("%d %d", &n, &k);
	
	for(int N = 1; N <= n; N++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				int a = gcd(i,j);
				int b = i*j / a;
				ans1 = (ans1 + (a*b)) % k;
				GCD = (GCD + a) % k;
				LCM = (LCM + b) % k;
			}
		}
	}
	
	ans2 = (GCD * LCM) % k;
	
	printf("%d\n%d", ans1, ans2);
}
