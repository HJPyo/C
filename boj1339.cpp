#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int n, ar[26];
vector<int>v;

bool cmp(int x, int y){
	return x > y;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		string tmp;
		cin >> tmp;
		int tmp_len = tmp.length();
		
		for(int i = 0; i < tmp_len; i++){
			int now = tmp[i] - 'A';
			ar[now] += pow(10, tmp_len-i-1);
		}
	}
	
	for(int i = 0; i < 26; i++){
		if(ar[i] == 0) continue;
		v.push_back(ar[i]);
	}
	
	sort(v.begin(), v.end(), cmp);
	int ans = 0;
	
	for(int i = 0, val = 9; i < v.size(); i++){
		ans += v[i] * val--;
	}
	
	cout << ans;
}
