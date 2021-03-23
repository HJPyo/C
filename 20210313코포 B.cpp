#include<stdio.h>
#include<stack>
#define max(x,y) (x > y ? x : y)
using namespace std;

int t;
int n, ar[222222];
stack<int>st;

int main()
{
	scanf("%d", &t);
	
	while(t--){
		
		scanf("%d", &n);
		
		for(int i = 0, j; i < n; i++){
			scanf("%d", &j);
			st.push(j);
		}
		
		int param = 0;
		
		for(int i = n; i > 0; i--){
			param = max(param,st.top());
			st.pop();
			
			ar[i] = param ? 1 : 0;
			param--;
		}
		
		for(int i = 1; i <= n; i++){
			printf("%d ", ar[i]);
		}
		
		puts("");
	}
}
