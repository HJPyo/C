#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 4004
using namespace std;

int n, ar[4][MAX];
vector<int>presum;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 4; j++){
			cin >> ar[j][i];
		}
	}
	
	for(int i = 0; i < 2; i++){
		sort(ar[i],ar[i]+n);
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			presum.push_back(ar[2][i]+ar[3][j]);
		}
	}
	
	int v_size = presum.size();
	int cnt = 0;
	
	for(int i = 0; i < v_size; i++){
		int L = 0, R = n-1;
		while(L < n-1 || R > 0){
			int now = presum[i] + ar[0][L] + ar[1][R];
			if(now < 0){
				if(L == n-1) break;
				L++;
			}
			else if(now > 0){
				if(R == 0) break;
				R--;
			}
			else{
				cnt++;
				R--;
			}
		}
	}
	
	cout << cnt;
}
