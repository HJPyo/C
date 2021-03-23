#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	srand(time(NULL));
	
	int n = 123;
	int m = 321;
	int k = 123456789;
	
	printf("%d %d %d\n", n, m, k);
	
	for(int i = 0; i < n; i++){
		printf("%d ", (rand() % m)+1);
	}
	
	puts("");
	
	for(int i = 0; i < m; i++){
		printf("%d ", (rand() % m)+1);
	}
}
