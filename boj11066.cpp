#include<stdio.h>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	
	int gcd = [](int x, int y){
		while(y){
			int tmp = y;
			y = x%y;
			x = tmp;
		}
		return x;
	}(a,b);
	
	printf("%d\n%d", gcd, a*b/gcd);
}
