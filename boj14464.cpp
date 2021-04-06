#include<stdio.h>
#include<queue>
using namespace std;

int n, k;
priority_queue<int>chick, chick2;
priority_queue<pair<int,int>>cow, cow2;

int main(){
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		chick.push(a);
	}
	
	for(int j = 0; j < k; j++){
		int a, b;
		scanf("%d %d", &a, &b);
		cow.push({b,a});
	}
	
	int cnt = 0;
	
	while(!cow.empty()){
		int chk = chick.top();
		int cowS = cow.top().second;
		int cowE = cow.top().first;
		chick.pop();
		cow.pop();
		
		while(cowE > chk || chk < cowS){
			if(cow.empty()) goto SEX1;
			cow2.push({-cowS,-cowE});
			cowS = cow.top().second;
			cowE = cow.top().first;
			cow.pop();
		}
		
		printf(">> chk : %d cow : {%d, %d}\n", chk, cowS, cowE);
		
		cnt++;
	}
	
	SEX1:
	
	while(!chick.empty()){
		chick2.push(-chick.top());
		chick.pop();
	}
	
	while(!cow2.empty()){
		int chk = -chick2.top();
		int cowS = -cow2.top().first;
		int cowE = -cow2.top().second;
		chick2.pop();
		cow2.pop();
		
		while(cowE > chk || chk < cowS){
			if(cow2.empty()) goto SEX2;
			cowS = -cow2.top().first;
			cowE = -cow2.top().second;
			cow2.pop();
		}
		
		printf(">> chk : %d cow : {%d, %d}\n", chk, cowS, cowE);
		
		cnt++;
	}
	
	SEX2:
	
	printf("%d", cnt);
}
