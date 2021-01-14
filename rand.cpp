#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	srand(time(NULL));
	int n = rand()%100000 + 1;
	printf("%d\n", n);
	for(int i = 0; i < n; i++){
		printf("%d\n", rand()%100000 + 1);
	}
}
