#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int cnt = 1, ptr = 0;
string n, m;
vector<int>V[27];

int main()
{
	cin >> n >> m;
	
	int nlen = n.length();
	int mlen = m.length();
	
	for(int i = 0; i < mlen; i++){
		int now = m[i] - 'a';
		V[now].push_back(i);
	}
	
	for(int i = 0; i < nlen; i++){
		int now = n[i] - 'a';
		if(V[now].empty()){
			cnt = -1;
			break;
		}
		int idx = lower_bound(V[now].begin(), V[now].end(), ptr) - V[now].begin();
		if(idx >= V[now].size()){
			cnt++;
			idx = 0;
		}
		ptr = V[now][idx];
		ptr++;
	}
	
	cout << cnt;
}
