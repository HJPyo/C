#include<stdio.h>
#include<algorithm>
#include<stack>
#define MAX 1000001
using namespace std;

int n, ar[MAX], dp[MAX], me[MAX];

int main(){
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &ar[i]);
	}
	
	int len = 0;
	for(int i = 0; i < n; i++){
		int idx = lower_bound(dp,dp+len,ar[i]) - dp;
		dp[idx] = ar[i];
		me[i] = idx;
		if(idx == len) len++;
	}
	
	printf("%d\n", len);
	
	int c1, c2, c3 = len-2;
	stack<int>st;
	
	for(int i = n-1; i >= 0; i--){
		if(me[i] == len-1){
			c1 = i;
			c2 = ar[i];
			break;
		}
	}
	
	st.push(c2);
	
	for(int i = c1-1; c3 >= 0; i--){
		if(me[i] == c3 && ar[i] < c2){
			c2 = ar[i];
			c3--;
			st.push(ar[i]);
		}
	}
	
	while(!st.empty()){
		printf("%d ", st.top());
		st.pop();
	}
}
