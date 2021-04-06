#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int>v;

int main(){
	cin >> n;
	
	for(int i = 2; n > 1; i++){
		while(n % i == 0){
			n /= i;
			v.push_back(i);
		}
	}
	
	for(auto i: v){
		cout << i << '\n';
	}
	
	return 0;
}
