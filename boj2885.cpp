#include<stdio.h>

int n, size, cnt = 0;

int main()
{
	scanf("%d", &n);
	for(size = 1; size < n; size <<= 1);
	
	int cut = size;
	
	while(n != 0){
		while(cut > n){
			cut >>= 1;
			cnt++;
		}
		n -= cut;
	}
	
	printf("%d %d", size, cnt);
}
