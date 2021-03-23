#include<stdio.h>
#include<stack>
#define IDX s2.top().first
#define NOW s2.top().second
using namespace std;

int n, ar[500005];
stack<pair<int,int>>s1, s2;

int main()
{
	scanf("%d", &n);
	
	for(int i = 0, j; i < n; i++){
		scanf("%d", &j);
		s1.push({i,j});
	}
	
	for(int i = 0; i < n; i++){
		int idx = s1.top().first;
		int now = s1.top().second;
		s1.pop();
		
		while(!s2.empty() && NOW <= now){
			ar[IDX] = idx+1;
			s2.pop();
		}
		s2.push({idx,now});
	}
	
	for(int i = 0; i < n; i++){
		printf("%d ", ar[i]);
	}
}
