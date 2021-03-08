#include<stdio.h>
#include<queue>
#define LL long long
using namespace std;

int n;
LL int ans = 0;
priority_queue<LL int>pQ;

int main(){
	scanf("%d", &n);
	
	for(int i = 0, j; i < n; i++){
		scanf("%d", &j);
		pQ.push(-j);
	}
	
	while(pQ.size() >= 1){
		LL int card1 = -pQ.top(); pQ.pop();
		LL int card2 = -pQ.top(); pQ.pop();
		
		ans += card1 + card2;
		pQ.push(-card1-card2);
	}
	
	printf("%lld", ans);
}
