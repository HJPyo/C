#include<stdio.h>
#include<stack>
#define MAX 500005
using namespace std;

int n, k;
int ar[MAX];
stack<int>st1, st2;

int main(){
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < n; i++){
		scanf("%1d", &ar[i]);
	}
	
	for(int i = n-1; i >= 0; i--){
		st2.push(ar[i]);
	}
	
	st1.push(st2.top());
	st2.pop();
	
	while(k && !st2.empty()){
		if(st1.top() < st2.top()){
			st1.pop();
			st1.push(st2.top());
			st2.pop();
			k--;
		}
		else{
			st1.push(st2.top());
			st2.pop();
		}
	}
	
	if(k){
		while(k--){
			st1.push(st2.top());
			st2.pop();
		}
		
		while(!st2.empty()){
			st2.pop();
		}
	}
	
	while(!st1.empty()){
		st2.push(st1.top());
		st1.pop();
	}
	
	while(!st2.empty()){
		printf("%d", st2.top());
		st2.pop();
	}
	
	return 0;
}
