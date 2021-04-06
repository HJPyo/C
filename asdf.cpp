#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n, m, k, sq, ar[300003], ans[10001], num1[10001], num2[300003];

struct query{
	int L, R, idx;
}q[10001];

int main(){
	cin >> n >> m;
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
	
	int tmp = 0, L = q[0].L, R = q[0].R, midx = -1;
	
	for(int i = L; i <= R; i++){
		num1[ar[i]]++;
	}
	
	for(int i = 1; i <= m; i++){
		num2[num1[i]]++;
		if(tmp < num1[i]){
			tmp = num1[i];
			midx = i;
		}
	}
	
	if(tmp >= R-L){
		ans[q[0].idx] = midx;
	}
	else{
		ans[q[0].idx] = -1;
	}
	
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
			if(tmp < num1[ar[L]]){
				tmp = num1[ar[L]];
				midx = ar[L];
			}
		}
		while(R < q[i].R){
			R++;
			num2[num1[ar[R]]]--;
			num1[ar[R]]++;
			num2[num1[ar[R]]]++;
			if(tmp < num1[ar[R]]){
				tmp = num1[ar[R]];
				midx = ar[R];
			}
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
		
		if(tmp >= R-L){
			ans[q[i].idx] = midx;
		}
		else{
			ans[q[i].idx] = -1;
		}
	}
	
	for(int i = 0; i < k; i++){
		if(ans[i] == -1){
			cout << "no\n";
		}
		else{
			cout << "yes " << ans[i] << '\n';
		}
	}
}
