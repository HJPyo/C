#include<stdio.h>

int x, y = 1, k;

int main()
{
	scanf("%d %d", &x, &k);
	
	for(int cnt = 0; cnt < k; y++){
		if(x|y == x+y) cnt++;
	}
	
	printf("%d", y);
}
