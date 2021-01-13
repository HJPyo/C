#include<stdio.h>

int n, ar[2002] = {};

int main()
{
	scanf("%d", &n);
	while(n--){
		int tmp = 0;
		scanf("%d", &tmp);
		tmp+=1000;
		ar[tmp] = 1;
	}
	for(int i = 0; i < 2001; i++){
		if(ar[i]){
			printf("%d ", i-1000);
		}
	}
}
