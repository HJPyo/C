#include<stdio.h>
#include<queue>
#define LL long long
using namespace std;

int n;
priority_queue<LL int>pQ;

int main()
{
	scanf("%d", &n);
	
	for(int i = 1; i < 10; i++){
		pQ.push(-i);
	}
	
	LL int ans = 0;
	
	if(n > 1022){
		return 0;
	}
	
	while(n--){
		ans = -pQ.top();
		printf("%lld,", ans);
		pQ.pop();
		for(int i = (ans%10)-1; i >= 0; i--){
			pQ.push(-(ans*10+i));
		}
	}
}
