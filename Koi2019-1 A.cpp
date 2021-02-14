#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#define LL long long
using namespace std;

struct mall{ int time, id, idx; };

struct cmp{
	bool operator()(mall x, mall y){
		if(x.time == y.time) return x.idx > y.idx;
		else return x.time > y.time;
	}
};

bool _cmp(mall x, mall y){
	if(x.time == y.time) return x.idx > y.idx;
	else return x.time < y.time;
}

int n, k, cnt = 1;
LL int sum = 0;
priority_queue<mall, vector<mall>, cmp>pQ;
vector<mall>ans;

int main()
{
	scanf("%d %d", &n, &k);
	
	for(int i = 1; i <= k; i++){
		pQ.push({0, 0, i});
	}
	
	for(int i = 1; i <= n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		
		int TIME = pQ.top().time;
		int ID = pQ.top().id;
		int IDX = pQ.top().idx;
		pQ.pop();
		
		if(ID != 0){
			ans.push_back({TIME, ID, IDX});
		}
		
		pQ.push({TIME+b, a, IDX});
	}
	
	while(!pQ.empty()){
		int TIME = pQ.top().time;
		int ID = pQ.top().id;
		int IDX = pQ.top().idx;
		if(ID != 0){
			ans.push_back({TIME, ID, IDX});
		}
		pQ.pop();
	}
	
	sort(ans.begin(), ans.end(), _cmp);
	
	for(int i = 0; i < ans.size(); i++){
		sum += (LL int) ans[i].id * (i+1);
	}
	
	printf("%lld", sum);
}
