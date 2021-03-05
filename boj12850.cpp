#include<stdio.h>
#define MOD 1000000007

int n;

int ar[10];
long long int tmp[10];

void f()
{
	tmp[1] = ar[2] + ar[3];
	tmp[2] = ar[1] + ar[3] + ar[4];
	tmp[3] = ar[1] + ar[2] + ar[4] + ar[5];
	tmp[4] = ar[2] + ar[3] + ar[5] + ar[6];
	tmp[5] = ar[3] + ar[4] + ar[6] + ar[7];
	tmp[6] = ar[4] + ar[5] + ar[8];
	tmp[7] = ar[5] + ar[8];
	tmp[8] = ar[6] + ar[7];
	for(int i = 1; i <= 8; i++){
		ar[i] = tmp[i] % MOD;
	}
}

int main()
{
	ar[1] = 1;
	scanf("%d", &n);
	while(n--) f();
	printf("%d", ar[1]);
}
