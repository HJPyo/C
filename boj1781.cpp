#include<stdio.h>
#include<queue>
#include<algorithm>
#define MAX 200002
using namespace std;

int n, ans;
priority_queue<int>pq[MAX], qt;

int main(){
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		pq[n-a].push(b);
	}
	
	for(int i = 0; i < n; i++){
		while(!pq[i].empty()){
			qt.push(pq[i].top());
			pq[i].pop();
		}
		
		if(!qt.empty()){
			ans += qt.top();
			qt.pop();
		}
	}
	
	printf("%d", ans);
}
