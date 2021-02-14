#include<stdio.h>

int n, k, cnt = 0;

int main()
{
	scanf("%d %d", &n, &k);
	
	for(int i = k; i > 0; i--){
		n -= i;
		cnt++;
		if(n < 0){
			printf("-1\n");
			return 0;
		}
	}
	
	printf("%d\n", cnt+(n % k == 0 ? 0 : 1)-1);
}
