#include<stdio.h>
#define LL long long

LL int n, dp[41] = {8, 6, 14};
char Messi[7] = " Messi", Gimossi[9] = " Gimossi";

void f(int x)
{
	if(x < 2 || dp[x]) return;
	f(x-1);
	f(x-2);
	dp[x] = dp[x-1] + dp[x-2];
}

int main()
{
	f(40);
	scanf("%lld", &n);
	
	for(int i = 40; i > 1; i--)
	if(n-dp[i] >= 0) n-=dp[i];
	if(n-dp[1] >= 0){
		n-=dp[1]; dp[0] = 123;
	}
	
	if(n == 0){
		printf("Messi Messi Gimossi");
	}
	else{
		if(dp[0] == 123){
			printf("%c", Gimossi[n]);
		}
		else{
			printf("%c", Messi[n]);
		}
	}
}
