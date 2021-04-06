#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n, k, sq, ar[100005], ans[100005], num[1000005];
struct query{
	int L, R, idx;
}q[100005];

bool cmp(query x, query y){
	if(x.L/sq == y.L/sq) return x.R < y.R;
	else return x.L/sq < y.L/sq;
}

int main(){
	cin >> n;
	sq = sqrt(n);	
	for(int i = 1; i <= n; i++){
		cin >> ar[i];
	}
	cin >> k;
	for(int i = 0; i < k; i++){
		cin >> q[i].L >> q[i].R;
		q[i].idx = i;
	}
	sort(q,q+k,cmp);
	
	int tmp = 0, L = q[0].L, R = q[0].R;
	
	for(int i = L; i <= R; i++){
		if(num[ar[i]]++ == 0) tmp++;
	}
	
	ans[q[0].idx] = tmp;
	
	for(int i = 1; i < k; i++){
		while(L < q[i].L){
			if(--num[ar[L++]] == 0) tmp--;
		}
		while(L > q[i].L){
			if(num[ar[--L]]++ == 0) tmp++;
		}
		while(R > q[i].R){
			if(--num[ar[R--]]== 0) tmp--;
		}
		while(R < q[i].R){
			if(num[ar[++R]]++ == 0) tmp++;
		}
		ans[q[i].idx] = tmp;
	}
	
	for(int i = 0; i < k; i++){
		cout << ans[i] << '\n';
	}
}
