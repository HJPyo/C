#include<stdio.h>
#include<math.h>
#define LL long long

int t;
LL int n, table[10001];

int main()
{
	for(int i = 0; i < 10000; i++){
		table[i] = pow(i+1,3);
	}
	
	scanf("%d", &t);
	while(t--){
		int flag = 0;
		scanf("%lld", &n);
		int L = 0, R = 9999;
		while(L <= R){
			LL int now = table[L] + table[R];
			if(now > n){
				R--;
			}
			else if(now < n){
				L++;
			}
			else{
				flag = 1;
				break;
			}
		}
		printf("%s\n", flag ? "YES" : "NO");
	}
}
