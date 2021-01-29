#include<stdio.h>
#define MOD 1000000

int n, dp[1001][2][3];

int f(int day, int late, int out)
{
	if(late == 2 || out == 3) return 0;
	if(day == 0) return 1;
	if(dp[day][late][out]) return dp[day][late][out];
	return dp[day][late][out] = 
		(f(day-1, late, 0) + f(day-1, late+1, 0) + f(day-1, late, out+1)) % MOD;
}

int main()
{
	scanf("%d", &n);
	printf("%d", f(n,0,0));
}
