#include<stdio.h>

const int f();

const int a = f(), b = f(), c = f(), d = f(), e = f();

const int f()
{
	printf("%d %d %d %d %d\n", a, b, c, d, e);
	return a + b + c + d + e + 1;
}

int main()
{
	printf("%d %d %d %d %d\n", a, b, c, d, e);
}
