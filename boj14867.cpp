#include<stdio.h>
#include<set>
#include<queue>
using namespace std;

int a, b, A, B;
queue<pair<pair<int,int>,int>>Q;
set<pair<int,int>>S;

int main()
{
	scanf("%d %d %d %d", &a, &b, &A, &B);
	
	int ans = -1;
	Q.push({{0,0},0});
	while(!Q.empty()){
		int Va = Q.front().first.first;
		int Vb = Q.front().first.second;
		int cnt = Q.front().second;
		Q.pop();
		
		if(S.find({Va,Vb}) != S.end())
			continue;
		else
			S.insert({Va,Vb});
		
		if(Va == A && Vb == B){
			ans = cnt;
			break;
		}
		int tmp = Va+Vb;
		
		if(Va < a)
			Q.push({{a,Vb},cnt+1}); //F a
		if(Vb < b)
			Q.push({{Va,b},cnt+1}); //F b
		if(Va > 0){
			Q.push({{0,Vb},cnt+1}); //E a 
			if(Vb < b){				//M a to b
				if(tmp > b)
					Q.push({{tmp-b,b},cnt+1});
				else
					Q.push({{0,tmp},cnt+1});
			}
		}
		if(Vb > 0){
			Q.push({{Va,0},cnt+1}); //E b
			if(Va < a){				//M b to a
				if(tmp > a)
					Q.push({{a,tmp-a},cnt+1});
				else
					Q.push({{tmp,0},cnt+1});
			}
		}
			
	}
	printf("%d", ans);
}
