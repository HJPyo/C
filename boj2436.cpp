#include<stdio.h>
#define min(x,y) (x < y ? x : y)
#define LL long long int

LL a, b;

LL gcd(LL x, LL y){
	return x ? gcd(y%x,x) : y;
}

int main(){
	scanf("%lld %lld", &a, &b);
	
	LL x, y;
	
	b /= a;
	
	for(LL i = 1; i*i <= b; i++){
		if(i % b == 0){
			if(gcd(i,i/b) == 1){
				x = i;
				y = i/b;
			}
		}
	}
	
	printf("%lld %lld", x*a, y*a);
}
