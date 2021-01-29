#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int n;
vector<pair<int,string> >ar(100001,{0,"asdf"});

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> ar[i].first >> ar[i].second;
	}
	sort(ar.begin(), ar.end());
	
	for(int i = 0; i < n; i++){
		cout << ar[i].first << ' ' << ar[i].second << '\n';
	}
}
