#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;

int main(){
	int T;
	cin >> T;
	
	while(T--){
		int n, dp[100001];
		pair<int,int> ar[100001];
		
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> ar[i].first >> ar[i].second;
		}
		
		sort(ar,ar+n);
		
		int low = ar[0].second;
		int ans = n;
		
		for(int i = 1; i < n; i++){
			if(low < ar[i].second) ans--;
			low = min(low,ar[i].second);
		}
		
		cout << ans << '\n';
	}
}
