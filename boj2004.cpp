#include<stdio.h>

int n, m;

int min(int x, int y)
{
	return x < y ? x : y;
}

int main()
{
	scanf("%d %d", &n, &m);
	m = min(n-m,m);
	int cnt2 = 0, cnt5 = 0;
	for(int i = n; i > n-m; i--){
		int now = i;
		while(now % 2 == 0){
			cnt2++; now >>= 1;
		}
		while(now % 5 == 0){
			cnt5++; now /= 5;
		}
	}
	for(int i = m; i > 1; i--){
		int now = i;
		while(now % 2 == 0){
			cnt2--; now >>= 1;
		}
		while(now % 5 == 0){
			cnt5--; now /= 5;
		}
	}
	printf("%d", min(cnt2,cnt5));
}
