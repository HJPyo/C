#include<iostream>
#include<algorithm>
#include<utility>
#include<stack>
#define MAX 100005
using namespace std;

int n, dp[MAX], chk[MAX];
pair<int,int> ar[MAX];

int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> ar[i].first >> ar[i].second;
	}
	
	sort(ar, ar+n);
	
	int cnt = 0;
	
	for(int i = 0; i < n; i++){
		int idx = lower_bound(dp, dp+cnt, ar[i].second) - dp;
		dp[idx] = ar[i].second;
		chk[i] = idx;
		if(idx == cnt) cnt++;
	}
	
	cout << n - cnt;
	
	cnt--;
	
	stack<int>st;
	
	int c1, c2, c3 = cnt-1;
	
	for(int i = n-1; i >= 0; i--){
		if(chk[i] == cnt){
			c1 = i;
			c2 = ar[i].second;
			break;
		}
	}
	
	for(int i = c1-1; c3 >= 0; i--){
		if(chk[i] == c3 && ar[i])
	}
}
