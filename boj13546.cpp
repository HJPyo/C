#include<stdio.h>
#include<algorithm>
#include<vector>
#include<deque>
#include<cmath>
#define MAX 100005
using namespace std;

struct query{
	int L, R, idx;
}q[MAX];

int n, m, k, sq, ar[MAX], num1[MAX], num2[MAX];
vector<deque<int>>dq;

bool cmp(query x, query y){
	if(x.L/sq == y.L/sq) return x.R < y.R;
	else return x.L/sq < y.L/sq;
}

int main(){
	scanf("%d %d", &n, &m);
	dq.resize(m+5,deque<int>());
	sq = sqrt(n);
	
	for(int i = 1; i <= n; i++){
		scanf("%d", &ar[i]);
	}
	
	scanf("%d", &k);
	
	for(int i = 0; i < k; i++){
		scanf("%d %d", &q[i].L, &q[i].R);
		q[i].idx = i;
	}
	
	sort(q,q+k,cmp);
	
	int tmp = 0, L = q[0].L, R = q[0].R;
	
	for(int i = L; i <= R; i++){
		dq[ar[i]].push_back(i);
		num1[ar[i]] = dq[ar[i]].back() - dq[ar[i]].front();
		tmp = max(tmp,num1[ar[i]]);
	}
	
	for(int i = 1; i <= m; i++){
		num2[num1[i]]++;
	}
	
	ans[q[0].idx] = tmp;
	
	for(int i = 1; i < k; i++){
		if(L < q[i].L){
			dq[ar[L]].pop_front();
			L++;
		}
		if(L > q[i].L){
			L--;
			
		}
		if(R < q[i].R){
			R++;
			
		}
		if(R > q[i].R){
			
			R--;
		}
	}
}
