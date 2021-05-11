#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int n, mnum = -1;
string str[1005];

int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> str[i];
		for(int j = 0; j < str[i].length(); j++){
			mnum = max(mnum,str[i][j] - '0');
		}
	}
	
	if(mnum == 0){
		cout << 0;
		return 0;
	}
	
	sort(str,str+n,[](string x, string y){	
		return x+y > y+x;
	});
	
	for(int i = 0; i < n; i++){
		cout << str[i];
	}
	
	return 0;
}
