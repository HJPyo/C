#include<iostream>
#include<algorithm>
#define MAX 10004
using namespace std;

int n, m, ar[MAX];
int L = 0, R = 0, ans = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> ar[i];
		R = max(R,ar[i]);
	}
	cin >> m;
	
	while(L <= R){
		int M = (L+R)/2;
		long int now = 0;
		
		for(int i = 0; i < n; i++){
			now += min(M,ar[i]);
		}
		
		if(now <= m){
			L = M+1;
			ans = max(ans,M);
		}
		else R = M-1;
	}
	cout << ans;
}
