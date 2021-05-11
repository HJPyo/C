#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int n;
string sex = "zzzzzzzzz";
vector<string>v0, v1, v2;

bool cmp(string x, string y){
	return x+y < y+x;
}

int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		string tmp;
		cin >> tmp;
		
		if(tmp[0] == '0'){
			v0.push_back(tmp);
		}
		else{
			v1.push_back(tmp);
			
			if(sex > tmp){
				sex = tmp;
			}
		}
	}
	
	if(v1.size() == 0){
		cout << "INVALID";
	}
	else{
		sort(v0.begin(), v0.end(), cmp);
		sort(v1.begin(), v1.end(), cmp);
		
		string str1 = "", str2 = "";
		
		str1 = str1 + v1[0];
		for(int i = 0; i < v0.size(); i++){
			str1 = str1 + v0[i];
		}
		for(int i = 1; i < v1.size(); i++){
			str1 = str1 + v1[i];
		}
		
		int flag = 0;
		
		for(int i = 0; i < v1.size(); i++){
			if(v1[i] != sex){
				v2.push_back(v1[i]);
			}
			else{
				if(flag == 1){
					v2.push_back(v1[i]);
				}
				else{
					flag = 1;
				}
			}
		}
		
		sort(v2.begin(), v2.end(), cmp);
		
		str2 = str2 + sex;
		
		for(int i = 0; i < v0.size(); i++){
			str2 = str2 + v0[i];
		}
		
		for(int i = 0; i < v2.size(); i++){
			str2 = str2 + v2[i];
		}
		
		if(str1 < str2){
			cout << str1;
		}
		else{
			cout << str2;
		}
	}
}
