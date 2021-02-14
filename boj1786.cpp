#include<iostream>
#include<string>
#include<vector>
#define MAX 1000000
using namespace std;

int fail[MAX+1];
string str1, str2;
vector<int>ans;

int main()
{
	getline(cin,str1);
	getline(cin,str2);
	
	for(int i = 1, j = 0; i < str2.size(); i++){
		while(j > 0 && str2[i] != str2[j]){
			j = fail[j-1];
		}
		if(str2[i] == str2[j]){
			fail[i] = ++j;
		}
	}
	
	int n = str1.size();
	int m = str2.size();
	
	int i = 0, j = 0;
	while(i <= n - m){
		if(j < m && str1[i + j] == str2[j]){
			if(++j == m) ans.push_back(i);
		}
		else{
			if(j == 0) i++;
			else{
				i += j-fail[j-1];
				j = fail[j-1];
			}
		}
	}
	
	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]+1);
	}
}
