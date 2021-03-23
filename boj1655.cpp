#include<stdio.h>
#include<queue>
using namespace std;

int n;
priority_queue<int> pQ1, pQ2;

int main()
{
	scanf("%d", &n);
	
	while(n--){
		int x;
		scanf("%d", &x);
		
		if(pQ1.size() == pQ2.size()) pQ1.push(x);
		else pQ2.push(-x);
		
		while(!pQ1.empty() && !pQ2.empty() && pQ1.top() > -pQ2.top()){
			int a = pQ1.top(); pQ1.pop();
			int b = -pQ2.top(); pQ2.pop();
			pQ1.push(b);
			pQ2.push(-a);
		}
		
		printf("%d\n", pQ1.top());
	}
}
