#include<stdio.h>
#define MAX 50001

int n, ar[MAX];

int main()
{
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		ar[a]++;
	}
	
	int flag, cnt = 0;
	
	for(int i = 1; i < MAX; i++){
		if(cnt < ar[i]) cnt = ar[i];
	} 
	
	printf("%d", cnt);
}
