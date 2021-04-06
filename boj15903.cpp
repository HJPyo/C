#include<stdio.h>
#include<queue>
using namespace std;

int n, k;
priority_queue<long long int>pq;

int main(){
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < n; i++){
		long long int a;
		scanf("%lld", &a);
		pq.push(-a);
	}
	
	for(int i = 0; i < k; i++){
		long long int a = -pq.top(); pq.pop();
		long long int b = -pq.top(); pq.pop();
		long long int c = a + b;
		pq.push(-c);
		pq.push(-c);
	}
	
	long long int ans = 0;
	
	while(!pq.empty()){
		ans -= (long long int)pq.top(); pq.pop();
	}
	
	printf("%lld", ans);
}
