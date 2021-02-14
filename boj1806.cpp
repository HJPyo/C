#include<stdio.h>
#define INF 1999999999

int n, k, ar[100001], len = INF;

int min(int x, int y)
{
	return x < y ? x : y;
}

int main()
{
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d", &ar[i]);
	}
	
	int L = 0, R = 0, sum = ar[0];
	while(L <= R && R < n){
		if(sum < k) sum += ar[++R];
		else if(sum == k){
			len = min(len,R-L+1);
			sum += ar[++R];
		}
		else if(sum > k){
			len = min(len,R-L+1);
			sum -= ar[L++];
		}
	}
	
	printf("%d", len == INF ? 0 : len);
}
