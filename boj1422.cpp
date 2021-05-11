#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int n, k;
string top = "";
vector<string>v;

bool cmp1(string x, string y){
	if(x.length() == y.length()) return x < y;
	else return x.length() < y.length();
}

bool cmp2(string x, string y){
	return x + y > y + x;
}

int main(){
	cin >> n >> k;
	
	for(int i = 0; i < n; i++){
		string tmp;
		cin >> tmp;
		v.push_back(tmp);
		
		if(cmp1(top, tmp)){
			top = tmp;
		}
	}
	
	for(int i = 0; i < k-n; i++){
		v.push_back(top);
	}
	
	sort(v.begin(), v.end(), cmp2);
	
	for(int i = 0; i < k; i++){
		cout << v[i];
	}
	
	return 0;
}
