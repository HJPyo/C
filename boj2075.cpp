#include<stdio.h>
#include<queue>
#include <functional>
using namespace std;

int n;
priority_queue<int>Q;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n*n; i++){
		int tmp;
		scanf("%d", &tmp);
		Q.push(-tmp);
		if(Q.size()>n) Q.pop();
	}
	
	printf("%d", -Q.top());
}
