#include<stdio.h>

void f(int x, int a, int b, int c)
{
	if(x == 1){
		printf("%d %d\n", a, c);
	}
	else{
		f(x-1, a, c, b);
		printf("%d %d\n", a, c);
		f(x-1, b, a, c);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", (1<<n)-1);
	f(n,1,2,3);
}
