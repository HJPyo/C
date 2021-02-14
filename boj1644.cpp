#include<stdio.h>
#include<vector>
#define MAX 4444444
using namespace std;

int n, IsPrime[MAX] = {0,0};
vector<int>prime_num;

int main()
{
	for(int i = 2; i < MAX; i++){
		if(IsPrime[i] == 1) continue;
		prime_num.push_back(i);
		for(int j = i<<1; j < MAX; j+=i){
			IsPrime[j] = 1;
		}
	}
	
	scanf("%d", &n);
	
	int L = 0, R = 0, now = 0, cnt = 1 - IsPrime[n];
	while(prime_num[R] <= n){
		if(now == n) cnt++;
		if(now >= n) now -= prime_num[L++];
		else if(now < n) now += prime_num[R++];
	}
	
	printf("%d", cnt);
}
