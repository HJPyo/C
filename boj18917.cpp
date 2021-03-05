#include<stdio.h>

int t;

int main()
{
	long long int SUM = 0, XOR = 0;
	scanf("%d", &t);
	while(t--){
		int a, b;
		scanf("%d", &a);
		if(a < 3)
			scanf("%d", &b);
			
		if(a == 1){
			SUM += (long long int)b;
			XOR ^= (long long int)b;
		}
		else if(a == 2){
			SUM -= (long long int)b;
			XOR ^= (long long int)b;
		}
		else if(a == 3){
			printf("%lld\n", SUM);
		}
		else{
			printf("%lld\n", XOR);
		}
	}
}
