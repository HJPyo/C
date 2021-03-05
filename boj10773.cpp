#include<stdio.h>
#include<stack>
using namespace std;

int n, ans = 0;
stack<int>don;

int main()
{
	scanf("%d", &n);
	while(n--){
		int x;
		scanf("%d", &x);
		if(x == 0) don.pop();
		else don.push(x);
	}
	while(!don.empty()){
		ans += don.top();
		don.pop();
	}
	printf("%d", ans);
}
