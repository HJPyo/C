#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n, k, cnt = 0;
vector<int>v[21];

int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		string name;
		cin >> name;
		v[name.length()].push_back(i);
	}
	
	for(int i = 1; i <= 20; i++){
		int v_size = v[i].size();
		if(!v_size) continue;
		for(int j = 0; j < v_size-1; j++){
			for(int k = j+1; k < v_size; k++){
				if(v[i][k] - v[i][j] <= k) cnt++;
			}
		}
	}
	
	cout << cnt;
}
