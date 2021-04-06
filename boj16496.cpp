#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int n;
string str[1005];

bool cmp(string x, string y){
	int idx = 0;
	
	while(idx < 10){
		if(x[idx] == '*' && y[idx] == '0') return 1;
		if(x[idx] == '0' && y[idx] == '*') return 0;
		if(x[idx] > y[idx]) return 1;
		if(x[idx] < y[idx]) return 0;
		idx++;
	}
	
	return 0;
}

int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> str[i];
		while(str[i].length() < 10){
			str[i] = str[i] + '*';
		}
	}
	
	if(n > 1) sort(str,str+n,cmp);
	
	int flag = 0;
	string ans = "";
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 10; j++){
			if(str[i][j] == '*') break;
			ans = ans + str[i][j];
		}
	}
	
	if(ans[0] == '0') cout << "0";
	else cout << ans;
	
	return 0;
}
