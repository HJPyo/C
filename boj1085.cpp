#include<stdio.h>

int main()
{
	int a, b, x, y;
	scanf("%d %d %d %d", &a, &b, &x, &y);
	
	int ans = 999999999;
	
	if(ans > x-a){
		ans = x-a;
	}
	
	if(ans > y-b){
		ans = y-b;
	}
	
	if(ans > a){
		ans = a;
	}
	
	if(ans > b){
		ans = b;
	}
	
	printf("%d", ans);
}
