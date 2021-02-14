#include<stdio.h>
#include<queue>
using namespace std;

int t;

int main()
{
	scanf("%d", &t);
	
	while(t--){
		int a, b;
		priority_queue< pair<int,pair<int,int> > >pQ;
		
		scanf("%d %d", &a, &b);
		pQ.push({0,{-a,b}});
		
		while(!pQ.empty()){
			int A = -pQ.top().second.first;
			int B = pQ.top().second.second;
			int cnt = -pQ.top().first;
			pQ.pop();
			
			if(A == 0){
				printf("%d\n", cnt);
				break;
			}
			
			pQ.push({-(cnt+1),{(int)A/B,B}});
			pQ.push({-(cnt+1),{A,B+1}});
		}
	}
}
