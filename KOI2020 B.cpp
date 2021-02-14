#include<stdio.h>
#include<math.h>

int n, now = 1, cnt = 1, ar[300003];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &ar[i]);
	}
	for(int i = 2; i <= n; i++){
		if(now == 1){
			if(ar[i-1] > ar[i]){
				cnt++;
				now = 0;	
			}
		}
		else{
			if(ar[i-1] < ar[i]){
				cnt++;
				now = 1;
			}
		}
	}
	printf("%d", (int)ceil(log2(cnt)));
}
