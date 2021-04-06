#include<iostream>
#include<algorithm>
#include<cmath>
#define MAX 100005
using namespace std;

int n, k, sq, ar[MAX], ans[MAX], num1[MAX], num2[MAX];

struct query{
	int L, R, idx;
}q[MAX];

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
	
	sort(q,q+k,[](query x, query y){
		if(x.L/sq == y.L/sq) return x.R < y.R;
		else return x.L/sq < y.L/sq;
	});
	
	int tmp = 0, L = q[0].L, R = q[0].R;
	
	for(int i = L; i <= R; i++){
		num1[ar[i]]++;
	}
	
	for(int i = 1; i <= MAX-5; i++){
		num2[num1[i]]++;
		tmp = max(tmp,num1[i]);
	}

	ans[q[0].idx] = tmp;
	
	for(int i = 1; i < k; i++){
		while(L < q[i].L){
			if(tmp == num1[ar[L]]){
				if(num2[tmp] == 1) tmp--;
			}
			num2[num1[ar[L]]]--;
			num1[ar[L]]--;
			num2[num1[ar[L]]]++;
			L++;
		}
		while(L > q[i].L){
			L--;
			num2[num1[ar[L]]]--;
			num1[ar[L]]++;
			num2[num1[ar[L]]]++;
			tmp = max(tmp,num1[ar[L]]);
		}
		while(R < q[i].R){
			R++;
			num2[num1[ar[R]]]--;
			num1[ar[R]]++;
			num2[num1[ar[R]]]++;
			tmp = max(tmp,num1[ar[R]]);
		}
		while(R > q[i].R){
			if(tmp == num1[ar[R]]){
				if(num2[tmp] == 1) tmp--;
			}
			num2[num1[ar[R]]]--;
			num1[ar[R]]--;
			num2[num1[ar[R]]]++;
			R--;
		}
		ans[q[i].idx] = tmp;
	}
	
	for(int i = 0; i < k; i++){
		cout << ans[i] << '\n';
	}
}
