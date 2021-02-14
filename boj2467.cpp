#include<stdio.h>
#include<math.h>

int n, ar[100001];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; scanf("%d", &ar[i++]));
	
	int L = 1, R = n, ans = (1<<31)-1;
	int l1, l2;
	while(L < R){
		int now = ar[L]+ar[R];
		if(abs(now) < ans){
			ans = abs(now);
			l1 = ar[L];
			l2 = ar[R];
		}
		
		if(now <= 0) L++;
		else R--;
	}
	printf("%d %d", l1, l2);
}
