#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int n;
set<string>dic;
vector<string>ans;

bool cmp(string x, string y)
{
	if(x.length() == y.length()) return x < y;
	else return x.length() < y.length();
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		string tmp;
		cin >> tmp;
		dic.insert(tmp);
	}
	
	set<string>::iterator P;
	for(P = dic.begin(); P != dic.end(); P++){
		ans.push_back(*P);
	}
	
	sort(ans.begin(),ans.end(),cmp);
	
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << '\n';
	}
}
