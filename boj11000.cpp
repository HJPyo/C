#include<stdio.h>
#include<queue>
using namespace std;

int n;
priority_queue<pair<int,int>>pQ1;
priority_queue<int>pQ2;

int main()
{
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		pQ1.push({-a,-b});
	}
	
	while(!pQ1.empty()){
		int st = -pQ1.top().first;
		int en = -pQ1.top().second;
		pQ1.pop();
		
		if(pQ2.empty()) pQ2.push(-en);
		else{
			int before = -pQ2.top();
			if(before <= st) pQ2.pop();
			pQ2.push(-en);
		}
	}
	
	printf("%d", pQ2.size());
}
